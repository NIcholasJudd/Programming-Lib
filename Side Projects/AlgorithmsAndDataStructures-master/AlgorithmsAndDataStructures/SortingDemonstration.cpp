
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//


// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"
sf::Texture sortingModule::backgroundTexture;
sf::Texture sortingModule::playTexture;
sf::Texture sortingModule::pauseTexture;
sf::Texture sortingModule::helpTexture;
sf::Texture sortingModule::helpOverlayTexture;
sf::Texture sortingModule::lessonTexture;
sf::Texture sortingModule::button1Texture;
sf::Texture sortingModule::button2Texture;
sf::Texture sortingModule::button3Texture;
sf::Texture sortingModule::button4Texture;
sf::Texture sortingModule::button5Texture;

void sortingModule::startModule(sf::RenderWindow& mainWindow, sortingModule sort){
    backgroundTexture = sort.loadTexture("SortingBackground.png");
    playTexture = sort.loadTexture("sort_b_play.png");
    pauseTexture = sort.loadTexture("sort_b_pause.png");
    helpTexture = sort.loadTexture("Help.png");
    lessonTexture = sort.loadTexture("Lesson.png");
    helpOverlayTexture = sort.loadTexture("helpOverlay.png");
    button1Texture = sort.loadTexture("sortButton1.png");
    button2Texture = sort.loadTexture("sortButton2.png");
    button3Texture = sort.loadTexture("sortButton3.png");
    button4Texture = sort.loadTexture("sortButton4.png");
    button5Texture = sort.loadTexture("sortButton5.png");
    
    windowSize = mainWindow.getSize();
    buildBackground(mainWindow, sort); 
    buildArray();
    while (mainWindow.isOpen())
    {
        sf::Event menuEvent;
        drawScreen(mainWindow);
        while (mainWindow.pollEvent(menuEvent))
        {
            action = -1;
            if (menuEvent.type == sf::Event::KeyPressed && menuEvent.key.code == sf::Keyboard::Q) {
                return;
            }
            if (menuEvent.type == sf::Event::KeyPressed && menuEvent.key.code == sf::Keyboard::P && size < 100) {
                size++;
                buildArray();
            }
            if(menuEvent.type == sf::Event::MouseButtonPressed){
                sf::Vector2i click = handleMouseClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y, mainWindow);
                action = HandleClick(click.x, click.y);
            }
            
            
            switch (action) {
                    //0. Shuffle
                case 0:
                    swaps = 0;
                    comparisons = 0;
                    play = false;
                    shuffleArray();
                    highlightLine.move(10000, 10000);
                    if (bubble == true){
                        bubbleMenu(mainWindow, action);
                    }else if ( selection == true){
                        selectionMenu(mainWindow, action);
                    }else if (insertion == true){
                        insertionMenu(mainWindow, action);
                    }
                    drawScreen(mainWindow);
                    buttonSprite.setTexture(button1Texture);
                    buttonSprite.setPosition(18, 398);
                    break;
                    //1. Bubble sort
                case 1:
                    helpOverlayTexture = sort.loadTexture("bubbleSortHelpOverlay.png");
                    buttonSprite.setTexture(button3Texture);
                    buttonSprite.setPosition(154, 398);
                    bubbleMenu(mainWindow, action);
                    break;
                    
                    //2. Reverse Sort
                case 2:
                    play = false;
                    reverseSortArray();
                    highlightLine.move(10000, 10000);
                    
                    buttonSprite.setTexture(button2Texture);
                    buttonSprite.setPosition(18, 467);
                    drawScreen(mainWindow);
                    break;
                    
                    //3. Selection Sort
                case 3:
                    helpOverlayTexture = sort.loadTexture("selectionSortHelpOverlay.png");
                    highlightLine.move(10000, 10000);
                    buttonSprite.setTexture(button2Texture);
                    buttonSprite.setPosition(154, 467);
                    selectionMenu(mainWindow, action);
                    break;
                    //4. Sorted Array
                case 4:
                    play = false;
                    forwardSortArray();
                    highlightLine.move(10000, 10000);
                    buttonSprite.setTexture(button5Texture);
                    buttonSprite.setPosition(18, 534);
                    drawScreen(mainWindow);
                    break;
                    
                    //5. Insertion Sort
                case 5:
                    helpOverlayTexture = sort.loadTexture("insertionSortHelpOverlay.png");
                    highlightLine.move(10000, 10000);
                    buttonSprite.setTexture(button4Texture);
                    buttonSprite.setPosition(154, 534);
                    insertionMenu(mainWindow, action);
                    break;
                    //6. minus elements
                case 6:
                    highlightLine.move(10000, 10000);
                    if (play == false){
                        if (size >= 6 && size <= 101){
                            animate.erase(animate.begin(), animate.end());
                            size--;
                            buildArray();
                        }
                    }
                    break;
                    //7. plus elements
                case 7:
                    highlightLine.move(10000, 10000);
                    if (play == false){
                        if (size >= 5 && size <= 100){
                            animate.erase(animate.begin(), animate.end());
                            size++;
                            buildArray();
                        }
                    }
                    break;
                    //8. Back
                case 8:
                    return;
                    break;
                    //9. Step Through
                case 9:
                    step = true;
                    drawScreen(mainWindow);
                    break;
                    //10. Play
                case 10:
                    if (play == false){
                        play = true;
                    }else {
                        play = false;
                    }
                    drawScreen(mainWindow);
                    break;
                case 11:
                    help = !help;
                    break;
                case 12:
                    if (bubble == true){
                        runLessonBuilder("bubbleSortLesson1.txt", mainWindow, 1);
                    }else if (selection == true){
                        runLessonBuilder("selectionSortLesson1.txt", mainWindow, 1);
                    }else if (insertion == true){
                        runLessonBuilder("insertionSortLesson1.txt", mainWindow, 1);
                    }
                    break;
                default:
                    drawScreen(mainWindow);
                    break;
            }

        }
        
    }
    
}

void sortingModule::bubbleMenu(sf::RenderWindow& mainWindow, int action){
    buildPsuedo(1);
    swaps = 0;
    comparisons = 0;
    play = false;
    bubble = true;
    selection = false;
    insertion = false;
    animate.erase(animate.begin(), animate.end());
    bubbleSortFunction(mainWindow);
    drawScreen(mainWindow);
}

void sortingModule::selectionMenu(sf::RenderWindow& mainWindow, int action){
    buildPsuedo(3);
    swaps = 0;
    comparisons = 0;
    play = false;
    bubble = false;
    selection = true;
    insertion = false;
    animate.erase(animate.begin(), animate.end());
    selectionSortFunction(mainWindow);
    drawScreen(mainWindow);
}
void sortingModule::insertionMenu(sf::RenderWindow& mainWindow, int action){
    buildPsuedo(5);
    swaps = 0;
    comparisons = 0;
    play = false;
    bubble = false;
    selection = false;
    insertion = true;
    animate.erase(animate.begin(), animate.end());
    insertionSortFunction(mainWindow);
    drawScreen(mainWindow);
}