#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>

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

void MainWindow::on_pushButton_2_clicked()
{
    ui->widget->tableWidget()->setColumnCount(ui->widget->tableWidget()->horizontalHeader()->count() + 1);
}

void MainWindow::on_pushButton_clicked()
{
    ui->widget->tableWidget()->setColumnCount(ui->widget->tableWidget()->horizontalHeader()->count() - 1);
}
