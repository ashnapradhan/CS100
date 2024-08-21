#include <string>

#include "../header/equipment/weapon.hpp"

using std::string;

Weapon::Weapon(int atkPnt, string name, string m1, string m2) {
    attackPoints = atkPnt;
    weaponName = name;
    move1 = m1;
    move2 = m2;
}

int Weapon::getAttackPoints() const {
    return attackPoints;
}

string Weapon::getWeaponName() const {
    return weaponName;
}

string Weapon::getMove1() const {
    return move1;
}

string Weapon::getMove2() const {
    return move2;
}

void Weapon::changeAttackPoints(int changeAmount) {
    attackPoints += changeAmount;
}