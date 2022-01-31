// CS1300 Spring 2019
// Author: Harrison Webb
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/harrisonwebb8/csci1300webb
// Project 3

#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <iostream>
#include <string>
//#include <vector>
//#include "Player.hpp"
using namespace std;

class Player; //some circular dependency thing/ forward declaration

class Enemy{
    public:
        Enemy();
        Enemy(string xName, double xHealth, double xDamage, double xAccuracy, double xConstitution, double xExpValue);
        
        //getters
        string getName();
        double getHealth();
        double getDamage();
        double getAccuracy();
        double getConstitution();
        double getExpValue();
        int getIPosition();
        int getJPosition();
        //setters
        void setName(string _name);
        void setHealth(double _health);
        void setDamage(double _damage);
        void setAccuracy(double _accuracy);
        void setConstitution(double _constitution);
        void setExpValue(double _exp);
        void setIPosition(int i);
        void setJPosition(int j);
        
        void attackPlayer(Player p);
        
    private:
        string name;
        double health;
        double damage;
        double accuracy;
        double constitution;
        double expValue;
        int iPosition;
        int jPosition;
};

#endif