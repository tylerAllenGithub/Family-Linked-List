#ifndef HUSBAND_C
#define HUSBAND_C//include guards

#include <string>
#include <iostream>
using namespace std;//include libraries

#include "Person.h"
#include "Husband.h"
#include "Wife.h"
#include "Child.h"
#include "Family.h"//include class Nodes

Husband::Husband()//default constructor
{
  setSSN(0);//sett SSN in Person class to 0
  setFirstName(" ");//set First Name in Person class to " "
  setLastName(" ");//set Last Name in Person class to " "
}
//second constructor, takes ssn, Fname, and Lname
Husband::Husband(long ssn, string Fname, string Lname)
{
  setSSN(ssn);//sets SSN to ssn
  setFirstName(Fname);//sets firstName to Fname
  setLastName(Lname);//sets lastName to Lname
}
//Husband's const print function, takes no parameters
void Husband::print() const
{
  cout<<"**********Husband**********"<<endl;
  Person::print();//calls print function inherited from Person class
  cout<<"********End husband**********"<<endl;
}
#endif
