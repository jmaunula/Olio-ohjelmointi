#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , pTimer(new QTimer(this))
    , gameState(0)
{
    ui->setupUi(this);
    ui->stopGame->setEnabled(false);
    ui->startGame->setEnabled(false);
    ui->switchPlayer1->setEnabled(false);
    ui->switchPlayer2->setEnabled(false);

    connect(ui->switchPlayer1, &QPushButton::clicked, this, &MainWindow::on_SwitchPlayer_Clicked);
    connect(ui->switchPlayer2, &QPushButton::clicked, this, &MainWindow::on_SwitchPlayer_Clicked);
    connect(ui->chooseTime1, &QPushButton::clicked, this, &MainWindow::on_ChooseTime_Clicked);
    connect(ui->chooseTime2, &QPushButton::clicked, this, &MainWindow::on_ChooseTime_Clicked);
    connect(ui->startGame, &QPushButton::clicked, this, &MainWindow::on_StartStopGame_Clicked);
    connect(ui->stopGame, &QPushButton::clicked, this, &MainWindow::on_StartStopGame_Clicked);

    connect(pTimer, &QTimer::timeout, this, &MainWindow::timeout);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeout()
{
    if(gameState == 1)
    {
        if(player1Time > 0)
        {
            player1Time--;
            updateProgressBar();
            qDebug() <<player1Time;
        }
        else
        {
            setGameInfoText("Player 2 won!", 25);
            ui->switchPlayer1->setEnabled(false);
            ui->switchPlayer2->setEnabled(false);
            pTimer->stop();
        }

    }
    else if(gameState == 2)
    {
        if(player2Time > 0)
        {
            player2Time--;
            updateProgressBar();
            qDebug() <<player2Time;
        }
        else
        {
            setGameInfoText("Player 1 won!", 25);
            ui->switchPlayer1->setEnabled(false);
            ui->switchPlayer2->setEnabled(false);
            pTimer->stop();
        }

    }
}

void MainWindow::updateProgressBar()
{
    if(gameState == 1)
    {
        ui->progressBarP1->setValue(player1Time);
    }
    else if(gameState == 2)
    {
        ui->progressBarP2->setValue(player2Time);
    }

}

void MainWindow::setGameInfoText(QString text, int fontSize)
{
    ui->gameInfoLabel->setText(text);
    QFont font = ui->gameInfoLabel->font();
    font.setPointSize(fontSize);
    ui->gameInfoLabel->setFont(font);
}

void MainWindow::resetGame()
{
    pTimer->stop();
    currentPlayerTime = 120;
    ui->progressBarP1->setMaximum(currentPlayerTime);
    ui->progressBarP1->setValue(currentPlayerTime);
    ui->progressBarP2->setMaximum(currentPlayerTime);
    ui->progressBarP2->setValue(currentPlayerTime);

    setGameInfoText("Select playtime and start a new game", 25);
    ui->startGame->setEnabled(false);
    ui->stopGame->setEnabled(false);

    ui->chooseTime1->setEnabled(true);
    ui->chooseTime2->setEnabled(true);

    ui->switchPlayer1->setEnabled(false);
    ui->switchPlayer2->setEnabled(false);

    gameState = 0;
}

void MainWindow::on_SwitchPlayer_Clicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    QString buttonText = button->text();
    if(buttonText == "Switch Player 1")
    {
        gameState = 2;
        ui->switchPlayer1->setEnabled(false);
        ui->switchPlayer2->setEnabled(true);

    }
    else if(buttonText == "Switch Player 2")
    {
        gameState = 1;
        ui->switchPlayer2->setEnabled(false);
        ui->switchPlayer1->setEnabled(true);
    }
}

void MainWindow::on_ChooseTime_Clicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;
    setGameInfoText("Ready to play", 25);
    QString buttonText = button->text();
    if(buttonText == "120s")
    {
        currentPlayerTime = 120;
        player1Time = currentPlayerTime;
        player2Time = currentPlayerTime;

        ui->progressBarP1->setMaximum(currentPlayerTime);
        ui->progressBarP1->setValue(currentPlayerTime);
        ui->progressBarP2->setMaximum(currentPlayerTime);
        ui->progressBarP2->setValue(currentPlayerTime);
        if(ui->chooseTime1->isChecked()) ui->chooseTime2->setChecked(false);
    }
    else if(buttonText == "5min")
    {
        currentPlayerTime = 300;
        player1Time = currentPlayerTime;
        player2Time = currentPlayerTime;

        ui->progressBarP1->setMaximum(currentPlayerTime);
        ui->progressBarP1->setValue(currentPlayerTime);
        ui->progressBarP2->setMaximum(currentPlayerTime);
        ui->progressBarP2->setValue(currentPlayerTime);
        if(ui->chooseTime2->isChecked()) ui->chooseTime1->setChecked(false);
    }
    ui->startGame->setEnabled(true);

}

void MainWindow::on_StartStopGame_Clicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    QString buttonText = button->text();
    if(buttonText == "START GAME")
    {
        pTimer->start(1000);
        setGameInfoText("The game is ongoing", 25);
        ui->startGame->setEnabled(false);
        ui->stopGame->setEnabled(true);
        ui->chooseTime1->setEnabled(false);
        ui->chooseTime2->setEnabled(false);
        ui->chooseTime1->setChecked(false);
        ui->chooseTime2->setChecked(false);
        ui->switchPlayer1->setEnabled(true);
        gameState = 1;

    }
    else if(buttonText == "STOP GAME")
    {
        resetGame();
    }

}


