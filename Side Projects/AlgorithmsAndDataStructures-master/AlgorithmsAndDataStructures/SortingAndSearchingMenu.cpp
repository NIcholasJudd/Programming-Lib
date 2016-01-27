//
//  SortingAndSearching.cpp
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 16/07/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#include "SortingAndSearchingMenu.h"

/*****************************************************
 
SORTING AND SEARCHING MENU AND ACTION HANDLERS / LISTENERS
 
 *****************************************************/

SortingAndSearchingMenu::SortingAndSearchingMenuResult SortingAndSearchingMenu::Show(sf::RenderWindow& renderWindow){
    renderWindow.clear(sf::Color(sf::Color::Black));
    
    //sf::Texture sorting1ATexture;
    //sorting1ATexture.loadFromFile(resourcePath() + "MMsorting1a.gif");
    //sf::Sprite sorting1ASprite(sorting1ATexture);
    //sorting1ASprite.setPosition(312, 200);
    
    // Load a sprite to use for scrolling background
    sf::Texture texture;
    texture.loadFromFile(resourcePath() + "scrollingBackgroundTile.gif");
    sf::Sprite backgroundSprite(texture);
    
    scrollingBackground myBackground(backgroundSprite,(sf::Vector2f(-0.5, -0.5)));
    
    sf::Time elapsed = GLOBAL_CLOCK.restart();
    myBackground.update(elapsed);
    myBackground.draw(renderWindow);
    
    sf::Texture sorting2ATexture;
    sorting2ATexture.loadFromFile(resourcePath() + "MMsorting2a.gif");
    sf::Sprite sorting2ASprite(sorting2ATexture);
    sorting2ASprite.setPosition(312, 200);
    
    sf::Texture sorting3ATexture;
    sorting3ATexture.loadFromFile(resourcePath() + "MMsorting3a.gif");
    sf::Sprite sorting3ASprite(sorting3ATexture);
    sorting3ASprite.setPosition(312, 300);
    
    sf::Texture backATexture;
    backATexture.loadFromFile(resourcePath() + "MMbackA.gif");
    sf::Sprite backASprite(backATexture);
    backASprite.setPosition(312, 600);
    
    //Begin lesson menu item coordinates
    //SortingAndSearchingMenuItem beginLessonButton;
    //beginLessonButton.rect.top = 200;
    //beginLessonButton.rect.height = 80;
    //beginLessonButton.rect.left = 312;
    //beginLessonButton.rect.width = 400;
    //beginLessonButton.action = BeginLesson;
    
    //Begin demo menu item coordinates
    SortingAndSearchingMenuItem beginDemoButton;
    beginDemoButton.rect.top = 200;
    beginDemoButton.rect.height = 80;
    beginDemoButton.rect.left = 312;
    beginDemoButton.rect.width = 400;
    beginDemoButton.action = BeginDemo;
    
    //Begin demo menu item coordinates
    SortingAndSearchingMenuItem beginComparissonButton;
    beginComparissonButton.rect.top = 300;
    beginComparissonButton.rect.height = 80;
    beginComparissonButton.rect.left = 312;
    beginComparissonButton.rect.width = 400;
    beginComparissonButton.action = BeginComparisson;
    
    //Exit menu item coordinates
    SortingAndSearchingMenuItem backButton;
    backButton.rect.top = 600;
    backButton.rect.height = 80;
    backButton.rect.left = 312;
    backButton.rect.width = 400;
    backButton.action = Back;
    
    //menuItems.push_back(beginLessonButton);
    menuItems.push_back(beginDemoButton);
    menuItems.push_back(beginComparissonButton);
    menuItems.push_back(backButton);
    
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        exit(1);
    }
    
    //renderWindow.draw(sorting1ASprite);
    renderWindow.draw(sorting2ASprite);
    renderWindow.draw(sorting3ASprite);
    renderWindow.draw(backASprite);
    
    renderWindow.display();
    return GetSortingAndSearchingMenuResponse(renderWindow);
}

SortingAndSearchingMenu::SortingAndSearchingMenuResult SortingAndSearchingMenu::HandleClick(int x, int y){
    std::list<SortingAndSearchingMenuItem>::iterator it;
    
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

SortingAndSearchingMenu::SortingAndSearchingMenuResult SortingAndSearchingMenu::GetSortingAndSearchingMenuResponse(sf::RenderWindow& window){
    window.clear();
    sf::Event menuEvent;
    
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        exit(1);
    }
    sf::Text menuText("Sorting", font, 80);
    menuText.setPosition(390, 50);
    menuText.setColor(sf::Color::White);
    
    // Load a sprite to use for scrolling background
    sf::Texture texture;
    texture.loadFromFile(resourcePath() + "scrollingBackgroundTile.gif");
    sf::Sprite backgroundSprite(texture);
    
    scrollingBackground myBackground(backgroundSprite,(sf::Vector2f(-0.5, -0.5)));
    
    sf::Time elapsed = GLOBAL_CLOCK.restart();
    myBackground.update(elapsed);
    
    //sf::Texture sorting1ATexture;
    //sorting1ATexture.loadFromFile(resourcePath() + "MMsorting1a.gif");
    //sf::Sprite sorting1ASprite(sorting1ATexture);
    //sorting1ASprite.setPosition(312, 200);
    
    sf::Texture sorting2ATexture;
    sorting2ATexture.loadFromFile(resourcePath() + "MMsorting2a.gif");
    sf::Sprite sorting2ASprite(sorting2ATexture);
    sorting2ASprite.setPosition(312, 200);
    
    sf::Texture sorting3ATexture;
    sorting3ATexture.loadFromFile(resourcePath() + "MMsorting3a.gif");
    sf::Sprite sorting3ASprite(sorting3ATexture);
    sorting3ASprite.setPosition(312, 300);
    
    sf::Texture backATexture;
    backATexture.loadFromFile(resourcePath() + "MMbackA.gif");
    sf::Sprite backASprite(backATexture);
    backASprite.setPosition(312, 600);
    
    //sf::Texture sorting1BTexture;
    //sorting1BTexture.loadFromFile(resourcePath() + "MMsorting1b.gif");
    //sf::Sprite sorting1BSprite(sorting1BTexture);
    //sorting1BSprite.setPosition(312, 200);
    
    sf::Texture sorting2BTexture;
    sorting2BTexture.loadFromFile(resourcePath() + "MMsorting2b.gif");
    sf::Sprite sorting2BSprite(sorting2BTexture);
    sorting2BSprite.setPosition(312, 200);
    
    sf::Texture sorting3BTexture;
    sorting3BTexture.loadFromFile(resourcePath() + "MMsorting3b.gif");
    sf::Sprite sorting3BSprite(sorting3BTexture);
    sorting3BSprite.setPosition(312, 300);
    
    sf::Texture backBTexture;
    backBTexture.loadFromFile(resourcePath() + "MMbackB.gif");
    sf::Sprite backBSprite(backBTexture);
    backBSprite.setPosition(312, 600);
    
    for(;;){
        
        int draw;
        
        myBackground.update(elapsed);
        myBackground.draw(window);
        window.draw(sorting2ASprite);
        window.draw(sorting3ASprite);
        window.draw(backASprite);
        window.draw(backASprite);
        window.draw(menuText);
        
        while(window.pollEvent(menuEvent)){
            
            sf::Vector2i position = sf::Mouse::getPosition(window);
            sf::Vector2i relativePosition = handleMouseClick(position.x, position.y, window);
            std::list<SortingAndSearchingMenuItem>::iterator it;
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
                window.draw(sorting2BSprite);
                break;
            case 1:
                window.draw(sorting3BSprite);
                break;
            case 2:
                window.draw(backBSprite);
                break;
        }
        window.display();
    }
}

