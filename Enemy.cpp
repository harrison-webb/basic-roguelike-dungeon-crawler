#include <iostream>
#include <string>
#include <vector>
#include "Enemy.hpp"
#include "Player.hpp"
using namespace std;

Enemy::Enemy(){
    name = "";
    health = 0;
    damage = 0;
    accuracy = 0;
    constitution = 0;
    expValue = 0;
}

Enemy::Enemy(string xName, double xHealth, double xDamage, double xAccuracy, double xConstitution, double xExpValue){
    name = xName;
    health = xHealth;
    damage = xDamage;
    accuracy = xAccuracy;
    constitution = xConstitution;
    expValue = xExpValue;
}

string Enemy::getName(){
    return name;
}
double Enemy::getHealth(){
    return health;
}
double Enemy::getDamage(){
    return damage;
}
double Enemy::getAccuracy(){
    return accuracy;
}
double Enemy::getConstitution(){
    return constitution;
}
double Enemy::getExpValue(){
    return expValue;
}
int Enemy::getIPosition(){
    return iPosition;
}
int Enemy::getJPosition(){
    return jPosition;
}

//setters
void Enemy::setName(string _name){
    name = _name;
}
void Enemy::setHealth(double _health){
    health = _health;
}
void Enemy::setDamage(double _damage){
    damage = _damage;
}
void Enemy::setAccuracy(double _accuracy){
    accuracy = _accuracy;
}
void Enemy::setConstitution(double _constitution){
    constitution = _constitution;
}
void Enemy::setExpValue(double _exp){
    expValue = _exp;
}
void Enemy::setIPosition(int i){
    iPosition = i;
}
void Enemy::setJPosition(int j){
    jPosition = j;
}

void Enemy::attackPlayer(Player p){    //TODO
}