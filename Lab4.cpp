
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
	
	/*Polygon triangle(6);
	triangle.Readall();
	triangle.Display();*/
	
	Teacher j(2, "John", "DER");
	Course k(45, "math");
	j.AddCourse(&k);
	
	
	
	return 0;
}