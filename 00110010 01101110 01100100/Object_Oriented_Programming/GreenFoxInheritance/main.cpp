#include <iostream>
#include "person.h"
#include "student.h"
#include "mentor.h"

int main() {
    Person person1;
    Person person2("Bence", 21, MALE);

    person2.introduce();
    person2.getGoal();
    person1.introduce();

    Student student1;
    student1.introduce();

    Student student2("Bence", 21, MALE, "MZSG");
    student2.skipDays(2);
    student2.introduce();
    student2.getGoal();

    Mentor mentor1;
    mentor1.introduce();

    Mentor mentor2("Matyi", 29, MALE, INTERMEDIATE);
    mentor2.introduce();
    mentor2.getGoal();

    return 0;
}