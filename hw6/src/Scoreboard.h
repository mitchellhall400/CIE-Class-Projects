/**********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 11/4/2019
 *     Description: The header file for the class Scoreboard which stores the games scores.
 **********************************************************************************************************************/

#ifndef HW6_SCOREBOARD_H
#define HW6_SCOREBOARD_H

#include <set>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <fstream>

class Scoreboard {
private:
    std::vector<std::pair<int, std::string>> m_scores;
    std::string m_filePath;
    std::string m_outputString;

public:
    explicit Scoreboard(std::string filePath);
    ~Scoreboard();
    bool importFromFile();
    bool exportToFile();
    bool addScore(int score, const std::string &initials);
    const std::string & toString(bool isFullSize = false);

};

#endif //HW6_SCOREBOARD_H
