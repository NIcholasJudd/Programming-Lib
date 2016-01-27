//
//  sortScreenRender.cpp
//  SortingModule
//
//  Created by Nicholas Judd on 16/08/2015.
//  Copyright (c) 2015 Nicholas Judd. All rights reserved.
//

#include "ResourcePath.hpp"

void sortingModule::setCompAndSwapValue(){
    if (comparisons < 99){
        comparisonsNumber.setCharacterSize(80);
        comparisonsNumber.setPosition(885, 450);
    }else if (comparisons > 99 && comparisons < 999){
        comparisonsNumber.setPosition(845, 450);
    }else if (comparisons > 999){
        comparisonsNumber.setPosition(835, 460);
        comparisonsNumber.setCharacterSize(67);
    }
    if (swaps < 99){
        swapsNumber.setCharacterSize(80);
        swapsNumber.setPosition(885, 633);
    }else if (swaps > 99 && swaps < 999){
        swapsNumber.setPosition(845, 633);
    }else if (swaps > 999){
        swapsNumber.setPosition(835, 643);
        swapsNumber.setCharacterSize(67);
    }
}
void sortingModule::animateBubble(sf::RenderWindow& mainWindow, sf::Sprite backgroundSprite){
    mainWindow.clear(sf::Color::Black);
    std::list<animation>::iterator it;
    it = animate.begin();
    if ((*it).action == 1){
        comparisons++;
        comparisonsNumber.setString(std::to_string(comparisons));
        swapsNumber.setString(std::to_string(swaps));
        for (int i = 0; i < size-correct; i++){
            sortList[i].rect.setFillColor(sf::Color::White);
        }
        sortList[(*it).element1].rect.setFillColor(sf::Color::Yellow);
        sortList[(*it).element2].rect.setFillColor(sf::Color::Red);
        highlightLine.setPosition(320, 532);
        sf::sleep(sf::milliseconds(120));
        renderScreen(mainWindow, backgroundSprite);
        sf::sleep(sf::seconds(0.3));
    }else if ((*it).action == 2){
        swaps++;
        comparisonsNumber.setString(std::to_string(comparisons));
        swapsNumber.setString(std::to_string(swaps));
        std::swap(sortList[(*it).element1].heightValue, sortList[(*it).element2].heightValue);
        std::swap(sortList[(*it).element1].rect, sortList[(*it).element2].rect);
        highlightLine.setPosition(320, 585);
        sf::sleep(sf::milliseconds(120));
        renderScreen(mainWindow, backgroundSprite);
        sf::Vector2f one = sortList[(*it).element1].rect.getPosition();
        sf::Vector2f two = sortList[(*it).element2].rect.getPosition();
        double moveSize = one.x - two.x;
        for (int i = 0; i < speed;i++){
            sortList[(*it).element1].rect.move(-(moveSize/speed), 0);
            sortList[(*it).element2].rect.move((moveSize/speed), 0);
            renderScreen(mainWindow, backgroundSprite);
        }
    }else if((*it).action == 3){
        correct++;
        for (int i = 0; i < size; i++){
            if (i < (size - correct)){
                sortList[i].rect.setFillColor(sf::Color::White);
            }else
                sortList[i].rect.setFillColor(sf::Color::Green);
        }
    }else if((*it).action == 4){
        for (int i = 0; i < size; i++){
            sortList[i].rect.setFillColor(sf::Color::Green);
        }
        correct = 0;
        play=false;
    }else if ((*it).action == 5){
        highlightLine.setPosition(320, 429);
        renderScreen(mainWindow, backgroundSprite);
        sf::sleep(sf::milliseconds(120));
        
    }else if ((*it).action == 6){
        highlightLine.setPosition(320, 482);
        sf::sleep(sf::milliseconds(120));
    }
    animate.pop_front();
}


//Selection sort animation list
//1. compare elements
//2. swap elements
//3. array sorted
//4. loop 1
//5. loop 2
//6. set min element 1
//7. set min element 2
void sortingModule::animateSelection(sf::RenderWindow& mainWindow, sf::Sprite backgroundSprite){
    mainWindow.clear(sf::Color(224, 224, 224, 255));
    std::list<animation>::iterator it;
    it = animate.begin();
    if ((*it).action == 1){
        comparisons++;
        comparisonsNumber.setString(std::to_string(comparisons));
        swapsNumber.setString(std::to_string(swaps));
        for (int i = correct; i < size; i++){
            sortList[i].rect.setFillColor(sf::Color::White);
        }
        for (int i = 0; i < correct; i++){
            sortList[i].rect.setFillColor(sf::Color::Green);
        }
        sortList[correct].rect.setFillColor(sf::Color::Red);
        sortList[(*it).element1].rect.setFillColor(sf::Color::Yellow);
        sortList[(*it).element2].rect.setFillColor(sf::Color::Yellow);
        highlightLine.setPosition(320, 550);
        renderScreen(mainWindow, backgroundSprite);
        sf::sleep(sf::milliseconds(120));
        renderScreen(mainWindow, backgroundSprite);
        sf::sleep(sf::seconds(0.3));
    }else if ((*it).action == 2){
        swaps++;
        correct++;
        comparisonsNumber.setString(std::to_string(comparisons));
        swapsNumber.setString(std::to_string(swaps));
        std::swap(sortList[(*it).element1].heightValue, sortList[(*it).element2].heightValue);
        std::swap(sortList[(*it).element1].rect, sortList[(*it).element2].rect);
        highlightLine.setPosition(320, 630);
        renderScreen(mainWindow, backgroundSprite);
        sf::sleep(sf::milliseconds(120));
        renderScreen(mainWindow, backgroundSprite);
        sf::Vector2f one = sortList[(*it).element1].rect.getPosition();
        sf::Vector2f two = sortList[(*it).element2].rect.getPosition();
        double moveSize = one.x - two.x;
        for (int i = 0; i < speed;i++){
            sortList[(*it).element1].rect.move(-(moveSize/speed), 0);
            sortList[(*it).element2].rect.move((moveSize/speed), 0);
            renderScreen(mainWindow, backgroundSprite);
        }
        sortList[(*it).element2].rect.setFillColor(sf::Color::Green);
        sortList[(*it).element1].rect.setFillColor(sf::Color::White);
    }else if((*it).action == 3){
        highlightLine.setPosition(320, 429);
        renderScreen(mainWindow, backgroundSprite);
        sf::sleep(sf::milliseconds(120));
        for (int i = 0; i < size; i++){
            sortList[i].rect.setFillColor(sf::Color::Green);
        }
        correct=0;
        play=false;
    }else if((*it).action == 4){
        highlightLine.setPosition(320, 429);
        renderScreen(mainWindow, backgroundSprite);
        sf::sleep(sf::milliseconds(120));
    }else if ((*it).action == 5){
        highlightLine.setPosition(320, 510);
        renderScreen(mainWindow, backgroundSprite);
        sf::sleep(sf::milliseconds(120));
    }else if ((*it).action == 6){
        highlightLine.setPosition(320, 470);
        renderScreen(mainWindow, backgroundSprite);
        sf::sleep(sf::milliseconds(120));
    }else if ((*it).action == 7){
        highlightLine.setPosition(320, 590);
        renderScreen(mainWindow, backgroundSprite);
        sf::sleep(sf::milliseconds(120));
    }
    
    
    animate.pop_front();
}

void sortingModule::animateInsertion(sf::RenderWindow& mainWindow, sf::Sprite backgroundSprite){
    mainWindow.clear(sf::Color(224, 224, 224, 255));
    std::list<animation>::iterator it;
    it = animate.begin();
    if ((*it).action == 1){
        comparisons++;
        comparisonsNumber.setString(std::to_string(comparisons));
        swapsNumber.setString(std::to_string(swaps));
        for (int i = 0; i < size; i++){
            sortList[i].rect.setFillColor(sf::Color::White);
        }
        for (int i = 0; i < correct; i++){
            sortList[i].rect.setFillColor(sf::Color::Green);
        }
        sortList[(*it).element1].rect.setFillColor(sf::Color::Red);
        sortList[(*it).element2].rect.setFillColor(sf::Color::Yellow);
        renderScreen(mainWindow, backgroundSprite);
        sf::sleep(sf::seconds(0.3));
    }else if ((*it).action == 2){
        swaps++;
        comparisonsNumber.setString(std::to_string(comparisons));
        swapsNumber.setString(std::to_string(swaps));
        std::swap(sortList[(*it).element1].heightValue, sortList[(*it).element2].heightValue);
        std::swap(sortList[(*it).element1].rect, sortList[(*it).element2].rect);
        highlightLine.setPosition(320, 560);
        renderScreen(mainWindow, backgroundSprite);
        sf::sleep(sf::milliseconds(120));
        renderScreen(mainWindow, backgroundSprite);
        sf::Vector2f one = sortList[(*it).element1].rect.getPosition();
        sf::Vector2f two = sortList[(*it).element2].rect.getPosition();
        double moveSize = one.x - two.x;
        for (int i = 0; i < speed;i++){
            sortList[(*it).element1].rect.move(-(moveSize/speed), 0);
            sortList[(*it).element2].rect.move((moveSize/speed), 0);
            renderScreen(mainWindow, backgroundSprite);
        }
        sortList[(*it).element1].rect.setFillColor(sf::Color::Green);
    }else if((*it).action == 3){
        highlightLine.setPosition(320, 460);
        renderScreen(mainWindow, backgroundSprite);
        sf::sleep(sf::milliseconds(120));
        highlightLine.setPosition(320, 501);
        renderScreen(mainWindow, backgroundSprite);
        sf::sleep(sf::milliseconds(120));
    }else if((*it).action == 4){
        correct=0;
        for (int i = 0; i < size; i++){
            sortList[i].rect.setFillColor(sf::Color::Green);
        }
        play=false;
    }else if((*it).action == 5){
        highlightLine.setPosition(320, 429);
        renderScreen(mainWindow, backgroundSprite);
        sf::sleep(sf::milliseconds(120));
    }else if((*it).action == 6){
        highlightLine.setPosition(320, 528);
        renderScreen(mainWindow, backgroundSprite);
        sf::sleep(sf::milliseconds(120));
    }
    animate.pop_front();
}

//678,550
void sortingModule::renderScreen(sf::RenderWindow& mainWindow,  sf::Sprite backgroundSprite){
    mainWindow.clear(sf::Color::Black);
    sf::Sprite helpSprite;
    helpSprite.setTexture(helpTexture);
    sf::Sprite lessonSprite;
    lessonSprite.setTexture(lessonTexture);
    comparisonsNumber.setString(std::to_string(comparisons));
    swapsNumber.setString(std::to_string(swaps));
    elementNumber.setString(std::to_string(size));
    mainWindow.draw(backgroundSprite);
    if (!play){
        sf::Sprite playSprite;
        playSprite.setTexture(playTexture);
        playSprite.setPosition(552.f,680.f);
        mainWindow.draw(playSprite);
    }else{
        sf::Sprite pauseSprite;
        pauseSprite.setTexture(pauseTexture);
        pauseSprite.setPosition(552.f,680.f);
        mainWindow.draw(pauseSprite);
    }
    mainWindow.draw(comparisonsNumber);
    mainWindow.draw(swapsNumber);
    mainWindow.draw(elementNumber);
    mainWindow.draw(highlightLine);
    for (int i = 0; i < size; i++){
        mainWindow.draw(sortList[i].rect);
    }
    drawPsudeo(mainWindow);
    if (help == true){
        sf::Sprite helpOverlaySprite;
            helpOverlaySprite.setTexture(helpOverlayTexture);
            mainWindow.draw(helpOverlaySprite);
    }
    helpSprite.setPosition(1000.f, 0.f);
    mainWindow.draw(helpSprite);
    mainWindow.draw(lessonSprite);
    mainWindow.draw(buttonSprite);
    mainWindow.display();
}

void sortingModule::drawPsudeo(sf::RenderWindow& mainWindow){
    double width = 320;
    double height = 429;
    double psudeoBoxHeight = 254;
    if (bubble == true){
        fontSize = 32;
        sf::Vector2f highlightSize(471.f, 40.f);
        highlightLine.setSize(highlightSize);
        for (int i = 0; i < psudeoCode.size(); i++){
            sf::Text tempCommand(psudeoCode[i], font, fontSize);
            tempCommand.setPosition(width, height);
            tempCommand.setColor(sf::Color::Yellow);
            tempCommand.setStyle(sf::Text::Bold);
            i++;
            stringLength1 = tempCommand.getLocalBounds();
            sf::Text temp(psudeoCode[i], font, fontSize);
            temp.setPosition((width+stringLength1.width), height);
            temp.setColor(sf::Color::White);
            stringLength2 = temp.getLocalBounds();
            mainWindow.draw(temp);
            mainWindow.draw(tempCommand);
            height += stringLength2.height + ((psudeoBoxHeight/stringLength2.height)*2.5);
            width += stringLength1.width;
        }
    }else if (selection == true){
        fontSize = 30;
        sf::Vector2f highlightSize(471.f, 35.f);
        highlightLine.setSize(highlightSize);
        int check = (unsigned int)psudeoCode.size();
        for (int i = 0; i < psudeoCode.size(); i++){
            sf::Text tempCommand(psudeoCode[i], font, fontSize);
            tempCommand.setPosition(width, height);
            tempCommand.setColor(sf::Color::Yellow);
            tempCommand.setStyle(sf::Text::Bold);
            i++;
            stringLength1 = tempCommand.getLocalBounds();
            sf::Text temp(psudeoCode[i], font, fontSize);
            temp.setColor(sf::Color::White);
            temp.setPosition((width+stringLength1.width), height);
            stringLength2 = temp.getLocalBounds();
            mainWindow.draw(temp);
            mainWindow.draw(tempCommand);
            if (i+3 == check){
                width -= 80;
                height += stringLength2.height + ((psudeoBoxHeight/stringLength2.height)*1.5);
            }else {
                height += stringLength2.height + ((psudeoBoxHeight/stringLength2.height)*1.5);
                width += stringLength1.width;
            }
        }
    }else if (insertion == true){
        fontSize = 26;
        sf::Vector2f highlightSize(471.f, 30.f);
        highlightLine.setSize(highlightSize);
        for (int i = 0; i < psudeoCode.size(); i++){
            sf::Text tempCommand(psudeoCode[i], font, fontSize);
            tempCommand.setPosition(width, height);
            tempCommand.setColor(sf::Color::Yellow);
            tempCommand.setStyle(sf::Text::Bold);
            i++;
            stringLength1 = tempCommand.getLocalBounds();
            sf::Text temp(psudeoCode[i], font, fontSize);
            temp.setPosition((width+stringLength1.width), height);
            temp.setColor(sf::Color::White);
            stringLength2 = temp.getLocalBounds();
            mainWindow.draw(temp);
            mainWindow.draw(tempCommand);
            height += stringLength2.height + ((psudeoBoxHeight/stringLength2.height));
            width += stringLength1.width;
        }
    }
}

void sortingModule::drawScreen(sf::RenderWindow& mainWindow){
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    setCompAndSwapValue();
    
    if (animate.size() > 0) {
        if (play == true){
            if (bubble == true){
                animateBubble(mainWindow, backgroundSprite);
            }else if (selection == true){
                animateSelection(mainWindow, backgroundSprite);
            }else if (insertion == true){
                animateInsertion(mainWindow, backgroundSprite);
            }
        }else if (step == true){
            if (bubble == true){
                animateBubble(mainWindow, backgroundSprite);
            }else if (selection == true){
                animateSelection(mainWindow, backgroundSprite);
            }else if (insertion == true){
                animateInsertion(mainWindow, backgroundSprite);
            }
            step = false;
        }
        renderScreen(mainWindow, backgroundSprite);
    }else {
        renderScreen(mainWindow, backgroundSprite);
    }
}

int sortingModule::HandleClick(int x, int y){
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