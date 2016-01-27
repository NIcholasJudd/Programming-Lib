////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2013 Marco Antognini (antognini.marco@gmail.com), 
//                         Laurent Gomila (laurent.gom@gmail.com), 
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////
#ifndef RESOURCE_PATH_HPP
#define RESOURCE_PATH_HPP
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <string>
#include <list>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <random>
#include <deque>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "MainLoop.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include "TreesAndStructuresMenu.h"
#include "PuzzlesAndGamesMenu.h"
#include "SortingAndSearchingMenu.h"
#include "SchoolOfImplementationsMenu.h"
#include "SortingDemonstration.h"
#include "StackAttack.h"
#include "TreeDungeonMaps.h"
#include "TreeDungeonGraphics.h"
#include "TreeDungeonInput.h"
#include "TreeDungeonLineOfSight.h"
#include "TreeDungeonCharacter.h"
#include "TreeDungeonGameFunctions.h"
#include "RunBinaryTreeDungeon.h"
#include "Compare.h"
#include "AlbertonsLessonBuilder.h"
#include "ConwaysMain.h"
#include "RiverCrossing.h"
#include "scrollingBackground.h"
#include "stackAttackGame.h"
////////////////////////////////////////////////////////////
/// \brief Return the path to the resource folder.
///
/// \return The path to the resource folder associate
/// with the main bundle or an empty string is there is no bundle.
///
//////////////////////////////////////////////////////////// 
std::string resourcePath(void);
extern sf::Clock GLOBAL_CLOCK;

#endif
