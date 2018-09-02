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
//  FILE:        llsit.h
//
//  DESCRIPTION:
//   This file contains the the llist class defintion.
//
//
****************************************************************/

#ifndef _LL_CLASS
#define _LL_CLASS

using namespace std;
struct record;

class llist
{
    private:
        record * start;
        char filename[ 16 ];
        int readfile();
        void writefile();
        record * reverse( record * );
        void cleanup();

    public:
        llist();
        llist( char[ ] );
        ~llist();
        int addRecord( int, char[ ], char[ ] );
        /*Overloaded Operator*/
        friend ostream & operator << ( ostream &, llist & );
        /*Copy Constructor*/
        llist ( const llist & );
        int printRecord( int );
        int deleteRecord( int );
        void reverse();
};

#endif






