#include "mainwindow.hh"
#include "ui_mainwindow.h"

#include <iostream>
#include <QFile>
#include <string>
#include <QRegExp>

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

void MainWindow::on_matchCheckBox_clicked(bool checked)
{
    if(checked)
        checked_ = true;
    else
        checked_ = false;
}

void MainWindow::on_fileLineEdit_editingFinished()
{
    filename_ = ui->fileLineEdit->text();
}

void MainWindow::on_keyLineEdit_editingFinished()
{
    key_ = ui->keyLineEdit->text();
}

void MainWindow::on_findPushButton_clicked()
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
                QStringList words = line.split(" ");
                foreach(QString word, words)
                {
                    if(checked_ == false)
                    {
                        if(word.toLower() == key_.toLower())
                        {
                            ui->textBrowser->append("Word found");
                            return;
                        }
                    }
                    else
                    {
                        if(word == key_)
                        {
                            ui->textBrowser->append("Word found");
                            return;
                        }
                    }
                }


            }
            ui->textBrowser->append("Word not found");
        }
    }
}

