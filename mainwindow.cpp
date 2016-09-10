#include "columnalignedlayout.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    alignedLayout = new ColumnAlignedLayout();
    alignedLayout->addWidget(new QLineEdit(this));
    alignedLayout->addWidget(new QLineEdit(this));
    ui->verticalLayout->insertItem(0, alignedLayout);
    alignedLayout->setTableColumnsToTrack(ui->tableWidget->horizontalHeader());
    alignedLayout->setParent(ui->verticalLayout);
    connect(ui->tableWidget->horizontalHeader(), SIGNAL(sectionResized(int,int,int)), SLOT(onTableColumnsResized(int,int,int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTableColumnsResized(int logicalIndex, int oldSize, int newSize)
{
    alignedLayout->invalidate();
}
