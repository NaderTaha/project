#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define uint8 unsigned char
#define size 10
#include "header.h"

bool SDB_IsFull(void){
if(top>=size)
    return 1;
    return 0;
}

uint8 SDB_GetUsedSize(void){
return top;
}

bool SDB_AddEntery(uint8 ID,int year[],Subjects*ptr_S,Grades*ptr_G){

if(top>=size)
    return 0;
else{
id[top]=ID;
printf("Please Enter Student Year\n");
scanf("%d",&year[top]);
printf("Please Enter 3 Subjects IDS\n\n");
printf("subject_1:-\t");
scanf("%s",(ptr_S+top)->course_1);
printf("subject_2:-\t");
scanf("%s",(ptr_S+top)->course_2);
printf("subject_3:-\t");
scanf("%s",(ptr_S+top)->course_3);
start_1:
printf("\nPlease Enter 3 Grades of Subjects IDS\n"
"The Allowed Range For The Grade Is Only From 0 To 100\n\n");
printf("Grade_1 :  ");
scanf("%d",(ptr_G+top)->course_1);
if(*(ptr_G+top)->course_1>100 || *(ptr_G+top)->course_1<0)
   {printf("\nOut Of Allowed Range\n");
    goto start_1;}
start_2:
printf("Grade_2 :  ");
scanf("%d",(ptr_G+top)->course_2);
if(*(ptr_G+top)->course_2>100 || *(ptr_G+top)->course_2<0)
   {printf("\nOut Of  Allaowed Range\n");
    goto start_2;}
start_3:
printf("Grade_3 :  ");
scanf("%d",(ptr_G+top)->course_3);
if(*(ptr_G+top)->course_3>100 || *(ptr_G+top)->course_3<0)
   {printf("\nOut Of Allowd Range\n");
    goto start_3;}
top++;
}
return 1;
}

void SDB_deleteEntry(uint8 ID,int year[],Subjects *ptr_S,Grades *ptr_G){

for(p=0;p<=top;p++)
    if(id[p]==ID)
        break;
   if(id[p]!=ID){
    printf("The Entry Not Found");
return ;
}
if(top==0)
printf("\nThe Data Base Is Empty \n");

else if(size-1==p){
top--;
printf("The Entry Is Deleted\n");
}
else{
for(;p<=top;p++){
id[p]=id[p+1];
year[p]=year[p+1];
*(ptr_S+p)=*(ptr_S+p+1);
*(ptr_G+p)=*(ptr_G+p+1);
}
top--;
printf("The Entry Is Deleted\n");
}
}
bool SDB_ReadEntry(uint8 ID,int year[],Subjects *ptr_S,Grades *ptr_G){

for(p=0;p<=top;p++)
    if(id[p]==ID)
    break;
if(id[p]==ID){
printf("Student Year : %d\n",year[p]);
printf("Subject_1 :  %s\n",(ptr_S+p)->course_1);
printf("Subject_2 :  %s\n",(ptr_S+p)->course_2);
printf("Subject_3 :  %s\n",(ptr_S+p)->course_3);
printf("Grade_1   :  %d\n",*(ptr_G+p)->course_1);
printf("Grade_2   :  %d\n",*(ptr_G+p)->course_2);
printf("Grade_3   :  %d\n",*(ptr_G+p)->course_3);
return 1;
}
return 0;
}

void SDB_GetIdList(uint8 *count,uint8 list[]){

if(top==0)
    printf("The Data Base Is Empty\n");
else {
uint8 i;
*count=top;
for(i=0;i<*count;i++)
    list[i]=id[i];

}
}

bool SDB_IsIdExist(uint8 ID){

uint8 i;
for(i=0;i<top;i++)
    if(id[i]==ID)
        return 1;
        return 0;
}
