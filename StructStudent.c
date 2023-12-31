#include<stdio.h>
#include<stdlib.h>

typedef struct student{
    char name[20];
    int regNo;
    int marks[3];
    int avg;
}student;



student*p; 
int i,j;

void read(int n)
{
    p=(student*)malloc(n*sizeof(student));
    for(i=0; i<n; i++)
    {
        printf("\nEnter the details for student %d",i+1);
        printf("\nName:\t"); scanf("%s",(p+i)->name);
        printf("\nRoll no:\t"); scanf("%d",&(p+i)->regNo);
        for(j=0; j<3; j++)
        {
            printf("\nEnter the marks in subject %d:\t",j+1);
            scanf("%d",&(p+i)->marks[j]);
        }
        printf("\n\n");
    }
}

void display(int n)
{
    for(i=0; i<n; i++)
    {
        printf("\nDetails for student %d",i+1);
        printf("\nName:\t"); printf("%s",(p+i)->name);
        printf("\nRoll no:\t"); printf("%d",(p+i)->regNo);
        for(j=0; j<3; j++)
        {
            printf("\nMarks in subject %d:\t",j+1);
            printf("%d",(p+i)->marks[j]);
        }
        printf("\n\n");
    }
}

void average (int n)
{   
    int a=0, lowest;
    for(i=0; i<n; i++)
    {
        a = 0;
        for(j=0; j<3; j++)
        {
            a = a + (p+i)->marks[j];
        }
    lowest = ((p+i)->marks[0]<=(p+i)->marks[1])?((p+i)->marks[0]<=(p+i)->marks[2]?(p+i)->marks[0]:(p+i)->marks[2]):((p+i)->marks[1]<=(p+i)->marks[2]?(p+i)->marks[1]:(p+i)->marks[2]);
    
        a = a-lowest;
    printf("\nAverage of best 2 marks in subjects for student %d:\t%.2f",i+1,(float)a*0.5);    
    }
}

int main()
{   int m; char c;
    printf("Number of students:\t");
    scanf("%d",&m);
    
    read(m);
    display(m);
    average(m);
    return 0;
    
}


