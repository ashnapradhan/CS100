#include "../header/player.hpp"
#include "../header/equipment/armor.hpp"
#include "../header/equipment/weapon.hpp"

#include <stdexcept>

using std::runtime_error;

Player::Player(int classNum, const string& pName) {
    if(classNum == 1) {         //Swordsman
        classType = "Swordsman";
        name = pName;
        maxHealth = 0;
        health = 0;
        attack = 0;
        defaultMove1Name = "Hit";
        defaultMove2Name = "Strike";

        { //Load all weapons and armor
            weaponList.push_back( Weapon(10, "Bow", "Fire", "Snipe") );

            armorList.push_back( Armor(10, "Leather Tunic") );
        }

        equipWeapon(0);
        equipArmor(0);

    } else if(classNum == 2) {  //Mage

    } else if(classNum == 3) {  //Archer
        classType = "Archer";
        name = pName;
        maxHealth = 100;
        health = 100;
        attack = 10;
        defaultMove1Name = "Shoot";
        defaultMove2Name = "Snipe";

        { //Load all weapons and armor
            weaponList.push_back( Weapon(10, "Bow", "", "") );

            armorList.push_back( Armor(10, "Leather Tunic") );
        }

        equipWeapon(0);
        equipArmor(0);

    } else {
        throw runtime_error("player constructor error");
    }
}

const string& Player::getPlayerClass() {
    return classType;
}

const string& Player::getName() {
    return name;
}

int Player::getMaxHP() {
    return maxHealth;
}

int Player::getHP() {
    return health;
}

int Player::getATK() {
    return attack;
}

const string& Player::getMove1Name() {
    if(weaponList.at(weaponIndex).getMove1().empty()) {
        return defaultMove1Name;
    } else {
        return weaponList.at(weaponIndex).getMove1();
    }
}

const string& Player::getMove2Name() {
    if(weaponList.at(weaponIndex).getMove2().empty()) {
        return defaultMove2Name;
    } else {
        return weaponList.at(weaponIndex).getMove2();
    }
}

void Player::setMaxHP(int newMaxHP) {
    maxHealth = newMaxHP;
}

void Player::setHP(int newHP) {
    health = newHP;
}

void Player::setATK(int newATK) {
    attack = newATK;
}

void Player::equipWeapon(int index) {
    // if(index == weaponIndex) {
    //     throw runtime_error("player equipWeapon same_index_error");
    // }

    //Remove old weapon attack bonuses
    setATK( getATK() - weaponList.at(weaponIndex).getAttackPoints() );

    //Change to new weapon and push_back new weapon attack bonuses
    weaponIndex = index;
    setATK( getATK() + weaponList.at(weaponIndex).getAttackPoints() );
}

void Player::equipArmor(int index) {
    // if(index == armorIndex) {
    //     throw runtime_error("player equipArmor same_index_error");
    // }

    //Remove old armor health bonuses
    setMaxHP( getMaxHP() - armorList.at(armorIndex).getHealthPoints() );
    setHP( getHP() - armorList.at(armorIndex).getHealthPoints() );

    //Change to new armor and push_back new armor health bonuses
    armorIndex = index;
    setMaxHP( getMaxHP() + armorList.at(armorIndex).getHealthPoints() );
    setHP( getHP() + armorList.at(armorIndex).getHealthPoints() );

    if(getHP() <= 0) {
        setHP( armorList.at(armorIndex).getHealthPoints() );
    }
}