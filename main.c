#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define uint8 unsigned char
#define size 10
#include "header.h"

int main()
{

    Subjects S[size];
    Subjects*ptr_S =&S;
    Grades G[size];
    Grades*ptr_G =&G;
    uint8 count,list[size],ID,i;
    int year[size],ch;
s:
    printf("                  <<========================== Data Base Module Project =========================>>\n\n"
           "                              Please Select A Number Of Function That You Want to Operate\n\n");
    printf("1: Check If The Data Base Is Full\n"
           "2: Add New Entry To The Data Base\n"
           "3: Get The Number Of Entries In The Data Base\n"
           "4: Read An Entry Matching The Provided ID\n"
           "5: Delete The Entry With The Given ID\n"
           "6: Get The List Of IDS Of The Student\n"
           "7: Check If The Provided Student ID Exists\n"
           "0: Select 0 to Exit\n"
           "\t\t\t\t\t\tchoose Number : ");

    scanf("%d",&ch);
    switch(ch)
    {

    case 1:
        SDB_IsFull()? printf("The Data Base Is Full\n"):
        printf("The Data Base Is Not Full\n");

        break;
    case 2:
        printf("\nPlease Enter Student ID That You Want To Add\n");
        scanf("%d",&ID);
        if(SDB_AddEntery(ID,year,ptr_S,ptr_G))
            printf("\nThe New Entry is Successfully  Added\n");
        else
            printf("\nThe Data Base Is Full\n");
        break;
    case 3:
        printf("\nThe Number Of Entries In The Data Base : %d\n",SDB_GetUsedSize());
        break;
    case 4:
        printf("\nPlease Enter Student ID That You Want To Read\n");
        scanf("%d",&ID);
        if(SDB_ReadEntry(ID,year,ptr_S,ptr_G)==0)
            printf("The Id Is Not found\n");
            break;
        case 5:
            printf("\nEnter The Student ID That you want to Delete\n");
            scanf("%d",&ID);
            SDB_deleteEntry(ID,year,ptr_S,ptr_G);
            break;
        case 6:
            SDB_GetIdList(&count,list);
            printf("\nnumber of IDS:- ( %d )\n",count);
            printf("\nIDS list :-\n");
            for(i=0; i<count; i++)
                printf("\n%d-  %d\n",i+1,list[i]);
            break;
        case 7:
            printf("\nEnter The Student ID That you want to Check\n");
            scanf("%d",&ID);
            SDB_IsIdExist(ID)?
            printf("\nID Exists in Data Base"):
            printf("\nID Not Exists");
            break;
        case 0:
            return ;
        default :
            printf("\t\t\t\t\t\tNot Available Choice\n");
            break;
        }
        goto s;
        return 0;
    }
