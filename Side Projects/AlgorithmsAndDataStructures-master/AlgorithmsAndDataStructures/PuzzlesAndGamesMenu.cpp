//
//  PuzzlesAndGamesMenu.cpp
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 16/07/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#include "PuzzlesAndGamesMenu.h"

/*****************************************************
 
 PUZZLES AND GAMES MENU AND ACTION HANDLERS / LISTENERS
 
 *****************************************************/

PuzzlesAndGamesMenu::PuzzlesAndGamesMenuResult PuzzlesAndGamesMenu::Show(sf::RenderWindow& renderWindow){
    renderWindow.clear(sf::Color(sf::Color::Black));
    
    // Load a sprite to use for scrolling background
    sf::Texture texture;
    texture.loadFromFile(resourcePath() + "scrollingBackgroundTile.gif");
    sf::Sprite backgroundSprite(texture);
    
    scrollingBackground myBackground(backgroundSprite,(sf::Vector2f(-0.5, -0.5)));
    
    sf::Time elapsed = GLOBAL_CLOCK.restart();
    myBackground.update(elapsed);
    myBackground.draw(renderWindow);
    
    sf::Texture puzzles1ATexture;
    puzzles1ATexture.loadFromFile(resourcePath() + "MMpuzzles1A.gif");
    sf::Sprite puzzles1ASprite(puzzles1ATexture);
    puzzles1ASprite.setPosition(312, 200);
    
    sf::Texture puzzles2ATexture;
    puzzles2ATexture.loadFromFile(resourcePath() + "MMpuzzles2a.gif");
    sf::Sprite puzzles2ASprite(puzzles2ATexture);
    puzzles2ASprite.setPosition(312, 300);
    
    sf::Texture backATexture;
    backATexture.loadFromFile(resourcePath() + "MMbackA.gif");
    sf::Sprite backASprite(backATexture);
    backASprite.setPosition(312, 600);
    
    //Begin menu item coordinates
    PuzzlesAndGamesMenuItem beginButton;
    beginButton.rect.top= 200;
    beginButton.rect.height = 80;
    beginButton.rect.left = 312;
    beginButton.rect.width = 400;
    beginButton.action = BeginConways;
    
    //Begin boat menu item coordinates
    PuzzlesAndGamesMenuItem beginBoatButton;
    beginBoatButton.rect.top= 300;
    beginBoatButton.rect.height = 80;
    beginBoatButton.rect.left = 312;
    beginBoatButton.rect.width = 400;
    beginBoatButton.action = BeginRiverCrossing;
    
    //Exit menu item coordinates
    PuzzlesAndGamesMenuItem backButton;
    backButton.rect.top = 600;
    backButton.rect.height = 80;
    backButton.rect.left = 312;
    backButton.rect.width = 400;
    backButton.action = Back;
    
    menuItems.push_back(beginButton);
    menuItems.push_back(beginBoatButton);
    menuItems.push_back(backButton);
    
    renderWindow.draw(puzzles1ASprite);
    renderWindow.draw(puzzles2ASprite);
    renderWindow.draw(backASprite);
    //renderWindow.draw(menuText);
    
    renderWindow.display();
    return GetPuzzlesAndGamesMenuResponse(renderWindow);
}

PuzzlesAndGamesMenu::PuzzlesAndGamesMenuResult PuzzlesAndGamesMenu::HandleClick(int x, int y){
    std::list<PuzzlesAndGamesMenuItem>::iterator it;
    
    for ( it = menuItems.begin(); it != menuItems.end(); it++){
        sf::Rect<int> menuItemRect = (*it).rect;
        if( x > menuItemRect.left
           && x < menuItemRect.left + menuItemRect.width
           && y > menuItemRect.top
           && y < menuItemRect.height + menuItemRect.top){
            return (*it).action;
        }
    }
    return Nothing;
}

PuzzlesAndGamesMenu::PuzzlesAndGamesMenuResult PuzzlesAndGamesMenu::GetPuzzlesAndGamesMenuResponse(sf::RenderWindow& window){
    window.clear();
    sf::Event menuEvent;
    
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        exit(1);
    }
    sf::Text menuText("Puzzles and Games", font, 80);
    menuText.setPosition(160, 50);
    menuText.setColor(sf::Color::White);

    
    // Load a sprite to use for scrolling background
    sf::Texture texture;
    texture.loadFromFile(resourcePath() + "scrollingBackgroundTile.gif");
    sf::Sprite backgroundSprite(texture);
    
    scrollingBackground myBackground(backgroundSprite,(sf::Vector2f(-0.5, -0.5)));
    
    sf::Time elapsed = GLOBAL_CLOCK.restart();
    myBackground.update(elapsed);
    myBackground.draw(window);
    
    sf::Texture puzzles1ATexture;
    puzzles1ATexture.loadFromFile(resourcePath() + "MMpuzzles1A.gif");
    sf::Sprite puzzles1ASprite(puzzles1ATexture);
    puzzles1ASprite.setPosition(312, 200);
    
    sf::Texture puzzles2ATexture;
    puzzles2ATexture.loadFromFile(resourcePath() + "MMpuzzles2a.gif");
    sf::Sprite puzzles2ASprite(puzzles2ATexture);
    puzzles2ASprite.setPosition(312, 300);
    
    sf::Texture backATexture;
    backATexture.loadFromFile(resourcePath() + "MMbackA.gif");
    sf::Sprite backASprite(backATexture);
    backASprite.setPosition(312, 600);
    
    sf::Texture puzzles1BTexture;
    puzzles1BTexture.loadFromFile(resourcePath() + "MMpuzzles1b.gif");
    sf::Sprite puzzles1BSprite(puzzles1BTexture);
    puzzles1BSprite.setPosition(312, 200);
    
    sf::Texture puzzles2BTexture;
    puzzles2BTexture.loadFromFile(resourcePath() + "MMpuzzles2b.gif");
    sf::Sprite puzzles2BSprite(puzzles2BTexture);
    puzzles2BSprite.setPosition(312, 300);
    
    sf::Texture backBTexture;
    backBTexture.loadFromFile(resourcePath() + "MMbackB.gif");
    sf::Sprite backBSprite(backBTexture);
    backBSprite.setPosition(312, 600);
    
    for(;;){
        
        int draw;
        
        myBackground.update(elapsed);
        myBackground.draw(window);
        window.draw(puzzles1ASprite);
        window.draw(puzzles2ASprite);
        window.draw(backASprite);
        window.draw(menuText);
        
        while(window.pollEvent(menuEvent)){
            
            sf::Vector2i position = sf::Mouse::getPosition(window);
            sf::Vector2i relativePosition = handleMouseClick(position.x, position.y, window);
            std::list<PuzzlesAndGamesMenuItem>::iterator it;
            if(menuEvent.type == sf::Event::MouseButtonPressed){
                sf::Vector2i click = handleMouseClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y, window);
                return HandleClick(click.x, click.y);
            }
            if(menuEvent.type == sf::Event::KeyPressed){
                if(menuEvent.key.code == sf::Keyboard::Q){
                    return Back;
                }
            }
            for ( it = menuItems.begin(); it != menuItems.end(); it++){
                int x = relativePosition.x, y = relativePosition.y;
                sf::Rect<int> menuItemRect = (*it).rect;
                if( x > menuItemRect.left
                   && x < menuItemRect.left + menuItemRect.width
                   && y > menuItemRect.top
                   && y < menuItemRect.height + menuItemRect.top){
                    if(std::distance(menuItems.begin(), it) == 0){
                        draw = 0;
                    }
                    if(std::distance(menuItems.begin(), it) == 1){
                        draw = 1;
                    }
                    if(std::distance(menuItems.begin(), it) == 2){
                        draw = 2;
                    }
                }
            }
        }
        switch(draw){
            case 0:
                window.draw(puzzles1BSprite);
                break;
            case 1:
                window.draw(puzzles2BSprite);
                break;
            case 2:
                window.draw(backBSprite);
                break;
        }
        window.display();
    }
}

