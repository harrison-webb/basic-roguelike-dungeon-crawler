// CS1300 Spring 2019
// Author: Harrison Webb
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/harrisonwebb8/csci1300webb
// Project 3

#ifndef TILE_HPP
#define TILE_HPP
#include <iostream>
#include <string>
using namespace std;

class Tile{
    public:
        Tile();
        Tile(string str);
        
        //getters
        string getType();
        
        //setters
        void setType(string _type);
        
        void printTile();
    
    private:
        string type;
    
};

#endif