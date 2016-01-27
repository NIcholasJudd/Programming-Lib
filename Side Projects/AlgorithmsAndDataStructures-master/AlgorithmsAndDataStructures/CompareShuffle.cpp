//
//  sortShuffle.cpp
//  SortingModule
//
//  Created by Nicholas Judd on 16/08/2015.
//  Copyright (c) 2015 Nicholas Judd. All rights reserved.
//

#include "ResourcePath.hpp"


void comparisonModule::shuffleArray(){
    sf::Vector2f one, two;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(std::begin(sortList[0]),std::end(sortList[0]),g);
    sortList[2] = sortList[1] = sortList[0];
}

void comparisonModule::reverseSortArray(){
    std::reverse(std::begin(sortList[0]), std::end(sortList[0]));
    std::reverse(std::begin(sortList[1]), std::end(sortList[1]));
    std::reverse(std::begin(sortList[2]), std::end(sortList[2]));
}

void comparisonModule::forwardSortArray(){
    std::sort(std::begin(sortList[0]), std::end(sortList[0]));
    std::sort(std::begin(sortList[1]), std::end(sortList[1]));
    std::sort(std::begin(sortList[2]), std::end(sortList[2]));
}
