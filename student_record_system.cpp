#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Student records
typedef struct{
    int rollNo;
    char name[50];
    float marks;
} Student;

Student students[100];
int studentCount = 0;

void addStudent(){
    if(studentCount < 100){
        Student newStudent;
        printf("Enter Roll Number: ");
        scanf("%d", &newStudent.rollNo);
        getchar();
        printf("Enter Name: ");
        scanf("%[^\n]", newStudent.name);
        getchar();
        printf("Enter Marks: ");
        scanf("%f", &newStudent.marks);

        students[studentCount++] = newStudent;
        printf("Student added successfully!\n");
    }
    else{
        printf("Student record limit reached!\n");
    }
}

void viewStudents(){
    if(studentCount == 0){
        printf("No student records available.\n");
    }
    else{
        printf("Student Records\n");
        for(int i=0; i<studentCount; i++){
            printf("Roll No: %d, Name: %s, Marks: %.2f\n", students[i].rollNo, students[i].name, students[i].marks);
        }
    }
}

void deleteStudent(){
    if(studentCount == 0){
        printf("No student records available to delete.\n");
    }
    else{
        int rollNo;
        printf("Enter Roll Number of the student to delete: ");
        scanf("%d", &rollNo);

        int found = 0;
        for(int i=0; i<studentCount; i++){
            if(students[i].rollNo == rollNo){
                for(int j=i; j<studentCount-1; j++){
                    students[j] = students[j+1];
                }
                studentCount--;
                found = 1;
                printf("Student deleted successfully!\n");
                break;
            }
        }
        if(!found){
            printf("Student with Roll Number %d not found.\n", rollNo);
        }
    }
}

int main(){
    int choice;
    while(1){
        printf("\nStudent Record System\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Delete Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                exit(0);
                break;
            default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}