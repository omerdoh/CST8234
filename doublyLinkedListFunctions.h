 /* Author: Nathan Fan, Sifat Jamaly */
 /* Student number: 040842225 */
 /* CST 8234 C Language */
 /* Lab section 022 */
 /* Assignment 1  */
 /* Part B */
 /* Due: 11/13/2020 */
 /* Submitted: 11/13/2020 */
 /* Professor: Natalie Gluzman */
 /* This file provides the header for the doubly linked list functions */
 /**********************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*#include "LinkedListFunctions.h"*/
#ifndef doublyLinkedListFunctions
#define doublyLinkedListFunctions

struct AreaDll{ 
    int areaCode;
    char areaName[20];
    struct AreaDll *next;
    struct AreaDll *prev;
};


/*********************************************************************/
/* FUNCTION :  GetNewNode                                            */
/* PURPOSE  :  Function to be called for allocating new node         */
/* INPUT    :  N/A                                                   */
/* OUTPUT   :  Returns a node                                        */
/* NOTES    :                                                        */
/*********************************************************************/
struct AreaDll* GetNewNode();


/*********************************************************************/
/* FUNCTION :  dll                                                   */
/* PURPOSE  :  turns Area singly linked list into double linked list */
/* INPUT    :  startArea                                             */
/* OUTPUT   :  N/A                                                   */
/* NOTES    :                                                        */
/*********************************************************************/
void dll(struct Area** startArea);

/*********************************************************************/
/* FUNCTION :  dllDeleteDesc                                         */
/* PURPOSE  :  searches doubly linked list by description            */
/* INPUT    :  start, startArea                                      */
/* OUTPUT   :  N/A                                                   */
/* NOTES    :                                                        */
/*********************************************************************/
void dllDeleteDesc(struct PhEntry* start,struct Area* startArea);


/*********************************************************************/
/* FUNCTION :  dllDeleteCode                                         */
/* PURPOSE  :  searches doubly linked list by area code              */
/* INPUT    :  startArea, head            \                          */
/* OUTPUT   :  N/A                                                   */
/* NOTES    :                                                        */
/*********************************************************************/
void dllDeleteCode(struct Area** startArea, struct PhEntry** head);


/*********************************************************************/
/* FUNCTION :  deleteDll                                             */
/* PURPOSE  :  resets doubly linkedList                              */
/* INPUT    :  cur                                                   */
/* OUTPUT   :  N/A                                                   */
/* NOTES    :                                                        */
/*********************************************************************/
void deleteDll(struct AreaDll *cur);

/*********************************************************************/
/* FUNCTION :  displayAreaDll                                        */
/* PURPOSE  :  displays doubly linkedList                            */
/* INPUT    :  N/A                                                   */
/* OUTPUT   :  N/A                                                   */
/* NOTES    :                                                        */
/*********************************************************************/
void displayAreaDll();

#endif
