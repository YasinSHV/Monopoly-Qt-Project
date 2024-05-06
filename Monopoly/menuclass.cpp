#include "menuclass.h"
#include "qicon.h"
#include "ui_menuclass.h"
#include <qstyle.h>

MenuClass::MenuClass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuClass)
{
    ui->setupUi(this);

    for(int i = 2; i <= 8; i++)
    {
      QString a = QString::number(i);
      ui->comboBox->addItem(a);
    }

    QString path = QString(":/board/cards/Assets/menuBack.png");
    QPixmap image(path);
    QIcon icon = style()->standardIcon(QStyle::SP_DialogOkButton);
    icon = QIcon(path);
    QPixmap pixmap = icon.pixmap(QSize(300, 300));
    ui->back->setPixmap(pixmap);
    setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);
}

MenuClass::~MenuClass()
{
    delete ui;
}
