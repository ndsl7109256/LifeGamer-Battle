#ifndef TOWER_H
#define TOWER_H

#include "unit.h"
#include "battle.h"

class Tower : public Unit
{
public:
    Tower(int hp, int atk, int attackRange, int attackDelay, int group, int target, Battle *battle, QObject *parent);

    void setPoint(int x, int y);
    virtual QJsonObject toJsonObject(bool isNew = false);

    int SN;

public slots:
    virtual void active();
};

#endif // TOWER_H
