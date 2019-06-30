#include <iostream>
#include "person.h"
#include "student.h"

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

    return 0;
}