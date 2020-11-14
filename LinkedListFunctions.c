 /* Author: Nathan Fan, Sifat Jamaly */
 /* Student number: 040842225 */
 /* CST 8234 C Language */
 /* Lab section 022 */
 /* Assignment 1  */
 /* Part B */
 /* Due: 11/13/2020 */
 /* Submitted: 11/13/2020 */
 /* Professor: Natalie Gluzman */
 /* This file provides the linked list function definitions required for options 1-4 */
 /**********************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "LinkedListFunctions.h"
/*#include "doublyLinkedListFunctions.h"*/
#include "doublyLinkedListFunctions.c"



struct PhEntry *start = NULL;
struct Area *startArea = NULL;

int countArea = 0;
struct Area *getnodeArea() {
    return((struct Area *)calloc(1, sizeof(struct Area)));
}

/**************************************************************************/
/* display area linked list                                               */
/**************************************************************************/
void displayArea(struct Area *headArea) {
    struct Area *temp=headArea;
    while(temp!=NULL)
    {
        printf("\n");
        printf("%d\n",temp->areaCode);
        printf("%s\n",temp->AreaName);
        temp=temp->nextArea;
    }
    printf("\n");
    return;
}

/**************************************************************************/
/* insert new node into area linked list                                  */
/**************************************************************************/
void insertArea(struct Area ***headArea) {
    struct Area *temp,*nn;
    int code = 0;
    nn=getnodeArea();
    temp=**headArea;
    while(temp->nextArea!=NULL)
    {
        temp=temp->nextArea;
    }
    printf("Enter area code:\n");
    scanf("%d",&code);
    if ( (!searchAreaCode(**headArea,code)) && !(code == 905 || code == 647 || code == 613 || code == 416 || code == 519) ) {
        nn->areaCode = code;
        printf("Enter name of area:\n");
        scanf("%s",nn->AreaName);
        temp->nextArea=nn;
        nn->nextArea=NULL;
        countArea++;
        temp=**headArea;
        displayArea(temp);
    }
    return;
}

/**************************************************************************/
/* create a node in the area linked list                                  */
/**************************************************************************/
 void createArea(struct Area **headArea) {
    if (countArea < 5) {
        int code = 0;
        struct Area *nn;
        if(headArea!=NULL)
            insertArea(&headArea);
        else {
            nn=getnodeArea();
            *headArea=nn;
            printf("Enter area code:\n");
            scanf("%d",&code);
            if ( (code == 905 || code == 647 || code == 613 || code == 416 || code == 519) && (!searchAreaCode(*headArea,code))  ) {
                nn->areaCode = code;
                printf("Enter name of area:\n");
                scanf("%s",nn->AreaName);
                nn->nextArea=NULL;
                countArea++;
                struct Area *temp;
                temp=*headArea;
                displayArea(temp);
            } 
            else {
                printf("Area code already exists in database\n");
            }
        }
    }
    return ;
}


/**************************************************************************/
/* Checks whether the value x is present in linked list                   */
/**************************************************************************/
bool searchAreaCode(struct Area* head, int x) 
{ 
    /* Base case */
    if (head == NULL) 
        return false; 
      
    /* If key is present in current node, return true */
    if (head->areaCode == x) 
        return true; 
  
    /* Recur for remaining list */
    return searchAreaCode(head->nextArea, x); 
}

/**************************************************************************/
/* Checks whether the char array str is present in linked list            */
/**************************************************************************/
bool searchAreaDesc(struct Area* head, char str[]) 
{ 
    /* Base case */
    if (head == NULL) 
        return false; 
      
    /* If key is present in current node, return true */
    if ( strcmp(head->AreaName, str) == 0)
        return true; 
  
    /* Recur for remaining list */
    return searchAreaDesc(head->nextArea, str); 
}

int countEntry = 0;

/**************************************************************************/
/* allocate node for phonebook linked list                                */
/**************************************************************************/
struct PhEntry *getnode()
{
   return (struct PhEntry *)calloc(1, sizeof(struct PhEntry));
} 

/**************************************************************************/
/* display phonebook linked list nodes                                    */
/**************************************************************************/
void display(struct PhEntry *start)
{
    struct PhEntry *temp;
    temp=start;
    while(temp!=NULL)
    {
        printf("\n");
        printf("%s\n",temp->firstName);
        printf("%s\n",temp->lastName);
        printf("%d-", temp->areaCode);
        printf("%d\n",temp->phoneNumber);
        temp=temp->next;
    }
    printf("\n");
    printf("\n");
}

/**************************************************************************/
/* add node to phonebook linked list                                      */
/**************************************************************************/
void insert(struct PhEntry ***head,struct Area ***headArea) {
    struct PhEntry *nn;
    nn=getnode();

    printf("Enter First name:\n");
    scanf("%s",nn->firstName);
    printf("Enter Last name:\n");
    scanf("%s",nn->lastName);
    printf("Enter area code:\n");
    scanf("%d",&nn->areaCode);
    while (!searchAreaCode(**headArea,nn->areaCode)) {
        printf("entered area code does not exist\n");
        printf("Enter area code:\n");
        scanf("%d",&nn->areaCode);
    }
    printf("Enter number:\n");
    scanf("%d",&nn->phoneNumber);

    nn->next=start;
    start = nn;
    display(start);
    countEntry++;
}

/**************************************************************************/
/* add node to phonebook linked list                                      */
/**************************************************************************/
void create(struct PhEntry **head,struct Area **headArea) {
    if (countEntry < 10) {
        struct PhEntry *nn;
        if(start!=NULL)
            insert(&head, &headArea);
        else {
            nn=getnode();
            start=nn;
            printf("Enter First name:\n");
            scanf("%s",nn->firstName);
            printf("Enter Last name:\n");
            scanf("%s",nn->lastName);
            printf("Enter area code:\n");
            scanf("%d",&nn->areaCode);
            if (!searchAreaCode(*headArea,nn->areaCode)) {
                printf("entered area code does not exist\n");
                free(nn);
                return;
            }
            printf("Enter number:\n");
            scanf("%d",&nn->phoneNumber);
            countEntry++;
            printf("%d\n",countEntry);
             struct PhEntry *temp;
            temp=*head;
            display(temp);
        }
    }
}

/***************************************************************************/
/* delete an existing phonebook entry after after searching by phonenumber */
/***************************************************************************/
void delNumber() {
    struct PhEntry *pretemp,*temp;
    temp = start;
    pretemp = NULL;
    int n;
    int code;
    printf("Enter area code:\n");
    scanf("%d",&code);
    printf("Enter number:");
    scanf("%d",&n);
    while(temp != NULL)
    {
        if((temp->phoneNumber == n) && (temp->areaCode==code) )
        {
            printf("%s ",temp->firstName);
            printf("%s ",temp->lastName);
            printf("%d\n",temp->phoneNumber);

            if (pretemp != NULL) pretemp->next = temp->next;
            else start = temp->next;

            free(temp);
            break;
        }

        pretemp = temp;
        temp = temp->next;
    }
}

/***************************************************************************/
/* delete an existing phonebook entry after after searching by last name   */
/***************************************************************************/
void delName() {
    struct PhEntry *pretemp,*temp;
    char l[20];
    temp = start;
    pretemp = NULL;
    printf("Enter last name :");
    scanf("%s",l);
    while(temp != NULL)
    {
        if(strcmp(temp->lastName, l) == 0)
        {
            printf("%s ", temp->firstName);
            printf("%s ", temp->lastName);
            printf("%d ", temp->phoneNumber);

            if (pretemp != NULL) pretemp->next = temp->next;
            else start = temp->next;

            free(temp);
            break;
        }
        
        pretemp = temp;
        temp = temp->next;
    }
    countEntry--;
}

/***************************************************************************/
/* Counts no. of nodes in linked list                                      */
/***************************************************************************/
int getCount(struct PhEntry* head) 
{ 
    int count = 0;  /* Initialize count */
    struct PhEntry* current = head;  /* Initialize current*/ 
    while (current != NULL) 
    { 
        count++; 
        current = current->next; 
    } 
    return count; 
} 

/**************************************************************************/
/* Function to modify phonebook entry after searching by number           */
/**************************************************************************/
bool searchNumber(struct PhEntry* head, struct Area *headArea, int phone,int areaCodeSearch) {
    int choice = 0;
    int code; 
    /* Base case */
    if (head == NULL) {
        return false; 
    }

    /* If key is present in current node, return true */
    if ((head->phoneNumber == phone) && (head->areaCode == areaCodeSearch)) {
        while (choice != 5) {
            printf("Press [1] to modify Area information\n");
            printf("Press [2] to modify Phone number\n");
            printf("Press [3] to modify last name\n");
            printf("Press [4] to modify first name\n");
            printf("Press [5] to stop modifying\n");
            scanf("%d",&choice);
            printf("you entered a number\n");
            switch (choice) {
                case 1:
                    printf("Enter area code:\n");
                    scanf("%d",&code);
                    if (searchAreaCode(headArea,code)) {
                        head->areaCode = code;
                    }
                    break;
                case 2:
                    printf("Enter number:\n");
                    scanf("%d",&head->phoneNumber);
                    break;
                case 3:
                    printf("Enter Last name:\n");
                    scanf("%s",head->lastName);
                    break;
                case 4:
                    printf("Enter First name:\n");
                    scanf("%s",head->firstName);
                    break;
                default:
                    break;
            }
        }
    }
    return true; 
    /* Recur for remaining list */
    return searchNumber(head->next, headArea->nextArea, phone,areaCodeSearch); 
} 

/**************************************************************************/
/* Function to modify phonebook entry after searching by last name        */
/**************************************************************************/
bool searchName(struct PhEntry* head, struct Area* headArea, char str[]) { 
    int choice = 0;
    int code; 

    /* Base case */
    if (head == NULL) 
        return false; 
      
    /* If last name is in list, then start modifying */
    if( strcmp( head->lastName, str ) == 0 ) {
    
        while (choice != 5) {
            printf("Press [1] to modify Area information\n");
            printf("Press [2] to modify Phone number\n");
            printf("Press [3] to modify last name\n");
            printf("Press [4] to modify first name\n");
            printf("Press [5] to stop modifying\n");
            scanf("%d",&choice);
            switch (choice) {
                case 1:
                    printf("Enter area code:\n");
                    scanf("%d",&code);
                    if (searchAreaCode(headArea,code)) {
                        head->areaCode = code;
                    }
                    else
                    {
                        printf("entered area code does not exist\n");
                    }
                    
                    break;
                case 2:
                    printf("Enter number:\n");
                    scanf("%d",&head->phoneNumber);
                    break;
                case 3:
                    printf("Enter Last name:\n");
                    scanf("%s",head->lastName);
                    break;
                case 4:
                    printf("Enter First name:\n");
                    scanf("%s",head->firstName);
                    break;
                case 5: ;
                    dll(&startArea);
                    printf("Would you like to search by area code or description?\n");
                    printf("1 for area code and 2 for description\n");
                    int option = 0;
                    scanf("%d",&option);
                    switch (option)
                    {
                    case 1:
                        dllDeleteCode(&startArea,&start);
                        break;
                    case 2:
                        dllDeleteDesc(start,startArea);
                        break;
                    default:
                        break;
                    }
                    displayAreaDll();
                    break;
                default:
                    break;
            }
        }
    }
        return true; 
    /* continue recursion for rest of list */
    return searchName(head->next, headArea->nextArea, str); 
}


/**************************************************************************/
/* driver                                                                 */
/**************************************************************************/
int main() {
    char choice = 'a';
    int option = 0;
    while (option != 6) {
        printf("Press [1] to Enter Area information\n");
        printf("Press [2] to Enter Phonebook Entry\n");
        printf("Press [3] to Modify an existing Phonebook Entry\n");
        printf("Press [4] to Delete an existing Phonebook Entry\n");
        printf("Press [5] to Delete an unused Area using doubly linked list\n");
        scanf("%d",&option);
        switch (option) {
            case 1:
                printf("main option 1\n");
                createArea(&startArea);
                break;
            case 2:
                create(&start,&startArea);
                break;
            case 3:
                printf("Would you like to search by phone number or last name?\n");
                printf("l for last name and n for phone number\n");
                getchar();
                scanf("%c",&choice);
                if (choice == 'l') {
                    printf("Enter last name to search by\n");
                    char lastNameSearch[20];
                    scanf("%s",lastNameSearch);
                    searchName(start,startArea,lastNameSearch);
                }
                else if (choice == 'n') 
                {
                    int phoneNumberSearch;
                    int areaCodeSearch;
                    printf("Enter area code:\n");
                    scanf("%d",&areaCodeSearch);
                    if (searchAreaCode(startArea,areaCodeSearch)) {
                        printf("Enter phone number to search by\n");
                        scanf("%d",&phoneNumberSearch);
                        searchNumber(start,startArea,phoneNumberSearch,areaCodeSearch);
                    } else
                    {
                        printf("entered area code does not exist\n");
                    }
                    
                }
                break;
            case 4:
                printf("Would you like to search by phone number or last name?\n");
                printf("l for last name and n for phone number\n");
                getchar();
                scanf("%c",&choice);
                if (choice == 'l') {
                    delName();
                }
                if (choice == 'n') {
                    delNumber();
                }
                break;
            default:
                break;
        }
    }
    return 0;
}