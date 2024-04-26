#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int ID;
    char department[5];
    int age;
    char gender;
    float cgpa;
    char mobileNumber[11];
};

struct Student students[10000];
int numOfStudents = 0;

void addStudent() {
    struct Student newStudent;
    
    printf("Enter student name: ");
    scanf("%s", newStudent.name);
    printf("Enter student ID: ");
    scanf("%d", &newStudent.ID);
    printf("Enter student department (CSE/BBA/EEE/MSJ/ENGLISH): ");
    scanf("%s", newStudent.department);
    printf("Enter student age: ");
    scanf("%d", &newStudent.age);
    printf("Enter student gender (M/F): ");
    scanf(" %c", &newStudent.gender);
    printf("Enter student CGPA: ");
    scanf("%f", &newStudent.cgpa);
    printf("Enter student mobile number: ");
    scanf("%s", newStudent.mobileNumber);
    
    students[numOfStudents++] = newStudent;
    printf("Student added successfully.\n");
}

void searchStudent() {
    int searchID;
    
    printf("Enter student ID to search: ");
    scanf("%d", &searchID);
    
    for (int i = 0; i < numOfStudents; i++) {
        if (students[i].ID == searchID) {
            printf("Student found:\n");
            printf("Name: %s\nID: %d\nDepartment: %s\nAge: %d\nGender: %c\nCGPA: %.2f\nMobile: %s\n",
                   students[i].name, students[i].ID, students[i].department, students[i].age, students[i].gender,
                   students[i].cgpa, students[i].mobileNumber);
            return;
        }
    }
    
    printf("Student with ID %d not found.\n", searchID);
}

void updateStudent() {
    int updateID;
    char updateMobile[15];
    float newCGPA;
    char newMobile[15];
    int found = 0;
    
    printf("Enter student ID to update: ");
    scanf("%d", &updateID);
    
    for (int i = 0; i < numOfStudents; i++) {
        if (students[i].ID == updateID) {
            printf("Enter new CGPA: ");
            scanf("%f", &newCGPA);
            students[i].cgpa = newCGPA;
            printf("Enter new mobile number: ");
            scanf("%s", newMobile);
            strcpy(students[i].mobileNumber, newMobile);
            printf("Student information updated successfully.\n");
            found = 1;
            break;
        }
    }
    
    if (!found)
        printf("Student with ID %d not found.\n", updateID);
}

void deleteStudent() {
    int deleteID;
    int found = 0;

    printf("Enter student ID to delete: ");
    scanf("%d", &deleteID);

    for (int i = 0; i < numOfStudents; i++) {
        if (students[i].ID == deleteID) {
            for (int j = i; j < numOfStudents - 1; j++) {
                students[j] = students[j + 1];
            }
            numOfStudents--;
            printf("Student with ID %d deleted successfully.\n", deleteID);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student with ID %d not found.\n", deleteID);
}

void displayStudentsBySpecificDepartment(const char* department) {
    printf("List of students in %s department:\n", department);
    int found = 0;
    for (int i = 0; i < numOfStudents; i++) {
        if (strcmp(students[i].department, department) == 0) {
            printf("Name: %s\nID: %d\nAge: %d\nGender: %c\nCGPA: %.2f\nMobile: %s\n\n",
                   students[i].name, students[i].ID, students[i].age, students[i].gender,
                   students[i].cgpa, students[i].mobileNumber);
            found = 1;
        }
    }
    if (!found)
        printf("No students found in %s department.\n", department);
}

void displayStudents() {
    char department[5];
    printf("Enter department (CSE/BBA/EEE/MSJ/ENGLISH): ");
    scanf("%s", department);
    displayStudentsBySpecificDepartment(department);
}


int main() {
    int choice;
    
    do {
        printf("\nStudent Management System\n");
        printf("1. Add student\n");
        printf("2. Search student\n");
        printf("3. Update student information\n");
        printf("4. Delete student\n");
        printf("5. Display students by department\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                searchStudent();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                displayStudents();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 6);
    
    return 0;
}
