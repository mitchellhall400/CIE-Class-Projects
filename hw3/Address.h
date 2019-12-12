/**********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 9/27/2019
 *    Project Name: hw3
 *     Description: The header file for the class Address which stores info for a physical address.
 **********************************************************************************************************************/

#ifndef HW3_ADDRESS_H
#define HW3_ADDRESS_H

#include <string>
#include <ostream>

class Address {
private:

    std::string m_city;
    std::string m_state;

public:

    explicit Address(const std::string& city = "", const std::string& state = "");

    void setCity(const std::string& city);
    void setState(const std::string& state);
    const std::string& getCity();
    const std::string& getState();

    friend std::ostream& operator << (std::ostream& out, const Address& address);
    friend bool operator == (const Address& address1, const Address& address2);

};

#endif //HW3_ADDRESS_H
