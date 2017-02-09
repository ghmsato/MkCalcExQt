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

public slots:
    // DIV mode
    void divclicked();
    void divchangeslider();
    void divchangevaluev();
    void divchangevaluel();
    void divsubmit();
    // MUL mode
    void mulclicked();
    void mulsubmit();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
