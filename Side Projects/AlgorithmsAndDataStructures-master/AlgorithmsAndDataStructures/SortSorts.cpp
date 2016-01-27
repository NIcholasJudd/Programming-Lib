//
//  sortSorts.cpp
//  SortingModule
//
//  Created by Nicholas Judd on 17/08/2015.
//  Copyright (c) 2015 Nicholas Judd. All rights reserved.
//

#include "ResourcePath.hpp"

// Bubble sort animation list
//1. compare.
//2. swap.
//3. element in its correct position.
//4. array is correctly sorted.
//5. loop 1
//6. loop 2
void sortingModule::bubbleSortFunction(sf::RenderWindow& mainWindow){
    bool swapped = false;
    std::vector<sortArray> tempArray = sortList;
    animation Animation;
    Animation.action = 5;
    animate.push_back(Animation);
    for (int i = 1; i < size;i++){
        
        for (int j = 0; j < size-i; j++){
            animation Animation;
            Animation.action = 6;
            animate.push_back(Animation);
            Animation.element1 = j;
            Animation.element2 = j+1;
            Animation.action = 1;
            animate.push_back(Animation);
            if (tempArray[j].heightValue > tempArray[j+1].heightValue){
                
                swapped = true;
                animation Animation;
                Animation.element1 = j;
                Animation.element2 = j+1;
                Animation.action = 2;
                animate.push_back(Animation);
                std::swap(tempArray[j+1].heightValue, tempArray[j].heightValue);
                std::swap(tempArray[j+1].rect, tempArray[j].rect);
                Animation.action = 6;
                animate.push_back(Animation);
            }
        }
        animation Animation;
        Animation.action = 3;
        animate.push_back(Animation);
        if (swapped == false){
            animation Animation;
            Animation.action = 4;
            animate.push_back(Animation);
            return;
        }
        swapped = false;
        Animation.action = 5;
        animate.push_back(Animation);
    }
    Animation.action = 4;
    animate.push_back(Animation);
    Animation.action = 5;
    animate.push_back(Animation);
}
//Selection sort animation list
//1. compare elements
//2. swap elements
//3. array sorted
//4. loop 1
//5. loop 2
//6. set min element 1
//7. set min element 2
void sortingModule::selectionSortFunction(sf::RenderWindow& mainWindow){
    int minIndex = 0;
    std::vector<sortArray> tempArray = sortList;
    for (int i = 0; i < size-1; i++){
        animation Animation;
        Animation.action = 4;
        animate.push_back(Animation);
        minIndex = i;
        Animation.action = 6;
        animate.push_back(Animation);
        for (int j = i + 1; j < size; j++){
            animation Animation;
            Animation.action = 5;
            animate.push_back(Animation);
            Animation.element1 = minIndex;
            Animation.element2 = j;
            Animation.action = 1;
            animate.push_back(Animation);
            if (tempArray[j].heightValue < tempArray[minIndex].heightValue){
                animation Animation;
                Animation.action = 7;
                animate.push_back(Animation);
                minIndex = j;
            }
        }
        if(minIndex != i){
            animation Animation;
            Animation.element1 = minIndex;
            Animation.element2 = i;
            Animation.action = 2;
            animate.push_back(Animation);
            std::swap(tempArray[i].heightValue, tempArray[minIndex].heightValue);
            std::swap(tempArray[i].rect, tempArray[minIndex].rect);
        }
    }
    animation Animation;
    Animation.action = 3;
    animate.push_back(Animation);
}
//Insertion sort animation list
//1. compare elements
//2. swap elements
//3. set min element
//4. array sorted
//5. loop 1
//6. while
void sortingModule::insertionSortFunction(sf::RenderWindow& mainWindow){
    int j = 0;
    std::vector<sortArray> tempArray = sortList;
    for (int i = 1; i < size; i++){
        j = i;
        animation Animation;
        Animation.action = 3;
        animate.push_back(Animation);
        Animation.action = 5;
        animate.push_back(Animation);
        Animation.element1 = j-1;
        Animation.element2 = j;
        Animation.action = 1;
        animate.push_back(Animation);
        while (j>0 && tempArray[j-1].heightValue > tempArray[j].heightValue){
            animation Animation;
            Animation.action = 6;
            animate.push_back(Animation);
            Animation.element1 = j-1;
            Animation.element2 = j;
            Animation.action = 1;
            animate.push_back(Animation);
            Animation.element1 = j-1;
            Animation.element2 = j;
            Animation.action = 2;
            animate.push_back(Animation);
            std::swap(tempArray[j-1].heightValue, tempArray[j].heightValue);
            std::swap(tempArray[j-1].rect, tempArray[j].rect);
            j--;
        }
    }
    animation Animation;
    Animation.action = 4;
    animate.push_back(Animation);
}
