// CS1300 Spring 2019
// Author: Harrison Webb
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/harrisonwebb8/csci1300webb
// Project 3
//  Warrior class                  //  Archer class                //  Mage class 
//  Health: High                   //  Health: Medium              //  Health: Low
//  Damage: High                   //  Damage: Medium              //  Damage: Low
//  Range: Low                     //  Range: Medium               //  Range: High
//  Vision: Low                    //  Vision: Medium              //  Vision: High
//  Agility: Low                   //  Agility: High               //  Agility: Low
//  Charisma: Low                  //  Charisma: Low               //  Charisma: High

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Food.hpp"
//#include "Enemy.hpp"
#include "Map.hpp"
using namespace std;

class Enemy; //forward declaration

class Player{
    public:
        Player();
        Player(int selection, string xName);
        
        //getters
        string getName();
        double getHealth();
        int getTotalHealth();
        double getDamage();
        double getAccuracy();
        int getLevel();
        int getRange();
        int getVision();
        vector<Food> getInventory();
        double getAgility();
        double getCharisma();
        int getIPosition(); //hmm ******
        int getJPosition(); // TODO
        bool isAlive();
        Food getTomato();
        Food getCake();
        
        //setters
        void setName(string _name);
        void setHealth(double _health);
        void setTotalHealth(int _totalHealth);
        void setDamage(double _damage);
        void setAccuracy(double _accuracy);
        void setLevel(int _level);
        void setRange(int _range);
        void setVision(int _vision);
        void setAgility(double _agility);
        void setCharisma(double _charisma);
        void setIPosition(int i);
        void setJPosition(int j);
        
        //actions
        void levelUp();
        void eat(int index);
        int move(char direction, Map& m);
        void attack(Enemy e1);
        void rest();
        void dodge(Enemy e2);
        void charm(Enemy e3);
        
        void printMiniMap(Map m);
    
    private:
        string name;
        double health;
        int totalHealth;
        double damage;
        double accuracy;
        int level;
        int range;
        int vision;
        vector<Food> inventory;
        double agility;
        double charisma;
        int iPosition;
        int jPosition;
        Food tomato;
        Food cake;
        bool alive;
};

#endif