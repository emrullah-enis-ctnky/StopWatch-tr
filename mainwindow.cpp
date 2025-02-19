#include "mainwindow.h"
#include "./ui_mainwindow.h"
int pause_start=0;
int second=0,minute=0,hour=0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&MainWindow::timer_func);
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
    }
    else if(pause_start==0){
        timer->start(1000);
        ui->start_pause->setIcon(QIcon(":/icons/icons/pause(2).svg"));
        pause_start=1;
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
            ui->time->setText(QString("%1").arg(second));
        }
        else {
            ui->time->setText(QString("%1:%2").arg(minute).arg(second));
        }
    }
    else{
        ui->time->setText(QString("%1:%2:%3").arg(hour).arg(minute).arg(second));
    }
}

void MainWindow::on_reset_clicked()
{
    timer->stop();
    second=0;
    minute=0;
    hour=0;
    ui->time->setText(QString("%1").arg(second));
    pause_start=0;
    ui->start_pause->setIcon(QIcon(":/icons/icons/play(1).svg"));
}




void MainWindow::on_about_triggered()
{
    QMessageBox::about(this,"Hakkında","Bu uygulama <b>Emrullah Enis Çetinkaya</b> tarafından"
                                         " QT ile açık kaynak olarak geliştirilmektedir.<br></br>"
                                         "<a href=\"https://youtube.com/@teknolojimuhafizi?feature=shared\">Youtube sayfası</a>");
}

