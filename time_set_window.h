#ifndef TIME_SET_WINDOW_H
#define TIME_SET_WINDOW_H

#include <QWidget>

namespace Ui {
class time_set_window;
}

class time_set_window : public QWidget
{
    Q_OBJECT

public:
    explicit time_set_window(QWidget *parent = nullptr);
    ~time_set_window();
    QString line_edit_second_func();
    QString line_edit_minute_func();
    QString line_edit_hour_func();
    void line_edit_clear();
signals:
    void push_button_clicked();
private:
    Ui::time_set_window *ui;
};

#endif // TIME_SET_WINDOW_H
