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
//  FILE:        debug.h
//
//  DESCRIPTION:
//   This file contains the debugPrint template
//
//
****************************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <stdarg.h>
#include <iomanip>
#include "llist.h"
#include <cstdlib>


#ifndef _DEBUG
#define _DEBUG

using namespace std;

/****************************************************************************
//
//  template name: debugPrint 
//
//  DESCRIPTION:   This template takes in a generic type and prints
//                 out its name, value, and address of where
//                 it is stored in memory.
//
//  Parameters:    vars (T const & ) : Variable to be printed
//                 name (string)     : Name of variable being passed
//                 isParam (bool)    : Is the Variable being passed
//                                     a parameter or a varible declared
//                                     within function.
//
//  Return values: VOID  
//
******************************************************************************/

template <typename T>
void debugPrint (T const& vars, string name, bool isParam)
{
    if( isParam )
    {
        cout << "                                   The Parameter \"" << name << "\"";
        cout << "\n                                   stores the value:                     " << vars ;
        cout << "\n                                   in the address:                       " << &vars << "\n\n";
    }
    else
    {
        cout << "                                   The Variable \"" << name << "\"";
        cout << "\n                                   stores the value:                     " << vars ;
        cout << "\n                                   in the address:                       " << &vars << "\n\n";
    }
}

#endif 
