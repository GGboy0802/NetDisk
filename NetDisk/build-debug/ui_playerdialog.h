/********************************************************************************
** Form generated from reading UI file 'playerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERDIALOG_H
#define UI_PLAYERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <myopenglwidget.h>

QT_BEGIN_NAMESPACE

class Ui_PlayerDialog
{
public:
    QVBoxLayout *mainLayout;
    QWidget *wdg_content;
    QVBoxLayout *verticalLayout;
    MyOpenGLWidget *wdg_show;
    QHBoxLayout *progressLayout;
    QLabel *lb_curTime;
    QSlider *slider_progress;
    QLabel *lb_totalTime;
    QHBoxLayout *controlLayout;
    QPushButton *pb_start;
    QPushButton *pb_resume;
    QPushButton *pb_pause;
    QPushButton *pb_stop;
    QComboBox *cb_speed;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *PlayerDialog)
    {
        if (PlayerDialog->objectName().isEmpty())
            PlayerDialog->setObjectName(QString::fromUtf8("PlayerDialog"));
        PlayerDialog->resize(1024, 768);
        PlayerDialog->setMinimumSize(QSize(400, 300));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        PlayerDialog->setFont(font);
        mainLayout = new QVBoxLayout(PlayerDialog);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setContentsMargins(0, 0, 0, 0);
        wdg_content = new QWidget(PlayerDialog);
        wdg_content->setObjectName(QString::fromUtf8("wdg_content"));
        wdg_content->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        verticalLayout = new QVBoxLayout(wdg_content);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        wdg_show = new MyOpenGLWidget(wdg_content);
        wdg_show->setObjectName(QString::fromUtf8("wdg_show"));

        verticalLayout->addWidget(wdg_show);


        mainLayout->addWidget(wdg_content);

        progressLayout = new QHBoxLayout();
        progressLayout->setObjectName(QString::fromUtf8("progressLayout"));
        progressLayout->setContentsMargins(10, 2, 10, 2);
        lb_curTime = new QLabel(PlayerDialog);
        lb_curTime->setObjectName(QString::fromUtf8("lb_curTime"));

        progressLayout->addWidget(lb_curTime);

        slider_progress = new QSlider(PlayerDialog);
        slider_progress->setObjectName(QString::fromUtf8("slider_progress"));
        slider_progress->setOrientation(Qt::Horizontal);

        progressLayout->addWidget(slider_progress);

        lb_totalTime = new QLabel(PlayerDialog);
        lb_totalTime->setObjectName(QString::fromUtf8("lb_totalTime"));
        lb_totalTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        progressLayout->addWidget(lb_totalTime);


        mainLayout->addLayout(progressLayout);

        controlLayout = new QHBoxLayout();
        controlLayout->setObjectName(QString::fromUtf8("controlLayout"));
        controlLayout->setContentsMargins(10, 2, 10, 4);
        pb_start = new QPushButton(PlayerDialog);
        pb_start->setObjectName(QString::fromUtf8("pb_start"));

        controlLayout->addWidget(pb_start);

        pb_resume = new QPushButton(PlayerDialog);
        pb_resume->setObjectName(QString::fromUtf8("pb_resume"));

        controlLayout->addWidget(pb_resume);

        pb_pause = new QPushButton(PlayerDialog);
        pb_pause->setObjectName(QString::fromUtf8("pb_pause"));

        controlLayout->addWidget(pb_pause);

        pb_stop = new QPushButton(PlayerDialog);
        pb_stop->setObjectName(QString::fromUtf8("pb_stop"));

        controlLayout->addWidget(pb_stop);

        cb_speed = new QComboBox(PlayerDialog);
        cb_speed->addItem(QString());
        cb_speed->addItem(QString());
        cb_speed->addItem(QString());
        cb_speed->addItem(QString());
        cb_speed->addItem(QString());
        cb_speed->addItem(QString());
        cb_speed->setObjectName(QString::fromUtf8("cb_speed"));
        cb_speed->setMinimumSize(QSize(70, 0));

        controlLayout->addWidget(cb_speed);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        controlLayout->addItem(horizontalSpacer);


        mainLayout->addLayout(controlLayout);


        retranslateUi(PlayerDialog);

        cb_speed->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(PlayerDialog);
    } // setupUi

    void retranslateUi(QDialog *PlayerDialog)
    {
        PlayerDialog->setWindowTitle(QApplication::translate("PlayerDialog", "\350\247\206\351\242\221\346\222\255\346\224\276\345\231\250", nullptr));
        lb_curTime->setText(QApplication::translate("PlayerDialog", "00:00:00", nullptr));
        lb_totalTime->setText(QApplication::translate("PlayerDialog", "00:00:00", nullptr));
        pb_start->setText(QApplication::translate("PlayerDialog", "\346\211\223\345\274\200", nullptr));
        pb_resume->setText(QApplication::translate("PlayerDialog", "\346\222\255\346\224\276/\346\201\242\345\244\215", nullptr));
        pb_pause->setText(QApplication::translate("PlayerDialog", "\346\232\202\345\201\234", nullptr));
        pb_stop->setText(QApplication::translate("PlayerDialog", "\345\201\234\346\255\242", nullptr));
        cb_speed->setItemText(0, QApplication::translate("PlayerDialog", "0.5x", nullptr));
        cb_speed->setItemText(1, QApplication::translate("PlayerDialog", "0.75x", nullptr));
        cb_speed->setItemText(2, QApplication::translate("PlayerDialog", "1.0x", nullptr));
        cb_speed->setItemText(3, QApplication::translate("PlayerDialog", "1.25x", nullptr));
        cb_speed->setItemText(4, QApplication::translate("PlayerDialog", "1.5x", nullptr));
        cb_speed->setItemText(5, QApplication::translate("PlayerDialog", "2.0x", nullptr));

    } // retranslateUi

};

namespace Ui {
    class PlayerDialog: public Ui_PlayerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERDIALOG_H
