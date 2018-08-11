#ifndef FILTEREDTABLEWIDGET_H
#define FILTEREDTABLEWIDGET_H

class ColumnAlignedLayout;

#include <QWidget>

namespace Ui {
class FilteredTableWidget;
}

class FilteredTableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FilteredTableWidget(QWidget *parent = 0);
    ~FilteredTableWidget();

private slots:
    void invalidateAlignedLayout();

private:
    Ui::FilteredTableWidget *ui;
    ColumnAlignedLayout *alignedLayout;
};

#endif // FILTEREDTABLEWIDGET_H
