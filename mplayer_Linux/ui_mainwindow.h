/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QListWidget *showPlayList;
    QSlider *volumeSlider;
    QWidget *widget_2;
    QPushButton *nextSongBtn;
    QPushButton *playBtn;
    QPushButton *preSongBtn;
    QComboBox *playModelCbox;
    QPushButton *scanLocalFileBtn;
    QPushButton *showPlayListBtn;
    QSlider *playProgressSlider;
    QLabel *songNameLB;
    QLabel *bgtimeLB;
    QLabel *label_2;
    QLabel *edtimeLB;
    QPushButton *pushButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *lrcLB_1;
    QLabel *lrcLB_2;
    QLabel *lrcLB_3;
    QLabel *lrcLB_4;
    QLabel *lrcLB_5;
    QLabel *lrcLB_6;
    QLabel *lrcLB_7;
    QPushButton *preSongBtn_2;
    QPushButton *exitBtn;
    QLabel *pictureLB;
    QLabel *usernameLB;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1250, 666);
        MainWindow->setMinimumSize(QSize(40, 40));
        MainWindow->setMaximumSize(QSize(1250, 666));
        MainWindow->setStyleSheet(QLatin1String("#MainWindow{\n"
"	border-image: url(:/player/logo/02.jpg);\n"
"}\n"
"\n"
"\n"
"\n"
""));
        MainWindow->setIconSize(QSize(40, 40));
        MainWindow->setDocumentMode(false);
        MainWindow->setDockNestingEnabled(false);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(1250, 600));
        centralWidget->setMaximumSize(QSize(1250, 600));
        showPlayList = new QListWidget(centralWidget);
        showPlayList->setObjectName(QStringLiteral("showPlayList"));
        showPlayList->setGeometry(QRect(900, 20, 300, 451));
        showPlayList->setMinimumSize(QSize(300, 200));
        showPlayList->setMaximumSize(QSize(300, 500));
        QFont font;
        font.setPointSize(14);
        showPlayList->setFont(font);
        showPlayList->setStyleSheet(QLatin1String("background-color: rgba(5, 105, 161, 80);\n"
"color:rgb(231, 231, 231);"));
        showPlayList->setSortingEnabled(false);
        volumeSlider = new QSlider(centralWidget);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setGeometry(QRect(1019, 570, 191, 10));
        QFont font1;
        font1.setPointSize(8);
        volumeSlider->setFont(font1);
        volumeSlider->setStyleSheet(QLatin1String("QSlider{\n"
"border-color:#bcbcbc;\n"
"}\n"
"QSlider::handle:horizontal{\n"
"	border:7px solid rgba(255,255,255,0);\n"
"	border-radius: 7px;\n"
"	\n"
"}\n"
"QSlider::sub-page:horizontal{\n"
"	background-color: rgb(53, 193, 255);\n"
"}\n"
"QSlider::handle:horizontal:hover{\n"
"	border:7px solid rgb(53, 193, 255);\n"
"}"));
        volumeSlider->setTracking(true);
        volumeSlider->setOrientation(Qt::Horizontal);
        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(680, 520, 181, 51));
        nextSongBtn = new QPushButton(widget_2);
        nextSongBtn->setObjectName(QStringLiteral("nextSongBtn"));
        nextSongBtn->setGeometry(QRect(130, 10, 41, 41));
        nextSongBtn->setFocusPolicy(Qt::NoFocus);
        nextSongBtn->setStyleSheet(QStringLiteral("border: 0px solid #bbb;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/player/logo/\344\270\213\344\270\200\346\233\262.png"), QSize(), QIcon::Normal, QIcon::Off);
        nextSongBtn->setIcon(icon);
        nextSongBtn->setIconSize(QSize(45, 45));
        nextSongBtn->setAutoDefault(false);
        nextSongBtn->setDefault(false);
        nextSongBtn->setFlat(true);
        playBtn = new QPushButton(widget_2);
        playBtn->setObjectName(QStringLiteral("playBtn"));
        playBtn->setGeometry(QRect(70, 10, 41, 41));
        playBtn->setFocusPolicy(Qt::NoFocus);
        playBtn->setStyleSheet(QStringLiteral("border: 0px solid #bbb;"));
        playBtn->setIconSize(QSize(45, 45));
        playBtn->setCheckable(true);
        playBtn->setChecked(false);
        playBtn->setAutoRepeat(false);
        playBtn->setAutoExclusive(false);
        playBtn->setAutoDefault(false);
        playBtn->setDefault(false);
        playBtn->setFlat(true);
        preSongBtn = new QPushButton(widget_2);
        preSongBtn->setObjectName(QStringLiteral("preSongBtn"));
        preSongBtn->setGeometry(QRect(10, 10, 41, 41));
        preSongBtn->setFocusPolicy(Qt::NoFocus);
        preSongBtn->setAutoFillBackground(false);
        preSongBtn->setStyleSheet(QStringLiteral("border: 0px solid #bbb;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/player/logo/\344\270\212\344\270\200\346\233\262.png"), QSize(), QIcon::Normal, QIcon::On);
        preSongBtn->setIcon(icon1);
        preSongBtn->setIconSize(QSize(45, 45));
        preSongBtn->setAutoDefault(false);
        preSongBtn->setFlat(true);
        playModelCbox = new QComboBox(centralWidget);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/player/logo/\345\210\227\350\241\250\345\276\252\347\216\257.png"), QSize(), QIcon::Normal, QIcon::On);
        playModelCbox->addItem(icon2, QString());
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/player/logo/\345\215\225\346\233\262\345\276\252\347\216\257.png"), QSize(), QIcon::Normal, QIcon::On);
        playModelCbox->addItem(icon3, QString());
        playModelCbox->addItem(icon2, QString());
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/player/logo/\351\232\217\346\234\272.png"), QSize(), QIcon::Normal, QIcon::On);
        playModelCbox->addItem(icon4, QString());
        playModelCbox->setObjectName(QStringLiteral("playModelCbox"));
        playModelCbox->setEnabled(true);
        playModelCbox->setGeometry(QRect(480, 550, 141, 41));
        QFont font2;
        font2.setPointSize(11);
        playModelCbox->setFont(font2);
        playModelCbox->setFocusPolicy(Qt::NoFocus);
        playModelCbox->setStyleSheet(QLatin1String("#playModelCbox{\n"
"background: transparent;\n"
"color:rgba(231, 231, 231);\n"
"border: 0px solid #bbb;\n"
"}\n"
"#playModelCbox::drop-down{\n"
"width:0px;\n"
"}"));
        playModelCbox->setEditable(false);
        playModelCbox->setMaxVisibleItems(20);
        playModelCbox->setInsertPolicy(QComboBox::InsertAtTop);
        playModelCbox->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLengthWithIcon);
        playModelCbox->setMinimumContentsLength(0);
        playModelCbox->setIconSize(QSize(45, 45));
        playModelCbox->setDuplicatesEnabled(false);
        playModelCbox->setFrame(true);
        scanLocalFileBtn = new QPushButton(centralWidget);
        scanLocalFileBtn->setObjectName(QStringLiteral("scanLocalFileBtn"));
        scanLocalFileBtn->setGeometry(QRect(1100, 520, 101, 31));
        scanLocalFileBtn->setFont(font2);
        scanLocalFileBtn->setFocusPolicy(Qt::NoFocus);
        scanLocalFileBtn->setStyleSheet(QStringLiteral("border: 0px solid #bbb;"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/player/logo/\351\237\263\344\271\220.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QString::fromUtf8(":/player/logo/\351\237\263\344\271\220.png"), QSize(), QIcon::Normal, QIcon::On);
        scanLocalFileBtn->setIcon(icon5);
        scanLocalFileBtn->setIconSize(QSize(35, 35));
        scanLocalFileBtn->setFlat(true);
        showPlayListBtn = new QPushButton(centralWidget);
        showPlayListBtn->setObjectName(QStringLiteral("showPlayListBtn"));
        showPlayListBtn->setGeometry(QRect(1100, 470, 103, 45));
        showPlayListBtn->setFocusPolicy(Qt::NoFocus);
        showPlayListBtn->setStyleSheet(QStringLiteral("border: 0px solid #bbb;"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/player/logo/\351\237\263\344\271\220\346\222\255\346\224\276\345\210\227\350\241\250.png"), QSize(), QIcon::Normal, QIcon::Off);
        showPlayListBtn->setIcon(icon6);
        showPlayListBtn->setIconSize(QSize(35, 35));
        showPlayListBtn->setFlat(true);
        playProgressSlider = new QSlider(centralWidget);
        playProgressSlider->setObjectName(QStringLiteral("playProgressSlider"));
        playProgressSlider->setEnabled(true);
        playProgressSlider->setGeometry(QRect(370, 490, 691, 15));
        playProgressSlider->setStyleSheet(QLatin1String("QSlider{\n"
"border-color:#bcbcbc;\n"
"}\n"
"QSlider::handle:horizontal{\n"
"	border:5px solid rgba(255,255,255,0);\n"
"	border-radius: 5px;\n"
"	\n"
"}\n"
"QSlider::sub-page:horizontal{\n"
"	background-color: rgb(39, 249, 36);\n"
"}\n"
"QSlider::handle:horizontal:hover{\n"
"	border:7px solid rgba(9, 249, 36);\n"
"}"));
        playProgressSlider->setPageStep(10);
        playProgressSlider->setTracking(true);
        playProgressSlider->setOrientation(Qt::Horizontal);
        songNameLB = new QLabel(centralWidget);
        songNameLB->setObjectName(QStringLiteral("songNameLB"));
        songNameLB->setGeometry(QRect(410, 520, 251, 31));
        QFont font3;
        font3.setPointSize(10);
        songNameLB->setFont(font3);
        songNameLB->setStyleSheet(QStringLiteral("border: 0px solid #bbb;"));
        bgtimeLB = new QLabel(centralWidget);
        bgtimeLB->setObjectName(QStringLiteral("bgtimeLB"));
        bgtimeLB->setGeometry(QRect(980, 520, 41, 17));
        bgtimeLB->setStyleSheet(QStringLiteral("border: 0px solid #bbb;"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(1020, 520, 10, 17));
        label_2->setStyleSheet(QLatin1String("\n"
"border: 0px solid #bbb;"));
        edtimeLB = new QLabel(centralWidget);
        edtimeLB->setObjectName(QStringLiteral("edtimeLB"));
        edtimeLB->setEnabled(true);
        edtimeLB->setGeometry(QRect(1030, 520, 41, 17));
        edtimeLB->setStyleSheet(QStringLiteral("border: 0px solid #bbb;"));
        edtimeLB->setLineWidth(-1);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(990, 565, 21, 21));
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setStyleSheet(QStringLiteral("border: 0px solid #bbb;"));
        pushButton->setIconSize(QSize(20, 20));
        pushButton->setCheckable(true);
        pushButton->setChecked(true);
        pushButton->setFlat(true);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(400, 50, 641, 421));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lrcLB_1 = new QLabel(widget);
        lrcLB_1->setObjectName(QStringLiteral("lrcLB_1"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lrcLB_1->sizePolicy().hasHeightForWidth());
        lrcLB_1->setSizePolicy(sizePolicy1);
        QFont font4;
        font4.setPointSize(13);
        lrcLB_1->setFont(font4);
        lrcLB_1->setLayoutDirection(Qt::LeftToRight);
        lrcLB_1->setStyleSheet(QStringLiteral(""));
        lrcLB_1->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lrcLB_1);

        lrcLB_2 = new QLabel(widget);
        lrcLB_2->setObjectName(QStringLiteral("lrcLB_2"));
        sizePolicy1.setHeightForWidth(lrcLB_2->sizePolicy().hasHeightForWidth());
        lrcLB_2->setSizePolicy(sizePolicy1);
        lrcLB_2->setFont(font4);
        lrcLB_2->setStyleSheet(QStringLiteral(""));
        lrcLB_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lrcLB_2);

        lrcLB_3 = new QLabel(widget);
        lrcLB_3->setObjectName(QStringLiteral("lrcLB_3"));
        sizePolicy1.setHeightForWidth(lrcLB_3->sizePolicy().hasHeightForWidth());
        lrcLB_3->setSizePolicy(sizePolicy1);
        lrcLB_3->setFont(font4);
        lrcLB_3->setStyleSheet(QStringLiteral(""));
        lrcLB_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lrcLB_3);

        lrcLB_4 = new QLabel(widget);
        lrcLB_4->setObjectName(QStringLiteral("lrcLB_4"));
        sizePolicy1.setHeightForWidth(lrcLB_4->sizePolicy().hasHeightForWidth());
        lrcLB_4->setSizePolicy(sizePolicy1);
        QFont font5;
        font5.setPointSize(20);
        font5.setBold(false);
        font5.setWeight(50);
        lrcLB_4->setFont(font5);
        lrcLB_4->setStyleSheet(QStringLiteral("color: rgb(1, 230, 208);"));
        lrcLB_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lrcLB_4);

        lrcLB_5 = new QLabel(widget);
        lrcLB_5->setObjectName(QStringLiteral("lrcLB_5"));
        sizePolicy1.setHeightForWidth(lrcLB_5->sizePolicy().hasHeightForWidth());
        lrcLB_5->setSizePolicy(sizePolicy1);
        lrcLB_5->setFont(font4);
        lrcLB_5->setStyleSheet(QStringLiteral(""));
        lrcLB_5->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lrcLB_5);

        lrcLB_6 = new QLabel(widget);
        lrcLB_6->setObjectName(QStringLiteral("lrcLB_6"));
        sizePolicy1.setHeightForWidth(lrcLB_6->sizePolicy().hasHeightForWidth());
        lrcLB_6->setSizePolicy(sizePolicy1);
        lrcLB_6->setFont(font4);
        lrcLB_6->setStyleSheet(QStringLiteral(""));
        lrcLB_6->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lrcLB_6);

        lrcLB_7 = new QLabel(widget);
        lrcLB_7->setObjectName(QStringLiteral("lrcLB_7"));
        sizePolicy1.setHeightForWidth(lrcLB_7->sizePolicy().hasHeightForWidth());
        lrcLB_7->setSizePolicy(sizePolicy1);
        lrcLB_7->setFont(font4);
        lrcLB_7->setStyleSheet(QStringLiteral(""));
        lrcLB_7->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lrcLB_7);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 2);
        verticalLayout->setStretch(2, 2);
        verticalLayout->setStretch(3, 3);
        verticalLayout->setStretch(4, 2);
        verticalLayout->setStretch(5, 2);
        verticalLayout->setStretch(6, 2);
        preSongBtn_2 = new QPushButton(centralWidget);
        preSongBtn_2->setObjectName(QStringLiteral("preSongBtn_2"));
        preSongBtn_2->setGeometry(QRect(360, 550, 41, 41));
        preSongBtn_2->setFocusPolicy(Qt::NoFocus);
        preSongBtn_2->setAutoFillBackground(false);
        preSongBtn_2->setStyleSheet(QStringLiteral("border: 0px solid #bbb;"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/player/logo/\345\276\252\347\216\257.png"), QSize(), QIcon::Normal, QIcon::On);
        preSongBtn_2->setIcon(icon7);
        preSongBtn_2->setIconSize(QSize(35, 45));
        preSongBtn_2->setAutoDefault(false);
        preSongBtn_2->setFlat(true);
        exitBtn = new QPushButton(centralWidget);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        exitBtn->setGeometry(QRect(0, -10, 42, 42));
        exitBtn->setMinimumSize(QSize(42, 42));
        exitBtn->setMaximumSize(QSize(42, 42));
        exitBtn->setFocusPolicy(Qt::NoFocus);
        exitBtn->setAutoFillBackground(false);
        exitBtn->setStyleSheet(QString::fromUtf8("QPushButton::hover{\n"
"	\n"
"	border-image: url(:/player/logo/\351\200\200\345\207\2722.png);\n"
"}"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/player/logo/\351\200\200\345\207\2722.png"), QSize(), QIcon::Normal, QIcon::Off);
        exitBtn->setIcon(icon8);
        exitBtn->setIconSize(QSize(40, 40));
        exitBtn->setAutoDefault(false);
        exitBtn->setFlat(true);
        pictureLB = new QLabel(centralWidget);
        pictureLB->setObjectName(QStringLiteral("pictureLB"));
        pictureLB->setGeometry(QRect(39, 140, 300, 300));
        pictureLB->setMinimumSize(QSize(0, 0));
        pictureLB->setMaximumSize(QSize(16777215, 16777215));
        pictureLB->setStyleSheet(QLatin1String("-min-width:     300px;     \n"
"-min-height:    300px;     \n"
"-max-width:     300px;     \n"
"-max-height:    300px;     \n"
"-border-radius: 150px;     \n"
"border:0px solid black;  \n"
"border-image: url(:/player/logo/R-C.jpg);\n"
""));
        usernameLB = new QLabel(centralWidget);
        usernameLB->setObjectName(QStringLiteral("usernameLB"));
        usernameLB->setGeometry(QRect(60, 0, 241, 41));
        usernameLB->setFont(font);
        usernameLB->setStyleSheet(QStringLiteral("color: rgb(90, 86, 91);"));
        MainWindow->setCentralWidget(centralWidget);
        volumeSlider->raise();
        widget_2->raise();
        playModelCbox->raise();
        scanLocalFileBtn->raise();
        showPlayListBtn->raise();
        playProgressSlider->raise();
        songNameLB->raise();
        bgtimeLB->raise();
        label_2->raise();
        edtimeLB->raise();
        pushButton->raise();
        widget->raise();
        showPlayList->raise();
        preSongBtn_2->raise();
        exitBtn->raise();
        pictureLB->raise();
        usernameLB->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1250, 31));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        playModelCbox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        nextSongBtn->setText(QString());
        playBtn->setText(QString());
        preSongBtn->setText(QString());
        playModelCbox->setItemText(0, QApplication::translate("MainWindow", "\351\241\272\345\272\217\346\222\255\346\224\276", 0));
        playModelCbox->setItemText(1, QApplication::translate("MainWindow", "\345\215\225\346\233\262\345\276\252\347\216\257", 0));
        playModelCbox->setItemText(2, QApplication::translate("MainWindow", "\345\276\252\347\216\257\346\222\255\346\224\276", 0));
        playModelCbox->setItemText(3, QApplication::translate("MainWindow", "\351\232\217\346\234\272\346\222\255\346\224\276", 0));

        scanLocalFileBtn->setText(QApplication::translate("MainWindow", "\346\211\253\346\217\217\346\255\214\346\233\262", 0));
        showPlayListBtn->setText(QApplication::translate("MainWindow", "\346\222\255\346\224\276\345\210\227\350\241\250", 0));
        songNameLB->setText(QApplication::translate("MainWindow", "\346\232\202\346\227\240\346\255\214\346\233\262", 0));
        bgtimeLB->setText(QApplication::translate("MainWindow", "00:00", 0));
        label_2->setText(QApplication::translate("MainWindow", "/", 0));
        edtimeLB->setText(QApplication::translate("MainWindow", "00:00", 0));
        pushButton->setText(QString());
        lrcLB_1->setText(QString());
        lrcLB_2->setText(QString());
        lrcLB_3->setText(QString());
        lrcLB_4->setText(QString());
        lrcLB_5->setText(QString());
        lrcLB_6->setText(QString());
        lrcLB_7->setText(QString());
        preSongBtn_2->setText(QString());
        exitBtn->setText(QString());
        pictureLB->setText(QString());
        usernameLB->setText(QString());
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
