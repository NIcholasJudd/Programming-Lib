//
//  SpalshScreen.h
//  AlgorithmsAndDataStructures
//
//  Created by Jim Gollop on 7/06/2014.
//  Copyright (c) 2014 Jim. All rights reserved.
//

#include "ResourcePath.hpp"

void beginStackAttack(sf::RenderWindow &window){
    
    // Load background sprite to display
    sf::Texture backgroundSprite;
    if (!backgroundSprite.loadFromFile(resourcePath() + "stackAttackBG.png")) {
        return;
    }
    sf::Sprite background(backgroundSprite);
    
    // Load menu sprites
    sf::Texture playMenuSprite;
    if (!playMenuSprite.loadFromFile(resourcePath() + "playMenu.gif")) {
        return;
    }
    sf::Sprite playMenu(playMenuSprite);
    playMenu.setPosition(sf::Vector2f(630, 214));
    
    sf::Texture editMenuSprite;
    if (!editMenuSprite.loadFromFile(resourcePath() + "editMenu.gif")) {
        return;
    }
    sf::Sprite editMenu(editMenuSprite);
    editMenu.setPosition(sf::Vector2f(630, 214));
    
    
    sf::Texture stackBaseImage;
    if (!stackBaseImage.loadFromFile(resourcePath() + "stackBase.gif")) {
        return;
    }
    sf::Sprite stackBase(stackBaseImage);
    
    sf::Texture stackUpImage;
    if (!stackUpImage.loadFromFile(resourcePath() + "stackUp.gif")) {
        return;
    }
    sf::Sprite stackUp(stackUpImage);
    
    sf::Texture stackDownImage;
    if (!stackDownImage.loadFromFile(resourcePath() + "stackDown.gif")) {
        return;
    }
    sf::Sprite stackDown(stackDownImage);
    
    
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return;
    }
    
    // Variable declaration and initialisation
    
    srand((unsigned int)time(0));
    stackAttackGame game;
    
    game.gameMode = stackAttackGame::PLAY;
    game.init(game.createSolution(5), 3);
    game.setDefaults();
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process keyboard events
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            // Space pressed: Toggle Play/Edit mode
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                if (game.gameMode == stackAttackGame::PLAY) {
                    game.gameMode = stackAttackGame::EDIT;
                } else {
                    game.gameMode = stackAttackGame::PLAY;
                }
            }
            
            // U pressed: Undo last move
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::U) {
                game.undoMove();
            }
            
            // R pressed: Reset game
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
                game.init(game.solution, game.stackCount);
            }
            
            // 0 pressed: Pop from inputStack, push to S1
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num0) {
                if(game.checkMove(0)) {
                    //game.print();
                }
            }
            // 1 pressed: Pop from S1, push to S2
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num1) {
                if(game.checkMove(1)) {
                    //game.print();
                }
            }
            // 2 pressed: Pop from S2, push to S3
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num2) {
                if(game.checkMove(2)) {
                    //game.print();
                }
            }
            // 3 pressed: Pop from S3, push to S4
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num3) {
                if(game.checkMove(3)) {
                    //game.print();
                }
            }
            // 4 pressed: Pop from S4, push to S5
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num4) {
                if(game.checkMove(4)) {
                    //game.print();
                }
            }
            // 5 pressed: Pop from S5, push to S6
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num5) {
                if(game.checkMove(5)) {
                    //game.print();
                }
            }
            // 6 pressed: Pop from S6, push to S7
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num6) {
                if (game.checkMove(6)) {
                    //game.print();
                }
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q) {
                return;
            }
            
            
            // Process mouse events
            if (event.type == sf::Event::MouseButtonPressed) {
                
                // REPLACE THIS LINE WITH A CALL TO BEN'S MAGIC FUNCTION
                sf::Vector2i position = sf::Mouse::getPosition(window);
                sf::Vector2i localPosition = handleMouseClick(position.x, position.y, window);
                //sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                
                if (game.gameMode == stackAttackGame::PLAY) {
                    if (game.b_modeToggle.contains(localPosition)) { // Mode Toggle (PLAY/EDIT)
                        game.gameMode = stackAttackGame::EDIT;
                    } else if (game.b_restart.contains(localPosition)) { // Restart
                        game.init(game.solution, game.stackCount);
                    } else if (game.b_undo.contains(localPosition)) { // Undo
                        game.undoMove();
                    } else if (game.b_input.contains(localPosition)) {
                        if(game.checkMove(0)) {
                            //game.print();
                        }
                    }
                    for (int i = 0; i < game.stackCount; i++) {
                        if (game.b_stack[i].contains(localPosition)) {
                            if(game.checkMove(i+1)) {
                                //game.print();
                            }
                        }
                    }
                } else { // gameMode == EDIT
                    if (game.b_modeToggle.contains(localPosition)) { // Mode Toggle (PLAY/EDIT)
                        game.gameMode = stackAttackGame::PLAY;
                    } else if (game.b_stacksPlus.contains(localPosition) && game.stackCount < game.MAXSTACKCOUNT) {
                        game.stackCount++;
                        game.init(game.solution, game.stackCount);
                        //std::cout << "New stackCount is " << game.stackCount << std::endl;
                        
                    } else if (game.b_stacksMinus.contains(localPosition) && game.stackCount > 1) {
                        game.stackCount--;
                        game.init(game.solution, game.stackCount);
                        //std::cout << "New stackCount is " << game.stackCount << std::endl;
                        
                    } else if (game.b_elemPlus.contains(localPosition) && game.solution.getSize() < 8) {
                        game.init(game.createSolution((int)game.solution.getSize()+1), game.stackCount);
                        //std::cout << "New solution of size " << game.solution.getSize() << std::endl;
                    } else if (game.b_elemMinus.contains(localPosition) && game.solution.getSize() > 1) {
                        game.init(game.createSolution((int)game.solution.getSize()-1), game.stackCount);
                        //std::cout << "New solution of size " << game.solution.getSize() << std::endl;
                    }
                    // Test stack size +/- buttons here
                    for (int i = 0; i < game.stackCount; i++) {
                        if (game.b_stackUp[i].contains(localPosition) && game.currStackSizes[i] < game.MAXSTACKSIZE) {
                            game.currStackSizes[i]++;
                            game.init(game.solution, game.stackCount);
                        } else if (game.b_stackDown[i].contains(localPosition) && game.currStackSizes[i] > 1) {
                            game.currStackSizes[i]--;
                            game.init(game.solution, game.stackCount);
                        }
                    }
                }
            }
        }
        // Clear screen
        window.clear();
        
        // Draw the background sprite
        window.draw(background);
        
        // Draw appropriate menu
        if (game.gameMode == stackAttackGame::PLAY) {
            window.draw(playMenu);
        } else { // gameMode == EDIT
            window.draw(editMenu);
        }
        
        // Draw all stacks
        game.draw(window, font, stackBase, stackUp, stackDown);
        
        // Update the window
        window.display();
    }
}
