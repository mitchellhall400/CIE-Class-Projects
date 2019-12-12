/**********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 9/27/2019
 *    Project Name: hw2
 *     Description: The cpp file to outline all methods for the class AddressBook which stores multiple Contacts and
 *                  their info.
 **********************************************************************************************************************/

#include "AddressBook.h"
#include <fstream>
#include <iostream>

/**********************************************************************************************************************
 * Description: Adds contact to the class's vector member contacts.
 *      Inputs: const Contact& contact - memory address to Contact object to add to contacts
 *     Outputs: void
 **********************************************************************************************************************/
void AddressBook::addContact(const Contact& contact) {
    m_contacts.push_back(contact);
}

/**********************************************************************************************************************
 * Description: Deletes/clears all contact objects in the class's vector member contacts.
 *      Inputs: None
 *     Outputs: void
 **********************************************************************************************************************/
void AddressBook::deleteAllContacts() {
    m_contacts.clear();
}

/**********************************************************************************************************************
 * Description: Returns the size or how many contact objects are in the class's vector member contacts.
 *      Inputs: None
 *     Outputs: int - size or number of contact objects
 **********************************************************************************************************************/
int AddressBook::size() {
    return m_contacts.size();
}

/**********************************************************************************************************************
 * Description: Prints all of the objects contact objects in the class's vector member contacts.
 *      Inputs: None
 *     Outputs: void
 **********************************************************************************************************************/
void AddressBook::printAllContacts() {
    for(Contact& contact:m_contacts) {
        std::cout << contact << std::endl << std::endl;
    }
}

/**********************************************************************************************************************
 * Description: Searches for the inputted address object in the class's vector member contacts.
 *      Inputs: const Address& address - memory address to the Address object to search for
 *     Outputs: void
 **********************************************************************************************************************/
void AddressBook::searchByAddress(const Address& address) {
    for(Contact& contact:m_contacts) {
        if(contact.getAddress() == address) {
            std::cout << contact << std::endl << std::endl;
        }
    }
}

/**********************************************************************************************************************
 * Description: Imports contacts from the inputted file path and adds them to the class's vector member contacts.
 *      Inputs:
 *     Outputs: bool - whether or not the importing was successful
 **********************************************************************************************************************/
bool AddressBook::importFromFile(const std::string& fileName) {

    std::ifstream fin(fileName);

    if(fin.is_open()) {

        std::string firstName;
        std::string lastName;
        std::string city;
        std::string state;

        while(!fin.eof()) {
            fin >> firstName;
            fin >> lastName;
            fin >> city;
            fin >> state;

            this->addContact(Contact());

            m_contacts.back().setFirstName(firstName);
            m_contacts.back().setLastName(lastName);
            m_contacts.back().setAddress(Address(city, state));
        }

        fin.close();
        return true;
    }

    fin.close();
    return false;
}