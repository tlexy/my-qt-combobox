#include "widget.h"
#include <QComboBox>
#include <QListWidget>
#include <QListView>
#include <QHBoxLayout>
#include <QLabel>
#include "inputdevicedelegate.h"
#include <QStandardItemModel>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    _combo = new QComboBox();
    _listWidget = new QListView();
    _listWidget->setViewMode(QListView::ListMode);
    InputDeviceDelegate* deleg = new InputDeviceDelegate();
    _listWidget->setItemDelegate(deleg);
    _listWidget->setSpacing(0);

    _model = new QStandardItemModel();
    _proxyModel = new QSortFilterProxyModel(_listWidget);
    _proxyModel->setSourceModel(_model);
    //_model->setHeaderData(1, Qt::Horizontal, QVariant::fromValue(tr("咐咐舍")),Qt::UserRole);

    connect(_combo, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
          [=](const QString &text){
        qDebug() << "change: " << text;
        QModelIndexList list = _listWidget->selectionModel()->selectedIndexes();
         foreach (QModelIndex sourceIndex, list){
            QString text1 = sourceIndex.data(Qt::UserRole).value<QString>();
            qDebug() <<"select index: " << text1;
            //_combo->setEditText(text1);
            _combo->setCurrentText(text1);
         }
    });
    connect(deleg, &InputDeviceDelegate::sig_click, this, &Widget::slot_current_text);

    connect(_listWidget, &QListView::clicked, this, &Widget::slot_index_click);

    _listWidget->setModel(_proxyModel);


    //必须先调用setModel
    _combo->setModel(_listWidget->model());
    _combo->setView(_listWidget);
    _combo->setEditable(true);
    //_combo->setInsertPolicy(QComboBox::InsertAtCurrent);
    _combo->setStyleSheet(QString("QComboBox{font-size: 16px;"
                                  "height:30px;"
                                  "min-width: 150px;"
                                  "margin-left:3px;"
                                  "border-style:solid;"
                                  "border-top-left-radius:13px;"
                                  "border-bottom-left-radius: 13px;"
                                  "background-color:rgb(64,66,68);"
                                  "}"));

    //_listWidget->model()->setHeaderData(0, Qt::Horizontal, QVariant::fromValue(tr("咐咐舍")),Qt::UserRole);
    //_combo->addItem(tr("咐咐舍"));
    QHBoxLayout* hMainLayout = new QHBoxLayout();
    hMainLayout->setContentsMargins(0,0,0,0);
    hMainLayout->setMargin(0);
    hMainLayout->addWidget(_combo);

    setContentsMargins(0,0,0,0);
    setLayout(hMainLayout);
}

Widget::~Widget()
{

}

void Widget::slot_index_click(const QModelIndex &index)
{
    qDebug() << "slot_index_click";
}

void Widget::slot_current_text(const QString& text) const
{
    qDebug() << text;
    //_combo->setCurrentText(text);
}

void Widget::addItem(const QString& text)
{
    //_combo->addItem(text);
    QStandardItem *item = new QStandardItem;
    item->setData(QVariant::fromValue(text),Qt::UserRole);
    _model->appendRow(item);
    qDebug() << "rowCount: " << _model->rowCount();
    if (_model->rowCount() == 1)
    {
        _combo->setCurrentText(text);
    }
    //QWidget* item = new ComboItemInputDevice(text);
    //item->setFixedHeight(47);
    //int pos = _listWidget->count() - 1 < 0 ? 0 : _listWidget->count() - 1;
    //_listWidget->insertItem(pos, new QListWidgetItem());
    //_listWidget->setItemWidget(_listWidget->item(pos), item);

    //_combo->setEditText(text);
    //_combo->setCurrentText(text);

}

/////////////////////////////////-----------
///
ComboItemInputDevice::ComboItemInputDevice(const QString& text, QWidget* parent)
    :QWidget(parent)
{
    _cont = new QLabel(text);


    QHBoxLayout* hMainLayout = new QHBoxLayout();
    hMainLayout->setContentsMargins(0,0,0,0);
    hMainLayout->setMargin(0);
    hMainLayout->addWidget(_cont);

    setContentsMargins(0,0,0,0);
    setLayout(hMainLayout);
}
