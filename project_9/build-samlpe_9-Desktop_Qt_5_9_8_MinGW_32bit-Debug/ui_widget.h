/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *groupBox;
    QPushButton *btnCheck;
    QPushButton *btnClearRec;
    QPushButton *btnOpen;
    QPushButton *btnClearSend;
    QComboBox *cmbBoxPort;
    QComboBox *cmbBoxBaud;
    QComboBox *cmbBoxDataBits;
    QComboBox *cmbBoxParity;
    QComboBox *cmbBoxStopBits;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QRadioButton *radioBtnChar;
    QRadioButton *radioBtnHex;
    QLabel *labelStatus;
    QGroupBox *groupBox_2;
    QTextEdit *textEditRec;
    QGroupBox *groupBox_3;
    QTextEdit *textEditSend;
    QRadioButton *radioBtnChar2;
    QRadioButton *radioBtnHex2;
    QPushButton *BtnSend;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(565, 451);
        Widget->setMinimumSize(QSize(565, 451));
        Widget->setMaximumSize(QSize(565, 451));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 531, 161));
        btnCheck = new QPushButton(groupBox);
        btnCheck->setObjectName(QStringLiteral("btnCheck"));
        btnCheck->setEnabled(true);
        btnCheck->setGeometry(QRect(330, 20, 75, 23));
        btnClearRec = new QPushButton(groupBox);
        btnClearRec->setObjectName(QStringLiteral("btnClearRec"));
        btnClearRec->setGeometry(QRect(330, 50, 75, 23));
        btnOpen = new QPushButton(groupBox);
        btnOpen->setObjectName(QStringLiteral("btnOpen"));
        btnOpen->setGeometry(QRect(420, 20, 75, 23));
        btnClearSend = new QPushButton(groupBox);
        btnClearSend->setObjectName(QStringLiteral("btnClearSend"));
        btnClearSend->setGeometry(QRect(420, 50, 75, 23));
        cmbBoxPort = new QComboBox(groupBox);
        cmbBoxPort->setObjectName(QStringLiteral("cmbBoxPort"));
        cmbBoxPort->setGeometry(QRect(80, 30, 81, 22));
        cmbBoxBaud = new QComboBox(groupBox);
        cmbBoxBaud->setObjectName(QStringLiteral("cmbBoxBaud"));
        cmbBoxBaud->setGeometry(QRect(80, 60, 81, 22));
        cmbBoxDataBits = new QComboBox(groupBox);
        cmbBoxDataBits->setObjectName(QStringLiteral("cmbBoxDataBits"));
        cmbBoxDataBits->setGeometry(QRect(80, 100, 81, 22));
        cmbBoxParity = new QComboBox(groupBox);
        cmbBoxParity->setObjectName(QStringLiteral("cmbBoxParity"));
        cmbBoxParity->setGeometry(QRect(250, 60, 69, 22));
        cmbBoxStopBits = new QComboBox(groupBox);
        cmbBoxStopBits->setObjectName(QStringLiteral("cmbBoxStopBits"));
        cmbBoxStopBits->setGeometry(QRect(250, 100, 69, 22));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 54, 12));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 70, 54, 12));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 110, 54, 12));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(180, 100, 54, 12));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(180, 70, 54, 12));
        radioBtnChar = new QRadioButton(groupBox);
        radioBtnChar->setObjectName(QStringLiteral("radioBtnChar"));
        radioBtnChar->setGeometry(QRect(330, 100, 89, 16));
        radioBtnChar->setChecked(true);
        radioBtnHex = new QRadioButton(groupBox);
        radioBtnHex->setObjectName(QStringLiteral("radioBtnHex"));
        radioBtnHex->setGeometry(QRect(440, 100, 89, 16));
        labelStatus = new QLabel(groupBox);
        labelStatus->setObjectName(QStringLiteral("labelStatus"));
        labelStatus->setGeometry(QRect(170, 30, 30, 30));
        labelStatus->setStyleSheet(QLatin1String("border-radius:15px;\n"
"background-color:rgb(170,0,0);"));
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 180, 531, 121));
        textEditRec = new QTextEdit(groupBox_2);
        textEditRec->setObjectName(QStringLiteral("textEditRec"));
        textEditRec->setGeometry(QRect(10, 20, 511, 91));
        textEditRec->setReadOnly(true);
        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 310, 531, 131));
        textEditSend = new QTextEdit(groupBox_3);
        textEditSend->setObjectName(QStringLiteral("textEditSend"));
        textEditSend->setGeometry(QRect(13, 20, 351, 101));
        radioBtnChar2 = new QRadioButton(groupBox_3);
        radioBtnChar2->setObjectName(QStringLiteral("radioBtnChar2"));
        radioBtnChar2->setGeometry(QRect(400, 40, 89, 16));
        radioBtnChar2->setChecked(true);
        radioBtnHex2 = new QRadioButton(groupBox_3);
        radioBtnHex2->setObjectName(QStringLiteral("radioBtnHex2"));
        radioBtnHex2->setGeometry(QRect(400, 70, 89, 16));
        BtnSend = new QPushButton(groupBox_3);
        BtnSend->setObjectName(QStringLiteral("BtnSend"));
        BtnSend->setGeometry(QRect(400, 90, 75, 23));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\344\270\262\345\217\243\345\260\217\345\212\251\346\211\213", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Widget", "\344\270\262\345\217\243\346\223\215\344\275\234", Q_NULLPTR));
        btnCheck->setText(QApplication::translate("Widget", "\344\270\262\345\217\243\346\243\200\346\265\213", Q_NULLPTR));
        btnClearRec->setText(QApplication::translate("Widget", "\346\270\205\347\251\272\346\216\245\346\224\266", Q_NULLPTR));
        btnOpen->setText(QApplication::translate("Widget", "\344\270\262\345\217\243\346\211\223\345\274\200", Q_NULLPTR));
        btnClearSend->setText(QApplication::translate("Widget", "\346\270\205\347\251\272\345\217\221\351\200\201", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\344\270\262\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\346\257\224\347\211\271\347\216\207\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\344\275\215\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("Widget", "\345\201\234\346\255\242\344\275\215\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("Widget", "\345\245\207\345\201\266\346\240\241\351\252\214\357\274\232", Q_NULLPTR));
        radioBtnChar->setText(QApplication::translate("Widget", "\345\255\227\347\254\246\346\230\276\347\244\272", Q_NULLPTR));
        radioBtnHex->setText(QApplication::translate("Widget", "Hex\346\230\276\347\244\272", Q_NULLPTR));
        labelStatus->setText(QString());
        groupBox_2->setTitle(QApplication::translate("Widget", "\346\225\260\346\215\256\346\216\245\346\224\266", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("Widget", "\346\225\260\346\215\256\345\217\221\351\200\201", Q_NULLPTR));
        radioBtnChar2->setText(QApplication::translate("Widget", "\345\255\227\347\254\246\345\217\221\351\200\201", Q_NULLPTR));
        radioBtnHex2->setText(QApplication::translate("Widget", "Hex\345\217\221\351\200\201", Q_NULLPTR));
        BtnSend->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\345\217\221\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
