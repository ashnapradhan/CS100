#pragma once

#include <string>

using std::string;

class Weapon {
 private:
    int attackPoints;
    string weaponName;
    string move1;
    string move2;

 public:
    Weapon(int atkPnt, string name, string m1, string m2);

    int getAttackPoints() const;
    string getWeaponName() const;
    string getMove1() const;
    string getMove2() const;
    
    void changeAttackPoints(int changeAmount);
};