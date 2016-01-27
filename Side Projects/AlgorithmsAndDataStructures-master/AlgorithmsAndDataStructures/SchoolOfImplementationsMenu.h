//
//  SchoolOfImplementations.h
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 16/07/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#ifndef __AlgorithmsAndDataStructures__SchoolOfImplementations__
#define __AlgorithmsAndDataStructures__SchoolOfImplementations__

#include "ResourcePath.hpp"

class SchoolOfImplementationsMenu{
public:
    enum SchoolOfImplementationsMenuResult { Nothing, Back, BeginSortingLesson, BeginTreesLesson, BeginStacksLesson, BeginProblemSolvingLesson };
    
    struct SchoolOfImplementationsMenuItem{
    public:
        sf::Rect<int> rect;
        SchoolOfImplementationsMenuResult action;
    };
    
    SchoolOfImplementationsMenuResult Show(sf::RenderWindow& window);
    
private:
    SchoolOfImplementationsMenuResult GetSchoolOfImplementationsMenuResponse(sf::RenderWindow& window);
    SchoolOfImplementationsMenuResult HandleClick(int x, int y);
    std::list<SchoolOfImplementationsMenuItem> menuItems;
};

#endif /* defined(__AlgorithmsAndDataStructures__SchoolOfImplementations__) */
