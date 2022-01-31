// CS1300 Spring 2019
// Author: Harrison Webb
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/harrisonwebb8/csci1300webb
// Project 3

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <random>
#include "Map.hpp"
#include "Tile.hpp"
using namespace std;



Map::Map(){
    respawnRate = 0.1;
    foodRate = 0.5;
    weaponRate = 0.05;
    trapRate = 0.1;
}

Map::Map(string fileName, double _respawnRate, double _foodRate, double _weaponRate, double _trapRate){
    respawnRate = _respawnRate;
    foodRate = _foodRate;
    weaponRate = _weaponRate;
    trapRate = _trapRate;
    
    string line = "";
    int i = 0;
    ifstream inFile;
    inFile.open(fileName);
    if(inFile.fail()){
        cout << "Failed to load map" << endl;
        inFile.close();
    }
    
    else{
        while(getline(inFile, line)){
            for(int j = 0; j < col; j++){
                if(line[j] == '+'){
                    map[i][j].setType("wall");
                }
                
                if(line[j] == 'o'){
                    map[i][j].setType("floor");
                }
            }
            i++;
        }
    }
    inFile.close();
}

void Map::print(){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            map[i][j].printTile();
        }
        cout << endl;
    }
}

void Map::update(){ //loads new map and changes data member values for next floor
    // default_random_engine mapNumGenerator;
    // uniform_int_distribution<int> mapNumDistribution(1,6);
    int mapNum = rand() % 6 +1;//mapNumDistribution(mapNumGenerator); //random number between 1 and 6
    string fileName = "map" + to_string(mapNum) + ".txt";
    
    //load map from the new file
    string line = "";
    int i = 0;
    ifstream inFile;
    inFile.open(fileName);
    if(inFile.fail()){
        cout << "Failed to load map" << endl;
        inFile.close();
    }
    
    else{
        while(getline(inFile, line)){
            for(int j = 0; j < col; j++){
                if(line[j] == '+'){
                    map[i][j].setType("wall");
                }
                
                if(line[j] == 'o'){
                    map[i][j].setType("floor");
                }
            }
            i++;
        }
    }
    inFile.close();
    
    //update map data members
    respawnRate += 0.05;
    if(foodRate >= 0.03){
        foodRate -= 0.03;
    }
    if(weaponRate >= 0.01){
        weaponRate -= 0.01;
    }
    trapRate += 0.01;
}

void Map::loadStuff(){
    //load stairs on one tile
    // default_random_engine generator1;
    // default_random_engine generator2;
    // uniform_int_distribution<int> distribution1(0,26);
    // uniform_int_distribution<int> distribution2(0,60); seeding isnt working for these :(
    bool onFloor = false;
    int randomRow, randomCol;
    while(!onFloor){
        randomRow = rand() % row;//distribution1(generator1);
        randomCol = rand() % col;//distribution2(generator2);
        if(map[randomRow][randomCol].getType() == "floor"){
            onFloor = true;
        }
        
    }
    map[randomRow][randomCol].setType("stairs");
    
    //load other things that can exist more than once in a map
    default_random_engine generator3;
     for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(map[i][j].getType() == "floor"){
                //int loadChance = rand() % 10 +1;
               // if(loadChance <= 8){ //8 in 10 chance to have a chance to load something on the floor
                    //tile types to be loaded: food, traps, weapons
                    uniform_int_distribution<int> distribution3(1,3);
                    int randomTile = distribution3(generator3);
                    int randBase = rand() % 100 + 1;
                    switch(randomTile){
                        case 1: //food
                            if(randBase * foodRate > 35){
                                int foodRand = rand() % 2;
                                if(foodRand == 0){
                                    map[i][j].setType("tomato");
                                }
                                if(foodRand == 1){
                                    map[i][j].setType("cake");
                                }
                            }
                            break;
                        case 2: //traps
                            if(randBase * trapRate > 9.9){
                                map[i][j].setType("trap");
                            }
                            break;
                        case 3: //weapons
                            if(randBase * weaponRate > 4.9){
                                map[i][j].setType("weapon");
                            }
                            break;
                    }
                    
                //}
            }
        }
     }    
}

void Map::boss(){
    string line = "";
    int i = 0;
    ifstream inFile;
    inFile.open("mapBoss.txt");
    if(inFile.fail()){
        cout << "Failed to load map" << endl;
        inFile.close();
    }
    
    else{
        while(getline(inFile, line)){
            for(int j = 0; j < col; j++){
                if(line[j] == '+'){
                    map[i][j].setType("wall");
                }
                
                if(line[j] == 'o'){
                    map[i][j].setType("floor");
                }
                
            }
            i++;
        }
    }
    inFile.close();
}

double Map::getRespawnRate(){
    return respawnRate;
}
double Map::getFoodRate(){
    return foodRate;
}
double Map::getWeaponRate(){
    return weaponRate;
}
double Map::getTrapRate(){
    return trapRate;
}
Tile Map::getTileAt(int x, int y){
    return map[x][y];
}

void Map::setRespawnRate(double xRespawnRate){
    respawnRate = xRespawnRate;
}
void Map::setFoodRate(double xFoodRate){
    foodRate = xFoodRate;
}
void Map::setWeaponRate(double xWeaponRate){
    weaponRate = xWeaponRate;
}
void Map::setTrapRate(double xTrapRate){
    trapRate = xTrapRate;
}
void Map::setTileAt(int a, int b, string str){
    map[a][b].setType(str);
}

// void Map::setTile(string xStr){
//     map[x][y].setType(xStr);
// }