//
//  TreeDungeonCharacter.h
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 16/07/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#ifndef __Trevors_Traversal__character__
#define __Trevors_Traversal__character__

class Character{
private:
    int playerXPosition;
    int playerYPosition;
    bool playerMove;
    int treasureCollected;
    bool onTreasure;
    bool allTreasures;
public:
    int goal;
    void setAllTreasures(bool AT)       { allTreasures = AT; };
    bool getAllTreasures()              { return allTreasures; };
    int getTreasureCollected()          { return treasureCollected; };
    void incTreasure()                  { treasureCollected++; };
    void setOnTreasure(bool t)          { onTreasure = t; };
    bool getOnTreasure()                { return onTreasure; };
    bool getPlayerMove()                { return playerMove; };
    void setPlayerMove(bool move)       { playerMove = move; };
    int getPlayerX()                    { return playerXPosition; };
    int getPlayerY()                    { return playerYPosition; };
    void setPlayerX(int x)              { playerXPosition = x; };
    void setPlayerY(int y)              { playerYPosition = y; };
    Character();
    
    std::string treasureInventory;
};

static Character Character;

#endif /* defined(__Trevors_Traversal__character__) */
