// CS1300 Spring 2019
// Author: Harrison Webb
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/harrisonwebb8/csci1300webb
// Project 3

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Game.hpp"
#include "Tile.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include "Enemy.hpp"
using namespace std;

Game::Game(){
    numTurns = 0;
    levelNum = 0;
    gameFlag = true;
    
    skeleton.setName("skeleton");
    skeleton.setHealth(5);
    skeleton.setDamage(2);
    skeleton.setAccuracy(.5);
    skeleton.setConstitution(.3);
    skeleton.setExpValue(2);
}

int Game::getNumTurns(){
    return numTurns;
}
int Game::getLevelNum(){
    return levelNum;
}
void Game::setNumTurns(int _numTurns){
    numTurns = _numTurns;
}
void Game::setLevelNum(int _levelNum){
    levelNum = _levelNum;
}

int Game::mainMenu(){
    Map coolMap;
    cout << "~~~~~~~~The Sp00ky Dungeon Roguelike Game~~~~~~~~" << endl << endl;
    cout << "-----------------Main Menu-----------------------" << endl << endl;
    cout << "1. Start Game                      2. How to Play" << endl;
    cout << "3. Previous Game Stats             4. Quit" << endl << endl;
    char menuSelect;
    bool flag = true;
    while(flag){
        cout << "Make a selection (1, 2, 3, or 4): ";
        cin >> menuSelect; //TODO stringstream
        if(menuSelect == '1' || menuSelect == '2' || menuSelect == '3' || menuSelect == '4'){
            flag = false;
        }
    }
    switch(menuSelect){ //TODO
        case '1':
            play(coolMap);
            break; 
        case '2':
            howToPlay();
            mainMenu();
            break;
        case '3':
            //TODO
            mainMenu();
            break;
        case '4':
            cout << "Goodbye!" << endl;
            return 1;
            break;
    }
    
}

void Game::play(Map& m2){
    intro(); //TODO
    m2 = newLevel(m2);
    bool /*playerAlive = true,*/ endGame = false;
    while(user.isAlive() && !endGame && gameFlag){
        //dostuff
        Turn(m2);
        cout << "Number of turns: " << numTurns << endl;
        cout << "Player health: " << user.getHealth() << "/" << user.getTotalHealth() << endl;
        cout << "Player position: (" << user.getIPosition() << ", " << user.getJPosition() << ")" << endl;
        cout << "Enemy positions: " << endl;
        for(int i = 0; i < enemies.size(); i ++){
            cout << "Enemy " << i << ":" << "(" << enemies.at(i).getIPosition() << ", " << enemies.at(i).getJPosition() << ")" << endl;
        }
    }
    if(!user.isAlive()){
        cout << "You died! rip in peace" << endl;
    }
    
}
void Game::displayMenu(/*Player p,*/ Map& m){
    //print out menu stuff and minimap on screen
    cout << "Player Map:" <<endl << endl;
    //p.printMiniMap(m);
    user.printMiniMap(m);
    cout << "   _________________________________________" << endl;
    cout << " /~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~\\" << endl;
    cout << "/============================================\\" << endl;
    cout << "||    1. Move                   2. Eat      ||" << endl;
    cout << "||                                          ||" << endl;
    cout << "||    3. Combat                 4. Rest     ||" << endl;
    cout << "||                                          ||" << endl;
    cout << "||    5. Stats                  6. Quit     ||" << endl;
    cout << "||__________________________________________||" << endl;
    cout << "||==========================================||" << endl;
    cout << "Make a selection (1, 2, 3, 4, 5, or 6): ";
    int turnSelection;
    cin >> turnSelection; //TODO stringstream
    cout << endl;
    if(turnSelection == 1){ //move
        user.printMiniMap(m);
        cout << "   _________________________________________" << endl;
        cout << " /~~~~~~~~~~~~~~~~~~Move~~~~~~~~~~~~~~~~~~~~\\" << endl;
        cout << "/============================================\\" << endl;
        cout << "||   Up -> Press W       Down -> Press S    ||" << endl;
        cout << "||                                          ||" << endl;
        cout << "||                                          ||" << endl;
        cout << "||   Left -> Press A     Right -> Press D   ||" << endl;
        cout << "||                                          ||" << endl;
        cout << "||__________________________________________||" << endl;
        cout << "||==========================================||" << endl;
        char moveSelection;
        cin >> moveSelection;
        cout << endl;
        int z = user.move(moveSelection, m);
        if(z == 2){
            if(numTurns == 6){
                //boss battle
            }
            else{
                newLevel(m);
            }
        }
    }
    else if(turnSelection == 2){ //eat
        if(user.getInventory().size() == 0){
            cout << "Inventory empty- you have no food!" << endl << endl;
        }
        else{
            int tomatoes = 0;
            int cakes = 0;
            for(int i = 0; i < user.getInventory().size(); i++){
                if(user.getInventory().at(i).getName() == "cake"){
                    cakes++;
                }
                else if(user.getInventory().at(i).getName() == "tomato"){
                    tomatoes++;
                }
            }
            cout << "   _________________________________________" << endl;
            cout << " /~~~~~~~~~~~~~~~~Inventory~~~~~~~~~~~~~~~~~\\" << endl;
            cout << "/============================================\\" << endl;
            cout << "||                                          ||" << endl;
            cout << "||                                          ||" << endl;
            cout << "||    1. " << tomatoes << "x tomatoes         2. " << cakes << "x cakes    ||" << endl;
            cout << "||                                          ||" << endl;
            cout << "||                                          ||" << endl;
            cout << "||__________________________________________||" << endl;
            cout << "||==========================================||" << endl;
            char foodSelection;
            bool foodFlag = true;
            while(foodFlag){
                cout << "Make a selection (1 or 2): ";
                cin >> foodSelection;
                if(foodSelection == '1' || foodSelection == '2'){
                    foodFlag = false;
                }
            }
            if(foodSelection == '1'){
                if(tomatoes == 0){
                    cout << "You dont have any tomatoes :(" << endl;
                }
                else{
                    int marker;
                    user.setHealth(user.getHealth() + (int)user.getTomato().getFoodValue());
                    cout << "You feel marginally better after eating the tomato" << endl;
                    cout << "HP: " << user.getHealth() << "/" << user.getTotalHealth() << endl;
                    int tomatoScanNum = 0;
                    for(int i = 0; i < user.getInventory().size(); i++){
                        if(tomatoScanNum == 0){
                            if(user.getInventory().at(i).getName() == "tomato"){
                            marker = i;
                            tomatoScanNum = 1;
                            }
                        }
                        
                    }
                    user.getInventory().at(marker) = move(user.getInventory().back()); //this is supposed to remove element from inventory but seems like it isnt 
                    user.getInventory().pop_back();
                }
            }
            if(foodSelection == '2'){
                if(cakes == 0){
                    cout << "You dont have any cake :(" << endl;
                }
                else{
                    int marker;
                    user.setHealth(user.getHealth() + (int)user.getCake().getFoodValue());
                    cout << "You eat an entire cake and feel ... great." << endl;
                    cout << "HP: " << user.getHealth() << "/" << user.getTotalHealth() << endl;
                    int cakeScanNum = 0;
                    for(int i = 0; i < user.getInventory().size(); i++){
                        if(cakeScanNum == 0){
                            if(user.getInventory().at(i).getName() == "cake"){
                            marker = i;
                            cakeScanNum = 1;
                            }
                        }
                        
                    }
                    cout << "Gets through for loop" << endl;
                    user.getInventory().at(marker) = move(user.getInventory().back()); //same as above
                    user.getInventory().pop_back(); //s
                }
            }
        }
    }
    else if(turnSelection ==3){ //combat
        
    }
    else if(turnSelection == 4){ //rest
        cout << "You took a power nap and are feeling well rested" << endl;
        if(user.getHealth() < user.getTotalHealth()){
            user.setHealth(user.getHealth() + 1);
            cout << "+1 HP" << endl;
            cout << "HP: " << user.getHealth() << "/" << user.getTotalHealth() << endl;
        }
        else{
            cout << "HP full" << endl;
        }
    }
    else if(turnSelection == 5){ //stats
        cout << "   _________________________________________" << endl;
        cout << " /~~~~~~~~~~~~~~~~~~Stats~~~~~~~~~~~~~~~~~~~\\" << endl;
        cout << "/============================================\\" << endl;
        cout << "||    Health: " << user.getHealth() << "/" << user.getTotalHealth() << "          Level: "<< user.getLevel() << endl;
        cout << "||                                          ||" << endl;
        cout << "||    Damage: " << user.getDamage() << "              Accuracy: " << user.getAccuracy() << endl;
        cout << "||                                          ||" << endl;
        cout << "||    Agility: " << user.getAgility() << "           Charisma: " << user.getCharisma() << endl;
        cout << "||__________________________________________||" << endl;
        cout << "||==========================================||" << endl;
        char u;
        cout << "press any key to continue ";
        cin >> u;
        cout << endl;
    }
    else if(turnSelection == 6){ //quit
        cout << "Goodbye, " << user.getName() << "!" << endl;
        gameFlag = false;
    }
    
}

void Game::intro(){ 
    //introduce game, have player pick class/choose name, etc etc
    cout << endl << "Welcome to The Sp00ky Dungeon Roguelike Game!" << endl;
    cout << "Your village has been destroyed by an evil Wildebeest and it's up to you to stop him." << endl;
    cout << "By the way, what's your name?" << endl;
    cout << "(enter name): ";
    string name;
    cin >> name;
    cout << endl;
    cout << "Good to meet you, " << name << ". Before you go, what kind of fighter are you?" << endl;
    int p = 1;
    int selection;
    while(p == 1){
        cout << "          1: Warrior                     2. Archer                     3. Mage" << endl;
        cout << "Health:       High                           Medium                        Low" << endl;
        cout << "Damage:       High                           Medium                        Low" << endl;
        cout << "Range:        Low                            Medium                        High" << endl;
        cout << "Vision:       Low                            Medium                        High" << endl;
        cout << "Agility:      Low                            High                          Low" << endl;
        cout << "Charisma:     Low                            Low                           High" << endl;
        cout << "(select 1, 2, or 3): ";
        cin >> selection;//TODO stringstream
        cout << endl;
        if(selection == 1 || selection == 2 || selection == 3){
            p = 2;
        }
        else{
            cout << "Invalid selection, please select 1, 2, or 3:" << endl;
        }
    }
    cout << "Good luck again " << name << ", you'll need it. Your village is depending on you!" << endl;
    cout << "Your location is represented by the P in the center of the minimap. Use WASD to move!" << endl << endl;
    Player dude(selection, name);
    user = dude;
}

void Game::initialize(){ //
    
}
Map Game::newLevel(Map& m1){ //
    cout << "New Floor!" << endl;
    if(levelNum < 6){
        levelNum++;
        cout << "Level " << levelNum << ":" << endl;
        m1.update();//load map
        m1.loadStuff();
        loadEnemies(m1);
        
        //put player in random location
        bool loadPlayer = true;
        int i1, j1;
        while(loadPlayer){
            i1 = rand() % 26;
            j1 = rand() % 60;
            if(m1.getTileAt(i1,j1).getType() == "floor"){
                loadPlayer = false;
            }
        }
        user.setIPosition(i1);
        user.setJPosition(j1);
        return m1;
    }
    else{ //boss floor
        cout << "Boss Floor" << endl;
        m1.boss();
        user.setIPosition(17);
        user.setJPosition(35);
        return m1;
        
        //load boss into map as enemy
    }
}

void Game::Turn(Map& m3){
    displayMenu(m3);
    //enemy stuff
    moveEnemies(m3);
    numTurns++;
}

void Game::howToPlay(){
    cout << endl;
    cout << "----------------How To Play----------------" << endl << endl;
    cout << "Use the number keys and  W A S D  to navigate the menus and move your character" << endl << endl;
    cout << "Navigate your way through all of the floors and defeat the deadly evil Wildebeest to save your village" << endl << endl;
    cout << "Enemies and invisible traps will hurt you, but there's some cake and tomatoes scattered about that will replenish your health (marked by C and A on the minimap, respectively)" << endl <<endl;
    cout << "You can also pick up weapons that will make you stronger (marked by W)" << endl << endl;
    cout << "There are stairs in each level that will take you deeper towards the Wildebeest's lair- they're marked by 'S'" << endl << endl;
    cout << "Kill enemies for exp but be sure not to let your HP reach 0!" << endl << endl;
    cout << "Press any key to continue: ";
    char temp;
    cin >> temp;
    cout << endl << endl;
}

void Game::moveEnemies(Map& m4){
    for(int i = 0; i < enemies.size(); i++){
        bool enemyFlag = true;
        m4.setTileAt(enemies.at(i).getIPosition(), enemies.at(i).getJPosition(), "floor");
        while(enemyFlag){
            int x = rand() % 2;
            int y = rand() % 2;
            if(y == 0){
                y = -1;
            }
            if(x == 0){
                if(m4.getTileAt(enemies.at(i).getIPosition() + y, enemies.at(i).getJPosition()).getType() == "floor" && 
                    (enemies.at(i).getIPosition() + y + enemies.at(i).getJPosition()) != user.getIPosition() + user.getJPosition() ){ 
                        
                    enemies.at(i).setIPosition(enemies.at(i).getIPosition() + y);    //checking that enemy isnt being moved onto stairs or user or wall
                    enemyFlag = false;
                    m4.setTileAt(enemies.at(i).getIPosition(), enemies.at(i).getJPosition(), "enemy");
                }
                
            }
            if(x == 1){
                if(m4.getTileAt(enemies.at(i).getIPosition(), enemies.at(i).getJPosition() + y).getType() == "floor" &&
                    (enemies.at(i).getIPosition() + enemies.at(i).getJPosition() + y) != user.getIPosition() + user.getJPosition() ){
                        
                    enemies.at(i).setJPosition(enemies.at(i).getJPosition() + y); //chekcing same as above
                    enemyFlag = false;
                    m4.setTileAt(enemies.at(i).getIPosition(), enemies.at(i).getJPosition(), "enemy");
                }
            }
        }
    }
}

void Game::loadEnemies(Map& m5){
    int n = 0;
    while(n < 6){
        int x, y;
        bool z = true;
        while(z){
            x = rand() % 36;
            y = rand() % 70;
            if(m5.getTileAt(x,y).getType() == "floor"){
                enemies.push_back(skeleton);
                enemies.at(enemies.size() - 1).setIPosition(x);
                enemies.at(enemies.size() - 1).setJPosition(y);
                z = false;
            }
        }
        n++;
    }
}
