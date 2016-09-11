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

    Q_ASSERT_X(headerView, "layout", "no table columns to track");
    if (!headerView) {
        return;
    }

    Q_ASSERT_X(headerView->count() == count(), "layout", "there must be as many items in the layout as there are columns in the table");
    if (headerView->count() != count()) {
        return;
    }

    Q_ASSERT(parentWidget());

    int widgetX = parentWidget()->mapToGlobal(QPoint(0, 0)).x();
    int headerX = headerView->mapToGlobal(QPoint(0, 0)).x();
    int delta = headerX - widgetX;

    for (int ii = 0; ii < headerView->count(); ++ii) {
        int pos = headerView->sectionViewportPosition(ii);
        int size = headerView->sectionSize(ii);

        auto item = itemAt(ii);
        auto r = item->geometry();
        r.setLeft(pos + delta);
        r.setWidth(size);
        item->setGeometry(r);
    }
}
