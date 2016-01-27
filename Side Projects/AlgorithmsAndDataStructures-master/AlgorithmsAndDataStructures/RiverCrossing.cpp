//
//  RiverCrossing.cpp
//  River Crossing
//
//  Created by Peter Mavridis on 2/10/2015.
//  Copyright (c) 2015 Peter Mavridis. All rights reserved.
//

#include "ResourcePath.hpp"

void RiverLoop(sf::RenderWindow &window){
    
    sf::Clock cloud_clock;
    bool show = false;                                                                                                          // Used to show the all possible states screen.
    bool gameState = true;
    std::pair<int, int> highlight_coords;
    // In the order of boat, carrot, goat and wolf.
    int currentPosition[4] = {0,0,0,0};
    
    
    // Array used to show who is on the boat.
    // Represented as carrot, goat and wolf.
    bool onBoat[3] = {0,0,0};
    
    int cloud_x = 0;
    // Create the main window
    //static sf::RenderWindow window(sf::VideoMode(1024, 768), "Farmer Problems");
    
    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        exit(1);
    }
    //window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        exit(1);
    }
    
    // Declarations of the images to be used.
    sf::Texture backgroundImage;                                         // Background.
    sf::Texture boatIconImage;                                           // The boat image.
    sf::Texture goatImage;                                               // The goat image.
    sf::Texture goatImageRed;                                            // The red goat image.
    sf::Texture wolfImage;                                               // The wolf image.
    sf::Texture wolfImageRed;                                            // The red wolf image.
    sf::Texture carrotImage;                                             // The carrot image.
    sf::Texture carrotImageRed;                                          // The red carrot image.
    sf::Texture boatImageRight;                                          // The right pointing boat button.
    sf::Texture boatImageLeft;                                           // The left pointing boat button.
    sf::Texture boatMove;                                                // The boat image.
    sf::Texture statesImage;                                             // The state screen image.
    sf::Texture game;                                                    // The game over image.
    sf::Texture state_highlight_image;                                   // The image used to highlight current state.
    sf::Texture rolling_clouds;                                          // The image for the clouds.
    
    
    // Load the resource files.
    if (!rolling_clouds.loadFromFile(resourcePath()+ "CloudsLoop.png")) {
        exit(1);
    }
    if (!state_highlight_image.loadFromFile(resourcePath()+ "river_ttHighlight.png")) {
        exit(1);
    }
    
    if (!backgroundImage.loadFromFile(resourcePath() + "RiverCrossingTempBack.gif")) {
        exit(1);
    }
    
    if (!carrotImage.loadFromFile(resourcePath() + "river_icon_carrot.png")) {
        exit(1);
    }
    
    if (!carrotImageRed.loadFromFile(resourcePath() + "river_icon_carrotR.png")) {
        exit(1);
    }
    
    if (!goatImage.loadFromFile(resourcePath() + "river_icon_goat.png")) {
        exit(1);
    }
    
    if (!goatImageRed.loadFromFile(resourcePath() + "river_icon_goatR.png")) {
        exit(1);
    }
    
    if (!wolfImage.loadFromFile(resourcePath() + "river_icon_wolf.png")) {
        exit(1);
    }
    
    if (!wolfImageRed.loadFromFile(resourcePath() + "river_icon_wolfR.png")) {
        exit(1);
    }
    
    if (!boatIconImage.loadFromFile(resourcePath() + "river_icon_boat.png")) {
        exit(1);
    }
    
    if (!boatImageLeft.loadFromFile(resourcePath() + "river_icon_boatLeft.png")) {
        exit(1);
    }
    
    if (!boatImageRight.loadFromFile(resourcePath() + "river_icon_boatRight.png")) {
        exit(1);
    }
    
    if (!boatMove.loadFromFile(resourcePath() + "river_boat.png")) {
        exit(1);
    }
    
    if (!statesImage.loadFromFile(resourcePath() + "river_truthTable.png")) {
        exit(1);
    }
    if (!game.loadFromFile(resourcePath() + "gameOver.jpg")) {
        exit(1);
    }
    
    // Load the images.
    sf::Sprite background(backgroundImage);                                    // Laod the backround image.
    sf::Sprite boatIconLeft(boatImageLeft);                                    // Load the left boat icon.
    sf::Sprite boatIconRight(boatImageRight);                                  // Load the right boat icon.
    sf::Sprite carrot(carrotImage);                                            // Load the carrot image.
    sf::Sprite carrotRed(carrotImageRed);                                      // Load red carrot image.
    sf::Sprite goat(goatImage);                                                // Load the goat image.
    sf::Sprite goatRed(goatImageRed);                                          // Load the red goat.
    sf::Sprite wolf(wolfImage);                                                // Load the wolf image.
    sf::Sprite wolfRed(wolfImageRed);                                          // Load the red wolf.
    sf::Sprite boat(boatMove);                                                 // Load the boat image.
    sf::Sprite states(statesImage);                                            // Load the all possible states image.
    sf::Sprite gameOver(game);                                                 // Load the game over image.
    sf::Sprite state_highlight(state_highlight_image);                         // Load the current state image used for highlighting.
    sf::Sprite clouds(rolling_clouds);                                         // Load the clouds image.
    
    // Set the positions and scale of the images.
    carrot.setPosition(30, 30);
    goat.setPosition(30, 160);
    wolf.setPosition(30, 290);
    carrotRed.setPosition(30, 30);
    goatRed.setPosition(30, 160);
    wolfRed.setPosition(30, 290);
    boatIconLeft.setPosition(462, 30);
    boatIconRight.setPosition(462, 30);
    boat.setPosition(280, 530);
    states.setPosition(283, 164);
    clouds.setPosition(1024, 120);
    
    bool left_right_boat = true;
    // Bounding boxes of where images are. Used for mouse clicks.
    sf::IntRect carrot_bound_box_left(30,30,100,100);
    sf::IntRect carrot_bound_box_right(894,30,100,100);
    sf::IntRect goat_bound_box_left(30,160,100,100);
    sf::IntRect goat_bound_box_right(894,160,100,100);
    sf::IntRect wolf_bound_box_left(30,290,100,100);
    sf::IntRect wolf_bound_box_right(894,290,100,100);
    sf::IntRect boatIcon_bound_box(462,30,100,100);
    sf::IntRect moved_to_boat_bound(462,160,100,100);
    
    sf::Clock clock;
    sf::Time boat_move_time = sf::seconds(1.50f);
    
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q) {
                return;
            }
            // Space pressed: shows and hides the state screen.
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                showStates(show);
            }
            if (gameState == true) {
               
                
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    sf::Vector2i windowPosition = sf::Mouse::getPosition(window);
                    sf::Vector2i localPosition = handleMouseClick(windowPosition.x, windowPosition.y, window);
                    // Move carrot from left side to boat.
                    if (carrot_bound_box_left.contains(localPosition) && isAnythingOnBoat(onBoat) == false) {
                        onBoat[0] = 1;
                        moveImageToBoat(window, carrot);
                    }
                    // Move carrot from right side to boat.
                    if (carrot_bound_box_right.contains(localPosition) && isAnythingOnBoat(onBoat) == false) {
                        onBoat[0] = 1;
                        moveImageToBoat(window, carrot);
                    }
                    // Move goat from left side to boat.
                    if (goat_bound_box_left.contains(localPosition) && isAnythingOnBoat(onBoat) == false) {
                        onBoat[1] = 1;
                        moveImageToBoat(window, goat);
                    }
                    // Move goat from right side to boat.
                    if (goat_bound_box_right.contains(localPosition) && isAnythingOnBoat(onBoat) == false) {
                        onBoat[1] = 1;
                        moveImageToBoat(window, goat);
                    }
                    // Move wolf from left side to boat.
                    if (wolf_bound_box_left.contains(localPosition) && isAnythingOnBoat(onBoat) == false) {
                        onBoat[2] = 1;
                        moveImageToBoat(window, wolf);
                    }
                    // Move wolf from right side to boat.
                    if (wolf_bound_box_right.contains(localPosition) && isAnythingOnBoat(onBoat) == false) {
                        onBoat[2] = 1;
                        moveImageToBoat(window, wolf);
                    }
                    if (boatIcon_bound_box.contains(localPosition)) {
                        moveBoat(window, boat, left_right_boat, boat_move_time, clock, currentPosition, gameState, onBoat, carrot, goat, wolf, carrotRed, show, boatIconRight, boatIconLeft, goatRed, wolfRed, background, gameOver, states, state_highlight, clouds, cloud_x);
                        if (boat.getPosition().x == 599) {
                            moveToRightBank(window, boat, left_right_boat, boat_move_time, clock, currentPosition, gameState, onBoat, carrot, goat, wolf, carrotRed, show, boatIconRight, boatIconLeft, goatRed, wolfRed, background, gameOver, states, state_highlight, clouds, cloud_x);
                        }
                        if (boat.getPosition().x == 280) {
                            moveToleftBank(window, boat, left_right_boat, boat_move_time, clock, currentPosition, gameState, onBoat, carrot, goat, wolf, carrotRed, show, boatIconRight, boatIconLeft, goatRed, wolfRed, background, gameOver, states, state_highlight, clouds, cloud_x);
                        }
                        gameState = true;
                    }
                    
                    if (moved_to_boat_bound.contains(localPosition) && isAnythingOnBoat(onBoat)) {
                        if (boat.getPosition().x < 599) {
                            moveToleftBank(window, boat, left_right_boat, boat_move_time, clock, currentPosition, gameState, onBoat, carrot, goat, wolf, carrotRed, show, boatIconRight, boatIconLeft, goatRed, wolfRed, background, gameOver, states, state_highlight, clouds,cloud_x);
                        }else moveToRightBank(window, boat, left_right_boat, boat_move_time, clock, currentPosition, gameState, onBoat, carrot, goat, wolf, carrotRed, show, boatIconRight, boatIconLeft, goatRed, wolfRed, background, gameOver, states, state_highlight, clouds, cloud_x);
                    }
                }
            }
            updateHighlight(highlight_coords, currentPosition);
            state_highlight.setPosition(highlight_coords.first, highlight_coords.second);
            renderScreen(window, carrot, goat, wolf, carrotRed, goatRed, wolfRed, boat, background, gameOver, boatIconRight, boatIconLeft, currentPosition, states, left_right_boat, show, gameState, onBoat, state_highlight, clouds);
        }
        if (cloud_clock.getElapsedTime().asMilliseconds() >= 40) {
            rollingClouds(window, cloud_x);
            clouds.setPosition(cloud_x, clouds.getPosition().y);
            renderScreen(window, carrot, goat, wolf, carrotRed, goatRed, wolfRed, boat, background, gameOver, boatIconRight, boatIconLeft, currentPosition, states, left_right_boat, show, gameState, onBoat, state_highlight, clouds);
            cloud_clock.restart();
        }
    }
}

// Called to update the screen.
void renderScreen(sf::RenderWindow &window, sf::Sprite &carrot, sf::Sprite &goat, sf::Sprite &wolf, sf::Sprite &carrotRed, sf::Sprite &goatRed, sf::Sprite &wolfRed, sf::Sprite &boat, sf::Sprite &background, sf::Sprite &gameOver, sf::Sprite &boatIconRight, sf::Sprite &boatIconLeft, int currentPosition[], sf::Sprite &states, bool &left_right_boat, bool &show, bool &gameState, bool onBoat[], sf::Sprite &state_highlight, sf::Sprite &clouds){
    // Clear screen
    window.clear();
    
    // Draw the background
    window.draw(background);
    window.draw(clouds);
    // Draw the images.
    if (isAnythingOnBoat(onBoat) == true) {
        window.draw(carrot);
        window.draw(goat);
        window.draw(wolf);
    }
    if (isAnythingOnBoat(onBoat) == false) {
        window.draw(carrot);
        window.draw(goat);
        window.draw(wolf);
        if (checkMove(window, currentPosition) == true){
            window.draw(carrotRed);
            window.draw(goatRed);
            window.draw(wolfRed);
            gameFinished(window, gameOver, gameState);
        }
    }
    
    if (left_right_boat == true) {
        window.draw(boatIconRight);
    }else window.draw(boatIconLeft);
    
    window.draw(boat);
    if (show == true) {
        window.draw(states);
        window.draw(state_highlight);
    }
    // Update the window
    window.display();
}

void rollingClouds(sf::RenderWindow & window, int &x) {
    x--;
    if (x == -1024) {
        x = 0;
    }
}

// Highlights the current state of the game.
void updateHighlight(std::pair<int, int> &highlight_coords, int currentPosition[]) {
    int z;
    z = (currentPosition[0] * 8) + (currentPosition[1] * 4) + (currentPosition[2] * 2) + currentPosition[3];    // Finds the currrent state of the game.
    highlight_coords.first = ((z/8) * 220) + 324;
    highlight_coords.second = ((z%8) * 40) + 246;
}

// Boat carrot goat wolf.
// Validates the current state of the game.
bool checkMove(sf::RenderWindow &window, int currentPosition[]){
    if (currentPosition[0] != currentPosition[2] && (currentPosition[1] == currentPosition[2] || currentPosition[2] == currentPosition[3])){
        return true;
    }else return false;
}

// Move whats on the boat to the left bank.
void moveToleftBank(sf::RenderWindow &window, sf::Sprite &boat, bool &left_right_boat, sf::Time &boat_move_time, sf::Clock &clock, int currentPosition[], bool &gameState, bool onBoat[], sf::Sprite &carrot, sf::Sprite &goat, sf::Sprite &wolf, sf::Sprite &carrotRed, bool &show, sf::Sprite &boatIconRight, sf::Sprite &boatIconLeft, sf::Sprite &goatRed, sf::Sprite &wolfRed, sf::Sprite &background, sf::Sprite &gameOver, sf::Sprite &states, sf::Sprite &state_highlight, sf::Sprite &clouds, int &cloud_x){
    
    sf::Clock cloud_clock;
    int i = 462;                                    // Used to move images from boat to left bank horizantally.
    float j = 0.31;                                 // Used to move images from boat to left bank virtically.
    float move_time = 0.1;                          // Used to set the speed of the animation.
    // Moves the carrot.
    if (onBoat[0] == 1) {
        while (carrot.getPosition().x != 30) {
            if (clock.getElapsedTime().asMilliseconds() >= move_time) {
                carrot.setPosition(i, carrot.getPosition().y);
                if (carrot.getPosition().y != 30) {
                    carrot.setPosition(carrot.getPosition().x, carrot.getPosition().y - j);
                    if (cloud_clock.getElapsedTime().asMilliseconds() >= 40) {
                        rollingClouds(window, cloud_x);
                        clouds.setPosition(cloud_x, clouds.getPosition().y);
                        renderScreen(window, carrot, goat, wolf, carrotRed, goatRed, wolfRed, boat, background, gameOver, boatIconRight, boatIconLeft, currentPosition, states, left_right_boat, show, gameState, onBoat, state_highlight, clouds);
                        cloud_clock.restart();
                    }
                }
                renderScreen(window, carrot, goat, wolf, carrotRed, goatRed, wolfRed, boat, background, gameOver, boatIconRight, boatIconLeft, currentPosition, states, left_right_boat, show, gameState, onBoat, state_highlight, clouds);
                i--;
                clock.restart();
            }
        }
        carrotRed.setPosition(carrot.getPosition().x, carrot.getPosition().y); // Sets the red carrot to where the last position of the blue carrot was.
        onBoat[0] = 0;
        currentPosition[1] = 0;
    }
    // Moves the goat.
    if (onBoat[1] == 1) {
        while (goat.getPosition().x != 30) {
            if (clock.getElapsedTime().asMilliseconds() >= move_time) {
                goat.setPosition(i, 160);
                renderScreen(window, carrot, goat, wolf, carrotRed, goatRed, wolfRed, boat, background, gameOver, boatIconRight, boatIconLeft, currentPosition, states, left_right_boat, show, gameState, onBoat, state_highlight, clouds);
                if (cloud_clock.getElapsedTime().asMilliseconds() >= 40) {
                    rollingClouds(window, cloud_x);
                    clouds.setPosition(cloud_x, clouds.getPosition().y);
                    renderScreen(window, carrot, goat, wolf, carrotRed, goatRed, wolfRed, boat, background, gameOver, boatIconRight, boatIconLeft, currentPosition, states, left_right_boat, show, gameState, onBoat, state_highlight, clouds);
                    cloud_clock.restart();
                }
                i--;
                clock.restart();
            }
        }
        goatRed.setPosition(goat.getPosition().x, goat.getPosition().y); // Sets the red goat to where the last position of the blue goat was.
        onBoat[1] = 0;
        currentPosition[2] = 0;
    }
    // Moves the wolf.
    if (onBoat[2] == 1) {
        while (wolf.getPosition().x != 30) {
            if (clock.getElapsedTime().asMilliseconds() >= move_time) {
                wolf.setPosition(i, wolf.getPosition().y);
                if (wolf.getPosition().y != 290) {
                    wolf.setPosition(wolf.getPosition().x, wolf.getPosition().y + j);
                    if (cloud_clock.getElapsedTime().asMilliseconds() >= 40) {
                        rollingClouds(window, cloud_x);
                        clouds.setPosition(cloud_x, clouds.getPosition().y);
                        renderScreen(window, carrot, goat, wolf, carrotRed, goatRed, wolfRed, boat, background, gameOver, boatIconRight, boatIconLeft, currentPosition, states, left_right_boat, show, gameState, onBoat, state_highlight, clouds);
                        cloud_clock.restart();
                    }
                }
                renderScreen(window, carrot, goat, wolf, carrotRed, goatRed, wolfRed, boat, background, gameOver, boatIconRight, boatIconLeft, currentPosition, states, left_right_boat, show, gameState, onBoat, state_highlight, clouds);
                i--;
                clock.restart();
            }
        }
        wolfRed.setPosition(wolf.getPosition().x, wolf.getPosition().y); // Sets the red wolf to where the last position of the blue wolf was.
        onBoat[2] = 0;
        currentPosition[3] = 0;
    }
}

// Move whats on the boat to the right bank.
void moveToRightBank(sf::RenderWindow &window, sf::Sprite &boat, bool &left_right_boat, sf::Time &boat_move_time, sf::Clock &clock, int currentPosition[], bool &gameState, bool onBoat[], sf::Sprite &carrot, sf::Sprite &goat, sf::Sprite &wolf, sf::Sprite &carrotRed, bool &show, sf::Sprite &boatIconRight, sf::Sprite &boatIconLeft, sf::Sprite &goatRed, sf::Sprite &wolfRed, sf::Sprite &background, sf::Sprite &gameOver, sf::Sprite &states, sf::Sprite &state_highlight, sf::Sprite &clouds, int &cloud_x){
    
    sf::Clock cloud_clock;
    int i = 462; // Used to move images horizontal.
    float j = 0.31; // Used to move images virtcal.
    float move_time = 0.1; // Used to set the speed of the animation.
    // Moves the carrot.
    if (onBoat[0] == 1) {
        while (carrot.getPosition().x != 894) {
            if (clock.getElapsedTime().asMilliseconds() >= move_time) {
                carrot.setPosition(i, carrot.getPosition().y); // Moves carrot horizontal.
                if (carrot.getPosition().y != 30) { // Moves carrot verticle.
                    carrot.setPosition(carrot.getPosition().x, carrot.getPosition().y - j);
                    if (cloud_clock.getElapsedTime().asMilliseconds() >= 40) {
                        rollingClouds(window, cloud_x);
                        clouds.setPosition(cloud_x, clouds.getPosition().y);
                        renderScreen(window, carrot, goat, wolf, carrotRed, goatRed, wolfRed, boat, background, gameOver, boatIconRight, boatIconLeft, currentPosition, states, left_right_boat, show, gameState, onBoat, state_highlight, clouds);
                        cloud_clock.restart();
                    }
                }
                renderScreen(window, carrot, goat, wolf, carrotRed, goatRed, wolfRed, boat, background, gameOver, boatIconRight, boatIconLeft, currentPosition, states, left_right_boat, show, gameState, onBoat, state_highlight, clouds);
                i++;
                clock.restart();
            }
        }
        carrotRed.setPosition(carrot.getPosition().x, carrot.getPosition().y); // Sets the red carrot to where the last position of the blue carrot was.
        onBoat[0] = 0;
        currentPosition[1] = 1;
    }
    // Moves the goat.
    if (onBoat[1] == 1) {
        while (goat.getPosition().x != 894) {
            if (clock.getElapsedTime().asMilliseconds() >= move_time) {
                goat.setPosition(i, 160);
                renderScreen(window, carrot, goat, wolf, carrotRed, goatRed, wolfRed, boat, background, gameOver, boatIconRight, boatIconLeft, currentPosition, states, left_right_boat, show, gameState, onBoat, state_highlight, clouds);
                if (cloud_clock.getElapsedTime().asMilliseconds() >= 40) {
                    rollingClouds(window, cloud_x);
                    clouds.setPosition(cloud_x, clouds.getPosition().y);
                    renderScreen(window, carrot, goat, wolf, carrotRed, goatRed, wolfRed, boat, background, gameOver, boatIconRight, boatIconLeft, currentPosition, states, left_right_boat, show, gameState, onBoat, state_highlight, clouds);
                    cloud_clock.restart();
                }
                i++;
                clock.restart();
            }
        }
        goatRed.setPosition(goat.getPosition().x, goat.getPosition().y); // Sets the red goat to where the last position of the blue goat was.
        onBoat[1] = 0;
        currentPosition[2] = 1;
    }
    // Moves the wolf.
    if (onBoat[2] == 1) {
        while (wolf.getPosition().x != 894) {
            if (clock.getElapsedTime().asMilliseconds() >= move_time) {
                wolf.setPosition(i, wolf.getPosition().y);
                if (wolf.getPosition().y != 290) {
                    wolf.setPosition(wolf.getPosition().x, wolf.getPosition().y + j);
                    if (cloud_clock.getElapsedTime().asMilliseconds() >= 40) {
                        rollingClouds(window, cloud_x);
                        clouds.setPosition(cloud_x, clouds.getPosition().y);
                        renderScreen(window, carrot, goat, wolf, carrotRed, goatRed, wolfRed, boat, background, gameOver, boatIconRight, boatIconLeft, currentPosition, states, left_right_boat, show, gameState, onBoat, state_highlight, clouds);
                        cloud_clock.restart();
                    }
                }
                renderScreen(window, carrot, goat, wolf, carrotRed, goatRed, wolfRed, boat, background, gameOver, boatIconRight, boatIconLeft, currentPosition, states, left_right_boat, show, gameState, onBoat, state_highlight, clouds);
                i++;
                clock.restart();
            }
        }
        wolfRed.setPosition(wolf.getPosition().x, wolf.getPosition().y); // Sets the red wolf to where the last position of the blue wolf was.
        onBoat[2] = 0;
        currentPosition[3] = 1;
    }
}

// Show all the states when spacebar pressed.
bool showStates(bool &show) {
    if (show) {
        return show = false;
    }else return show = true;
}
// Move image to the boat either from the left or right side.
void moveImageToBoat(sf::RenderWindow &window, sf::Sprite &image) {
    image.setPosition(462, 160);
}



// Moves the boat either from the right or left side.
void moveBoat(sf::RenderWindow &window, sf::Sprite &boat, bool &left_right_boat, sf::Time &boat_move_time, sf::Clock &clock, int currentPosition[], bool &gameState, bool onBoat[], sf::Sprite &carrot, sf::Sprite &goat, sf::Sprite &wolf, sf::Sprite &carrotRed, bool &show, sf::Sprite &boatIconRight, sf::Sprite &boatIconLeft, sf::Sprite &goatRed, sf::Sprite &wolfRed, sf::Sprite &background, sf::Sprite &gameOver, sf::Sprite &states, sf::Sprite &state_highlight_image, sf::Sprite &clouds, int &cloud_x) {

    sf::Clock cloud_clock;
    sf::Clock boat_upDown_motion;                           // Used for the motion of the boat.
    gameState = false;                                      // Used to stop input during animation to avoid further interaction with the game.
    int left_right = 280;                                   // Used to move the boat left to right.
    int right_left = 599;                                   // Used to move the boat right to left.
    int convex = boat.getPosition().y - 10;                 // The peak of the curve.
    int concave = boat.getPosition().y + 10;                // The trough of the curve.
    int water_level = boat.getPosition().y;                 // The sea level at which the boat begins and ends.
    bool up_down = false;                                   // To switch between going up or down the wave and rocking back and forward.
    // Moves boat from left to right side.
    if (left_right_boat == true) {
        if (isAnythingOnBoat(onBoat) == false) {
            return;
        }
        
        while (boat.getPosition().x != 599) {
            if (cloud_clock.getElapsedTime().asMilliseconds() >= 40) {  // Clouds scrolling.
                rollingClouds(window, cloud_x);
                clouds.setPosition(cloud_x, clouds.getPosition().y);
                renderScreen(window, carrot, goat, wolf, carrotRed, goatRed, wolfRed, boat, background, gameOver, boatIconRight, boatIconLeft, currentPosition, states, left_right_boat, show, gameState, onBoat, state_highlight_image, clouds);
                cloud_clock.restart();
            }
            if (clock.getElapsedTime().asMilliseconds() >= 3) { // Makes boat move across the river.
                boat.setPosition(left_right, water_level);
                if (cloud_clock.getElapsedTime().asMilliseconds() >= 40) { // Clouds scrolling.
                    rollingClouds(window, cloud_x);
                    clouds.setPosition(cloud_x, clouds.getPosition().y);
                    renderScreen(window, carrot, goat, wolf, carrotRed, goatRed, wolfRed, boat, background, gameOver, boatIconRight, boatIconLeft, currentPosition, states, left_right_boat, show, gameState, onBoat, state_highlight_image, clouds);
                    cloud_clock.restart();
                }
                renderScreen(window, carrot, goat, wolf, carrotRed, goatRed, wolfRed, boat, background, gameOver, boatIconRight, boatIconLeft, currentPosition, states, left_right_boat, show, gameState, onBoat, state_highlight_image, clouds);
                left_right++;
                if (boat_upDown_motion.getElapsedTime().asMilliseconds() >= 15) { // Makes the boat bounce up and down and rocking back and forward.
                    if (up_down == false) {
                        if (water_level > convex) {
                            water_level -= 1;
                            if (cloud_clock.getElapsedTime().asMilliseconds() >= 40) { // Clouds scrolling.
                                rollingClouds(window, cloud_x);
                                clouds.setPosition(cloud_x, clouds.getPosition().y);
                                renderScreen(window, carrot, goat, wolf, carrotRed, goatRed, wolfRed, boat, background, gameOver, boatIconRight, boatIconLeft, currentPosition, states, left_right_boat, show, gameState, onBoat, state_highlight_image, clouds);
                                cloud_clock.restart();
                            }
                        }
                            renderScreen(window, carrot, goat, wolf, carrotRed, goatRed, wolfRed, boat, background, gameOver, boatIconRight, boatIconLeft, currentPosition, states, left_right_boat, show, gameState, onBoat, state_highlight_image, clouds);
                            boat_upDown_motion.restart();
                            if (water_level == convex) {
                                up_down = true;
                            }
                    }
                    if (up_down == true){
                        if (water_level < concave) {
                            water_level += 1;
                            if (cloud_clock.getElapsedTime().asMilliseconds() >= 40) { // Clouds scrolling.
                                rollingClouds(window, cloud_x);
                                clouds.setPosition(cloud_x, clouds.getPosition().y);
                                renderScreen(window, carrot, goat, wolf, carrotRed, goatRed, wolfRed, boat, background, gameOver, boatIconRight, boatIconLeft, currentPosition, states, left_right_boat, show, gameState, onBoat, state_highlight_image, clouds);
                                cloud_clock.restart();
                            }
                            boat_upDown_motion.restart();
                            if (water_level == concave) {
                                up_down = false;
                            }
                        }
                    }
                }
                clock.restart();
            }
        }
        left_right_boat = false;
        currentPosition[0] = 1;
        boat.setPosition(599, 530);
        boat.setRotation(0);
    }
    
    // Moves boat from right to left side.
    else if (left_right_boat == false) {
        while (boat.getPosition().x != 280) {
            if (cloud_clock.getElapsedTime().asMilliseconds() >= 40) { // Clouds Scrolling.
                rollingClouds(window, cloud_x);
                clouds.setPosition(cloud_x, clouds.getPosition().y);
                renderScreen(window, carrot, goat, wolf, carrotRed, goatRed, wolfRed, boat, background, gameOver, boatIconRight, boatIconLeft, currentPosition, states, left_right_boat, show, gameState, onBoat, state_highlight_image, clouds);
                cloud_clock.restart();
            }
            if (clock.getElapsedTime().asMilliseconds() >= 3) {
                if (cloud_clock.getElapsedTime().asMilliseconds() >= 40) { // Clouds Scrolling.
                    rollingClouds(window, cloud_x);
                    clouds.setPosition(cloud_x, clouds.getPosition().y);
                    renderScreen(window, carrot, goat, wolf, carrotRed, goatRed, wolfRed, boat, background, gameOver, boatIconRight, boatIconLeft, currentPosition, states, left_right_boat, show, gameState, onBoat, state_highlight_image, clouds);
                    cloud_clock.restart();
                }
                boat.setPosition(right_left, water_level);
                renderScreen(window, carrot, goat, wolf, carrotRed, goatRed, wolfRed, boat, background, gameOver, boatIconRight, boatIconLeft, currentPosition, states, left_right_boat, show, gameState, onBoat, state_highlight_image, clouds);
                right_left--;
                if (boat_upDown_motion.getElapsedTime().asMilliseconds() >= 15) { // Makes the boat bounce up and down and rocking back and forward.
                    if (up_down == false) {
                        if (water_level > convex) {
                            water_level -= 1;
                            if (cloud_clock.getElapsedTime().asMilliseconds() >= 40) { // Clouds Scrolling.
                                rollingClouds(window, cloud_x);
                                clouds.setPosition(cloud_x, clouds.getPosition().y);
                                renderScreen(window, carrot, goat, wolf, carrotRed, goatRed, wolfRed, boat, background, gameOver, boatIconRight, boatIconLeft, currentPosition, states, left_right_boat, show, gameState, onBoat, state_highlight_image, clouds);
                                cloud_clock.restart();
                            }
                            renderScreen(window, carrot, goat, wolf, carrotRed, goatRed, wolfRed, boat, background, gameOver, boatIconRight, boatIconLeft, currentPosition, states, left_right_boat, show, gameState, onBoat, state_highlight_image, clouds);
                            boat_upDown_motion.restart();
                            if (water_level == convex) {
                                up_down = true;
                            }
                        }
                    }
                    if (up_down == true){
                        if (water_level < concave) {
                            water_level += 1;
                            if (cloud_clock.getElapsedTime().asMilliseconds() >= 40) { // Clouds Scrolling.
                                rollingClouds(window, cloud_x);
                                clouds.setPosition(cloud_x, clouds.getPosition().y);
                                renderScreen(window, carrot, goat, wolf, carrotRed, goatRed, wolfRed, boat, background, gameOver, boatIconRight, boatIconLeft, currentPosition, states, left_right_boat, show, gameState, onBoat, state_highlight_image, clouds);
                                cloud_clock.restart();
                            }
                            renderScreen(window, carrot, goat, wolf, carrotRed, goatRed, wolfRed, boat, background, gameOver, boatIconRight, boatIconLeft, currentPosition, states, left_right_boat, show, gameState, onBoat, state_highlight_image, clouds);
                            boat_upDown_motion.restart();
                            if (water_level == concave) {
                                up_down = false;
                            }
                        }
                    }
                }
                clock.restart();
            }
        }
        left_right_boat = true;
        currentPosition[0] = 0;
        boat.setPosition(280, 530);
        boat.setRotation(0);
    }
}


// Checks to see if anything is currently on the boat.
bool isAnythingOnBoat(bool onBoat[]) {
    for (int i = 0; i < 3; i++) {
        if (onBoat[i] == 1) {
            return true;
        }
    }
    return false;
}
// When the game ends displays a game over image.
void gameFinished(sf::RenderWindow &window, sf::Sprite &gameOver, bool &gameState) {
    gameOver.setPosition(450, 300);
    for (float i = 0.1; i < 0.6; i++) {
        gameOver.setScale(0.5, 0.5);
        window.draw(gameOver);
        gameState = false;
    }
    
}




