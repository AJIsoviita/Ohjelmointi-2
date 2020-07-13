#include "mainwindow.hh"
#include "ui_mainwindow.h"

#include <iostream>
#include <QFile>
#include <string>
#include <algorithm>

using namespace std;

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

void MainWindow::on_matchcheckBox_clicked(bool checked)
{
    if(checked)
        checked_ = true;
    else
        checked_ = false;
}

void MainWindow::on_fileLineEdit_textEdited(const QString &arg1)
{
    filename_ = arg1;
}

void MainWindow::on_keyLineEdit_textEdited(const QString &arg1)
{
    key_ = arg1;
}

void MainWindow::on_findpushButton_clicked()
{
    ui->textBrowser->clear();
    QFile input(filename_);
    if(!input.open(QIODevice::ReadOnly | QIODevice::Text))
        ui->textBrowser->append("File not found");
    else
    {
        if(key_ == "")
            ui->textBrowser->append("File found");
        else
        {
            while(!input.atEnd())
            {
                QString line = input.readLine();
                if(checked_ == false)
                {
                    if(line.contains(key_, Qt::CaseInsensitive))
                        ui->textBrowser->append("Word found");
                    else
                        ui->textBrowser->append("Word not found");
                }
                else
                {
                    if(line.contains(key_, Qt::CaseSensitive))
                        ui->textBrowser->append("Word found");
                    else
                        ui->textBrowser->append("Word not found");
                }

            }
        }
    }
}
