/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboBox_serialPort;
    QLabel *label_2;
    QComboBox *comboBox_baudrate;
    QLabel *DataBits;
    QComboBox *comboBox_databits;
    QLabel *label_3;
    QComboBox *comboBox_stopbits;
    QLabel *label_4;
    QComboBox *comboBox_checkdigit;
    QLabel *label_5;
    QComboBox *comboBox_flowctrl;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_scan;
    QPushButton *pushButton_pause;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_open;
    QPushButton *pushButton_close;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_rec_ascii;
    QRadioButton *radioButton_rec_hex;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton_send_ascii;
    QRadioButton *radioButton_send_hex;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox_repeat;
    QSpinBox *spinBox_repeat;
    QLabel *label_6;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_8;
    QTextBrowser *textBrowser_rec;
    QTextEdit *textEdit_send;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_send;
    QPushButton *pushButton_clear;
    QWidget *draw;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_enableDraw;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(771, 514);
        horizontalLayout_4 = new QHBoxLayout(Widget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboBox_serialPort = new QComboBox(groupBox);
        comboBox_serialPort->setObjectName(QString::fromUtf8("comboBox_serialPort"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox_serialPort);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        comboBox_baudrate = new QComboBox(groupBox);
        comboBox_baudrate->setObjectName(QString::fromUtf8("comboBox_baudrate"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBox_baudrate);

        DataBits = new QLabel(groupBox);
        DataBits->setObjectName(QString::fromUtf8("DataBits"));

        formLayout->setWidget(2, QFormLayout::LabelRole, DataBits);

        comboBox_databits = new QComboBox(groupBox);
        comboBox_databits->setObjectName(QString::fromUtf8("comboBox_databits"));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBox_databits);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        comboBox_stopbits = new QComboBox(groupBox);
        comboBox_stopbits->setObjectName(QString::fromUtf8("comboBox_stopbits"));

        formLayout->setWidget(3, QFormLayout::FieldRole, comboBox_stopbits);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        comboBox_checkdigit = new QComboBox(groupBox);
        comboBox_checkdigit->setObjectName(QString::fromUtf8("comboBox_checkdigit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBox_checkdigit);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        comboBox_flowctrl = new QComboBox(groupBox);
        comboBox_flowctrl->setObjectName(QString::fromUtf8("comboBox_flowctrl"));

        formLayout->setWidget(5, QFormLayout::FieldRole, comboBox_flowctrl);


        verticalLayout_5->addLayout(formLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        pushButton_scan = new QPushButton(groupBox);
        pushButton_scan->setObjectName(QString::fromUtf8("pushButton_scan"));

        horizontalLayout_6->addWidget(pushButton_scan);

        pushButton_pause = new QPushButton(groupBox);
        pushButton_pause->setObjectName(QString::fromUtf8("pushButton_pause"));

        horizontalLayout_6->addWidget(pushButton_pause);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        pushButton_open = new QPushButton(groupBox);
        pushButton_open->setObjectName(QString::fromUtf8("pushButton_open"));

        horizontalLayout_7->addWidget(pushButton_open);

        pushButton_close = new QPushButton(groupBox);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));

        horizontalLayout_7->addWidget(pushButton_close);


        verticalLayout_5->addLayout(horizontalLayout_7);


        verticalLayout_6->addWidget(groupBox);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_13 = new QHBoxLayout(groupBox_2);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButton_rec_ascii = new QRadioButton(groupBox_2);
        radioButton_rec_ascii->setObjectName(QString::fromUtf8("radioButton_rec_ascii"));
        radioButton_rec_ascii->setChecked(true);

        horizontalLayout->addWidget(radioButton_rec_ascii);

        radioButton_rec_hex = new QRadioButton(groupBox_2);
        radioButton_rec_hex->setObjectName(QString::fromUtf8("radioButton_rec_hex"));

        horizontalLayout->addWidget(radioButton_rec_hex);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_13->addLayout(verticalLayout_2);


        verticalLayout_6->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_12 = new QHBoxLayout(groupBox_3);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        radioButton_send_ascii = new QRadioButton(groupBox_3);
        radioButton_send_ascii->setObjectName(QString::fromUtf8("radioButton_send_ascii"));
        radioButton_send_ascii->setChecked(true);

        horizontalLayout_3->addWidget(radioButton_send_ascii);

        radioButton_send_hex = new QRadioButton(groupBox_3);
        radioButton_send_hex->setObjectName(QString::fromUtf8("radioButton_send_hex"));

        horizontalLayout_3->addWidget(radioButton_send_hex);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        checkBox_repeat = new QCheckBox(groupBox_3);
        checkBox_repeat->setObjectName(QString::fromUtf8("checkBox_repeat"));

        horizontalLayout_2->addWidget(checkBox_repeat);

        spinBox_repeat = new QSpinBox(groupBox_3);
        spinBox_repeat->setObjectName(QString::fromUtf8("spinBox_repeat"));
        spinBox_repeat->setMaximum(999999);
        spinBox_repeat->setValue(1000);

        horizontalLayout_2->addWidget(spinBox_repeat);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);


        verticalLayout_4->addLayout(horizontalLayout_2);


        horizontalLayout_12->addLayout(verticalLayout_4);


        verticalLayout_6->addWidget(groupBox_3);


        horizontalLayout_4->addLayout(verticalLayout_6);

        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        textBrowser_rec = new QTextBrowser(tab);
        textBrowser_rec->setObjectName(QString::fromUtf8("textBrowser_rec"));
        textBrowser_rec->setStyleSheet(QString::fromUtf8("font: 12pt \"Ubuntu Mono\";"));

        verticalLayout_8->addWidget(textBrowser_rec);

        textEdit_send = new QTextEdit(tab);
        textEdit_send->setObjectName(QString::fromUtf8("textEdit_send"));
        textEdit_send->setMinimumSize(QSize(0, 50));
        textEdit_send->setMaximumSize(QSize(16777215, 120));

        verticalLayout_8->addWidget(textEdit_send);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButton_send = new QPushButton(tab);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));

        horizontalLayout_5->addWidget(pushButton_send);

        pushButton_clear = new QPushButton(tab);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));

        horizontalLayout_5->addWidget(pushButton_clear);


        verticalLayout_8->addLayout(horizontalLayout_5);


        verticalLayout_3->addLayout(verticalLayout_8);

        tabWidget->addTab(tab, QString());
        draw = new QWidget();
        draw->setObjectName(QString::fromUtf8("draw"));
        verticalLayout = new QVBoxLayout(draw);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        checkBox_enableDraw = new QCheckBox(draw);
        checkBox_enableDraw->setObjectName(QString::fromUtf8("checkBox_enableDraw"));

        verticalLayout->addWidget(checkBox_enableDraw);

        tabWidget->addTab(draw, QString());

        horizontalLayout_4->addWidget(tabWidget);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Widget", "Serial Port Configration:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "Serial Port:", 0, QApplication::UnicodeUTF8));
        comboBox_serialPort->clear();
        comboBox_serialPort->insertItems(0, QStringList()
         << QApplication::translate("Widget", "None", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("Widget", "Baud Rate:", 0, QApplication::UnicodeUTF8));
        comboBox_baudrate->clear();
        comboBox_baudrate->insertItems(0, QStringList()
         << QApplication::translate("Widget", "1200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "2400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "4800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "9600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "19200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "38400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "57600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "115200", 0, QApplication::UnicodeUTF8)
        );
        DataBits->setText(QApplication::translate("Widget", "Data Bits:", 0, QApplication::UnicodeUTF8));
        comboBox_databits->clear();
        comboBox_databits->insertItems(0, QStringList()
         << QApplication::translate("Widget", "5 Bits", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "6 Bits", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "7 Bits", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "8 Bits", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("Widget", "Stop Bits:", 0, QApplication::UnicodeUTF8));
        comboBox_stopbits->clear();
        comboBox_stopbits->insertItems(0, QStringList()
         << QApplication::translate("Widget", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "1.5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "2", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("Widget", "Partity:", 0, QApplication::UnicodeUTF8));
        comboBox_checkdigit->clear();
        comboBox_checkdigit->insertItems(0, QStringList()
         << QApplication::translate("Widget", "None", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "Even", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "Odd", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "Space", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "Mark", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("Widget", "Flow Ctrl:", 0, QApplication::UnicodeUTF8));
        comboBox_flowctrl->clear();
        comboBox_flowctrl->insertItems(0, QStringList()
         << QApplication::translate("Widget", "Disable", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "Hardware", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "Software", 0, QApplication::UnicodeUTF8)
        );
        pushButton_scan->setText(QApplication::translate("Widget", "scan", 0, QApplication::UnicodeUTF8));
        pushButton_pause->setText(QApplication::translate("Widget", "pause", 0, QApplication::UnicodeUTF8));
        pushButton_open->setText(QApplication::translate("Widget", "open", 0, QApplication::UnicodeUTF8));
        pushButton_close->setText(QApplication::translate("Widget", "close", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Widget", "Recived Configration:", 0, QApplication::UnicodeUTF8));
        radioButton_rec_ascii->setText(QApplication::translate("Widget", "ASCII", 0, QApplication::UnicodeUTF8));
        radioButton_rec_hex->setText(QApplication::translate("Widget", "Hex", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("Widget", "Send Configration:", 0, QApplication::UnicodeUTF8));
        radioButton_send_ascii->setText(QApplication::translate("Widget", "ASCII", 0, QApplication::UnicodeUTF8));
        radioButton_send_hex->setText(QApplication::translate("Widget", "Hex", 0, QApplication::UnicodeUTF8));
        checkBox_repeat->setText(QApplication::translate("Widget", "Repeat Send", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Widget", "ms", 0, QApplication::UnicodeUTF8));
        pushButton_send->setText(QApplication::translate("Widget", "send", 0, QApplication::UnicodeUTF8));
        pushButton_clear->setText(QApplication::translate("Widget", "clear", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "Word Trans", 0, QApplication::UnicodeUTF8));
        checkBox_enableDraw->setText(QApplication::translate("Widget", "Enable Draw Function", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(draw), QApplication::translate("Widget", "Draw Trans", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
