#ifndef COLUMNALIGNEDLAYOUT_H
#define COLUMNALIGNEDLAYOUT_H

#include <QHBoxLayout>

class QHeaderView;

class ColumnAlignedLayout : public QHBoxLayout
{
    Q_OBJECT
public:
    ColumnAlignedLayout();
    explicit ColumnAlignedLayout(QWidget *parent);
    void setTableColumnsToTrack(QHeaderView *view) { columns = view; }

signals:

public slots:

private:
    void setGeometry(const QRect &r);
    QHeaderView *columns;
};

#endif // COLUMNALIGNEDLAYOUT_H
