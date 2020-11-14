 /* Author: Nathan Fan, Sifat Jamaly */
 /* Student number: 040842225 */
 /* CST 8234 C Language */
 /* Lab section 022 */
 /* Assignment 1  */
 /* Part B */
 /* Due: 11/13/2020 */
 /* Submitted: 11/13/2020 */
 /* Professor: Natalie Gluzman */
 /* This file provides the header for the functions required for options 1-4 */
 /**********************************/
#include <stdio.h>
#include <stdlib.h>
#ifndef LinkedListFunctions
#define LinkedListFunctions

typedef struct Area {
    int areaCode;
    char AreaName[20];
    struct Area *nextArea;
}   
Area;

typedef struct PhEntry {
    int areaCode;
    int phoneNumber;
    char lastName[20];
    char firstName[20];
    struct PhEntry *next;
} PhEntry;

/*********************************************************************/
/* FUNCTION :  createArea                                            */
/* PURPOSE  :  create a node in the area linked list                 */
/* INPUT    :  headArea                                              */
/* OUTPUT   :  N/A                                                   */
/* NOTES    :                                                        */
/*********************************************************************/
void createArea(struct Area **headArea);


/*********************************************************************/
/* FUNCTION :  displayArea                                           */
/* PURPOSE  :  display area linked list nodes                        */
/* INPUT    :  headArea                                              */
/* OUTPUT   :  N/A                                                   */
/* NOTES    :                                                        */
/*********************************************************************/
void displayArea(struct Area *headArea);

/*********************************************************************/
/* FUNCTION :  insertArea                                            */
/* PURPOSE  :  insert new node into area linked list                 */
/* INPUT    :  headArea                                              */
/* OUTPUT   :  N/A                                                   */
/* NOTES    :                                                        */
/*********************************************************************/
void insertArea(struct Area ***headArea);

/*********************************************************************/
/* FUNCTION :  getnodeArea                                           */
/* PURPOSE  :  allocate new node for area linked list                */
/* INPUT    :  N/A                                                   */
/* OUTPUT   :  N/A                                                   */
/* NOTES    :                                                        */
/*********************************************************************/
struct Area *getnodeArea();

/*********************************************************************/
/* FUNCTION :  searchAreaCode                                        */
/* PURPOSE  :  check if area code exists                             */
/* INPUT    :  headArea, x                                           */
/* OUTPUT   :  1                                                     */
/* NOTES    :                                                        */
/*********************************************************************/
bool searchAreaCode(struct Area* head, int x);

/*********************************************************************/
/* FUNCTION :  searchAreaDesc                                        */
/* PURPOSE  :  check if area description exists                      */
/* INPUT    :  headArea, str[]                                       */
/* OUTPUT   :  1                                                     */
/* NOTES    :                                                        */
/*********************************************************************/
bool searchAreaDesc(struct Area* head, char str[]);

/*********************************************************************/
/* FUNCTION :  create                                                */
/* PURPOSE  :  add node to phonebook linked list                     */
/* INPUT    :  head, headArea                                        */
/* OUTPUT   :  N/A                                                   */
/* NOTES    :                                                        */
/*********************************************************************/
void create(struct PhEntry **head, struct Area **headArea);

/*********************************************************************/
/* FUNCTION :  display                                               */
/* PURPOSE  :  display phonebook linked list nodes                   */
/* INPUT    :  head                                                  */
/* OUTPUT   :  N/A                                                   */
/* NOTES    :                                                        */
/*********************************************************************/
void display(struct PhEntry *head);

/*********************************************************************/
/* FUNCTION :  insert                                                */
/* PURPOSE  :  add node to phonebook linked list                     */
/* INPUT    :  head,headArea                                         */
/* OUTPUT   :  N/A                                                   */
/* NOTES    :                                                        */
/*********************************************************************/
void insert(struct PhEntry ***head, struct Area ***headArea);

/*********************************************************************/
/* FUNCTION :  delNumber                                             */
/* PURPOSE  :  delete an existing phonebook entry after              */
/*             after searching by phonenumber                        */
/* INPUT    :  N/A                                                   */
/* OUTPUT   :  N/A                                                   */
/* NOTES    :                                                        */
/*********************************************************************/
void delNumber();

/*********************************************************************/
/* FUNCTION :  delName                                               */
/* PURPOSE  :  delete an existing phonebook entry after              */
/*             after searching by last name                          */
/* INPUT    :  N/A                                                   */
/* OUTPUT   :  N/A                                                   */
/* NOTES    :                                                        */
/*********************************************************************/
void delName();

/*********************************************************************/
/* FUNCTION :  getCount                                              */
/* PURPOSE  :  count number of phonebook entries                     */
/* INPUT    :  head                                                  */
/* OUTPUT   :  N/A                                                   */
/* NOTES    :                                                        */
/*********************************************************************/
int getCount(struct PhEntry* head);

/*********************************************************************/
/* FUNCTION :  searchNumber                                          */
/* PURPOSE  :  modify an existing phonebook entry after              */
/*             after searching by number                             */
/* INPUT    :  N/A                                                   */
/* OUTPUT   :  N/A                                                   */
/* NOTES    :                                                        */
/*********************************************************************/
bool searchNumber(struct PhEntry* head, struct Area *headArea, int phone,int areaCodeSearch);

/*********************************************************************/
/* FUNCTION :  searchName                                            */
/* PURPOSE  :  modify an existing phonebook entry after              */
/*             after searching by last name                          */
/* INPUT    :  N/A                                                   */
/* OUTPUT   :  N/A                                                   */
/* NOTES    :                                                        */
/*********************************************************************/
bool searchName(struct PhEntry* head, struct Area* headArea, char str[]);

/*********************************************************************/
/* FUNCTION :  getnode                                               */
/* PURPOSE  :  allocate node for phonebook linked list               */
/* INPUT    :  N/A                                                   */
/* OUTPUT   :  struct PhEntry                                        */
/* NOTES    :                                                        */
/*********************************************************************/
struct PhEntry *getnode();



#endif
