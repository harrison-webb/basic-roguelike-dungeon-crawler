// CS1300 Spring 2019
// Author: Harrison Webb
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/harrisonwebb8/csci1300webb
// Project 3

#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"
#include "Map.hpp"
#include "Enemy.hpp"
using namespace std;

class Game{
    public:
        Game();
        
        int getNumTurns();
        int getLevelNum();
        
        void setNumTurns(int _numTurns);
        void setLevelNum(int _levelNum);
        
        int mainMenu();
        void play(Map& m2);
        void howToPlay();
        void displayMenu(Map& m);
        void intro(); //
        void initialize();
        Map newLevel(Map& m1);
        void Turn(Map& m3);
        
        void moveEnemies(Map& m4);
        void loadEnemies(Map& m5);
    private:
        int numTurns;
        int levelNum;
        bool gameFlag;
        Player user;
        vector<Enemy> enemies;
        Enemy skeleton;
        //Map gameMap; probably not ideal
        
};

#endif