/**********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 9/27/2019
 *    Project Name: hw2
 *     Description: Homework for making an Address Book that contains Contacts with first name, last name, and address.
 *        Resource: https://stackoverflow.com/questions/875249/how-to-get-current-directory - Get working directory
 **********************************************************************************************************************/

#include <iostream>
#include <string>
#include <windows.h>
#include "AddressBook.h"

std::string ExePath();          //Function prototype

int main() {

    std::string tmpString;      //For testing getters
    Address tmpAddress;         //For testing getters

    /* Testing Constructors and Setters for Contact and Address */
    std::cout << "***Testing Constructors for Contact and Address***" << std::endl;
    std::cout << "Creating contact rick using contact setters and address constructor...";
    Contact rick;
    rick.setFirstName("Rick");
    rick.setLastName("Astley");
    Address newYork("New York", "NY");
    rick.setAddress(newYork);
    std::cout << "[DONE]" << std::endl;
    std::cout << "Expected:\nRick Astley\nNew York, NY"
                 "\nActually:\n" << rick << std::endl;
    std::cout << std::endl;

    std::cout << "Creating contact fresh using contact setters and address setters...";
    Contact fresh;
    fresh.setFirstName("Fresh");
    fresh.setLastName("Prince");
    Address belAir;
    belAir.setCity("Bel-Air");
    belAir.setState("CA");
    fresh.setAddress(belAir);
    std::cout << "[DONE]" << std::endl;
    std::cout << "Expected:\nFresh Prince\nBel-Air, CA"
                 "\nActually:\n" << fresh << std::endl;
    std::cout << std::endl;

    std::cout << "Creating contact will using contact constructor...";
    Contact will("Will","Smith","Philadelphia","PA");
    std::cout << "[DONE]" << std::endl;
    std::cout << "Expected:\nWill Smith\nPhiladelphia, PE"
                 "\nActually:\n" << will << std::endl;
    std::cout << std::endl;

    std::cout << "Creating contact bill using contact constructor...";
    Contact bill("Bill","Gates","Medina","WA");
    std::cout << "[DONE]" << std::endl;
    std::cout << "Expected:\nBill Gates\nMedina, WA"
                 "\nActually:\n" << bill << std::endl;
    std::cout << std::endl;

    std::cout << "Changing contact bill using contact setters and address constructor...";
    bill.setFirstName("Bill");
    bill.setLastName("Nye");
    Address seattle("Seattle", "WA");
    bill.setAddress(seattle);
    std::cout << "[DONE]" << std::endl;
    std::cout << "Expected:\nBill Nye\nSeattle, WA"
                 "\nActually:\n" << bill << std::endl;
    std::cout << std::endl;

    /* Testing Contact Getters */
    std::cout << "***Testing Contact Getters***" << std::endl;
    std::cout << "Getting first name of bill...";
    tmpString = bill.getFirstName();
    std::cout << "[DONE]" << std::endl;
    std::cout << "Expected:\nBill"
                 "\nActually:\n" << tmpString << std::endl;
    std::cout << std::endl;

    std::cout << "Getting last name of bill...";
    tmpString = bill.getLastName();
    std::cout << "[DONE]" << std::endl;
    std::cout << "Expected:\nNye"
                 "\nActually:\n" << tmpString << std::endl;
    std::cout << std::endl;

    std::cout << "Getting address of bill...";
    tmpAddress = bill.getAddress();
    std::cout << "[DONE]" << std::endl;
    std::cout << "Expected:\nSeattle, WA"
                 "\nActually:\n" << tmpAddress << std::endl;
    std::cout << std::endl;

    /* Testing Address Getters */
    std::cout << "***Testing Address Getters***" << std::endl;
    std::cout << "Getting city of bill's address...";
    tmpString = tmpAddress.getCity();
    std::cout << "[DONE]" << std::endl;
    std::cout << "Expected:\nBill"
                 "\nActually:\n" << tmpString << std::endl;
    std::cout << std::endl;

    std::cout << "Getting state of bill's address...";
    tmpString = tmpAddress.getState();
    std::cout << "[DONE]" << std::endl;
    std::cout << "Expected:\nWA"
                 "\nActually:\n" << tmpString << std::endl;
    std::cout << std::endl;

    /* Testing AddressBook.addContact() */
    std::cout << "***Testing AddressBook.addContact()***" << std::endl;
    AddressBook book;
    std::cout << "Adding contacts...";
    book.addContact(rick);
    book.addContact(fresh);
    book.addContact(will);
    book.addContact(bill);
    std::cout << "[DONE]" << std::endl;
    std::cout << "Expected:\n"
                 "Rick Astley\nNew York, NY\n\n"
                 "Fresh Prince\nBel-Air, CA\n\n"
                 "Will Smith\nPhiladelphia, PA\n\n"
                 "Bill Nye\nSeattle, WA\n\n"
                 "Actually:" << std::endl;
    book.printAllContacts();

    /* Testing AddressBook.searchByAddress() */
    std::cout << "***Testing AddressBook.searchByAddress()***" << std::endl;
    std::string city;
    std::string state;
    std::cout << "City: ";
    std::cin >> city;
    std::cout << "State: ";
    std::cin >> state;
    Address search(city,state);
    std::cout << "Displaying results for " << search << "..." << std::endl;
    book.searchByAddress(search);
    std::cout << "[DONE]\n" << std::endl;

    /* Testing AddressBook.deleteAllContacts() and AddressBook.size() */
    std::cout << "***Testing AddressBook.deleteAllContacts() and AddressBook.size()***" << std::endl;
    std::cout << "Deleting all contacts...";
    book.deleteAllContacts();
    std::cout << "[DONE]" << std::endl;
    std::cout << "Expected Number of Contacts: 0"
                 "\nActual Number of Contacts: " << book.size() << std::endl;
    std::cout << std::endl;

    /* Testing AddressBook.importFromFile() */
    std::cout << "***Testing AddressBook.importFromFile()***" << std::endl;
    std::string fileName;

    std::cout << "Please enter path to file containing contacts.\n"
                 "For reference, here is your working directory: " << ExePath() << std::endl;
    std::cin >> fileName;

    std::cout << "Importing \"" << fileName << "\"...";
    bool importSuccess = book.importFromFile(fileName);

    if(importSuccess) {         //Attempt importing custom inputted file.
        std::cout << "[DONE]" << std::endl;
        std::cout << "Imported " << book.size() << " contacts:" << std::endl;
        book.printAllContacts();
    }
    else {
        std::cout << "[FAIL]\nImporting default contacts...";

        importSuccess = book.importFromFile("../input.txt");          //Attempt importing default input file.
        if(importSuccess) {
            std::cout << "[DONE]" << std::endl;
            std::cout << "Expected Number of Contacts: 3"
                         "\nActual Number of Contacts: " << book.size() << std::endl;
            std::cout << "Expected:\n"
                         "Will Smith\nPhiladelphia, PA\n\n"
                         "Fresh Prince\nBel-Air, CA\n\n"
                         "Herky Hawkeye\nIowa_City, IA\n"
                         "\nActual: " << std::endl;
            book.printAllContacts();
        }
        else {
            std::cout << "[FAIL]" << std::endl;           //All have failed, files unreachable
        }
    }
}

/**********************************************************************************************************************
 * Description: Returns the current path to the executing program
 *      Inputs: None
 *     Outputs: string - The current path to the executing program
 *        Note: This function was taken from stack overflow and is just for ease of use. Homework is not dependent on
 *              this.
 **********************************************************************************************************************/
std::string ExePath() {
    char buffer[MAX_PATH];
    GetModuleFileName( nullptr, buffer, MAX_PATH );
    std::string::size_type pos = std::string( buffer ).find_last_of( "\\/" );
    return std::string( buffer ).substr( 0, pos);
}
