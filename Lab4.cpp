
#include <iostream>
#include "HeadeLab4r.h"
bool IsParallel(const Line& L1,const  Line& L2) {
	
	if ((L1.Isvertical() && L2.Isvertical()) || (L1.Ishorizontal() && L2.Ishorizontal())) {
		return true;
	}
	double slopeL1;
	double slopeL2;
	if (L1.getslope(slopeL1) == L2.getslope(slopeL2)) {
		return true;
	}
	return false;
}
	int main()
	{
        Teacher t1(1, "Ahmed");
        Teacher t2(2, "Mohamed");
        Teacher t3(3, "Omar");

        Course c1(101, "Physics");
        Course c2(102, "Mathematics");
        Course c3(103, "Programming");

        // Test 1: Assign a course to a teacher
        std::cout << "\n--- Test 1 ---\n";
        t1.AddCourse(&c1);

        // Test 2: Assign a teacher to an occupied course
        std::cout << "\n--- Test 2 ---\n";
        c1.AddTeacher(&t2);

        // Test 3: Assign an occupied teacher to another course
        std::cout << "\n--- Test 3 ---\n";
        t1.AddCourse(&c2);

        // Test 4: Assign an available teacher and course
        std::cout << "\n--- Test 4 ---\n";
        t2.AddCourse(&c2);

        // Test 5: Try assigning nullptr
        std::cout << "\n--- Test 5 ---\n";
        t3.AddCourse(nullptr);

        // Test 6: Remove relationship from Course side
        std::cout << "\n--- Test 6 ---\n";
        c1.DropTeacher();

        // Test 7: Reuse previously occupied teacher
        std::cout << "\n--- Test 7 ---\n";
        t1.AddCourse(&c3);

        // Test 8: Reuse previously occupied course
        std::cout << "\n--- Test 8 ---\n";
        t3.AddCourse(&c1);

        // Test 9: Remove relationship from Teacher side
        std::cout << "\n--- Test 9 ---\n";
        t2.DropCourse();

        // Test 10: Reuse both objects
        std::cout << "\n--- Test 10 ---\n";
        t2.AddCourse(&c2);

		return 0;
	}
