#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_weightLineEdit_editingFinished()
{
    QString weight = (ui->weightLineEdit->text());
    weight_ = weight.toFloat();
}

void MainWindow::on_heightLineEdit_editingFinished()
{
    QString height = (ui->heightLineEdit->text());
    height_= height.toFloat();
}

void MainWindow::on_countButton_clicked()
{
    bmi_ = weight_ / ((height_/100) * (height_/100));
    ui->infoTextBrowser->clear();
    QString bmi = QString::number(bmi_);
    ui->resultLabel->setText((bmi));
    if (bmi_ < 18.5)
        ui->infoTextBrowser->append("You are underweight.");
    else if(bmi_ > 25)
        ui->infoTextBrowser->append("You are overweight.");
    else
        ui->infoTextBrowser->append("Your weight is normal.");
}


