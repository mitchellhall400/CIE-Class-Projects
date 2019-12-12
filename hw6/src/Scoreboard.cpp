/**********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 11/4/2019
 *     Description: The cpp file to outline all methods for the class Scoreboard which stores the games scores.
 **********************************************************************************************************************/

#include "Scoreboard.h"

/* Constructor */
Scoreboard::Scoreboard(std::string filePath) {
    m_filePath = std::move(filePath);
}

/* Destructor */
Scoreboard::~Scoreboard() {
    exportToFile();
}

/**********************************************************************************************************************
 * Description: Adds a score as a pair to m_scores
 *      Inputs: std::string - Three characters as a string to be added (initials)
 *              int score - Score to be added
 *     Outputs: bool - If the added score was a highscore
 **********************************************************************************************************************/
bool Scoreboard::addScore(int score, const std::string &initials) {
    /* High Score */
    bool isHighScore = false;
    if(not m_scores.empty()) {
        isHighScore = m_scores.at(0).first <= score;
    }

    /* Addition of Score */
    bool found = false;
    auto *addPair = new std::pair<int, std::string>;
    addPair->first = score;
    addPair->second = initials;
    for(auto &pair: m_scores) {
        if(addPair->second == pair.second) {
            found = true;
            if(addPair->first > pair.first) {
                pair.first = addPair->first;
            }
        }
    }
    if(not found) {
        m_scores.push_back(*addPair);
    }

    /* Sort and Cut to Size of 10*/
    std::sort(m_scores.begin(), m_scores.end(), std::greater<std::pair<int, std::string>>());
    return isHighScore;
}

/**********************************************************************************************************************
 * Description: Imports score data from the file at m_filePath
 *      Inputs: N/A
 *     Outputs: bool - If the importing was successful
 **********************************************************************************************************************/
bool Scoreboard::importFromFile() {
    bool good;
    std::string tmpInitials;
    int tmpScore;
    std::ifstream fin;
    fin.open(m_filePath);
    good = fin.good();
    while(not fin.eof()) {      //Read through file
        fin >> tmpScore;
        fin >> tmpInitials;
        addScore(tmpScore, tmpInitials);
    }
    fin.close();
    return good;
}

/**********************************************************************************************************************
 * Description: Exports score data to the file at m_filePath
 *      Inputs: N/A
 *     Outputs: bool - If the importing was successful
 **********************************************************************************************************************/
bool Scoreboard::exportToFile() {
    bool good;
    std::ofstream fout;
    fout.open(m_filePath, std::ofstream::trunc);
    good = fout.good();
    fout << toString(true);
    fout.close();
    return good;
}

/**********************************************************************************************************************
 * Description: Creates the string m_outputString to align with the Scorboard data and also returns this string.
 *      Inputs: bool isFullSize - Whether or not to get the full scores record or just 10
 *     Outputs: const std::string & - String of scoreboard data
 **********************************************************************************************************************/
const std::string & Scoreboard::toString(bool isFullSize) {
    m_outputString = "";
    if(isFullSize) {
        for(const auto &pair: m_scores) {
            m_outputString.append(std::to_string(pair.first));
            m_outputString.append(" ");
            m_outputString.append(pair.second);
            m_outputString.append("\n");
        }
    }
    else {
        int i = 0;
        for(const auto &pair: m_scores) {
            if(i < 10) {
                m_outputString.append(std::to_string(pair.first));
                m_outputString.append(" ");
                m_outputString.append(pair.second);
                m_outputString.append("\n");
                i++;
            }
        }
    }
    return m_outputString;
}

