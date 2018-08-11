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
    connect(ui->tableWidget->horizontalHeader(), SIGNAL(sectionCountChanged(int,int)), SLOT(onSectionCountChanged(int,int)));
}

FilteredTableWidget::~FilteredTableWidget()
{
    delete ui;
}

QTableWidget *FilteredTableWidget::tableWidget()
{
    return ui->tableWidget;
}

void FilteredTableWidget::invalidateAlignedLayout()
{
    alignedLayout->invalidate();
}

void FilteredTableWidget::onSectionCountChanged(int oldCount, int newCount)
{
    Q_UNUSED(oldCount);

    while (alignedLayout->count() > newCount) {
        QWidget *w = alignedLayout->itemAt(alignedLayout->count() - 1)->widget();
        alignedLayout->removeWidget(w);
        delete w;
    }

    while (alignedLayout->count() < newCount) {
        alignedLayout->addWidget(new QLineEdit(this));
    }
}
