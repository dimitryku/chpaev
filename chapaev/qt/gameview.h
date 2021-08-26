#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItemGroup>
#include <vector>

#include "game.h"
#include "qcheckersholder.h"
#include "qchecker.h"
#include "qboard.h"

class Game;
class QCheckersHolder;

class GameView : public QGraphicsView
{
    Q_OBJECT
public:
    GameView(QObject *parent = nullptr, Game* game = 0);
    static float rectSize;

signals:

private:

    QGraphicsScene* scene;
    QGraphicsItemGroup* checkers;
    QBoard* board;
    QCheckersHolder* checkersHolder;

    void SetCheckers(Game* game, int num);

};

#endif // GAMEVIEW_H
