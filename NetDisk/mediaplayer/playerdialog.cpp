#include "playerdialog.h"
#include "ui_playerdialog.h"

//#define _DEF_PATH "D:/xwechat_files/wxid_rkggnbmxpj2p22_6fbe/msg/video/2026-03/7d9c0a6304ba3a3da230a45206cc2ccb.mp4"
#define _DEF_PATH "http://192.168.142.135:80/vod//101.mp4"
PlayerDialog::PlayerDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PlayerDialog)
{
    ui->setupUi(this);
    m_player = new VideoPlayer;
    connect(m_player,SIGNAL(SIG_getOneImage(QImage)),this,SLOT(slot_setImage(QImage)));

    slot_PlayerStateChanged(PlayerState::Stop);
    //测试
    //m_player->setFileName(_DEF_PATH);

    //connect(&m_timer,SIGNAL(timeout()),this,SLOT());

    connect(m_player,SIGNAL(SIG_PlayerStateChanged(int)),this,SLOT(slot_PlayerStateChanged(int)));

    connect( m_player, SIGNAL( SIG_TotalTime(qint64)) , this ,SLOT( slot_getTotalTime(qint64)) );


    connect(&m_timer,SIGNAL(timeout()),this,SLOT(slot_TimerTimeOut()));
    m_timer.setInterval(500);//超时时间500

    //安装事件过滤称为被观察对象， this执行事件判断
    ui->slider_progress->installEventFilter(this);
}

PlayerDialog::~PlayerDialog()
{
    delete ui;
    delete m_player;
}


//QT 线程
//QThread 定义子类 start() ->run();

//打开文件进行播放
#include<QFileDialog>
void PlayerDialog::on_pb_start_clicked()
{
    //开始播放 -> 一段时间内 获取图片
    //    m_player->start();


    // 打开浏览选择文件
    QString path = QFileDialog::getOpenFileName( this, "选择要播放的文件" , "./","视频文件 (*.flv *.rmvb *.avi *.MP4 *.mkv);; 所有文件(*.*);;");
    //判断
    if( path.isEmpty() ) return;

    //首先 要先关闭 判断 当前的状态 stop
    if( m_player->playerState() != PlayerState::Stop ){
        m_player->stop( true );
    }
    //设置 m_play fileName
    m_player->setFileName(path);

    m_player->start();
    //切换状态
    slot_PlayerStateChanged(PlayerState::Playing);
}

void PlayerDialog::slot_setImage(QImage img)
{
    //pixmap image
    //缩放
//    QPixmap pixmap ;
//    if(!img.isNull())
//        pixmap= QPixmap::fromImage( img.scaled( ui->lb_show->size(), Qt::KeepAspectRatio ) );
//    else
//        pixmap=QPixmap::fromImage(img);
//    ui->lb_show->setPixmap( pixmap );
    //实现视频加速渲染OpenGL

    ui->wdg_show->slot_setImage(img);
}


void PlayerDialog::on_pb_resume_clicked()
{
    if (m_player->playerState() != PlayerState::Pause) return;

    m_player->play();

    //切换
    ui->pb_resume->hide();
    ui->pb_pause->show();
}


void PlayerDialog::on_pb_pause_clicked()
{
    if (m_player->playerState() != PlayerState::Playing) return;

    m_player->pause();

    //切换
    ui->pb_resume->show();
    ui->pb_pause->hide();
}


void PlayerDialog::on_pb_stop_clicked()
{
    m_player->stop(true);
}

// 直接播放指定路径的视频文件
void PlayerDialog::playFile(const QString& filePath)
{
    if( filePath.isEmpty() ) return;

    // 先停止当前播放
    if( m_player->playerState() != PlayerState::Stop ){
        m_player->stop( true );
    }
    // 设置文件路径并开始播放
    m_player->setFileName(filePath);
    m_player->start();
    // 切换状态
    slot_PlayerStateChanged(PlayerState::Playing);
}

//播放状态切换槽函数
void PlayerDialog::slot_PlayerStateChanged(int state)
{
    switch( state )
    {
    case PlayerState::Stop:
        qDebug()<< "VideoPlayer::Stop";
        m_timer.stop();
        ui->slider_progress->setValue(0);
        ui->lb_totalTime->setText("00:00:00");
        ui->lb_curTime->setText("00:00:00");
        ui->pb_pause->hide();
        ui->pb_resume->show();
//    {
//        QImage img;
//        img.fill( Qt::black);
//        slot_setImage( img );
//    }
        this->update();
        isStop = true;
        break;
    case PlayerState::Playing:
        qDebug()<< "VideoPlayer::Playing";
        ui->pb_resume->hide();
        ui->pb_pause->show();
        m_timer.start();
        this->update();
        isStop = false;
        break;
    }
}

//获取视频全部时间
void PlayerDialog::slot_getTotalTime(qint64 uSec)
{
    qint64 Sec = uSec/1000000;
    ui->slider_progress->setRange(0,Sec);//精确到秒
    QString hStr = QString("00%1").arg(Sec/3600);
    QString mStr = QString("00%1").arg(Sec/60);
    QString sStr = QString("00%1").arg(Sec%60);
    QString str =
            QString("%1:%2:%3").arg(hStr.right(2)).arg(mStr.right(2)).arg(sStr.right(2));
    ui->lb_totalTime->setText(str);
}


//获取当前视频时间定时器
void PlayerDialog::slot_TimerTimeOut()
{
    if (QObject::sender() == &m_timer)
    {
        qint64 Sec = m_player->getCurrentTime()/1000000;
        ui->slider_progress->setValue(Sec);
        QString hStr = QString("00%1").arg(Sec/3600);
        QString mStr = QString("00%1").arg(Sec/60%60);
        QString sStr = QString("00%1").arg(Sec%60);
        QString str =
                QString("%1:%2:%3").arg(hStr.right(2)).arg(mStr.right(2)).arg(sStr.right(2));
        ui->lb_curTime->setText(str);
        if(ui->slider_progress->value() == ui->slider_progress->maximum()
                && m_player->playerState() == PlayerState::Stop)
        {
            slot_PlayerStateChanged( PlayerState::Stop );
        }else if(ui->slider_progress->value() + 1 ==
                 ui->slider_progress->maximum()
                 && m_player->playerState() == PlayerState::Stop)
        {
            slot_PlayerStateChanged( PlayerState::Stop );
        }
    }
}
#include<QStyle>
#include<QMouseEvent>
bool PlayerDialog::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->slider_progress) {
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            int min = ui->slider_progress->minimum();
            int max = ui->slider_progress->maximum();
            int value = QStyle::sliderValueFromPosition(min, max, mouseEvent->pos().x(), ui->slider_progress->width());

            m_timer.stop();
            ui->slider_progress->setValue(value);
            m_player->seek((qint64)value*1000000);
            m_timer.start();


            return true;
        } else {
            return false;
        }
    }
    // pass the event on to the parent class
    return QDialog::eventFilter(obj, event);
}
