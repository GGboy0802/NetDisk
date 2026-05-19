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
    QWidget *wdg_content;
    QVBoxLayout *verticalLayout;
    MyOpenGLWidget *wdg_show;
    QSlider *slider_progress;
    QLabel *lb_curTime;
    QLabel *lb_totalTime;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pb_start;
    QPushButton *pb_resume;
    QPushButton *pb_pause;
    QPushButton *pb_stop;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *PlayerDialog)
    {
        if (PlayerDialog->objectName().isEmpty())
            PlayerDialog->setObjectName(QString::fromUtf8("PlayerDialog"));
        PlayerDialog->resize(800, 600);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        PlayerDialog->setFont(font);
        wdg_content = new QWidget(PlayerDialog);
        wdg_content->setObjectName(QString::fromUtf8("wdg_content"));
        wdg_content->setGeometry(QRect(0, 0, 801, 521));
        wdg_content->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        verticalLayout = new QVBoxLayout(wdg_content);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        wdg_show = new MyOpenGLWidget(wdg_content);
        wdg_show->setObjectName(QString::fromUtf8("wdg_show"));

        verticalLayout->addWidget(wdg_show);

        slider_progress = new QSlider(PlayerDialog);
        slider_progress->setObjectName(QString::fromUtf8("slider_progress"));
        slider_progress->setGeometry(QRect(80, 530, 641, 16));
        slider_progress->setOrientation(Qt::Horizontal);
        lb_curTime = new QLabel(PlayerDialog);
        lb_curTime->setObjectName(QString::fromUtf8("lb_curTime"));
        lb_curTime->setGeometry(QRect(10, 530, 61, 16));
        lb_totalTime = new QLabel(PlayerDialog);
        lb_totalTime->setObjectName(QString::fromUtf8("lb_totalTime"));
        lb_totalTime->setGeometry(QRect(730, 530, 61, 16));
        layoutWidget = new QWidget(PlayerDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 559, 781, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pb_start = new QPushButton(layoutWidget);
        pb_start->setObjectName(QString::fromUtf8("pb_start"));

        horizontalLayout->addWidget(pb_start);

        pb_resume = new QPushButton(layoutWidget);
        pb_resume->setObjectName(QString::fromUtf8("pb_resume"));

        horizontalLayout->addWidget(pb_resume);

        pb_pause = new QPushButton(layoutWidget);
        pb_pause->setObjectName(QString::fromUtf8("pb_pause"));

        horizontalLayout->addWidget(pb_pause);

        pb_stop = new QPushButton(layoutWidget);
        pb_stop->setObjectName(QString::fromUtf8("pb_stop"));

        horizontalLayout->addWidget(pb_stop);

        horizontalSpacer = new QSpacerItem(338, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(PlayerDialog);

        QMetaObject::connectSlotsByName(PlayerDialog);
    } // setupUi

    void retranslateUi(QDialog *PlayerDialog)
    {
        PlayerDialog->setWindowTitle(QApplication::translate("PlayerDialog", "PlayerDialog", nullptr));
        lb_curTime->setText(QApplication::translate("PlayerDialog", "00:00:00", nullptr));
        lb_totalTime->setText(QApplication::translate("PlayerDialog", "00:03:00", nullptr));
        pb_start->setText(QApplication::translate("PlayerDialog", "\346\211\223\345\274\200", nullptr));
        pb_resume->setText(QApplication::translate("PlayerDialog", "\346\222\255\346\224\276/\346\201\242\345\244\215", nullptr));
        pb_pause->setText(QApplication::translate("PlayerDialog", "\346\232\202\345\201\234", nullptr));
        pb_stop->setText(QApplication::translate("PlayerDialog", "\345\201\234\346\255\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayerDialog: public Ui_PlayerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERDIALOG_H
