#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->countButton, &QPushButton::clicked, this, &MainWindow::onCountBtnClicked);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::onResetBtnClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onCountBtnClicked()
{
    userText = ui->lineEdit->text();
    int userNumber = userText.toInt();
    userNumber = userNumber +1;
    ui->lineEdit->setText(QString::number(userNumber));
}

void MainWindow::onResetBtnClicked()
{
    userText = ui->lineEdit->text();
    ui->lineEdit->clear();
}
