#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_STUDENTS 20

typedef struct {
   uint8_t grade;
   char name[MAX_NAME_LENGTH];
} student_t;

typedef struct {
   size_t count;
   student_t students[MAX_STUDENTS];
} roster_t;

size_t init_roster(roster_t *roster)
{
    roster->count = 0;
    return roster->count;
}

int sort(roster_t *roster)
{
    if (roster->count == 1)
        return 0;

    // Sort by grade
    for (size_t i = 0; i < roster->count; i++) {
        for (size_t j = 0; j < roster->count - i - 1; j++) {
            if (roster->students[j].name[0] > roster->students[j+1].name[0]) {
                student_t temp = roster->students[j];
                roster->students[j] = roster->students[j + 1];
                roster->students[j + 1] = temp;
            }

            if (roster->students[j].grade > roster->students[j+1].grade) {
                student_t temp = roster->students[j];
                roster->students[j] = roster->students[j + 1];
                roster->students[j + 1] = temp;
                continue;
            }
        }
    }
}

roster_t get_grade(roster_t *roster, uint8_t desired_grade) 
{
    roster_t new_roster;
    for (size_t i = 0; i < roster->count; i++) {
        if (roster->students[i].grade == desired_grade) {
            new_roster.students[new_roster.count] = roster->students[i];
            new_roster.count++;
        }
    }
    return new_roster;
}

int add_student(roster_t *roster, char name[], int grade)
{
    for (int i = 0; i < roster->count; i++) {
        if (strcmp(roster->students[i].name, name) == 0)
            return 0;
    }
    roster->count++;
    student_t student;
    strcpy(student.name, name);
    student.grade = grade;
    roster->students[roster->count-1] = student;

    sort(roster);

    return 1;
}

int main()
{
   roster_t actual;

   init_roster(&actual);
   /* printf("%d\n", actual.count); */
   add_student(&actual, "Peter", 2);
   add_student(&actual, "Zoe", 1);
   add_student(&actual, "Alex", 1);
   add_student(&actual, "Jim", 2);

   for (size_t i = 0; i < actual.count; i++) {
       printf("%d - %s with %d\n", i+1, actual.students[i].name, actual.students[i].grade);
   }

   roster_t new_actual = get_grade(&actual, 1);
   printf("\nGrade: %d\n", new_actual.count);

   for (size_t i = 0; i < new_actual.count; i++) {
       printf("%d - %s with %d\n", i+1, new_actual.students[i].name, new_actual.students[i].grade);
   }
}
