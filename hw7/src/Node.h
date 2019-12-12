/***********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 11/27/2019
 *     Description: The header file for the class Node which stores data as a string and a reference to the next node.
 **********************************************************************************************************************/

#ifndef HW7_NODE_H
#define HW7_NODE_H

#include <string>
#include <utility>

class Node {
private:
    std::string m_data;
    Node *m_nextPtr;

public:
    // Constructor
    explicit Node(std::string data = "", Node *nextPtr = nullptr): m_data(std::move(data)), m_nextPtr(nextPtr) {}

    // Getters and Setters
    const std::string &getData() const;
    void setData(const std::string &data);
    Node *getNextPtr() const;
    void setNextPtr(Node *nextPtr);
};

#endif // HW7_NODE_H
