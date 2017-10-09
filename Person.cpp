#ifndef PERSON_C
#define PERSON_C//include guards

#include <string>//include class libraries
#include "Person.h"

Person::Person()//default constructor
  {
    SSN=0;
    firstName=" ";
    lastName=" ";
    age=0;
    gender=' ';//initializes variables
  }
Person::Person(long SSN, string firstName, string lastName)//second constructor, takes ssn, Fname, Lname
  {
    this->SSN=SSN;
    this->firstName=firstName;
    this->lastName=lastName;//initializes variables to parameters respectively
  }
long Person::getSSN()//returns long SSN
  {
    return SSN;
  }
void Person::setSSN(long SSN)//sets SSN to parameter
  {
    this->SSN=SSN;
  }
string Person::getFirstName()//gets firstName string
  {
    return firstName;
  }
void Person::setFirstName(string firstName)//sets firstName to string parameter
  {
    this->firstName=firstName;
  }
string Person::getLastName()//gets lastName
  {
    return lastName;
  }
void Person::setLastName(string lastName)//sets lastName to string parameter
  {
    this->lastName=lastName;
  }
void Person::print() const//const print function
  {
    cout<<"SSN is: "<<SSN<<endl;
    cout<<"First Name is: "<<firstName<<endl;
    cout<<"Last Name is: "<<lastName<<endl;
    }
#endif
