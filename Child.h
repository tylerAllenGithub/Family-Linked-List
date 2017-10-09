#ifndef CHILD_H
#define CHILD_H//include guards

#include <string>
#include <iostream>
using namespace std;//include class libraries

#include "Person.h"//include class node

class Child;//forward class declaration

class Child :public Person//inherits from class Person
{
  friend class Family;//friend classes with Family
 protected:
  long fatherSSN;//Father SSN of type long
  Child* mySibling;//points to next children in lis
 public:
  Child();//default constructor
  Child(long ssn, string Fname, string Lname, long fSSN);//second constructor, takes ssn, Fname, Lname, and fSSN
  void setFatherSSN(long id);//sets FatherSSN takes id as parameter
  void print() const;//Child's const print function
};
#endif
