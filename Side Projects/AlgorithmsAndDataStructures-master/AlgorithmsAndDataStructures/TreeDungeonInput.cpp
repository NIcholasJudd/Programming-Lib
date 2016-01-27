//
//  TreeDungeonInput.cpp
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 9/07/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#include "ResourcePath.hpp"

int input(sf::RenderWindow &Window, class Character &Character, Maps &Map, Node* &CurrentNode, BTree &MapTree, TreeDungeonGraphics &MappedSprites){
    
    sf::Event event;
    while(Window.pollEvent(event)){

        if (event.type == sf::Event::KeyPressed){
            
            if (event.key.code == sf::Keyboard::Left){
                Character.setPlayerX(Character.getPlayerX()-32);
                if(collisions(Character, Map)){
                    Character.setPlayerX(Character.getPlayerX()+32);
                }
            }
            
            if (event.key.code == sf::Keyboard::Right){
                Character.setPlayerX(Character.getPlayerX()+32);
                if(collisions(Character, Map)){
                    Character.setPlayerX(Character.getPlayerX()-32);
                }
            }
            
            if (event.key.code == sf::Keyboard::Up){
                Character.setPlayerY(Character.getPlayerY()-32);
                if(collisions(Character, Map)){
                    Character.setPlayerY(Character.getPlayerY()+32);
                }
            }
            
            if (event.key.code == sf::Keyboard::Down){
                Character.setPlayerY(Character.getPlayerY()+32);
                if(collisions(Character, Map)){
                    Character.setPlayerY(Character.getPlayerY()-32);
                }
            }
            
            if (event.key.code == sf::Keyboard::A){
                resetGameState(MapTree, CurrentNode, Character, Map, MappedSprites);
                Character.goal = 1;
            }
            if (event.key.code == sf::Keyboard::B){
                resetGameState(MapTree, CurrentNode, Character, Map, MappedSprites);
                Character.goal = 2;
            }
            if (event.key.code == sf::Keyboard::C){
                resetGameState(MapTree, CurrentNode, Character, Map, MappedSprites);
                Character.goal = 3;
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q) {
                return 1;
            }
            treasure(Character, Map);
        }
    }
    return -1;
}

bool collisions(class Character& Character, Maps& Map){
    if(Map.getCurrentMap(Character.getPlayerX() / 32, Character.getPlayerY() / 32) == 'x'){
        return true;
    }
    return false;
}

void treasure(class Character& Character, Maps& Map){
    if(Map.getCurrentMap(Character.getPlayerX() / 32, Character.getPlayerY() / 32) == 't'){
        Character.setOnTreasure(true);
    }
}
