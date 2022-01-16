#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::showTime);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    if(timer->isActive())
        return;
    else
        timer -> start(1000);
}

void MainWindow::on_resetButton_clicked()
{
    seconds_ = 0;
    minutes_ = 0;
    if(timer->isActive())
        timer -> stop();
    ui->lcdNumberSec->display(seconds_);
    ui->lcdNumberMin->display(minutes_);
}

void MainWindow::on_stopButton_clicked()
{
    timer -> stop();
}

void MainWindow::showTime()
{
    seconds_++;
    if(seconds_ == 60)
    {
        seconds_ = 0;
        minutes_++;
    }

    ui->lcdNumberSec->display(seconds_);
    ui->lcdNumberMin->display(minutes_);
}
