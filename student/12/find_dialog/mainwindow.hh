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

    void on_matchcheckBox_clicked(bool checked);

    void on_fileLineEdit_textEdited(const QString &arg1);

    void on_keyLineEdit_textEdited(const QString &arg1);

    void on_findpushButton_clicked();

private:
    Ui::MainWindow *ui;
    bool checked_ = false;
    QString filename_ = "";
    QString key_ = "";
};

#endif // MAINWINDOW_HH
