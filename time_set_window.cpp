#include "time_set_window.h"
#include "ui_time_set_window.h"

time_set_window::time_set_window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::time_set_window)
{
    ui->setupUi(this);
    setWindowTitle("Zamanı Ayarla");
    setWindowFlags(Qt::Window);
    connect(ui->pushButton_time_set,SIGNAL(clicked()),this,SIGNAL(push_button_clicked()));
    QIntValidator *validator=new QIntValidator(0,59,ui->lineEdit_hour);
    ui->lineEdit_hour->setValidator(validator);
    QIntValidator *validator2=new QIntValidator(0,59,ui->lineEdit_minute);
    ui->lineEdit_minute->setValidator(validator2);
    QIntValidator *validator3=new QIntValidator(0,59,ui->lineEdit_second);
    ui->lineEdit_second->setValidator(validator3);
}

time_set_window::~time_set_window()
{
    delete ui;
}

QString time_set_window::line_edit_second_func()
{
    return ui->lineEdit_second->text();
}

QString time_set_window::line_edit_minute_func()
{
    return ui->lineEdit_minute->text();
}

QString time_set_window::line_edit_hour_func()
{
    return ui->lineEdit_hour->text();
}
void time_set_window::line_edit_clear(){
    ui->lineEdit_second->clear();
    ui->lineEdit_hour->clear();
    ui->lineEdit_minute->clear();
}
void time_set_window::closeEvent(QCloseEvent *event){
    line_edit_clear();
    emit close_event_signal();
}
