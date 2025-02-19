#include "mainwindow.h"
#include "./ui_mainwindow.h"
int pause_start=0;
int second=0,minute=0,hour=0;
QTime current_time=QTime::currentTime();
QDate today=QDate::currentDate();
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    timer=new QTimer(this);
    timer2=new QTimer(this);
    timer2->start(1000);
    ui->setupUi(this);



    connect(timer,&QTimer::timeout,this,&MainWindow::timer_func);
    connect(timer2,&QTimer::timeout,this,&MainWindow::main_timer_func);

    ui->start_pause->setShortcut(QKeySequence(Qt::Key_Space));
    ui->reset->setShortcut(QKeySequence(Qt::Key_R));
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_start_pause_clicked()
{
    if(pause_start){
        timer->stop();
        ui->start_pause->setIcon(QIcon(":/icons/icons/play(1).svg"));
        pause_start=0;
        ui->statusbar->showMessage("Sayaç durduruldu.",1500);
    }
    else if(pause_start==0){
        timer->start(1000);
        ui->start_pause->setIcon(QIcon(":/icons/icons/pause(2).svg"));
        pause_start=1;
        ui->statusbar->showMessage("Sayaç başlatıldı.",1500);
    }
}

void MainWindow::timer_func(){
    second++;
    if(second==60){
        minute++;
        second=0;
        if(minute==60){
            hour++;
            minute=0;
        }
    }
    if(hour==0){
        if(minute==0){
            ui->label_time->setText(QString("%1").arg(second));
        }
        else {
            ui->label_time->setText(QString("%1:%2").arg(minute).arg(second));
        }
    }
    else{
        ui->label_time->setText(QString("%1:%2:%3").arg(hour).arg(minute).arg(second));
    }
}

void MainWindow::on_reset_clicked()
{
    timer->stop();
    second=0;
    minute=0;
    hour=0;
    ui->label_time->setText(QString("%1").arg(second));
    pause_start=0;
    ui->start_pause->setIcon(QIcon(":/icons/icons/play(1).svg"));
    ui->statusbar->showMessage("Sayaç sıfırlandı.",1500);
}




void MainWindow::on_about_triggered()
{
    QMessageBox::about(this,"Hakkında","Bu uygulama <b>Emrullah Enis Çetinkaya</b> tarafından"
                                         " QT ile açık kaynak olarak geliştirilmektedir.<br></br>"
                                         "<a href=\"https://youtube.com/@teknolojimuhafizi?feature=shared\">Youtube sayfası</a>");
}

void MainWindow::main_timer_func(){
    current_time=QTime::currentTime();
    ui->label_main_time->setText(current_time.toString("HH:mm:ss"));
    ui->label_main_date->setText(today.toString("dd.MM.yyyy"));
}
