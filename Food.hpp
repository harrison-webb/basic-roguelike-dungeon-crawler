// CS1300 Spring 2019
// Author: Harrison Webb
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/harrisonwebb8/csci1300webb
// Project 3

#ifndef FOOD_HPP
#define FOOD_HPP
#include <iostream>
#include <string>
using namespace std;

class Food{
    public:
        Food();
        Food(string str);
        
        string getName();
        double getFoodValue();
        
        void setFood(string f);
        void setName(string str);
        void setFoodValue(int z);
    private:
        string name;
        int foodValue;
};
#endif