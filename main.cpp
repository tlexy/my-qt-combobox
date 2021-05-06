#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.addItem(QString("abced"));
    w.addItem(QString("开心呀"));
    w.addItem(QString("HighDefinition"));
    w.addItem(QString("Audio"));
    w.addItem(QString("fffdfdfd"));


    w.show();

    return a.exec();
}
