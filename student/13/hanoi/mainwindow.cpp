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
        QBrush disc_color(Qt::yellow);
        QGraphicsRectItem* disc = scene_->addRect(QRect(x, y ,s ,h), border, disc_color);
        pole1_.append(disc);
        pole1_numbers_.push_back(amount_of_discs);
        amount_of_discs++;
        x += 5;
        y -= 22;
        s -= 10;
    }

    win_numbers_ = pole1_numbers_;
    min_moves = pow(2, disc_amount_) - 1;
    ui->min_moves->display(min_moves);
    ui->current_mov->display(current_moves);
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

    pole2_.append(disc_);
    pole1_.pop_back();

    is_winner();
    current_moves++;
    ui->current_mov->display(current_moves);
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

    pole3_.append(disc_);
    pole1_.pop_back();

    is_winner();
    current_moves++;
    ui->current_mov->display(current_moves);
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

    pole1_.append(disc_);
    pole2_.pop_back();

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

    pole3_.append(disc_);
    pole2_.pop_back();

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

    pole1_.append(disc_);
    pole3_.pop_back();

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

    pole2_.append(disc_);
    pole3_.pop_back();

    is_winner();
    current_moves++;
    ui->current_mov->display(current_moves);
}

void MainWindow::is_winner()
{
    if(pole2_numbers_ == win_numbers_)
        status_ = true;
    else if(pole3_numbers_ == win_numbers_)
        status_ = true;
    else
        status_ = false;
}

