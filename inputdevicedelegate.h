#ifndef INPUTDEVICEDELEGATE_H
#define INPUTDEVICEDELEGATE_H

#include <QStyledItemDelegate>
#include <QModelIndex>
#include <QStandardItemModel>

class InputDeviceDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    InputDeviceDelegate(QObject *parent = 0);

    void paint(QPainter * painter,const QStyleOptionViewItem & option,const QModelIndex & index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

signals:
    void sig_click(const QString&) const;
};

#endif // INPUTDEVICEDELEGATE_H
