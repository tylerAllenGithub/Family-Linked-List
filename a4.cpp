#include <string>
#include <iostream>
using namespace std;//include libraries

#include "Family.h"//include class node

int main()
{
  Family USAFamilies;//create Family object
  USAFamilies.ReadTransactionFile( );//call ReadTransaction function

  return 0;
}
