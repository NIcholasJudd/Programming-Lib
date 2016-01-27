//
//  TreesAndStructuresMenu.h
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 31/01/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#ifndef __AlgorithmsAndDataStructures__TreesAndStructuresMenu__
#define __AlgorithmsAndDataStructures__TreesAndStructuresMenu__

#include "ResourcePath.hpp"

class TreesAndStructuresMenu{
public:
    enum TreesAndStructuresMenuResult { Nothing, Back, BeginStacksLesson, BeginStackAttack, BeginTreeDungeon };
    
    struct TreesAndStructuresMenuItem{
    public:
        sf::Rect<int> rect;
        TreesAndStructuresMenuResult action;
    };
    
    TreesAndStructuresMenuResult Show(sf::RenderWindow& window);
    
private:
    TreesAndStructuresMenuResult GetTreesAndStructuresMenuResponse(sf::RenderWindow& window);
    TreesAndStructuresMenuResult HandleClick(int x, int y);
    std::list<TreesAndStructuresMenuItem> menuItems;
};

#endif /* defined(__AlgorithmsAndDataStructures__SubMenu__) */
