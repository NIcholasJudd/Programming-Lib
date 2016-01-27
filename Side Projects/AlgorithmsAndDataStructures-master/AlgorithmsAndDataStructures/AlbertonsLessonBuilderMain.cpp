//
//  AlbertonsLessonBuilder.h
//  AlbertonsLessonBuilder
//
//  Created by Benjamin Waters on 11/09/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#include "ResourcePath.hpp"

void runLessonBuilder(std::string fileName, sf::RenderWindow &mainWindow, bool type) {
    buildLesson(fileName, mainWindow, type);
    return;
}
