#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "divresultwindow.h"
#include "mulresultwindow.h"
#include <QtGlobal>
#include <QTime>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize random seed
    qsrand(QTime::currentTime().msec());

    // Connect (DIV mode)
    ui->groupBox_3->setVisible(false);
    ui->div_res_no->connect(ui->div_res_no, SIGNAL(clicked(bool)), this, SLOT(divclicked()));
    ui->div_res_yes->connect(ui->div_res_yes, SIGNAL(clicked(bool)), this, SLOT(divclicked()));
    ui->div_res_mix->connect(ui->div_res_mix, SIGNAL(clicked(bool)), this, SLOT(divclicked()));
    ui->horizontalSlider->connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(divchangeslider()));
    ui->div_num_v->connect(ui->div_num_v, SIGNAL(valueChanged(int)), this, SLOT(divchangevaluev()));
    ui->div_num_l->connect(ui->div_num_l, SIGNAL(valueChanged(int)), this, SLOT(divchangevaluel()));
    ui->div_generate->connect(ui->div_generate, SIGNAL(clicked()), this, SLOT(divsubmit()));

    // Connect (MUL mode)
    ui->groupBox_5->setVisible(false);
    ui->mul_no->connect(ui->mul_no, SIGNAL(clicked(bool)), this, SLOT(mulclicked()));
    ui->mul_yes->connect(ui->mul_yes, SIGNAL(clicked(bool)), this, SLOT(mulclicked()));
    ui->mul_generate->connect(ui->mul_generate, SIGNAL(clicked()), this, SLOT(mulsubmit()));

    // Set Window Title
    QString title = QString::fromLocal8Bit("算数問題作成");
    this->setWindowTitle(title);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//
// Slots (DIV mode)
//
void MainWindow::divclicked()
{
    if (ui->div_res_mix->isChecked()) {
        ui->groupBox_3->setVisible(true);
    } else {
        ui->groupBox_3->setVisible(false);
    }
}

void MainWindow::divchangeslider()
{
    ui->div_num_v->setValue(ui->horizontalSlider->value());
}

void MainWindow::divchangevaluev()
{
    ui->horizontalSlider->setValue(ui->div_num_v->value());
}

void MainWindow::divchangevaluel()
{
    int l = ui->div_num_l->value();
    ui->horizontalSlider->setRange(1, l);
    ui->div_num_v->setRange(1, l);
}

void MainWindow::divsubmit()
{
    // Get Values
    int a = ui->div_num_a->value();
    int b = ui->div_num_b->value();
    int l = ui->div_num_l->value();
    int v = ui->div_num_v->value();
    int f;
    if (ui->div_res_no->isChecked()) {
        f = 0;
    } else if (ui->div_res_yes->isChecked()) {
        f = 1;
    } else {
        f = 2;
    }

    if (a < b) {
        QString m1 = QString::fromLocal8Bit("エラー");
        QString m2 = QString::fromLocal8Bit("割る数が大きすぎます");
        QMessageBox::critical(this, m1, m2);
    } else {
        DivResultWindow* rw = new DivResultWindow(a, b, l, v, f);
        rw->setWindowFlags(Qt::Window);
        rw->show();
    }
    return;
}


//
// Slots (MUL mode)
//
void MainWindow::mulclicked()
{
    if (ui->mul_yes->isChecked()) {
        ui->groupBox_5->setVisible(true);
    } else {
        ui->groupBox_5->setVisible(false);
    }
}

void MainWindow::mulsubmit()
{
    // Get Values
    int a = ui->mul_num_a->value();
    int b = ui->mul_num_b->value();
    int c = ui->mul_num_c->value();
    int d = ui->mul_num_d->value();
    int l = ui->mul_num_l->value();

    if (ui->mul_no->isChecked()) {
        c = 0;
        d = 0;
    }

    if (((a + b + c + d) > 9)) {
        QString m1 = QString::fromLocal8Bit("エラー");
        QString m2 = QString::fromLocal8Bit("桁が大きすぎます");
        QMessageBox::critical(this, m1, m2);
    } else {
        MulResultWindow* rw = new MulResultWindow(a, b, c, d, l);
        rw->setWindowFlags(Qt::Window);
        rw->show();
    }
    return;
}
