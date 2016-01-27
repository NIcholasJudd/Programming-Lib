//
//  main.h
//  comparisonSort
//
//  Created by Nicholas Judd on 4/09/2015.
//  Copyright (c) 2015 Nicholas Judd. All rights reserved.
//

#ifndef AlgorithmsAndDataStructures_main_h
#define AlgorithmsAndDataStructures_main_h
#include "ResourcePath.hpp"
class comparisonModule {
public:
    struct menu{
        sf::Rect<int> buttonController;
        int buttonNumber;
    };
    
    sf::Vector2u windowSize;
    // entry point for module
    void startModule(sf::RenderWindow&, comparisonModule);
    void buildBackground(sf::RenderWindow&, comparisonModule);
    void buildArray();
    void drawScreen(sf::RenderWindow&);
    void renderScreen(sf::RenderWindow&, sf::Sprite);
    void bubbleSortFunction(sf::RenderWindow&);
    void selectionSortFunction(sf::RenderWindow&);
    void insertionSortFunction(sf::RenderWindow&);
    void shuffleArray();
    void reset();
    void reverseSortArray();
    void forwardSortArray();
    void setCompAndSwapValue();
    int HandleClick(int x, int y);
    sf::Texture const loadTexture(std::string);
private:
    static sf::Texture backgroundTexture;
    static sf::Texture pauseTexture;
    static sf::Texture playTexture;
    static sf::Texture shuffleTexture;
    static sf::Texture sorttedTexture;
    static sf::Texture revSortTexture;
    static sf::Texture sortingTexture;
    static sf::Texture barTexture;
    static sf::Texture selectedTexture;
    double resizeSwap[3] = {0};
    double resizeCompare[3] = {0};
    bool sorted = true;
    bool revSort = false;
    bool shuffled = false;
    bool play = false;
    int size = 10000;
    int count = 0;
    int action = -1;
    long int comparisons[3] = {0};
    long int swaps[3]= {0};
    long double time[3] = {0};
    double increase = 0;
    double timeIncrease = 0;
    double largestValue = 0;
    double largestTime = 0;
    sf::Font font;
    sf::Text elementNum;
    sf::Text comparisonsNumber[3];
    sf::Text swapsNumber[3];
    sf::Text timeComp[3];
    sf::Text largestValueText[3];
    sf::Vector2f sizeGraphSwap[3];
    sf::Vector2f sizeGraphComp[3];
    sf::Vector2f sizeGraphTime[3];
    std::vector<int> sortList[3];
    std::list<menu> menuControler;
    sf::RectangleShape swapGraph[3];
    sf::RectangleShape compareGraph[3];
    sf::RectangleShape timeGraph[3];
};

void beginSortingComparisson(sf::RenderWindow &);

#endif
