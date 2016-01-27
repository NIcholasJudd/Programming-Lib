//
//  TreeDungeonMaps.cpp
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 9/07/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#include "ResourcePath.hpp"

Maps::Maps(){
    std::ifstream RootMapFile;
    RootMapFile.open(resourcePath() + "map_root.txt", std::ios::in);
    for(int i = 0; i < MAPSIZE; ++i){
        for(int j = 0; j < MAPSIZE; ++j){
            RootMapFile >> dungeonMapRoot[j][i];
        }
    }
    RootMapFile.close();
    
    std::ifstream CorridorMapFile0;
    CorridorMapFile0.open(resourcePath() + "map_corridor0.txt", std::ios::in);
    for(int i = 0; i < MAPSIZE; ++i){
        for(int j = 0; j < MAPSIZE; ++j){
            CorridorMapFile0 >> dungeonMapCorridor0[j][i];
        }
    }
    CorridorMapFile0.close();
    
    std::ifstream ForkMapFile0;
    ForkMapFile0.open(resourcePath() + "map_fork0.txt", std::ios::in);
    for(int i = 0; i < MAPSIZE; ++i){
        for(int j = 0; j < MAPSIZE; ++j){
            ForkMapFile0 >> dungeonMapFork0[j][i];
        }
    }
    ForkMapFile0.close();
    
    std::ifstream LeafMapFile0;
    LeafMapFile0.open(resourcePath() + "map_leaf0.txt", std::ios::in);
    for(int i = 0; i < MAPSIZE; ++i){
        for(int j = 0; j < MAPSIZE; ++j){
            LeafMapFile0 >> dungeonMapLeaf0[j][i];
        }
    }
    LeafMapFile0.close();
    
    std::ifstream CorridorMapFile1;
    CorridorMapFile1.open(resourcePath() + "map_corridor1.txt", std::ios::in);
    for(int i = 0; i < MAPSIZE; ++i){
        for(int j = 0; j < MAPSIZE; ++j){
            CorridorMapFile1 >> dungeonMapCorridor1[j][i];
        }
    }
    CorridorMapFile1.close();
    
    std::ifstream ForkMapFile1;
    ForkMapFile1.open(resourcePath() + "map_fork1.txt", std::ios::in);
    for(int i = 0; i < MAPSIZE; ++i){
        for(int j = 0; j < MAPSIZE; ++j){
            ForkMapFile1 >> dungeonMapFork1[j][i];
        }
    }
    ForkMapFile1.close();
    
    std::ifstream LeafMapFile1;
    LeafMapFile1.open(resourcePath() + "map_leaf1.txt", std::ios::in);
    for(int i = 0; i < MAPSIZE; ++i){
        for(int j = 0; j < MAPSIZE; ++j){
            LeafMapFile1 >> dungeonMapLeaf1[j][i];
        }
    }
    LeafMapFile1.close();
    
    std::ifstream CorridorMapFile2;
    CorridorMapFile2.open(resourcePath() + "map_corridor2.txt", std::ios::in);
    for(int i = 0; i < MAPSIZE; ++i){
        for(int j = 0; j < MAPSIZE; ++j){
            CorridorMapFile2 >> dungeonMapCorridor2[j][i];
        }
    }
    CorridorMapFile2.close();
    
    std::ifstream ForkMapFile2;
    ForkMapFile2.open(resourcePath() + "map_fork2.txt", std::ios::in);
    for(int i = 0; i < MAPSIZE; ++i){
        for(int j = 0; j < MAPSIZE; ++j){
            ForkMapFile2 >> dungeonMapFork2[j][i];
        }
    }
    ForkMapFile2.close();
    
    std::ifstream LeafMapFile2;
    LeafMapFile2.open(resourcePath() + "map_leaf2.txt", std::ios::in);
    for(int i = 0; i < MAPSIZE; ++i){
        for(int j = 0; j < MAPSIZE; ++j){
            LeafMapFile2 >> dungeonMapLeaf2[j][i];
        }
    }
    LeafMapFile2.close();
}

void Maps::setCurrentMap(char newMap[MAPSIZE][MAPSIZE]){
    for(int i = 0; i < MAPSIZE; ++i){
        for(int j = 0; j < MAPSIZE; ++j){
            currentMap[i][j] = newMap[i][j];
        }
    }
}

BTree::BTree(){
    root=NULL;
}

void BTree::destroy_tree(Node *leaf){
    if(leaf!=NULL){
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void BTree::insert(char key, Node *leaf){
    if(key< leaf->keyValue){
        if(leaf->left!=NULL)
            insert(key, leaf->left);
        else{
            leaf->left=new Node;
            leaf->left->keyValue=key;
            leaf->left->left=NULL;
            leaf->left->right=NULL;
        }
    }
    else if(key>=leaf->keyValue){
        if(leaf->right!=NULL)
            insert(key, leaf->right);
        else{
            leaf->right=new Node;
            leaf->right->keyValue=key;
            leaf->right->left=NULL;
            leaf->right->right=NULL;
        }
    }
}

Node *BTree::search(char key, Node *leaf){
    if(leaf!=NULL){
        if(key==leaf->keyValue)
            return leaf;
        if(key<leaf->keyValue)
            return search(key, leaf->left);
        else
            return search(key, leaf->right);
    }
    else return NULL;
}

Node *Node::getParent(char currentKey, Node *leaf){
    if(leaf != NULL){
        if(leaf->left != NULL){
            if(currentKey == leaf->left->keyValue){
                return leaf;
            }
        }
        if(leaf->right != NULL){
            if(currentKey == leaf->right->keyValue){
                return leaf;
            }
        }
        if(currentKey < leaf->keyValue)
            return getParent(currentKey, leaf->left);
        else
            return getParent(currentKey, leaf->right);
    }
    else return NULL;
}

void BTree::insert(char key){
    if(root!=NULL)
        insert(key, root);
    else{
        root=new Node;
        root->keyValue=key;
        root->left=NULL;
        root->right=NULL;
    }
}

void BTree::inOrder(Node* Root) {
    if(Root != NULL) {
        inOrder(Root->getLeft());
        goalInOrder.push_back(Root->keyValue);
        inOrder(Root->getRight());
    }
}

void BTree::preOrder(Node* node){
    if (node){
        goalPreOrder.push_back(node->keyValue);
        preOrder(node->getLeft());
        preOrder(node->getRight());
    }
}

void BTree::postOrder(Node* Root){
    if(Root != NULL) {
        postOrder(Root->getLeft());
        postOrder(Root->getRight());
        goalPostOrder.push_back(Root->keyValue);
    }
}

void BTree::mapTree(Node *node){
    if(node != NULL) {
        int randomRooms = std::rand() % 3;
        mapTree(node->getLeft());
        if(node->getLeft() != NULL && node->getRight() != NULL){
            if(randomRooms == 0){
                node->NodeMap.setCurrentMap(Map.dungeonMapFork0);
            }
            if(randomRooms == 1){
                node->NodeMap.setCurrentMap(Map.dungeonMapFork1);
            }
            if(randomRooms == 2){
                node->NodeMap.setCurrentMap(Map.dungeonMapFork2);
            }
        }
        else if(node->getLeft() == NULL && node->getRight() == NULL){
            if(randomRooms == 0){
                node->NodeMap.setCurrentMap(Map.dungeonMapLeaf0);
            }
            if(randomRooms == 1){
                node->NodeMap.setCurrentMap(Map.dungeonMapLeaf1);
            }
            if(randomRooms == 2){
                node->NodeMap.setCurrentMap(Map.dungeonMapLeaf2);
            }
        }
        else{
            if(randomRooms == 0){
                node->NodeMap.setCurrentMap(Map.dungeonMapCorridor0);
            }
            if(randomRooms == 1){
                node->NodeMap.setCurrentMap(Map.dungeonMapCorridor1);
            }
            if(randomRooms == 2){
                node->NodeMap.setCurrentMap(Map.dungeonMapCorridor2);
            }
        }
        mapTree(node->getRight());
        if(node->getLeft() != NULL && node->getRight() != NULL){
            if(randomRooms == 0){
                node->NodeMap.setCurrentMap(Map.dungeonMapFork0);
            }
            if(randomRooms == 1){
                node->NodeMap.setCurrentMap(Map.dungeonMapFork1);
            }
            if(randomRooms == 2){
                node->NodeMap.setCurrentMap(Map.dungeonMapFork2);
            }
        }
        else if(node->getLeft() == NULL && node->getRight() == NULL){
            if(randomRooms == 0){
                node->NodeMap.setCurrentMap(Map.dungeonMapLeaf0);
            }
            if(randomRooms == 1){
                node->NodeMap.setCurrentMap(Map.dungeonMapLeaf1);
            }
            if(randomRooms == 2){
                node->NodeMap.setCurrentMap(Map.dungeonMapLeaf2);
            }
        }
        else{
            if(randomRooms == 0){
                node->NodeMap.setCurrentMap(Map.dungeonMapCorridor0);
            }
            if(randomRooms == 1){
                node->NodeMap.setCurrentMap(Map.dungeonMapCorridor1);
            }
            if(randomRooms == 2){
                node->NodeMap.setCurrentMap(Map.dungeonMapCorridor2);
            }
        }
        node->treasureCollected = false;
    }
    node = root;
    node->NodeMap.setCurrentMap(Map.dungeonMapRoot);
}

Node *BTree::search(char key){
    return search(key, root);
}

void BTree::destroy_tree(){
    destroy_tree(root);
}

BTree::~BTree(){
    destroy_tree();
}

Node *updateMap(class Character &Character, class Maps &Map, Node* &CurrentNode, Node* RootNode){
    if(Map.getCurrentMap(Character.getPlayerX() / 32, Character.getPlayerY() / 32) == 'l'){
        CurrentNode = CurrentNode->getLeft();
        Character.setPlayerX(256);
        Character.setPlayerY(128);
    }
    if(Map.getCurrentMap(Character.getPlayerX() / 32, Character.getPlayerY() / 32) == 'r'){
        CurrentNode = CurrentNode->getRight();
        Character.setPlayerX(256);
        Character.setPlayerY(128);
    }
    if(Map.getCurrentMap(Character.getPlayerX() / 32, Character.getPlayerY() / 32) == 'g'){
        CurrentNode = CurrentNode->getParent(CurrentNode->keyValue, RootNode);
        Character.setPlayerX(256);
        Character.setPlayerY(384);
    }
    if(Map.getCurrentMap(Character.getPlayerX() / 32, Character.getPlayerY() / 32) == 'd'){
        if(CurrentNode->right){
            CurrentNode = CurrentNode->getRight();
        }
        else{
            CurrentNode = CurrentNode->getLeft();
        }
        Character.setPlayerX(128);
        Character.setPlayerY(128);
    }
    return CurrentNode;
}

int myrandom(int i){
    return std::rand() % i;
}

std::string generateMap(class BTree &MapTree){
    std::string MapText = "";
    
    std::srand (unsigned (std::time(0)));
    std::vector<int> myvector;

    for (int i = 65; i < 75; ++i){
        myvector.push_back(i);
    }
    std::random_shuffle (myvector.begin(), myvector.end());
    std::random_shuffle (myvector.begin(), myvector.end(), myrandom);
    
    for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it){
        MapTree.insert(*it);
        MapText += *it;
    }
    Node *RootNode = MapTree.getRoot();
    MapTree.inOrder(RootNode);
    MapTree.preOrder(RootNode);
    MapTree.postOrder(RootNode);
    
    return MapText;
}

int maxDepth(struct Node* node){
    if (node==NULL)
        return 0;
    else {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
        
        if (lDepth > rDepth)
            return(lDepth+1);
        else return(rDepth+1);
    }
}
