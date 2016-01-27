//
//  ConwaysMain.h
//  AlgorithmsAndDataStructures
//
//  Created by Jim Gollop on 12/09/2015.
//  Copyright (c) 2015 Jim. All rights reserved.
//

#ifndef AlgorithmsAndDataStructures_ConwaysMain_h
#define AlgorithmsAndDataStructures_ConwaysMain_h

void beginConwaysGameOfLife(sf::RenderWindow &);
void init(bool **board, int x, int y);                                              // Initialises an empty board
void rand(bool **board, int x, int y);                                              // Randomises all cells
void buildStamp(std::vector<bool> &stamp, std::string newStamp);                    // Build a stamp from a string of binary
void updateBoard(bool **&board, bool **&calcBoard, bool **&swap,
                 const int &gridX, const int &gridY);                               // Calculate next board state
void resizeBoard(int n, int &gridX, int &gridY, int &gridWidth, int &gridHeight,
                 float &cellWidth, float &cellHeight, sf::RectangleShape &cell);    // Resize the board

#endif
