#include "StudentManagementSystem.h"

void Add_Student(char *Name, int *ID)
{
    //First of all we have to check if the ID exists in the list
    if(List_Head == NULL)
    {
        //Do nothing
    }
    else
    {
        Student_Node *temp = List_Head;
        while (temp != NULL)
        {
            if(temp->ID == *ID)
            {
                printf("\n\nERROR: ID already exist! please create new unique ID\n\n");
                return;
            }
            temp = temp->Next;
        }
    }

    //create a new node for that student first
    Student_Node *Current = (Student_Node*)malloc(sizeof(Student_Node));
    //check if the allocation is successful
    if(Current == NULL)
    {
        printf("Memory allocation for a new student failed!\n");
        free(Current);
        return;
    }
    else
    {
        printf("Allocation for a new student is done successfully\n");
        Current->ID = *ID;
        strcpy(Current->NAME,Name);
    }
    //Check if the list is empty or not
    //If empty
    if(List_Head == NULL)
    {
        //Empty List
        List_Head = Current;
        List_Head->Next = NULL;

        List_Tail = Current;
        List_Tail->Next = NULL;
        printf("Student Was added successfully!\n");
    }
    else
    {
        //Not empty
        List_Tail->Next = Current;
        List_Tail = Current;
        List_Tail->Next = NULL;
        printf("Student Was added successfully!\n");
    }
}
void Search_by_ID(int *ID)
{
    Student_Node *temp = List_Head;
    while (temp != NULL)
    {
        if(temp->ID == *ID)
        {
            printf("\n\nStudent was found: \n");
            printf("Name: %s\n",temp->NAME);
            printf("ID: %d\n\n",temp->ID);
            return;
        }
        temp = temp->Next;
    }
    
    printf("Student was not found!\n\n");

}
void Print_All_Students(void)
{
    Student_Node *temp;
    temp = List_Head;
    if(List_Head == NULL)
    {
        printf("No students are added yet in the list!\n");
        return;
    }
    else
    {
        int i = 1;
        while(temp != NULL)
        {
            printf("Student %d\n",i);
            printf("Name: %s\n",temp->NAME);
            printf("ID: %d\n",temp->ID);
            printf("************************\n");
            i++;
            temp = temp->Next;
        }
    }
}
void Remove_Student(int *ID)
{
    //search for the student and delete his node
    //if not found print student is not in the list
    Student_Node *temp = List_Head;
    int flag_found = 0;
    while(temp != NULL)
    {
        if(temp->ID == *ID)
        {
            flag_found = 1;
            break;
        }
        temp = temp->Next;
    }

    if(flag_found == 0)
    {
        printf("This student ID does not exist in the list!\n");
    }
    else
    {
        //check if the node is at head, middle, or tail
        if(temp == List_Head)
        {
            List_Head = List_Head->Next;
            free(temp);
            printf("Student is now deleted!\n");
        }
        else if(temp == List_Tail)
        {
            //get the previous node (the node that is before the tail)
            Student_Node *p = List_Head, *n = List_Head->Next;
            while(n != NULL && p != NULL)
            {
                if(n == List_Tail)
                {
                    break;
                }
                n = n->Next;
                p = p->Next;
            }

            List_Tail = p;
            List_Tail->Next = NULL;
            free(temp);
            printf("Student is now deleted!\n");
        }
        else
        {
            //the node is in the middle
            Student_Node *p = List_Head, *n = List_Head->Next;
            while(n != NULL && p != NULL)
            {
                if(n->ID == *ID)
                {
                    break;
                }
                n = n->Next;
                p = p->Next;
            }

            p->Next = n->Next;
            free(temp);
            printf("Student is now deleted!\n");            
        }
    }
}

int main()
{
    //Main program
    program:
    int userChoice;
    printf("\n\n*********************STUDENT-SYSTEM*********************\n");
    printf("************************MainMenu************************\n");
    printf("Choose one option from the following:\n");
    printf("1: Search for a student\n");
    printf("2: Add a new student\n");
    printf("3: delete a student\n");
    printf("4: Show all stuedents\n");
    printf("********************************************************\n");
    printf("Choice: ");
    scanf("%d",&userChoice);

    switch(userChoice)
    {
        case 1:
        if(List_Head == NULL)
        {
            printf("The list is empty, no students to search for!\n");
            goto program;
        }
        int ID;
        printf("\nPlease enter the student ID: ");
        scanf("%d",&ID);
        Search_by_ID(&ID);
        goto program;
        break;

        case 2:
        //Adding new student
        char name[20];
        int ID_create;

        printf("Enter the student name: ");
        scanf("%s",name);
        printf("create a new ID: ");
        scanf("%d",&ID_create);

        //Constraint for ID
        if(ID_create > 9999999 || ID_create < 1000000)
        {
            printf("ERROR: Student ID must be 7 numbers!\n\n");
            goto program;
        }

        printf("\n\n");
        Add_Student(name,&ID_create);

        goto program;
        break;

        case 3:
        //Check if the list is empty first or not
        if(List_Head == NULL)
        {
            printf("The list is empty, there are no students to delete!\n\n");
        }
        else
        {
            //if not search for the student and delete his node
            int delete_ID;
            printf("Enter the student ID: ");
            scanf("%d",&delete_ID);
            Remove_Student(&delete_ID);
        }
        goto program;
        break;

        case 4:
        Print_All_Students();
        printf("\n\n");
        goto program;
        break;

        default:
        printf("Not a right choice please choose options (numbers from 1 to 4 only)\n");
        goto program;
        break;
    }
}