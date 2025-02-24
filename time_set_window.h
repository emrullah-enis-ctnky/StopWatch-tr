/**
   
StopWatch-tr Türkçe bir kronometre uygulamasıdır. Geliştirdikçe farklı diller de gelebilir.

Copyright (C) 2025 Emrullah Enis Çetinkaya and contributors

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

 **/

#ifndef TIME_SET_WINDOW_H
#define TIME_SET_WINDOW_H

#include <QWidget>
#include "QIntValidator"
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
    void close_event_signal();
private:
    Ui::time_set_window *ui;
    void closeEvent(QCloseEvent *event)override;
};

#endif // TIME_SET_WINDOW_H
