#ifndef _STUDENTMANAGE_H_
#define _STUDENTMANAGE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student_Node{
        char NAME[20];
        int ID;
        struct Student_Node *Next;
}Student_Node;

Student_Node *List_Head=NULL,*List_Tail=NULL;

void Add_Student(char *Name, int *ID);
void Search_by_ID(int *ID);
void Print_All_Students(void);
void Remove_Student(int *ID);

#endif