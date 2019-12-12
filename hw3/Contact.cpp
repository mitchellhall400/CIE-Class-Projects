/**********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 9/27/2019
 *    Project Name: hw2
 *     Description: The  cpp file to outline all methods for the class Contact which stores contact information.
 **********************************************************************************************************************/

#include "Contact.h"

/**********************************************************************************************************************
 * Description: Constructor for Contact that takes in and sets all parameters which default to "" if not given.
 *      Inputs: const std::string& first - first name of the contact
 *              const std::string& last - last name of the contact
 *              const std::string& city - city name of contact's the address
 *              const std::string& state - state name of the contact's address
 *     Outputs: None - constructor
 **********************************************************************************************************************/
Contact::Contact(const std::string& first, const std::string& last, const std::string& city, const std::string& state) {
    m_firstName = first;
    m_lastName = last;
    m_address = Address(city,state);
}

//Get First Name
const std::string& Contact::getFirstName() {
    return m_firstName;
}

//Get Last Name
const std::string& Contact::getLastName() {
    return m_lastName;
}

//Get Address
const Address& Contact::getAddress() {
    return m_address;
}

//Set First Name
void Contact::setFirstName(const std::string& first) {
    m_firstName = first;
}

//Set Last Name
void Contact::setLastName(const std::string& last) {
    m_lastName = last;
}

//Set Address
void Contact::setAddress(const Address& address) {
    m_address = address;
}

/**********************************************************************************************************************
 * Description: Overloading of the ostream << operator to output it in the form FIRST LAST.
 *      Inputs: std::ostream& out - the output stream memory address
 *              const Contact& contact - memory address of an object of the Contact class
 *     Outputs: std::ostream& - memory address of the output stream
 **********************************************************************************************************************/
std::ostream& operator << (std::ostream& out, const Contact& contact) {
    out << contact.m_firstName << " " << contact.m_lastName << std::endl << contact.m_address;
    return out;
}

/**********************************************************************************************************************
 * Description: Overloading of the == operator to compare if two contact's data members are each equal.
 *      Inputs: const Contact& contact1 - Memory address to first Contact object to compare
 *              const Contact& contact2 - Memory address to second Contact object to compare
 *     Outputs: bool - Whether or not the the two contacts are equal
 **********************************************************************************************************************/
bool operator == (const Contact& contact1, const Contact& contact2) {
    if(contact1.m_firstName == contact2.m_firstName) {
        if(contact1.m_lastName == contact2.m_lastName) {
            if(contact1.m_address == contact2.m_address) {
                return true;
            }
        }
    }
    return false;
}
