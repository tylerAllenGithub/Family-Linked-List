/*FAMILY CLASS
Purpose: To create a linked list of linked lists.
 This class implements functions that manipulate the nodes of class Husband, wife, and child class.
This includes adding removing, searching etc.
Output: Should be able to take commands from input file and print them to screen.*/


#ifndef FAMILY_C //include guards
#define FAMILY_C//include guards

#include <iostream>
using namespace std;
#include <string>
#include <fstream>//include libraries

#include "Person.h"
#include "Husband.h"
#include "Family.h"
#include "Child.h"
#include "Wife.h"//include class Nodes

class Husband;//forward class declaration

Family::Family()//default constructor
{
  top=NULL;//set top to null
}
//Adds Husband to Family, takes SSN, first name and last name
void Family::AddHusband(long SSN, string Fname, string Lname)//takes 1 long, 2 strings
{
  if(searchHus(SSN)!=NULL)//checks if Husband already exists
    {
      cout<<"Another husband with the same ID already exists."<<endl;//error message
      return;
    }
  //else
  Husband* p = new Husband(SSN, Fname, Lname);//create new Husband node
  p->nextFamily=top;//sets next Husband node to top
  top=p;//sets top equal to p
}
//makes searching much easier for husband, takes ssn
Husband* Family::searchHus(long ssn)//takes 1 long parameter
{
  Husband* p = top;//starts pointer at top
  while(p!=NULL)//continue until null
    {
      if(p->SSN==ssn)//if ssn's match
        return p;//return the corresponding husband
      p=p->nextFamily;//otherwise continue down the list
    }
  return NULL;//return null pointer if couldn't be found
}

//removes husband and other members, takes SSN
void Family::RemoveHusband(long SSN)//takes 1 long parameter
{
  Husband* p=searchHus(SSN);//set p to target Husband
  if(p==NULL)//if it isn't there
    {
      cout<<"Husband was not removed."<<endl;//error message
      return;//stop
    }
  Husband* q;//holding pointer

  RemoveWife(SSN);//if husband is being removed its list must be removed first
  //check to see if SSN isn't matched
  while(p->nextFamily->SSN!=SSN)//while it isn't
    {
      if(p->SSN==SSN)//if SSN's match
         {
           q=p;//set holder to "traveling" pointer
           p=p->nextFamily;//have p continue on
         }
       else
         p=p->nextFamily;//have p continue on
    }
  q=p->nextFamily;//set q equal to next Husband node
  p->nextFamily=q->nextFamily;//set next p node to next q node
  delete(q);//delete holder pointer
}
//Adds Wife to list, takes SSN, first name, last name, and husband SSN
void Family::AddWife(long SSN, string Fname, string Lname, long husbandSSN)//takes 2 long, 2 string
{
  Husband* p = searchHus(husbandSSN);//sets p to target Husband pointer
  if(p==NULL)//if pointer can't be found
    {
      cout<<"The husband with that SSN doesn't exist."<<endl;//error message
      return;//stop
    }
  if(p->myWife!=NULL)//if there is already wife
    {
      cout<<"This husband has another wife already."<<endl;//error message
      return;
    }
  Wife* wife = new Wife(SSN, Fname, Lname);//create new wife
  p->myWife=wife;//set Husband's myWife pointer to wife
  wife->myChildren=NULL;//set wife's children pointer to NULL
}
//Removes Wife, takes husband's SSN
void Family::RemoveWife(long husbandSSN)//takes 1 long
{
  Husband* p=searchHus(husbandSSN);//sets p to target Husband pointer
  if(p==NULL)//if pointer can't be found
    {
      cout<<"This husband does not exist."<<endl;//error message
      return;//stop
    }

  if(p->myWife==NULL)//if there is already wife
    {
      cout<<"This man is not bound by the chains of responsibility."<<endl;//error message
    }
  else
    {
      Wife* wife = p->myWife;//create wife pointer from p's myWife
      Child* child=wife->myChildren;//create child pointer from wife's myChildren
      Child* temp;//create holder variable

      if(child==NULL){}//if child doesn't exist do nothing
      else//otherwise
        {
          while(child!=NULL)//while it doesn't equal null
          {
            temp=child;//set holder to child
            child=child->mySibling;//child continues down list
            delete(temp);//deletes holder
          }
        }
      p->myWife=NULL;//sets p's myWife pointer to null
      delete(wife);//delete wife
      cout<<"Wife was deleted."<<endl;//confirmation message
    }

}
//adds child to list, takes SSN, Fname, Lname, fatherSSN
void Family::AddAChild(long SSN, string Fname, string Lname, long fatherSSN)//takes 2 long, 2 string
{
  Husband* p=searchHus(fatherSSN);//sets p to target Husband pointer
  if(p==NULL)//if it can't be found
    {
      cout<<"This child doesn't have a father."<<endl;//error message
      return;//stops
    }
  if(p->myWife==NULL)//if theres's no wife
    {
      cout<<"This child doesn't have a mother."<<endl;//error message
      return;//stop
    }//Child can't exist without parents

  Child* child=p->myWife->myChildren;//sets child to Husband's wife's pointer
  Child* c;//declare Child pointer
  if(child==NULL)//if there is no child
    {
      c = new Child(SSN, Fname, Lname, fatherSSN);//create new child
      p->myWife->myChildren=c;//point wife to c
      return;//stops
    }
  Child* temp;//holder pointer
  while(child!=NULL)//while child has no value
    {
      temp=child;//set temp to child
      child=child->mySibling;//child continues down the list
    }
  c = new Child(SSN, Fname, Lname, fatherSSN);//create new child
  temp->mySibling=c;//set temp's sibling to point to c
    }
//Removes a child, takes FatherSSN and childSSN
void Family::RemoveAChild(long FatherSSN, long childSSN)//takes 2 longs
{
  Husband* p=searchHus(FatherSSN);//sets p to target Husband pointer
  if(p==NULL)//if p is null
    {
      cout<<"The child does not exist."<<endl;//error message
      return;//stops
    }
  if(p->myWife==NULL)//if wife isn't there
    {
      cout<<"Child does not exist."<<endl;//error message
      return;//stops function
    }
  if(p->myWife->myChildren==NULL)//if child isnn't there
  {
    cout<<"Child does not exist."<<endl;//error message
    return;//stops function
  }

 Child* child= p->myWife->myChildren;//initialize child pointer to wife's myChildren
 Child* temp;//declare holder Child pointer
 if(child->SSN==childSSN)//if child's SSN matches with target SSN
   {
     temp=child;//set holder variable to child
     p->myWife->myChildren= child->mySibling;//child continues down list
     delete(temp);//delete holder
     return;//stops
   }
 else//otherwise
   {
     while(child!=NULL)//while child isn't null
       {
         if(child->SSN==childSSN)//if child's ssn matches with target ssn
           {
             temp=child;//set holder variable to child
             child=child->mySibling;//child continues down list
             delete(temp);//delete holder
             return;//stops
           }
         else
           child=child->mySibling;//child continues down list
       }
     if(child==NULL)//if child still isn't there
       cout<<"Child does not exist."<<endl;//error message
   }
}
//print a single family unit of husband, wife, and children, takes fatherSSN
void Family::PrintAFamily(long fatherSSN)//takes 1 long
{
  Husband* p = searchHus(fatherSSN);//sets p to target Husband pointer
  if(p==NULL)//if p is null
    {
      cout<<"Husband doesn't exist."<<endl;//error message
      return;//stops
    }
  else if(p!=NULL)//if p does exist
    {
      p->print();//call p's print function from husband class
      Wife* wife =p->myWife;//initialize wife pointer
      if(wife==NULL)//if wife has no value
        {
          cout<<"Wife doesn't exist."<<endl;//error message
        }
      else if(wife!=NULL)//if wife exists
        {
          wife->print();//call wife's print function
          if(wife->myChildren!=NULL)//if wife has children
            {
              Child* child = wife->myChildren;//initialize child pointer
              //precaution against segmentation fault
              if(child->mySibling==NULL)//if child's sibling doesn't exist
                {
                  child->print();//print current child
                  return;//stops
                }
              else if(child->mySibling!=NULL)//if child's sibling not equal to null
                {
                  while(child!=NULL)//if current child not qual to null
                   {
                     child->print();//print current child
                     child=child->mySibling;//child continues down list
                   }
                }
            }

        }
        }
}
//print all families, takes no parameters
void Family::PrintAllFamilies()
{
  Husband* p=top;//initialize husband pointer p to top
  if(p==NULL)//if there is no husband
    {
      cout<<"No Families."<<endl;//error message
      return;//stops
    }
  while(p!=NULL)//while p isn't null
    {
      PrintAFamily(p->SSN);//print a single family
      cout<<endl<<endl;//extra space for readability
      p=p->nextFamily;//p continues down the list
    }
}
//reads transaction file, takes no parameters
void Family::ReadTransactionFile()
{
  ifstream fin;//declare infile
  fin.open("transaction01.txt");//open file
  if(!fin)//if file could not be opened
    {
      cout<<"Could not open transaction file. (Hint:transaction01.txt)"<<endl;//error message
      return;//stops
    }
  string command;//for storing command string
  long id;//stores SSN from file
  string firstName;//stores firstName from file
  string lastName;//stores lastName from file
  long id2;//stores miscellaneous other long from file

  fin>>command;//read in first command

  while(fin)//while reading file
 {
   if(command=="AddHusband")//if command is AddHusband
    {
      fin>>id;//read in id
      fin>>firstName;//read in first name
      fin>>lastName;//read in last name
      AddHusband(id, firstName, lastName);//call AddHusband function with above arguments
    }
   else if(command=="PrintAllFamilies")//if command is PrintAllFamilies
    PrintAllFamilies();//call PrintAllFunctions
   else if(command=="AddWife")//if command is AddWife
    {
      fin>>id;//read in id
      fin>>firstName;//read in first name
      fin>>lastName;//read in last name
      fin>>id2;//read in id2
      AddWife(id, firstName, lastName, id2);//call AddWife function with above arguments
    }
   else if(command=="AddAchild")//if command is AddAchild
    {
      fin>>id;//read in id
      fin>>firstName;//read in first name
      fin>>lastName;//read in last name
      fin>>id2;//read in id2
      AddAChild(id, firstName, lastName, id2);//call AddChild function with above arguments
    }
   else if(command=="RemoveAchild")//if command is RemoveAchild
    {
      fin>>id;//read in id
      fin>>id2;//read in id2
      RemoveAChild(id, id2);//call RemoveAChild function with above arguments
    }
   else if(command=="PrintAFamily")//if command is PrintAFamily
    {
      fin>>id;//read in id
      PrintAFamily(id);//call PrintAFamily function with id argument
    }
   else if(command=="RemoveWife")//if command is RemoveWife
    {
      fin>>id;//read in id
      RemoveWife(id);//call RemoveWife function with id argument
    }
   else if(command=="RemoveHusband")//if command is RemoveHusband
    {
      fin>>id;//read in id
      RemoveHusband(id);//call RemoveHusband with id argument
    }
   fin>>command;//read in command for loop
 }
}
#endif
