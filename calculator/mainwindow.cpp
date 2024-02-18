#include "mainwindow.h"
#include "./ui_mainwindow.h"
extern "C"{
#include "../src/calculation.h"
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_plus_and_minus, SIGNAL(clicked()), this, SLOT(operations()));

    //math
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_multiply, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(math_operations()));


    //thrigon
    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(thrig_operations()));
    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(thrig_operations()));
    connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(thrig_operations()));
    connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(thrig_operations()));
    connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(thrig_operations()));
    connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(thrig_operations()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(thrig_operations()));
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(thrig_operations()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(thrig_operations()));

    //skobki
    connect(ui->pushButton_open, SIGNAL(clicked()), this, SLOT(skobki()));
    connect(ui->pushButton_close, SIGNAL(clicked()), this, SLOT(skobki()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{


    QPushButton *button = (QPushButton *)sender();

    QString new_lable;

    if(znack && !skobkiFlag){
        out += znak_mass;
        znack = false;
    }
    if(!skobkiFlag){
        out += button->text();
    }



    if(ui->pushButton_plus->isChecked() ||
       ui->pushButton_minus->isChecked() ||
       ui->pushButton_divide->isChecked() ||
       ui->pushButton_multiply->isChecked() ||
       ui->pushButton_pow->isChecked() ||
       ui->pushButton_plus_and_minus->isChecked() ||
       ui->pushButton_mod->isChecked()){
        new_lable = "";
        ui->result_show->setText(new_lable);
    }

    if(!skobkiFlag && i == 0){
        new_lable = (ui->result_show->text() + button->text());
        ui->result_show->setText(new_lable);
    } else {
        new_lable = (buffer + button->text());
        buffer = "";
        buffer = new_lable;
        ui->result_show->setText(new_lable);
    }


    waitingForOperand = false;
    off();
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->result_show->text().contains('.'))){
        ui->result_show->setText(ui->result_show->text() + ".");
        out += ".";
    }
}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_lable;

    if(button->text() == "+/-"){
        if(!skobkiFlag){
            all_numbers = (ui->result_show->text()).toDouble();
            all_numbers = all_numbers * -1;
            new_lable = QString::number(all_numbers, 'g', 15);
            ui->result_show->setText(new_lable);
            if(unar_bool){
                unar_bool = false;
            } else {
                unar_bool = true;
            }
        } else {
            if (unar_bool) {
                unar_bool = false;
                buffer_two = buffer;
                QString text = ui->result_show->text();
                QStringList operators = { "-", "+", "*", "^", "/", "("};
                int last_index = -1;

                for (const QString& op : operators) {
                    int current_index = text.lastIndexOf(op);
                    if (current_index != -1 && current_index > last_index) {
                        last_index = current_index;
                    }
                }

                if (last_index != -1) {
                    ui->result_show->setText(text.insert(last_index + 1, "-"));
                    buffer = ui->result_show->text();
                }
            } else {
                unar_bool = true;
                ui->result_show->setText(buffer_two);
                buffer_two = buffer;

            }

        }

    }
}



void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *)sender();
    QString new_lable;

    if(ui->pushButton_plus->isChecked() ||
        ui->pushButton_minus->isChecked() ||
        ui->pushButton_divide->isChecked() ||
        ui->pushButton_multiply->isChecked() ||
        ui->pushButton_pow->isChecked() ||
        ui->pushButton_plus_and_minus->isChecked()){
        off();
    }

    button->setChecked(true);
    znak_mass = "";
    if(unar_bool){
        znak_mass += button->text();
    } else {
        if(skobkiFlag){
            znak_mass += button->text();
            out += buffer;
        } else {
            znak_mass += "*(-1)" + button->text();
        }
        unar_bool = true;
    }
    if(skobkiFlag){
        buffer += znak_mass;
        znack = false;
    }
    //включение кнопки
    if(button->text() == "+"){
        ui->pushButton_plus->setEnabled(false);
    } else if(button->text() == "-"){
        ui->pushButton_minus->setEnabled(false);
    } else if(button->text() == "*"){
        ui->pushButton_multiply->setEnabled(false);
    } else if(button->text() == "/"){
        ui->pushButton_divide->setEnabled(false);
    } else if (button->text() == "mod"){
        ui->pushButton_mod->setEnabled(false);
    } else {
        ui->pushButton_pow->setEnabled(false);
    }
    waitingForOperand = true;
    if(!skobkiFlag){
        znack = true;
    }
}


void MainWindow::on_pushButton_del_clicked()
{
    QString new_lable;

    new_lable = "";
    ui->result_show->setText(new_lable);
    ui->lineEdit_x->setText(new_lable);

    out = "";
    buffer = "";
    znak_mass = "";
    buffer_two ="";

    waitingForOperand = false;
    skobkiFlag = false;
    unar_bool = true;
    znack = false;

    i = 0;

    off();
}

void MainWindow::thrig_operations()
{
    QPushButton *button = (QPushButton *)sender();
    QString new_lable;

    if(znack){
        out += znak_mass;
        znack = false;
    }

    new_lable = button->text() + "(";


    if(!skobkiFlag){
        buffer += new_lable;
        skobkiFlag = true;
    } else {
        new_lable = (buffer + new_lable);
        buffer = "";
        buffer += new_lable;
    }
    i++;
    ui->result_show->setText(new_lable);
}

 void MainWindow::skobki()
{
     QPushButton *button = (QPushButton *)sender();
     QString new_lable;
     if(button->text() == ")"){
         i--;
         if(i == 0){
            skobkiFlag = false;
             out += buffer + button->text();
         }
         if(!unar_bool){
             unar_bool = true;
         }

     } else {
         skobkiFlag = true;
         i++;
         if(znack){
             out += znak_mass;
             znack = false;
         }
     }
     buffer += button->text();
     new_lable = (buffer);
     ui->result_show->setText(new_lable);
     if(!skobkiFlag && i == 0){
         buffer = "";
     }

}

void MainWindow::off()
{
    //отключение кнопок
    ui->pushButton_plus->setEnabled(true);
    ui->pushButton_minus->setEnabled(true);
    ui->pushButton_divide->setEnabled(true);
    ui->pushButton_multiply->setEnabled(true);
    ui->pushButton_pow->setEnabled(true);
    ui->pushButton_mod->setEnabled(true);
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    ui->pushButton_pow->setChecked(false);
    ui->pushButton_mod->setChecked(false);
}

void MainWindow::on_pushButton_x_clicked()
{
    if(znack){
        out += znak_mass;
        znack = false;
    }
    off();

    if(skobkiFlag){
        buffer += "x";
        out += "x";
        ui->result_show->setText(ui->result_show->text()+ znak_mass + "x");
    } else {
        ui->result_show->setText("x");
        out += "x";
    }
}

void MainWindow::on_pushButton_equals_clicked()
{
    if(!unar_bool){
        out += "*(-1)";
        unar_bool = true;
    }
    ui->result_show->setText(out);

    double x = ui->lineEdit_x->text().toDouble();
    ui->lineEdit_x->setText("");
    const char *str = out.toUtf8().constData();
    double result = 0; //функция си


    result = smart_calculation(str, x);
    ui->result_show->setText(QString::number(result));

}

