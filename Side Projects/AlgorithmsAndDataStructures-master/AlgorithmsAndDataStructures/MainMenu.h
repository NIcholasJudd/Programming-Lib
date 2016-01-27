//
//  MainMenu.h
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 7/06/2014.
//  Copyright (c) 2014 _BENJAMIN. All rights reserved.
//

#ifndef SFML_test_MainMenu_h
#define SFML_test_MainMenu_h

#pragma once

#include "ResourcePath.hpp"

class MainMenu{
    
public:
	enum MenuResult {   Nothing,
                        Exit,
                        SortingAndSearchingMenu,
                        PuzzlesAndGamesMenu,
                        TreesAndStructuresMenu,
                        SchoolOfImplementationsMenu };
    
	struct MenuItem{
    public:
        sf::Rect<int> rect;
        MenuResult action;
    };
	MenuResult Show(sf::RenderWindow& window);
    
private:
	MenuResult GetMenuResponse(sf::RenderWindow& window);
    MenuResult HandleClick(int x, int y);
	std::list<MenuItem> menuItems;
};

#endif
