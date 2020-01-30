#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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




    void on_radioButton_clicked();

    void on_radioButton_2_clicked();


    void on_radioButton_3_clicked();



    void on_radioButton_4_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_pushButton_clicked();




private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
