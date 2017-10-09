#ifndef CHILD_C
#define CHILD_C//include guards

#include <string>
#include <iostream>
using namespace std;//include class libraries

#include "Child.h"//include class node

Child::Child()//default constructor
{
  setSSN(0);//sett SSN in Person class to 0
  setFirstName(" ");//set First Name in Person class to " "
  setLastName(" ");//set Last Name in Person class to " "
  fatherSSN=0;//sets fatherSSN to 0
}

Child::Child(long ssn, string Fname, string Lname,long fSSN)//second constructor, takes ssn, Fname, Lname, and fSSN
{
  setSSN(ssn);//sets SSN to ssn
  setFirstName(Fname);//sets firstName to Fname
  setLastName(Lname);//sets lastName to Lname
  fatherSSN=fSSN;//sets fatherSSN to fSSN
}

void Child::setFatherSSN(long id)//sets FatherSSN to id parameter
{
  fatherSSN=id;
}

void Child::print() const//Child's const print function
{
  cout<<"********Child*********"<<endl;
  Person::print();//calls print function inherited from Person class
  cout<<"*******End Child*******"<<endl;
  }
#endif
