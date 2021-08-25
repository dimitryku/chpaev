#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtGui"
#include <QMessageBox>
#include "gameposition.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->game = new Game();
    view = new GameView(this, game);

    //TODO: check, mb change later
    game->SetView(GameView);

    ui->gridLayout->addWidget(view);
}

void MainWindow::on_NewGameButton_clicked()
{
    QMessageBox *mb = new QMessageBox("Внимание!", "Начать новую игру? Прогресс будет потерян!", QMessageBox::Information, QMessageBox::Yes,
                                      QMessageBox::No, 0);
    int reply = mb->exec();
    delete mb;
    if(reply == QMessageBox::Yes)
    {
        //TODO restart game
        ui->statusBar->showMessage("Игра сброшена");
    }
}

GameView *MainWindow::GetView()
{
    return view;
}

MainWindow::~MainWindow()
{
    delete ui;
}
