/*****************************************************************
//
//  NAME:        Zachary Gilbert
//
//  HOMEWORK:    Project 2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        April 27th, 2018
//
//  FILE:        main.cpp
//
//  DESCRIPTION:
//   This file contains the userInterface class functions.
//
//
****************************************************************/

#include <iostream>
#include <string>
#include <cstring>

#include "llist.h"
#include "userInterface.h"
#include "record.h"

using namespace std;

/*****************************************************************
//
//  Function name:   main
//
//  DESCRIPTION:     Main function creates llist and userInterface
//                   objects and class the UI method. See the 
//                   userInterface class to se IU implementation.
//
//  Parameters:      n/a      
//
//  Return values:   0
//
****************************************************************/

int main()
{
    llist * list;
    userInterface  menu;
    
    list = new llist();
    llist * list2 = list;

    menu.UI( list2 );
   
    delete list;
    
    return 0;
}
