/**********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 9/13/2019
 *    Project Name: hw2
 *     Description: The header file for the class Contact which stores contact information.
 **********************************************************************************************************************/

#include <string>

class Contact {
private:

    /* Private Member Variables */
    std::string m_firstName;
    std::string m_lastName;
    std::string m_emailAddress;

public:

    /* Constructors */
    Contact();
    Contact(std::string first, std::string last, std::string email);

    /* First Name */
    std::string getFirstName();
    void setFirstName(std::string first);

    /* Last Name */
    std::string getLastName();
    void setLastName(std::string last);

    /* Email Address */
    std::string getEmailAddress();
    void setEmailAddress(std::string email);

    /* Print */
    void printFirstLast();
    void printLastFirst();

};
