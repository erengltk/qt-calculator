#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void digit_pressed();
    void on_pushButton_nokta_released();
    void number_operator_pressed();
    void islem_operatoru();
    void on_pushButton_equ_released();

    void on_pushButtonCl_released();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
