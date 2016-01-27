//
//  MainLoop.cpp
//  AlgorithmsAndDataStructures
//
//  Created by Benjamin Waters on 7/06/2014.
//  Copyright (c) 2014 _BENJAMIN. All rights reserved.
//

#include "ResourcePath.hpp"

MainLoop::ProgramState MainLoop::programState = Uninitialized;
sf::RenderWindow MainLoop::MainWindow;
sf::View MainLoop::MainView;
sf::Music MainLoop::MainMusic;

void MainLoop::Start(void){
    
    std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
    MainWindow.setVerticalSyncEnabled(true);
    
    sf::VideoMode mode = modes[0];
    
    unsigned int X = mode.width, Y = mode.height;
    float L = 1.0f, XPrime = Y * 4/3, W = (XPrime / X); L -= W; L = L / 2;
    
    MainWindow.create(sf::VideoMode(X, Y), "SFML window", sf::Style::Fullscreen);           // X Y
    //MainWindow.create(sf::VideoMode(X, Y), "SFML window");           // X Y
    sf::View MainView(sf::FloatRect(0, 0, 1024, 768));
    MainView.setViewport(sf::FloatRect(L, 0.0f, W, 1.f));                                   // L W
    MainWindow.setView(MainView);
    
    // Should never happen
    if(programState != Uninitialized){
        return;
    }
    // The initial program state, should only happen once
    programState = MainLoop::ShowingSplash;
    
    // Enter the main program loop
    while(!IsExiting()){
        RunLoop();
    }
    MainWindow.close();
}

bool MainLoop::IsExiting(){
    if(programState == MainLoop::Exiting)
        return true;
    else
        return false;
}

/*
 
 THIS IS THE MAIN PROGRAM LOOP
 
 This switch() statement will grow as the application grows.
 The program states will appear here as enumerated types, or "states",
 hence state driven design.
 
 PLEASE KEEP THE SWITCH STATEMENT NEAT AND TIDY
 
 Everything that happens goes here
 
 */

void MainLoop::RunLoop(){
    sf::Event currentEvent;
    while(MainWindow.pollEvent(currentEvent)){

        switch(programState){
            case MainLoop::Uninitialized:{
                break;
            }
            case MainLoop::ShowingSplash:{
                ShowSplashScreen();
                break;
            }
            case MainLoop::ShowingMenu:{
                ShowMenu();
                break;
            }
            case MainLoop::ShowingTreesAndStructuresMenu:{
                ShowTreesAndStructuresMenu();
                break;
            }
            case MainLoop::RunningStacksLesson:{
                RunStacksLesson();
                break;
            }
            case MainLoop::RunningTreesLesson:{
                RunTreesLesson();
                break;
            }
            case MainLoop::RunningSortingLesson:{
                RunSortingLesson();
                break;
            }
                
            case MainLoop::RunningStackAttack:{
                RunStackAttack();
                break;
            }
                
            case MainLoop::RunningBinaryTreeDungeon:{
                RunBinaryTreeDungeon();
                break;
            }
            case MainLoop::ShowingSortingAndSearchingMenu:{
                ShowSortingAndSearchingMenu();
                break;
            }
            case MainLoop::RunningSortingAndSearchingLesson:{
                MainWindow.clear(sf::Color(sf::Color::Black));
                
                sf::Font font;
                if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
                    exit(1);
                }
                sf::Text LessonText("Placeholder text.  ESC to go back", font, 30);
                MainWindow.draw(LessonText);
                
                MainWindow.display();

                if(currentEvent.type == sf::Event::KeyPressed){
                    if(currentEvent.key.code == sf::Keyboard::Key::Escape) ShowSortingAndSearchingMenu();
                }
                break;
            }
                
            case MainLoop::RunningSortingAndSearchingDemo:{
                RunSortingDemonstration();
                break;
            }
                
            case MainLoop::RunningSortingComparisson:{
                RunSortingComparisson();
                break;
            }
                
            case MainLoop::ShowingPuzzlesAndGamesMenu:{
                ShowPuzzlesAndGamesMenu();
                break;
            }
                
            case MainLoop::RunningConwaysGameOfLife:{
                RunConwaysGameOfLife();
                break;
            }
            case MainLoop::RunningRiverCrossing:{
                RunRiverCrossing();
                break;
            }
            case MainLoop::ShowingSchoolOfImplementationsMenu:{
                ShowSchoolOfImplementationsMenu();
                break;
            }
                
            case MainLoop::RunningSchoolOfImplementations:{
                MainWindow.clear(sf::Color::Black);
                
                sf::Font font;
                if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
                    exit(1);
                }
                sf::Text LessonText("Placeholder text.  ESC to go back", font, 30);
                MainWindow.draw(LessonText);
                
                MainWindow.display();
                if(currentEvent.type == sf::Event::Closed){
                    programState = MainLoop::Exiting;
                }
                if(currentEvent.type == sf::Event::KeyPressed){
                    if(currentEvent.key.code == sf::Keyboard::Key::Escape) ShowSchoolOfImplementationsMenu();
                }
                break;
            }
            case MainLoop::Paused:{
                break;
            }
            case MainLoop::RunningProblemSolvingLesson:{
                break;
            }
            case MainLoop::Exiting:{
                // Exit safely.  SFML should by rights free resources here
                exit(0);
                break;
            }
        }
    }
}

void MainLoop::ShowSplashScreen(){
	SplashScreen splashScreen;
	splashScreen.Show(MainWindow);
	programState = MainLoop::ShowingMenu;
}

/*
 
 THE MENUS AND SUB MENUS APPEAR HERE
 
 Each has their own .cpp and .h file in order that they can be dynamic and themed.
 
 NO GENERIC BUILD MENU CLASS
 
 It is important that the project remain as collaborative and modular as possible,
 this way it is far easier to combine other, smaller applications into this one
 
*/

void MainLoop::ShowMenu(){
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(MainWindow);
	switch(result){
        case MainMenu::Exit:
			programState = MainLoop::Exiting;
			break;
        case MainMenu::SortingAndSearchingMenu:
            programState = MainLoop::ShowingSortingAndSearchingMenu;
            break;
        case MainMenu::TreesAndStructuresMenu:
            programState = MainLoop::ShowingTreesAndStructuresMenu;
            break;
        case MainMenu::PuzzlesAndGamesMenu:
            programState = MainLoop::ShowingPuzzlesAndGamesMenu;
            break;
        case MainMenu::SchoolOfImplementationsMenu:
            programState = MainLoop::ShowingSchoolOfImplementationsMenu;
            break;
        case MainMenu::Nothing:
            ShowMenu();
            break;
	}
}

void MainLoop::ShowSortingAndSearchingMenu(){
    SortingAndSearchingMenu sortingAndSearchingMenu;
    SortingAndSearchingMenu::SortingAndSearchingMenuResult result = sortingAndSearchingMenu.Show(MainWindow);
    switch(result){
        case SortingAndSearchingMenu::Back:
            programState = MainLoop::ShowingMenu;
            break;
        case SortingAndSearchingMenu::BeginLesson:
            programState = MainLoop::RunningSortingAndSearchingLesson;
            break;
        case SortingAndSearchingMenu::BeginDemo:
            programState = MainLoop::RunningSortingAndSearchingDemo;
            break;
        case SortingAndSearchingMenu::BeginComparisson:
            programState = MainLoop::RunningSortingComparisson;
            break;
        case SortingAndSearchingMenu::Nothing:
            // Vitally important
            ShowSortingAndSearchingMenu();
            break;
    }
}

void MainLoop::RunSortingDemonstration(){
    programState = MainLoop::RunningSortingAndSearchingLesson;
    runLessonBuilder("SortingDemo.txt", MainWindow, 0);
    sortingModule sort;
    sort.startModule(MainWindow, sort);
    programState = MainLoop::ShowingSortingAndSearchingMenu;
}

void MainLoop::RunSortingComparisson(){
    programState = MainLoop::RunningSortingComparisson;
    beginSortingComparisson(MainWindow);
    programState = MainLoop::ShowingSortingAndSearchingMenu;
}

void MainLoop::ShowTreesAndStructuresMenu(){
    TreesAndStructuresMenu treesAndStructuresMenu;
    TreesAndStructuresMenu::TreesAndStructuresMenuResult result = treesAndStructuresMenu.Show(MainWindow);
    switch(result){
        case TreesAndStructuresMenu::Back:
            programState = MainLoop::ShowingMenu;
            break;
        case TreesAndStructuresMenu::BeginStacksLesson:
            programState = MainLoop::RunningStacksLesson;
            break;
        case TreesAndStructuresMenu::BeginStackAttack:
            programState = MainLoop::RunningStackAttack;
            break;
        case TreesAndStructuresMenu::BeginTreeDungeon:
            programState = MainLoop::RunningBinaryTreeDungeon;
            break;
        case TreesAndStructuresMenu::Nothing:
            // Vitally important
            ShowTreesAndStructuresMenu();
            break;
    }
}

void MainLoop::RunBinaryTreeDungeon(){
    programState = MainLoop::RunningBinaryTreeDungeon;
    runLessonBuilder("BinaryTreeDungeon.txt", MainWindow, 0);
    beginBinaryTreeDungeon(MainWindow);
    programState = MainLoop::ShowingTreesAndStructuresMenu;
}

void MainLoop::RunStackAttack(){
    programState = MainLoop::RunningStackAttack;
    runLessonBuilder("StackAttack.txt", MainWindow, 0);
    beginStackAttack(MainWindow);
    programState = MainLoop::ShowingTreesAndStructuresMenu;
}

void MainLoop::ShowPuzzlesAndGamesMenu(){
    PuzzlesAndGamesMenu puzzlesAndGamesMenu;
    PuzzlesAndGamesMenu::PuzzlesAndGamesMenuResult result = puzzlesAndGamesMenu.Show(MainWindow);
    switch(result){
        case PuzzlesAndGamesMenu::Back:
            programState = MainLoop::ShowingMenu;
            break;
        case PuzzlesAndGamesMenu::BeginConways:
            programState = MainLoop::RunningConwaysGameOfLife;
            break;
        case PuzzlesAndGamesMenu::BeginRiverCrossing:
            programState = MainLoop::RunningRiverCrossing;
            break;
        case PuzzlesAndGamesMenu::Nothing:
            ShowPuzzlesAndGamesMenu();
            break;
    }
}

void MainLoop::RunConwaysGameOfLife(){
    programState = MainLoop::RunningConwaysGameOfLife;
    runLessonBuilder("ConwaysGameOfLife.txt", MainWindow, 0);
    beginConwaysGameOfLife(MainWindow);
    programState = MainLoop::ShowingPuzzlesAndGamesMenu;
}

void MainLoop::RunRiverCrossing(){
    programState = MainLoop::RunningRiverCrossing;
    RiverLoop(MainWindow);
    programState = MainLoop::ShowingPuzzlesAndGamesMenu;
}

void MainLoop::RunStacksLesson(){
    programState = MainLoop::RunningStacksLesson;
    runLessonBuilder("sAndQLesson.txt", MainWindow, 1);
    programState = MainLoop::ShowingSchoolOfImplementationsMenu;
}

void MainLoop::RunTreesLesson(){
    programState = MainLoop::RunningTreesLesson;
    runLessonBuilder("masterTreeLesson.txt", MainWindow, 1);
    programState = MainLoop::ShowingSchoolOfImplementationsMenu;
}

void MainLoop::RunSortingLesson(){
    programState = MainLoop::RunningSortingLesson;
    runLessonBuilder("masterSortingLesson.txt", MainWindow, 1);
    programState = MainLoop::ShowingSchoolOfImplementationsMenu;
}

void MainLoop::ShowSchoolOfImplementationsMenu(){
    SchoolOfImplementationsMenu schoolOfImplementationsMenu;
    SchoolOfImplementationsMenu::SchoolOfImplementationsMenuResult result = schoolOfImplementationsMenu.Show(MainWindow);
    switch(result){
        case SchoolOfImplementationsMenu::Back:
            programState = MainLoop::ShowingMenu;
            break;
        case SchoolOfImplementationsMenu::BeginSortingLesson:
            programState = MainLoop::RunningSortingLesson;
            break;
        case SchoolOfImplementationsMenu::BeginTreesLesson:
            programState = MainLoop::RunningTreesLesson;
            break;
        case SchoolOfImplementationsMenu::BeginStacksLesson:
            programState = MainLoop::RunningStacksLesson;
            break;
        case SchoolOfImplementationsMenu::BeginProblemSolvingLesson:
            programState = MainLoop::RunningSchoolOfImplementations;
            break;
        case SchoolOfImplementationsMenu::Nothing:
            // Vitally important
            SchoolOfImplementationsMenu();
            break;
    }
}

sf::Vector2i handleMouseClick(unsigned int x, unsigned int y, sf::RenderWindow &window){
    sf::Vector2i mouse(x, y);
    sf::Vector2f mouse_world = window.mapPixelToCoords(mouse);
    return sf::Vector2i(mouse_world.x, mouse_world.y);
}
