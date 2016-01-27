//
//  TreeDungeonMaps.h
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 9/07/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#ifndef __Trevors_Traversal__maps__
#define __Trevors_Traversal__maps__

#include "ResourcePath.hpp"

const int MAPSIZE = 14;

class Maps{
public:
    char dungeonMapRoot[MAPSIZE][MAPSIZE];
    char dungeonMapCorridor0[MAPSIZE][MAPSIZE];
    char dungeonMapFork0[MAPSIZE][MAPSIZE];
    char dungeonMapLeaf0[MAPSIZE][MAPSIZE];
    char dungeonMapCorridor1[MAPSIZE][MAPSIZE];
    char dungeonMapFork1[MAPSIZE][MAPSIZE];
    char dungeonMapLeaf1[MAPSIZE][MAPSIZE];
    char dungeonMapCorridor2[MAPSIZE][MAPSIZE];
    char dungeonMapFork2[MAPSIZE][MAPSIZE];
    char dungeonMapLeaf2[MAPSIZE][MAPSIZE];
    char currentMap[MAPSIZE][MAPSIZE];
    char lineOfSight[MAPSIZE][MAPSIZE];
    void setCurrentMap(char [MAPSIZE][MAPSIZE]);
    char getCurrentMap(int x, int y)                { return currentMap[x][y]; }
    char getLOS(int x, int y)                       { return lineOfSight[x][y]; }
    void setLOS(int x, int y, char X)               { lineOfSight[x][y] = X; }
    Maps();
};

static Maps Map;

struct Node{
    char keyValue;
    Maps NodeMap;
    Node *left;
    Node *right;
    Node *getLeft()                                 { return left; }
    Node *getRight()                                { return right; }
    Node *getParent(char currentKey, Node *leaf);
    bool treasureCollected;
};

int maxDepth(struct Node*);

class BTree{
public:
    BTree();
    ~BTree();
    
    void insert(char key);
    Node *search(char key);
    void destroy_tree();
    
    Node *getCurrent()                              { return current; }
    Node *getRoot()                                 { return root; }
    
    void inOrder(Node* n);
    void preOrder(Node* n);
    void postOrder(Node* n);
    
    void mapTree(Node* Root);
    
    std::vector<char> goalInOrder;
    std::vector<char> goalPreOrder;
    std::vector<char> goalPostOrder;
    
private:
    void destroy_tree(Node *leaf);
    void insert(char key, Node *leaf);
    
    Node *search(char key, Node *leaf);
    
    Node *root;
    Node *current;
};

Node * updateMap(class Character &, class Maps &, Node* &, Node *);
int myrandom(int i);

static BTree MapTree;
std::string generateMap(class BTree &);

#endif /* defined(__Trevors_Traversal__maps__) */
