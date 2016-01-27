//
//  TreesAndStructuresMenu.cpp
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 31/01/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#include "TreesAndStructuresMenu.h"

/*****************************************************
 
 TREES AND STRUCTURES MENU AND ACTION HANDLERS / LISTENERS
 
*****************************************************/

TreesAndStructuresMenu::TreesAndStructuresMenuResult TreesAndStructuresMenu::Show(sf::RenderWindow& renderWindow){
    renderWindow.clear(sf::Color(sf::Color::Black));
    
    // Load a sprite to use for scrolling background
    sf::Texture texture;
    texture.loadFromFile(resourcePath() + "scrollingBackgroundTile.gif");
    sf::Sprite backgroundSprite(texture);
    
    scrollingBackground myBackground(backgroundSprite,(sf::Vector2f(-0.5, -0.5)));
    
    sf::Time elapsed = GLOBAL_CLOCK.restart();
    myBackground.update(elapsed);
    myBackground.draw(renderWindow);
    
    sf::Texture structures2ATexture;
    structures2ATexture.loadFromFile(resourcePath() + "MMstructures2a.gif");
    sf::Sprite structures2ASprite(structures2ATexture);
    structures2ASprite.setPosition(312, 200);
    
    sf::Texture structures3ATexture;
    structures3ATexture.loadFromFile(resourcePath() + "MMstructures3a.gif");
    sf::Sprite structures3ASprite(structures3ATexture);
    structures3ASprite.setPosition(312, 300);
    
    sf::Texture backATexture;
    backATexture.loadFromFile(resourcePath() + "MMbackA.gif");
    sf::Sprite backASprite(backATexture);
    backASprite.setPosition(312, 600);
    
    //Begin menu item coordinates
//    TreesAndStructuresMenuItem beginStacksLessonButton;
//    beginStacksLessonButton.rect.top= 200;
//    beginStacksLessonButton.rect.height = 80;
//    beginStacksLessonButton.rect.left = 312;
//    beginStacksLessonButton.rect.width = 400;
//    beginStacksLessonButton.action = BeginStacksLesson;
    
    //Begin clickable button
//    sf::RectangleShape beginStacksLessonBox;
//    beginStacksLessonBox.setSize(sf::Vector2f(400, 80));
//    beginStacksLessonBox.setOutlineColor(sf::Color::Blue);
//    beginStacksLessonBox.setFillColor(sf::Color::Blue);
//    beginStacksLessonBox.setOutlineThickness(0);
//    beginStacksLessonBox.setPosition(312, 200);
//    renderWindow.draw(beginStacksLessonBox);
    
    //Begin stack attack menu item coordinates
    TreesAndStructuresMenuItem beginStackAttackButton;
    beginStackAttackButton.rect.top = 200;
    beginStackAttackButton.rect.height = 80;
    beginStackAttackButton.rect.left = 312;
    beginStackAttackButton.rect.width = 400;
    beginStackAttackButton.action = BeginStackAttack;
    
    //Begin stack attack clickable button
//    sf::RectangleShape beginStackAttackBox;
//    beginStackAttackBox.setSize(sf::Vector2f(400, 80));
//    beginStackAttackBox.setOutlineColor(sf::Color::Blue);
//    beginStackAttackBox.setFillColor(sf::Color::Blue);
//    beginStackAttackBox.setOutlineThickness(0);
//    beginStackAttackBox.setPosition(312, 300);
//    renderWindow.draw(beginStackAttackBox);
    
    //Begin tree dungeon menu item coordinates
    TreesAndStructuresMenuItem beginTreeDungeonButton;
    beginTreeDungeonButton.rect.top = 300;
    beginTreeDungeonButton.rect.height = 80;
    beginTreeDungeonButton.rect.left = 312;
    beginTreeDungeonButton.rect.width = 400;
    beginTreeDungeonButton.action = BeginTreeDungeon;
    
    //Begin tree dungeon clickable button
//    sf::RectangleShape beginTreeDungeonBox;
//    beginTreeDungeonBox.setSize(sf::Vector2f(400, 80));
//    beginTreeDungeonBox.setOutlineColor(sf::Color::Blue);
//    beginTreeDungeonBox.setFillColor(sf::Color::Blue);
//    beginTreeDungeonBox.setOutlineThickness(0);
//    beginTreeDungeonBox.setPosition(312, 400);
//    renderWindow.draw(beginTreeDungeonBox);
    
    //Exit menu item coordinates
    TreesAndStructuresMenuItem backButton;
    backButton.rect.top = 600;
    backButton.rect.height = 80;
    backButton.rect.left = 312;
    backButton.rect.width = 400;
    backButton.action = Back;
    
    //Exit clickable button
    //sf::RectangleShape exitBox;
    //exitBox.setSize(sf::Vector2f(400, 80));
    //exitBox.setOutlineColor(sf::Color::Blue);
    //exitBox.setFillColor(sf::Color::Blue);
    //exitBox.setOutlineThickness(0);
    //exitBox.setPosition(312, 600);
    //renderWindow.draw(exitBox);
    
    //menuItems.push_back(beginStacksLessonButton);
    menuItems.push_back(beginStackAttackButton);
    menuItems.push_back(beginTreeDungeonButton);
    menuItems.push_back(backButton);
    

//    
//    sf::Text beginStacksLessonText("Lesson on Structures", font, 40);
//    beginStacksLessonText.setPosition(310, 200);
//    beginStacksLessonText.setColor(sf::Color::White);
//    
//    sf::Text beginStackAttackText("Stack Attack", font, 40);
//    beginStackAttackText.setPosition(390, 300);
//    beginStackAttackText.setColor(sf::Color::White);
//    
//    sf::Text beginTreeDungeonText("Tree Dungeon", font, 40);
//    beginTreeDungeonText.setPosition(390, 400);
//    beginTreeDungeonText.setColor(sf::Color::White);
//    
//    sf::Text backText("Back", font, 40);
//    backText.setPosition(460, 600);
//    backText.setColor(sf::Color::White);
//    
//    renderWindow.draw(menuText);
//    renderWindow.draw(beginStacksLessonText);
//    renderWindow.draw(beginStackAttackText);
//    renderWindow.draw(beginTreeDungeonText);
//    renderWindow.draw(backText);
    
    //sf::Music music;
    //music.openFromFile(resourcePath() + "StackAttack.ogg");
    //music.play();
    
    renderWindow.draw(structures2ASprite);
    renderWindow.draw(structures3ASprite);
    renderWindow.draw(backASprite);
    
    renderWindow.display();
    return GetTreesAndStructuresMenuResponse(renderWindow);
}

TreesAndStructuresMenu::TreesAndStructuresMenuResult TreesAndStructuresMenu::HandleClick(int x, int y){
    std::list<TreesAndStructuresMenuItem>::iterator it;
    
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

TreesAndStructuresMenu::TreesAndStructuresMenuResult TreesAndStructuresMenu::GetTreesAndStructuresMenuResponse(sf::RenderWindow& window){
    window.clear();
    sf::Event menuEvent;
    
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        exit(1);
    }
    sf::Text menuText("Data Structures", font, 80);
    menuText.setPosition(250, 50);
    menuText.setColor(sf::Color::White);
    
    // Load a sprite to use for scrolling background
    sf::Texture texture;
    texture.loadFromFile(resourcePath() + "scrollingBackgroundTile.gif");
    sf::Sprite backgroundSprite(texture);
    
    scrollingBackground myBackground(backgroundSprite,(sf::Vector2f(-0.5, -0.5)));
    
    sf::Time elapsed = GLOBAL_CLOCK.restart();
    myBackground.update(elapsed);
    
    sf::Texture structures2ATexture;
    structures2ATexture.loadFromFile(resourcePath() + "MMstructures2a.gif");
    sf::Sprite structures2ASprite(structures2ATexture);
    structures2ASprite.setPosition(312, 200);
    
    sf::Texture structures3ATexture;
    structures3ATexture.loadFromFile(resourcePath() + "MMstructures3a.gif");
    sf::Sprite structures3ASprite(structures3ATexture);
    structures3ASprite.setPosition(312, 300);
    
    sf::Texture backATexture;
    backATexture.loadFromFile(resourcePath() + "MMbackA.gif");
    sf::Sprite backASprite(backATexture);
    backASprite.setPosition(312, 600);
    
    sf::Texture structures2BTexture;
    structures2BTexture.loadFromFile(resourcePath() + "MMstructures2b.gif");
    sf::Sprite structures2BSprite(structures2BTexture);
    structures2BSprite.setPosition(312, 200);
    
    sf::Texture structures3BTexture;
    structures3BTexture.loadFromFile(resourcePath() + "MMstructures3b.gif");
    sf::Sprite structures3BSprite(structures3BTexture);
    structures3BSprite.setPosition(312, 300);
    
    sf::Texture backBTexture;
    backBTexture.loadFromFile(resourcePath() + "MMbackB.gif");
    sf::Sprite backBSprite(backBTexture);
    backBSprite.setPosition(312, 600);
    
    for(;;){
        
        int draw;
        
        myBackground.update(elapsed);
        myBackground.draw(window);
        window.draw(structures2ASprite);
        window.draw(structures3ASprite);
        window.draw(backASprite);
        window.draw(menuText);
        
        while(window.pollEvent(menuEvent)){
            
            sf::Vector2i position = sf::Mouse::getPosition(window);
            sf::Vector2i relativePosition = handleMouseClick(position.x, position.y, window);
            std::list<TreesAndStructuresMenuItem>::iterator it;
            if(menuEvent.type == sf::Event::MouseButtonPressed){
                sf::Vector2i click = handleMouseClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y, window);
                return HandleClick(click.x, click.y);
            }
            if(menuEvent.type == sf::Event::Closed){
                return Back;
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
                window.draw(structures2BSprite);
                break;
            case 1:
                window.draw(structures3BSprite);
                break;
            case 2:
                window.draw(backBSprite);
                break;
        }
        window.display();
    }
}

