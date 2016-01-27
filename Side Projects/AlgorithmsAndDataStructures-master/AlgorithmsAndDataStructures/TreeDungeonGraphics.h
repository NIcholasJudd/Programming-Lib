//
//  TreeDungeonGraphics.h
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 9/07/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#ifndef __Trevors_Traversal__graphics__
#define __Trevors_Traversal__graphics__

#include "ResourcePath.hpp"


class TreeDungeonGraphics{
private:
    sf::Sprite PlayerSprite;
    sf::Sprite MonsterSprite;
    sf::Sprite FloorSprite;
    sf::Sprite WallSprite;
    sf::Sprite FogSprite;
    sf::Sprite TreasureSpriteOpen;
    sf::Sprite TreasureSpriteClosed;
    sf::Sprite UpSprite;
    sf::Sprite DownSprite;
    sf::Sprite BackgroundSprite;
    std::vector<sf::Sprite> FloorSprites;
public:
    std::vector<sf::Sprite> getFloorSprites()           { return FloorSprites; };
    sf::Sprite getPlayerSprite()                        { return PlayerSprite; };
    sf::Sprite getMonsterSprite()                       { return MonsterSprite; };
    sf::Sprite getFloorSprite()                         { return FloorSprite; };
    sf::Sprite getWallSprite()                          { return WallSprite; };
    sf::Sprite getFogSprite()                           { return FogSprite; };
    sf::Sprite getUp()                                  { return UpSprite; };
    sf::Sprite getDown()                                { return DownSprite; };
    sf::Sprite getTreasureSpriteOpen()                  { return TreasureSpriteOpen; };
    sf::Sprite getTreasureSpriteClosed()                { return TreasureSpriteClosed; };
    sf::Sprite getBackground()                          { return BackgroundSprite; };
    
    std::string MapText;
    sf::Font dungeonFont;
    
    const TreeDungeonGraphics initSprites(sf::Texture &, class Character &);
    const TreeDungeonGraphics initBGSprite(sf::Texture &Texture);
    static const sf::Texture initTextures();
    static const sf::Texture initBackground();
    
};

static TreeDungeonGraphics MappedSprites;

void updateGraphics(sf::RenderWindow &, class TreeDungeonGraphics &, class Maps &, class Character &, class BTree &, Node* &);
void drawMap(sf::RenderWindow &,class Maps &, class BTree &, Node *);
sf::Color nodeColour(Node *, Node *);

#endif /* defined(__Trevors_Traversal__graphics__) */
