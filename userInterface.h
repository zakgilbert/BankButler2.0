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
//  FILE:        userInterface.h
//
//  DESCRIPTION:
//   This file contains the userInterface class defintion.
//
//
****************************************************************/

#ifndef _USER_INTERFACE
#define _USER_INTERFACE

#include "llist.h"

using namespace std;

class userInterface
{
    private:
        void getAddress( char[], int );
        int getAccountNum( );
        void clearBuffer();
        void getUserInput( char[] );        
        void getAccount( llist *, char[], int, char[], int, int );
        void generateMenu( string[] );
        void getDelete( llist *, char [] );
        int getPrint( llist *, int);
        void addressFixer( char[] ); 
        void debugPrintName( string );

    public:
        void UI( llist *);
        userInterface();
        ~userInterface();
};

#endif

