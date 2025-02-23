#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QTimer"
#include "QMessageBox"
#include "QTime"
#include "QDate"
#include "second_window.h"
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
    void main_window_show2();
    ~MainWindow();


private slots:
    void on_start_pause_clicked();
    void on_reset_clicked();
    void on_about_triggered();
    void timer_window_open(bool checked);

private:
    Ui::MainWindow *ui;
    QTimer *timer,*timer2;
    void main_timer_func();
    void timer_func();
    second_window *timer_window;

};
#endif // MAINWINDOW_H
