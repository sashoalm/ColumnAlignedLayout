#include "columnalignedlayout.h"
#include "filteredtablewidget.h"
#include "ui_filteredtablewidget.h"

#include <QLineEdit>
#include <QScrollBar>

FilteredTableWidget::FilteredTableWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FilteredTableWidget)
{
    ui->setupUi(this);

    alignedLayout = new ColumnAlignedLayout();
    for (int ii = 0; ii < ui->tableWidget->horizontalHeader()->count(); ++ii) {
        alignedLayout->addWidget(new QLineEdit(this));
    }
    ui->widget->setLayout(alignedLayout);
    alignedLayout->setTableColumnsToTrack(ui->tableWidget->horizontalHeader());
    alignedLayout->setParent(ui->widget);
    connect(ui->tableWidget->horizontalHeader(), SIGNAL(sectionResized(int,int,int)), SLOT(invalidateAlignedLayout()));
    connect(ui->tableWidget->horizontalScrollBar(), SIGNAL(valueChanged(int)), SLOT(invalidateAlignedLayout()));
}

FilteredTableWidget::~FilteredTableWidget()
{
    delete ui;
}

void FilteredTableWidget::invalidateAlignedLayout()
{
    alignedLayout->invalidate();
}
