#include <string>
#include<iostream>
using namespace std;//include class libraries

#ifndef PERSON_H
#define PERSON_H//include guards


class Person //class Person
{
 protected:
  long SSN;
  string firstName;
  string lastName;
  int age;
  char gender;//declare variables
 public:
  Person();//default constructor
  Person(long SSN, string firstName, string lastName);//second constructor, takes ssn, Fname, Lname
  long getSSN();//returns long SSN
  void setSSN(long SSN);//sets SSN to parameter
  string getFirstName();//gets firstName string
  void setFirstName(string firstName);//sets firstName to string parameter
  string getLastName();//gets lastName
  void setLastName(string lastName);//sets lastName to string parameter
  void print() const;//const print function
};
#endif

