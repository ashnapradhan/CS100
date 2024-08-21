#include "../header/enemy.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Enemy::Enemy() {
    this->name = "";
    this->hp = 0;
    this->atk = 0;
    this->difficulty = 0;
}

Enemy::Enemy(const string& name, int hp, int atk, int difficulty) {
    this->name = name;
    this->hp = hp;
    this->atk = atk;
    this->difficulty = difficulty;
}

const string& Enemy::getName() const {
    return name;
}

int Enemy::getHP() {
    return hp;

}


int Enemy::getATK() {
    return atk;

}

int Enemy::getMaxHP() {
    return hp;

}

int Enemy::getDifficulty() {
    return difficulty;
}

void Enemy::setHP(int newHP) {
    hp = newHP;
    
}

void Enemy::setATK(int newATK) {
    atk = newATK;

}

void Enemy::setName(string newName) {
    name = newName;
}

const string& Enemy::getMove1Name() {
    return defaultMove1Name;
   
}

const string& Enemy::getMove2Name() {
    return defaultMove2Name;
  
}





 /*

void Enemy::getEnemyArt() {

}
*/



