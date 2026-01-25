#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Student
{
    char name[50];
    int rollNumber;
    float marks[5]; //Assuming 5 subjects
    float totalMarks;
    float percentage;
    char result[20];
};

//Function to input student details
void inputStudentDetails(struct Student* student)
{
    printf("Enter student Name: ");
    scanf("%[^\n]s",student->name);
    printf("Enter Roll Number:");
    scanf("%d",&student->rollNumber);

    printf("Enter Marks for 5 Subjects:\n");
    for(int i=0; i<5; i++)
    {
        printf("Subject %d:", i+1);
        scanf("%f",&student->marks[i]);
        student->totalMarks += student->marks[i];
    }
    student->percentage = (student->totalMarks / 500)* 100;
}
//Function to calculate result for each student
void calculateResult(struct Student* student)
{
    if(student->percentage >= 40)
    {
        strcpy(student->result,"Pass");
    }
    else
    {
        strcpy(student->result, "Fail");
    }
}

//Function to display student report card
void displayReportCard(struct Student* student)
{
    printf("\nReport Card for %s (Roll Number: %d):\n", student->name, student->rollNumber);
    printf("Total Marks: %2f%%\n", student->totalMarks);
    printf("Percentage: %2f%%\n", student->percentage);
    printf("Result: %s\n", student->result);
}
//Function to calculate and display class result
void displayClassResult(struct Student students[], int numStudents)
{
    int passCount = 0;
    for(int i = 0; i < numStudents; i++)
    {
        if(students[i].percentage > 40)
        {
            passCount++;
        }
    }
    printf("\nClass Result:\n");
    printf("Number of Students: %d\n", numStudents);
    printf("Number of students Passed: %d\n", passCount);
    printf("Number of students Failed: %d\n", numStudents - passCount);

    if(passCount == numStudents)
    {
        printf("Overall Class Result: Pass\n");
    }
    else
    {
        printf("Overall Class Result: Fail\n");
    }
}
int main()
{
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    //Dynamically allocate memory for an array of students
    struct Student* students = (struct Student*)malloc(numStudents* sizeof(struct Student));

    //Input details for each student
    for(int i=0; i < numStudents; i++)
    {
        printf("\nEnter details for Student %d:\n", i+1);
        inputStudentDetails(&students[i]);
        calculateResult(&students[i]);
    }

    //Display report card for each student
    for(int i = 0; i < numStudents; i++)
    {
        displayReportCard(&students[i]);
    }

    //Display overall class result
    displayClassResult(students, numStudents);

    //Free the allocated memory
    free(students);

    return 0;
}
