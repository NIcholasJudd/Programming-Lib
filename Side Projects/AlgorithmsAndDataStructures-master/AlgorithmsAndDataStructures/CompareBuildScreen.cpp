//
//  compareBuildScreen.cpp
//  compare
//
//  Created by Nicholas Judd on 4/09/2015.
//  Copyright (c) 2015 Nicholas Judd. All rights reserved.
//

#include "ResourcePath.hpp"

sf::Texture const comparisonModule::loadTexture(std::string filename){
    sf::Texture texture;
    if(!texture.loadFromFile(resourcePath() + filename)){
        exit(1);
    }
    return texture;
}

// rewrite dosent scale speak to jim for help with the maths of it
void comparisonModule::buildArray() {

    for (int i = 0; i < 3; i++){
        sortList[i].erase(sortList[i].begin(), sortList[i].end());
    }
    for ( int i = 1; i <= size; i++){
        sortList[0].push_back(i);
    }
    for ( int i = 1; i <= size; i++){
        sortList[1].push_back(i);
    }
    for ( int i = 1; i <= size; i++){
        sortList[2].push_back(i);
    }
    
}

void comparisonModule::buildBackground(sf::RenderWindow& mainWindow, comparisonModule sort){
    sf::Vector2f buttonSize = sf::Vector2f((237),(60));
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        exit(1);
    }
    
    elementNum.setString("10");
    elementNum.setFont(font);
    elementNum.setCharacterSize(20);
    elementNum.setColor(sf::Color::White);
    elementNum.setPosition(363, 637);
    
    timeComp[0].setString("0");
    timeComp[0].setFont(font);
    timeComp[0].setCharacterSize(30);
    timeComp[0].setColor(sf::Color::White);
    timeComp[0].setPosition(396,50);
    
    timeComp[1].setString("0");
    timeComp[1].setFont(font);
    timeComp[1].setCharacterSize(30);
    timeComp[1].setColor(sf::Color::White);
    timeComp[1].setPosition(396,240);
    
    timeComp[2].setString("0");
    timeComp[2].setFont(font);
    timeComp[2].setCharacterSize(30);
    timeComp[2].setColor(sf::Color::White);
    timeComp[2].setPosition(396,430);
    
    comparisonsNumber[0].setString("0");
    comparisonsNumber[0].setFont(font);
    comparisonsNumber[0].setCharacterSize(20);
    comparisonsNumber[0].setColor(sf::Color::White);
    comparisonsNumber[0].setPosition(843,148);
    
    comparisonsNumber[1].setString("0");
    comparisonsNumber[1].setFont(font);
    comparisonsNumber[1].setCharacterSize(20);
    comparisonsNumber[1].setColor(sf::Color::White);
    comparisonsNumber[1].setPosition(843,335);
    
    comparisonsNumber[2].setString("0");
    comparisonsNumber[2].setFont(font);
    comparisonsNumber[2].setCharacterSize(20);
    comparisonsNumber[2].setColor(sf::Color::White);
    comparisonsNumber[2].setPosition(843,520);
    
    
    swapsNumber[0].setString("0");
    swapsNumber[0].setFont(font);
    swapsNumber[0].setCharacterSize(20);
    swapsNumber[0].setColor(sf::Color::White);
    swapsNumber[0].setPosition(843,71);
    //29
    swapsNumber[1].setString("0");
    swapsNumber[1].setFont(font);
    swapsNumber[1].setCharacterSize(20);
    swapsNumber[1].setColor(sf::Color::White);
    swapsNumber[1].setPosition(843,260);
    
    swapsNumber[2].setString("0");
    swapsNumber[2].setFont(font);
    swapsNumber[2].setCharacterSize(20);
    swapsNumber[2].setColor(sf::Color::White);
    swapsNumber[2].setPosition(843,455);
 
    //sf::Vector2f size(61, 5);
    for (int i = 0; i < 3; i++){
        sizeGraphTime[i].x = 5;
        sizeGraphTime[i].y = 67;
        timeGraph[i].setSize(sizeGraphTime[i]);
    }
    for (int i = 0; i < 3; i++){
        swaps[i] = 0;
        comparisons[i] = 0;
    }
    timeGraph[0].setPosition(65, 100);
    timeGraph[1].setPosition(65, 290);
    timeGraph[2].setPosition(65, 480);
    
    menuControler.erase(menuControler.begin(), menuControler.end());
    
    menu backController;
    backController.buttonController.height = buttonSize.y;
    backController.buttonController.width = buttonSize.x;
    backController.buttonController.top = 605;
    backController.buttonController.left = 35;
    backController.buttonNumber = 0;
    menuControler.push_back(backController);
    
    menu shuffleController;
    shuffleController.buttonController.height = buttonSize.y;
    shuffleController.buttonController.width = buttonSize.x;
    shuffleController.buttonController.top = 675;
    shuffleController.buttonController.left = 35;
    shuffleController.buttonNumber = 1;
    menuControler.push_back(shuffleController);
    
    menu revShuffelController;
    revShuffelController.buttonController.height = buttonSize.y;
    revShuffelController.buttonController.width = buttonSize.x;
    revShuffelController.buttonController.top = 675;
    revShuffelController.buttonController.left = 530;
    revShuffelController.buttonNumber = 2;
    menuControler.push_back(revShuffelController);
    
    menu sorttedController;
    sorttedController.buttonController.height = buttonSize.y;
    sorttedController.buttonController.width = buttonSize.x;
    sorttedController.buttonController.top = 675;
    sorttedController.buttonController.left = 285;
    sorttedController.buttonNumber = 3;
    menuControler.push_back(sorttedController);
    
    menu playController;
    playController.buttonController.height = buttonSize.y;
    playController.buttonController.width = buttonSize.x;
    playController.buttonController.top = 605;
    playController.buttonController.left = 530;
    playController.buttonNumber = 4;
    menuControler.push_back(playController);
    
    menu plusController;
    plusController.buttonController.height = 60;
    plusController.buttonController.width = 60;
    plusController.buttonController.top = 605;
    plusController.buttonController.left = 460;
    plusController.buttonNumber = 5;
    menuControler.push_back(plusController);
    
    menu minusController;
    minusController.buttonController.height = 60;
    minusController.buttonController.width = 60;
    minusController.buttonController.top = 605;
    minusController.buttonController.left = 283;
    minusController.buttonNumber = 6;
    menuControler.push_back(minusController);
    
}