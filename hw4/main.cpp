/**********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 10/16/2019
 *    Project Name: hw4
 *     Description: The  cpp file to outline all methods for the class Address which stores info for a physical address.
 **********************************************************************************************************************/
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

/**********************************************************************************************************************
 * Class point - holds an x and y value
 **********************************************************************************************************************/
class point {
private:
    int m_x{}, m_y{};

public:
    explicit point(int x = 0, int y = 0) {      //Constructor
        this -> m_x = x;
        this -> m_y = y;
    }

    void setX(int x) {
        this -> m_x = x;
    }

    void setY(int y) {
        this -> m_y = y;
    }

    int getX() {
        return m_x;
    }

    int getY() {
        return m_y;
    }

};


/**********************************************************************************************************************
 * Main Loop
 **********************************************************************************************************************/
int main() {

    /* Seed For Random */
    srand(time(0));

    /* Set Up Window*/
    sf::RenderWindow app(sf::VideoMode(400, 533), "Doodle Game!");
    app.setFramerateLimit(60);

    /* Create Textures */
    sf::Texture t1, t2, t3;
    if (!t1.loadFromFile("images/background.png")) {
        return EXIT_FAILURE;
    }
    if(!t2.loadFromFile("images/platform.png")) {
        return EXIT_FAILURE;
    }
    if(!t3.loadFromFile("images/doodle.png")) {
        return EXIT_FAILURE;
    }

    /* Initialize Variables */
    sf::Sprite sBackground(t1), sPlat(t2), sPers(t3);       //Sprites from textures
    point plat[20];     //Create array of 20 platforms (plat)
    point persPoint(100, 100);      //The doodles x and y coord
    int h = 200;        //Middle/max height of doodle
    float dy = 0;       //Velocity of elements when they need to move vertically

    /* Initialize  All Platforms To Random */
    for(int i = 0; i < 10; i++) {
        plat[i].setX(rand() % 400);
        plat[i].setY(rand() % 533);
    }


    /* Main Game Loop */
    while(app.isOpen()) {

        sf::Event e{};      //Declare event

        /* Check If Event Is Closed to Close App When Done */
        while(app.pollEvent(e)) {
            if(e.type == sf::Event::Closed) {
                app.close();
            }
        }

        /* Keyboard Update Events */
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {       //Right
            persPoint.setX(persPoint.getX() + 3);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {        //Left
            persPoint.setX(persPoint.getX() - 3);
        }

        /* Increment dy and Set New Doodle Y Position */
        dy += 0.2;
        persPoint.setY(persPoint.getY() + int(dy));

        /* If Sprite Hits The Bottom Then Set dy To Bounce Back Up  */
        if(persPoint.getY() > 500) {
            dy = -10;
        }

        /* Update Platform Positions */
        if(persPoint.getY() < h) {      //If Doodle is above halfway
            for(int i = 0; i < 10; i++) {
                persPoint.setY(h);      //Lock in Doodle position at halfway
                plat[i].setY(plat[i].getY() - int(dy));     //Move the platforms down
                if(plat[i].getY() > 533) {      //If platform goes off screen move it to new random X at top
                    plat[i].setY(0);
                    plat[i].setX((rand() % 350) - 25);
                }
            }
        }

        /* Check If Doodle Is Hitting A Platform and Change Direction*/
        for(int i = 0; i < 10; i++) {
            if((persPoint.getX() + 50 > plat[i].getX()) && (persPoint.getX() + 20 < plat[i].getX() + 68) &&
               (persPoint.getY() + 70 > plat[i].getY()) && (persPoint.getY() + 70 < plat[i].getY() + 14) && (dy > 0)) {
                dy = -10;
            }
        }

        sPers.setPosition(float(persPoint.getX()), float(persPoint.getY()));        //Update doodle sprite position

        /* Draw All Sprites */
        app.draw(sBackground);
        app.draw(sPers);
        for(int i = 0; i < 10; i++) {
            sPlat.setPosition(float(plat[i].getX()), float(plat[i].getY()));        //Update platform sprite position
            app.draw(sPlat);
        }

        /* Refresh App */
        app.display();

    }

    return 0;
}
