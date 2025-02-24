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
