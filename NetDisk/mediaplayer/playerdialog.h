#ifndef PLAYERDIALOG_H
#define PLAYERDIALOG_H

#include <QDialog>
#include"videoplayer.h"
QT_BEGIN_NAMESPACE
namespace Ui { class PlayerDialog; }
QT_END_NAMESPACE
#include<QTimer>
#include<QDebug>

class PlayerDialog : public QDialog
{
    Q_OBJECT

public:
    PlayerDialog(QWidget *parent = nullptr);
    ~PlayerDialog();

    // 直接播放指定路径的视频文件（供外部调用）
    void playFile(const QString& filePath);

private slots:

    void on_pb_start_clicked();

    void slot_setImage(QImage img);
    void on_pb_resume_clicked();

    void on_pb_pause_clicked();

    void on_pb_stop_clicked();

    void slot_PlayerStateChanged(int state);

    void slot_getTotalTime(qint64 uSec);
    void slot_TimerTimeOut();

    //事件过滤器
    bool eventFilter(QObject* pbj,QEvent *event);
private:
    Ui::PlayerDialog *ui;

    VideoPlayer * m_player;
    QTimer m_timer;

    //停止状态
    bool isStop;

};
#endif // PLAYERDIALOG_H
