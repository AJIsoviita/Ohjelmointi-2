#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QGraphicsView>
#include <QPen>
#include <QList>
#include <vector>
#include <iostream>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_PBAB_clicked();

    void on_PBAC_clicked();

    void on_PBBA_clicked();

    void on_PBBC_clicked();

    void on_PBCA_clicked();

    void on_PBCB_clicked();

    void is_winner();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene_;

    QVector<QGraphicsRectItem*> pole1_;
    QVector<QGraphicsRectItem*> pole2_;
    QVector<QGraphicsRectItem*> pole3_;

    vector<int> win_numbers_;
    vector<int> pole1_numbers_;
    vector<int> pole2_numbers_;
    vector<int> pole3_numbers_;

    int min_moves = 0;
    int current_moves = 0;

    bool status_ = false;

    QGraphicsRectItem* disc_;

    QTimer timer_;          // For continuous moving
    int disc_amount_ = 7;   // For setting amount of discs

    const int center_ = 340;
    const int step_ = 170;
    const int bottom_ = 250;
    const int pole_height = 132;

    int dy_ = 0; // For calculating the height of the movement on y-axis

    const int BORDER_UP = 0;
    const int BORDER_DOWN = 260;
    const int BORDER_LEFT = 0;
    const int BORDER_RIGHT = 680;
};

#endif // MAINWINDOW_HH
