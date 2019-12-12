/**********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 9/27/2019
 *    Project Name: hw3
 *     Description: The header file for the class Contact which stores contact information.
 **********************************************************************************************************************/

#ifndef HW3_CONTACT_H
#define HW3_CONTACT_H

#include "Address.h"
#include <ostream>

class Contact {
private:

    std::string m_firstName;
    std::string m_lastName;
    Address m_address;

public:

    explicit Contact(const std::string& first = "", const std::string& last = "",
            const std::string& city = "", const std::string& state = "");

    const std::string& getFirstName();
    const std::string& getLastName();
    const Address& getAddress();
    void setFirstName(const std::string& first);
    void setLastName(const std::string& last);
    void setAddress(const Address& address);

    friend std::ostream& operator << (std::ostream& out, const Contact& contact);
    friend bool operator == (const Contact& contact1, const Contact& contact2);

};

#endif //HW3_CONTACT_H