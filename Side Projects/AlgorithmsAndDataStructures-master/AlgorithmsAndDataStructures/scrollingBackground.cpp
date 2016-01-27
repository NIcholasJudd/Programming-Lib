//
//  scrollingBackground.cpp
//  scrollingBackground
//
//  Created by Jim Gollop on 23/10/2015.
//  Copyright (c) 2015 Jim Gollop. All rights reserved.
//

#include "ResourcePath.hpp"
//#include "scrollingBackground.h"

scrollingBackground::scrollingBackground(sf::Sprite s, sf::Vector2f m) {
    mySprite = s;
    move = m;
    timer = sf::milliseconds(0);
    offset = sf::Vector2f(0, 0);
    width = (2048/mySprite.getGlobalBounds().width) + 2;
    height = (2048/mySprite.getGlobalBounds().height) + 2;
}

void scrollingBackground::update(sf::Time elapsed) {
    timer += elapsed;
    if (timer.asMilliseconds() > 5) {
        offset += move;
        if (offset.x < (-1*mySprite.getGlobalBounds().width) || offset.x > mySprite.getGlobalBounds().width) {
            offset.x = 0;
        }
        if (offset.y < (-1*mySprite.getGlobalBounds().height) || offset.y > mySprite.getGlobalBounds().height) {
            offset.y = 0;
        }
        timer = sf::milliseconds(0);
    }
}

void scrollingBackground::draw(sf::RenderWindow &window) {
    for (int j = 0; j < height; j++) {
        for (int i = 0;  i < width; i++) {
            mySprite.setPosition(i*mySprite.getGlobalBounds().width+offset.x-mySprite.getGlobalBounds().width,
                                 j*mySprite.getGlobalBounds().height+offset.y-mySprite.getGlobalBounds().height);
            window.draw(mySprite);
        }
    }
    window.draw(mySprite);
}

void scrollingBackground::setMovement(sf::Vector2f m) {
    move = m;
}
