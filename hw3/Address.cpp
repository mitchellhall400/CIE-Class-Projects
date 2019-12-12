/**********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 9/27/2019
 *    Project Name: hw2
 *     Description: The  cpp file to outline all methods for the class Address which stores info for a physical address.
 **********************************************************************************************************************/

#include "Address.h"

/**********************************************************************************************************************
 * Description: Constructor for Address that takes in and sets all parameters which default to "" if not given.
 *      Inputs: const std::string& city - city name of the address
 *              const std::string& state - state name of the address
 *     Outputs: None - constructor
 **********************************************************************************************************************/
Address::Address(const std::string& city, const std::string& state) {
    m_city = city;
    m_state = state;
}

//Set City
void Address::setCity(const std::string& city) {
    m_city = city;
}

//Set State
void Address::setState(const std::string& state) {
    m_state = state;
}

//Get City
const std::string& Address::getCity() {
    return m_city;
}

//Get State
const std::string& Address::getState(){
    return m_state;
}

/**********************************************************************************************************************
 * Description: Overloading of the ostream << operator to output it in the form CITY, STATE.
 *      Inputs: std::ostream& out - the output stream memory address
 *              const Address& address - memory address of an object of the Address class
 *     Outputs: std::ostream& - memory address of the output stream
 **********************************************************************************************************************/
std::ostream& operator << (std::ostream& out, const Address& address) {
    out << address.m_city << ", " << address.m_state;
    return out;
}

/**********************************************************************************************************************
 * Description: Overloading of the == operator to compare if two address's data members are each equal.
 *      Inputs: const Address& address1 - Memory address to first Address object to compare
 *              const Address& address2 - Memory address to first Address object to compare
 *     Outputs:
 **********************************************************************************************************************/
bool operator == (const Address& address1, const Address& address2) {
    if(address1.m_state == address2.m_state) {
        if(address1.m_city == address2.m_city) {
            return true;
        }
    }
    return false;
}
