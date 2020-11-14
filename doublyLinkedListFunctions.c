 /* Author: Nathan Fan, Sifat Jamaly */
 /* Student number: 040842225 */
 /* CST 8234 C Language */
 /* Lab section 022 */
 /* Assignment 1  */
 /* Part B */
 /* Due: 11/13/2020 */
 /* Submitted: 11/13/2020 */
 /* Professor: Natalie Gluzman */
 /* This file provides the double linked list function definitions  */
 /**********************************/

#include <stdio.h>
#include <stdlib.h>
#include "doublyLinkedListFunctions.h"
#include "LinkedListFunctions.h"
#include <string.h>
	

struct AreaDll* startAreaDll; 

void displayAreaDll() {
    struct AreaDll *temp;
    temp=startAreaDll;
    while(temp!=NULL)
    {
        printf("\n");
        printf("%d\n",temp->areaCode);
        printf("%s\n",temp->areaName);
        temp=temp->next;
    }
    printf("\n");
    return;
}

struct AreaDll* GetNewNode() {
	struct AreaDll* newNode = (struct AreaDll*)malloc(sizeof(struct AreaDll));
    newNode->areaCode = 0;
    newNode->areaName[0] = '\0';
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}


void deleteDll(struct AreaDll *cur) {
    if (cur == NULL) return;
    deleteDll( cur->next );
    free(cur);
}

void dll(struct Area** startArea) {
    deleteDll(startAreaDll);
    startAreaDll = NULL;
    
    struct Area* tempArea = *startArea;
    while (tempArea != NULL)
    {
        struct AreaDll* newNode = GetNewNode();
        if(startAreaDll == NULL) {
            startAreaDll = newNode;
            startAreaDll->areaCode = tempArea->areaCode;
            strcpy(startAreaDll->areaName, tempArea->AreaName);
            continue;
        }
        struct AreaDll* temp = startAreaDll;

        /* Go To last Node */
        while(temp->next != NULL) temp = temp->next;

        temp->next = newNode;
        temp->areaCode = tempArea->areaCode;
        strcpy(temp->areaName, tempArea->AreaName);
        newNode->prev = temp;

        tempArea = tempArea->nextArea;
    }
}

void dllDeleteCode(struct Area** startArea, struct PhEntry** head) {
    if (startAreaDll == NULL)  {
        return;
    }
    printf("Please enter the area code you wish to delete.\n");
    int code;
    scanf("%d",&code);
    if (searchAreaCode(*startArea,code)) {
        struct AreaDll *tempArea;
        tempArea = startAreaDll;
        struct PhEntry *tempEntry;
        tempEntry = *head;
        while (tempArea != NULL)
        {
            if (tempArea->areaCode == code)
            {
                break; /*arrived at the node that we are looking for*/
            }
            tempArea = tempArea->next; 
        }

        while (tempEntry != NULL)
        {
            if (tempEntry->areaCode == code)
            {
                printf("Area is in use and cannot be deleted.\n");
                return;
            }
            tempEntry = tempEntry->next;
        }
        /*if node to be deleted is still the head node*/
        if (tempArea == startAreaDll)
        {
            startAreaDll = tempArea->next;
        }

        if (tempArea->next != NULL)
        {
            tempArea->next->prev = tempArea->prev;
        }

        if (tempArea->prev != NULL)
        {
            tempArea->prev->next = tempArea->next;
        }

        free(tempArea);
    }
}

void dllDeleteDesc(struct PhEntry* start,struct Area* startArea) {
    /* base case */
    if (startArea == NULL && start == NULL)  {
        return;
    }
    char desc[20];
    printf("Enter area description :");
    scanf("%s",desc);
    if (searchAreaDesc(startArea,desc)) {
        struct AreaDll *tempArea;
        tempArea = startAreaDll;
        int areaCount  = 0;
        while (tempArea != NULL) 
        {
            if ( strcmp(tempArea->areaName, desc) == 0) {
                areaCount++;
            }
            tempArea=tempArea->next;
        }
        if (areaCount > 1) {
            printf("The description given has more than 1 corresponding area code.\n");
            printf("Please enter the area code you wish to delete.\n");
            int code;
            scanf("%d",&code);
            tempArea = startAreaDll;
            if (searchAreaCode(startArea,code))
            {
                while (tempArea != NULL)
                {
                    if ((tempArea->areaCode == code) && (strcmp(tempArea->areaName, desc) == 0))
                    {
                        break; /*arrived at the node that we are looking for*/
                    }
                    tempArea = tempArea->next; 
                }
            
                struct PhEntry *tempEntry;
                tempEntry = start;
                while (tempEntry != NULL)
                {
                    if (tempArea->areaCode == tempEntry->areaCode)
                    {
                        printf("Area is in use and cannot be deleted.\n");
                        return;
                    }
                    tempEntry = tempEntry->next;
                }
                /*if node to be deleted is still the head node*/
                if (tempArea == startAreaDll)
                {
                    startAreaDll = tempArea->next;
                }

                if (tempArea->next != NULL)
                {
                    tempArea->next->prev = tempArea->prev;
                }

                if (tempArea->prev != NULL)
                {
                    tempArea->prev->next = tempArea->next;
                }
                
                free(tempArea);
                return;
            } 
            else 
            {
                printf("Invalid area code.\n");
                return;
            }
        } else
        {
            tempArea = startAreaDll;
            while (tempArea != NULL)
            {
                if (strcmp(tempArea->areaName, desc) == 0)
                {
                    break; /*arrived at the node that we are looking for*/
                }
                tempArea = tempArea->next; 
            }
            struct PhEntry *tempEntry;
            tempEntry = start;
            while (tempEntry != NULL)
            {
                if (tempArea->areaCode == tempEntry->areaCode)
                {
                    printf("Area is in use and cannot be deleted.\n");
                    return;
                }
                tempEntry = tempEntry->next;
            }
            /*if node to be deleted is still the head node*/
            if (tempArea == startAreaDll)
            {
                startAreaDll = tempArea->next;
            }

            if (tempArea->next != NULL)
            {
                tempArea->next->prev = tempArea->prev;
            }

            if (tempArea->prev != NULL)
            {
                tempArea->prev->next = tempArea->next;
            }
            
            free(tempArea);
            return;
        }
    } else {
        printf("Area name does not exist.\n");
        return;
    }
}