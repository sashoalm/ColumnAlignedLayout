#include "columnalignedlayout.h"
#include <QHeaderView>

ColumnAlignedLayout::ColumnAlignedLayout()
    : QHBoxLayout()
{

}

ColumnAlignedLayout::ColumnAlignedLayout(QWidget *parent)
    : QHBoxLayout(parent)
{

}

void ColumnAlignedLayout::setGeometry(const QRect &r)
{
    QHBoxLayout::setGeometry(r);

    Q_ASSERT_X(columns, "layout", "no table columns to track");
    if (!columns) {
        return;
    }

    Q_ASSERT_X(columns->count() == count(), "layout", "there must be as many items in the layout as there are columns in the table");
    if (columns->count() != count()) {
        return;
    }

    Q_ASSERT(parentWidget());

    int widgetX = parentWidget()->mapToGlobal(QPoint(0, 0)).x();
    int headerX = columns->mapToGlobal(QPoint(0, 0)).x();
    int delta = headerX - widgetX;

    for (int ii = 0; ii < columns->count(); ++ii) {
        int pos = columns->sectionPosition(ii);
        int size = columns->sectionSize(ii);

        auto item = itemAt(ii);
        auto r = item->geometry();
        r.setLeft(pos + delta);
        r.setWidth(size);
        item->setGeometry(r);
    }
}
