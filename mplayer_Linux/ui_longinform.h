/********************************************************************************
** Form generated from reading UI file 'longinform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LONGINFORM_H
#define UI_LONGINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LonginForm
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;

    void setupUi(QWidget *LonginForm)
    {
        if (LonginForm->objectName().isEmpty())
            LonginForm->setObjectName(QStringLiteral("LonginForm"));
        LonginForm->resize(648, 357);
        LonginForm->setStyleSheet(QLatin1String("#LonginForm{border-image: url(:/player/logo/r.jpg);}\n"
"\n"
""));
        pushButton = new QPushButton(LonginForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(180, 250, 99, 41));
        QFont font;
        font.setPointSize(16);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QLatin1String("color: rgb(211, 209, 209);\n"
"border: 0px solid #bbb;"));
        pushButton->setFlat(true);
        pushButton_2 = new QPushButton(LonginForm);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(370, 250, 99, 41));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QLatin1String("color: rgb(211, 209, 209);\n"
"border: 0px solid #bbb;"));
        pushButton_2->setFlat(true);
        label = new QLabel(LonginForm);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(false);
        label->setGeometry(QRect(110, 90, 67, 41));
        QFont font1;
        font1.setPointSize(15);
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral("color: rgb(211, 209, 209);"));
        label_2 = new QLabel(LonginForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(false);
        label_2->setGeometry(QRect(110, 160, 67, 41));
        label_2->setFont(font1);
        label_2->setStyleSheet(QStringLiteral("color: rgb(211, 209, 209);"));
        lineEdit = new QLineEdit(LonginForm);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(210, 90, 281, 41));
        QFont font2;
        font2.setPointSize(14);
        lineEdit->setFont(font2);
        lineEdit->setAutoFillBackground(false);
        lineEdit->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#FFFFFF;\n"
"border-color:rgb(211, 209, 209);\n"
"border-style:solid;\n"
"border-top-width:0px;\n"
"border-right-width:0px;\n"
"border-bottom-width:3px;\n"
"border-left-width:0px;\n"
""));
        lineEdit->setDragEnabled(false);
        lineEdit->setClearButtonEnabled(false);
        lineEdit_2 = new QLineEdit(LonginForm);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(210, 160, 281, 41));
        lineEdit_2->setFont(font2);
        lineEdit_2->setStyleSheet(QLatin1String("background:transparent;\n"
"color:#FFFFFF;\n"
"border-color:rgb(211, 209, 209);\n"
"border-style:solid;\n"
"border-top-width:0px;\n"
"border-right-width:0px;\n"
"border-bottom-width:3px;\n"
"border-left-width:0px;"));
        lineEdit_2->setEchoMode(QLineEdit::Password);

        retranslateUi(LonginForm);

        QMetaObject::connectSlotsByName(LonginForm);
    } // setupUi

    void retranslateUi(QWidget *LonginForm)
    {
        LonginForm->setWindowTitle(QApplication::translate("LonginForm", "Form", 0));
        pushButton->setText(QApplication::translate("LonginForm", "\346\263\250\345\206\214", 0));
        pushButton_2->setText(QApplication::translate("LonginForm", "\347\231\273\345\275\225", 0));
        label->setText(QApplication::translate("LonginForm", "\345\270\220\345\217\267:", 0));
        label_2->setText(QApplication::translate("LonginForm", "\345\257\206\347\240\201:", 0));
    } // retranslateUi

};

namespace Ui {
    class LonginForm: public Ui_LonginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LONGINFORM_H
