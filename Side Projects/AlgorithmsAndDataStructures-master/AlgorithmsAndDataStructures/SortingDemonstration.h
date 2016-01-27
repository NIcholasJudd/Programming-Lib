//
//  main.h
//  SortingModule
//
//  Created by Nicholas Judd on 16/08/2015.
//  Copyright (c) 2015 Nicholas Judd. All rights reserved.
//

#ifndef SortingModule_main_h
#define SortingModule_main_h

class sortingModule {
public:
    struct menu{
        sf::Rect<int> buttonController;
        int buttonNumber;
    };
    struct sortArray{
    public:
        sf::RectangleShape rect;
        int heightValue;
    };
    struct animation{
    public:
        int element1;
        int element2;
        int action;
    };
    sf::Vector2u windowSize;
    void startModule(sf::RenderWindow&, sortingModule);
    void buildScreen(sortingModule);
    void buildBackground(sf::RenderWindow&, sortingModule);
    void buildArray();
    void drawPsudeo(sf::RenderWindow&);
    void drawScreen(sf::RenderWindow&);
    void renderScreen(sf::RenderWindow&, sf::Sprite);
    void animateScreen(sf::RenderWindow&, sf::Sprite);
    void animateBubble(sf::RenderWindow&, sf::Sprite);
    void animateSelection(sf::RenderWindow&, sf::Sprite);
    void animateInsertion(sf::RenderWindow&, sf::Sprite);
    void bubbleSortFunction(sf::RenderWindow&);
    void selectionSortFunction(sf::RenderWindow&);
    void insertionSortFunction(sf::RenderWindow&);
    void bubbleMenu (sf::RenderWindow&, int);
    void selectionMenu (sf::RenderWindow&, int);
    void insertionMenu (sf::RenderWindow&, int);
    void shuffleArray();
    void reverseSortArray();
    void buildPsuedo(int);
    void forwardSortArray();
    void setCompAndSwapValue();
    int HandleClick(int x, int y);
    sf::Texture const loadTexture(std::string);
    sf::Sprite buttonSprite;
private:
    static sf::Texture backgroundTexture;
    static sf::Texture pauseTexture;
    static sf::Texture playTexture;
    static sf::Texture helpTexture;
    static sf::Texture lessonTexture;
    static sf::Texture helpOverlayTexture;
    static sf::Texture button1Texture;
    static sf::Texture button2Texture;
    static sf::Texture button3Texture;
    static sf::Texture button4Texture;
    static sf::Texture button5Texture;
    int size = 10;
    int action = -1;
    int speed = 20;
    int comparisons = 0;
    int swaps = 0;
    int correct = 0;
    bool play = false;
    bool step = false;
    bool bubble = false;
    bool selection = false;
    bool insertion = false;
    bool help = false;
    int fontSize = 50;
    sf::RectangleShape highlightLine;
    sf::FloatRect stringLength1;
    sf::FloatRect stringLength2;
    sf::Font font;
    sf::Text comparisonsNumber;
    sf::Text swapsNumber;
    sf::Text elementNumber;
    std::vector<sortArray> sortList;
    std::list<menu> menuControler;
    std::list<animation> animate;
    std::vector<std::string> psudeoCode;
};

#endif
