#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QTimer"
#include "QMessageBox"
#include "QTime"
#include "QDate"
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


private slots:


    void on_start_pause_clicked();

    void on_reset_clicked();


    void on_about_triggered();

private:
    Ui::MainWindow *ui;
    QTimer *timer,*timer2;
    void main_timer_func();
    void timer_func();
};
#endif // MAINWINDOW_H
