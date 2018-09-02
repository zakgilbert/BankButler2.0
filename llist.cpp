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
//  FILE:        llist.cpp
//
//  DESCRIPTION:
//   This file contains the llist.cpp class functions, which 
//   implements a Linked List of bank records. The linked list
//   lets one add, delete, print, or reverse the order of the
//   data held in the records.
//
//
****************************************************************/

#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>

#include "llist.h"
#include "record.h"
#include "debug.h"


using namespace std;

/*****************************************************************
//
//  Function name:   llist
//
//  DESCRIPTION:     llist class constructor creates a generic 
//                   file name, points the head of the list to
//                   null, then calls the read file method.
//
//  Parameters:      n/a
//
//  Return values:   n/a
//
****************************************************************/

llist:: llist()
{
    #ifdef DEBUG_MODE
        cout << "\nDEBUG_MODE: llist:: list(); constructor called.\n";
        debugPrint( start, "start (record *)", false );
        debugPrint( filename, "filename (char[])", false );
    #endif
    strcpy( this -> filename, "text.txt" );
    this -> start = NULL;
    this -> readfile();
}

/*****************************************************************
//
//  Function name:   llist
//
//  DESCRIPTION:     llist class constructor takes in a filename 
//                   as a parameter, points the head of the list to
//                   null, then calls the read file method.
//
//  Parameters:      filename (char[]) : filename to read and
//                                       write to.
//
//  Return values:   n/a
//
****************************************************************/

llist:: llist( char filename[] )
{
    #ifdef DEBUG_MODE
        cout << "\nDEBUG_MODE: llist:: list(); constructor called.\n";
        debugPrint( filename, "filename (char[])", true );
        debugPrint( start, "start (record *)", false );
    #endif

    strcpy( this -> filename, filename );
    this -> start = NULL;
    this -> readfile();
}

/*****************************************************************
//
//  Function name:   llist
//
//  DESCRIPTION:     llist destructor call the cleanup Method.
//
//  Parameters:      n/a
//
//  Return values:   n/a
//
****************************************************************/

llist:: ~llist()
{
    #ifdef DEBUG_MODE
        cout << "\nDEBUG_MODE: llist:: list(); destructor called.\n";
    #endif

    this -> cleanup();

}

/*****************************************************************
//
//  Function name:   llist
//
//  DESCRIPTION:     llist copy constructor
//
//  Parameters:      list (llist & ) : llsit obj being copied
//
//  Return values:   n/a
//
****************************************************************/

llist:: llist( const llist & list )
{
    
    #ifdef DEBUG_MODE
        cout << "\nDEBUG_MODE: llist:: list(); copy constructor called.\n";
    #endif
    
    this -> start = list.start;
    strcpy( this -> filename, list.filename );

}
/*****************************************************************************
//
//  Function name:   addRecord
//
//  DESCRIPTION:     Adds a bank account record to Linked List.
//
//  Parameters:      accountNumber (int) : Account Number to be added
//                   uname      (char[]) : Customer name to be added
//                   uaddress   (char[]) : Address to be added
//
//  Return values:   accountNumber 
//                            
//
*****************************************************************************/

                           /* - PUBLIC - */ 

int llist:: addRecord( int accountNumber, char uname[ ], char uaddress[ ] )
{    
    struct record * current;
    struct record * previous;
    struct record * marker;
    struct record * newAccount;

    newAccount = new record();
    current = this -> start;
    previous = NULL;
    marker = NULL;

    #ifdef DEBUG_MODE
        cout << "\nDEBUG_MODE: llist:: addRecord();  method called.\n";
        debugPrint( accountNumber, "accountNumber (int)", true );
        debugPrint( uname, "uname (char[])", true );
        debugPrint( uaddress, "uname (char[])", true );
        debugPrint( current, "current (record *)", false );
        debugPrint( previous, "previous (record *)", false );
        debugPrint( marker, "marker (record *)", false );
        debugPrint( newAccount, "newAccount (record *)", false );
    #endif

    strcpy( newAccount -> name, uname );
    strcpy( newAccount -> address, uaddress );

    if( accountNumber < 1 )
    {
        accountNumber = 1;
    }
    
    if( this -> start == NULL || accountNumber < this -> start->accountno )
    {
        newAccount -> next = this -> start;
        this -> start = newAccount;
    } 
    else
    {
        while( current != NULL )
        {
            if( current -> accountno == accountNumber )
            {
                accountNumber++;
            }
            if( accountNumber < current -> accountno )
            {
                marker = previous;
            }
            previous = current;
            current = current -> next; 
        }
        if( marker != NULL )
        {
            previous = marker;
        }
        newAccount -> next = previous -> next;
        previous -> next = newAccount;
    }  
    newAccount -> accountno = accountNumber;

    return accountNumber;   
}

/*****************************************************************
//
//  Function name:   operator <<
//
//  DESCRIPTION:     Overloading of << operator. If << is called 
//                   all records in Linked List are printed.
//
//  Parameters:      out (ostream &) :   cout.
//                   list (llist & ) :   Reference to llist class
//
//  Return values:   VOID
//
****************************************************************/

ostream & operator << ( ostream & out, llist & list)
{ 
    struct record * current;
    int strLen;
    string border("-");

    #ifdef DEBUG_MODE
        out << "\nDEBUG_MODE: llist:: operator <<;  method called.\n";
        debugPrint( current, "current (record *)", false );
        debugPrint( strLen, "strLen (int)", false );
        debugPrint( border, "border (string)", false );
    #endif
    current = list.start;
   
    if( current == NULL )
    {
        out << "\nThere are no accounts in the data base\n";
    } 
    while( current != NULL )
    {
        strLen = strlen( current -> name );
        out << "\nAccount # " << current -> accountno << '\n';
        
        for( int k = 0; k < strLen; k++)
        {
            out <<  border;
        }
        out << "\n"  << current -> name;
        out << "\n" << current -> address << "\n\n";
            
        current = current -> next;
    }
    return out;
}

/*****************************************************************
//
//  Function name:    printRecord
//
//  DESCRIPTION:      Prints a bank record from the Linked List
//                    specified by the user.
//
//  Parameters:       accountNumber (int): accountNumber to be 
//                                         printed.
//
//  Return values:  -1 : Account does not exist
//                   0 : Success!!
//
****************************************************************/

int llist:: printRecord( int accountNumber )
{
    struct record * current, * temp;
    
    string border("-");
    int result, strLen;

    #ifdef DEBUG_MODE
        cout << "\nDEBUG_MODE: llist:: printRecord();  method called.\n";
        debugPrint( accountNumber, "accountNumber (int)", true );
        debugPrint( current, "current (record *)", false );
        debugPrint( temp, "temp (record *)", false );
        debugPrint( border, "border (string)", false );
        debugPrint( result, "result (int)", false );
        debugPrint( strLen, "strLen (int)", false );
    #endif
    
    current = this -> start;
    temp = NULL;
    result = 0;
    strLen = 0;

    if( current == NULL )
    {
        cout << "\nThere are no accounts in the data base\n";
    } 
    
    while( current != NULL )
    {
        if( current -> accountno == accountNumber )
        {
            temp = current;
        } 

        current = current -> next;
    }
    
    if( temp != NULL )
    {
        strLen = strlen( temp -> name );

        cout << "\nAccount # " << temp -> accountno << '\n';
        
        for( int k = 0; k < strLen; k++)
        {
            cout <<  border;
        }
        
        cout << "\n"  << temp -> name;
        cout << "\n" << temp -> address << "\n\n";
        
        result = 0;
    }
    else
    {
        result = -1;
    }
    return result;
}

/*****************************************************************
//
//  Function name:   deleteRecord
//
//  DESCRIPTION:     Deletes a record from the Linked List
//
//  Parameters:      accountNumber (int) : Account Number to be
//                                         deleted.
//
//  Return values:   -1            : If account does not exist.
//                   accountNumber : If account was deleted.
//
****************************************************************/

int llist:: deleteRecord( int accountNumber )
{
    struct record * recordToDelete;
    struct record * current;
    struct record * previous;
    struct record * marker;
    
    marker = NULL;
    recordToDelete = NULL;
    previous = NULL;
    current = this -> start;

    #ifdef DEBUG_MODE
        cout << "\nDEBUG_MODE: llist:: deleteRecord();  method called.\n";
        debugPrint( accountNumber, "accountNumber (int)", true );
        debugPrint( recordToDelete, "recordToDelete (record *)", false );
        debugPrint( current, "current (record *)", false );
        debugPrint( previous, "previous (record *)", false );
        debugPrint( marker, "marker (record *)", false );
    #endif


    if( current == NULL )
    {
        accountNumber = -1;
    }
    else if( current -> accountno == accountNumber )
    {
        recordToDelete = current;
        this -> start = current -> next;
        delete recordToDelete;
        accountNumber = 0;
    }
    else
    {
        while( current != NULL )
        {
            if(current -> accountno == accountNumber )
            {
                marker = previous;
                recordToDelete = current;
            }
            previous = current;
            current = current -> next;
        }
        if( marker == NULL )
        {
            accountNumber = -1;
        }
        else
        {
            marker -> next = recordToDelete -> next;
            delete recordToDelete;
            accountNumber = 0;    
        }
    } 

    return accountNumber;
}

/*****************************************************************
//
//  Function name:   reverse
//
//  DESCRIPTION:     Helper method for "record * reverse( record * );"
//
//  Parameters:      n/a
//
//  Return values:   VOID
//
****************************************************************/

void llist:: reverse()
{
    struct record * newStart;

    newStart = NULL;
    
    #ifdef DEBUG_MODE
        cout << "\nDEBUG_MODE: llist:: reverse();  method called.\n";
        debugPrint( newStart, "newStart (record *)", false );
    #endif
    
    if( this -> start != NULL )
    {
        newStart = this -> start;

        while( newStart -> next != NULL )
        {
            newStart = newStart -> next;
        }
        this -> start = this -> reverse( newStart );
    }
}

/*****************************************************************
//
//  Function name:    reverse
//
//  DESCRIPTION:      Recursivly reverses the list.
//
//  Parameters:       n/a
//
//  Return values:    VOID
//
****************************************************************/

                           /* - PRIVATE - */

record * llist::  reverse( record * newStart )
{
    struct record * current, * previous;

    current = this -> start;
    previous = NULL;

    #ifdef DEBUG_MODE
        cout << "\nDEBUG_MODE: llist:: reverse();  method called.\n";
        debugPrint( newStart, "newStart (record *)", true );
        debugPrint( current, "current (record *)", false );
        debugPrint( previous, "previous (record *)", false );
    #endif

    if( current -> next != NULL )
    {
        while( current -> next != NULL )
        {
            previous = current;
            current = current -> next;
        }
        previous -> next = current -> next;
        current -> next = previous;
        this -> reverse( newStart );
    }
    return newStart;
}

/*****************************************************************
//
//  Function name:    readfile
//
//  DESCRIPTION:      Reads text file and stores data in 
//                    Linked List.
//
//  Parameters:       n/a
//
//  Return values:    -1: if no accounts were read
//                     0: Success!!   
//
****************************************************************/

int llist:: readfile()
{
    ifstream file;
    int num, i, accountLength, result;
    char name[ 25 ], address[ 80 ];
    string account;
    int strCord[ 3 ]; 

    #ifdef DEBUG_MODE
        cout << "\nDEBUG_MODE: llist:: readfile();  method called.\n";
        debugPrint( file, "file (ifstream)", false );
        debugPrint( num, "num (int)", false );
        debugPrint( i, "i (int)", false );
        debugPrint( accountLength, "accountLength (int)", false );
        debugPrint( result, "result (int)", false );
        debugPrint( name, "name (char[])", false );
        debugPrint( address, "address (char[])", false );
        debugPrint( account, "account (string)", false );
        debugPrint( strCord, "strCord (int[])", false );
    #endif
 
    file.open ( this -> filename );

    num = 0;
    result = -1;
    accountLength = 0;   
 
    while( getline( file, account ))
    {
        i = 0;
        accountLength = account.length();
       
        for(int k = 0; k < accountLength; k++ )
        {
            if( account.at( k ) == '$' )
            {
                if( i < 2 )
                {
                    strCord[ i ] = k;
                    i++;
                }
                if( i == 2) 
                {
                    account.at( k ) = '\n';
                }
            }
        }
        num = atoi( account.substr( 0, strCord[0] - 0).c_str());
        strcpy( name, account.substr( strCord[0] + 1, strCord[1] - (strCord[0] + 1) ).c_str());
        strcpy( address, account.substr( strCord[1] + 1, account.length() - (strCord[1] + 1) ).c_str());
        addRecord( num, name, address );
      
    }
    file.close();
    
    if( accountLength > 0 )
    {
        result = 0;  
    }
    return result;
}

/*****************************************************************
//
//  Function name:  writefile
//
//  DESCRIPTION:    Writes the Linked List data to a text file.
//
//  Parameters:     n/a
//
//  Return values:  VOID
//
****************************************************************/

void llist:: writefile()
{
    struct record * current; 
    string buffer, number;   
    ostringstream stream;
    int bufferLength, account_NameLen;

    #ifdef DEBUG_MODE
        cout << "\nDEBUG_MODE: llist:: writefile();  method called.\n";
        debugPrint( current, "current (record *)", false );
        debugPrint( buffer, "buffer (string)", false );
        debugPrint( number, "number (string)", false );
        debugPrint( stream , "stream (ostringstream)", false );
        debugPrint( bufferLength, "bufferLength (int)", false );
        debugPrint( account_NameLen, "account_NameLen (int)", false );
    #endif
    
    ofstream file( this -> filename );
    current = this -> start;
    bufferLength = 0;
    account_NameLen = 0;

    while( current != NULL )
    {
        stream << current -> accountno;
        buffer += stream.str();
        stream.str("");
        buffer += '$';
 
        stream << current -> name;
        buffer += stream.str();
        stream.str("");
        buffer += '$';

        account_NameLen = buffer.length();
        
        stream << current -> address;
        buffer += stream.str();
        stream.str("");
        buffer += '\n';       
        
        bufferLength = buffer.length();

        for( int k = account_NameLen; k < bufferLength - 2 ; k++ )
        {
            if( buffer.at(k) == '\n' )
            {
                buffer[k] = '$';    
            }
        }
        
        current = current -> next;
    }
        
    buffer[bufferLength - 1] = '\0';
    file << buffer;
     
}

/*****************************************************************
//
//  Function name:   cleanup
//
//  DESCRIPTION:     Deallocates the Records stored on the heap
//
//  Parameters:      n/a
//
//  Return values:   VOID
//
****************************************************************/

void llist:: cleanup()
{
    struct record * temp;
    struct record * current;

    #ifdef DEBUG_MODE
        cout << "\nDEBUG_MODE: llist:: cleanup();  method called.\n";
        debugPrint( temp, "temp (record *)", false );
        debugPrint( current, "current (record *)", false );
    #endif

    this -> writefile();

    current = this -> start;

    while( current != NULL )
    {
        temp = current;
        current = current -> next;
        delete temp;
    }
    temp = NULL;
}














