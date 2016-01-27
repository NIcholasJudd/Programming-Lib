//
//  scrollingBackground.h
//  scrollingBackground
//
//  Created by Jim Gollop on 23/10/2015.
//  Copyright (c) 2015 Jim Gollop. All rights reserved.
//

#ifndef __scrollingBackground__scrollingBackground__
#define __scrollingBackground__scrollingBackground__

#include "ResourcePath.hpp"

class scrollingBackground{
private:
    sf::Sprite mySprite;
    sf::Vector2f move;
    sf::Vector2f offset;
    sf::Time timer;
    int width;
    int height;
public:
    scrollingBackground(sf::Sprite, sf::Vector2f);
    void update(sf::Time elapsed);
    void draw(sf::RenderWindow &window);
    void setMovement(sf::Vector2f m);
};

#endif /* defined(__scrollingBackground__scrollingBackground__) */
