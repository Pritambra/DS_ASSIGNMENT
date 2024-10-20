#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10
#define NAME_LENGTH 50


struct Student {
    int rollno;
    char name[NAME_LENGTH];
    float marks;
};


void sortStudents(struct Student students[], int n) {
    struct Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) { // Sort in descending order
               
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct Student students[MAX_STUDENTS] = {
        {1, "A", 85},
        {2, "B", 78},
        {3, "C", 92},
        {4, "D", 65},
        {5, "E", 88},
        {6, "F", 72},
        {7, "G", 95},
        {8, "H", 80},
        {9, "I", 90},
        {10, "J", 70}
    };

    
    sortStudents(students, MAX_STUDENTS);

    
    printf("Sorted Students by Marks:\n");
    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", 
                students[i].rollno, students[i].name, students[i].marks);
    }

    return 0;
}
