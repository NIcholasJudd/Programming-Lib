//
//  compareBuildScreen.cpp
//  compare
//
//  Created by Nicholas Judd on 4/09/2015.
//  Copyright (c) 2015 Nicholas Judd. All rights reserved.
//

#include "ResourcePath.hpp"

sf::Texture comparisonModule::backgroundTexture;
sf::Texture comparisonModule::playTexture;
sf::Texture comparisonModule::pauseTexture;
sf::Texture comparisonModule::sorttedTexture;
sf::Texture comparisonModule::revSortTexture;
sf::Texture comparisonModule::shuffleTexture;
sf::Texture comparisonModule::sortingTexture;
sf::Texture comparisonModule::barTexture;
sf::Texture comparisonModule::selectedTexture;

void beginSortingComparisson(sf::RenderWindow &mainWindow){
    comparisonModule compare;
    compare.startModule(mainWindow, compare);
}

void comparisonModule::reset(){
    largestValue = 0;
    count = 0;
    for (int i = 0; i < 3; i++){
        swaps[i] = 0;
        comparisons[i] = 0;
        time[i] = 0;
        sizeGraphTime[i].x = 5;
        sizeGraphTime[i].y = 67;
        timeGraph[i].setSize(sizeGraphTime[i]);
        largestValue = 0;
        swapsNumber[i].setString(std::to_string(swaps[i]));
        comparisonsNumber[i].setString(std::to_string(comparisons[i]));
        timeComp[i].setString(std::to_string(time[i]));
    }
    
}

void comparisonModule::startModule(sf::RenderWindow& mainWindow, comparisonModule compare){
    backgroundTexture = loadTexture("SortCompBackground04.png");
    playTexture = loadTexture("sortcomp_b_play.gif");
    pauseTexture = loadTexture("sortcomp_b_pause.gif");
    sorttedTexture = loadTexture("sortcomp_icon_sorted.gif");
    shuffleTexture = loadTexture("sortcomp_icon_shuffle.gif");
    revSortTexture = loadTexture("sortcomp_icon_reverse.gif");
    sortingTexture = loadTexture("SORTING.png");
    selectedTexture = loadTexture("sortcomp_b_selected.png");
    windowSize = mainWindow.getSize();
    buildBackground(mainWindow, compare);
    buildArray();
    while (mainWindow.isOpen())
    {
        sf::Event menuEvent;
        drawScreen(mainWindow);
        while (mainWindow.pollEvent(menuEvent))
        {
            action = -1;
            if (menuEvent.type == sf::Event::Closed) {
                mainWindow.close();
            }
            if (menuEvent.type == sf::Event::KeyPressed && menuEvent.key.code == sf::Keyboard::Q) {
                return;
            }
            if(menuEvent.type == sf::Event::MouseButtonPressed){
                sf::Vector2i click = handleMouseClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y, mainWindow);
                action = HandleClick(click.x, click.y);
            }
            switch (action) {
                case 0:
                    return;
                    break;
                case 1:
                    buildArray();
                    shuffleArray();
                    reset();
                    shuffled = true;
                    revSort = false;
                    sorted = false;
                    action = -1;
                    break;
                case 2:
                    buildArray();
                    reverseSortArray();
                    reset();
                    revSort = true;
                    sorted = false;
                    shuffled = false;
                    action = -1;
                    break;
                case 3:
                    buildArray();
                    forwardSortArray();
                    reset();
                    sorted = true;
                    shuffled = false;
                    revSort = false;
                    action = -1;
                    break;
                case 4:
                    if (!play){
                        reset();
                        play = true;
                        sf::Sprite sortingSprite;
                        sortingSprite.setTexture(sortingTexture);
                        mainWindow.draw(sortingSprite);
                        sf::Sprite pauseSprite;
                        pauseSprite.setTexture(pauseTexture);
                        pauseSprite.setPosition(534.f,606.f);
                        mainWindow.draw(pauseSprite);
                        mainWindow.display();
                        bubbleSortFunction(mainWindow);
                        selectionSortFunction(mainWindow);
                        insertionSortFunction(mainWindow);
                        //bar size 735px x 63px
                        long double temp[3] = {0};
                        for (int i = 0; i < 3; i++){
                            timeComp[i].setString(std::to_string(time[i]));
                            temp[i] = time[i];
                        }
                        std::sort(std::begin(temp), std::end(temp));
                        timeIncrease = (735/(temp[2]*100));
                        largestValue = temp[2]*100;
                    }else{
                        play = false;
                    }
                    action = -1;
                    break;
                    
                case 5:
                    if (size <  50000){
                        size += 5000;
                    }
                    buildArray();
                    reset();
                    sorted = true;
                    shuffled = false;
                    revSort = false;
                    break;

                case 6:
                    if (size >= 10000){
                        size -= 5000;
                    }
                    buildArray();
                    reset();
                    sorted = true;
                    shuffled = false;
                    revSort = false;
                    break;
                default:
                    drawScreen(mainWindow);
                    break;
            }
        }
    }
    
}