/***********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 11/27/2019
 *     Description: The cpp file to outline all methods for the class MyList which stores a pointer to a start node and
 *                  can manipulate and access all linked nodes.
 **********************************************************************************************************************/

#include "MyList.h"

/***********************************************************************************************************************
 * Description: MyList constructor
 *      Inputs: N/A
 *     Outputs: N/A
 **********************************************************************************************************************/
MyList::MyList() {
    m_startPtr = nullptr;
}

/***********************************************************************************************************************
 * Description: MyList deep copy constructor
 *      Inputs: const MyList &listToCopy - MyList class to copy
 *     Outputs: N/A
 **********************************************************************************************************************/
MyList::MyList(const MyList &listToCopy) {
    if(!listToCopy.empty()) {

        // Pointers to Nodes for iteration
        m_startPtr = new Node();
        Node *newNode = this->m_startPtr;
        Node *copyNode = listToCopy.m_startPtr;

        while(copyNode != nullptr) {        // Copy every node
            if(copyNode->getNextPtr() == nullptr){
                newNode->setNextPtr(nullptr);
            }
            else {
                newNode->setNextPtr(new Node());
            }
            newNode->setData(copyNode->getData());
            copyNode = copyNode->getNextPtr();
            newNode = newNode->getNextPtr();
        }

    }
    else {
        this->m_startPtr = nullptr;
    }
}

/***********************************************************************************************************************
 * Description: MyList destructor
 *      Inputs: N/A
 *     Outputs: N/A
 **********************************************************************************************************************/
MyList::~MyList() {
    if(not this->empty()) {
        Node *tmpNode = nullptr;
        Node *node = m_startPtr;
        while(node->getNextPtr() != nullptr) {
            tmpNode = node;
            node = node->getNextPtr();
            std::cout << tmpNode->getData() << " was deleted." << std::endl;
            delete tmpNode;
        }
        std::cout << node->getData() << " was deleted." << std::endl;
        delete node;
    }
}

/***********************************************************************************************************************
 * Description: Returns whether or not MyList is empty
 *      Inputs: N/A
 *     Outputs: bool
 **********************************************************************************************************************/
bool MyList::empty() const {
    return m_startPtr == nullptr;
}

/***********************************************************************************************************************
 * Description: Prints out MyList
 *      Inputs: N/A
 *     Outputs: void
 **********************************************************************************************************************/
void MyList::print() const {
    if(empty()) {
        std::cout << "List is empty." << std::endl;
    }
    else {
        Node *node = m_startPtr;
        while(node->getNextPtr() != nullptr) {
            std::cout << node->getData() << " ";
            node = node->getNextPtr();
        }
        std::cout << node->getData() << std::endl;
    }
}

/***********************************************************************************************************************
 * Description: Inserts a string into MyList sorted alphabetically
 *      Inputs: std::string str - string to be inserted
 *     Outputs: void
 **********************************************************************************************************************/
void MyList::insert(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);     // Convert to lowercase

    Node *prevNode = nullptr;
    Node *curNode = m_startPtr;

    while(curNode != nullptr && curNode->getData() < str) {     // Find where str belongs
        prevNode = curNode;
        curNode = curNode->getNextPtr();
    }

    if(prevNode == nullptr) {       // Node to be inserted at front
        m_startPtr = new Node(str, curNode);
    }
    else {      // Node to be inserted between prevNode and curNode
        prevNode->setNextPtr(new Node(str, curNode));
    }
}

/***********************************************************************************************************************
 * Description: Removes the first instance of str if it exists
 *      Inputs: std::string str - string to be found and removed
 *     Outputs: void
 **********************************************************************************************************************/
void MyList::remove(std::string str) {
    if(not empty()) {       // List is not empty
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);     // Convert to lowercase

        Node *prevNode = nullptr;
        Node *curNode = m_startPtr;

        while(curNode != nullptr && curNode->getData() != str) {
            prevNode = curNode;
            curNode = curNode->getNextPtr();
        }

        if(curNode == nullptr) {        // str not found
            std::cout << str << " was not found, nothing has been deleted." << std::endl;
        }
        else if(prevNode == nullptr) {      // First node to be deleted
            m_startPtr = curNode->getNextPtr();
            delete curNode;
            std::cout << str << " has been deleted." << std::endl;
        }
        else {      // Node to be deleted is in middle
            prevNode->setNextPtr(curNode->getNextPtr());
            delete curNode;
            std::cout << str << " has been deleted." << std::endl;
        }

    }
    else {      // List is empty
        std::cout << "List is empty, nothing has been deleted." << std::endl;
    }
}

/***********************************************************************************************************************
 * Description: Removes all nodes from list
 *      Inputs: N/A
 *     Outputs: void
 **********************************************************************************************************************/
void MyList::clear() {
    if(not this->empty()) {
        Node *tmpNode = nullptr;
        Node *node = m_startPtr;
        while(node->getNextPtr() != nullptr) {
            tmpNode = node;
            node = node->getNextPtr();
            std::cout << tmpNode->getData() << " was deleted." << std::endl;
            delete tmpNode;
        }
        std::cout << node->getData() << " was deleted." << std::endl;
        delete node;
    }
    m_startPtr = nullptr;
}
