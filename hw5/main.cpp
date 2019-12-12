/***********************************************************************************************************************
 *       IMPORTANT: !!!All credit and license references to resources used can be found in README.md!!!
 *      Programmer: Mitchell Hall
 *            Date: 10/21/2019
 *    Project Name: hw5
 *     Description: Space jump is a simple game for introduction to SFML. It started based on an OSS doodle jump game.
 *       Resources: Original Code by FamTrinli from https://www.youtube.com/watch?v=7Vf_vQIUk5Q
 *                  under Standard YouTube License
 *
 *                  Music and Sounds
 *                  Background Music from www.PlayOnLoop.com under Creative Commons Attribute License
 *                  Rocket Burn by krystameredith on www.freesound.org under Creative Commons Attribute License
 *                  Shoot by V-ktor on www.freesound.org under Creative Commons Attribute License
 *                  UFO Hit by MortisBlack on www.freesound.org under Creative Commons Attribute License
 *                  Game Over by myfox14 on www.freesound.org under Creative Commons Attribute License
 *
 *                  Images
 *                  Space Ship by Good Ware from www.flaticon.com under Free License (with attribution)
 *                  Fuel Icon by Freepik from www.flaticon.com under Free License (with attribution)
 *                  All other images are original work by Mitchell Hall
 *
 *                  Fonts
 *                  Audiowide by Astigmatic One Eye Typographic Institute from www.1001freefonts.com
 *                  under Public domain, GPL, OFL
 **********************************************************************************************************************/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <random>
#include <fstream>
#include "src/point.h"

int main() {

    /* Seed For Random */
    std::random_device rand;

    /* Set Up Window*/
    sf::RenderWindow app(sf::VideoMode(400, 533), "Space Jump");
    sf::Image icon;
    if(!icon.loadFromFile("res/images/icon.png")) { return EXIT_FAILURE; }
    app.setFramerateLimit(60);
    app.setIcon(64, 64, icon.getPixelsPtr());

    /* Textures and Sprites */
    sf::Texture tBackground, tPlat, tRocket, tFire, tUfo, tShoot, tMenu, tPause, tHighScore, tInfoWindow;
    if(!tBackground.loadFromFile("res/images/background.png")) { return EXIT_FAILURE; }
    if(!tPlat.loadFromFile("res/images/platform.png")) { return EXIT_FAILURE; }
    if(!tRocket.loadFromFile("res/images/rocket.png")) { return EXIT_FAILURE; }
    if(!tFire.loadFromFile("res/images/fire.png")) { return EXIT_FAILURE; }
    if(!tUfo.loadFromFile("res/images/ufo.png")) { return EXIT_FAILURE; }
    if(!tShoot.loadFromFile("res/images/shoot.png")) { return EXIT_FAILURE; }
    if(!tMenu.loadFromFile("res/images/menuBackground.png")) { return EXIT_FAILURE; }
    if(!tPause.loadFromFile("res/images/pauseBackground.png")) { return EXIT_FAILURE; }
    if(!tHighScore.loadFromFile("res/images/highScoreLine.png")) { return EXIT_FAILURE; }
    if(!tInfoWindow.loadFromFile("res/images/infoWindow.png")) { return EXIT_FAILURE; }
    sf::Sprite sBackground, sBackgroundSecond(tBackground), sPlat(tPlat), sRocket(tRocket), sFire(tFire),
               sUfo(tUfo), sShoot(tShoot), sHighScore(tHighScore), sInfoWindow(tInfoWindow);

    /* Music */
    sf::Music backgroundMusic;
    if(!backgroundMusic.openFromFile("res/sounds/galaxynauts.ogg")) { return EXIT_FAILURE; }
    backgroundMusic.setLoop(true);

    /* Sound Buffers and Sounds */
    sf::SoundBuffer buffBurn, buffShoot, buffHit, buffFall;
    if(!buffBurn.loadFromFile("res/sounds/burn.ogg")) { return EXIT_FAILURE; }
    if(!buffShoot.loadFromFile("res/sounds/shoot.ogg")) { return EXIT_FAILURE; }
    if(!buffHit.loadFromFile("res/sounds/hit.ogg")) { return EXIT_FAILURE; }
    if(!buffFall.loadFromFile("res/sounds/fall.ogg")) { return EXIT_FAILURE; }
    sf::Sound burn(buffBurn), shoot(buffShoot), hit(buffHit), fall(buffFall);

    /* Text and Fonts */
    sf::Font audiowide;
    if(!audiowide.loadFromFile("res/fonts/Audiowide-Regular.ttf")) { return EXIT_FAILURE; }
    sf::Text scoreText;
    scoreText.setPosition(0,500);
    scoreText.setFont(audiowide);
    sf::Text menuScores;
    menuScores.setFont(audiowide);
    menuScores.setPosition(25,200);

    /* File Stream */
    float highScore = 0;
    std::ifstream fin("res/score.dat");
    if(!fin.good()) { return EXIT_FAILURE; }
    fin >> highScore;
    fin.close();
    std::ofstream fout("res/score.dat");
    if(!fout.good()) { return EXIT_FAILURE; }
    fout.close();

    /* Initialize Variables */
    point plat[6];
    float h = 200;
    float platsY[] = {44, 133, 222, 311, 400, 489};
    float dy = 0;
    float ufoDx = 1;
    float savedBackgroundY = 0;
    bool ufoRight = true;
    float score = 0;
    bool inGame = false;
    bool setupDone = false;
    bool pause = false;
    bool pauseSetup = false;
    bool infoDisplayed = false;

    /* Main Game Loop */
    while(app.isOpen()) {

        sf::Event e{};      //Declare event

        /* Check If Event Is Closed to Close App When Done */
        while(app.pollEvent(e)) {
            if(e.type == sf::Event::Closed) {
                app.close();
            }
        }

        /* Main Menu */
        if(not inGame) {

            /* One Time Setup */
            if(not setupDone) {
                if(score > highScore) {
                    highScore = score;
                    fout.open("res/score.dat");
                    fout << highScore;
                    fout.close();
                    menuScores.setString("NEW HIGHSCORE!\n\nScore: " + std::to_string(int(highScore/10)));
                }
                else {
                    menuScores.setString("Score: " + std::to_string(int(score/10)) +
                                         "\n\nHighscore: " + std::to_string(int(highScore/10)));
                }
                backgroundMusic.pause();
                burn.pause();
                sBackground.setPosition(0,0);
                sBackground.setTexture(tMenu);
                app.draw(sBackground);
                app.draw(menuScores);
                app.display();
                setupDone = true;
            }

            /* Information Menu */
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::C) && infoDisplayed) {
                app.draw(sBackground);
                app.draw(menuScores);
                app.display();
                infoDisplayed = false;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::I) && !infoDisplayed) {
                app.draw(sBackground);
                app.draw(sInfoWindow);
                app.display();
                infoDisplayed = true;
            }

            /* Wait For Resume Key Press */
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::R) && !infoDisplayed) {
                inGame = true;
                setupDone = false;
            }

        }

        /* Pause Menu */
        if((not app.hasFocus() || pause) && inGame) {

            /* First Time Setup*/
            if(not pauseSetup) {
                savedBackgroundY = sBackground.getPosition().y;
                pause = true;
                pauseSetup = true;
                burn.pause();
                backgroundMusic.pause();
                sBackground.setPosition(0, 0);
                sBackground.setTexture(tPause);
                app.draw(sBackground);
                app.display();
            }

            /* Look For Resume Key Press */
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::R) && app.hasFocus()) {
                inGame = true;
                pause = false;
                pauseSetup = false;
                backgroundMusic.play();
                sBackground.setPosition(0, savedBackgroundY);
                sBackground.setTexture(tBackground);
                app.draw(sBackground);
                app.display();
            }
        }

        /* In Game */
        if(inGame && app.hasFocus() && not pause) {

            /* One Time Setup */
            if(not setupDone) {
                backgroundMusic.play();
                sBackground.setTexture(tBackground);
                sHighScore.setPosition(0, float(-highScore) + 172);
                for(int i = 0; i <= 5; i++) {
                    plat[i].setX(float(int(rand() % 332)));
                    plat[i].setY(platsY[i]);
                }
                plat[5].setX(166);
                sBackgroundSecond.setPosition(0, -533);
                sFire.setPosition(0,700);
                sUfo.setPosition(0,700);
                sShoot.setPosition(0, -50);
                sRocket.setPosition(160, 400);
                dy = 0;
                score = 0;
                setupDone = true;
            }

            /* Keyboard Update Events */
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                sRocket.setPosition(sRocket.getPosition().x + 4, sRocket.getPosition().y);
                if(sRocket.getPosition().x > 388) {
                    sRocket.setPosition(sRocket.getPosition().x - 468, sRocket.getPosition().y);
                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                sRocket.setPosition(sRocket.getPosition().x - 4, sRocket.getPosition().y);
                if(sRocket.getPosition().x < -68) {
                    sRocket.setPosition(sRocket.getPosition().x + 468, sRocket.getPosition().y);
                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sShoot.getPosition().y < 0) {
                sShoot.setPosition(sRocket.getPosition().x + 28, sRocket.getPosition().y);
                shoot.play();
            }
            sShoot.setPosition(sShoot.getPosition().x, sShoot.getPosition().y - 10);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
                pause = true;
            }

            /* Increment dy and Set New Rocket Y Position */
            dy += 0.18;
            sRocket.setPosition(sRocket.getPosition().x, sRocket.getPosition().y + dy);

            /* End Game If Rocket Falls Too Low */
            if(sRocket.getPosition().y > 500) {
                dy = -9;
                inGame = false;
                setupDone = false;
                fall.play();
            }

            /* Update Scrolling Effect Positions */
            if(sRocket.getPosition().y < h) {

                /* Update Platforms */
                for(auto & platI : plat) {
                    sRocket.setPosition(sRocket.getPosition().x, h);
                    platI.setY(platI.getY() - dy);

                    /* Recycle Platforms If At Bottom */
                    if(platI.getY() > 533) {
                        platI.setY(float(int(platI.getY()) % 533));
                        platI.setX(float(rand() % 332));
                        if(dy >= -9 && sFire.getPosition().y > 600 && rand() % 8 == 1) {
                            sFire.setPosition(platI.getX() + 18, platI.getY() - 32);
                        } else if(dy >= -9 && sUfo.getPosition().y > 600 && rand() % 6 == 1) {
                            sUfo.setPosition(platI.getX() + 18, platI.getY() - 80);
                        }
                    }

                }

                /* Increment All Other Moving Sprites */
                sFire.setPosition(sFire.getPosition().x, sFire.getPosition().y - dy);
                sUfo.setPosition(sUfo.getPosition().x, sUfo.getPosition().y - dy);
                sHighScore.setPosition(sHighScore.getPosition().x, sHighScore.getPosition().y - dy);

                /* Background Scroll */
                sBackground.setPosition(0, float(sBackground.getPosition().y - (dy / 10.0)));
                if(sBackground.getPosition().y > 533) {
                    sBackground.setPosition(0, sBackground.getPosition().y - 533);
                }
                sBackgroundSecond.setPosition(0, sBackground.getPosition().y - 533);

                score -= dy;        //Increase score
            }

            /* Platform and Rocket Collision */
            float rocketX = sRocket.getPosition().x;
            float rocketY = sRocket.getPosition().y;
            for(auto & platI : plat) {
                if ((rocketX + 68 > platI.getX()) && (rocketX + 12 < platI.getX() + 68) &&
                    (rocketY + 65 > platI.getY()) && (rocketY + 60 < platI.getY() + 14) && (dy > 0)) {
                    dy = -9;
                }
            }

            /* Fire Boost and Rocket Collision */
            float fireX = sFire.getPosition().x;
            float fireY = sFire.getPosition().y;
            if((rocketX + 68 > fireX) && (rocketX + 12 < fireX + 32) &&
               (rocketY + 65 > fireY) && (rocketY + 60 < fireY + 32) && (dy > 0)) {
                dy = -22;
            }

            /* UFO and Rocket Collision */
            float ufoX = sUfo.getPosition().x;
            float ufoY = sUfo.getPosition().y;
            if((ufoX + 64 > rocketX + 12) && (ufoX < rocketX + 68) &&
               (ufoY + 50 > rocketY) && (ufoY + 14 < rocketY + 64)) {
                if(dy >= -9) {
                    fall.play();
                    inGame = false;
                    setupDone = false;
                }
                else {
                    sUfo.setPosition(0, 700);
                    hit.play();
                }
            }

            /* UFO and Shoot Collision */
            float shootX = sShoot.getPosition().x;
            float shootY = sShoot.getPosition().y;
            if((ufoX + 64 > shootX + 2) && (ufoX < shootX + 22) && (ufoY + 32 > shootY + 4) && (ufoY < shootY + 22)) {
                sUfo.setPosition(0, 700);
                sShoot.setPosition(0, -50);
                hit.play();
            }

            /* Rocket Flying Burn Effect */
            if(dy > 5 || dy < -5) {
                if(burn.getStatus() != sf::Sound::Playing) {
                    burn.play();
                }
                sRocket.setTextureRect(sf::IntRect(0, 0, 80, 80));
            }
            else {
                burn.pause();
                sRocket.setTextureRect(sf::IntRect(0, 0, 80, 65));
            }

            /* UFO Side-To-Side Movement */
            if(ufoDx > 1 || ufoDx < -1) {
                ufoRight = !ufoRight;
            }
            if(ufoRight) {
                ufoDx -= 0.03;
                sUfo.setPosition(sUfo.getPosition().x + ufoDx, sUfo.getPosition().y);
            }
            else {
                ufoDx += 0.03;
                sUfo.setPosition(sUfo.getPosition().x + ufoDx, sUfo.getPosition().y);
            }

            /* Draw All Sprites */
            app.draw(sBackground);
            app.draw(sBackgroundSecond);
            app.draw(sHighScore);
            for(auto & platI : plat) {
                sPlat.setPosition(float(platI.getX()), float(platI.getY()));        //Update platform sprite position
                app.draw(sPlat);
            }
            scoreText.setString("Score: " + std::to_string(int(score / 10)));
            app.draw(sFire);
            app.draw(sUfo);
            app.draw(sShoot);
            app.draw(sRocket);
            app.draw(scoreText);

            /* Refresh App */
            app.display();
        }

    }

    return 0;
}
