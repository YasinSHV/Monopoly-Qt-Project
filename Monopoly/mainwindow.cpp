#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "housecards.h"
#include <qstyle.h>
#include <QMessageBox>
#include "menuclass.h"
#include "ui_menuclass.h"
#include <QSound>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString path = QString(":/board/cards/Assets/GameBoard.png");
    QIcon icon = style()->standardIcon(QStyle::SP_DialogOkButton);
    icon = QIcon(path);
    QPixmap pixmap = icon.pixmap(QSize(600, 600));
    ui->Map->setPixmap(pixmap);


    DieIcon[0]= QIcon::fromTheme(":/board/cards/Assets/die1.png");
    DieIcon[1]= QIcon::fromTheme(":/board/cards/Assets/die2.png");
    DieIcon[2]= QIcon::fromTheme(":/board/cards/Assets/die3.png");
    DieIcon[3]= QIcon::fromTheme(":/board/cards/Assets/die4.png");
    DieIcon[4]= QIcon::fromTheme(":/board/cards/Assets/die5.png");
    DieIcon[5]= QIcon::fromTheme(":/board/cards/Assets/die6.png");


     QMediaPlaylist *playlist = new QMediaPlaylist();
     playlist->addMedia(QUrl("qrc:/board/cards/bgsound.wav"));
     playlist->setPlaybackMode(QMediaPlaylist::Loop);

     QMediaPlayer *music = new QMediaPlayer();
     music->setPlaylist(playlist);
     music->setVolume(15);
     music->play();

     //connect Buttons To Card Info
     for(int i = 0; i < 28; i++)
     {
         QString butName = "Button" + QString::number(i+1);
         houseButtons[i] = MainWindow::findChild<QPushButton *>(butName);
         houseButtons[i]->setText(QString::number(i+1));
         connect(houseButtons[i], SIGNAL(released()), this
                 ,SLOT(hButtonPressed()));
     }
     //end

    //Brown
    houseCards[0] = HouseCards(1, 60, 2, false, false, 10, 30, 90, 160,250);
    houseCards[1] = HouseCards(1, 60, 4, false, false, 20, 60, 180, 320,450);
    //Station1
    houseCards[2] = HouseCards(9, 200, 25, true, false, 0, 0, 0, 0,0);
    //lightBlue
    houseCards[3] = HouseCards(2, 100, 6, false, false, 30, 90, 270, 400,550);
    houseCards[4] = HouseCards(2, 100, 6, false, false, 30, 90, 270, 400,550);
    houseCards[5] = HouseCards(2, 120, 8, false, false, 40, 100, 300, 450,600);
    //Pink1
    houseCards[6] = HouseCards(3, 140, 10, false, false, 50, 150, 450, 625, 750);
    //utility1
    houseCards[7] = HouseCards(10, 150, 4, false, true, 0, 0, 0, 0,0);
    //Pink2&3
    houseCards[8] = HouseCards(3, 140, 10, false, false, 50, 150, 450, 625, 750);
    houseCards[9] = HouseCards(3, 160, 12, false, false, 60, 180, 500, 700,900);
    //Station2
    houseCards[10] = HouseCards(9, 200, 25, true, false, 0, 0, 0, 0,0);
    //Ornage
    houseCards[11] = HouseCards(4, 180, 14, false, false, 70, 200, 550, 750,950);
    houseCards[12] = HouseCards(4, 180, 14, false, false, 70, 200, 550, 750,950);
    houseCards[13] = HouseCards(4, 200, 16, false, false, 80, 220, 600, 800,1000);
    //Red
    houseCards[14] = HouseCards(5, 220, 18, false, false, 90, 250, 700, 875,1050);
    houseCards[15] = HouseCards(5, 220, 18, false, false, 90, 250, 700, 875,1050);
    houseCards[16] = HouseCards(5, 240, 20, false, false, 100, 300, 750, 925,1100);
    //Station3
    houseCards[17] = HouseCards(9, 200, 25, true, false, 0, 0, 0, 0,0);
    //Yellow1&2
    houseCards[18] = HouseCards(6, 260, 22, false, false, 110, 330, 800, 975,1150);
    houseCards[19] = HouseCards(6, 260, 22, false, false, 110, 330, 800, 975,1150);
    //Utility2
    houseCards[20] = HouseCards(10, 150, 4, false, true, 0, 0, 0, 0,0);
    //Yellow3
    houseCards[21] = HouseCards(6, 280, 24, false, false, 120, 360, 850, 1025,1200);
    //Green
    houseCards[22] = HouseCards(7, 300, 26, false, false, 130, 390, 900, 1100,1275);
    houseCards[23] = HouseCards(7, 300, 26, false, false, 130, 390, 900, 1100,1275);
    houseCards[24] = HouseCards(7, 320, 28, false, false, 150, 450, 1000, 1200,1400);
    //Station4
    houseCards[25] = HouseCards(9, 200, 25, true, false, 0, 0, 0, 0,0);
    //Blue
    houseCards[26] = HouseCards(8, 350, 35, false, false, 175, 500, 1100, 1300,1500);
    houseCards[27] = HouseCards(8, 400, 50, false, false, 200, 600, 1400, 1700,2000);
    //end
    houseCards[28] = HouseCards(0, 0, 0, false, false, 0, 0, 0, 0,0);

    comm1[0].cardID = 1;
    comm1[1].cardID = 2;

    for(int i = 2 ; i < 16; i++)
    {
        comm2[i-2].cardID = i+1;
    }for(int i = 16 ; i < 24; i++)
    {
        Chance1[i-16].cardID = i+1;
    }for(int i = 24 ; i < 30; i++)
    {
        Chance2[i-24].cardID = i+1;
    }

    menu.setModal(true);
    connect(menu.ui->pushButton,SIGNAL(released()), this, SLOT(GetComboBoxValue()));
    menu.ui->comboBox->currentText().toInt();
    menu.setWindowTitle("Monoploy");
    setWindowTitle("Monoploy");
    menu.exec();

    ui->offerButton->hide();
    ui->passButton->hide();
    ui->unmortgage->hide();
    ui->houseSell->hide();
    ui->buyButton->hide();
    ui->houseBuy->hide();
    ui->jailfree->hide();
    ui->mortgage->hide();
    ui->offerBox->hide();
    ui->endTurn->hide();
    ui->pay200->hide();
    ui->getout->hide();
    ui->bidBox->hide();
    ui->submit->hide();
    ui->Accept->hide();
    ui->Reject->hide();
    ui->pay10->hide();
    ui->priceOffer->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::GetComboBoxValue()
{
    bool flag = false;
    playerCount = menu.ui->comboBox->currentText().toInt();
    playerList = new Player[playerCount];
    for(int i = 0; i < playerCount; i++)
    {
        playerList[i].SetIconId((rand() % ((8 + 1) - 1) + 1));

        for(int j = 0; j < playerCount; j++)
        {
            if(playerList[i].GetIconId() == playerList[j].GetIconId() && j != i)
            {
                flag = true; break;
            }
        }

        if(flag){i--; flag = false;}
    }

    QString pathCard = (QString(":/board/cards/Assets/Player") + QString::number(playerList[0].GetIconId()) + QString(".png"));
    QIcon icon = style()->standardIcon(QStyle::SP_DialogOkButton);
    icon = QIcon(pathCard);
    QPixmap pixmap2 = icon.pixmap(QSize(70, 70));
    ui->playerImage->setPixmap(pixmap2);
    menu.hide();

    for (int i = 0; i < playerCount; ++i)
       lbArr[i] = new QLabel(this);


}

void MainWindow::hButtonPressed()
{
    ui->verticalLayoutWidget->setVisible(true);
    music2->setMedia(QUrl("qrc:/board/cards/cardSound.wav"));
    music2->setVolume(40);
    music2->play();
    QPushButton *button = (QPushButton *)sender();
    QString pathCard = (QString(":/board/cards/Assets/card") + QString::number(button->text().toInt()) + QString(".png"));
    QIcon iconCard = style()->standardIcon(QStyle::SP_DialogOkButton);
    iconCard = QIcon(pathCard);
    QPixmap pixmap2 = iconCard.pixmap(QSize(280, 280));
    ui->cardShowCase->setPixmap(pixmap2);


    if(houseCards[button->text().toInt()].owner != -1 && turnHandler[currentTurn] != houseCards[button->text().toInt()].owner)
    {
      ui->ownerLabel->setText(QString::fromStdString(playerList[houseCards[button->text().toInt()].owner].GetName()));
      ui->rentLabel->setText(QString::number(houseCards[button->text().toInt()-1].getRent(playerList[houseCards[button->text().toInt()].owner].stationCount,
                             playerList[turnHandler[currentTurn]].lastThrough)) + "$");
      ui->housesLabel->setText(QString::number(houseCards[button->text().toInt()-1].houseCount + 1));
      ui->playerID->setText(QString::number(houseCards[button->text().toInt()].owner));
      ui->offerID->setText(QString::number(houseCards[button->text().toInt()].cardID-1));

      if(houseCards[button->text().toInt()].hasHotel)
      ui->hotelLabel->setText("True");
      else
          ui->hotelLabel->setText("False");

      if(houseCards[button->text().toInt()].isMortage)
          ui->mortgageLabel->setText("True");
      else
          ui->mortgageLabel->setText("False");

      if(playerList[ui->playerID->text().toInt()].offer == 0){
      ui->offerButton->show();
      ui->offerBox->show();
    }}
    else
    {
        ui->offerButton->hide();
        ui->offerBox->hide();
        ui->ownerLabel->setText(QString("None"));
        ui->housesLabel->setText(QString("None"));
        ui->hotelLabel->setText(QString("None"));
        ui->rentLabel->setText("None");
        ui->mortgageLabel->setText("False");
    }
    if(turnHandler[currentTurn] == houseCards[button->text().toInt()].owner)
    {
        if(!houseCards[houseCards[button->text().toInt()].owner].isMortage)
        ui->mortgage->show();
        else
        ui->unmortgage->show();
        ui->endTurn->show();
        if((playerList[turnHandler[currentTurn]].colorSets[houseCards[houseCards[button->text().toInt()].owner].colorId -1] == 2 && (houseCards[houseCards[button->text().toInt()].owner].colorId == 1
                                                                                                                    || houseCards[houseCards[button->text().toInt()].owner].colorId == 8))
                ||(playerList[turnHandler[currentTurn]].colorSets[houseCards[houseCards[button->text().toInt()].owner].colorId -1] == 3))
        {
            ui->houseBuy->show();
            ui->houseSell->show();
            if(houseCards[houseCards[button->text().toInt()].owner].houseCount >= 0)
            {
            }if(houseCards[houseCards[button->text().toInt()].owner].houseCount == 4)
            {
                ui->houseBuy->hide();
            }
        }
    }else
    {
        ui->mortgage->hide();
        ui->unmortgage->hide();
    }

}


void MainWindow::updateDie()
{
    ui->Dice1->setIcon(DieIcon[(rand() % ((6 + 1) - 1) + 1) -1]);
    ui->Dice2->setIcon(DieIcon[(rand() % ((6 + 1) - 1) + 1) -1]);
}



void MainWindow::on_RollButton_pressed()
{
    int a1 = (rand() % (((6 + 1) - 1)));
    int a2 = (rand() % (((6 + 1) - 1)));
    if(GameState == 1)
        GameState = 2;
    QSound::play(":/board/cards/ds.wav");

    int i = 10000;
    while(ui->RollButton->isDown() && i > 0)
    {
        if(i % 7 == 0){
        updateDie();}
        i--;
        QApplication::processEvents();
    }
    ui->Dice1->setIcon(DieIcon[a1]);
    ui->Dice2->setIcon(DieIcon[a2]);

    if(GameState == 3)
     {
     if(!playerList[turnHandler[currentTurn]].getInJail())
     {
         ui->jailfree->hide();
     if(a1 == a2)
     {
         doubleCounter++;
         ui->doubleRoll->setText("DOUBLE!!! \n" + QString::number(doubleCounter));
         QSound::play(":/board/cards/bell.wav");
         rolledDouble = true;
     }else
     {
       ui->doubleRoll->setText("");
     }
     updatePixmapPos(a1+a2+2);
     ActionFase();
     ui->RollButton->hide();
     doubleCounter = 0;
     }else
     {
         ui->getout->show();
         ui->RollButton->hide();
         if(playerList[turnHandler[currentTurn]].GetJailFree())
         ui->jailfree->show();

         playerList[turnHandler[currentTurn]].jailTime++;

         if(a1 == a2)
         {
              ui->jailfree->hide();
             doubleCounter++;
             ui->doubleRoll->setText("DOUBLE!!! \n" + QString::number(doubleCounter));
             QSound::play(":/board/cards/bell.wav");
             playerList[turnHandler[currentTurn]].setInJail(false);
             playerList[turnHandler[currentTurn]].jailTime = 0;
             updatePixmapPos(a1+a2+2);
             ui->getout->hide();
         }else if(playerList[turnHandler[currentTurn]].jailTime == 4)
         {
             playerList[turnHandler[currentTurn]].setInJail(false);
             playerList[turnHandler[currentTurn]].jailTime = 0;
             playerList[turnHandler[currentTurn]].SetBalance(-50);
             QSound::play(":/board/cards/bell.wav");
             ui->getout->hide();
             ui->jailfree->hide();
             updatePixmapPos(a1+a2+2);
         }
         playerList[currentTurn].lastThrough = a1 +a2 + 2;
         ActionFase();
     }

     }
    playerList[currentTurn].lastThrough = a1 +a2 + 2;
    if(GameState == 0)
    {
        playerList[currentTurn].lastThrough = a1 +a2 + 2;
        currentTurn++;
        if(currentTurn == playerCount - 1)
        {
            GameState = 1;
            for (int i = 0; i < playerCount - 1; i++)
                for (int j = 0; j < playerCount - i - 1; j++)
                    if (playerList[j].lastThrough < playerList[j + 1].lastThrough)
                        std::swap(turnHandler[j], turnHandler[i]);
        }
    }
    if(currentTurn > playerCount - 1)
    {
        currentTurn = 0;
    }

    if(doubleCounter == 3)
    {
        GoToJail();
        doubleCounter = 0;
    }
    updateListWidget();
    if(GameState == 2)
        GameState = 3;

}



void MainWindow::on_lineEdit_returnPressed()
{
    if(ui->lineEdit->text().trimmed().length() < 11 && ui->lineEdit->text().trimmed().length() != 0)
    {
     if(myCounter < playerCount)
     {
        playerList[myCounter].SetName(ui->lineEdit->text().toStdString());
        ui->lineEdit->clear();

        myCounter++;
        QString pathCard = (QString(":/board/cards/Assets/Player") + QString::number(playerList[myCounter].GetIconId()) + QString(".png"));
        QIcon icon = style()->standardIcon(QStyle::SP_DialogOkButton);
        icon = QIcon(pathCard);
        QPixmap pixmap2 = icon.pixmap(QSize(70, 70));
        ui->playerImage->setPixmap(pixmap2);
     }
     if(myCounter == playerCount)
     {
         ui->CoverAll->hide();
         ui->lineEdit->hide();
         ui->playerImage->hide();
         ui->nameEnter->hide();
         ui->C1->hide();
         ui->C2->hide();
         updateListWidget();
         BuildGame();
         music2->setMedia(QUrl("qrc:/board/cards/pop.wav"));
         music2->setVolume(30);
         music2->play();
     }
    }

}



void MainWindow::updateListWidget()
{
    ui->PlayerShow->setGeometry(ui->PlayerShow->x(),ui->PlayerShow->y(),ui->PlayerShow->width(), 0);
    ui->PlayerShow->clear();
    myCounter = 0;
    for(; myCounter < playerCount; myCounter++)
    {
        int n = 0;
        std::string name = playerList[myCounter].GetName() + " Balance: " + QString::number(playerList[myCounter].GetBalance()).toStdString() + "$";

        if(playerList[myCounter].getInJail())
        {
            name += "\nIN JAIL";
            n = 5;
        }

        QString pathCard = (QString(":/board/cards/Assets/Player") + QString::number(playerList[myCounter].GetIconId()) + QString(".png"));
        QIcon icon = style()->standardIcon(QStyle::SP_DialogOkButton);
        icon = QIcon(pathCard);
        QPixmap pixmap2 = icon.pixmap(QSize(65, 65));

        QListWidgetItem *item = new QListWidgetItem(pixmap2, "", ui->PlayerShow);
        item->setText(QString::fromStdString(name));
        item->setTextColor("white");
        if(myCounter == turnHandler[currentTurn])
        {
            item->setBackgroundColor(QColor("#7fc97f"));
            ui->PlayerShow->insertItem(0,item);
        }else{ui->PlayerShow->addItem(item);}
        ui->PlayerShow->setIconSize(QSize(200,200));

        if(ui->PlayerShow->height() < 300)
            ui->PlayerShow->setGeometry(ui->PlayerShow->x(),ui->PlayerShow->y(),ui->PlayerShow->width(), ui->PlayerShow->height() + 72 + n);
    }


}



void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    arg1.isSimpleText();
    ui->C2->setText(QString::number(ui->lineEdit->text().trimmed().length()));
    if(ui->lineEdit->text().trimmed().length() > 10){
    ui->C2->setStyleSheet("color: red");
}else if(ui->lineEdit->text().trimmed().length() == 0)
 {
    ui->C1->setStyleSheet("color: black");
    ui->C2->setStyleSheet("color: black");
 }else{
        ui->C1->setStyleSheet("color: white");
        ui->C2->setStyleSheet("color: white");
    }
}



void MainWindow::BuildGame()
{
    int spacing = 0;
    for(int i = 0; i < playerCount; i++)
    {
    QString path2 = (QString(":/board/cards/Assets/Player") + QString::number(playerList[i].GetIconId()) + QString(".png"));
    QIcon icon2 = style()->standardIcon(QStyle::SP_DialogOkButton);
    icon2 = QIcon(path2);
    QPixmap pixmap2 = icon2.pixmap(QSize(47, 47));
    lbArr[i]->setGeometry(790 + spacing,530 + spacing,35,35);
    lbArr[i]->setPixmap(pixmap2);
    spacing += 7;
    }ui->CoverAll->hide();
}



void MainWindow::updatePixmapPos(int x)
{
     //updateSets();
    int moveX = 0, moveY = 0;
    int n = 47 + (turnHandler[currentTurn] + 1);
    while(x != 0)
    {
        if(playerList[turnHandler[currentTurn]].matY == 10 && (playerList[turnHandler[currentTurn]].matX <= 10 && playerList[turnHandler[currentTurn]].matX != 0))
        {
            moveX -= n;
            playerList[turnHandler[currentTurn]].matX -= 1;
        }
        else if(playerList[turnHandler[currentTurn]].matX == 0 && (playerList[turnHandler[currentTurn]].matY <= 10 && playerList[turnHandler[currentTurn]].matY != 0))
        {
            moveY -= n;
            playerList[turnHandler[currentTurn]].matY -= 1;
        }
        else if(playerList[turnHandler[currentTurn]].matY == 0 && (playerList[turnHandler[currentTurn]].matX <= 10 && playerList[turnHandler[currentTurn]].matX != 10))
        {
            moveX += n;
            playerList[turnHandler[currentTurn]].matX += 1;
        }
        else if(playerList[turnHandler[currentTurn]].matX == 10 && (playerList[turnHandler[currentTurn]].matY <= 10 && playerList[turnHandler[currentTurn]].matY != 10))
        {
            moveY += n;
            playerList[turnHandler[currentTurn]].matY += 1;
        }
        x--;

        if(((playerList[turnHandler[currentTurn]].matX == 10 && playerList[turnHandler[currentTurn]].matY == 10) && GameState != 0)
                && !playerList[turnHandler[currentTurn]].getInJail())
        {
            QSound::play(":/board/cards/money.wav");
            playerList[turnHandler[currentTurn]].SetBalance(200);
        }
    }
    lbArr[turnHandler[currentTurn]]->setGeometry(lbArr[turnHandler[currentTurn]]->x() + moveX,lbArr[turnHandler[currentTurn]]->y() + moveY,45, 45);
    updateInfo();
}



void MainWindow::ActionFase()
{
    int n = cardsMap[playerList[turnHandler[currentTurn]].matY][playerList[turnHandler[currentTurn]].matX];
    music2->setMedia(QUrl("qrc:/board/cards/cardSound.wav"));
    music2->setVolume(20);
    music2->play();
    QString pathCard = (QString(":/board/cards/Assets/card") + QString::number(n) + QString(".png"));
    QIcon iconCard = style()->standardIcon(QStyle::SP_DialogOkButton);
    iconCard = QIcon(pathCard);
    QPixmap pixmap2 = iconCard.pixmap(QSize(280, 280));
    ui->cardShowCase->setPixmap(pixmap2);



    int tempY = playerList[turnHandler[currentTurn]].matY;
    int tempX = playerList[turnHandler[currentTurn]].matX;

    if(cardsMap[tempY][tempX] < 29 && cardsMap[tempY][tempX] > 0)
    {
        ui->verticalLayoutWidget->setVisible(true);
        updateInfo();

    if(turnHandler[currentTurn] == houseCards[cardsMap[tempY][tempX]-1].owner)
    {

        //if(houseCards[cardsMap[tempY][tempX]-1].colorId)

        if(!houseCards[cardsMap[tempY][tempX]-1].isMortage){
        ui->mortgage->show();
        }else{
        ui->unmortgage->show();}

        if((playerList[turnHandler[currentTurn]].colorSets[houseCards[cardsMap[tempY][tempX]-1].colorId -1] == 2 && (houseCards[cardsMap[tempY][tempX]-1].colorId == 1
                                                                                                                    || houseCards[cardsMap[tempY][tempX]-1].colorId == 8))
                ||(playerList[turnHandler[currentTurn]].colorSets[houseCards[cardsMap[tempY][tempX]-1].colorId -1] == 3))
        {
            ui->houseBuy->show();
            ui->houseSell->show();
            if(houseCards[cardsMap[tempY][tempX]-1].houseCount == 0)
            {
                ui->houseSell->hide();
            }if(houseCards[cardsMap[tempY][tempX]-1].houseCount == 4)
            {
                ui->houseBuy->hide();
            }
        }

        ui->endTurn->show();


    }else if((turnHandler[currentTurn] != houseCards[cardsMap[tempY][tempX]-1].owner
             && houseCards[cardsMap[tempY][tempX]].owner != -1) && !houseCards[cardsMap[tempY][tempX]-1].isMortage)
    {
        music2->setMedia(QUrl("qrc:/board/cards/lostmoney.wav"));
        music2->setVolume(20);
        music2->play();

        playerList[houseCards[cardsMap[tempY][tempX]].owner].SetBalance(houseCards[cardsMap[tempY][tempX]-1].getRent(playerList[turnHandler[currentTurn]].stationCount,
                playerList[turnHandler[currentTurn]].lastThrough));
        playerList[turnHandler[currentTurn]].SetBalance(-houseCards[cardsMap[tempY][tempX]-1].getRent(playerList[turnHandler[currentTurn]].stationCount,
                playerList[turnHandler[currentTurn]].lastThrough));

        ui->endTurn->show();

    }else if(houseCards[cardsMap[tempY][tempX]].owner == -1)
    {
        //QMessageBox::warning(this,"",QString::number(cardsMap[tempY][tempX] -1));
        ui->CoverAll->show();
        ui->passButton->show();
        if(playerList[turnHandler[currentTurn]].GetBalance() >= houseCards[cardsMap[tempY][tempX]].firstCost)
        {
            ui->buyButton->show();
            ui->buyButton->setText("Buy " + QString::number(houseCards[cardsMap[tempY][tempX]-1].firstCost) + "$");
        }
    }
    }else if(cardsMap[tempY][tempX] < 0)
    {
        ui->verticalLayoutWidget->setVisible(false);
        if(cardsMap[tempY][tempX] == -1){
            playerList[turnHandler[currentTurn]].SetBalance(-75);
            ui->endTurn->show();
        }

        else
        {
            ui->pay200->show();
            ui->pay10->show();
        }
    }else if(cardsMap[tempY][tempX] == 444)
    {
        GoToJail();
    }else if(cardsMap[tempY][tempX] == 0 || cardsMap[tempY][tempX] == 55)
    {
        if(cardsMap[tempY][tempX] == 55)
        {

            if(chestPointer == 0 || chestPointer == 1){
               if(comm1[chestPointer].chAndcomm() == 1 && chestPointer == 0)
               {
                   playerList[turnHandler[currentTurn]].SetJailFree(true);
               }else if(comm1[chestPointer].chAndcomm() == 0)
               {
                   while(!playerList[turnHandler[currentTurn]].getInJail())
                   {
                       int tempY2 = playerList[turnHandler[currentTurn]].matY;
                       int tempX2 = playerList[turnHandler[currentTurn]].matX;
                       updatePixmapPos(1);
                       if(cardsMap[tempY2][tempX2] == 444)
                           {

                               GoToJail();}
                   }

               }
               QString pathCard = (QString(":/board/cards/Assets/ch") + QString::number(comm1[chestPointer].cardID) + QString(".jpg"));
               iconCard = QIcon(pathCard);
               QPixmap pixmap2 = iconCard.pixmap(QSize(580, 580));
               ui->cardShowCase->setPixmap(pixmap2);
            }else{
                if(comm2[chestPointer-2].chAndcomm() == 111)
               {
                    bool flag = false;
                    while(!flag)
                    {
                        int tempY2 = playerList[turnHandler[currentTurn]].matY;
                        int tempX2 = playerList[turnHandler[currentTurn]].matX;
                        updatePixmapPos(1);
                        if(cardsMap[tempY2][tempX2] == 111)
                            {
                            flag = true;
                               }
                    }


               }else if(comm2[chestPointer-2].chAndcomm() == 222)
               {
                    int n = 0;
                   for(int i = 0; i < playerCount; i++)
                   {
                       if(i != turnHandler[currentTurn]){
                           playerList[i].SetBalance(-50);
                           n+=50;}

                   }

                   playerList[turnHandler[currentTurn]].SetBalance(n);
                   QSound::play(":/board/cards/money.wav");

               }else if(comm2[chestPointer-2].chAndcomm() == 333)
               {
                    QSound::play(":/board/cards/lostmoney.wav");
                   playerList[turnHandler[currentTurn]].SetBalance(40*playerList[turnHandler[currentTurn]].houseCount + 115*playerList[turnHandler[currentTurn]].hotelCount);
               }else
               {
                    QSound::play(":/board/cards/money.wav");
                   playerList[turnHandler[currentTurn]].SetBalance(comm2[chestPointer-2].chAndcomm());
               }
                QString pathCard = (QString(":/board/cards/Assets/ch") + QString::number(comm2[chestPointer-2].cardID) + QString(".jpg"));
                iconCard = QIcon(pathCard);
                QPixmap pixmap2 = iconCard.pixmap(QSize(580, 580));
                ui->cardShowCase->setPixmap(pixmap2);
            }


               ui->endTurn->show();
               chestPointer++;

               if(chestPointer > 15)
               {
                   chestPointer = 0;
               }
        }else
        {
            if(Chance2[chancePointer].chAndcomm() == 111)
           {
                QSound::play(":/board/cards/lostmoney.wav");
               playerList[turnHandler[currentTurn]].SetBalance(40*playerList[turnHandler[currentTurn]].houseCount + 115*playerList[turnHandler[currentTurn]].hotelCount);

           }else if(Chance2[chancePointer].chAndcomm() == 222)
           {
                int n = 0;
               for(int i = 0; i < playerCount; i++)
               {
                   if(i != turnHandler[currentTurn]){
                       playerList[i].SetBalance(50);
                       n-=50;}

               }

               playerList[turnHandler[currentTurn]].SetBalance(n);
               QSound::play(":/board/cards/lostmoney.wav");

           }else if(Chance2[chancePointer].chAndcomm() == 333)
            {
                bool flag = false;
                while(!flag)
                {
                    int tempY2 = playerList[turnHandler[currentTurn]].matY;
                    int tempX2 = playerList[turnHandler[currentTurn]].matX;
                    updatePixmapPos(1);
                    if(cardsMap[tempY2][tempX2] == 111)
                        {
                        flag = true;
                           }
                }

            }else
           {
                QSound::play(":/board/cards/money.wav");
               playerList[turnHandler[currentTurn]].SetBalance(Chance2[chancePointer].chAndcomm());
           }
            QString pathCard = (QString(":/board/cards/Assets/ch") + QString::number(Chance2[chancePointer].cardID) + QString(".jpg"));
            iconCard = QIcon(pathCard);
            QPixmap pixmap2 = iconCard.pixmap(QSize(580, 580));
            ui->cardShowCase->setPixmap(pixmap2);



           ui->endTurn->show();
          chancePointer++;

           if(chancePointer > 4)
           {
               chancePointer = 0;
           }
        }

    }else
    {
        if(playerList[turnHandler[currentTurn]].getInJail())
        {

        }
        ui->verticalLayoutWidget->setVisible(false);
         ui->endTurn->show();
    }


}



void MainWindow::on_buyButton_clicked()
{
    int tempY = playerList[turnHandler[currentTurn]].matY;
    int tempX = playerList[turnHandler[currentTurn]].matX;

    houseCards[cardsMap[tempY][tempX]].owner = turnHandler[currentTurn];
    music2->setMedia(QUrl("qrc:/board/cards/money.wav"));
    music2->setVolume(40);
    music2->play();
    playerList[turnHandler[currentTurn]].SetBalance(-houseCards[cardsMap[tempY][tempX]].firstCost);
    if(houseCards[cardsMap[tempY][tempX]-1].isStation)
         playerList[turnHandler[currentTurn]].stationCount++;

    playerList[turnHandler[currentTurn]].colorSets[houseCards[cardsMap[tempY][tempX]-1].colorId-1]++;

    updateListWidget();
    ui->passButton->hide();
    ui->buyButton->hide();
    ui->endTurn->show();
    ui->CoverAll->hide();
    updateInfo();
    //updateSets();
}



void MainWindow::on_endTurn_clicked()
{
    bool flag = false;

    if(playerList[turnHandler[currentTurn]].GetBalance() < -200)
    {
        playerList[turnHandler[currentTurn]].SetBankrupt(true);
    }


    for(int i = 0; i < playerCount; i++)
    {
        if(playerList[turnHandler[currentTurn]].GetBankrupt()){
            currentTurn++;flag = true;
        if(currentTurn > playerCount - 1)
        {
            currentTurn = 0;
        }}
    }
    if(rolledDouble)
    {
     rolledDouble = false;
    }
    else{
      currentTurn++;

      if(flag)
          currentTurn--;

     if(currentTurn > playerCount - 1)
     {
         currentTurn = 0;
     }
     doubleCounter = 0;

    }
    ui->endTurn->hide();
    updateListWidget();
    ui->passButton->hide();
    ui->mortgage->hide();
    ui->unmortgage->hide();
    ui->getout->hide();
    ui->jailfree->hide();
    ui->houseSell->hide();
    ui->houseBuy->hide();
    ui->offerBox->hide();
    ui->offerButton->hide();

    if(playerList[turnHandler[currentTurn]].offer != 0)
    {
            QSound::play(":/board/cards/bell.wav");
        ui->Accept->show();
        ui->Reject->show();
            ui->priceOffer->show();
            QString pathCard = (QString(":/board/cards/Assets/card") + QString::number(ui->offerID->text().toInt()) + QString(".png"));
            QIcon iconCard = style()->standardIcon(QStyle::SP_DialogOkButton);
            iconCard = QIcon(pathCard);
            QPixmap pixmap2 = iconCard.pixmap(QSize(280, 280));
            ui->cardShowCase->setPixmap(pixmap2);
    }else
    {
     ui->RollButton->show();
    }



}



void MainWindow::on_pay10_clicked()
{
    music2->setMedia(QUrl("qrc:/board/cards/money.wav"));
    music2->setVolume(40);
    music2->play();

   int n = (playerList[turnHandler[currentTurn]].GetBalance()) / 10;
    playerList[turnHandler[currentTurn]].SetBalance(-n);

    ui->pay200->hide();
    ui->pay10->hide();
    on_endTurn_clicked();
}



void MainWindow::on_pay200_clicked()
{
    music2->setMedia(QUrl("qrc:/board/cards/money.wav"));
    music2->setVolume(40);
    music2->play();

    playerList[turnHandler[currentTurn]].SetBalance(-200);

    ui->pay200->hide();
    ui->pay10->hide();
    on_endTurn_clicked();
}



void MainWindow::on_mortgage_clicked()
{
    music2->setMedia(QUrl("qrc:/board/cards/lostmoney.wav"));
    music2->setVolume(20);
    music2->play();
    int tempY = playerList[turnHandler[currentTurn]].matY;
    int tempX = playerList[turnHandler[currentTurn]].matX;

       playerList[turnHandler[currentTurn]].colorSets[houseCards[cardsMap[tempY][tempX]-1].colorId-1]--;

    playerList[turnHandler[currentTurn]].SetBalance(houseCards[cardsMap[tempY][tempX]-1].mortageVal);
    houseCards[cardsMap[tempY][tempX]-1].isMortage = true;
    if(houseCards[cardsMap[tempY][tempX]-1].isStation)
         playerList[turnHandler[currentTurn]].stationCount--;
    ui->mortgage->hide();
    updateListWidget();
    updateInfo();
    //updateSets();
}



void MainWindow::on_unmortgage_clicked()
{
    music2->setMedia(QUrl("qrc:/board/cards/money.wav"));
    music2->setVolume(40);
    music2->play();
    int tempY = playerList[turnHandler[currentTurn]].matY;
    int tempX = playerList[turnHandler[currentTurn]].matX;

       playerList[turnHandler[currentTurn]].colorSets[houseCards[cardsMap[tempY][tempX]-1].colorId-1]++;

    playerList[turnHandler[currentTurn]].SetBalance(-(houseCards[cardsMap[tempY][tempX]-1].mortageVal + houseCards[cardsMap[tempY][tempX]-1].mortageVal/10));
    houseCards[cardsMap[tempY][tempX]].isMortage = false;
    if(houseCards[cardsMap[tempY][tempX]-1].isStation)
         playerList[turnHandler[currentTurn]].stationCount++;
    ui->unmortgage->hide();
    updateListWidget();
    updateInfo();
    //updateSets();
}



void MainWindow::updateInfo()
{

//    int tempY = playerList[turnHandler[currentTurn]].matY;
//    int tempX = playerList[turnHandler[currentTurn]].matX;

//       //set Info Labels
//       if(houseCards[cardsMap[tempY][tempX]].owner != -1)
//       {
//       ui->ownerLabel->setText(QString::fromStdString(playerList[houseCards[cardsMap[tempY][tempX]].owner].GetName()));
//       ui->rentLabel->setText(QString::number(houseCards[cardsMap[tempY][tempX]-1].getRent(playerList[houseCards[cardsMap[tempY][tempX]-1].owner].stationCount,
//                              playerList[turnHandler[currentTurn]].lastThrough)) + "$");
//       ui->housesLabel->setText(QString::number(houseCards[cardsMap[tempY][tempX]-1].houseCount + 1));

//       if(houseCards[cardsMap[tempY][tempX]].hasHotel)
//       ui->hotelLabel->setText("True");
//       else
//           ui->hotelLabel->setText("False");

//       if(houseCards[cardsMap[tempY][tempX]].isMortage)
//           ui->mortgageLabel->setText("True");
//       else
//            ui->mortgageLabel->setText("False");
//       }else
//       {
//           ui->ownerLabel->setText(QString("None"));
//           ui->housesLabel->setText(QString("None"));
//           ui->hotelLabel->setText(QString("None"));
//           ui->rentLabel->setText("None");
//           ui->mortgageLabel->setText("False");
//       }
//        //end
}



void MainWindow::GoToJail()
{
    QSound::play(":/board/cards/jailSound.wav");
    if(chestPointer == 1)
    GoToDestination(0,0);
    else{
        GoToDestination(11,0);
    }
    playerList[turnHandler[currentTurn]].setInJail(true);
    ui->endTurn->show();
}

void MainWindow::on_getout_clicked()
{
    playerList[turnHandler[currentTurn]].setInJail(false);
    playerList[turnHandler[currentTurn]].jailTime = 0;
    playerList[turnHandler[currentTurn]].SetBalance(-50);
    QSound::play(":/board/cards/bell.wav");
    updateListWidget();
    ui->getout->hide();
    updatePixmapPos(playerList[currentTurn].lastThrough);
}



void MainWindow::GoToDestination(int y, int x)
{
    int moveX = 0, moveY = 0;
    int n = 47 + (turnHandler[currentTurn] + 1);
    while(playerList[turnHandler[currentTurn]].matY != y && playerList[turnHandler[currentTurn]].matX != x)
    {
        if(playerList[turnHandler[currentTurn]].matY == 10 && (playerList[turnHandler[currentTurn]].matX <= 10 && playerList[turnHandler[currentTurn]].matX != 0))
        {
            moveX -= n;
            playerList[turnHandler[currentTurn]].matX -= 1;
        }
        else if(playerList[turnHandler[currentTurn]].matX == 0 && (playerList[turnHandler[currentTurn]].matY <= 10 && playerList[turnHandler[currentTurn]].matY != 0))
        {
            moveY -= n;
            playerList[turnHandler[currentTurn]].matY -= 1;
        }
        else if(playerList[turnHandler[currentTurn]].matY == 0 && (playerList[turnHandler[currentTurn]].matX <= 10 && playerList[turnHandler[currentTurn]].matX != 10))
        {
            moveX += n;
            playerList[turnHandler[currentTurn]].matX += 1;
        }
        else if(playerList[turnHandler[currentTurn]].matX == 10 && (playerList[turnHandler[currentTurn]].matY <= 10 && playerList[turnHandler[currentTurn]].matY != 10))
        {
            moveY += n;
            playerList[turnHandler[currentTurn]].matY += 1;
        }
        if(((playerList[turnHandler[currentTurn]].matX == 10 && playerList[turnHandler[currentTurn]].matY == 10) && GameState != 0)
                && !playerList[turnHandler[currentTurn]].getInJail())
        {
            QSound::play(":/board/cards/money.wav");
            playerList[turnHandler[currentTurn]].SetBalance(200);
        }
    }
    lbArr[turnHandler[currentTurn]]->setGeometry(lbArr[turnHandler[currentTurn]]->x() + moveX,lbArr[turnHandler[currentTurn]]->y() + moveY,45, 45);
    updateInfo();
}



void MainWindow::on_jailfree_clicked()
{
    playerList[turnHandler[currentTurn]].SetJailFree(false);
    playerList[turnHandler[currentTurn]].setInJail(false);
    QSound::play(":/board/cards/bell.wav");
    updateListWidget();
   ui->jailfree->hide();
   doubleCounter++;
   playerList[turnHandler[currentTurn]].jailTime = 0;
   updatePixmapPos(playerList[currentTurn].lastThrough);
   ui->getout->hide();
}


void MainWindow::on_houseBuy_clicked()
{
    int tempY = playerList[turnHandler[currentTurn]].matY;
    int tempX = playerList[turnHandler[currentTurn]].matX;
    playerList[turnHandler[currentTurn]].houseCount++;
    houseCards[cardsMap[tempY][tempX]].houseCount++;
    if(houseCards[cardsMap[tempY][tempX]].houseCount == 4)
    {
        houseCards[cardsMap[tempY][tempX]].hasHotel = true;
    }
    ActionFase();
}


void MainWindow::on_houseSell_clicked()
{
    int tempY = playerList[turnHandler[currentTurn]].matY;
    int tempX = playerList[turnHandler[currentTurn]].matX;

    playerList[turnHandler[currentTurn]].houseCount--;
    playerList[turnHandler[currentTurn]].SetBalance(-houseCards[cardsMap[tempY][tempX]-1].houseCost);

    if(houseCards[cardsMap[tempY][tempX]-1].houseCount != 4)
    {
        houseCards[cardsMap[tempY][tempX]-1].hasHotel = false;
    }
    ActionFase();
}


void MainWindow::on_passButton_clicked()
{
 myCounter = 0;
 QSound::play(":/board/cards/bell.wav");
 ui->nameEnter->show();
 ui->nameEnter->setText("Name Your Price:");
 ui->buyButton->hide();
 ui->passButton->hide();
 ui->playerImage->show();
 QString pathCard = (QString(":/board/cards/Assets/Player") + QString::number(playerList[myCounter].GetIconId()) + QString(".png"));
 QIcon icon = style()->standardIcon(QStyle::SP_DialogOkButton);
 icon = QIcon(pathCard);
 QPixmap pixmap2 = icon.pixmap(QSize(70, 70));
 ui->playerImage->setPixmap(pixmap2);
 ui->bidBox->setValue(10);
 ui->bidBox->show();
}





void MainWindow::on_bidBox_valueChanged(int arg1)
{

    if(playerList[myCounter].GetBalance() < arg1 && arg1 < 10)
    {
        ui->submit->hide();
    }else
     ui->submit->show();

    for(int i = myCounter - 1; i >= 0 ; i--)
    {
        if(arg1 == bidsList[i])
        {
            ui->submit->hide();
        }
    }
}

void MainWindow::on_submit_clicked()
{
     QSound::play(":/board/cards/bell.wav");
     bidsList[myCounter] = ui->bidBox->value();
     ui->bidBox->clear();
     myCounter++;
     QString pathCard = (QString(":/board/cards/Assets/Player") + QString::number(playerList[myCounter].GetIconId()) + QString(".png"));
     QIcon icon = style()->standardIcon(QStyle::SP_DialogOkButton);
     icon = QIcon(pathCard);
     QPixmap pixmap2 = icon.pixmap(QSize(70, 70));
     ui->playerImage->setPixmap(pixmap2);
     ui->bidBox->setValue(bidsList[myCounter -1] + 1);
     if(myCounter == playerCount)
     {
         int tempY = playerList[turnHandler[currentTurn]].matY;
            int tempX = playerList[turnHandler[currentTurn]].matX;
         int maxpos = 0;
         int max = bidsList[0];
             for (int i = 1; i < playerCount; i++)
                 if (bidsList[i] > max)
                 {
                     max = bidsList[i];
                     maxpos++;
                 }
          playerList[maxpos].SetBalance(-max);

          houseCards[cardsMap[tempY][tempX]].owner = maxpos;

          playerList[maxpos].colorSets[houseCards[cardsMap[tempY][tempX]-1].colorId-1]++;

         QSound::play(":/board/cards/gravelS.wav");
         ui->playerImage->hide();
         ui->bidBox->hide();
         ui->submit->hide();
         ui->endTurn->show();
         ui->nameEnter->hide();
         ui->CoverAll->hide();
         on_endTurn_clicked();
     }
}


void MainWindow::on_offerButton_clicked()
{
    QSound::play(":/board/cards/pop.wav");
    playerList[ui->playerID->text().toInt()].offer = ui->offerBox->value();
    playerList[ui->playerID->text().toInt()].sender = turnHandler[currentTurn];
        ui->priceOffer->setText(QString::number(playerList[ui->playerID->text().toInt()].offer) + "$");
    ui->offerBox->clear();
    ui->offerBox->hide();

    ui->offerButton->hide();
}





void MainWindow::on_offerBox_valueChanged(int arg1)
{
    if(playerList[turnHandler[currentTurn]].GetBalance() < arg1 && arg1 < 10)
    {
        ui->offerButton->hide();
    }else
     ui->offerButton->show();
}





void MainWindow::on_Accept_clicked()
{
    QSound::play(":/board/cards/money.wav");
    houseCards[ui->offerID->text().toInt()].owner  =   playerList[ui->playerID->text().toInt()].sender;
    playerList[playerList[ui->playerID->text().toInt()].sender].SetBalance(-playerList[ui->playerID->text().toInt()].offer);
    playerList[turnHandler[currentTurn]].SetBalance(playerList[turnHandler[currentTurn]].offer);
    playerList[turnHandler[currentTurn]].offer = 0;
    ui->RollButton->show();
    ui->Accept->hide();
    ui->Reject->hide();
    ui->priceOffer->hide();
    updateListWidget();
    playerList[turnHandler[currentTurn]].colorSets[houseCards[ui->offerID->text().toInt()].colorId-1]++;
    playerList[ui->playerID->text().toInt()].colorSets[houseCards[ui->offerID->text().toInt()].colorId-1]--;
}


void MainWindow::on_Reject_clicked()
{
    QSound::play(":/board/cards/fail.wav");
    playerList[turnHandler[currentTurn]].offer = 0;
     ui->priceOffer->hide();
    ui->RollButton->show();
    ui->Accept->hide();
    ui->Reject->hide();
    updateListWidget();
}

