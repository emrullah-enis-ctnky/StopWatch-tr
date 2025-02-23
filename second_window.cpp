#include "second_window.h"
#include "ui_second_window.h"
#include "QTimer"
QString minute_variable=0;
QString hour_variable=0;
QString second_variable=0;
second_window::second_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::second_window)
{
    ui->setupUi(this);
    QTimer *timer;
    timer=new QTimer();

    third_window=new time_set_window(this);
    connect(ui->stopwatch,&QAction::triggered,this,&second_window::main_window_show);
    connect(ui->about,&QAction::triggered,this,&second_window::about_triggered);
    connect(ui->time_set,SIGNAL(clicked()),this,SLOT(time_set_triggered()));
    connect(third_window,SIGNAL(push_button_clicked()),this,SLOT(third_window_set()));
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
    second_variable=third_window->line_edit_second_func();
    minute_variable=third_window->line_edit_minute_func();
    hour_variable=third_window->line_edit_hour_func();

    //ui->label_time->setText();//buradan devam edilecek
    this->show();
}
