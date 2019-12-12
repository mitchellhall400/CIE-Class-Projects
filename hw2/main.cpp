/**********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 9/13/2019
 *    Project Name: hw2
 *     Description: Creating and testing of custom class for storing contact information.
 **********************************************************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include "Contact.h"

/* Main Function */
int main() {

    std::string search;
    bool found = false;

    /* First Contact - Setters */
    std::cout << "First Contact" << std::endl;
    Contact firstContact;

    std::cout << R"(Testing setFirstName("Barry"))" << std::endl;
    std::cout << "\tShould be: Barry  ()" << std::endl;
    firstContact.setFirstName("Barry");
    std::cout << "\t Actually: ";
    firstContact.printFirstLast();

    std::cout << R"(Testing setLastName("Benson"))" << std::endl;
    std::cout << "\tShould be: Barry Benson ()" << std::endl;
    firstContact.setLastName("Benson");
    std::cout << "\t Actually: ";
    firstContact.printFirstLast();

    std::cout << R"(Testing setEmailAddress("barry-b-benson@uiowa.edu"))" << std::endl;
    std::cout << "\tShould be: Barry Benson (barry-b-benson@uiowa.edu)" << std::endl;
    firstContact.setEmailAddress("barry-b-benson@uiowa.edu");
    std::cout << "\t Actually: ";
    firstContact.printFirstLast();

    std::cout << std::endl;


    /* Second Contact - Getters */
    std::cout << "Second Contact" << std::endl;

    std::cout << R"(Testing Contact("Jim","Lee","jim-lee@gmail.com"))" << std::endl;
    Contact secondContact("Jim", "Lee", "jim-lee@gmail.com");
    std::cout << "\tShould be: Jim Lee (jim-lee@gmail.com)" << std::endl;
    std::cout << "\t Actually: ";
    secondContact.printFirstLast();

    std::cout << R"(Testing getFirstName())" << std::endl;
    std::cout << "\tShould be: Jim" << std::endl;
    std::cout << "\t Actually: " << secondContact.getFirstName() << std::endl;

    std::cout << R"(Testing getLastName())" << std::endl;
    std::cout << "\tShould be: Lee" << std::endl;
    std::cout << "\t Actually: " << secondContact.getLastName() << std::endl;

    std::cout << R"(Testing getEmailAddress())" << std::endl;
    std::cout << "\tShould be: jim-lee@gmail.com" << std::endl;
    std::cout << "\t Actually: " << secondContact.getEmailAddress() << std::endl;

    std::cout << std::endl;


    /* Third Contact - Setters */
    std::cout << "Third Contact" << std::endl;
    Contact thirdContact;

    std::cout << R"(Testing setFirstName("Bob"))" << std::endl;
    std::cout << "\tShould be: Bob  ()" << std::endl;
    thirdContact.setFirstName("Bob");
    std::cout << "\t Actually: ";
    thirdContact.printFirstLast();

    std::cout << R"(Testing setLastName("Brown"))" << std::endl;
    std::cout << "\tShould be: Bob Brown ()" << std::endl;
    thirdContact.setLastName("Brown");
    std::cout << "\t Actually: ";
    thirdContact.printFirstLast();

    std::cout << R"(Testing setEmailAddress("bob.brown@hotmail.com"))" << std::endl;
    std::cout << "\tShould be: Bob Brown (bob.brown@hotmail.com)" << std::endl;
    thirdContact.setEmailAddress("bob.brown@hotmail.com");
    std::cout << "\t Actually: ";
    thirdContact.printFirstLast();

    std::cout << std::endl;


    /* Fourth Contact - Getters */
    std::cout << "Fourth Contact" << std::endl;

    std::cout << R"(Testing Contact("Terry","Brown","tbrown@yahoo.com"))" << std::endl;
    Contact fourthContact("Terry", "Brown", "tbrown@yahoo.com");
    std::cout << "\tShould be: Terry Brown (tbrown@yahoo.com)" << std::endl;
    std::cout << "\t Actually: ";
    fourthContact.printFirstLast();

    std::cout << R"(Testing getFirstName())" << std::endl;
    std::cout << "\tShould be: Terry" << std::endl;
    std::cout << "\t Actually: " << fourthContact.getFirstName() << std::endl;

    std::cout << R"(Testing getLastName())" << std::endl;
    std::cout << "\tShould be: Brown" << std::endl;
    std::cout << "\t Actually: " << fourthContact.getLastName() << std::endl;

    std::cout << R"(Testing getEmailAddress())" << std::endl;
    std::cout << "\tShould be: tbrown@yahoo.com" << std::endl;
    std::cout << "\t Actually: " << fourthContact.getEmailAddress() << std::endl;

    std::cout << std::endl;


    /* Fifth Contact - Setters */
    std::cout << "Fifth Contact" << std::endl;
    Contact fifthContact("Corey","Gray","c.gray@earthlink.net");

    std::cout << R"(Testing setFirstName("Tom"))" << std::endl;
    std::cout << "\tShould be: Tom Gray (c.gray@earthlink.net)" << std::endl;
    fifthContact.setFirstName("Tom");
    std::cout << "\t Actually: ";
    fifthContact.printFirstLast();

    std::cout << R"(Testing setLastName("Tompkins"))" << std::endl;
    std::cout << "\tShould be: Tom Tompkins (c.gray@earthlink.net)" << std::endl;
    fifthContact.setLastName("Tompkins");
    std::cout << "\t Actually: ";
    fifthContact.printFirstLast();

    std::cout << R"(Testing setEmailAddress("tommy.tomp@msn.com"))" << std::endl;
    std::cout << "\tShould be: Tom Tompkins (tommy.tomp@msn.com)" << std::endl;
    fifthContact.setEmailAddress("tommy.tomp@msn.com");
    std::cout << "\t Actually: ";
    fifthContact.printFirstLast();

    std::cout << std::endl;


    /* Sixth Contact - Getters*/
    std::cout << "Sixth Contact" << std::endl;

    std::cout << R"(Testing Contact("Randy","Bate","randy_b_200@aol.com"))" << std::endl;
    Contact sixthContact("Randy", "Bate", "randy_b_200@aol.com");
    std::cout << "\tShould be: Randy Bate (randy_b_200@aol.com)" << std::endl;
    std::cout << "\t Actually: ";
    sixthContact.printFirstLast();

    std::cout << R"(Testing getFirstName())" << std::endl;
    std::cout << "\tShould be: Randy" << std::endl;
    std::cout << "\t Actually: " << sixthContact.getFirstName() << std::endl;

    std::cout << R"(Testing getLastName())" << std::endl;
    std::cout << "\tShould be: Bate" << std::endl;
    std::cout << "\t Actually: " << sixthContact.getLastName() << std::endl;

    std::cout << R"(Testing getEmailAddress())" << std::endl;
    std::cout << "\tShould be: randy_b_200@aol.com" << std::endl;
    std::cout << "\t Actually: " << sixthContact.getEmailAddress() << std::endl;

    std::cout << std::endl;


    /* Seventh Contact - Setters */
    std::cout << "Seventh Contact" << std::endl;
    Contact seventhContact;

    std::cout << R"(Testing setFirstName("Megan"))" << std::endl;
    std::cout << "\tShould be: Megan  ()" << std::endl;
    seventhContact.setFirstName("Megan");
    std::cout << "\t Actually: ";
    seventhContact.printFirstLast();

    std::cout << R"(Testing setLastName("Brown"))" << std::endl;
    std::cout << "\tShould be: Megan Brown ()" << std::endl;
    seventhContact.setLastName("Brown");
    std::cout << "\t Actually: ";
    seventhContact.printFirstLast();

    std::cout << R"(Testing setEmailAddress("Megan.Brown@gmail.com"))" << std::endl;
    std::cout << "\tShould be: Megan Brown (Megan.Brown@gmail.com)" << std::endl;
    seventhContact.setEmailAddress("Megan.Brown@gmail.com");
    std::cout << "\t Actually: ";
    seventhContact.printFirstLast();

    std::cout << std::endl;


    /* Eighth Contact - Getters */
    std::cout << "Eighth Contact" << std::endl;

    std::cout << R"(Testing Contact("Jill","Tompkins","jill.tomp@msn.com"))" << std::endl;
    Contact eighthContact("Jill", "Tompkins", "jill.tomp@msn.com");
    std::cout << "\tShould be: Jill Tompkins (jill.tomp@msn.com)" << std::endl;
    std::cout << "\t Actually: ";
    eighthContact.printFirstLast();

    std::cout << R"(Testing getFirstName())" << std::endl;
    std::cout << "\tShould be: Jill" << std::endl;
    std::cout << "\t Actually: " << eighthContact.getFirstName() << std::endl;

    std::cout << R"(Testing getLastName())" << std::endl;
    std::cout << "\tShould be: Tompkins" << std::endl;
    std::cout << "\t Actually: " << eighthContact.getLastName() << std::endl;

    std::cout << R"(Testing getEmailAddress())" << std::endl;
    std::cout << "\tShould be: jill.tomp@msn.com" << std::endl;
    std::cout << "\t Actually: " << eighthContact.getEmailAddress() << std::endl;

    std::cout << R"(Testing printFirstLast())" << std::endl;
    eighthContact.printFirstLast();
    std::cout << R"(Testing printLastFirst())" << std::endl;
    eighthContact.printLastFirst();

    std::cout << std::endl;


    /* Append all to addressBook */
    std::vector<Contact> addressBook;
    addressBook.push_back(firstContact);
    addressBook.push_back(secondContact);
    addressBook.push_back(thirdContact);
    addressBook.push_back(fourthContact);
    addressBook.push_back(fifthContact);
    addressBook.push_back(sixthContact);
    addressBook.push_back(seventhContact);
    addressBook.push_back(eighthContact);


    /* Getting Search Term */
    std::cout << "Please enter a last name to search for in addressBook: ";
    std::cin >> search;

    for(Contact contact:addressBook) {
        if(contact.getLastName() == search) {
            contact.printLastFirst();
            found = true;
        }
    }
    if(!found) {
        std::cout << "No contacts where found." << std::endl;
    }
    return 0;
}
