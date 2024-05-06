#ifndef MENUCLASS_H
#define MENUCLASS_H

#include <QDialog>

namespace Ui {
class MenuClass;
}

class MenuClass : public QDialog
{
    Q_OBJECT

public:
    explicit MenuClass(QWidget *parent = nullptr);
    Ui::MenuClass *ui;
    ~MenuClass();

private:

};

#endif // MENUCLASS_H
