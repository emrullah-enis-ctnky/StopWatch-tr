#ifndef SECOND_WINDOW_H
#define SECOND_WINDOW_H

#include <QMainWindow>
#include "QMessageBox"
#include "time_set_window.h"
#include "QCloseEvent"
namespace Ui {
class second_window;
}

class second_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit second_window(QWidget *parent = nullptr);
    void about_triggered();

    ~second_window();
signals:
    void main_window_show();
private slots:
    void time_set_triggered();
    void third_window_set();
    void reset_button_clicked();
    void start_pause_clicked();
    void third_window_close();
private:
    Ui::second_window *ui;
    time_set_window *third_window;
    void timer_func();
    void label_time_set();
    QTimer *timer;
    void closeEvent(QCloseEvent *event) override;

};


#endif // SECOND_WINDOW_H
