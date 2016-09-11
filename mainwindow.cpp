#include "columnalignedlayout.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLineEdit>
#include <QScrollBar>

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
    connect(ui->tableWidget->horizontalHeader(), SIGNAL(sectionResized(int,int,int)), SLOT(invalidateAlignedLayout()));
    connect(ui->tableWidget->horizontalScrollBar(), SIGNAL(valueChanged(int)), SLOT(invalidateAlignedLayout()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::invalidateAlignedLayout()
{
    alignedLayout->invalidate();
}
