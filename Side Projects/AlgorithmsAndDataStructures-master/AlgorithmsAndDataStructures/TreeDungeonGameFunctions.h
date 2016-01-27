//
//  TreeDungeonGameFunctions.h
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 5/09/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#ifndef __Trevors_Traversal__TreeDungeonGameFunctions__
#define __Trevors_Traversal__TreeDungeonGameFunctions__

#include "ResourcePath.hpp"

void updateGame(class BTree &, struct Node* &, class Character &, class Maps &, class TreeDungeonGraphics &, sf::RenderWindow &);
void resetGameState(class BTree &, struct Node* &, class Character &, class Maps &, class TreeDungeonGraphics &);
void displayEndGame(sf::RenderWindow &);

#endif /* defined(__Trevors_Traversal__TreeDungeonGameFunctions__) */
