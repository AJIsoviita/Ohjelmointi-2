#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>

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

    void on_heightLineEdit_editingFinished();

    void on_countButton_clicked();

    void on_weightLineEdit_editingFinished();

private:
    Ui::MainWindow *ui;
    float weight_ = 0;
    float height_ = 0;
    float bmi_ = 0;
};

#endif // MAINWINDOW_HH
