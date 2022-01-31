// CS1300 Spring 2019
// Author: Harrison Webb
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/harrisonwebb8/csci1300webb
// Project 3
//types of tiles: floor[o], wall[+], trap[o], stairs[S], weapon[W], tomato[T], cake[C]

#include <iostream>
#include <string>
#include "Tile.hpp"
using namespace std;

Tile::Tile(){
    type = "";
}

Tile::Tile(string str){
    type = str;
}

string Tile::getType(){
    return type;
}

void Tile::setType(string _type){
    type = _type;
}

void Tile::printTile(){
    if(type == "wall"){
        cout << "+"; //**
    }
    if(type == "floor" || type == "trap"){
        cout << ' ';
    }
    if(type == "stairs"){
        cout << 'S';
    }
    if(type == "weapon"){
        cout << 'W';
    }
    if(type == "tomato"){
        cout << 'T';
    }
    if(type == "cake"){
        cout << 'C';
    }
    if(type == "enemy"){
        cout << 'E';
    }
    
}