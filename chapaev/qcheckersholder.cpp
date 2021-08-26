#include "qcheckersholder.h"

QCheckersHolder::QCheckersHolder(Game* game)
{
    InitGameData* initer = InitGameData::GetInstance();
    CheckerViewStyle * stl = new CheckerViewStyle(BattleSide::black);
    int i;
    for(i = 0; i < initer->GetBlackCheckersQuantity(); i++)
    {
        checkers.push_back(new QChecker(game->getGamePosition()[i],
                                         stl, BattleSide::black));
    }
    stl = new CheckerViewStyle(BattleSide::white);
    for(int j = i; j < i + initer->GetWhiteCheckersQuantity(); j++)
    {
        checkers.push_back(new QChecker(game->getGamePosition()[j],
                                         stl, BattleSide::white));
    }
}

std::vector<QChecker*> QCheckersHolder::GetCheckers() const
{
    return checkers;
}
