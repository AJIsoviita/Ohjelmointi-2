/*
 * GUI Projekti: Hanoin Torni
 * Isoviita Antti-Jussi
 * antti-jussi.isoviita@tuni.fi 283435
 *
 * Description;
 * Program is a game of Towers of Hanoi. Player can move discs between poles
 * using pushbuttons. Game measures time and made moves and shows them during game.
 * Game calculates amount of minimum moves using 2^number of discs -1 formula.
 * Game informs player of the state of the game and if player has won, all the
 * buttons are hidden.
*/

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
    // Move disc from pole 1 to pole 2
    void on_PBAB_clicked();
    // Move disc from pole 1 to pole 3
    void on_PBAC_clicked();
    // Move disc from pole 2 to pole 1
    void on_PBBA_clicked();
    // Move disc from pole 2 to pole 3
    void on_PBBC_clicked();
    // Move disc from pole 3 to pole 1
    void on_PBCA_clicked();
    // Move disc from pole 3 to pole 2
    void on_PBCB_clicked();
    // To determine if player has won
    void is_winner();
    // Display game time
    void show_time();
    // Hide unplayable buttons
    void hide();
    // Reveal pushbuttons
    void reveal();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene_;

    // To store discs
    QVector<QGraphicsRectItem*> pole1_;
    QVector<QGraphicsRectItem*> pole2_;
    QVector<QGraphicsRectItem*> pole3_;

    // To keep track of discs
    vector<int> win_numbers_;
    vector<int> pole1_numbers_;
    vector<int> pole2_numbers_;
    vector<int> pole3_numbers_;

    // Calculating current and maximum moves
    int min_moves = 0;
    int current_moves = 0;

    // Has player won
    bool win_ = false;

    QGraphicsRectItem* disc_;

    // To display and measure time
    QTimer* timer_;
    int seconds_ = 0;
    int minutes_ = 0;

    // For setting amount of discs
    int disc_amount_ = 7;

    // Values, that are used in many functions
    const int center_ = 340;
    const int step_ = 170;
    const int bottom_ = 250;
    const int pole_height = 132;

    // For calculating the height of the movement on y-axis
    int dy_ = 0;

    // For setting scene
    const int BORDER_UP = 0;
    const int BORDER_DOWN = 260;
    const int BORDER_LEFT = 0;
    const int BORDER_RIGHT = 680;
};

#endif // MAINWINDOW_HH
