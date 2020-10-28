#include "mainwindow.h"
#include "ui_mainwindow.h"

double first_operand;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(write_number()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(write_number()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(write_number()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(write_number()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(write_number()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(write_number()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(write_number()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(write_number()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(write_number()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(write_number()));
    connect(ui->pushButton_plusminus,SIGNAL(clicked()),this,SLOT(operation()));
    connect(ui->pushButton_percent,SIGNAL(clicked()),this,SLOT(operation()));
    connect(ui->pushButton_divine,SIGNAL(clicked()),this,SLOT(operators()));
    connect(ui->pushButton_mul,SIGNAL(clicked()),this,SLOT(operators()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(operators()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(operators()));

    ui->pushButton_mul->setCheckable(true);
    ui->pushButton_divine->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::write_number(){
    QPushButton *button = (QPushButton *) sender();

    double numbers;

    if(ui->resultPanel->text().contains('.') && button->text()=="0"){
        ui->resultPanel->setText(ui->resultPanel->text() + button->text());
    } else{

    numbers = (ui->resultPanel->text() + button->text()).toDouble();

    ui->resultPanel->setText(QString::number(numbers, 'g', 12));
    }
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->resultPanel->text().contains('.')) ){
        ui->resultPanel->setText(ui->resultPanel->text()+'.');
    }
}
void MainWindow::operation(){
    QPushButton *button = (QPushButton *) sender();

    double numbers;

    if(button->text()== "+/-"){
    numbers = (ui->resultPanel->text()).toDouble() *(-1);

    ui->resultPanel->setText(QString::number(numbers, 'g', 12));
    } else if(button->text()== "%"){
        numbers = (ui->resultPanel->text()).toDouble() *(0.01);

        ui->resultPanel->setText(QString::number(numbers, 'g', 12));
        }
}

void MainWindow::operators()
{
    QPushButton *button = (QPushButton *) sender();

    first_operand = ui->resultPanel->text().toDouble();
    ui->resultPanel->setText("");

    ui->pushButton_mul->setChecked(false);
    ui->pushButton_divine->setChecked(false);
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);

    button->setChecked(true);

}


void MainWindow::on_pushButton_AC_clicked()
{
    ui->pushButton_mul->setChecked(false);
    ui->pushButton_divine->setChecked(false);
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);

    ui->resultPanel->setText("0");
}

void MainWindow::on_pushButton_equals_clicked()
{
    double second_Operand;

    second_Operand = ui->resultPanel->text().toDouble();

    if(ui->pushButton_plus->isChecked()){
        ui->resultPanel->setText(QString::number(first_operand + second_Operand, 'g', 12));
        ui->pushButton_plus->setChecked(false);
    }
    if(ui->pushButton_minus->isChecked()){
        ui->resultPanel->setText(QString::number(first_operand - second_Operand, 'g', 12));
     ui->pushButton_minus->setChecked(false);
    }
    if(ui->pushButton_divine->isChecked()){
        if(second_Operand!=0){
        ui->resultPanel->setText(QString::number(first_operand / second_Operand, 'g', 12));
    }else{
            ui->resultPanel->setText("0");

        }
         ui->pushButton_divine->setChecked(false);
    }
    if(ui->pushButton_mul->isChecked()){
        ui->resultPanel->setText(QString::number(first_operand * second_Operand, 'g', 12));
    }
     ui->pushButton_minus->setChecked(false);
}
