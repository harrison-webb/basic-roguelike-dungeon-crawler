// CS1300 Spring 2019
// Author: Harrison Webb
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/harrisonwebb8/csci1300webb
// Project 3

#include <iostream>
#include <string>
#include "Food.hpp"
using namespace std;

Food::Food(){
    name = "";
    foodValue = 0;
}

Food::Food(string str){
    name = str;
    
    if(str == "tomato"){
        foodValue = 2;
    }
    
    if(str == "cake"){
        foodValue = 4;
    }
}

string Food::getName(){
    return name;
}
double Food::getFoodValue(){
    return foodValue;
}

void Food::setFood(string f){
    if(f == "cake"){
        name = "cake";
        foodValue = 4;
    }
    else if(f == "tomato"){
        name = "tomato";
        foodValue = 2;
    }
    else{
        name = "fuk"; //**
        foodValue = 0;
    }
}