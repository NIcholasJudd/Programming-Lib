//
//  MainMenu.cpp
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 7/06/2014.
//  Copyright (c) 2014 _BENJAMIN. All rights reserved.
//

#include "ResourcePath.hpp"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& renderWindow){
    
    renderWindow.clear(sf::Color(sf::Color::Black));
    
    // Load a sprite to use for scrolling background
    sf::Texture texture;
    texture.loadFromFile(resourcePath() + "scrollingBackgroundTile.gif");
    sf::Sprite backgroundSprite(texture);
    
    scrollingBackground myBackground(backgroundSprite,(sf::Vector2f(-0.5, -0.5)));
    
    sf::Time elapsed = GLOBAL_CLOCK.restart();
    myBackground.update(elapsed);
    myBackground.draw(renderWindow);
    
    sf::Texture puzzlesATexture;
    puzzlesATexture.loadFromFile(resourcePath() + "MMpuzzlesA.png");
    sf::Sprite puzzlesASprite(puzzlesATexture);
    puzzlesASprite.setPosition(212, 420);
    
    sf::Texture schoolATexture;
    schoolATexture.loadFromFile(resourcePath() + "MMschoolA.png");
    sf::Sprite schoolASprite(schoolATexture);
    schoolASprite.setPosition(524, 420);
    
    sf::Texture sortingATexture;
    sortingATexture.loadFromFile(resourcePath() + "MMsortingA.png");
    sf::Sprite sortingASprite(sortingATexture);
    sortingASprite.setPosition(212, 200);
    
    sf::Texture structuresATexture;
    structuresATexture.loadFromFile(resourcePath() + "MMstructuresA.png");
    sf::Sprite structuresASprite(structuresATexture);
    structuresASprite.setPosition(522, 200);
    
	//Begin sorting and searching menu item coordinates
	MenuItem beginSortingAndSearchingButton;
	beginSortingAndSearchingButton.rect.top= 200;
	beginSortingAndSearchingButton.rect.height = 200;
	beginSortingAndSearchingButton.rect.left = 212;
	beginSortingAndSearchingButton.rect.width = 300;
    beginSortingAndSearchingButton.action = SortingAndSearchingMenu;
    
    //Begin trees and structures menu item coordinates
    MenuItem beginTreesAndStructuresButton;
    beginTreesAndStructuresButton.rect.top= 200;
    beginTreesAndStructuresButton.rect.height = 200;
    beginTreesAndStructuresButton.rect.left = 522;
    beginTreesAndStructuresButton.rect.width = 300;
    beginTreesAndStructuresButton.action = TreesAndStructuresMenu;
    
    //Begin puzzles and games menu item coordinates
    MenuItem beginPuzzlesAndGamesButton;
    beginPuzzlesAndGamesButton.rect.top= 420;
    beginPuzzlesAndGamesButton.rect.height = 200;
    beginPuzzlesAndGamesButton.rect.left = 212;
    beginPuzzlesAndGamesButton.rect.width = 300;
    beginPuzzlesAndGamesButton.action = PuzzlesAndGamesMenu;
    
    //Begin school of implementations menu item coordinates
    MenuItem beginSchoolOfImplementationsButton;
    beginSchoolOfImplementationsButton.rect.top = 420;
    beginSchoolOfImplementationsButton.rect.height = 200;
    beginSchoolOfImplementationsButton.rect.left = 524;
    beginSchoolOfImplementationsButton.rect.width = 300;
    beginSchoolOfImplementationsButton.action = SchoolOfImplementationsMenu;

	menuItems.push_back(beginSortingAndSearchingButton);
    menuItems.push_back(beginTreesAndStructuresButton);
    menuItems.push_back(beginPuzzlesAndGamesButton);
    menuItems.push_back(beginSchoolOfImplementationsButton);
	//menuItems.push_back(exitButton);
    
    renderWindow.draw(puzzlesASprite);
    renderWindow.draw(schoolASprite);
    renderWindow.draw(sortingASprite);
    renderWindow.draw(structuresASprite);
	renderWindow.display();
    
	return GetMenuResponse(renderWindow);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y){
	std::list<MenuItem>::iterator it;
    
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

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow& window){
    window.clear();
	sf::Event menuEvent;
    
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        exit(1);
    }
    sf::Text menuText("Menu", font, 80);
    menuText.setPosition(400, 50);
    menuText.setColor(sf::Color::White);
    
    // Load a sprite to use for scrolling background
    sf::Texture texture;
    texture.loadFromFile(resourcePath() + "scrollingBackgroundTile.gif");
    sf::Sprite backgroundSprite(texture);
    
    scrollingBackground myBackground(backgroundSprite,(sf::Vector2f(-0.5, -0.5)));
    
    sf::Time elapsed = GLOBAL_CLOCK.restart();

    
    sf::Texture puzzlesATexture;
    puzzlesATexture.loadFromFile(resourcePath() + "MMpuzzlesA.png");
    sf::Sprite puzzlesASprite(puzzlesATexture);
    puzzlesASprite.setPosition(212, 420);
    
    sf::Texture schoolATexture;
    schoolATexture.loadFromFile(resourcePath() + "MMschoolA.png");
    sf::Sprite schoolASprite(schoolATexture);
    schoolASprite.setPosition(524, 420);
    
    sf::Texture sortingATexture;
    sortingATexture.loadFromFile(resourcePath() + "MMsortingA.png");
    sf::Sprite sortingASprite(sortingATexture);
    sortingASprite.setPosition(212, 200);
    
    sf::Texture structuresATexture;
    structuresATexture.loadFromFile(resourcePath() + "MMstructuresA.png");
    sf::Sprite structuresASprite(structuresATexture);
    structuresASprite.setPosition(522, 200);
    
    sf::Texture puzzlesBTexture;
    puzzlesBTexture.loadFromFile(resourcePath() + "MMPuzzlesB.png");
    sf::Sprite puzzlesBSprite(puzzlesBTexture);
    puzzlesBSprite.setPosition(212, 420);
    
    sf::Texture schoolBTexture;
    schoolBTexture.loadFromFile(resourcePath() + "MMschoolB.png");
    sf::Sprite schoolBSprite(schoolBTexture);
    schoolBSprite.setPosition(524, 420);
    
    sf::Texture sortingBTexture;
    sortingBTexture.loadFromFile(resourcePath() + "MMsortingB.png");
    sf::Sprite sortingBSprite(sortingBTexture);
    sortingBSprite.setPosition(212, 200);
    
    sf::Texture structuresBTexture;
    structuresBTexture.loadFromFile(resourcePath() + "MMstructuresB.png");
    sf::Sprite structuresBSprite(structuresBTexture);
    structuresBSprite.setPosition(522, 200);
    
    for(;;){
        int draw;
        
        myBackground.update(elapsed);
        myBackground.draw(window);
        window.draw(puzzlesASprite);
        window.draw(schoolASprite);
        window.draw(sortingASprite);
        window.draw(structuresASprite);
        window.draw(menuText);

		while(window.pollEvent(menuEvent)){
            
            sf::Vector2i position = sf::Mouse::getPosition(window);
            sf::Vector2i relativePosition = handleMouseClick(position.x, position.y, window);
            std::list<MenuItem>::iterator it;
            
			if(menuEvent.type == sf::Event::MouseButtonPressed){
                sf::Vector2i click = handleMouseClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y, window);
                return HandleClick(click.x, click.y);
			}
            
            if(menuEvent.type == sf::Event::KeyPressed){
                if(menuEvent.key.code == sf::Keyboard::Q){
                    return Exit;
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
                }
            }
		}
        switch(draw){
            case 0:
                window.draw(sortingBSprite);
                break;
            case 1:
                window.draw(structuresBSprite);
                break;
            case 2:
                window.draw(puzzlesBSprite);
                break;
            case 3:
                window.draw(schoolBSprite);
                break;
        }
        window.display();
	}
}
