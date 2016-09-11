# Column Aligned Layout

This layout tracks a table's columns. It inherits from QHBoxLayout, and it
arranges its child items so that each one is exactly above a certain column.

![](demo.gif)

## Usage

    alignedLayout = new ColumnAlignedLayout();
    alignedLayout->addWidget(new QLineEdit(this));
    alignedLayout->addWidget(new QLineEdit(this));
    alignedLayout->addWidget(new QLineEdit(this));
    alignedLayout->addWidget(new QLineEdit(this));
    ui->widget->setLayout(alignedLayout);
    alignedLayout->setTableColumnsToTrack(ui->tableWidget->horizontalHeader());
    alignedLayout->setParent(ui->widget);
    connect(ui->tableWidget->horizontalHeader(), SIGNAL(sectionResized(int,int,int)), SLOT(invalidateAlignedLayout()));
    connect(ui->tableWidget->horizontalScrollBar(), SIGNAL(valueChanged(int)), SLOT(invalidateAlignedLayout()));

And then in the slot call `invalidate()`:

    void MainWindow::invalidateAlignedLayout()
    {
        alignedLayout->invalidate();
    }


