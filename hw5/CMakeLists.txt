cmake_minimum_required(VERSION 3.10)
project(hw5)

set(CMAKE_CXX_STANDARD 11)

#File Stream
configure_file(res/score.dat res/score.dat COPYONLY)

#Images
configure_file(res/images/background.png res/images/background.png COPYONLY)
configure_file(res/images/rocket.png res/images/rocket.png COPYONLY)
configure_file(res/images/platform.png res/images/platform.png COPYONLY)
configure_file(res/images/fire.png res/images/fire.png COPYONLY)
configure_file(res/images/ufo.png res/images/ufo.png COPYONLY)
configure_file(res/images/shoot.png res/images/shoot.png COPYONLY)
configure_file(res/images/icon.png res/images/icon.png COPYONLY)
configure_file(res/images/menuBackground.png res/images/menuBackground.png COPYONLY)
configure_file(res/images/pauseBackground.png res/images/pauseBackground.png COPYONLY)
configure_file(res/images/highScoreLine.png res/images/highScoreLine.png COPYONLY)
configure_file(res/images/infoWindow.png res/images/infoWindow.png COPYONLY)

#Sounds/Music
configure_file(res/sounds/galaxynauts.ogg res/sounds/galaxynauts.ogg COPYONLY)
configure_file(res/sounds/burn.ogg res/sounds/burn.ogg COPYONLY)
configure_file(res/sounds/shoot.ogg res/sounds/shoot.ogg COPYONLY)
configure_file(res/sounds/hit.ogg res/sounds/hit.ogg COPYONLY)
configure_file(res/sounds/fall.ogg res/sounds/fall.ogg COPYONLY)

#Fonts
configure_file(res/fonts/Audiowide-Regular.ttf res/fonts/Audiowide-Regular.ttf COPYONLY)

# Define sources and executable
set(EXECUTABLE_NAME "hw5")

add_executable(${EXECUTABLE_NAME} main.cpp src/point.cpp src/point.h)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/res//cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()