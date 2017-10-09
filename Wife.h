#ifndef WIFE_H
#define WIFE_H//include guards

#include <string>
#include <iostream>
using namespace std;//include class libraries

#include "Person.h"//include class node

class Child;//forward class declaration


class Wife: public Person//inherits from class Person
{
  friend class Family;//fried classes with Family
 protected:
  Child* myChildren;//points to next children in list
 public:
  Wife();//default constructor
  Wife(long ssn, string Fname, string Lname);//second constructor, takes ssn, Fname, Lname
  void print() const;//Wife's const print function
};
#endif
