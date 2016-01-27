//
//  ConwaysMain.h
//  AlgorithmsAndDataStructures
//
//  Created by Jim Gollop on 12/09/2015.
//  Copyright (c) 2015 Jim. All rights reserved.
//

#include "ResourcePath.hpp"

void beginConwaysGameOfLife(sf::RenderWindow &window) {
    // Load background
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "ConwaysBackground.png")) {
        return;
    }
    sf::Sprite background(texture);
    
    // Load menus
    sf::Texture pMenu;
    if (!pMenu.loadFromFile(resourcePath() + "gol_playMode.gif")) {
        return;
    }
    sf::Sprite playMenu(pMenu);
    playMenu.setPosition(sf::Vector2f(736, 32));
    
    sf::Texture pMenu_play;
    if(!pMenu_play.loadFromFile(resourcePath() + "gol_b_play.gif")) {
        return;
    }
    sf::Sprite playMenu_play(pMenu_play);
    playMenu_play.setPosition(740, 118);
    
    sf::Texture pMenu_pause;
    if(!pMenu_pause.loadFromFile(resourcePath() + "gol_b_pause.gif")) {
        return;
    }
    sf::Sprite playMenu_pause(pMenu_pause);
    playMenu_pause.setPosition(740, 118);
    
    sf::Texture eMenu;
    if (!eMenu.loadFromFile(resourcePath() + "gol_editMode.gif")) {
        return;
    }
    sf::Sprite editMenu(eMenu);
    editMenu.setPosition(sf::Vector2f(736, 32));
    
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return;
    }
    sf::Text text("Edit Mode", font, 50);
    text.setColor(sf::Color::Magenta);
    
    sf::Text text2(">> Draw", font, 20);
    text2.setColor(sf::Color::Magenta);
    text2.setPosition(10, 50);
    
    sf::Text t_speed("X", font, 30);
    t_speed.setColor(sf::Color::White);
    t_speed.setPosition(865, 275);
    t_speed.setString(std::to_string(3));
    
    std::srand((unsigned int)time(0));
    int gridX = 100; int gridY = 100;                                   // Number of cells
    int gridWidth = 700; int gridHeight = 700;                          // Number of pixels
    int boardX = 19; int boardY = 34;                                   // X,Y location of top left corner of board
    float cellWidth = gridWidth/gridX;
    float cellHeight = gridHeight/gridY;
    const int boardSizes[3] = {20, 50, 100};                            // Small/Medium/Large
    
    int currSpeed = 2;                                                  // Current speed setting (0-4)
    const float speeds[5] = {0.2, 0.1, 0.075, 0.05, 0.025};             // Game speeds (in seconds)
    float gameSpeed = speeds[currSpeed];                                // Seconds between ticks
    sf::Clock clock;
    
    sf::RectangleShape cell(sf::Vector2f(cellWidth, cellHeight));       // Used to draw cells
    sf::IntRect bb(boardX, boardY, gridWidth, gridHeight);              // Used to test board boundaries
    sf::IntRect b_editMode(740, 36, 128, 60);                           // Edit Mode button
    sf::IntRect b_playMode(876, 36, 128, 60);                           // Play Mode button
    
    //---------- EDIT MODE BUTTONS
    sf::IntRect b_gridSmall(739, 117, 83, 60);                          // Small Grid button
    sf::IntRect b_gridMedium(830, 117, 83, 60);                         // Medium Grid button
    sf::IntRect b_gridLarge(921, 117, 83, 60);                          // Large Grid button
    
    sf::IntRect b_random(739, 185, 264, 60);                            // Random button
    sf::IntRect b_draw(739, 253, 264, 60);                              // Draw button
    sf::IntRect b_clear(739, 674, 264, 60);                             // Clear button
    sf::IntRect b_stampArea(739, 388, 264, 264);                        // Box covering all Stamps
    
    //---------- PLAY MODE BUTTONS
    sf::IntRect b_playPause(740, 118, 264, 60);                         // Play/Pause button
    sf::IntRect b_step(740, 186, 264, 60);                              // Step button
    sf::IntRect b_speedDown(740, 254, 60, 60);                          // Tortoise button
    sf::IntRect b_speedUp(944, 254, 60, 60);                            // Rabbit button
    
    enum mode {EDIT, PLAY};                                             // Main mode switch
    mode gameMode = EDIT;
    bool playMode = false;                                              // True = Play, False = Pause;
    
    enum bSize {SMALL, MEDIUM, LARGE};                                  // Board size
    bSize boardSize = LARGE;
    enum pen {ON, OFF, NONE};                                           // Pen state
    pen penMode = NONE;
    enum draw {DRAW, STAMP};                                            // Draw/Stamp state
    draw drawMode = DRAW;
    int currStamp = 0;                                                  // Current/Last used stamp (0-15)
    
    bool **board;                                                       // Create dynamic 2d bool array
    bool **calcBoard;                                                   // Spare board used for calculating next state
    bool **swap;                                                        // Used to swap boards
    
    board = new bool*[gridX];
    calcBoard = new bool*[gridX];
    for (int i = 0; i < gridX; i++) {
        board[i] = new bool[gridY];
        calcBoard[i] = new bool[gridY];
    }
    init(board, gridX, gridY);
    init(calcBoard, gridX, gridY);
    
    std::vector<bool> stamps[16];
    buildStamp(stamps[0], std::string("1111")); // Block
    buildStamp(stamps[1], std::string("0110100101100000")); // Beehive
    buildStamp(stamps[2], std::string("0110100101010010")); // Loaf
    buildStamp(stamps[3], std::string("110101010")); // Boat
    buildStamp(stamps[4], std::string("000111000")); // Blinker
    buildStamp(stamps[5], std::string("0000011111100000")); // Toad
    buildStamp(stamps[6], std::string("1100110000110011")); // Beacon
    buildStamp(stamps[7], std::string("0011000001100000110001100010010101010011110110110111010101010101000111000111000000000000000001110001110001010101010101110110110111100101010100100011000110000011000001100")); // Pulsar
    buildStamp(stamps[8], std::string("011110010")); // r-Pentomino
    buildStamp(stamps[9], std::string("0111110001100000")); // e-Pentomino
    buildStamp(stamps[10], std::string("0000000000000000000000101100000001000111000000000000000000000000")); // Die Hard
    buildStamp(stamps[11], std::string("0000000000000001000000001000110011100000000000000")); // Acorn
    buildStamp(stamps[12], std::string("010001111")); // Glider
    buildStamp(stamps[13], std::string("0111110001000011001000000")); // LWSS
    buildStamp(stamps[14], std::string("011111100001000001100010001000000000")); // MWSS
    buildStamp(stamps[15], std::string("0000000011111110000010000001100001000110000000000")); // HWSS
    
    std::string stampNames[16];
    stampNames[0] = "Block";
    stampNames[1] = "Beehive";
    stampNames[2] = "Loaf";
    stampNames[3] = "Boat";
    stampNames[4] = "Blinker";
    stampNames[5] = "Toad";
    stampNames[6] = "Beacon";
    stampNames[7] = "Pulsar";
    stampNames[8] = "R-Pentomino";
    stampNames[9] = "E-Pentomino";
    stampNames[10] = "Die Hard";
    stampNames[11] = "Acorn";
    stampNames[12] = "Glider";
    stampNames[13] = "LightWeight SpaceShip";
    stampNames[14] = "MediumWeight SpaceShip";
    stampNames[15] = "HeavyWeight SpaceShip";
    
    
    while (window.isOpen()) {
        // Timer
        if (clock.getElapsedTime().asSeconds() > gameSpeed) {
            if (gameMode == PLAY && playMode) {
                updateBoard(board, calcBoard, swap, gridX, gridY);
            }
            clock.restart();
        }
        
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            
            if (event.type == sf::Event::KeyPressed) { // Hotkeys
                if (event.key.code == sf::Keyboard::Q) { // Esc - Quit/Back
                    return;
                }
                if (event.key.code == sf::Keyboard::E) { // E - Edit Mode
                    gameMode = EDIT;
                }
                if (event.key.code == sf::Keyboard::P) { // P - Play Mode
                    gameMode = PLAY;
                }
                if (event.key.code == sf::Keyboard::C) { // C - Clear
                    init(board, gridX, gridY);
                    init(calcBoard, gridX, gridY);
                }
                if (event.key.code == sf::Keyboard::R) { // R - Random
                    rand(board, gridX, gridY);
                }
                if (event.key.code == sf::Keyboard::Num1) {
                    resizeBoard(boardSizes[0], gridX, gridY, gridWidth, gridHeight, cellWidth, cellHeight, cell);
                    init(board, gridX, gridY);
                    boardSize = SMALL;
                }
                if (event.key.code == sf::Keyboard::Num2) {
                    resizeBoard(boardSizes[1], gridX, gridY, gridWidth, gridHeight, cellWidth, cellHeight, cell);
                    init(board, gridX, gridY);
                    boardSize = MEDIUM;
                }
                if (event.key.code == sf::Keyboard::Num3) {
                    resizeBoard(boardSizes[2], gridX, gridY, gridWidth, gridHeight, cellWidth, cellHeight, cell);
                    init(board, gridX, gridY);
                    boardSize = LARGE;
                }
            }
            
            if (gameMode == EDIT) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                    localPosition = handleMouseClick(localPosition.x, localPosition.y, window);
                    if (bb.contains(localPosition)) {
                        
                        int myX = ((localPosition.x-boardX)/cellWidth);
                        int myY = ((localPosition.y-boardY)/cellHeight);
                        if (drawMode == DRAW) {
                            if (penMode == NONE) {
                                if (board[myX][myY]) {
                                    penMode = OFF;
                                } else {
                                    penMode = ON;
                                }
                            }
                            if (penMode == ON) {
                                board[myX][myY] = true;
                            } else {
                                board[myX][myY] = false;
                            }
                        } else { // drawMode == STAMP
                            int mySize = sqrt(stamps[currStamp].size());
                            myX -= mySize/2;
                            myY -= mySize/2;
                            for (int j = 0; j < mySize; j++) {
                                for (int i = 0; i < mySize; i++) {
                                    if (stamps[currStamp][j*mySize+i]) {
                                        board[(myX+i+gridX)%gridX][(myY+j+gridY)%gridY] = true;
                                    }
                                }
                            }
                        }
                    } else if (b_gridSmall.contains(localPosition) && boardSize != SMALL) {
                        resizeBoard(20, gridX, gridY, gridWidth, gridHeight, cellWidth, cellHeight, cell);
                        init(board, gridX, gridY);
                        boardSize = SMALL;
                    } else if (b_gridMedium.contains(localPosition) && boardSize != MEDIUM) {
                        resizeBoard(50, gridX, gridY, gridWidth, gridHeight, cellWidth, cellHeight, cell);
                        init(board, gridX, gridY);
                        boardSize = MEDIUM;
                    } else if (b_gridLarge.contains(localPosition) && boardSize != LARGE) {
                        resizeBoard(100, gridX, gridY, gridWidth, gridHeight, cellWidth, cellHeight, cell);
                        init(board, gridX, gridY);
                        boardSize = LARGE;
                    } else if (b_playMode.contains(localPosition)) {
                        gameMode = PLAY;
                    } else if (b_random.contains(localPosition)){
                        rand(board, gridX, gridY);
                    } else if (b_draw.contains(localPosition)) {
                        drawMode = DRAW;
                    } else if (b_stampArea.contains(localPosition)) {
                        currStamp = 4*((localPosition.y-388)/66) + (localPosition.x-739)/66;
                        drawMode = STAMP;
                        text2.setString(stampNames[currStamp]);
                    } else if (b_clear.contains(localPosition)) {
                        init(board, gridX, gridY);
                        init(calcBoard, gridX, gridY);
                    }
                } else {
                    penMode = NONE;
                }
            }
            
            if (gameMode == PLAY) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                    
                    localPosition = handleMouseClick(localPosition.x, localPosition.y, window);
                    
                    if (b_editMode.contains(localPosition)) { // Switch to Edit Mode
                        gameMode = EDIT;
                        playMode = false;
                    }
                    
                    if (b_playPause.contains(localPosition)) { // Toggle Play/Pause
                        playMode = !playMode;
                    } else if (b_step.contains(localPosition)) { // Step button
                        playMode = false;
                        updateBoard(board, calcBoard, swap, gridX, gridY);
                    } else if (b_speedUp.contains(localPosition) && currSpeed < 4) { // Speed Up
                        currSpeed++;
                        gameSpeed = speeds[currSpeed];
                        t_speed.setString(std::to_string(currSpeed+1));
                    } else if (b_speedDown.contains(localPosition)&& currSpeed > 0) { // Speed Down
                        currSpeed--;
                        gameSpeed = speeds[currSpeed];
                        t_speed.setString(std::to_string(currSpeed+1));
                    }
                }
            }
        }
        
        // Clear screen
        window.clear();
        
        // Draw the background
        window.draw(background);
        
        // Draw the relevant menu
        if (gameMode == EDIT) {
            window.draw(editMenu);
        } else {
            window.draw(playMenu);
        }
        
        // Draw the grid
        for (int i = 0; i < gridX; i++) {
            for (int j = 0; j < gridY; j++) {
                //Draw Cell
                cell.setPosition((i*cellWidth)+boardX, (j*cellHeight)+boardY);
                if (board[i][j]) {
                    cell.setFillColor(sf::Color::White);
                } else {
                    cell.setFillColor(sf::Color::Blue);
                }
                window.draw(cell);
            }
        }
        
        // Draw the stamp preview
        if (gameMode == EDIT && drawMode == STAMP) {
            sf::Vector2i localPosition = sf::Mouse::getPosition(window);
            
            localPosition = handleMouseClick(localPosition.x, localPosition.y, window);
            if (bb.contains(localPosition)) {
                
                int myX = ((localPosition.x-boardX)/cellWidth);
                int myY = ((localPosition.y-boardY)/cellHeight);
                int mySize = sqrt(stamps[currStamp].size());
                cell.setFillColor(sf::Color::Magenta);
                myX -= mySize/2;
                myY -= mySize/2;
                for (int j = 0; j < mySize; j++) {
                    for (int i = 0; i < mySize; i++) {
                        if (stamps[currStamp][j*mySize+i]) {
                            cell.setPosition((((myX+i+gridX)%gridX)*cellWidth)+boardX,
                                             (((myY+j+gridY)%gridY)*cellHeight)+boardY);
                            window.draw(cell);                        }
                    }
                }
            }
        }
        
        // Draw the string
        switch (gameMode) {
            case EDIT:
                text.setString("Edit Mode");
                break;
            case PLAY:
                text.setString("Play Mode");
                break;
            default:
                break;
        }
        switch (drawMode) {
            case DRAW:
                text2.setString(">> Draw");
                break;
            case STAMP:
                //text2.setString(">> Stamp");
                break;
            default:
                break;
        }
        window.draw(text);
        window.draw(text2);
        
        if (gameMode == PLAY) {
            window.draw(t_speed);
            if (playMode) {
                window.draw(playMenu_pause);
            } else {
                window.draw(playMenu_play);
            }
        }
        window.display();
    }
    
    return;
}

void init(bool **board, int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            board[i][j] = false;
        }
    }
}

void rand(bool **board, int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            board[i][j] = rand()%2;
        }
    }
}

void updateBoard(bool **&board, bool **&calcBoard, bool **&swap,
                 const int &gridX, const int &gridY) {
    int counter;
    for (int i = 0; i < gridX; i++) { // Iterate through grid
        for (int j = 0; j < gridY; j++) {
            counter = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) { // Count live neighbouring squares
                    if (!(x==0 && y==0) && board[(i+x+gridX)%gridX][(j+y+gridY)%gridY]) {
                        counter++;
                    }
                }
            }
            if (board[i][j] == false) { // Cell is dead
                if (counter == 3) {
                    calcBoard[i][j] = true;
                } else {
                    calcBoard[i][j] = false;
                }
            } else {                    // Cell is alive
                if (counter == 2 || counter == 3) {
                    calcBoard[i][j] = true;
                } else {
                    calcBoard[i][j] = false;
                }
            }
        }
    }
    // Swap board and calcBoard
    swap = board;
    board = calcBoard;
    calcBoard = swap;
}

void resizeBoard(int n, int &gridX, int &gridY,
                 int &gridWidth, int &gridHeight,
                 float &cellWidth, float &cellHeight,
                 sf::RectangleShape &cell) {
    gridX = n; gridY = n;
    cellWidth = gridWidth/gridX;
    cellHeight = gridHeight/gridY;
    cell.setSize(sf::Vector2f(cellWidth, cellHeight));
}

void buildStamp(std::vector<bool> &stamp, std::string newStamp) {
    for (int i = 0; i < newStamp.length(); i++) {
        if (newStamp[i] == '1') {
            stamp.push_back(true);
        } else {
            stamp.push_back(false);
        }
    }
}