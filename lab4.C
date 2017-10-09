/*Tyler Allen
Lab 3
*/
#include <iostream>
#include<fstream>
#include <string>
#include <vector>
#include <string>
using namespace std;
#include "Person.h"
#include "Course.h"
#include "Student.h"
#include "StudentProfile.h"

int main()
{
  Person PersonalInfo;
  string SSN;
  string firstName;
  string lastName;
  int age;
  char gender;

  Student StdInfo;
  long StNo;
  Course course1;
  int course1Num;
  string course1Name;
  Course course2;
  int course2Num;
  string course2Name;
  Course course3;
  int course3Num;
  string course3Name;

  vector<StudentProfile> StCollection;

  ifstream fin;
  fin.open("data2.txt");
  if(!fin)
    {
      cout<<"Cannot open file."<<endl;
    }
  else
    {
      int count=0;
      long SSN;
      string firstName;
      vector<StudentProfile> StCollection;
     fin>>SSN;
     PersonalInfo.setSSN(SSN);

     while(fin)
       {
	 fin>>firstName;
	 PersonalInfo.setFirstName(firstName);

	 fin>>lastName;
	 PersonalInfo.setLastName(lastName);

	 fin>>age;
	 PersonalInfo.setAge(age);

	 fin>>gender;
	 PersonalInfo.setGender(gender);

	 fin>>StNo;
	 StdInfo.setStNo(StNo);

	 fin>>course1Num;
	 fin>>course1Name;
	 StdInfo.setCourse1(course1Num, course1Name);

	 fin>>course2Num;
     fin>>course2Name;
	 StdInfo.setCourse2(course2Num, course2Name);

	 fin>>course3Num;
     fin>>course3Name;
	 StdInfo.setCourse3(course3Num, course3Name);

	 StudentProfile stuProf(PersonalInfo, StdInfo);
	 StCollection.push_back(stuProf);

	 count++;
	 fin>>SSN;
	 PersonalInfo.setSSN(SSN);
       }
     for(int i=0;i<StCollection.size();i++)
       {
	 StCollection[i].print();
       }
    }
  return 0;
    }
