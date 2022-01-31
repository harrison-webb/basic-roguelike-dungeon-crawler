// CS1300 Spring 2019
// Author: Harrison Webb
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/harrisonwebb8/csci1300webb
// Project 3

#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Tile.hpp"
using namespace std;

class Map{
    public:
        Map();
        Map(string fileName, double _respawnRate, double _foodRate, double _WeaponRate, double _trapRate);
        
        //getters
        double getRespawnRate();
        double getFoodRate();
        double getWeaponRate();
        double getTrapRate();
        Tile getTileAt(int x, int y);
        
        //setters
        void setRespawnRate(double xRespawnRate);
        void setFoodRate(double xFoodRate);
        void setWeaponRate(double xWeaponRate);
        void setTrapRate(double xTrapRate);
        void setTileAt(int a, int b, string str);
        
        void setTile(/*int x, int y, */string xType);
        void print();
        void update();
        void loadStuff();
        void boss();
        
        
    private:
        const static int row = 36;
        const static int col = 70;
        Tile map[row][col]; //map is a 2d array of tiles. #TODO array size
        double respawnRate;
        double foodRate;
        double weaponRate;
        double trapRate;
};

#endif