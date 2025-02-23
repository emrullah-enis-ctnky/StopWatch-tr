#ifndef SECOND_WINDOW_H
#define SECOND_WINDOW_H

#include <QMainWindow>
#include "QMessageBox"
#include "time_set_window.h"
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
private:
    Ui::second_window *ui;
    time_set_window *third_window;
};


#endif // SECOND_WINDOW_H
