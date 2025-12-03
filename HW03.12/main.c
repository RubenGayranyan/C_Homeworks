#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char lastname[50];
    int age;
    float grade;
} Student;

void sortByGrade(int size, Student* stud);
void writeCSV(int size, Student* stud);

int main(int argc, char **argv) {
    int size = 0;
    printf("Please, input the number of students: ");
    scanf("%d", &size);
    Student stud[size];
    for(int i = 0; i < size; ++i) {
        char tmp_name[50], tmp_lastname[50];
        int tmp_age = 0;
        float tmp_grade = 0.0;
        printf("Please, input students first name: ");
        scanf("%s", tmp_name);
        printf("Please, input students last name: ");
        scanf("%s", tmp_lastname);
        printf("Please, input students age: ");
        scanf("%d", &tmp_age);
        printf("Please, input students grade: ");
        scanf("%f", &tmp_grade);
       
        strcpy(stud[i].name, tmp_name); 
        strcpy(stud[i].lastname, tmp_lastname);
        stud[i].age = tmp_age;
        stud[i].grade = tmp_grade;
    }
    sortByGrade(size, stud);
    return 0;
}

void sortByGrade(int size, Student* stud) {
    int isSorted;
    do {
        isSorted = 1;
        for (int i = 0; i < size - 1; ++i) {
            if ((stud + i)->grade < (stud + i + 1)->grade) {
                Student tmp = *(stud + i);
                *(stud + i) = *(stud + i + 1);
                *(stud + i + 1) = tmp; 
                isSorted = 0; 
            }
        }
    } while (!isSorted);
    writeCSV(size, stud);
}


void writeCSV(int size, Student* stud) {
    FILE *csv;
    csv = fopen("students.csv", "w+");
    for(int i = 0; i < size; ++i) {
        fprintf(csv, "%s;%s;%d;%.2f\n", stud[i].name, stud[i].lastname, stud[i].age, stud[i].grade);
    }
    fclose(csv);
}

