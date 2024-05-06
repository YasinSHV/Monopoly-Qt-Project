#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();
    Ui::MenuWindow *ui;

private:
};

#endif // MENUWINDOW_H
