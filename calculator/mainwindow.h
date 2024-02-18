#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegularExpression>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString out;
    QString znak_mass;
    QString buffer;
    QString buffer_two;

    bool waitingForOperand = false;
    bool skobkiFlag = false;
    bool unar_bool = true;
    bool znack = false;

    int i = 0;

private:
    Ui::MainWindow *ui;


private slots:
    void digits_numbers();
    void on_pushButton_dot_clicked();
    void on_pushButton_del_clicked();
    void on_pushButton_equals_clicked();
    void math_operations();
    void thrig_operations();
    void skobki();
    void operations();
    void off();
    void on_pushButton_x_clicked();
};
#endif // MAINWINDOW_H
