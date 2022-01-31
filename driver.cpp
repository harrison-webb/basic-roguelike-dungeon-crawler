// CS1300 Spring 2019
// Author: Harrison Webb
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/harrisonwebb8/csci1300webb
// Project 3

#include <iostream>
#include <string>
using namespace std;
#include "Food.hpp"
#include "Boss.hpp"
#include "Enemy.hpp"
#include "Game.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Tile.hpp"
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main(){
    srand (time(NULL));
    Game game1;
    game1.mainMenu();
    //cout << endl;
    //game1.play(sampleMap);
    // //sampleMap.print();
    // //cout << endl << sampleMap.getFoodRate() << endl;
    // sampleMap.loadStuff();
    // sampleMap.print();
    
    
   // game1.play(sampleMap);
}