#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow),
    state(1), result(0), operand(-1)
{
    ui->setupUi(this);

    QVector<QPushButton*> numberButtons = {
        ui->btnNum_0, ui->btnNum_1, ui->btnNum_2, ui->btnNum_3,
        ui->btnNum_4, ui->btnNum_5, ui->btnNum_6, ui->btnNum_7,
        ui->btnNum_8, ui->btnNum_9
    };

    for (QPushButton* button : numberButtons) {
        connect(button, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    }

    connect(ui->btnAdd, &QPushButton::clicked, this, &MainWindow::operandClickedHandler);
    connect(ui->btnSub, &QPushButton::clicked, this, &MainWindow::operandClickedHandler);
    connect(ui->btnMul, &QPushButton::clicked, this, &MainWindow::operandClickedHandler);
    connect(ui->btnDiv, &QPushButton::clicked, this, &MainWindow::operandClickedHandler);

    connect(ui->btnEnter, &QPushButton::clicked, this, &MainWindow::clearEnterClickedHandler);
    connect(ui->btnClear, &QPushButton::clicked, this, &MainWindow::clearEnterClickedHandler);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickedHandler()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    QString buttonText = button->text();

    if(state == 1)
    {
        number1 += buttonText;
        ui->lineEditNum1->setText(number1);
    }
    else if(state == 2)
    {
        number2 += buttonText;
        ui->lineEditNum2->setText(number2);
    }

}


void MainWindow::clearEnterClickedHandler()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    if(button->text() == "enter")
    {
        float num1 = number1.toFloat();
        float num2 = number2.toFloat();

        switch(operand)
        {
            case 0: result = num1 + num2; break;
            case 1: result = num1 - num2; break;
            case 2: result = num1 * num2; break;
            case 3:
                if(num2 != 0) result = num1 / num2;
                else
                {
                    ui->lineEditResult->setText("Error");
                    return;
                }
                break;
        }

        ui->lineEditResult->setText(QString::number(result));
        state = 1;
    }
    else if(button->text() == "clear")
    {
        number1 = "";
        number2 = "";
        result = 0;
        operand = -1;
        resetLineEdits();
        state = 1;
    }
}

void MainWindow::operandClickedHandler()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    QString operation = button->text();

    if(operation == "+") operand = 0;
    else if(operation == "-") operand = 1;
    else if(operation == "*") operand = 2;
    else if(operation == "/") operand = 3;

    state = 2;
}

void MainWindow::resetLineEdits()
{
    ui->lineEditNum1->clear();
    ui->lineEditNum2->clear();
    ui->lineEditResult->clear();
}
