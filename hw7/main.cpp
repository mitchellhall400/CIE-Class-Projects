/***********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 11/27/2019
 *    Project Name: hw7
 *     Description: Implementation of a singly linked list class to keep an alphabetically sorted list of strings.
 **********************************************************************************************************************/

#include <iostream>
#include "src/MyList.h"

int main() {

    // MyList() - default constructor
    std::cout << "*** Testing MyList() - default constructor ***" << std::endl;
    MyList list = MyList();
    std::cout << "Expected: List is empty." << std::endl;
    std::cout << "Actually: ";
    list.print();
    std::cout << std::endl;

    // insert() - first element
    std::cout << "*** Testing insert() - first element ***" << std::endl;
    list.insert("test");
    std::cout << "Expected: test" << std::endl;
    std::cout << "Actually: ";
    list.print();
    std::cout << std::endl;

    // insert() - element at front
    std::cout << "*** Testing insert() - element at front ***" << std::endl;
    list.insert("abc");
    std::cout << "Expected: abc test" << std::endl;
    std::cout << "Actually: ";
    list.print();
    std::cout << std::endl;

    // insert() - element as end
    std::cout << "*** Testing insert() - element at end ***" << std::endl;
    list.insert("xyz");
    std::cout << "Expected: abc test xyz" << std::endl;
    std::cout << "Actually: ";
    list.print();
    std::cout << std::endl;

    // insert() - element in middle
    std::cout << "*** Testing insert() - element in middle ***" << std::endl;
    list.insert("cie");
    std::cout << "Expected: abc cie test xyz" << std::endl;
    std::cout << "Actually: ";
    list.print();
    std::cout << std::endl;

    // insert() duplicate element
    std::cout << "*** Testing insert() - duplicate element ***" << std::endl;
    list.insert("test");
    std::cout << "Expected: abc cie test test xyz" << std::endl;
    std::cout << "Actually: ";
    list.print();
    std::cout << std::endl;

    //insert() - case insensitive
    std::cout << "*** Testing insert() - case insensitive ***" << std::endl;
    list.insert("CaPiTaLiZeD");
    std::cout << "Expected: abc capitalized cie test test xyz" << std::endl;
    std::cout << "Actually: ";
    list.print();
    std::cout << std::endl;

    //remove() - case insensitive
    std::cout << "*** Testing remove() - case insensitive ***" << std::endl;
    list.remove("CaPiTaLiZeD");
    std::cout << "Expected: abc cie test test xyz" << std::endl;
    std::cout << "Actually: ";
    list.print();
    std::cout << std::endl;

    //remove() - element not found
    std::cout << "*** Testing remove() - element not found ***" << std::endl;
    list.remove("anything");
    std::cout << "Expected: abc cie test test xyz" << std::endl;
    std::cout << "Actually: ";
    list.print();
    std::cout << std::endl;

    // remove() - duplicate element
    std::cout << "*** Testing remove() - duplicate element ***" << std::endl;
    list.remove("test");
    std::cout << "Expected: abc cie test xyz" << std::endl;
    std::cout << "Actually: ";
    list.print();
    std::cout << std::endl;

    // remove() - element at front
    std::cout << "*** Testing remove() - element at front ***" << std::endl;
    list.remove("abc");
    std::cout << "Expected: cie test xyz" << std::endl;
    std::cout << "Actually: ";
    list.print();
    std::cout << std::endl;

    // remove() - element in middle
    std::cout << "*** Testing remove() - element in middle ***" << std::endl;
    list.remove("test");
    std::cout << "Expected: cie xyz" << std::endl;
    std::cout << "Actually: ";
    list.print();
    std::cout << std::endl;

    // remove() - element at end
    std::cout << "*** Testing remove() - element at end ***" << std::endl;
    list.remove("xyz");
    std::cout << "Expected: cie" << std::endl;
    std::cout << "Actually: ";
    list.print();
    std::cout << std::endl;

    // remove() - final element
    std::cout << "*** Testing remove() - final element ***" << std::endl;
    list.remove("cie");
    std::cout << "Expected: List is empty." << std::endl;
    std::cout << "Actually: ";
    list.print();
    std::cout << std::endl;

    // remove() - empty list
    std::cout << "*** Testing remove() - empty list ***" << std::endl;
    list.remove("anything");
    std::cout << "Expected: List is empty." << std::endl;
    std::cout << "Actually: ";
    list.print();
    std::cout << std::endl;

    // clear()
    std::cout << "*** Testing clear() ***" << std::endl;
    list.insert("abc");
    list.insert("test");
    list.insert("cie");
    list.insert("xyz");
    std::cout << "Starting List: ";
    list.print();
    list.clear();
    std::cout << "Expected: List is empty." << std::endl;
    std::cout << "Actually: ";
    list.print();
    std::cout << std::endl;

    // empty() - empty list
    std::cout << "*** Testing empty() - empty list ***" << std::endl;
    std::cout << "Starting List: ";
    list.print();
    std::cout << "Expected: 1" << std::endl;
    std::cout << "Actually: " << list.empty() << std::endl;
    std::cout << std::endl;

    // empty() - non-empty list
    std::cout << "*** Testing empty() - non-empty list ***" << std::endl;
    list.insert("abc");
    list.insert("test");
    list.insert("cie");
    list.insert("xyz");
    std::cout << "Starting List: ";
    list.print();
    std::cout << "Expected: 0" << std::endl;
    std::cout << "Actually: " << list.empty() << std::endl;
    std::cout << std::endl;

    // MyList() - copy constructor with multiple nodes
    std::cout << "*** Testing MyList() - copy constructor with multiple nodes ***" << std::endl;
    MyList copyListOne = MyList(list);
    std::cout << "Expected: abc cie test xyz" << std::endl;
    std::cout << "Actually: ";
    copyListOne.print();
    std::cout << std::endl;

    // MyList() - copy constructor with one node
    std::cout << "*** Testing MyList() - copy constructor with one node ***" << std::endl;
    std::cout << "Setting up list for test" << std::endl;
    list.remove("cie");
    list.remove("test");
    list.remove("xyz");
    MyList copyListTwo = MyList(list);
    std::cout << "Expected: abc" << std::endl;
    std::cout << "Actually: ";
    copyListTwo.print();
    std::cout << std::endl;

    // MyList() - copy constructor with no nodes
    std::cout << "*** Testing MyList() - copy constructor with no nodes ***" << std::endl;
    std::cout << "Setting up list for test" << std::endl;
    list.remove("abc");
    MyList copyListThree = MyList(list);
    std::cout << "Expected: List is empty." << std::endl;
    std::cout << "Actually: ";
    copyListThree.print();
    std::cout << std::endl;

    // MyList() - copy constructor deep copy check
    std::cout << "*** Testing MyList() - copy constructor deep copy check ***" << std::endl;
    copyListOne.insert("testing");
    list.insert("abc");
    copyListOne.remove("abc");
    list.remove("testing");
    std::cout << "Copy Expected: cie test testing xyz" << std::endl;
    std::cout << "Copy Actually: ";
    copyListOne.print();
    std::cout << "Root Expected: abc" << std::endl;
    std::cout << "Root Actually: ";
    list.print();
    std::cout << std::endl;

    // ~MyList() - deconstruction on application end
    std::cout << "*** Testing ~MyList() - deconstruction on application end ***" << std::endl;
    std::cout << "Testing deletion of Nodes on application end. (Also checked with Valgrind Memcheck)" << std::endl;
    std::cout << "Expected print:" << std::endl;
    std::cout << "abc was deleted." << std::endl;
    std::cout << "cie was deleted." << std::endl;
    std::cout << "test was deleted." << std::endl;
    std::cout << "testing was deleted." << std::endl;
    std::cout << "xyz was deleted." << std::endl;
    std::cout << "abc was deleted." << std::endl << std::endl;
    std::cout << "Actually Prints:" << std::endl;

    return 0;
}