#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include "../State/State.h"
#include "../Ability/Ability.h"
#include "../Exceptions/Errors.h"

class Ability;

class Unit {
    protected:
        const char* name;
        State* state;
        Ability* ability;

    public:
        Unit();
        const char* getName() const ;
        int getDamage() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;

        void setHitPoints(int value);
        void setHitPointsLimit(int value);
        void setDamage(int value);

        virtual void description() = 0;
        void attack(Unit* enemy);
        void ensureIsAlive();

};

#endif
