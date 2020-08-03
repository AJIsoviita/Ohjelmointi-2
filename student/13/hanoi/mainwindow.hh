#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QGraphicsView>
#include <QPen>
#include <QList>

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

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene_;
    QVector<QGraphicsRectItem*> discs_;
    QVector<QGraphicsRectItem*> pole1_;
    QVector<QGraphicsRectItem*> pole2_;
    QVector<QGraphicsRectItem*> pole3_;

    QGraphicsRectItem* disc_;


    QTimer timer_;          // for continuous moving
    int disc_amount_ = 7;   // for setting amount of discs

    const int center_ = 340;
    const int step_ = 170;
    const int bottom_ = 250;
    const int pole_height = 132;

    int dy_ = 0;

    const int BORDER_UP = 0;
    const int BORDER_DOWN = 260;
    const int BORDER_LEFT = 0;
    const int BORDER_RIGHT = 680;
};

#endif // MAINWINDOW_HH
