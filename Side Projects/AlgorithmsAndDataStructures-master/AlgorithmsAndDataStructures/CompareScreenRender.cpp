//
//  sortScreenRender.cpp
//  SortingModule
//
//  Created by Nicholas Judd on 16/08/2015.
//  Copyright (c) 2015 Nicholas Judd. All rights reserved.
//

#include "ResourcePath.hpp"

void comparisonModule::renderScreen(sf::RenderWindow& mainWindow,  sf::Sprite backgroundSprite){
    mainWindow.clear(sf::Color::Black);
    mainWindow.draw(backgroundSprite);
    
    elementNum.setString(std::to_string(size));
    mainWindow.draw(elementNum);

    if (sorted == true){
        sf::Sprite sortMethodSprite;
        sf::Sprite selectedSprite;
        selectedSprite.setTexture(selectedTexture);
        selectedSprite.setPosition(285.f, 675.f);
        sortMethodSprite.setTexture(sorttedTexture);
        sortMethodSprite.setPosition(795, 605);
        mainWindow.draw(selectedSprite);
        mainWindow.draw(sortMethodSprite);
    }else if ( shuffled == true){
        sf::Sprite sortMethodSprite;
        sf::Sprite selectedSprite;
        selectedSprite.setTexture(selectedTexture);
        selectedSprite.setPosition(35.f,675.f);
        sortMethodSprite.setTexture(shuffleTexture);
        sortMethodSprite.setPosition(795, 605);
        mainWindow.draw(sortMethodSprite);
        mainWindow.draw(selectedSprite);
    }else if (revSort == true){
        sf::Sprite sortMethodSprite;
        sf::Sprite selectedSprite;
        selectedSprite.setTexture(selectedTexture);
        selectedSprite.setPosition(530.f,675.f);
        sortMethodSprite.setTexture(revSortTexture);
        sortMethodSprite.setPosition(795, 605);
        mainWindow.draw(sortMethodSprite);
        
        mainWindow.draw(selectedSprite);
    }
    if (!play){
        sf::Sprite playSprite;
        playSprite.setTexture(playTexture);
        playSprite.setPosition(534.f,606.f);
        mainWindow.draw(playSprite);
        for (int i = 0; i < 3; i++){
            mainWindow.draw(timeGraph[i]);
            mainWindow.draw(swapsNumber[i]);
            mainWindow.draw(comparisonsNumber[i]);
            mainWindow.draw(timeComp[i]);
            
        }
        
    }else{
        sf::Sprite pauseSprite;
        pauseSprite.setTexture(pauseTexture);
        pauseSprite.setPosition(534.f,606.f);
        mainWindow.draw(pauseSprite);
        if (count < largestValue){
           for (int i = 0; i < 3; i++){
                if (count < time[i]*100){
                    sizeGraphTime[i].x += timeIncrease;
                    if (sizeGraphTime[i].x > 735){
                        sizeGraphTime[i].x = 735;
                    }
                    timeGraph[i].setSize(sizeGraphTime[i]);
                }
            }
        }else{
            play = false;
        }
        for (int i = 0; i < 3; i++){
            mainWindow.draw(timeGraph[i]);
            swapsNumber[i].setString(std::to_string(swaps[i]));
            comparisonsNumber[i].setString(std::to_string(comparisons[i]));
            mainWindow.draw(swapsNumber[i]);
            mainWindow.draw(comparisonsNumber[i]);
            mainWindow.draw(timeComp[i]);
            
        }
    }
    count++;;
    mainWindow.display();
}


void comparisonModule::drawScreen(sf::RenderWindow& mainWindow){
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    renderScreen(mainWindow, backgroundSprite);
}

int comparisonModule::HandleClick(int x, int y){
    std::list<menu>::iterator it;
    for ( it = menuControler.begin(); it != menuControler.end(); it++){
        if( x > (*it).buttonController.left
           && x < (*it).buttonController.left + (*it).buttonController.width
           && y > (*it).buttonController.top
           && y < (*it).buttonController.height + (*it).buttonController.top){
            return (*it).buttonNumber;
        }
    }
    return -1;
}