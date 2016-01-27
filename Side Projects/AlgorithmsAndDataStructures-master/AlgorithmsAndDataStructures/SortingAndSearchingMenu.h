//
//  SortingAndSearching.h
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 16/07/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#ifndef __AlgorithmsAndDataStructures__SortingAndSearching__
#define __AlgorithmsAndDataStructures__SortingAndSearching__

#include "ResourcePath.hpp"

class SortingAndSearchingMenu{
public:
    enum SortingAndSearchingMenuResult { Nothing, Back, BeginLesson, BeginDemo, BeginComparisson };
    
    struct SortingAndSearchingMenuItem{
    public:
        sf::Rect<int> rect;
        SortingAndSearchingMenuResult action;
    };
    
    SortingAndSearchingMenuResult Show(sf::RenderWindow& window);
    
private:
    SortingAndSearchingMenuResult GetSortingAndSearchingMenuResponse(sf::RenderWindow& window);
    SortingAndSearchingMenuResult HandleClick(int x, int y);
    std::list<SortingAndSearchingMenuItem> menuItems;
};


#endif /* defined(__AlgorithmsAndDataStructures__SortingAndSearching__) */
