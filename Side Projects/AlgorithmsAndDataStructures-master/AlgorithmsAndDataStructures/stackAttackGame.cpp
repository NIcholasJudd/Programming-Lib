//
//  stackAttackGame.cpp
//  StackAttack02
//
//  Created by Jim Gollop on 26/09/2015.
//  Copyright (c) 2015 Jim Gollop. All rights reserved.
//

#include "stackAttackGame.h"

void stackAttackGame::init(sf::String sol, int sCount) {
    inputStack.clear();
    outputStack.clear();
    for (int i = 0; i < MAXSTACKCOUNT; i++) {
        stacks[i].clear();
    }
    undo.clear();
    solution = sol;
    currSolutionLength = (int)solution.getSize();
    for (int i = 0; i < solution.getSize(); i++) {
        inputStack.push_back(solution[i]);
    }
    stackCount = sCount;
    this->calculateInput();
}

void stackAttackGame::setDefaults() {
    stackCount = 2;
    currStackSizes[0] = 3;
    currStackSizes[1] = 4;
}

void stackAttackGame::print() {
/*    std::cout << "Stack Count: " << stackCount << std::endl;
    for (int i = 0; i < stackCount; i++) {
        std::cout << "S" << i << ": ";
        for (int j = 0; j < stacks[i].size(); j++) {
            std::cout << stacks[i][j];
        }
        std::cout << ", " << stacks[i].size() << " elements" << std::endl;
    }
    std::cout << "Solution: " << solution.toAnsiString() << std::endl;
    std::cout << "Undo: ";
    for (int i = 0; i < undo.size(); i++) {
        std::cout << undo[i];
    }
    std::cout << std::endl;
 */
}

void stackAttackGame::draw(sf::RenderWindow &window, sf::Font font,
                           sf::Sprite &stackBase, sf::Sprite &stackUp, sf::Sprite &stackDown) {
    sf::RectangleShape box(sf::Vector2f(40, 40));
    box.setFillColor(sf::Color(0, 8, 163));
    box.setOutlineThickness(10);
    box.setOutlineColor(sf::Color(0, 8, 163));
    
    // Draw Stack backgrounds
    int stackW = 540;
    int stackXOffset = (stackW/(stackCount+1));
    int stackYOffset = 0;
    for (int i = 0; i < stackCount; i++) {
        for (int j = 0; j < currStackSizes[i]; j++) {
            box.setPosition(stackXOffset+(i*stackXOffset), 500-(j*50));
            window.draw(box);
        }
        // Update hitboxes for stack buttons
        b_stack[i] = sf::IntRect(stackXOffset+(i*stackXOffset)-10, 240, 70, 345);
        // Update hitboxes for stack up/down buttons (Edit mode only)
        b_stackUp[i] = sf::IntRect(stackXOffset+(i*stackXOffset)-10, 160, 60, 60);
        b_stackDown[i] = sf::IntRect(stackXOffset+(i*stackXOffset)-10, 600, 60, 60);
    }
    
    // Draw Stack bases and up/down buttons
    for (int i = 0; i < stackCount; i++) {
        stackBase.setPosition(stackXOffset+(i*stackXOffset)-13, 555);
        window.draw(stackBase);

        if (gameMode == EDIT) {
            stackUp.setPosition(stackXOffset+(i*stackXOffset)-10, 160);
            stackDown.setPosition(stackXOffset+(i*stackXOffset)-10, 600);
            window.draw(stackUp);
            window.draw(stackDown);
        }
    }
    
    // Draw Stack number
    for (int i = 0; i < stackCount; i++) {
        sf::String stackName = "S";
        stackName += std::to_string(i+1);
        sf::Text text(stackName, font, 22);
        text.setColor(sf::Color::White);
        text.setPosition(((i+1)*stackXOffset)+9, 554);
        window.draw(text);
    }
  
    box.setFillColor(sf::Color::Transparent);
    box.setOutlineThickness(3);
    box.setOutlineColor(sf::Color::White);
    
    // Draw Stack blocks
    for (int i = 0; i < stackCount; i++) {
        stackYOffset = (int)(stacks[i].size()-1)*(-50);
        for (int j = (int)stacks[i].size()-1; j >= 0; j--) {
            box.setPosition(stackXOffset+(i*(stackW/(stackCount+1))), stackYOffset+500+(j*50));
            window.draw(box);
            sf::Text text(stacks[i][j], font, 32);
            text.setColor(sf::Color::White);
            text.setPosition(7+stackXOffset+(i*(stackW/(stackCount+1))), stackYOffset+500+(j*50));
            window.draw(text);
        }
    }
    
    // Draw Input
    for (int i = 0; i < inputStack.size(); i++) {
        box.setPosition(610+(i*50), 100);
        window.draw(box);
        sf::Text text(inputStack[i], font, 32);
        text.setColor(sf::Color::White);
        text.setPosition(617+(i*50), 100);
        window.draw(text);
    }
    
    // Draw Solution
    for (int i = 0; i < solution.getSize(); i++) {
        box.setPosition(610+(i*50), 700);
        window.draw(box);
        sf::Text text(solution[i], font, 32);
        text.setColor(sf::Color::White);
        text.setPosition(617+(i*50), 700);
        window.draw(text);
    }
    
    // Draw Output
    for (int i = 0; i < outputStack.size(); i++) {
        box.setPosition(610+(i*50), 620);
        if (outputStack[i] == solution[i]) {
            box.setOutlineColor(sf::Color::Green);
        } else {
            box.setOutlineColor(sf::Color::Red);
        }
        window.draw(box);
        sf::Text text(outputStack[i], font, 32);

        text.setPosition(617+(i*50), 620);
        text.setColor(sf::Color::White);
        window.draw(text);
    }
}

bool stackAttackGame::checkMove(int input) {
    if (input > stackCount) {
        //std::cerr << "Value exceeds number of stacks in use" << std::endl;
        return false;
    } else if (input == 0) { // Push from input to S1
        if (!(inputStack.empty()) && stacks[0].size() < currStackSizes[0]) {
            stacks[0].push_front(inputStack.front());
            inputStack.pop_front();
            undo.push_back(input);
            return true;
        }
    } else if (input == stackCount) { // Push from Sn to output
        if (!(stacks[input-1].empty())) { // Don't need to test for space in output stack
            outputStack.push_back(stacks[input-1].front());
            stacks[input-1].pop_front();
            undo.push_back(input);
            return true;
        }
    } else { // Handles S1 to S(n-1)
        if (!(stacks[input-1].empty()) && stacks[input].size() < currStackSizes[input]) {
            stacks[input].push_front(stacks[input-1].front());
            stacks[input-1].pop_front();
            undo.push_back(input);
            return true;
        }
    }
    return false;
}

void stackAttackGame::undoMove() {
    if (undo.size() == 0) {
        //std::cerr << "There's nothing to undo!\n";
        return;
    } else {
        int temp = undo.back();
        //std::cout << "Last move was " << temp << std::endl;
        if (temp == 0) {
            // Push from S1 to Input
            inputStack.push_front(stacks[0].front());
            stacks[0].pop_front();
        } else if (temp == stackCount) {
            // Push from Output to stacks[stackCount]
            stacks[temp-1].push_front(outputStack.back());
            outputStack.pop_back();
        } else {
            // Push from S[temp] to S[temp-1]
            stacks[temp-1].push_front(stacks[temp].front());
            stacks[temp].pop_front();
        }
        undo.pop_back();
    }
}

void stackAttackGame::calculateInput() {
    outputStack = inputStack;
    inputStack.clear();
    std::vector<int> nextMove;
    //std::cout << "Solution Size: " << solution.getSize() << std::endl;
    //std::cout << "Input Size: " << inputStack.size() << std::endl;
    
    while (inputStack.size() != solution.getSize()) {
        // Build vector of valid moves
        nextMove.clear();
        if (!stacks[0].empty()) { // If S1 contains anything, S1->Input is valid
            nextMove.push_back(0);
        }
        if (!outputStack.empty() && stacks[stackCount-1].size() < currStackSizes[stackCount-1]) { // If there is still output and Sn has space, Output->Sn is valid (denoted by -1)
            nextMove.push_back(-1);
        }
        for (int i = 1; i < stackCount; i++) { //If Si contains anything and S(i-1) has space, Si->S(i-1) is valid
            if (!(stacks[i].empty()) && (stacks[i-1].size() < currStackSizes[i-1])) {
                nextMove.push_back(i);
            }
        }
        //std::cout << "nextMove: ";
        //for (int i = 0; i < nextMove.size(); i++) {
        //    std::cout << nextMove[i];
        //}
        //std::cout << std::endl;

        // Select move
        int move = nextMove[(std::rand()%nextMove.size())];
        //std::cout << "chosen move: " << move << std::endl;
    
        // Enact move
        if (move == -1) { // Output->Sn
            //std::cout << "Moving '" << outputStack.back() << "' from outputStack to S" << stackCount-1 << std::endl;
            stacks[stackCount-1].push_front(outputStack.back());
            outputStack.pop_back();
        } else if (move == 0) { // S1->Input
            //std::cout << "Moving '" << stacks[0].front() << "' from S0 to inputStack" << std::endl;
            inputStack.push_front(stacks[0].front());
            stacks[0].pop_front();
        } else { // Si->S(i-1)
            //std::cout << "Moving '" << stacks[move].front() << "' from S" << move << " to S" << move-1 << std::endl;
            stacks[move-1].push_front(stacks[move].front());
            stacks[move].pop_front();
        }
    }
}

sf::String stackAttackGame::createSolution(int len) {
    sf::String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    sf::String newSolution = "";
    for (int i = 0; i < len; i++) {
        newSolution += alphabet[i];
    }
    //std::cout << "Returning: " << newSolution.toAnsiString() << std::endl;
    return newSolution;
}