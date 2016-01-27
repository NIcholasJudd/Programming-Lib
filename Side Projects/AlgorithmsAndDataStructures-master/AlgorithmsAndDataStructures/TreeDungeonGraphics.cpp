//
//  TreeDungeonGraphics.cpp
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 9/07/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#include "ResourcePath.hpp"

TreeDungeonGraphics const TreeDungeonGraphics::initSprites(sf::Texture &Texture, class Character &Character){
    
    sf::Sprite Player(Texture);
    Player.setTextureRect(sf::IntRect(128, 0, 32, 32));
    Player.setPosition(Character.getPlayerX(), Character.getPlayerY());
    PlayerSprite = Player;
    
    sf::Sprite Monster(Texture);
    Monster.setTextureRect(sf::IntRect(0, 64, 32, 32));
    MonsterSprite = Monster;
    
    sf::Sprite Floor(Texture);
    Floor.setTextureRect(sf::IntRect(0, 32, 32, 32));
    FloorSprite = Floor;
    FloorSprites.push_back(Floor);
    Floor.setTextureRect(sf::IntRect(32, 32, 32, 32));
    FloorSprite = Floor;
    FloorSprites.push_back(Floor);
    Floor.setTextureRect(sf::IntRect(64, 32, 32, 32));
    FloorSprite = Floor;
    FloorSprites.push_back(Floor);
    
    sf::Sprite Wall(Texture);
    Wall.setTextureRect(sf::IntRect(32, 0, 32, 32));
    WallSprite = Wall;
    
    sf::Sprite Fog(Texture);
    Fog.setTextureRect(sf::IntRect(160, 0, 32, 32));
    FogSprite = Fog;
    
    sf::Sprite Treasure(Texture);
    Treasure.setTextureRect(sf::IntRect(128, 32, 32, 32));
    TreasureSpriteOpen = Treasure;
    
    Treasure.setTextureRect(sf::IntRect(160, 32, 32, 32));
    TreasureSpriteClosed = Treasure;
    
    sf::Sprite Up(Texture);
    Up.setTextureRect(sf::IntRect(0,0,32,32));
    UpSprite = Up;
    
    sf::Sprite Down(Texture);
    Down.setTextureRect(sf::IntRect(96,32,32,32));
    DownSprite = Down;

    
    if (!dungeonFont.loadFromFile(resourcePath() + "sansation.ttf")){
        std::cerr << "Could not load font" << std::endl;
    }
    
    return *this;
}

// Loads the texture sheet in its entirity
sf::Texture const TreeDungeonGraphics::initTextures(){
    sf::Texture Texture;
    if (!Texture.loadFromFile(resourcePath() + "DungeonTiles.png")) {
    }
    return Texture;
}

TreeDungeonGraphics const TreeDungeonGraphics::initBGSprite(sf::Texture &Texture){
    sf::Sprite Background(Texture);
    BackgroundSprite = Background;
    return *this;
}

sf::Texture const TreeDungeonGraphics::initBackground(){
    sf::Texture Texture;
    if (!Texture.loadFromFile(resourcePath() + "TreeDungeonBackground.png")) {
        std::cerr << "ERROR with background " << std::endl;
    }
    return Texture;
}

void updateGraphics(sf::RenderWindow &window, TreeDungeonGraphics &MappedSprites, Maps &Map, class Character &Character, class BTree &TreeMap, Node* &CurrentNode){
    
    window.clear();
    
    // Draw the map, fog and character
    
    sf::Sprite FloorSprite, WallSprite, PlayerSprite, MonsterSprite, FogSprite, TreasureSpriteOpen, UpSprite, DownSprite, TreasureSpriteClosed, Background;
    FloorSprite = MappedSprites.getFloorSprite();
    MonsterSprite = MappedSprites.getMonsterSprite();
    WallSprite = MappedSprites.getWallSprite();
    PlayerSprite = MappedSprites.getPlayerSprite();
    FogSprite = MappedSprites.getFogSprite();
    TreasureSpriteOpen = MappedSprites.getTreasureSpriteOpen();
    UpSprite = MappedSprites.getUp();
    DownSprite = MappedSprites.getDown();
    TreasureSpriteClosed = MappedSprites.getTreasureSpriteClosed();
    Background = MappedSprites.getBackground();
    Background.setPosition(0, 0);
    window.draw(Background);
    for(int i = 3; i < MAPSIZE; ++i){
        for(int j = 3; j < MAPSIZE; ++j){
            if(Map.getCurrentMap(j, i) == 't' && Map.getLOS(j, i) == 'o'){
                if(CurrentNode->treasureCollected == false){
                    TreasureSpriteOpen.setPosition(j * 32, i * 32);
                    window.draw(TreasureSpriteOpen);
                }
                else{
                    TreasureSpriteClosed.setPosition(j * 32, i * 32);
                    window.draw(TreasureSpriteClosed);
                }
            }
            if(Map.getCurrentMap(j, i) == 't' && Map.getLOS(j, i) == 'x'){
                FloorSprite.setPosition(j * 32, i * 32);
                window.draw(FloorSprite);
            }
            if(Map.getCurrentMap(j, i)=='o'){
                FloorSprite.setPosition(j * 32, i * 32);
                window.draw(FloorSprite);
            }
            if(Map.getCurrentMap(j, i)=='m'){
                FloorSprite.setPosition(j * 32, i * 32);
                window.draw(FloorSprite);
            }
            if(Map.getCurrentMap(j, i)=='m'){
                MonsterSprite.setPosition(j * 32, i * 32);
                window.draw(MonsterSprite);
            }
            if(Map.getLOS(j, i) == 'x'){
                FogSprite.setPosition(j * 32, i * 32);
                window.draw(FogSprite);
            }
            if(Map.getCurrentMap(j, i) == 'x'){
                WallSprite.setPosition(j * 32, i * 32);
                window.draw(WallSprite);
            }
            if(Map.getCurrentMap(j, i) == 'g'){
                UpSprite.setPosition(j * 32, i * 32);
                window.draw(UpSprite);
            }
            if(Map.getCurrentMap(j, i) == 'd'){
                DownSprite.setPosition(j * 32, i * 32);
                window.draw(DownSprite);
            }
            if(Map.getCurrentMap(j, i) == 'l'){
                DownSprite.setPosition(j * 32, i * 32);
                window.draw(DownSprite);
            }
            if(Map.getCurrentMap(j, i) == 'r'){
                DownSprite.setPosition(j * 32, i * 32);
                window.draw(DownSprite);
            }
        }
    }
    PlayerSprite.setPosition(Character.getPlayerX(), Character.getPlayerY());
    window.draw(PlayerSprite);
    
    // Draw the text
    sf::Text DungeonMapText;
    DungeonMapText.setFont(MappedSprites.dungeonFont);
    for(int i = 0; i < 10; ++i){
        int xOffset = 0;
        DungeonMapText.setString(MappedSprites.MapText.at(i));
        if(MappedSprites.MapText.at(i) == 'I' || MappedSprites.MapText.at(i) == 'J'){
            xOffset = 8;
        }
        DungeonMapText.setCharacterSize(24);
        DungeonMapText.setColor(sf::Color::White);
        DungeonMapText.setStyle(sf::Text::Bold);
        DungeonMapText.setPosition(650 + (i * 30) + xOffset, 260);
        window.draw(DungeonMapText);
        DungeonMapText.setStyle(sf::Text::Regular);
        std::string Key = "Key: ";
        DungeonMapText.setString(Key);
        DungeonMapText.setPosition(580, 260);
        window.draw(DungeonMapText);
    }
    
    int collectedYOffset = 0;
    for (std::string::iterator it=Character.treasureInventory.begin(); it!=Character.treasureInventory.end(); ++it){
        if(*it == 'A'){
            DungeonMapText.setString("Amazing amethyst armlet");
        }
        if(*it == 'B'){
            DungeonMapText.setString("Boring borite barney-snatchers");
        }
        if(*it == 'C'){
            DungeonMapText.setString("Considerably callous cornicopia");
        }
        if(*it == 'D'){
            DungeonMapText.setString("Digested donkey dilberts");
        }
        if(*it == 'E'){
            DungeonMapText.setString("Eggman Egberts erronious elepads");
        }
        if(*it == 'F'){
            DungeonMapText.setString("Festooned floundering flip-flops");
        }
        if(*it == 'G'){
            DungeonMapText.setString("Gloopy glamarous galoshes");
        }
        if(*it == 'H'){
            DungeonMapText.setString("Hillbert Humperdinks horrendous high-tops");
        }
        if(*it == 'I'){
            DungeonMapText.setString("Incognito incutaurs of the impetuous");
        }
        if(*it == 'J'){
            DungeonMapText.setString("Jostling jalepino jumpers");
        }
        DungeonMapText.setCharacterSize(16);
        DungeonMapText.setColor(sf::Color::White);
        DungeonMapText.setStyle(sf::Text::Regular);
        DungeonMapText.setPosition(600,(collectedYOffset * 30) + 400);
        window.draw(DungeonMapText);
        collectedYOffset++;
    }
    
    sf::Text OrderText, PreText, PostText;
    OrderText.setFont(MappedSprites.dungeonFont);
    PreText.setFont(MappedSprites.dungeonFont);
    PostText.setFont(MappedSprites.dungeonFont);
    
    OrderText.setCharacterSize(32);
    PreText.setCharacterSize(32);
    PostText.setCharacterSize(32);
    
    OrderText.setColor(sf::Color::White);
    PreText.setColor(sf::Color::White);
    PostText.setColor(sf::Color::White);
    
    switch(Character.goal){
        case 1:
            OrderText.setColor(sf::Color::Yellow);
            break;
        case 2:
            PreText.setColor(sf::Color::Yellow);
            break;
        case 3:
            PostText.setColor(sf::Color::Yellow);
            break;
    }
    
    OrderText.setStyle(sf::Text::Bold);
    PreText.setStyle(sf::Text::Bold);
    PostText.setStyle(sf::Text::Bold);
    
    OrderText.setString("[A] In-order traversal");
    PreText.setString("[B] Pre-order traversal");
    PostText.setString("[C] Post-order traversal");
    
    OrderText.setPosition(80, 580);
    PreText.setPosition(80, 630);
    PostText.setPosition(80, 680);
    
    window.draw(OrderText);
    window.draw(PreText);
    window.draw(PostText);
    
    drawMap(window, Map, TreeMap, CurrentNode);
    
    window.display();
}

void drawMap(sf::RenderWindow &window, class Maps &Map, class BTree &TreeMap, Node *CurrentNode){
    // Root node
    Node *RootNode = TreeMap.getRoot();
    // Depth two nodes
    Node *DepthTwoLeft = RootNode->getLeft();
    Node *DepthTwoRight = RootNode->getRight();
    // Depth three nodes
    Node *DepthThreeLeftLeft;
    Node *DepthThreeLeftRight;
    Node *DepthThreeRightLeft;
    Node *DepthThreeRightRight;
    // Bool to enter functions
    bool ThreeLeftLeft = false;
    bool ThreeLeftRight = false;
    bool ThreeRightLeft = false;
    bool ThreeRightRight = false;
    if(DepthTwoLeft->getLeft() != NULL){
        ThreeLeftLeft = true;
        DepthThreeLeftLeft = DepthTwoLeft->getLeft();
    }
    if(DepthTwoLeft->getRight() != NULL){
        ThreeLeftRight = true;
        DepthThreeLeftRight = DepthTwoLeft->getRight();
    }
    if(DepthTwoRight->getLeft() != NULL){
        ThreeRightLeft = true;
        DepthThreeRightLeft = DepthTwoRight->getLeft();
    }
    if(DepthTwoRight->getRight() != NULL){
        ThreeRightRight = true;
        DepthThreeRightRight = DepthTwoRight->getRight();
    }
    int rootX = 750, rootY = 80;
    // Nodes
    sf::RectangleShape treeNode(sf::Vector2f(16, 16));
    // Edges
    sf::Vertex treePath[] = {
        sf::Vertex(sf::Vector2f(0, 0)),
        sf::Vertex(sf::Vector2f(0, 0))
    };
    // Root node
    if(RootNode->treasureCollected == true){
        treeNode.setFillColor(sf::Color::Yellow);
    }
    else{
        treeNode.setFillColor(sf::Color::White);
    }
    treeNode.setFillColor(nodeColour(CurrentNode, RootNode));
    treeNode.setPosition(rootX, rootY);
    window.draw(treeNode);
    treeNode.setFillColor(sf::Color::White);
    // Depth 2
    if(RootNode->getLeft() != NULL){
        if(RootNode->getLeft()->treasureCollected == true){
            treeNode.setFillColor(sf::Color::Yellow);
        }
        treeNode.setFillColor(nodeColour(CurrentNode, RootNode->getLeft()));
        treeNode.setPosition(rootX - 96, rootY + 48);
        window.draw(treeNode);
        treePath[0] = sf::Vertex(sf::Vector2f(rootX - 96 + 8, rootY + 48));
        treePath[1] = sf::Vertex(sf::Vector2f(rootX, rootY + 16));
        window.draw(treePath, 2, sf::Lines);
        treeNode.setFillColor(sf::Color::White);
    }
    if(RootNode->getRight() != NULL){
        if(RootNode->getRight()->treasureCollected == true){
            treeNode.setFillColor(sf::Color::Yellow);
        }
        treeNode.setFillColor(nodeColour(CurrentNode, RootNode->getRight()));
        treeNode.setPosition(rootX + 96, rootY + 48);
        window.draw(treeNode);
        treePath[0] = sf::Vertex(sf::Vector2f(rootX + 96 + 8, rootY + 48));
        treePath[1] = sf::Vertex(sf::Vector2f(rootX + 16, rootY + 16));
        window.draw(treePath, 2, sf::Lines);
        treeNode.setFillColor(sf::Color::White);
    }
    // Depth 3
    if(DepthTwoLeft->getLeft() != NULL){
        if(DepthTwoLeft->getLeft()->treasureCollected == true){
            treeNode.setFillColor(sf::Color::Yellow);
        }
        treeNode.setFillColor(nodeColour(CurrentNode, DepthTwoLeft->getLeft()));
        treeNode.setPosition(rootX - 148, rootY + 96);
        window.draw(treeNode);
        treePath[0] = sf::Vertex(sf::Vector2f(rootX - 148 + 8, rootY + 96));
        treePath[1] = sf::Vertex(sf::Vector2f(rootX - 96, rootY + 48 + 16));
        window.draw(treePath, 2, sf::Lines);
        treeNode.setFillColor(sf::Color::White);
    }
    if(DepthTwoLeft->getRight() != NULL){
        if(DepthTwoLeft->getRight()->treasureCollected == true){
            treeNode.setFillColor(sf::Color::Yellow);
        }
        treeNode.setFillColor(nodeColour(CurrentNode, DepthTwoLeft->getRight()));
        treeNode.setPosition(rootX - 44, rootY + 96);
        window.draw(treeNode);
        treePath[0] = sf::Vertex(sf::Vector2f(rootX - 36, rootY + 96));
        treePath[1] = sf::Vertex(sf::Vector2f(rootX - 96 + 16, rootY + 48 + 16));
        window.draw(treePath, 2, sf::Lines);
        treeNode.setFillColor(sf::Color::White);
    }
    if(DepthTwoRight->getLeft() != NULL){
        if(DepthTwoRight->getLeft()->treasureCollected == true){
            treeNode.setFillColor(sf::Color::Yellow);
        }
        treeNode.setFillColor(nodeColour(CurrentNode, DepthTwoRight->getLeft()));
        treeNode.setPosition(rootX + 44, rootY + 96);
        window.draw(treeNode);
        treePath[0] = sf::Vertex(sf::Vector2f(rootX + 36 + 16, rootY + 96));
        treePath[1] = sf::Vertex(sf::Vector2f(rootX + 96, rootY + 48 + 16));
        window.draw(treePath, 2, sf::Lines);
        treeNode.setFillColor(sf::Color::White);
    }
    if(DepthTwoRight->getRight() != NULL){
        if(DepthTwoRight->getRight()->treasureCollected == true){
            treeNode.setFillColor(sf::Color::Yellow);
        }
        treeNode.setFillColor(nodeColour(CurrentNode, DepthTwoRight->getRight()));
        treeNode.setPosition(rootX + 148, rootY + 96);
        window.draw(treeNode);
        treePath[0] = sf::Vertex(sf::Vector2f(rootX + 148 + 8, rootY + 96));
        treePath[1] = sf::Vertex(sf::Vector2f(rootX + 96 + 16, rootY + 48 + 16));
        window.draw(treePath, 2, sf::Lines);
        treeNode.setFillColor(sf::Color::White);
    }
    // Depth 4
    if(ThreeLeftLeft){
        if(DepthThreeLeftLeft->getLeft() != NULL){
            if(DepthThreeLeftLeft->getLeft()->treasureCollected == true){
                treeNode.setFillColor(sf::Color::Yellow);
            }
            treeNode.setFillColor(nodeColour(CurrentNode, DepthThreeLeftLeft->getLeft()));
            treeNode.setPosition(rootX - 180, rootY + 144);
            window.draw(treeNode);
            treePath[0] = sf::Vertex(sf::Vector2f(rootX - 180 + 8, rootY + 144));
            treePath[1] = sf::Vertex(sf::Vector2f(rootX - 148, rootY + 96 + 16));
            window.draw(treePath, 2, sf::Lines);
            treeNode.setFillColor(sf::Color::White);
        }
        if(DepthThreeLeftLeft->getRight() != NULL){
            if(DepthThreeLeftLeft->getRight()->treasureCollected == true){
                treeNode.setFillColor(sf::Color::Yellow);
            }
            treeNode.setFillColor(nodeColour(CurrentNode, DepthThreeLeftLeft->getRight()));
            treeNode.setPosition(rootX - 116, rootY + 144);
            window.draw(treeNode);
            treePath[0] = sf::Vertex(sf::Vector2f(rootX - 116 + 8, rootY + 144));
            treePath[1] = sf::Vertex(sf::Vector2f(rootX - 132, rootY + 96 + 16));
            window.draw(treePath, 2, sf::Lines);
            treeNode.setFillColor(sf::Color::White);
        }
    }
    if(ThreeLeftRight){
        if(DepthThreeLeftRight->getLeft() != NULL){
            if(DepthThreeLeftRight->getLeft()->treasureCollected == true){
                treeNode.setFillColor(sf::Color::Yellow);
            }
            treeNode.setFillColor(nodeColour(CurrentNode, DepthThreeLeftRight->getLeft()));
            treeNode.setPosition(rootX - 76, rootY + 144);
            window.draw(treeNode);
            treePath[0] = sf::Vertex(sf::Vector2f(rootX - 76 + 8, rootY + 144));
            treePath[1] = sf::Vertex(sf::Vector2f(rootX - 44, rootY + 96 + 16));
            window.draw(treePath, 2, sf::Lines);
            treeNode.setFillColor(sf::Color::White);
        }
        if(DepthThreeLeftRight->getRight() != NULL){
            if(DepthThreeLeftRight->getRight()->treasureCollected == true){
                treeNode.setFillColor(sf::Color::Yellow);
            }
            treeNode.setFillColor(nodeColour(CurrentNode, DepthThreeLeftRight->getRight()));
            treeNode.setPosition(rootX - 12, rootY + 144);
            window.draw(treeNode);
            treePath[0] = sf::Vertex(sf::Vector2f(rootX - 6, rootY + 144));
            treePath[1] = sf::Vertex(sf::Vector2f(rootX - 28, rootY + 96 + 16));
            window.draw(treePath, 2, sf::Lines);
            treeNode.setFillColor(sf::Color::White);
        }
    }
    if(ThreeRightLeft){
        if(DepthThreeRightLeft->getLeft() != NULL){
            if(DepthThreeRightLeft->getLeft()->treasureCollected == true){
                treeNode.setFillColor(sf::Color::Yellow);
            }
            treeNode.setFillColor(nodeColour(CurrentNode, DepthThreeRightLeft->getLeft()));
            treeNode.setPosition(rootX + 12, rootY + 144);
            window.draw(treeNode);
            treePath[0] = sf::Vertex(sf::Vector2f(rootX + 20, rootY + 144));
            treePath[1] = sf::Vertex(sf::Vector2f(rootX + 44, rootY + 96 + 16));
            window.draw(treePath, 2, sf::Lines);
            treeNode.setFillColor(sf::Color::White);
        }
        if(DepthThreeRightLeft->getRight() != NULL){
            if(DepthThreeRightLeft->getRight()->treasureCollected == true){
                treeNode.setFillColor(sf::Color::Yellow);
            }
            treeNode.setFillColor(nodeColour(CurrentNode, DepthThreeRightLeft->getRight()));
            treeNode.setPosition(rootX + 76, rootY + 144);
            window.draw(treeNode);
            treePath[0] = sf::Vertex(sf::Vector2f(rootX + 76 + 8, rootY + 144));
            treePath[1] = sf::Vertex(sf::Vector2f(rootX + 60, rootY + 96 + 16));
            window.draw(treePath, 2, sf::Lines);
            treeNode.setFillColor(sf::Color::White);
        }
    }
    if(ThreeRightRight){
        if(DepthThreeRightRight->getLeft() != NULL){
            if(DepthThreeRightRight->getLeft()->treasureCollected == true){
                treeNode.setFillColor(sf::Color::Yellow);
            }
            treeNode.setFillColor(nodeColour(CurrentNode, DepthThreeRightRight->getLeft()));
            treeNode.setPosition(rootX + 116, rootY + 144);
            window.draw(treeNode);
            treePath[0] = sf::Vertex(sf::Vector2f(rootX + 116 + 8, rootY + 144));
            treePath[1] = sf::Vertex(sf::Vector2f(rootX + 132 + 16, rootY + 96 + 16));
            window.draw(treePath, 2, sf::Lines);
            treeNode.setFillColor(sf::Color::White);
        }
        if(DepthThreeRightRight->getRight() != NULL){
            if(DepthThreeRightRight->getRight()->treasureCollected == true){
                treeNode.setFillColor(sf::Color::Yellow);
            }
            treeNode.setFillColor(nodeColour(CurrentNode, DepthThreeRightRight->getRight()));
            treeNode.setPosition(rootX + 180, rootY + 144);
            window.draw(treeNode);
            treePath[0] = sf::Vertex(sf::Vector2f(rootX + 180 + 8, rootY + 144));
            treePath[1] = sf::Vertex(sf::Vector2f(rootX + 148 + 16, rootY + 96 + 16));
            window.draw(treePath, 2, sf::Lines);
            treeNode.setFillColor(sf::Color::White);
        }
    }
}

sf::Color nodeColour(Node *CurrentNode, Node *thisNode){
    if(CurrentNode == thisNode){
        return sf::Color::Green;
    }
    else if (thisNode->treasureCollected){
        return sf::Color::Yellow;
    }
    else{
        return sf::Color::White;
    }
}
