#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtGui"
#include <QMessageBox>
#include "PhysX/gameposition.h"

MainWindow::MainWindow(QWidget *parent, Game* game) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->game = game;
    view = new GameView(this, game);
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
