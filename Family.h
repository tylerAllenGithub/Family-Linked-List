/*Family Header Class
Purpose: To create a linked list of linked lists.
 This class implements functions that manipulate the nodes of class Husband, wife, and child class.
This includes adding removing, searching etc.
Output: Should be able to take commands from input file and print them to screen. */

#ifndef FAMILY_H
#define FAMILY_H//include guards

#include <string>
#include <iostream>
using namespace std;//include libraries

#include "Husband.h"//include husband header file

class Husband;//forward class declaration

class Family
{
 protected:
  Husband* top;//top of each Family is Husband pointer node
 public:
  Family();//default constructor
  void AddHusband(long SSN, string Fname, string Lname);//Adds Husband to Family, takes SSN, first name and last name
  Husband* searchHus(long SSN);//makes searching much easier for husband, takes ssn
  void RemoveHusband(long SSN);//removes husband and other members, takes SSN
  void AddWife(long SSN, string Fname, string Lname, long husbandSSN);//Adds Wife to list, takes SSN, first name, last name, and husband SSN
  void RemoveWife(long husbandSSN);//Removes Wife, takes husband's SSN
  void AddAChild(long SSN, string Fname, string Lname, long fatherSSN);//adds child to list, takes SSN, Fname, Lname, fatherSSN
  void RemoveAChild(long FatherSSN, long childSSN);//Removes a child, takes FatherSSN and childSSN
  void PrintAFamily(long fatherSSN);//print a single family unit of husband, wife, and children, takes fatherSSN
  void PrintAllFamilies();//print all families, takes no parameters
  void ReadTransactionFile();//reads transaction file, takes no parameters
};
#endif
