cmake_minimum_required(VERSION 3.10)
project(hw6)

set(CMAKE_CXX_STANDARD 11)

#Scores data
configure_file(res/scores.dat res/scores.dat COPYONLY)

#Images
configure_file(res/images/background.jpg res/images/background.jpg COPYONLY)
configure_file(res/images/fire_blue.png res/images/fire_blue.png COPYONLY)
configure_file(res/images/rock.png res/images/rock.png COPYONLY)
configure_file(res/images/rock_small.png res/images/rock_small.png COPYONLY)
configure_file(res/images/spaceship.png res/images/spaceship.png COPYONLY)
configure_file(res/images/ufo.png res/images/ufo.png COPYONLY)
configure_file(res/images/pause.png res/images/pause.png COPYONLY)
configure_file(res/images/explosions/type_B.png res/images/explosions/type_B.png COPYONLY)
configure_file(res/images/explosions/type_C.png res/images/explosions/type_C.png COPYONLY)
configure_file(res/images/icon.png res/images/icon.png COPYONLY)
configure_file(res/images/instructions.jpg res/images/instructions.jpg COPYONLY)

#Fonts
configure_file(res/fonts/joystix-monospace.ttf res/fonts/joystix-monospace.ttf COPYONLY)

#Sounds
configure_file(res/sounds/shoot.ogg res/sounds/shoot.ogg COPYONLY)
configure_file(res/sounds/ufo.ogg res/sounds/ufo.ogg COPYONLY)
configure_file(res/sounds/game-over.ogg res/sounds/game-over.ogg COPYONLY)
configure_file(res/sounds/explode.ogg res/sounds/explode.ogg COPYONLY)


# Define sources and executable
set(EXECUTABLE_NAME "hw6")

add_executable(${EXECUTABLE_NAME} main.cpp src/Animation.h src/Animation.cpp src/Entity.cpp
               src/Entity.h src/Asteroid.cpp src/Asteroid.h src/Bullet.cpp src/Bullet.h src/Player.cpp src/Player.h src/Ufo.cpp src/Ufo.h src/Scoreboard.cpp src/Scoreboard.h)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()