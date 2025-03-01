#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void timeout();


private:
    Ui::MainWindow *ui;
    QTimer* pTimer;
    short player1Time;
    short player2Time;
    short currentPlayerTime;
    short gameState;

    void updateProgressBar();
    void setGameInfoText(QString, int);
    void resetGame();

    void on_SwitchPlayer_Clicked();
    void on_ChooseTime_Clicked();
    void on_StartStopGame_Clicked();
};
#endif // MAINWINDOW_H
