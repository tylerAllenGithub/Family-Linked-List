#ifndef WIFE_C
#define WIFE_C//include guards

#include <string>
#include <iostream>
using namespace std;//include class libraries

#include "Wife.h"//include class node

Wife::Wife()//default constructor
{
  setSSN(0);//sett SSN in Person class to 0
  setFirstName(" ");//set First Name in Person class to " "
  setLastName(" ");//set Last Name in Person class to " "
}

Wife::Wife(long ssn, string Fname, string Lname)//second constructor, takes ssn, Fname, Lname
{
  setSSN(ssn);//sets SSN to ssn
  setFirstName(Fname);//sets firstName to Fname
  setLastName(Lname);//sets lastName to Lname
}
void Wife::print() const//Wife's const print function
{
  cout<<"**********Wife************"<<endl;
  Person::print();//calls print function inherited from Person class
  cout<<"********End Wife*******"<<endl;
}
#endif
