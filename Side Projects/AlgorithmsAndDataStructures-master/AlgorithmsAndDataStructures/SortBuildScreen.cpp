//
//  sortBuildScreen.cpp
//  SortingModule
//
//  Created by Nicholas Judd on 16/08/2015.
//  Copyright (c) 2015 Nicholas Judd. All rights reserved.
//

#include "ResourcePath.hpp"

sf::Texture const sortingModule::loadTexture(std::string filename)
{
    sf::Texture texture;
    if(!texture.loadFromFile(resourcePath() + filename)){
        exit(1);
    }
    return texture;
}

// rewrite dosent scale speak to jim for help with the maths of it
void sortingModule::buildArray() {
    double height = windowSize.y;
    double positionX = 20;
    double positionY = height * (380 / height);
    double rectWidth = (((1024 - (positionX*2))-2*size) / size);
    double rectHeight = (positionY - positionX) / size;
    double heightIncrease = (positionY - positionX) / size;
    
    sortList.erase(sortList.begin(), sortList.end());
    for ( int i = 1; i <= size; i++){
        sortArray rectangle;
        rectangle.rect.setSize(sf::Vector2f(rectWidth, (rectHeight*-1)));
        rectangle.heightValue = i;
        rectangle.rect.setPosition(positionX, positionY);
        rectangle.rect.setFillColor(sf::Color::White);
        rectangle.rect.setOutlineThickness(2);
        rectangle.rect.setOutlineColor(sf::Color::Black);
        positionX += rectWidth + 2;
        rectHeight+=heightIncrease;
        sortList.push_back(rectangle);
    }
}

void sortingModule::buildPsuedo(int action){
    psudeoCode.erase(psudeoCode.begin(),psudeoCode.end());
    std::string forString = "FOR ";
    std::string ifString = "IF ";
    std::string whileString = "WHILE ";
    std::string swapString = "SWAP ";
    std::string empty;
    if (action == 1){                                                           //Bubble Sort Algorithim
        std::string lineOne = "i from 1 to N";
        std::string lineTwo = "j from 0 to N - i";
        std::string lineThree = "a[j] > a[j + 1]";
        std::string lineFour = "( a[j], a[j + 1] )";
        psudeoCode.push_back(forString);
        psudeoCode.push_back(lineOne);
        psudeoCode.push_back(forString);
        psudeoCode.push_back(lineTwo);
        psudeoCode.push_back(ifString);
        psudeoCode.push_back(lineThree);
        psudeoCode.push_back(swapString);
        psudeoCode.push_back(lineFour);
    }else if (action == 3){                                                     //Selection Sort Algorithim
        std::string lineOne = "i from 1 to N -1";
        std::string lineTwo = "min = i";
        std::string lineThree = "j from i+1 to N";
        std::string lineFour = "a[j] < a[min]";
        std::string lineFive = "min = j";
        std::string lineSix = "( a[i], a[min] )";
        psudeoCode.push_back(forString);
        psudeoCode.push_back(lineOne);
        psudeoCode.push_back(empty);
        psudeoCode.push_back(lineTwo);
        psudeoCode.push_back(forString);
        psudeoCode.push_back(lineThree);
        psudeoCode.push_back(ifString);
        psudeoCode.push_back(lineFour);
        psudeoCode.push_back(empty);
        psudeoCode.push_back(lineFive);
        psudeoCode.push_back(swapString);
        psudeoCode.push_back(lineSix);
    }else if (action == 5){ //Insertion Sort Algorithim
        std::string lineOne = "i from 1 to N";
        std::string lineTwo = "index = a[i]";
        std::string lineThree = " j = i";
        std::string lineFour = "((j > 0) AND (a[j-1]>index))";
        std::string lineFive = "( a[j], a[j-1])";
        psudeoCode.push_back(forString);
        psudeoCode.push_back(lineOne);
        psudeoCode.push_back(empty);
        psudeoCode.push_back(lineTwo);
        psudeoCode.push_back(empty);
        psudeoCode.push_back(lineThree);
        psudeoCode.push_back(whileString);
        psudeoCode.push_back(lineFour);
        psudeoCode.push_back(swapString);
        psudeoCode.push_back(lineFive);    }
}

void sortingModule::buildBackground(sf::RenderWindow& mainWindow, sortingModule sort){
    int width = windowSize.x;
    int height = windowSize.y;
    sf::Vector2f buttonSize = sf::Vector2f((130),(60));
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        exit(1);
    }
    comparisonsNumber.setString("0");
    comparisonsNumber.setFont(font);
    comparisonsNumber.setCharacterSize(80);
    comparisonsNumber.setColor(sf::Color::White);
    comparisonsNumber.setPosition((width * 0.815429687), (height * 0.5859375));
    
    elementNumber.setString(std::to_string(size));
    elementNumber.setFont(font);
    elementNumber.setCharacterSize(20);
    elementNumber.setColor(sf::Color::White);
    elementNumber.setPosition((142), (645));
    
    swapsNumber.setString("0");
    swapsNumber.setFont(font);
    swapsNumber.setCharacterSize(80);
    swapsNumber.setColor(sf::Color::White);
    swapsNumber.setPosition((width * 0.864257812), (height * 0.82421875));
    
    menuControler.erase(menuControler.begin(), menuControler.end());
    
    highlightLine.setPosition(320, 429);
    highlightLine.setFillColor(sf::Color(100, 250, 50,(sf::Uint8)5000));
    
    menu shuffleController;
    shuffleController.buttonController.height = buttonSize.y;
    shuffleController.buttonController.width = buttonSize.x;
    shuffleController.buttonController.top = 405;
    shuffleController.buttonController.left = 20;
    shuffleController.buttonNumber = 0;
    menuControler.push_back(shuffleController);
    
    menu bubbleController;
    bubbleController.buttonController.height = buttonSize.y;
    bubbleController.buttonController.width = buttonSize.x;
    bubbleController.buttonController.top = 405;
    bubbleController.buttonController.left = 155;
    bubbleController.buttonNumber = 1;
    menuControler.push_back(bubbleController);
    
    menu revShuffelController;
    revShuffelController.buttonController.height = buttonSize.y;
    revShuffelController.buttonController.width = buttonSize.x;
    revShuffelController.buttonController.top = 470;
    revShuffelController.buttonController.left = 20;
    revShuffelController.buttonNumber = 2;
    menuControler.push_back(revShuffelController);
    
    menu selectionController;
    selectionController.buttonController.height = buttonSize.y;
    selectionController.buttonController.width = buttonSize.x;
    selectionController.buttonController.top = 470;
    selectionController.buttonController.left = 155;
    selectionController.buttonNumber = 3;
    menuControler.push_back(selectionController);
    
    menu sorttedController;
    sorttedController.buttonController.height = buttonSize.y;
    sorttedController.buttonController.width = buttonSize.x;
    sorttedController.buttonController.top = 540;
    sorttedController.buttonController.left = 20;
    sorttedController.buttonNumber = 4;
    menuControler.push_back(sorttedController);
    
    menu insertionController;
    insertionController.buttonController.height = buttonSize.y;
    insertionController.buttonController.width = buttonSize.x;
    insertionController.buttonController.top = 537;
    insertionController.buttonController.left = 155;
    insertionController.buttonNumber = 5;
    menuControler.push_back(insertionController);
    
    menu minusElementController;
    minusElementController.buttonController.height = buttonSize.y;
    minusElementController.buttonController.width = 78;
    minusElementController.buttonController.top = 615;
    minusElementController.buttonController.left = 31;
    minusElementController.buttonNumber = 6;
    menuControler.push_back(minusElementController);
    
    menu plusElementController;
    plusElementController.buttonController.height = buttonSize.y;
    plusElementController.buttonController.width = 78;
    plusElementController.buttonController.top = 615;
    plusElementController.buttonController.left = 214;
    plusElementController.buttonNumber = 7;
    menuControler.push_back(plusElementController);
    
    menu backController;
    backController.buttonController.height = buttonSize.y;
    backController.buttonController.width = 263;
    backController.buttonController.top = 690;
    backController.buttonController.left = 20;
    backController.buttonNumber = 8;
    menuControler.push_back(backController);
    
    menu stepController;
    stepController.buttonController.height = buttonSize.y;
    stepController.buttonController.width = 162;
    stepController.buttonController.top = 678;
    stepController.buttonController.left = 387;
    stepController.buttonNumber = 9;
    menuControler.push_back(stepController);
    
    menu playController;
    playController.buttonController.height = buttonSize.y;
    playController.buttonController.width = 161;
    playController.buttonController.top = 678;
    playController.buttonController.left = 550;
    playController.buttonNumber = 10;
    menuControler.push_back(playController);
    
    menu helpController;
    helpController.buttonController.height = 25;
    helpController.buttonController.width = 25;
    helpController.buttonController.top = 5;
    helpController.buttonController.left = 1000;
    helpController.buttonNumber = 11;
    menuControler.push_back(helpController);
    
    menu lessonController;
    lessonController.buttonController.height = 25;
    lessonController.buttonController.width = 25;
    lessonController.buttonController.top = 5;
    lessonController.buttonController.left = 5;
    lessonController.buttonNumber = 12;
    menuControler.push_back(lessonController);
    
}