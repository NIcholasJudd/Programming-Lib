//
//  StackAttack.h
//  AlgorithmsAndDataStructures
//
//  Created by Jim Gollop on 12/09/2015.
//  Copyright (c) 2015 Jim. All rights reserved.
//

#ifndef AlgorithmsAndDataStructures_StackAttack_h
#define AlgorithmsAndDataStructures_StackAttack_h

void beginStackAttack(sf::RenderWindow &);
void drawQueue(sf::RenderWindow &window, sf::Font &font, std::deque<char> q, int x, int y);
void drawStack(sf::RenderWindow &window, sf::Font &font, std::deque<char> q, int x, int y);
void drawOutput(sf::RenderWindow &window, sf::Font &font, std::deque<char> q, std::deque<char> solution, int x, int y);
void shuffle(std::deque<char> &q);
void init(std::deque<char> &inputQ, std::deque<char> &stack1,
          std::deque<char> &stack2, std::deque<char> &outputQ,
          std::deque<char> &solution, std::deque<char> &undo);

#endif
