/*************************************************************************
//  NAME:         Zachary Gilbert
//
//  HOMEWORK:     Project 1
//
//  CLASS:        ICS 212
//
//  INSTRUCTOR:   Ravi Narayan
//
//  DATE:         April 28th, 2018
//
//  FILE:         record.h
//
//  DESCRIPTION:  This file contains the record node structure.
//
*************************************************************************/


/*************************************************************************
//
//  STRUCTURE NAME: record
//
//  DESCRIPTION:    A node for a linked list that contains the behaviors
//                  nessisary for storing bank account records.
//
//  CONTENTS:       accountno        (int): Account number.
//
//                  name          (char[]): Name of customer.
//
//                  address       (char[]): Addres of customer.
//
//                  next  (struct record*): Pointer no next record in
//                                          bank data base.
//
*************************************************************************/


#ifndef _RECORD_STRUCT_
#define _RECORD_STRUCT_
struct record
{
    int accountno;
    char name[ 25 ];
    char address[ 80 ];
    struct record * next;
};

#endif
