//
//  sortShuffle.cpp
//  SortingModule
//
//  Created by Nicholas Judd on 16/08/2015.
//  Copyright (c) 2015 Nicholas Judd. All rights reserved.
//

#include "ResourcePath.hpp"


void sortingModule::shuffleArray(){
    sf::Vector2f one, two;
    std::srand((int)std::time(0));
    for (int i =0; i < size; i++){
        // Pick a random index from 0 to i
        int j = rand() % (size);
        std::swap(sortList[i].heightValue, sortList[j].heightValue);
        one = sortList[i].rect.getSize();
        two = sortList[j].rect.getSize();
        sortList[i].rect.setSize(two);
        sortList[j].rect.setSize(one);
        sortList[i].rect.setFillColor(sf::Color::White);
        sortList[j].rect.setFillColor(sf::Color::White);
    }
}

void sortingModule::reverseSortArray(){
    sf::Vector2f one, two;
    for (int i = 0; i < size; i++){
        for (int j = 1; j < size; j++){
            if (sortList[j].heightValue > sortList[j-1].heightValue){
                std::swap(sortList[j].heightValue, sortList[j-1].heightValue);
                one = sortList[j].rect.getSize();
                two = sortList[j-1].rect.getSize();
                sortList[j].rect.setSize(two);
                sortList[j-1].rect.setSize(one);
                sortList[j].rect.setFillColor(sf::Color::White);
                sortList[j-1].rect.setFillColor(sf::Color::White);
            }
        }
    }
}

void sortingModule::forwardSortArray(){
    sf::Vector2f one, two;
    for (int i = 0; i < size; i++){
        for (int j = 1; j < size; j++){
            if (sortList[j].heightValue < sortList[j-1].heightValue){
                std::swap(sortList[j].heightValue, sortList[j-1].heightValue);
                one = sortList[j].rect.getSize();
                two = sortList[j-1].rect.getSize();
                sortList[j].rect.setSize(two);
                sortList[j-1].rect.setSize(one);
                sortList[j].rect.setFillColor(sf::Color::White);
                sortList[j-1].rect.setFillColor(sf::Color::White);
            }
        }
    }
}
