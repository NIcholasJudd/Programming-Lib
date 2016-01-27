//
//  SpalshScreen.cpp
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 7/06/2014.
//  Copyright (c) 2014 _BENJAMIN. All rights reserved.
//

#include "ResourcePath.hpp"

void SplashScreen::Show(sf::RenderWindow &renderWindow){

    renderWindow.clear(sf::Color(0,0,0));
    
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        exit(1);
    }
    sf::Text SplashText("This is the Splash Screen", font, 50);
    SplashText.setPosition(220, 50);

    sf::Text PeterText("Peter Mavridis", font, 30);
    PeterText.setPosition(500, 200);
    
    sf::Text BenText("Benjamin  Waters", font, 30);
    BenText.setPosition(500, 240);
    
    sf::Text NickText("Nicholas Judd", font, 30);
    NickText.setPosition(500, 280);
    
    sf::Text JimText("Jim Gollop", font, 30);
    JimText.setPosition(500, 320);
    
    renderWindow.draw(SplashText);
    renderWindow.draw(PeterText);
    renderWindow.draw(BenText);
    renderWindow.draw(NickText);
    renderWindow.draw(JimText);

    renderWindow.display();
    sf::Event event;
    while(renderWindow.isOpen()){
        while(renderWindow.pollEvent(event)){
            if( event.type == sf::Event::EventType::KeyPressed ||
                event.type == sf::Event::EventType::MouseButtonPressed ||
                event.type == sf::Event::EventType::Closed ){
                return;
            }
        }
        return;
    }
}
