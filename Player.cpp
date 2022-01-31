
#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"
#include "Map.hpp"
#include "Food.hpp"
#include "Enemy.hpp"
#include <random>
using namespace std;

Player::Player(){
    name = "";
    health = 0.0;
    totalHealth = 0;
    damage = 0.0;
    accuracy = 0.0;
    level = 0;
    range = 0;
    vision = 0;
    agility = 0.0;
    charisma = 0.0;
    alive = true;
}

Player::Player(int selection, string xName){
    name = xName;
    level = 1;
    alive = true;
    cake.setFood("cake");
    tomato.setFood("tomato");
    
    if(selection == 1){ //warrior
        health = 15;
        totalHealth = 15;
        damage = 4;
        accuracy = 0.6;
        range = 1;
        vision = 7;
        agility = 0.1;
        charisma = 0.1;
    }
    
    if(selection == 2){ //archer
        health = 12;
        totalHealth = 12;
        damage = 3;
        accuracy = 0.7;
        range = 3;
        vision = 8;
        agility = 0.3;
        charisma = 0.1;
    }
    
    if(selection == 3){ //mage
        health = 10;
        totalHealth = 10;
        damage = 2;
        accuracy = 0.8;
        range = 4;
        vision = 10;
        agility = 0.1;
        charisma = 0.3;
    }
}

string Player::getName(){
    return name;
}
double Player::getHealth(){
    return health;
}
int Player::getTotalHealth(){
    return totalHealth;
}
double Player::getDamage(){
    return damage;
}
double Player::getAccuracy(){
    return accuracy;
}
int Player::getLevel(){
    return level;
}
int Player::getRange(){
    return range;
}
int Player::getVision(){
    return vision;
}
vector<Food> Player::getInventory(){
    return inventory;
}
double Player::getAgility(){
    return agility;
}
double Player::getCharisma(){
    return charisma;
}
int Player::getIPosition(){
    return iPosition;
}
int Player::getJPosition(){
    return jPosition;
}
bool Player::isAlive(){
    return alive;
}
Food Player::getTomato(){
    return tomato;
}
Food Player::getCake(){
    return cake;
}
//setters
void Player::setName(string _name){
    name = _name;
}
void Player::setHealth(double _health){
    health = _health;
}
void Player::setTotalHealth(int _totalHealth){
    totalHealth = _totalHealth;
}
void Player::setDamage(double _damage){
    damage = _damage;
}
void Player::setAccuracy(double _accuracy){
    accuracy = _accuracy;
}
void Player::setLevel(int _level){
    level = _level;
}
void Player::setRange(int _range){
    range = _range;
}
void Player::setVision(int _vision){
    vision = _vision;
}
void Player::setAgility(double _agility){
    agility = _agility;
}
void Player::setCharisma(double _charisma){
    charisma = _charisma;
}
void Player::setIPosition(int i){
    iPosition = i;
}
void Player::setJPosition(int j){
    jPosition = j;
}

//actions
void Player::levelUp(){ //TODO
    level += 1;
}
void Player::eat(int index){
    if(health + inventory.at(index).getFoodValue() > (double)totalHealth){
        health = totalHealth;
    }
    else{
        health += inventory.at(index).getFoodValue();
    }
}
int Player::move(char direction, Map& m){
    int i = 0, j = 0;
    int f = iPosition, g = jPosition;
        switch(direction){
            case 'w':
            case 'W':
                i = -1;
                break;
            case 'a':
            case 'A':
                j = -1;
                break;
            case 's':
            case 'S':
                i = 1;
                break;
            case 'd':
            case 'D':
                j = 1;
                break;
            default:
                cout << "Invalid entry: Please enter eithe W, A, S, or D to move" << endl;
                break;
                
        }
    if(m.getTileAt(f+i, g+j).getType() == "wall"){ //check if player is trying to move into a wall
        cout << "You can't walk through walls! Choose a different direction." << endl;
    }
    else if(m.getTileAt(f+i, g+j).getType() == "enemy"){
        cout << "There's an enemy there!" << endl;
    }
    else{
        iPosition += i;
        jPosition += j;
        
        if(m.getTileAt(iPosition, jPosition).getType() == "trap"){          //
            cout << "Stepped on a trap!" << endl << "-1 HP" << endl;        //
            health--;
            if(health == 0){
                alive = false;
                return 9;
            }
            else{
                cout << "HP: " << health << "/" << totalHealth << endl;
                m.setTileAt(iPosition, jPosition, "floor");
            }
        }
        if(m.getTileAt(iPosition, jPosition).getType() == "tomato"){
            cout << "tomato added to inventory" << endl;
            inventory.push_back(tomato);
            m.setTileAt(iPosition, jPosition, "floor");
        }
        if(m.getTileAt(iPosition, jPosition).getType() == "cake"){
            cout << "Cake added to inventory. Yum!" << endl;
            inventory.push_back(cake);
            m.setTileAt(iPosition, jPosition, "floor");
        }
        if(m.getTileAt(iPosition, jPosition).getType() == "weapon"){
            cout << "Picked up a shiny new weapon!" << endl << "+1 Damage" << endl;
            damage++;
            m.setTileAt(iPosition, jPosition, "floor");
        }
        if(m.getTileAt(iPosition, jPosition).getType() == "stairs"){
            return 2;
        }
    }
}
void Player::attack(Enemy e1){
    //TODO rand() shit
}
void Player::rest(){
    health += 1;
}
void Player::dodge(Enemy e2){
    //TODO
}
void Player::charm(Enemy e3){
    //TODO
}

void Player::printMiniMap(Map m){
    for(int i = iPosition - vision; i <= iPosition + vision; i++){
        cout << "           ";
        for(int j = jPosition - vision; j <= jPosition + vision; j++){
            if(i == iPosition && j == jPosition){
                cout << 'P';
            }
            else{
                m.getTileAt(i,j).printTile();
            }
        }
        cout << endl;
    }
}