#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define uint8 unsigned char
#define size 10


uint8 id[size] ;
uint8 top;
uint8 ch;
int year[size];
uint8 p;

typedef struct{
uint8 *course_1[20];
uint8 *course_2[20];
uint8 *course_3[20];
}Subjects;

typedef struct{
uint8 course_1[20];
uint8 course_2[20];
uint8 course_3[20];
}Grades;

bool SDB_IsFull();
uint8 SDB_GetUsedSize();
bool SDB_AddEntery(uint8,int [],Subjects*,Grades*);
void SDB_deleteEntry(uint8,int [],Subjects*,Grades*);
bool SDB_ReadEntry(uint8,int [],Subjects*,Grades*);
void SDB_GetIdList(uint8 *,uint8[]);
bool SDB_IsIdExist(uint8);

#endif  HEADER_H_INCLUDED
