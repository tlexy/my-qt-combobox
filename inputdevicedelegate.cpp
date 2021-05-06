#include "inputdevicedelegate.h"
#include <QPainter>

InputDeviceDelegate::InputDeviceDelegate(QObject *parent)
    :QStyledItemDelegate(parent)
{

}

void InputDeviceDelegate::paint(QPainter * painter,const QStyleOptionViewItem & option,const QModelIndex & index) const
{
    if(!index.isValid())
    {
        return;
    }
    painter->save();

    QRectF rect;
    rect.setX(option.rect.x());
    rect.setY(option.rect.y());
    rect.setWidth( option.rect.width()-1);
    rect.setHeight(option.rect.height()-1);

    QVariant variant = index.data(Qt::UserRole);
    QString data = variant.value<QString>();

    if(option.state.testFlag(QStyle::State_Sunken))
    {

    }

    if(option.state.testFlag(QStyle::State_Selected))
    {
        painter->setPen(QPen(Qt::blue));
        painter->setBrush(QColor(252, 245, 221));
        emit sig_click(data);
    }
    else if(option.state.testFlag(QStyle::State_MouseOver))
    {
        painter->setPen(QPen(Qt::green));
        painter->setBrush(Qt::NoBrush);
    }
    else{
        painter->setPen(QPen(Qt::gray));
        painter->setBrush(Qt::NoBrush);
    }
    painter->fillRect(rect, painter->brush());

    painter->drawText(rect.toRect(), data);

    QPainterPath path;
    path.addEllipse(QRect(rect.x() + 80, rect.y() + 1, 30, 30));
    painter->fillPath(path, QColor(58, 47, 113, 55));

    painter->restore();
}

QSize InputDeviceDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(320, 32);
}
