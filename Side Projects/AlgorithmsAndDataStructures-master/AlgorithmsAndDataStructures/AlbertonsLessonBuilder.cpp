//
//  AlbertonsLessonBuilder.cpp
//  AlbertonsLessonBuilder
//
//  Created by Benjamin Waters on 11/09/2015.
//  Copyright (c) 2015 Benjamin. All rights reserved.
//

#include "ResourcePath.hpp"

void buildLesson(std::string fileName, sf::RenderWindow &window, bool type){
    sf::Clock clock;
    sf::Clock clock2;
    bool hologram = false;
    sf::Texture LessonDialogueBackground;
    std::list<std::pair<int, std::string> > DialogueCommands = read(fileName);
    if (type == 0){
        LessonDialogueBackground = MappedLessonDialogueGraphics.initIntroBackground();
    }else{
        LessonDialogueBackground = MappedLessonDialogueGraphics.initLessonBackground();
    }
    
    sf::Texture LessonDialogueCharacters = MappedLessonDialogueGraphics.initCharacters();
    MappedLessonDialogueGraphics.initBGSprite(LessonDialogueBackground);
    MappedLessonDialogueGraphics.initCharacterSprites(LessonDialogueCharacters);
    
    bool skip = false;
    
    while (window.isOpen()) {
        albertonInput(window, skip);
        if(updateGraphics(window, MappedLessonDialogueGraphics, DialogueCommands, clock, clock2, hologram, skip, type) == 0){
            return;
        };
    }
    return;
}

sf::Texture const LessonDialogueGraphics::initIntroBackground(){
    sf::Texture Texture;
    if (!Texture.loadFromFile(resourcePath() + "AlbertonLessonBackground.gif")) {
        std::cerr << "ERROR with background " << std::endl;
    }
    return Texture;
}

sf::Texture const LessonDialogueGraphics::initLessonBackground(){
    sf::Texture Texture;
    if (!Texture.loadFromFile(resourcePath() + "LessonBackground.png")) {
        std::cerr << "ERROR with background " << std::endl;
    }
    return Texture;
}

sf::Texture const LessonDialogueGraphics::initCharacters(){
    sf::Texture Texture;
    if (!Texture.loadFromFile(resourcePath() + "LessonCharacters.png")) {
        std::cerr << "ERROR with characters " << std::endl;
    }
    return Texture;
}

LessonDialogueGraphics const LessonDialogueGraphics::initBGSprite(sf::Texture &Texture){
    sf::Sprite Background(Texture);
    DialogueBackground = Background;
    return *this;
}

LessonDialogueGraphics const LessonDialogueGraphics::initCharacterSprites(sf::Texture &Texture){
    sf::Sprite Alberton(Texture);
    Alberton.setTextureRect(sf::IntRect(0,0,300,300));
    ProfessorSprite = Alberton;
    sf::Sprite Companion(Texture);
    Companion.setTextureRect(sf::IntRect(300,0,300,300));
    CompanionSprite = Companion;
    return *this;
}

void albertonInput(sf::RenderWindow &window, bool &skip){
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            return;
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
            skip = true;
        }
    }
}

int updateGraphics(sf::RenderWindow &window, LessonDialogueGraphics &MappedLessonDialogueGraphics,
                   std::list<std::pair<int, std::string> > & Dialogue, sf::Clock &clock,
                   sf::Clock &clock2, bool &holo, bool &skip, bool type){
    sf::Event event;
    if (sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        return 0;
    }
    
    window.clear();
    
    sf::Font DialogueFont;
    if (!DialogueFont.loadFromFile(resourcePath() + "sansation.ttf")) {
        std::cerr << "Font not found" << std::endl;
    }
    sf::Text DialogueText;
    DialogueText.setFont(DialogueFont);
    DialogueText.setColor(sf::Color::White);
    
    sf::Sprite Background, Alberton, Companion, lessonSlide, holoImage;
    Background = MappedLessonDialogueGraphics.getDialogueBackround();
    Background.setPosition(0,0);
    window.draw(Background);
    if ( type == 0){
        Alberton = MappedLessonDialogueGraphics.getProfessorSprite();
        Alberton.setPosition(64, 460);
        window.draw(Alberton);
        
        Companion = MappedLessonDialogueGraphics.getCompanionSprite();
        Companion.setPosition(676, 460);
        window.draw(Companion);
    }
    std::list<std::pair<int, std::string> >::iterator it = Dialogue.begin();
    
    int speaker = it->first;
    std::string nextDialogue = it->second;
    DialogueText.setString(nextDialogue);
    
    if(speaker == 0){
        DialogueText.setPosition(280, 460);
    }
    else if(speaker == 1){
        DialogueText.setPosition(400, 600);
    }
    else if (speaker == 2){
        if (!TextureLessonSlide.loadFromFile(resourcePath() + nextDialogue)) {
                std::cerr << "ERROR with slide " << nextDialogue << std::endl;
        }
    }
    
    sf::Time elapsed1 = clock.getElapsedTime();
    sf::Time elapsed2 = clock2.getElapsedTime();
    if (elapsed1.asSeconds() > 3){
        if(it != Dialogue.end()){
            Dialogue.pop_front();
        }
        clock.restart();
    }
    if (elapsed2.asSeconds() > 0.05){
        std::random_device rd;
        std::default_random_engine e1(rd());
        std::uniform_int_distribution<int> uniform_dist(1, 3);
        if (uniform_dist(e1) == 1){
            if (!TextureHolo.loadFromFile(resourcePath() + "hologram1.png")) {
                std::cerr << "ERROR with HOLOGRAM 1 "<< std::endl;
            }
        }else if (uniform_dist(e1) == 2){
            if (!TextureHolo.loadFromFile(resourcePath() + "hologram2.png")) {
                std::cerr << "ERROR with HOLOGRAM 2 "<< std::endl;
            }
        }else if (uniform_dist(e1) == 3){
            if (!TextureHolo.loadFromFile(resourcePath() + "hologram3.1.png")) {
                std::cerr << "ERROR with HOLOGRAM 3 "<< std::endl;
            }
        }
        clock2.restart();
    }
    if (skip == true){
        if(it != Dialogue.end()){
            Dialogue.pop_front();
        }
        it++;
        skip = false;
        clock.restart();
    }
    if (speaker != 2){
        window.draw(DialogueText);
    }
    std::cout << type << std::endl;
    if (type == 1){
        lessonSlide.setTexture(TextureLessonSlide);
        lessonSlide.setPosition(91, 179);
        holoImage.setTexture(TextureHolo);
        window.draw(holoImage);
        window.draw(lessonSlide);
    }
    
    window.display();
    it = Dialogue.begin();
    if(it != Dialogue.end()){
        return 1;
    }else{
        return 0;
    }
}

std::list<std::pair<int, std::string> > read(std::string filename) {
    std::list<std::pair<int, std::string> > DialogueCommands;
    std::ifstream infile;
    infile.open(resourcePath() + filename.c_str(), std::ifstream::in);
    
    if (!infile.good()){
        std::cout << "Problem opening lesson file" << std::endl;
        exit(0);
    }
    
    std::string command;
    while (std::getline(infile, command)){
        std::string token = command.substr(0, command.find(":"));
        if (token.compare("Professor") == 0){
            int speaking = 0;
            std::pair<int, std::string> speaker_dialogue;
            std::string::size_type i = command.find("Professor: ");
            if (i != std::string::npos){
                command.erase(i, token.length() + 2);
            }
            speaker_dialogue.first = speaking;
            speaker_dialogue.second = command;
            DialogueCommands.push_back(speaker_dialogue);
        }
        if (token.compare("Companion") == 0){
            int speaking = 1;
            std::string::size_type i = command.find("Companion: ");
            if (i != std::string::npos){
                command.erase(i, token.length() + 2);
            }
            std::pair<int, std::string> speaker_dialogue;
            speaker_dialogue.first = speaking;
            speaker_dialogue.second = command;
            DialogueCommands.push_back(speaker_dialogue);
        }
        if (token.compare("Slide") == 0){
            int speaking = 2;
            std::string::size_type i = command.find("Slide: ");
            if (i != std::string::npos){
                command.erase(i, token.length() + 2);
            }
            std::pair<int, std::string> speaker_dialogue;
            speaker_dialogue.first = speaking;
            speaker_dialogue.second = command;
            DialogueCommands.push_back(speaker_dialogue);
        }
    }
    return DialogueCommands;
}
    
//98,197