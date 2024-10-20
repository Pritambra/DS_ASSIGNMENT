#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10
#define NAME_LENGTH 50


struct Student {
    int rollno;
    char name[NAME_LENGTH];
    float marks;
};


void selectionSort(struct Student students[], int n, int *passes, int *comparisons);
void bubbleSort(struct Student students[], int n, int *passes, int *comparisons);
void insertionSort(struct Student students[], int n, int *passes, int *comparisons);

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

   
    int passes = 0, comparisons = 0;

 
    struct Student studentsForSelection[MAX_STUDENTS];
    memcpy(studentsForSelection, students, sizeof(students));
    selectionSort(studentsForSelection, MAX_STUDENTS, &passes, &comparisons);
    printf("Selection Sort - Passes: %d, Comparisons: %d\n", passes, comparisons);

   
    passes = 0; comparisons = 0;
    struct Student studentsForBubble[MAX_STUDENTS];
    memcpy(studentsForBubble, students, sizeof(students));
    bubbleSort(studentsForBubble, MAX_STUDENTS, &passes, &comparisons);
    printf("Bubble Sort - Passes: %d, Comparisons: %d\n", passes, comparisons);

  
    passes = 0; comparisons = 0;
    struct Student studentsForInsertion[MAX_STUDENTS];
    memcpy(studentsForInsertion, students, sizeof(students));
    insertionSort(studentsForInsertion, MAX_STUDENTS, &passes, &comparisons);
    printf("Insertion Sort - Passes: %d, Comparisons: %d\n", passes, comparisons);

    return 0;
}


void selectionSort(struct Student students[], int n, int *passes, int *comparisons) {
    for (int i = 0; i < n - 1; i++) {
        (*passes)++;
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            (*comparisons)++;
            if (students[j].marks < students[minIndex].marks) {
                minIndex = j;
            }
        }
      
        if (minIndex != i) {
            struct Student temp = students[i];
            students[i] = students[minIndex];
            students[minIndex] = temp;
        }
    }
}


void bubbleSort(struct Student students[], int n, int *passes, int *comparisons) {
    for (int i = 0; i < n - 1; i++) {
        (*passes)++;
        for (int j = 0; j < n - i - 1; j++) {
            (*comparisons)++;
            if (students[j].marks > students[j + 1].marks) {
                
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}


void insertionSort(struct Student students[], int n, int *passes, int *comparisons) {
    for (int i = 1; i < n; i++) {
        (*passes)++;
        struct Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].marks > key.marks) {
            (*comparisons)++;
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
        
        if (j >= 0) {
            (*comparisons)++;
        }
    }
}
