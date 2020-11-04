#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Area{ 
    int areaCode;
    char areaName[20];
    struct Area* next; 
};

struct AreaDll{ 
    int areaCode;
    char areaName[20];
    struct AreaDll* next;
    struct AreaDll *prev;
};

struct AreaDll* GetNewNode() {
	struct AreaDll* newNode = (struct Node*)malloc(sizeof(struct AreaDll));
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
} 

bool searchAreaCode(struct Area* head, int x);

struct Area *startArea=NULL;
struct AreaDll *startAreaDll;
/*struct AreaDll *startAreaDll=NULL;*/

int countArea = 0;
struct Area *getnodeArea() {
    return((struct Area *)malloc(sizeof(struct Area)));
}

void displayArea(struct Area *startArea) {
    struct Area *temp;
    temp=startArea;
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

void insertArea() {
    struct Area *temp,*nn;
    int code = 0;
    nn=getnodeArea();
    temp=startArea;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    printf("Enter area code:\n");
    scanf("%d",&code);
    if (!searchAreaCode(startArea,code)) {
        nn->areaCode = code;
        printf("Enter name of area:\n");
        scanf("%s",nn->areaName);
        temp->next=nn;
        nn->next=NULL;
        countArea++;
        displayArea(startArea);
    }
    return;
}

struct Area *createArea() {
    if (countArea < 5) {
        int code = 0;
        struct Area *temp,*nn;
        if(startArea!=NULL)
            insertArea();
        else {
            nn=getnodeArea();
            startArea=nn;
            temp=startArea;
            printf("Enter area code:\n");
            scanf("%d",&code);
            if (!searchAreaCode(startArea,code)) {
                nn->areaCode = code;
                printf("Enter name of area:\n");
                scanf("%s",nn->areaName);
                nn->next=NULL;
                countArea++;
                displayArea(startArea);
            } 
            else {
                printf("Area code already exists in database\n");
            }
        }
    }
    return;
}

/* Checks whether the value x is present in linked list */
bool searchAreaCode(struct Area* head, int x) 
{ 
    /* Base case */
    if (head == NULL) 
        return false; 
      
    /* If key is present in current node, return true */
    if (head->areaCode == x) 
        return true; 
  
    /* Recur for remaining list */
    return searchAreaCode(head->next, x); 
}

/* Checks whether the char array str is present in linked list */
bool searchAreaDesc(struct Area* head, char str[]) 
{ 
    /* Base case */
    if (head == NULL) 
        return false; 
      
    /* If key is present in current node, return true */
    if ( strcmp(head->areaName, str) == 0)
        return true; 
  
    /* Recur for remaining list */
    return searchAreaDesc(head->next, str); 
}



struct PhEntry {
    int areaCode;
    int phoneNumber;
    char lastName[20];
    char firstName[20];
    struct PhEntry *next;
};

struct PhEntry *start=NULL;
int countEntry = 0;
struct PhEntry *getnode()
{
    return((struct PhEntry *)malloc(sizeof(struct PhEntry)));
} 

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

void insert() {
    struct PhEntry *temp,*nn;
    nn=getnode();
    temp=start;
    while(temp->next!=NULL) {
        temp=temp->next;
    }

    printf("Enter First name:\n");
    scanf("%s",nn->firstName);
    printf("Enter Last name:\n");
    scanf("%s",nn->lastName);
    printf("Enter area code:\n");
    scanf("%d",&nn->areaCode);
    while (!searchAreaCode(startArea,nn->areaCode)) {
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

struct PhEntry *create() {
    if (countEntry < 10) {
        struct PhEntry *temp,*nn;
        if(start!=NULL)
            insert();
        else {
            nn=getnode();
            start=nn;
            temp=start;
            printf("Enter First name:\n");
            scanf("%s",nn->firstName);
            printf("Enter Last name:\n");
            scanf("%s",nn->lastName);
            printf("Enter area code:\n");
            scanf("%d",&nn->areaCode);
            if (!searchAreaCode(startArea,nn->areaCode)) {
                printf("entered area code does not exist\n");
                free(nn);
                return;
            }
            printf("Enter number:\n");
            scanf("%d",&nn->phoneNumber);
            countEntry++;
            printf("%d\n",countEntry);
            display(start);
        }
    }
}

void delNumber() {
    struct PhEntry *pretemp,*temp;
    int n;
    temp=start;
    pretemp=start->next;
    int code;
    printf("Enter area code:\n");
    scanf("%d",&code);
    printf("Enter number:");
    scanf("%d",&n);
    while(temp!=NULL)
    {
        if( (pretemp->phoneNumber == n)&&(pretemp->areaCode==code) )
        {
            printf("%s ",temp->firstName);
            printf("%s ",temp->lastName);
            printf("%d ",temp->phoneNumber);
            temp->next=pretemp->next;
            free(pretemp);
            countEntry--;
            break;
        }
        else 
        {
            temp=temp->next;
            pretemp=pretemp->next;
        }
    }
}

void delName() {
    struct PhEntry *pretemp,*temp;
    char l[20];
    temp=start;
    pretemp=start->next;
    printf("Enter last name :");
    scanf("%s",l);
    while(temp!=NULL)
    {
        if( (strcmp(pretemp->lastName,l) == 0) )
        {
            printf("%s ",temp->firstName);
            printf("%s ",temp->lastName);
            printf("%d ",temp->phoneNumber);
            temp->next=pretemp->next;
            free(pretemp);
            return;
        }
        else 
        {
            temp=temp->next;
            pretemp=pretemp->next;
        }
    }
    countEntry--;
}

void dll() {
    struct Area* tempArea = startArea;
    while (tempArea != NULL)
    {
        struct AreaDll* temp = startAreaDll;
        struct AreaDll* newNode = GetNewNode();
        if(startAreaDll == NULL) {
            startAreaDll = newNode;
            startAreaDll->areaCode = tempArea->areaCode;
            (*startAreaDll->areaName) = (*tempArea->areaName);
            return;
        }

        while(temp->next != NULL) temp = temp->next; // Go To last Node
        temp->next = newNode;
        (*temp->areaName) = (*tempArea->areaName);
        temp->areaCode = tempArea->areaCode;
        newNode->prev = temp;
        tempArea = tempArea->next;
    }
}

/* Counts no. of nodes in linked list */
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

/*Function to modify phonebook entry after searching by number*/

/* Checks whether the value x is present in linked list */
bool searchNumber(struct PhEntry* head, int phone,int areaCodeSearch) {
    int choice = 0;
    int code; 
    /* Base case */
    if (head == NULL) {
        return false; 
    }

    /* If key is present in current node, return true */
    if ((head->phoneNumber == phone)&&(head->areaCode=areaCodeSearch)) {
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
                    if (searchAreaCode(startArea,code)) {
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
    return searchNumber(head->next, phone,areaCodeSearch); 
} 

bool searchName(struct PhEntry* head, char str[]) { 
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
                    if (searchAreaCode(startArea,code)) {
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
                default:
                    break;
            }
        }
    }
        return true; 
    /* continue recursion for rest of list */
    return searchName(head->next, str); 
}

void dllDeleteCode() {
    if (startAreaDll == NULL)  {
        return;
    }
    printf("Please enter the area code you wish to delete.\n");
    int code;
    scanf("%d",&code);
    if (searchAreaCode(startArea,code)) {
        struct AreaDll *tempArea;
        tempArea = getnodeDll();
        *tempArea=*startAreaDll;
        struct PhEntry *tempEntry;
        tempEntry = getnode();
        *tempEntry = *start;
        while (tempArea != NULL)
        {
            if ( (tempArea->areaCode = code))
            {
                break; /*arrived at the node that we are looking for*/
            }
            *tempArea = *tempArea->next; 
        }

        while (tempEntry != NULL)
        {
            if (tempEntry->areaCode == code)
            {
                printf("Area is in use and cannot be deleted.\n");
                return;
            }
            *tempEntry = *tempEntry->next;
        }
        /*if node to be deleted is still the head node*/
        if (tempArea == startAreaDll)
        {
            startAreaDll = tempArea->next;
        }

        if (tempArea->next != NULL)
        {
            tempArea->next->prev = tempArea->next;
        }

        if (tempArea->prev != NULL)
        {
            tempArea->prev->next = tempArea->next;
        }

        free(tempArea);
        return;
    }

}

void dllDeleteDesc() {
    /* base case */
    if (startArea == NULL && start == NULL)  {
        return;
    }
    char desc[20];
    printf("Enter area description :");
    scanf("%s",desc);
    if (searchAreaDesc(startArea,desc)) {
        struct AreaDll *tempArea;
        tempArea = getnodeDll();
        *tempArea=*startAreaDll;
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
                    if ( (tempArea->areaCode = code) && ( strcmp(tempArea->areaName, desc) == 0))
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
                    tempArea->next->prev = tempArea->next;
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
            *tempArea = *startAreaDll;
            while (tempArea != NULL)
            {
                if ( ( strcmp(tempArea->areaName, desc) == 0))
                {
                    break; /*arrived at the node that we are looking for*/
                }
                *tempArea = *tempArea->next; 
            }
            struct PhEntry *tempEntry;
            tempEntry = getnode();
            *tempEntry = *start;
            while (tempEntry != NULL)
            {
                if (tempArea->areaCode == tempEntry->areaCode)
                {
                    printf("Area is in use and cannot be deleted.\n");
                    return;
                }
                *tempEntry = *tempEntry->next;
            }
            /*if node to be deleted is still the head node*/
            if (tempArea == startAreaDll)
            {
                startAreaDll = tempArea->next;
            }

            if (tempArea->next != NULL)
            {
                tempArea->next->prev = tempArea->next;
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

int main() {
    char choice = 'a';
    int option;
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
                createArea();
                break;
            case 2:
                create();
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
                    searchName(start,lastNameSearch);
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
                        searchNumber(start,phoneNumberSearch,areaCodeSearch);
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
            case 5: ;
                dll();
                printf("Would you like to search by area code or description?\n");
                printf("1 for area code and 2 for description\n");
                scanf("%d",&option);
                switch (option)
                {
                case 1:
                    dllDeleteCode();
                    break;
                case 2:
                    dllDeleteDesc();
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
        }
    }
    return 0;
}