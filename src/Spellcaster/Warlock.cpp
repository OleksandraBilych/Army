#include "Warlock.h"

#define DEBUG 1

Warlock::Warlock(const char* name, int maxHp, int damage, int mana) {
    if ( DEBUG ) {
        std::cout << "WARLOCK::CONSTRUCTOR" << std::endl;
    }

    isCombatMage = true;
    this->name = name;
    this->state = new WarlockState(maxHp, damage, mana);
    this->ability = new BaseAttack();

    spellBook.insert ( std::pair<const char*, Spell*>("SummonDemon", SummonDemon::createSpell()) );
}

void Warlock::description() {
    if ( DEBUG ) {
        std::cout << "WARLOCK::description" << std::endl;
    }

    std::cout << "\nHealing mage - " << name << std::endl;
    state->showState();

}

Demon* Warlock::spell(const char* spellName, const char* demonName) {
    if ( DEBUG ) {
        std::cout << "WARLOCK::SPELL SUMONDEMON" << std::endl;
    }
    // (spellBook.at("SummonDemon"))->spell(this,this);
    return (dynamic_cast<SummonDemon*>(spellBook.at("SummonDemon")))->spell(this, demonName);
    // return NULL;
}