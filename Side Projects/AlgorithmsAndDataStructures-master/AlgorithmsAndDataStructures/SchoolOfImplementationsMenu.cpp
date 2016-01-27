//
//  SchoolOfImplementations.cpp
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 16/07/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#include "ResourcePath.hpp"

/*****************************************************
 
 SCHOOL OF IMPLEMENTATIONS MENU AND ACTION HANDLERS / LISTENERS
 
 *****************************************************/

SchoolOfImplementationsMenu::SchoolOfImplementationsMenuResult SchoolOfImplementationsMenu::Show(sf::RenderWindow& renderWindow){
    renderWindow.clear(sf::Color(sf::Color::Black));
    
    // Load a sprite to use for scrolling background
    sf::Texture texture;
    texture.loadFromFile(resourcePath() + "scrollingBackgroundTile.gif");
    sf::Sprite backgroundSprite(texture);
    
    scrollingBackground myBackground(backgroundSprite,(sf::Vector2f(-0.5, -0.5)));
    
    sf::Time elapsed = GLOBAL_CLOCK.restart();
    myBackground.update(elapsed);
    myBackground.draw(renderWindow);

    
    sf::Texture sorting1ATexture;
    sorting1ATexture.loadFromFile(resourcePath() + "MMsorting1a.gif");
    sf::Sprite sorting1ASprite(sorting1ATexture);
    sorting1ASprite.setPosition(312, 200);
    
    sf::Texture trees1ATexture;
    trees1ATexture.loadFromFile(resourcePath() + "LessonTreesA.gif");
    sf::Sprite trees1ASprite(trees1ATexture);
    trees1ASprite.setPosition(312, 300);
    
    sf::Texture stacks1ATexture;
    stacks1ATexture.loadFromFile(resourcePath() + "LessonStacksA.gif");
    sf::Sprite stacks1ASprite(stacks1ATexture);
    stacks1ASprite.setPosition(312, 400);
    
    sf::Texture abstraction1ATexture;
    abstraction1ATexture.loadFromFile(resourcePath() + "LessonAbstractionA.gif");
    sf::Sprite abstraction1ASprite(abstraction1ATexture);
    abstraction1ASprite.setPosition(312, 500);
    
    sf::Texture backATexture;
    backATexture.loadFromFile(resourcePath() + "MMbackA.gif");
    sf::Sprite backASprite(backATexture);
    backASprite.setPosition(312, 600);
    
    //Begin menu item coordinates
    SchoolOfImplementationsMenuItem beginSortingLessonButton;
    beginSortingLessonButton.rect.top= 200;
    beginSortingLessonButton.rect.height = 80;
    beginSortingLessonButton.rect.left = 312;
    beginSortingLessonButton.rect.width = 400;
    beginSortingLessonButton.action = BeginSortingLesson;
    
    SchoolOfImplementationsMenuItem beginTreesLessonButton;
    beginTreesLessonButton.rect.top= 300;
    beginTreesLessonButton.rect.height = 80;
    beginTreesLessonButton.rect.left = 312;
    beginTreesLessonButton.rect.width = 400;
    beginTreesLessonButton.action = BeginTreesLesson;
    
    SchoolOfImplementationsMenuItem beginStacksLessonButton;
    beginStacksLessonButton.rect.top= 400;
    beginStacksLessonButton.rect.height = 80;
    beginStacksLessonButton.rect.left = 312;
    beginStacksLessonButton.rect.width = 400;
    beginStacksLessonButton.action = BeginStacksLesson;
    
    SchoolOfImplementationsMenuItem beginProblemSolvingButton;
    beginProblemSolvingButton.rect.top= 500;
    beginProblemSolvingButton.rect.height = 80;
    beginProblemSolvingButton.rect.left = 312;
    beginProblemSolvingButton.rect.width = 400;
    beginProblemSolvingButton.action = BeginProblemSolvingLesson;
    
    //Begin clickable button
//    sf::RectangleShape beginBox;
//    beginBox.setSize(sf::Vector2f(400, 80));
//    beginBox.setOutlineColor(sf::Color::Blue);
//    beginBox.setFillColor(sf::Color::Blue);
//    beginBox.setOutlineThickness(0);
//    beginBox.setPosition(312, 200);
//    renderWindow.draw(beginBox);
    
    //Exit menu item coordinates
    SchoolOfImplementationsMenuItem backButton;
    backButton.rect.top = 600;
    backButton.rect.height = 80;
    backButton.rect.left = 312;
    backButton.rect.width = 400;
    backButton.action = Back;
    
    //Exit clickable button
//    sf::RectangleShape exitBox;
//    exitBox.setSize(sf::Vector2f(400, 80));
//    exitBox.setOutlineColor(sf::Color::Blue);
//    exitBox.setFillColor(sf::Color::Blue);
//    exitBox.setOutlineThickness(0);
//    exitBox.setPosition(312, 600);
//    renderWindow.draw(exitBox);
    
    menuItems.push_back(beginSortingLessonButton);
    menuItems.push_back(beginTreesLessonButton);
    menuItems.push_back(beginStacksLessonButton);
    menuItems.push_back(beginProblemSolvingButton);
    menuItems.push_back(backButton);
    
//
//    sf::Text beginText("Placeholder Text", font, 40);
//    beginText.setPosition(360, 200);
//    beginText.setColor(sf::Color::White);
//    
//    sf::Text backText("Back", font, 40);
//    backText.setPosition(460, 600);
//    backText.setColor(sf::Color::White);
//
    renderWindow.draw(sorting1ASprite);
    renderWindow.draw(trees1ASprite);
    renderWindow.draw(stacks1ASprite);
    renderWindow.draw(abstraction1ASprite);
    renderWindow.draw(backASprite);
    
    renderWindow.display();
    return GetSchoolOfImplementationsMenuResponse(renderWindow);
}

SchoolOfImplementationsMenu::SchoolOfImplementationsMenuResult SchoolOfImplementationsMenu::HandleClick(int x, int y){
    std::list<SchoolOfImplementationsMenuItem>::iterator it;
    
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

SchoolOfImplementationsMenu::SchoolOfImplementationsMenuResult SchoolOfImplementationsMenu::GetSchoolOfImplementationsMenuResponse(sf::RenderWindow& window){
    window.clear();
    sf::Event menuEvent;
    
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        exit(1);
    }
    sf::Text menuText("School", font, 80);
    menuText.setPosition(380, 50);
    menuText.setColor(sf::Color::White);

    
    // Load a sprite to use for scrolling background
    sf::Texture texture;
    texture.loadFromFile(resourcePath() + "scrollingBackgroundTile.gif");
    sf::Sprite backgroundSprite(texture);
    
    scrollingBackground myBackground(backgroundSprite,(sf::Vector2f(-0.5, -0.5)));
    
    sf::Time elapsed = GLOBAL_CLOCK.restart();
    
    sf::Texture sorting1ATexture;
    sorting1ATexture.loadFromFile(resourcePath() + "MMsorting1a.gif");
    sf::Sprite sorting1ASprite(sorting1ATexture);
    sorting1ASprite.setPosition(312, 200);
    
    sf::Texture trees1ATexture;
    trees1ATexture.loadFromFile(resourcePath() + "LessonTreesA.gif");
    sf::Sprite trees1ASprite(trees1ATexture);
    trees1ASprite.setPosition(312, 300);
    
    sf::Texture stacks1ATexture;
    stacks1ATexture.loadFromFile(resourcePath() + "LessonStacksA.gif");
    sf::Sprite stacks1ASprite(stacks1ATexture);
    stacks1ASprite.setPosition(312, 400);
    
    sf::Texture abstraction1ATexture;
    abstraction1ATexture.loadFromFile(resourcePath() + "LessonAbstractionA.gif");
    sf::Sprite abstraction1ASprite(abstraction1ATexture);
    abstraction1ASprite.setPosition(312, 500);
    
    sf::Texture backATexture;
    backATexture.loadFromFile(resourcePath() + "MMbackA.gif");
    sf::Sprite backASprite(backATexture);
    backASprite.setPosition(312, 600);
    
    sf::Texture sorting1BTexture;
    sorting1BTexture.loadFromFile(resourcePath() + "MMsorting1b.gif");
    sf::Sprite sorting1BSprite(sorting1BTexture);
    sorting1BSprite.setPosition(312, 200);
    
    sf::Texture trees1BTexture;
    trees1BTexture.loadFromFile(resourcePath() + "LessonTreesB.gif");
    sf::Sprite trees1BSprite(trees1BTexture);
    trees1BSprite.setPosition(312, 300);
    
    sf::Texture stacks1BTexture;
    stacks1BTexture.loadFromFile(resourcePath() + "LessonStacksB.gif");
    sf::Sprite stacks1BSprite(stacks1BTexture);
    stacks1BSprite.setPosition(312, 400);
    
    sf::Texture abstraction1BTexture;
    abstraction1BTexture.loadFromFile(resourcePath() + "LessonAbstractionB.gif");
    sf::Sprite abstraction1BSprite(abstraction1BTexture);
    abstraction1BSprite.setPosition(312, 500);
    
    sf::Texture backBTexture;
    backBTexture.loadFromFile(resourcePath() + "MMbackB.gif");
    sf::Sprite backBSprite(backBTexture);
    backBSprite.setPosition(312, 600);
    
    for(;;){
        
        int draw;
        
        myBackground.update(elapsed);
        myBackground.draw(window);
        window.draw(sorting1ASprite);
        window.draw(trees1ASprite);
        window.draw(stacks1ASprite);
        window.draw(abstraction1ASprite);
        window.draw(backASprite);
        window.draw(menuText);
        
        while(window.pollEvent(menuEvent)){
            
            sf::Vector2i position = sf::Mouse::getPosition(window);
            sf::Vector2i relativePosition = handleMouseClick(position.x, position.y, window);
            std::list<SchoolOfImplementationsMenuItem>::iterator it;
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
                    if(std::distance(menuItems.begin(), it) == 3){
                        draw = 3;
                    }
                    if(std::distance(menuItems.begin(), it) == 4){
                        draw = 4;
                    }
                }
            }
        }
        switch(draw){
            case 0:
                window.draw(sorting1BSprite);
                break;
            case 1:
                window.draw(trees1BSprite);
                break;
            case 2:
                window.draw(stacks1BSprite);
                break;
            case 3:
                window.draw(abstraction1BSprite);
                break;
            case 4:
                window.draw(backBSprite);
                break;
        }
        window.display();
    }
}
