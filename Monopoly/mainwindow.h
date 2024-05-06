#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "chestandchance.h"
#include <QMediaPlaylist>
#include "qpushbutton.h"
#include <QMediaPlayer>
#include "housecards.h"
#include "menuclass.h"
#include <QMainWindow>
#include <QPainter>
#include "player.h"
#include "qlabel.h"
#include <QTimer>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_RollButton_pressed();
    void hButtonPressed();
    void GetComboBoxValue();

    void on_lineEdit_returnPressed();

    void on_lineEdit_textChanged(const QString &arg1);


    void on_buyButton_clicked();

    void on_endTurn_clicked();

    void on_pay10_clicked();

    void on_pay200_clicked();

    void on_mortgage_clicked();

    void on_unmortgage_clicked();

    void on_getout_clicked();

    void on_jailfree_clicked();

    void on_houseBuy_clicked();

    void on_houseSell_clicked();

    void on_passButton_clicked();


    void on_bidBox_valueChanged(int arg1);

    void on_submit_clicked();

    void on_offerButton_clicked();


    void on_offerBox_valueChanged(int arg1);


    void on_Accept_clicked();

    void on_Reject_clicked();

private:
    Ui::MainWindow *ui;
    QIcon DieIcon[6];
    HouseCards houseCards[29];
    MenuClass menu;
    Player *playerList;
    QLabel *lbArr[8];

    QPushButton *houseButtons[28];
    QMediaPlayer *music2 = new QMediaPlayer();


    ChestAndChance *comm1 = new ChestJail[2];
    ChestAndChance *comm2 = new ChestPay[14];

    ChestAndChance *Chance1 = new ChanceMove[8];
    ChestAndChance *Chance2 = new ChancePay[6];

    void updateDie();
    void updateListWidget();
    void BuildGame();
    void updatePixmapPos(int x);
    void ActionFase();
    void updateInfo();
    void GoToJail();
    void updateSets();
    void GoToDestination(int, int);

    int cardsMap[11][11] = {
                       {333,15,0,16,17,18,19,20,21,22,444},
                           {14,0,0,0,0,0,0,0,0,0,23}
                          ,{13,0,0,0,0,0,0,0,0,0,24}
                          ,{55,0,0,0,0,0,0,0,0,0,55}
                          ,{12,0,0,0,0,0,0,0,0,0,25}
                          ,{11,0,0,0,0,0,0,0,0,0,26}
                          ,{10,0,0,0,0,0,0,0,0,0,0}
                          ,{9,0,0,0,0,0,0,0,0,0,27}
                          ,{8,0,0,0,0,0,0,0,0,0,-1}
                          ,{7,0,0,0,0,0,0,0,0,0,28}
                          ,{222,6,5,0,4,3,-2,2,55,1,111}};

    int playerCount;
    int myCounter = 0;
    int turnHandler[8] = {0,1,2,3,4,5,6,7};
    int currentTurn = 0;
    int GameState = 0;
    int doubleCounter = 0;
    int chestPointer = 0, chancePointer = 0;
    int bidsList[8] = {0};

    bool actionFinished = false;
    bool rolledDouble = false;
};
#endif // MAINWINDOW_H
