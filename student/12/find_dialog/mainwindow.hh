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

    void on_findPushButton_clicked();

    void on_matchCheckBox_clicked(bool checked);

    void on_fileLineEdit_editingFinished();

    void on_keyLineEdit_editingFinished();

private:
    Ui::MainWindow *ui;
    bool checked_ = false;
    QString filename_ = "";
    QString key_ = "";
};

#endif // MAINWINDOW_HH
