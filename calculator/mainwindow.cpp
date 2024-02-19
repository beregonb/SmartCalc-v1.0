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

    //grahp
    connect(ui->pushButton_graphics, SIGNAL(clicked()), this, SLOT(Graph()));


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

    unar_bool = true;

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
    ui->label_out->setText(out);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->result_show->text().contains('.'))){
        ui->result_show->setText(ui->result_show->text() + ".");
        out += ".";
    }
    ui->label_out->setText(out);
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
                buffer = buffer_two;

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
    if(trigonom){
        unar_bool = true;// так работает синус
    }

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
    ui->label_out->setText(out);
}


void MainWindow::on_pushButton_del_clicked()
{
    out = "";
    buffer = "";
    znak_mass = "";
    buffer_two ="";

    waitingForOperand = false;
    skobkiFlag = false;
    unar_bool = true;
    znack = false;
    trigonom = false;

    i = 0;

    off();
    ui->result_show->setText(out);
    ui->label_out->setText(out);
    ui->lineEdit_x->setText(out);

}

void MainWindow::thrig_operations()
{
    QPushButton *button = (QPushButton *)sender();
    QString new_lable;
    trigonom = true;
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
    ui->label_out->setText(out);
}

 void MainWindow::skobki()
{
     QPushButton *button = (QPushButton *)sender();
     QString new_lable;
     if(button->text() == ")"){
         i--;
         if(i == 0){
            trigonom = false;
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
     ui->label_out->setText(out);

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

        ui->result_show->setText(ui->result_show->text()+ znak_mass + "x");
    } else {
        ui->result_show->setText("x");
        out += "x";
    }
    ui->label_out->setText(out);
}

void MainWindow::on_pushButton_equals_clicked()
{
    if(!unar_bool){
        out += "*(-1)";
        unar_bool = true;
    }
    ui->label_out->setText(out);
    ui->result_show->setText(out);

    double x = ui->lineEdit_x->text().toDouble();
    const char *str = out.toUtf8().constData();
    double result = 0; //функция си


    result = smart_calculation(str, x);
    ui->result_show->setText(QString::number(result));

}



void MainWindow::on_pushButton_graphics_clicked()
{

}

void MainWindow::TimerSlot()
{

}

void MainWindow:: Graph()
{

    double x_min = ui->Xmin->value();
    double x_max = ui->Xmax->value();
    double y_min = ui->Ymin->value();
    double y_max = ui->Ymax->value();
    ui->widget->xAxis->setRange(x_min,x_max);
    ui->widget->yAxis->setRange(y_min,y_max);

    double delta = 0.1;

    if(!unar_bool){
        out += "*(-1)";
        unar_bool = true;
    }

    QByteArray ba = out.toLocal8Bit();
    char *str = ba.data();
    double y_res = 0; //функция си

    for(double i = -50; i <= 50; (i += delta)){
        x.push_back(i);
        printf("%lf %s\n", i, str);
        y_res = smart_calculation(str, i);
        y.push_back(y_res);
    }

    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y);
    ui->widget->replot();
    x.clear();
    y.clear();
    ui->widget->graph(0)->data()->clear();
}
