//
//  RiverCrossing.h
//  River Crossing
//
//  Created by Peter Mavridis on 2/10/2015.
//  Copyright (c) 2015 Peter Mavridis. All rights reserved.
//

#ifndef __River_Crossing__RiverCrossing__
#define __River_Crossing__RiverCrossing__

#include "ResourcePath.hpp"

void renderScreen(sf::RenderWindow &window, sf::Sprite &carrot, sf::Sprite &goat, sf::Sprite &wolf, sf::Sprite &carrotRed, sf::Sprite &goatRed, sf::Sprite &wolfRed, sf::Sprite &boat, sf::Sprite &background, sf::Sprite &gameOver, sf::Sprite &boatIconRight, sf::Sprite &boatIconLeft, int currentPosition[], sf::Sprite &states, bool &left_right_boat, bool &show, bool &gameState, bool onBoat[], sf::Sprite &state_highlight, sf::Sprite &clouds);
bool showStates(bool &show);
void moveImageToBoat(sf::RenderWindow &window, sf::Sprite & image);
void moveBoat(sf::RenderWindow &window, sf::Sprite &boat, bool &left_right_boat, sf::Time &boat_move_time, sf::Clock &clock, int currentPosition[], bool &gameState, bool onBoat[], sf::Sprite &carrot, sf::Sprite &goat, sf::Sprite &wolf, sf::Sprite &carrotRed, bool &show, sf::Sprite &boatIconRight, sf::Sprite &boatIconLeft, sf::Sprite &goatRed, sf::Sprite &wolfRed, sf::Sprite &background, sf::Sprite &gameOver, sf::Sprite &states, sf::Sprite &state_highlight, sf::Sprite &clouds, int &cloud_x);
bool isAnythingOnBoat(bool onBoat[]);
bool checkMove(sf::RenderWindow &window, int currentPosition[]);
void moveToRightBank(sf::RenderWindow &window, sf::Sprite &boat, bool &left_right_boat, sf::Time &boat_move_time, sf::Clock &clock, int currentPosition[], bool &gameState, bool onBoat[], sf::Sprite &carrot, sf::Sprite &goat, sf::Sprite &wolf, sf::Sprite &carrotRed, bool &show, sf::Sprite &boatIconRight, sf::Sprite &boatIconLeft, sf::Sprite &goatRed, sf::Sprite &wolfRed, sf::Sprite &background, sf::Sprite &gameOver, sf::Sprite &states, sf::Sprite &state_highlight, sf::Sprite &clouds, int &cloud_x);
void gameFinished(sf::RenderWindow &window, sf::Sprite &gameOver, bool &gameState);
void moveToleftBank(sf::RenderWindow &window, sf::Sprite &boat, bool &left_right_boat, sf::Time &boat_move_time, sf::Clock &clock, int currentPosition[], bool &gameState, bool onBoat[], sf::Sprite &carrot, sf::Sprite &goat, sf::Sprite &wolf, sf::Sprite &carrotRed, bool &show, sf::Sprite &boatIconRight, sf::Sprite &boatIconLeft, sf::Sprite &goatRed, sf::Sprite &wolfRed, sf::Sprite &background, sf::Sprite &gameOver, sf::Sprite &states, sf::Sprite &state_highlight, sf::Sprite &clouds, int &cloud_x);
void updateHighlight(std::pair<int, int> &highlight_coords, int currentPosition[]);
void rollingClouds(sf::RenderWindow &window, int &);
void RiverLoop(sf::RenderWindow &);
#endif /* defined(__River_Crossing__RiverCrossing__) */
