//
//  PuzzlesAndGamesMenu.h
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 16/07/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#ifndef __AlgorithmsAndDataStructures__PuzzlesAndGamesMenu__
#define __AlgorithmsAndDataStructures__PuzzlesAndGamesMenu__

#include "ResourcePath.hpp"

class PuzzlesAndGamesMenu{
public:
    enum PuzzlesAndGamesMenuResult { Nothing, Back, BeginConways, BeginRiverCrossing };
    
    struct PuzzlesAndGamesMenuItem{
    public:
        sf::Rect<int> rect;
        PuzzlesAndGamesMenuResult action;
    };
    
    PuzzlesAndGamesMenuResult Show(sf::RenderWindow& window);
    
private:
    PuzzlesAndGamesMenuResult GetPuzzlesAndGamesMenuResponse(sf::RenderWindow& window);
    PuzzlesAndGamesMenuResult HandleClick(int x, int y);
    std::list<PuzzlesAndGamesMenuItem> menuItems;
};

#endif /* defined(__AlgorithmsAndDataStructures__PuzzlesAndGamesMenu__) */
