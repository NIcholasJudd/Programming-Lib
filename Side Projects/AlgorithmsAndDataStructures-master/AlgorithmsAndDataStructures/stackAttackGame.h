//
//  stackAttackGame.h
//  StackAttack02
//
//  Created by Jim Gollop on 26/09/2015.
//  Copyright (c) 2015 Jim Gollop. All rights reserved.
//

#ifndef __StackAttack02__stackAttackGame__
#define __StackAttack02__stackAttackGame__

#include "ResourcePath.hpp"

class stackAttackGame{
private:

public:
    static const int MAXSTACKCOUNT = 6; // Maximum number of stacks
    static const int MAXSTACKSIZE = 6; // Maximum number of elements per stack
    
    int stackCount = 2; // (2-5)
    std::deque<char> inputStack;
    std::deque<char> stacks[MAXSTACKCOUNT];
    std::deque<char> outputStack;
    std::deque<int> undo;
    sf::String solution;
    int currStackSizes[MAXSTACKCOUNT];
    int currSolutionLength = 0;
    enum mode { PLAY, EDIT };
    mode gameMode = PLAY;
    // Play mode buttons
    sf::IntRect b_modeToggle;
    sf::IntRect b_restart;
    sf::IntRect b_undo;
    sf::IntRect b_input;
    sf::IntRect b_stack[MAXSTACKCOUNT];
    // Edit mode buttons
    sf::IntRect b_stacksMinus;
    sf::IntRect b_stacksPlus;
    sf::IntRect b_elemMinus;
    sf::IntRect b_elemPlus;
    sf::IntRect b_stackUp[MAXSTACKCOUNT];
    sf::IntRect b_stackDown[MAXSTACKCOUNT];
    
    stackAttackGame() {
        b_modeToggle = sf::IntRect(670, 252, 264, 60);
        b_restart = sf::IntRect(670, 321, 264, 60);
        b_undo = sf::IntRect(670, 391, 264, 60);
        b_input = sf::IntRect(578, 38, 447, 160);
        
        b_stacksMinus = sf::IntRect(670, 321, 60, 60);
        b_stacksPlus = sf::IntRect(874, 321, 60, 60);
        b_elemMinus = sf::IntRect(670, 391, 60, 60);
        b_elemPlus = sf::IntRect(874, 391, 60, 60);
        
        for (int i = 0; i < MAXSTACKCOUNT; i++) {
            b_stackUp[i] = sf::IntRect(0, 0, 60, 60);
            b_stackDown[i] = sf::IntRect(0, 0, 60, 60);
            currStackSizes[i] = 3;
        }
    }
    void init(sf::String sol, int sCount); // Initialises the stacks with new solution "sol"
    void setDefaults(); // Applies initial settings for the trade show
    
    void print(); // Outputs to console (debug)
    void draw(sf::RenderWindow &window, sf::Font font, sf::Sprite &stackBase, sf::Sprite &stackUp, sf::Sprite &stackDown); // Draws graphics to window
    bool checkMove(int input); // (0-5) 0:Input, 1:S1, 2:S2, etc 
    void undoMove(); // Undo the last valid move
    void calculateInput(); // Generate valid input from desired output
    sf::String createSolution(int len);
};

#endif /* defined(__StackAttack02__stackAttackGame__) */
