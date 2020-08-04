#include "mainwindow.hh"
#include "ui_mainwindow.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <QDebug>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Adding graphic scene to MainWindow
    ui->setupUi(this);
    scene_ = new QGraphicsScene(this);
    int left_margin = 10;
    int top_margin = 270;
    ui->graphicsView->setGeometry(left_margin, top_margin,
                                   BORDER_RIGHT + 2, BORDER_DOWN + 2);
    ui->graphicsView->setScene(scene_);

    // Adding poles to graphic scene
    QPen pole(Qt::black);
    pole.setWidth(4);
    scene_->addLine(QLine(center_, 100, center_, 250), pole);
    scene_->addLine(QLine(center_ - step_, 100, center_ - step_, 250), pole);
    scene_->addLine(QLine(center_ + step_, 100, center_ + step_, 250), pole);

    // Adding discs to graphic scene
    int amount_of_discs = 0; // Counting amount of discs

    QPen border (Qt::black);
    border.setWidth(1);

    int x = 120;
    int y = 250;
    int s = 100;
    int h = 20;
    while(amount_of_discs < disc_amount_)
    {
        QGraphicsRectItem* disc = scene_->addRect(QRect(x, y ,s ,h), border, disc_color_);
        pole1_.append(disc);
        pole1_numbers_.push_back(amount_of_discs);
        amount_of_discs++;
        x += 5;
        y -= 22;
        s -= 10;
    }
    // Counting minimum amount of moves
    win_numbers_ = pole1_numbers_;
    min_moves = pow(2, disc_amount_) - 1;
    ui->min_moves->display(min_moves);
    ui->current_mov->display(current_moves);

    // Connecting timer to method
    timer_ = new QTimer();
    connect(timer_, &QTimer::timeout, this, &MainWindow::show_time);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PBAB_clicked()
// Moving disc from pole 1 to pole 2
{

    disc_ = pole1_.back();

    dy_ = ((pole1_.size() - pole2_.size()) * 22) - 22;

    if(pole1_.size() == pole2_.size())
        disc_->moveBy(step_, -22);
    else
        disc_->moveBy(step_, dy_);

    disc_->setBrush(Qt::cyan);

    pole2_.append(disc_);
    pole1_.pop_back();

    pole2_numbers_.push_back(pole1_numbers_.back());
    pole1_numbers_.pop_back();

    is_winner();
    current_moves++;
    ui->current_mov->display(current_moves);

    if(!(timer_->isActive()))
        timer_->start(1000);
}

void MainWindow::on_PBAC_clicked()
// Moving disc from pole 1 to pole 3
{
    disc_ = pole1_.back();

    dy_ = ((pole1_.size() - pole3_.size()) * 22) - 22;

    if(pole1_.size() == pole3_.size())
        disc_->moveBy(2 * step_, -22);
    else
        disc_->moveBy(2 * step_, dy_);

    disc_->setBrush(Qt::blue);

    pole3_.append(disc_);
    pole1_.pop_back();

    pole3_numbers_.push_back(pole1_numbers_.back());
    pole1_numbers_.pop_back();

    is_winner();
    current_moves++;
    ui->current_mov->display(current_moves);

    if(!(timer_->isActive()))
        timer_->start(1000);

}

void MainWindow::on_PBBA_clicked()
// Moving disc from pole 2 to pole 1
{
    disc_ = pole2_.back();

    dy_ = ((pole2_.size() - pole1_.size()) * 22) - 22;

    if(pole2_.size() == pole1_.size())
        disc_->moveBy(-step_, -22);
    else
        disc_->moveBy(-step_, dy_);

    disc_->setBrush(Qt::yellow);

    pole1_.append(disc_);
    pole2_.pop_back();

    pole1_numbers_.push_back(pole2_numbers_.back());
    pole2_numbers_.pop_back();

    is_winner();
    current_moves++;
    ui->current_mov->display(current_moves);
}

void MainWindow::on_PBBC_clicked()
// Moving disc from pole 2 to pole 3
{
    disc_ = pole2_.back();

    dy_ = ((pole2_.size() - pole3_.size()) * 22) - 22;

    if(pole2_.size() == pole3_.size())
        disc_->moveBy(step_, -22);
    else
        disc_->moveBy(step_, dy_);

    disc_->setBrush(Qt::blue);

    pole3_.append(disc_);
    pole2_.pop_back();

    pole3_numbers_.push_back(pole2_numbers_.back());
    pole2_numbers_.pop_back();

    is_winner();
    current_moves++;
    ui->current_mov->display(current_moves);
}

void MainWindow::on_PBCA_clicked()
// Moving disc from pole 3 to pole 1
{
    disc_ = pole3_.back();

    dy_ = ((pole3_.size() - pole1_.size()) * 22) - 22;

    if(pole3_.size() == pole1_.size())
        disc_->moveBy(-2 * step_, -22);
    else
        disc_->moveBy(-2 * step_, dy_);

    disc_->setBrush(Qt::yellow);

    pole1_.append(disc_);
    pole3_.pop_back();

    pole1_numbers_.push_back(pole3_numbers_.back());
    pole3_numbers_.pop_back();

    is_winner();
    current_moves++;
    ui->current_mov->display(current_moves);
}

void MainWindow::on_PBCB_clicked()
// Moving disc rom pole 3 to pole 2
{
    disc_ = pole3_.back();

    dy_ = ((pole3_.size() - pole2_.size()) * 22) - 22;

    if(pole3_.size() == pole2_.size())
        disc_->moveBy(-step_, -22);
    else
        disc_->moveBy(-step_, dy_);

    disc_->setBrush(Qt::cyan);

    pole2_.append(disc_);
    pole3_.pop_back();

    pole2_numbers_.push_back(pole3_numbers_.back());
    pole3_numbers_.pop_back();

    is_winner();
    current_moves++;
    ui->current_mov->display(current_moves);
}

void MainWindow::is_winner()
// To check if player has won
{
    if(pole2_numbers_ == win_numbers_)
    {
        win_ = true;
        ui->WinnerLabel->setText("You have won \n the game.");
        timer_ -> stop();
    }
    else if(pole3_numbers_ == win_numbers_)
    {
        win_ = true;
        ui->WinnerLabel->setText("You have won \n the game.");
        timer_ -> stop();
    }
    else
    {
        win_ = false;
        ui->WinnerLabel->setText("Game is\n not complete");
    }
}

void MainWindow::show_time()
// Updating clock
{
    seconds_++;
    if(seconds_ == 60)
    {
        seconds_ = 0;
        minutes_++;
    }

    ui->Seconds->display(seconds_);
    ui->Minutes->display(minutes_);
}

