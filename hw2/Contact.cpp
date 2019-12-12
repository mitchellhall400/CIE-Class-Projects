/**********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 9/13/2019
 *    Project Name: hw2
 *     Description: The  cpp file to outline all methods for the class Contact which stores contact information.
 **********************************************************************************************************************/

#include "Contact.h"
#include <iostream>

/**********************************************************************************************************************
 * Description: Constructor for the contact class.
 *      Inputs: None
 *     Outputs: N/A
 **********************************************************************************************************************/
Contact::Contact() {
    // Empty constructor which is overloaded with constructor talking in all parameters.
    // This is for now parameters given.
}

/**********************************************************************************************************************
 * Description: Constructor for the contact class. Takes in fist, last and email and sets them to the member variables.
 *      Inputs: string first - the firstName to set to contact
 *              string last - the lastName to set to contact
 *              string email - the emailAddress to set to contact
 *     Outputs: N/A
 **********************************************************************************************************************/
Contact::Contact(std::string first, std::string last, std::string email) {
    Contact::m_firstName = std::move(first);
    Contact::m_lastName = std::move(last);
    Contact::m_emailAddress = std::move(email);
}

/**********************************************************************************************************************
 * Description: Returns the firstName of the contact.
 *      Inputs: None
 *     Outputs: string - the current firstName stored in contact
 **********************************************************************************************************************/
std::string Contact::getFirstName() {
    return Contact::m_firstName;
}

/**********************************************************************************************************************
 * Description: Sets the firstName of the contact.
 *      Inputs: string first - the firstName to set to contact
 *     Outputs: void
 **********************************************************************************************************************/
void Contact::setFirstName(std::string first) {
    Contact::m_firstName = std::move(first);
}

/**********************************************************************************************************************
 * Description: Returns the lastName of the contact.
 *      Inputs: None
 *     Outputs: string - the current lastName stored in contact
 **********************************************************************************************************************/
std::string Contact::getLastName() {
    return Contact::m_lastName;
}

/**********************************************************************************************************************
 * Description: Sets the lastName of the contact.
 *      Inputs: string last - the lastName to set to contact
 *     Outputs: void
 **********************************************************************************************************************/
void Contact::setLastName(std::string last) {
    Contact::m_lastName = std::move(last);
}

/**********************************************************************************************************************
 * Description: Returns the emailAddress of the contact.
 *      Inputs: None
 *     Outputs: string - the current emailAddress stored in contact
 **********************************************************************************************************************/
std::string Contact::getEmailAddress(){
    return Contact::m_emailAddress;
}

/**********************************************************************************************************************
 * Description: Sets the emailAddress of the contact.
 *      Inputs: string email - the emailAddress to set to contact
 *     Outputs: void
 **********************************************************************************************************************/
void Contact::setEmailAddress(std::string email){
    Contact::m_emailAddress = std::move(email);
}

/**********************************************************************************************************************
 * Description: Prints out the contact info in the form firstName lastName (emailAddress)
 *      Inputs: None
 *     Outputs: void
 **********************************************************************************************************************/
void Contact::printFirstLast() {
    std::cout << Contact::m_firstName << " " << Contact::m_lastName
              << " (" << Contact::m_emailAddress << ")" << std::endl;
}

/**********************************************************************************************************************
 * Description: Prints out the contact info in the form lastName, firstName (emailAddress)
 *      Inputs: None
 *     Outputs: void
 **********************************************************************************************************************/
void Contact::printLastFirst() {
    std::cout << Contact::m_lastName << ", " << Contact::m_firstName
              << " (" << Contact::m_emailAddress << ")" << std::endl;

}
