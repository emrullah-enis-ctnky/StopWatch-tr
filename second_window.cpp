#include "second_window.h"
#include "ui_second_window.h"
#include "QTimer"

int minute_variable=0;
int hour_variable=0;
int second_variable=0;
int total_second_variable=0;
bool control_start=false;
second_window::second_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::second_window)
{
    ui->setupUi(this);

    timer=new QTimer();
    connect(timer,&QTimer::timeout,this,&second_window::timer_func);
    third_window=new time_set_window(this);
    connect(ui->stopwatch,&QAction::triggered,this,&second_window::main_window_show);
    connect(ui->about,&QAction::triggered,this,&second_window::about_triggered);
    connect(ui->time_set,SIGNAL(clicked()),this,SLOT(time_set_triggered()));
    connect(third_window,SIGNAL(push_button_clicked()),this,SLOT(third_window_set()));
    connect(ui->reset,SIGNAL(clicked()),this,SLOT(reset_button_clicked()));
    connect(ui->start_pause,SIGNAL(clicked()),this,SLOT(start_pause_clicked()));
    connect(third_window,SIGNAL(close_event_signal()),this,SLOT(third_window_close()));
}

second_window::~second_window()
{
    delete ui;
}
void second_window::about_triggered()
{
    QMessageBox::about(this,"Hakkında","Bu uygulama <b>Emrullah Enis Çetinkaya</b> tarafından"
                                         " QT ile açık kaynak olarak geliştirilmektedir.<br></br>"
                                         "<a href=\"https://youtube.com/@teknolojimuhafizi?feature=shared\">Youtube sayfası</a>");

}
void second_window::time_set_triggered(){
    this->hide();
    third_window->show();
}
void second_window::third_window_set(){
    third_window->hide();
    second_variable=third_window->line_edit_second_func().toInt();
    minute_variable=third_window->line_edit_minute_func().toInt();
    hour_variable=third_window->line_edit_hour_func().toInt();
    this->show();
    third_window->line_edit_clear();
    second_window::label_time_set();
    total_second_variable=hour_variable*3600+minute_variable*60+second_variable;

}

void second_window::timer_func(){
    total_second_variable=hour_variable*3600+minute_variable*60+second_variable;
    if(total_second_variable<=1){
        total_second_variable=0;
        second_variable=0;
        second_window::label_time_set();
        timer->stop();
        ui->start_pause->setIcon(QIcon(":/icons/icons/play(1).svg"));
        QMessageBox::information(this,"Sayaç Durdu","Süre bitti!");
        control_start=false;
    }
    else{
        total_second_variable--;
        hour_variable=total_second_variable/3600;
        second_variable=total_second_variable%60;
        minute_variable=total_second_variable/60-hour_variable*60;
        second_window::label_time_set();
    }


}
void second_window::label_time_set(){
    if(hour_variable==0){
        if(minute_variable==0){
            ui->label_time->setText(QString("%1").arg(second_variable));
        }
        else {
            ui->label_time->setText(QString("%1:%2").arg(minute_variable).arg(second_variable));
        }
    }else {
        ui->label_time->setText(QString("%1:%2:%3").arg(hour_variable).arg(minute_variable).arg(second_variable));
    }
}
void second_window::start_pause_clicked(){
    if(control_start){
        timer->stop();
        ui->start_pause->setIcon(QIcon(":/icons/icons/play(1).svg"));
        control_start=false;
        ui->statusbar->showMessage("Sayaç durduruldu.",1500);
    }
    else if(control_start==false){

        if(total_second_variable>0){
            timer->start(1000);
            ui->start_pause->setIcon(QIcon(":/icons/icons/pause(2).svg"));
            control_start=true;
            ui->statusbar->showMessage("Sayaç başlatıldı.",1500);
        }

    }
}
void second_window::reset_button_clicked(){
    if(total_second_variable>0){
    minute_variable=0;
    hour_variable=0;
    second_variable=0;
    second_window::label_time_set();
    ui->statusbar->showMessage("Sayaç sıfırlandı.",1500);
    }
}
void second_window::closeEvent(QCloseEvent *event){
    QApplication::quit();
}
void second_window::third_window_close(){
    this->show();
}
