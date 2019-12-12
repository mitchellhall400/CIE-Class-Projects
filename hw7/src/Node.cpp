/***********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 11/27/2019
 *     Description: The cpp file to outline all methods for the class Node which stores data as a string and a reference
 *                  to the next node.
 **********************************************************************************************************************/

#include "Node.h"

// Getters and Setters
const std::string &Node::getData() const {
    return m_data;
}
void Node::setData(const std::string &data) {
    m_data = data;
}
Node *Node::getNextPtr() const {
    return m_nextPtr;
}
void Node::setNextPtr(Node *nextPtr) {
    m_nextPtr = nextPtr;
}
