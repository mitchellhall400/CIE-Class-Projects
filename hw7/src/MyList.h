/***********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 11/27/2019
 *     Description: The header file for the class MyList which stores a pointer to a start node and can manipulate and
 *                  access all linked nodes.
 **********************************************************************************************************************/

#ifndef HW7_MYLIST_H
#define HW7_MYLIST_H

#include "Node.h"
#include <iostream>
#include <algorithm>

class MyList {
private:
    Node *m_startPtr;

public:
    // Constructors and Destructors
    MyList();
    MyList(const MyList &listToCopy);
    ~MyList();

    // Accessor Methods
    bool empty() const;
    void print() const;

    // Mutator Methods
    void insert(std::string str);
    void remove(std::string str);
    void clear();
};

#endif // HW7_MYLIST_H
