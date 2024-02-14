/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *result_show;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_1;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_multiply;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_equals;
    QPushButton *pushButton_0;
    QPushButton *pushButton_pow;
    QPushButton *pushButton_del;
    QPushButton *pushButton_divide;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_atan;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_asin;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_acos;
    QPushButton *pushButton_log;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_graphics;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_x;
    QPushButton *pushButton_close;
    QPushButton *pushButton_open;
    QLabel *label;
    QPushButton *pushButton_plus_and_minus;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(763, 568);
        QFont font;
        font.setPointSize(13);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"  background-color: rgba(28, 113, 216, 59);\n"
"}\n"
"\n"
"QMainWindow:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        result_show = new QLabel(centralwidget);
        result_show->setObjectName("result_show");
        result_show->setGeometry(QRect(10, 0, 481, 61));
        QFont font1;
        font1.setPointSize(30);
        result_show->setFont(font1);
        result_show->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"  border: 1px solid gray;\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"QLabel {\n"
"background-color : white;\n"
"}\n"
""));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(260, 130, 51, 51));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(222, 221, 218);\n"
"  color: black; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_7->setCheckable(false);
        pushButton_7->setAutoDefault(false);
        pushButton_7->setFlat(false);
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(320, 130, 51, 51));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(222, 221, 218);\n"
"  color: black; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(380, 130, 51, 51));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(222, 221, 218);\n"
"  color: black; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(320, 190, 51, 51));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(222, 221, 218);\n"
"  color: black; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(380, 190, 51, 51));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(222, 221, 218);\n"
"  color: black; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(260, 190, 51, 51));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(222, 221, 218);\n"
"  color: black; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(320, 250, 51, 51));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(222, 221, 218);\n"
"  color: black; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(380, 250, 51, 51));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(222, 221, 218);\n"
"  color: black; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setGeometry(QRect(260, 250, 51, 51));
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(222, 221, 218);\n"
"  color: black; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_plus = new QPushButton(centralwidget);
        pushButton_plus->setObjectName("pushButton_plus");
        pushButton_plus->setGeometry(QRect(440, 250, 51, 51));
        pushButton_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(28, 113, 216);\n"
"  color: white; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_minus = new QPushButton(centralwidget);
        pushButton_minus->setObjectName("pushButton_minus");
        pushButton_minus->setGeometry(QRect(440, 190, 51, 51));
        pushButton_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(28, 113, 216);\n"
"  color: white; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_multiply = new QPushButton(centralwidget);
        pushButton_multiply->setObjectName("pushButton_multiply");
        pushButton_multiply->setGeometry(QRect(440, 130, 51, 51));
        pushButton_multiply->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(28, 113, 216);\n"
"  color: white; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_dot = new QPushButton(centralwidget);
        pushButton_dot->setObjectName("pushButton_dot");
        pushButton_dot->setGeometry(QRect(380, 310, 51, 51));
        pushButton_dot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(192, 191, 188);\n"
"  color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_equals = new QPushButton(centralwidget);
        pushButton_equals->setObjectName("pushButton_equals");
        pushButton_equals->setGeometry(QRect(440, 310, 51, 51));
        QFont font2;
        font2.setBold(false);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        font2.setKerning(true);
        font2.setStyleStrategy(QFont::PreferDefault);
        font2.setHintingPreference(QFont::PreferDefaultHinting);
        pushButton_equals->setFont(font2);
        pushButton_equals->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(28, 113, 216);\n"
"  color: white; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_0 = new QPushButton(centralwidget);
        pushButton_0->setObjectName("pushButton_0");
        pushButton_0->setGeometry(QRect(260, 310, 111, 51));
        pushButton_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(222, 221, 218);\n"
"  color: black; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_pow = new QPushButton(centralwidget);
        pushButton_pow->setObjectName("pushButton_pow");
        pushButton_pow->setGeometry(QRect(380, 70, 51, 51));
        pushButton_pow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(192, 191, 188);\n"
"  color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_del = new QPushButton(centralwidget);
        pushButton_del->setObjectName("pushButton_del");
        pushButton_del->setGeometry(QRect(260, 70, 51, 51));
        pushButton_del->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(192, 191, 188);\n"
"  color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_divide = new QPushButton(centralwidget);
        pushButton_divide->setObjectName("pushButton_divide");
        pushButton_divide->setGeometry(QRect(440, 70, 51, 51));
        pushButton_divide->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(28, 113, 216);\n"
"  color: white; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_tan = new QPushButton(centralwidget);
        pushButton_tan->setObjectName("pushButton_tan");
        pushButton_tan->setGeometry(QRect(170, 130, 71, 51));
        pushButton_tan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(28, 113, 216);\n"
"  color: white; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_atan = new QPushButton(centralwidget);
        pushButton_atan->setObjectName("pushButton_atan");
        pushButton_atan->setGeometry(QRect(170, 190, 71, 51));
        pushButton_atan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(28, 113, 216);\n"
"  color: white; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_mod = new QPushButton(centralwidget);
        pushButton_mod->setObjectName("pushButton_mod");
        pushButton_mod->setGeometry(QRect(170, 250, 71, 51));
        pushButton_mod->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(28, 113, 216);\n"
"  color: white; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_asin = new QPushButton(centralwidget);
        pushButton_asin->setObjectName("pushButton_asin");
        pushButton_asin->setGeometry(QRect(90, 190, 71, 51));
        pushButton_asin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(28, 113, 216);\n"
"  color: white; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_sqrt = new QPushButton(centralwidget);
        pushButton_sqrt->setObjectName("pushButton_sqrt");
        pushButton_sqrt->setGeometry(QRect(90, 250, 71, 51));
        pushButton_sqrt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(28, 113, 216);\n"
"  color: white; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_sin = new QPushButton(centralwidget);
        pushButton_sin->setObjectName("pushButton_sin");
        pushButton_sin->setGeometry(QRect(90, 130, 71, 51));
        pushButton_sin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(28, 113, 216);\n"
"  color: white; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_acos = new QPushButton(centralwidget);
        pushButton_acos->setObjectName("pushButton_acos");
        pushButton_acos->setGeometry(QRect(10, 190, 71, 51));
        pushButton_acos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(28, 113, 216);\n"
"  color: white; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_log = new QPushButton(centralwidget);
        pushButton_log->setObjectName("pushButton_log");
        pushButton_log->setGeometry(QRect(10, 250, 71, 51));
        pushButton_log->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(28, 113, 216);\n"
"  color: white; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_cos = new QPushButton(centralwidget);
        pushButton_cos->setObjectName("pushButton_cos");
        pushButton_cos->setGeometry(QRect(10, 130, 71, 51));
        pushButton_cos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(28, 113, 216);\n"
"  color: white; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_graphics = new QPushButton(centralwidget);
        pushButton_graphics->setObjectName("pushButton_graphics");
        pushButton_graphics->setGeometry(QRect(500, 310, 151, 51));
        pushButton_graphics->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(26, 95, 180);\n"
"  color: white; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_ln = new QPushButton(centralwidget);
        pushButton_ln->setObjectName("pushButton_ln");
        pushButton_ln->setGeometry(QRect(170, 70, 71, 51));
        pushButton_ln->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(28, 113, 216);\n"
"  color: white; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_x = new QPushButton(centralwidget);
        pushButton_x->setObjectName("pushButton_x");
        pushButton_x->setGeometry(QRect(10, 310, 71, 51));
        pushButton_x->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(192, 191, 188);\n"
"  color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_close = new QPushButton(centralwidget);
        pushButton_close->setObjectName("pushButton_close");
        pushButton_close->setGeometry(QRect(90, 70, 71, 51));
        pushButton_close->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(192, 191, 188);\n"
"  color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_open = new QPushButton(centralwidget);
        pushButton_open->setObjectName("pushButton_open");
        pushButton_open->setGeometry(QRect(10, 70, 71, 51));
        pushButton_open->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(192, 191, 188);\n"
"  color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 310, 151, 51));
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"  border: 1px solid gray;\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"QLabel {\n"
"background-color : white;\n"
"}\n"
""));
        pushButton_plus_and_minus = new QPushButton(centralwidget);
        pushButton_plus_and_minus->setObjectName("pushButton_plus_and_minus");
        pushButton_plus_and_minus->setGeometry(QRect(320, 70, 51, 51));
        pushButton_plus_and_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(192, 191, 188);\n"
"  color: black;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 763, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        pushButton_7->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        result_show->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_multiply->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_equals->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_pow->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        pushButton_del->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_divide->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButton_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        pushButton_atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        pushButton_acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        pushButton_log->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        pushButton_graphics->setText(QCoreApplication::translate("MainWindow", "Graphics", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        pushButton_x->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        pushButton_close->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        pushButton_open->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_plus_and_minus->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
