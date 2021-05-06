#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QObjectUserData>
#include <QSortFilterProxyModel>

class QComboBox;
class ComboItemInputDevice;
class QListWidget;
class QListView;
class QLabel;
class QStandardItemModel;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);

    void addItem(const QString&);

    ~Widget();

public slots:
    void slot_current_text(const QString&) const;
    void slot_index_click(const QModelIndex &index);

private:
    QComboBox* _combo;
    QListView* _listWidget;
    QStandardItemModel* _model;
    QSortFilterProxyModel* _proxyModel;
};

//自定义的comboBox item类
class ComboItemInputDevice : public QWidget
{
public:
    ComboItemInputDevice(const QString&, QWidget* parent = 0);

    void setText(const QString&);

private:
    QLabel* _cont;
};

#endif // WIDGET_H
