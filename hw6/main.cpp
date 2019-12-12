/***********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 11/4/2019
 *    Project Name: hw6
 *     Description: Asteroids is a game where you play as a space ship and avoid asteroids.
 *       Resources: Original Code by FamTrinli from https://www.youtube.com/watch?v=rWaSo2usU4A
 *                      under Standard YouTube License
 *
 *                  Music and Sounds
 *                  Shoot by LittleRobotSoundFactory on www.freesound.org under Creative Commons Attribute License
 *                  Explode by V-ktor on www.freesound.org under Creative Commons Attribute License
 *
 *                  Images
 *                  UFO by Freepik from www.flaticon.com under Free License (with attribution)
 *
 *                  Fonts
 *                  Joystix Monospace by Raymond Larabie from www.1001freefonts.com under Typodermic Fonts Inc. End User
 *                      License Agreement
 *    Extra Credit: Levels - IMPORTANT **My version of levels doesn't spawn 15 new asteroids every time, but rather it
 *                      increments the number by each level. Whenever a player destroys all asteroids then it spawns in
 *                      five asteroids plus which ever level the player is on. This is an added feature but still uses
 *                      the same principles as required by Part 3.
 *                  Scoreboard - Created a class called scoreboard which handles the games scoreboard. The scoreboard is
 *                      a vector of pairs holding a string and a integer score. The scoreboard automatically sorts
 *                      incoming scores and can return a string of the curently saved scoreboard. You can also import
 *                      scores from a file and on destruction of the object it automatically saves scores to a file so
 *                      that they are saved between program runs.
 *                  Principle of Least Privilege - All classes have been reworked and put under the src directory. All
 *                      classes now follow the principle of least privilege and use getters setters. Also cleaned up all
 *                      code to uniform style.
 *                  Game State - Incorporated game states to handle the flow of the entire game system. All game states
 *                      are documented below.
 *                  Other Minor Changes - Added sounds, auto-pause on games loss of focus, turning has velocity, added
 *                      icon to RenderWindow
 *      Game State: 0 = Main Menu
 *                  1 = Main Menu Set-Up
 *                  2 = Pause Menu
 *                  3 = Pause Menu Set-Up
 *                  4 = Instructions Menu
 *                  5 = Game
 *                  6 = Game Set-Up
 *                  7 = Score Screen
 *                  8 = Score Screen Set-Up
 *                  9 = Instructions Menu Set-Up
 **********************************************************************************************************************/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <list>
#include <iostream>
#include "src/Animation.h"
#include "src/Asteroid.h"
#include "src/Bullet.h"
#include "src/Player.h"
#include "src/Ufo.h"
#include "src/Scoreboard.h"

/* Function Prototypes */
bool isCollide(Entity *a, Entity *b);

int main() {

    srand(time(0));     //Random seet

    /* Set Up Window */
    sf::RenderWindow app(sf::VideoMode(Entity::getWidth(), Entity::getHeight()), "Asteroids!");
    app.setFramerateLimit(60);
    sf::Image icon;
    if(!icon.loadFromFile("res/images/icon.png")) { return EXIT_FAILURE; }
    app.setIcon(64, 64, icon.getPixelsPtr());

    /* Textures */
    sf::Texture t1,t2,t3,t4,t5,t6,t7,tUfo,tMenu,tPause, tInstruct;
    if(!t1.loadFromFile("res/images/spaceship.png")) { return EXIT_FAILURE; }
    if(!t2.loadFromFile("res/images/background.jpg")) { return EXIT_FAILURE; }
    if(!t3.loadFromFile("res/images/explosions/type_C.png")) { return EXIT_FAILURE; }
    if(!t4.loadFromFile("res/images/rock.png")) { return EXIT_FAILURE; }
    if(!t5.loadFromFile("res/images/fire_blue.png")) { return EXIT_FAILURE; }
    if(!t6.loadFromFile("res/images/rock_small.png")) { return EXIT_FAILURE; }
    if(!t7.loadFromFile("res/images/explosions/type_B.png")) { return EXIT_FAILURE; }
    if(!tUfo.loadFromFile("res/images/ufo.png")) { return EXIT_FAILURE; }
    if(!tPause.loadFromFile("res/images/pause.png")) { return EXIT_FAILURE; }
    if(!tInstruct.loadFromFile("res/images/instructions.jpg")) { return EXIT_FAILURE; }
    t1.setSmooth(true);
    t2.setSmooth(true);

    /* Sprites and Animations */
    sf::Sprite sBackground(t2), sPause(tPause), sInstruct(tInstruct);
    Animation sExplosion(t3, 0,0,256,256, 48, 0.5);
    Animation sRock(t4, 0,0,64,64, 16, 0.2);
    Animation sRock_small(t6, 0,0,64,64, 16, 0.2);
    Animation sBullet(t5, 0,0,32,64, 16, 0.8);
    Animation sPlayer(t1, 40,0,40,40, 1, 0);
    Animation sPlayer_go(t1, 40,40,40,40, 1, 0);
    Animation sExplosion_ship(t7, 0,0,192,192, 64, 0.5);
    Animation sUfo(tUfo, 0,14,64,36, 1, 0);

    /* Sound Buffers, Sounds, and Music */
    sf::SoundBuffer shootBuff, ufoBuff, gameOverBuff, explodeBuff;
    if(!shootBuff.loadFromFile("res/sounds/shoot.ogg")) { return EXIT_FAILURE; }
    if(!ufoBuff.loadFromFile("res/sounds/ufo.ogg")) { return EXIT_FAILURE; }
    if(!gameOverBuff.loadFromFile("res/sounds/game-over.ogg")) { return EXIT_FAILURE; }
    if(!explodeBuff.loadFromFile("res/sounds/explode.ogg")) { return EXIT_FAILURE; }
    sf::Sound shootSound(shootBuff), ufoSound(ufoBuff), gameOverSound(gameOverBuff), explodeSound(explodeBuff);
    ufoSound.setLoop(true);

    /* Font and Texts */
    sf::Font font;
    if(!font.loadFromFile("res/fonts/joystix-monospace.ttf")) { return EXIT_FAILURE; }
    sf::Text scoreText("", font), scoresText("", font), message("", font),
    secondaryMessage("", font), title("", font, 75);
    scoresText.setPosition(float(Entity::getWidth()) / 2.0f - 75, 200);

    /* Scoreboard */
    Scoreboard scores("res/scores.dat");
    if(!scores.importFromFile()) { return EXIT_FAILURE; }

    /* Variables */
    std::list<Entity*> entities;
    auto *p = new Player();
    int score = 0;
    int gameState = 1;
    int shootLock = 0;
    int blink = 50;
    int level = 1;
    int inputLocation = 0;
    int countdown = 0;      //Used to prevent user inputs being registered multiple times after each other
    int tmpDimensionX = 0;
    int tmpDimensionY = 0;
    bool blinkState = false;
    bool ufoLock = false;
    char inputChars [4];
    char tmpChar = 'A';
    std::string upperStr;
    std::string bottomStr;
    std::string inputStr;

    /* Main Loop */
    while(app.isOpen()) {

        sf::Event event{};

        /* Main Menu */
        if(gameState == 0) {

            /* User Input */
            if(countdown < 0) {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && app.hasFocus()) {     //Space to play
                    gameState = 6;      //Switch to game set-up
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::I) && app.hasFocus()) {     //'I' for instructions
                    gameState = 9;      //Switch to instructions set-up
                }
            }
            else {
                countdown--;
            }

            /* Blink */
            if(blink < 0) {
                blink = 40;
                blinkState = not blinkState;
            }
            blink--;

            /* Draw */
            app.draw(sBackground);
            app.draw(title);
            app.draw(scoresText);
            app.draw(secondaryMessage);
            if(blinkState) {        //Display elements to blink
                app.draw(message);
            }
            app.display();
        }

        /* Main Menu Set-Up */
        if(gameState == 1) {

            /* Set Up Variables */
            title.setString("Asteroids!");
            title.setPosition(float(Entity::getWidth()) / 2.0f - 290, 20);
            message.setString("Press 'Space' to Start");
            message.setPosition(float(Entity::getWidth()) / 2.0f - 275, float(Entity::getHeight()) - 200);
            secondaryMessage.setString("Press 'I' For Instructions\nPress 'P' In-Game to Pause");
            secondaryMessage.setPosition(float(Entity::getWidth()) / 2.0f - 325,
                                         float(Entity::getHeight()) - 100);
            scoresText.setString(scores.toString());
            blinkState = true;
            blink = 70;
            countdown = 50;

            /* Draw */
            app.draw(sBackground);
            app.draw(message);
            app.draw(secondaryMessage);
            app.draw(title);
            app.draw(scoresText);
            app.display();
            gameState = 0;      //Switch to menu
        }

        /* Pause Menu */
        if(gameState == 2) {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && app.hasFocus()) {     //Resume on 'Space'
                if(ufoLock) {       //Resume ufo sound if on screen
                    ufoSound.play();
                }
                gameState = 5;      //Switch back to game
            }
        }

        /* Pause Menu Set-Up */
        if(gameState == 3) {

            ufoSound.pause();
            gameState = 2;      //Switch to pause menu

            /* Draw */
            app.draw(sPause);
            message.setString("Press 'Space' to Resume");
            message.setPosition(float(Entity::getWidth()) / 2.0f - 290, float(Entity::getHeight()) - 200);
            app.draw(message);
            app.display();
        }

        /* Instructions Menu */
        if(gameState == 4) {
            /* Countdown */
            if(countdown < 0) {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::I) && app.hasFocus()) {
                    gameState = 1;      //Switch to menu set-up
                }

                /* Blink*/
                if(blink < 0) {
                    blinkState = not blinkState;
                    blink = 40;
                }

                /* Draw */
                app.draw(sInstruct);
                if(blinkState) {
                    app.draw(secondaryMessage);
                }
                blink--;
                app.draw(title);
                app.display();

            }
            else {
                countdown--;
                app.draw(sInstruct);
                app.draw(title);
                app.draw(secondaryMessage);
                app.display();
            }
        }

        /* Instructions Menu Set-Up */
        if(gameState == 9) {
            secondaryMessage.setString("Press 'I' To Go Back To Menu");
            title.setString("Instructions");
            title.setPosition(float(Entity::getWidth()) / 2.0f - 350, 20);
            countdown = 50;
            blinkState = true;
            blink = 40;
            gameState = 4;      //Switch to instructions menu
        }

        /* Game */
        if(gameState == 5) {

            /* User Input */
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shootLock < 0) {
                shootLock = 10;
                auto *b = new Bullet();
                b->settings(sBullet, p->getX(), p->getY(), p->getAngle(), 10);
                entities.push_back(b);
                shootSound.play();
            }
            shootLock--;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {       //Rotate right
                p->setDAngle(p->getDAngle() + 0.75f);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {        //Rotate left
                p->setDAngle(p->getDAngle() - 0.75f);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::P) || not app.hasFocus()) {     //Pause menu
                gameState = 3;      //Switch to pause set-up
            }
            p->setThrust(sf::Keyboard::isKeyPressed(sf::Keyboard::Up));     //Thrust on 'Up'

            /* Collision Detection */
            for(auto a:entities) {
                for(auto b:entities) {

                    /* Asteroid/UFO and Bullet Collision (Entity Destroyed) */
                    if((a->getName() == "asteroid" || a->getName() == "ufo") && b->getName() == "bullet") {
                        if(isCollide(a, b)) {

                            /* Set Lives */
                            a->setLife(false);
                            b->setLife(false);

                            /* Scoring */
                            if(a->getName() == "asteroid") {
                                score++;
                            }
                            else {
                                score += 5;
                            }

                            /* Explosion */
                            explodeSound.play();
                            auto *e = new Entity();
                            e->settings(sExplosion, a->getX(), a->getY());
                            e->setName("explosion");
                            entities.push_back(e);

                            /* Create Two Small Rocks If ptr a Is A Big Rock*/
                            if(a->getRadius() == 25) {
                                for(int i = 0; i < 2; i++) {
                                    Entity *eAsteroid = new Asteroid();
                                    eAsteroid->settings(sRock_small, a->getX(), a->getY(),
                                                        float(int(rand()) % 360), 15);
                                    entities.push_back(eAsteroid);
                                }
                            }
                        }
                    }

                    /* Player and Asteroid/UFO Collision (Game Over) */
                    if(a->getName() == "player" && (b->getName() == "asteroid" || b->getName() == "ufo")) {
                        if(isCollide(a, b)) {

                            /* Set Life */
                            b->setLife(false);

                            /* Explosion */
                            gameOverSound.play();
                            auto *e = new Entity();
                            e->settings(sExplosion_ship, a->getX(), a->getY());
                            e->setName("explosion");
                            entities.push_back(e);

                            /* Reset Player */
                            p->setThrust(false);
                            p->setDx(0);
                            p->setDy(0);
                            p->setDAngle(0);

                            /* End Game */
                            gameState = 8;      //Switch to score screen set-up
                        }
                    }
                }
            }

            /* Level Complete Check */
            if(Asteroid::getCount() == 0) {      //If all asteroids gone
                level++;
                score += 5;
                gameState = 6;      //Switch to game set-up
            }

            /* Thrust Animation */
            if(p->getThrust()) {
                p->setAnimation(sPlayer_go);
            }
            else {
                p->setAnimation(sPlayer);
            }

            /* End Life of Explosion If At End*/
            for(auto e:entities) {
                if(e->getName() == "explosion") {
                    if(e->isEnd()) {
                        e->setLife(false);
                    }
                }
            }

            /* UFO Generation */
            if(rand() % 500 == 0 && not ufoLock) {
                ufoLock = true;
                auto *a = new Ufo();
                a->settings(sUfo, 0, float(rand() % (Entity::getHeight() - 64)), 270, 32);
                entities.push_back(a);
                ufoSound.play();
            }

            /* Go Through All Entities */
            for(auto i = entities.begin(); i != entities.end();) {
                Entity *e = *i;

                /* Update Entities */
                e->update();
                e->updateAnimation();

                /* Remove End-Of-Life Entities */
                if(not e->isLife()) {
                    i = entities.erase(i);
                    delete e;

                    /* Unlock If Entity is Ufo*/
                    if(e->getName() == "ufo") {
                        ufoLock = false;
                        ufoSound.pause();
                    }
                }
                else {
                    i++;
                }
            }

            /* Draw */
            scoreText.setString("Score: " + std::to_string(score));
            app.draw(sBackground);
            for(auto i:entities) {      //Draw explosions on bottom
                if(i->getName() == "explosion") {
                    i->draw(app);
                }
            }
            for(auto i:entities) {      //Draw  asteroids, bullets, and ufos in the middle
                if(i->getName() == "ufo" || i->getName() == "asteroid" || i->getName() == "bullet") {
                    i->draw(app);
                }
            }
            p->draw(app);       //Draw player on top
            app.draw(scoreText);
            app.display();
        }

        /* Game Set-Up */
        if(gameState == 6) {

            /* Reset Variables */
            ufoSound.pause();
            ufoLock = false;
            countdown = 40;
            gameState = 5;      //Switch to game

            /* Initialize Entities */
            for(auto i:entities) {
                if(i->getName() != "player") {
                    delete i;
                }
            }
            entities.clear();
            p->settings(sPlayer,550,400,0,20);
            p->setThrust(false);
            p->setDx(0);
            p->setDy(0);
            p->setDAngle(0);
            entities.push_back(p);
            for(int i = 0; i < 5 + level; i++) {

                /* Get a X and Y Not On Top of Player*/
                do {
                    tmpDimensionX = rand() % Entity::getWidth();
                    tmpDimensionY = rand() % Entity::getHeight();
                } while(tmpDimensionX < 800 && tmpDimensionX > 400 &&
                        tmpDimensionY < 600 && tmpDimensionY > 200);

                /* Create New Asteroid */
                auto *a = new Asteroid();
                a->settings(sRock, float(tmpDimensionX), float(tmpDimensionY),
                            float(int(rand()) % 360), 25);
                entities.push_back(a);
            }

            /* Blink */
            title.setString("Level " + std::to_string(level));
            title.setPosition(float(Entity::getWidth()) / 2.0f - 200, 300);
            blink = 120;
            while(blink >= 0) {
                app.draw(sBackground);
                if(blink % 40 < 20) {
                    for (auto i:entities) {
                        i->draw(app);
                    }
                }
                app.draw(title);
                app.display();
                blink--;
            }
        }

        /* Score Screen */
        if(gameState == 7) {

            /* User Input */
            if(countdown < 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
               app.hasFocus()) {     //Increment char up
                tmpChar++;
                countdown = 15;
            }
            else if(countdown < 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
                    app.hasFocus()) {      //Increment char down
                tmpChar--;
                countdown = 15;
            }
            else if(countdown < 0 && inputLocation < 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
                    app.hasFocus()) {      //Increment input location right
                inputChars[inputLocation] = tmpChar;
                if(inputChars[inputLocation + 1] != '_') {
                    tmpChar = inputChars[inputLocation + 1];
                }
                else {
                    tmpChar = 'A';
                }
                inputLocation ++;
                countdown = 15;
            }
            else if(countdown < 0 && inputLocation > 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
                    app.hasFocus()) {       //Increment input location left
                inputChars[inputLocation] = tmpChar;
                tmpChar = inputChars[inputLocation - 1];
                inputLocation --;
                countdown = 15;
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && inputChars[2] != '_' &&
                    app.hasFocus()) {      //Submit
                inputChars[inputLocation] = tmpChar;
                gameState = 1;      //Switch to menu set-up
                scores.addScore(score, inputChars);
                score = 0;
            }

            /* Limit Character Input */
            if(tmpChar > 90) {
                tmpChar = 'A';
            }
            else if(tmpChar < 65) {
                tmpChar = 'Z';
            }

            /* Input String Display Handler */
            if(inputLocation < 3) {

                /* Blink*/
                if(blink < 0) {
                    blinkState = not blinkState;
                    blink = 7;
                }
                if(blinkState) {
                    inputChars[inputLocation] = ' ';
                }
                else {
                    inputChars[inputLocation] = tmpChar;
                }

                /* Iterate Variables */
                blink--;
                countdown--;

                /* Set Strings */
                if(inputLocation == 0) {
                    upperStr = " ^  \n";
                    bottomStr = "\n v  ";
                    inputStr = " " + std::string(inputChars) + ">";
                }
                else if(inputLocation == 1) {
                    upperStr = "  ^ \n";
                    bottomStr = "\n  v ";
                    inputStr = "<" + std::string(inputChars) + ">";
                }
                else if(inputLocation == 2) {
                    upperStr = "   ^\n";
                    bottomStr = "\n   v";
                    inputStr = "<" + std::string(inputChars) + " ";
                }

                /* Draw */
                title.setString(upperStr + inputStr + bottomStr);
                app.draw(sBackground);
                app.draw(scoreText);
                app.draw(title);
                app.draw(message);
                app.draw(secondaryMessage);
                app.display();
            }
        }

        /* Score Screen Set-Up */
        if(gameState == 8) {

            /* Reset Variables */
            ufoSound.pause();
            level = 1;

            /* Keep Game Updating For Countdown */
            if(countdown > 0) {
                app.draw(sBackground);
                app.draw(scoreText);
                for(auto e:entities) {
                    e->update();
                    e->updateAnimation();
                    e->draw(app);
                }
                app.display();
                countdown--;
            }
            else {      //Continue When Countdown Is Done

                /* Initialize Variables */
                title.setPosition(float(Entity::getWidth()) / 2.0f - 150, 250);
                message.setString("Use arrow keys to enter initials");
                secondaryMessage.setString("Press 'SPACE' to submit");
                message.setPosition(float(Entity::getWidth()) / 2.0f - 375, 150);
                secondaryMessage.setPosition(float(Entity::getWidth()) / 2.0f - 275,
                                             float(Entity::getHeight() - 200));
                countdown = 25;
                inputChars[0] = '_';
                inputChars[1] = '_';
                inputChars[2] = '_';
                inputLocation = 0;
                tmpChar = 'A';
                blink = 15;

                gameState = 7;      //Switch to score screen
            }
        }

        /* Application Closing Event */
        while(app.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {       //Closing application
                app.close();
            }
        }

        /* Update Width and Height */
        Entity::setWidth(app.getView().getSize().x);
        Entity::setHeight(app.getView().getSize().y);
    }

    return 0;
}

/**********************************************************************************************************************
 * Description: Checks if two Entities have collided
 *      Inputs: Entity *a - First entity  to check
 *              Entity *b - Second entity to check
 *     Outputs: bool - Whether or not the two entities are in collision
 **********************************************************************************************************************/
bool isCollide(Entity *a, Entity *b) {
    return (b->getX() - a->getX()) * (b->getX() - a->getX()) +
           (b->getY() - a->getY()) * (b->getY() - a->getY()) <
           (a->getRadius() + b->getRadius())*(a->getRadius() + b->getRadius());
}