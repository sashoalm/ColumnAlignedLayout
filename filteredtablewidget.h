#ifndef FILTEREDTABLEWIDGET_H
#define FILTEREDTABLEWIDGET_H

class ColumnAlignedLayout;
class QTableWidget;
class QLineEdit;

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

    QTableWidget *tableWidget();
    QLineEdit *columnFilter(int columnIndex);

private slots:
    void invalidateAlignedLayout();
    void onSectionCountChanged(int oldCount, int newCount);

private:
    Ui::FilteredTableWidget *ui;
    ColumnAlignedLayout *alignedLayout;
};

#endif // FILTEREDTABLEWIDGET_H
