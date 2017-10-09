#ifndef HUSBAND_H
#define HUSBAND_H//include guards

#include <string>
#include <iostream>
using namespace std;//include class libraries

#include "Person.h"
#include "Wife.h"
#include "Child.h"
#include "Family.h"//include class nodes

class Family;//forward class declaration

class Husband: public Person//inherits from class Person
{
  friend class Family;//fried classes with Family
 protected:
  Husband* nextFamily;//points to next Husband in list
  Wife* myWife;
 public:
  Husband();//default constructor
  Husband(long ssn, string Fname, string Lname);//second constructor, takes ssn, Fname, and Lname
  void print() const;//Husband's const print function, takes no parameters
};
#endif
