//
//  sortSorts.cpp
//  SortingModule
//
//  Created by Nicholas Judd on 17/08/2015.
//  Copyright (c) 2015 Nicholas Judd. All rights reserved.
//

#include "ResourcePath.hpp"

void comparisonModule::bubbleSortFunction(sf::RenderWindow& mainWindow){
    sf::Clock clock;
    for (int i = 1; i < size;i++){
        for (int j = 0; j < size-i; j++){
            comparisons[0]++;
            if (sortList[0][j] > sortList[0][j+1]){
                swaps[0]++;
                std::swap(sortList[0][j+1], sortList[0][j]);
            }
        }
    }
    sf::Time elapsed1 = clock.getElapsedTime();
    time[0] = elapsed1.asSeconds();
}
void comparisonModule::selectionSortFunction(sf::RenderWindow& mainWindow){
    sf::Clock clock;
    int minIndex = 0;
    for (int i = 0; i < size-1; i++){
        minIndex = i;
        for (int j = i + 1; j < size; j++){
            comparisons[1]++;
            if (sortList[1][j] < sortList[1][minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            swaps[1]++;
            std::swap(sortList[1][i], sortList[1][minIndex]);
        }
    }
    sf::Time elapsed1 = clock.getElapsedTime();
    time[1] = elapsed1.asSeconds();
}

void comparisonModule::insertionSortFunction(sf::RenderWindow& mainWindow){
    sf::Clock clock;
    int j = 0;
    for (int i = 1; i < size; i++){
        j = i;
        comparisons[2]++;
        while (j>0 && sortList[2][j-1] > sortList[2][j]){
            swaps[2]++;
            std::swap(sortList[2][j-1], sortList[2][j]);
            j--;
        }
    }
    
    sf::Time elapsed1 = clock.getElapsedTime();
    time[2] = elapsed1.asSeconds();
}
