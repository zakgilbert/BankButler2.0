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
//  FILE:        userInterface.cpp
//
//  DESCRIPTION:
//   This file contains the userInterface class functions.
//
//
****************************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <stdarg.h>
#include <iomanip>
#include <cstdlib>
#include "userInterface.h"
#include "llist.h"
#include "debug.h"

using namespace std;


/*****************************************************************
//
//  Function name:   userInterface constructor 
//
//  DESCRIPTION:     Constructer for the userInterface class.
//
//  Parameters:      n/a
//
//  Return values:   
//                 
****************************************************************/

userInterface:: userInterface()
{

}

/*****************************************************************
//
//  Function name:   userInterface destructor 
//
//  DESCRIPTION:     Destructor for the userInterface class.
//
//  Parameters:      n/a
//
//  Return values:   
//                 
****************************************************************/

userInterface:: ~userInterface()
{

}

/*****************************************************************
//
//  Function name:  debugPrintName
//
//  DESCRIPTION:    Prints the method name of the function being
//                  printed in debug mode.
//
//  Parameters:     name (string) : name of method.
//
//  Return values:  VOID
//
****************************************************************/

void userInterface:: debugPrintName(string name )
{
    cout << "\nDEBUG_MODE: userInterface.cpp " << name << " method called.\n";
}

/*****************************************************************
//
//  Function name:   getAddress
//
//  DESCRIPTION:     Gets multiple line address from user.
//
//  Parameters:      address (char[]) : Array to contain address.
//                   maxLength  (int) : Max length of address.
//
//  Return values:   VOID
//
****************************************************************/


void userInterface:: getAddress( char address[], int maxLength )
{

    #ifdef DEBUG_MODE
        debugPrintName( "getAddress();" );
        debugPrint( address, "address (char[])", true );    
        debugPrint( maxLength, "MaxLength (int)", true );    
    #endif

   /* char temp[180] = {""};
    int len = strlen( address );

    maxLength = 80 - (len - 2);

    if( maxLength < 2 || address[ len - 2 ] == '\n' )
    {
        address[len - 2] = '\0';
    }
    else
    {    
        cin.get(temp,maxLength);
        cin.clear();
        cin.ignore( 10000, '\n' );
        strcat(address, temp);
        getAddress( strcat( address, "\n"), maxLength);
    }*/

    cin.getline(address, maxLength, '$');
}

/*****************************************************************
//
//  Function name:  getAccountNum
//
//  DESCRIPTION:    Gets and integer input from user.
//
//  Parameters:     n/a
//
//  Return values:  integer that was taken from user.
//
****************************************************************/

int userInterface:: getAccountNum( )
{
    int input;
    
    #ifdef DEBUG_MODE
        debugPrintName( "getAccountNum();" );
        debugPrint( input, "input (int)", false );    
    #endif
    
    cin >> input;

    if( cin.fail() )
    {
        this -> clearBuffer();
        cout << '\n' << "Account number needs to be a number" ;
        getAccountNum();
    }
    
    return input;
}


/*****************************************************************
//
//  Function name:  getUserInput
//
//  DESCRIPTION:    Gets a user input and stores it in a
//                  character array.
//
//  Parameters:     userInput (char[]) : UserInput.
//
//  Return values:  VOID
//
****************************************************************/

void userInterface:: getUserInput(char  userInput[])
{
    #ifdef DEBUG_MODE
        debugPrintName( "getUserInput();" );
        debugPrint( userInput, "userInput(char[])", true );    
    #endif
    
    cin.get(userInput, 10);
}


/*****************************************************************
//
//  Function name:  addressFixer
//
//  DESCRIPTION:    Removes extra newline characters that 
//                  the user may enter on accident.
//
//  Parameters:     address (char[]) : Address to be fixed.
//
//  Return values:  VOID
//
****************************************************************/

void userInterface:: addressFixer( char address[] )
{
    int addressLen = strlen( address);
    int k = addressLen;

    #ifdef DEBUG_MODE
        debugPrintName( "addressFixer();" );
        debugPrint( address, "address (char[])", true );    
        debugPrint( addressLen, "addressLen (int)", false );    
        debugPrint( k, "k (int)", false );    
    #endif
    
    while( k >= 0 && address[k - 1] == '\n' )
    {
        address[k - 1] = '\0';
        k--;
    } 
}

/*****************************************************************
//
//  Function name:   clearBuffer
//
//  DESCRIPTION:     Clears the buffer.
//
//  Parameters:      n/a
//
//  Return values:   VOID
//
****************************************************************/

void userInterface:: clearBuffer()
{
    cin.clear();
    cin.ignore( 10000, '\n' ); 
}

/******************************************************************************************
//
//  Function name:   getAccount
//
//  DESCRIPTION:     Get account information from user then 
//                   calls llist::addAccount();
//
//  Parameters:      list       (llist*) : Linked List class obj.
//                   address    (char[]) : Array holding users address.
//                   addressLength (int) : Address max length.
//                   name       (char[]) : Array holding user name.
//                   nameLength    (int) : Name max length.
//                   input         (int) : User input.
//
//  Return values:   VOID
//
*****************************************************************************************/

void userInterface:: getAccount(llist * list, char address[], int addressLength, char name[], int nameLength, int input )
{

    #ifdef DEBUG_MODE
        debugPrintName( "getAccount();" );
        debugPrint( list, "list (llist class obj *)t", true );    
        debugPrint( address, "address (char[])", true );    
        debugPrint( addressLength, "addressLength (int)", true );    
        debugPrint( name, "name (char[])", true );    
        debugPrint( nameLength, "nameLength (int)", true );    
        debugPrint( input, "input (int)", true );    
    #endif
    
    cout << '\n' << '\n' << "You have invoked the add account function,";
    cout << '\n' << "please enter an account number to add: ";
    input = this -> getAccountNum();
    cout << '\n' << "You have entered: " << input;
    
    this -> clearBuffer();

    cout << '\n' << '\n' << "Please enter the customers name: ";
    cin.getline( name, nameLength );
    cout << '\n' << "You have entered: " << name;
    
    cout << '\n' << '\n' << "Please enter the customers address,";    
    cout << '\n' << "When you are done type \"$\" then hi enter." << '\n' ;

    this -> getAddress( address, addressLength );
    this -> addressFixer( address ); 
    
    input = list -> addRecord( input, name, address );
    
    cout << "\nThe account:\n";
    list -> printRecord( input );
    cout << "Has been added to banks data base";
}

/*****************************************************************
//
//  Function name:   generateMenu
//
//  DESCRIPTION:     Prints the userInterface Main menu
//
//  Parameters:      prompts (string[]) : Array of strings holding
//                                        key-bindings.
//
//  Return values:   VOID
//
****************************************************************/

void userInterface:: generateMenu( string prompts[] )
{
    string descriptions[6] = { " to add an account.", " to print an account.", " to print all accounts.", " to delete an account.", " to reverse the order of accounts."," to quit program." }; 


    #ifdef DEBUG_MODE
        debugPrintName( "generateMenu();" );
        debugPrint( prompts, "prompts (string[])", true );    
    #endif
    
    cout << '\n' << '\n' << "           - MAIN MENU -" ;
    cout << '\n' << '\n' << "Enter one of the commands to invoke" ;
    cout << '\n' << "the account management functions." ;
    cout << '\n';
    
    for( int k = 0; k < 6; k++ )
    {
        cout << '\n' <<  " Enter \"" << prompts[k] << "\"" << descriptions[k] ;
    }
    cout << "\n\n>";   
}

/*****************************************************************
//
//  Function name:   getDelete
//
//  DESCRIPTION:     Prompts the user about deleting an account.
//
//  Parameters:      list     (llist *) : Pointer to llist obj.
//                   userInput (char[]) : Users input
//
//  Return values:   VOID
//
****************************************************************/

void userInterface:: getDelete( llist * list, char userInput[] )
{
    bool checking = true;
    int input = 0;
    int accountNumber;

    #ifdef DEBUG_MODE
        debugPrintName( "getDelete();" );
        debugPrint( list, "list (llist class obj *)", true );    
        debugPrint( userInput, "userInput (char[])", true );    
        debugPrint( checking, "checking (bool)", false );    
        debugPrint( input, "input (int)", false);    
    #endif
    
    cout << '\n' << '\n' << "You have invoked the delete account function,";
    cout << '\n' << "please enter an account number to delete: ";
    input = this -> getAccountNum();
    cout << '\n' << "You have entered: " << input;
    
    this -> clearBuffer();

    cout << '\n' << "Are you sure you want to delete this acount?";
    cout << '\n' << "Hit \"y\" for yes or hit \"n\" for no\n";
    
    while( checking )
    {
   
        this -> getUserInput( userInput );
        
        if( strcmp( userInput, "y") == 0 )
        {
            checking = false;
              
        } 
        else if( strcmp( userInput, "n" ) == 0 )
        {
            input = -1;
            checking = false;
        }
        else 
        {
            cout << '\n' << "ERROR, please Hit \"y\" for yes or hit \"n\" for no\n";
        }  
        this -> clearBuffer();
    }

    if( input != -1 )
    {
        accountNumber = input;

        input = list -> deleteRecord( accountNumber );
        
        if( input != -1 )
        {
            cout << '\n' << "Account number " << accountNumber <<" has been deleted from the data base.";
        }
        else
        {
            cout << "\nThe account number that you've entered does not exist";
        }
    }
}

/*****************************************************************
//
//  Function name:   getPrint
//
//  DESCRIPTION:     Prompts the user about print an account.
//
//  Parameters:      list     (llist *) : Pointer to llist obj.
//                   userInput (char[]) : Users input
//
//  Return values:   -1 : fail
//                   Account number print if success.
//
****************************************************************/

int userInterface:: getPrint( llist * list, int input)
{
    #ifdef DEBUG_MODE
        debugPrintName( "getPrint();" );
        debugPrint( list, "list (llist class obj *)", true );    
        debugPrint( input, "input (int)", true);    
    #endif

    cout << "\nPlease enter the number of the account you wish to print\n>";
    input = this -> getAccountNum();
    this -> clearBuffer();

    if( list -> printRecord( input ) == -1 )
    {
        cout << "\nThe account you entered does not exist";
    }
    return input;
}

/*****************************************************************
//
//  Function name:  UI
//
//  DESCRIPTION:    Runs user interface program.
//
//  Parameters:     list (llist *) : Pointer to llist class obj.
//
//  Return values:  VOID
//
****************************************************************/

void userInterface:: UI( llist * list )
{
    string prompts[6] = { "add", "print" , "all", "del", "rev", "quit" };

    char userInput[10] = {""};
    char name[25] = {""};
    char address[80] = {""};
    int number = 0;
    bool thisCounter = true;
    bool programRunning = true;

    system( "clear");

    #ifdef DEBUG_MODE
        debugPrintName( "UI();" );
        debugPrint( list, "list (llist class obj *)", true );    
        debugPrint( prompts, "prompts (string[])", false );    
        debugPrint( userInput, "userInput (char[])", false );    
        debugPrint( name, "name (char[])", false );    
        debugPrint( address, "address (char[])", false );    
        debugPrint( number, "number (int)", false);    
        debugPrint( thisCounter, "thisCounter (bool)", false );    
        debugPrint( programRunning, "programRunning (bool)", false );    
    #endif

    
    cout << "\n\nThis banking software lets the user add, delete, and print accounts within a banks database.\n\n";
    
    while( programRunning )
    {

        if( thisCounter )
        {
            cout << '\n' << "Press Enter to return to main menu.";
            cin.get();
            system( "clear" );
            this -> generateMenu( prompts );
        }
        
        strcpy( name, "" );
        strcpy( address, "");

        this -> getUserInput( userInput );
        this -> clearBuffer();
        
        if( userInput == prompts[0] )
        {
            system( "clear" );
            this -> getAccount( list, address, 80, name, 25, number );
            this -> clearBuffer();
            thisCounter = true;
        }
        else if( userInput == prompts[5]  )
        {
            cout << '\n' << "Goodbye";
            programRunning = false;
        }
        else if( userInput == prompts[3] )
        {
            system( "clear" );
            this -> getDelete( list, userInput );

            thisCounter = true;
        }
        else if( userInput == prompts[2] )
        {
            system( "clear" );
            cout << *list;
            thisCounter = true;
        }
        else if ( userInput == prompts[1] )
        {
            system( "clear" );
            number = this -> getPrint( list, number );
           
            if( number == -1 )
            {
                thisCounter = false;
            }
            else
            {
                thisCounter = true;
            }
        }
        else if( userInput == prompts[4] )
        {
            list -> reverse();
            cout << "\nThe order of the accounts has been reversed\n>";
            thisCounter = false;
        }
        else
        {
            cout << "\nInvalid input, please enter a command from the menu\n";
            thisCounter = false;
        }
    }
}
