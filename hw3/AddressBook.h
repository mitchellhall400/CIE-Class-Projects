/**********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 9/27/2019
 *    Project Name: hw3
 *     Description: The header file for the class AddressBook which stores multiple Contacts and their info.
 **********************************************************************************************************************/

#ifndef HW3_ADDRESSBOOK_H
#define HW3_ADDRESSBOOK_H

#include "Contact.h"
#include "Address.h"
#include <vector>
#include <string>

class AddressBook {
private:

    std::vector<Contact> m_contacts;

public:

    AddressBook() = default;;        //Empty default constructor
    void addContact(const Contact& contact);
    void deleteAllContacts();
    int size();
    void printAllContacts();
    void searchByAddress(const Address& address);
    bool importFromFile(const std::string& fileName);

};

#endif //HW3_ADDRESSBOOK_H
