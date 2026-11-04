#include <iostream>
#include "HeadeLab4r.h"
Point::Point(double _x , double _y) : x(_x), y(_y) {};
void Point::Display() const{
	std::cout << "(" << x << "," << y << ")";
};
double Point::getX()const {
	return x;
}
double Point::getY() const {
	return y;
}
void Point::setX(double x) {
	this->x=x;
}
void Point::setY(double y)  {
	this->y = y;
}
Line::Line(double x1, double y1, double x2, double y2) : a(x1, y1),b(x2,y2){};
Line::Line():a(0,0) , b(0,0){};
void Line::Display() const {
	std::cout << " Start ";
	a.Display();
	std::cout << "\tEnd ";

	b.Display();
};
bool Line::Isvertical()const {
	return(a.getX() == b.getX());

}
bool Line::Ishorizontal()const {
	
	return(a.getY() == b.getY());


}
bool Line::getslope(double& slope) const {
	if (!Isvertical()) {

	slope = (a.getY() - b.getY()) / (a.getX() - b.getX());
	return true;
	}
	return false;
};
Point Line::getStart()const {
	return a;
}
Point Line::getEnd()const {
	return b;
}
void Line:: setStart(double x, double y) {
	a.setX(x);
	a.setY(y);
}
void Line::setEnd(double x, double y) {
	b.setX(x);
	b.setY(y);

};
void Line::setStart(Point p) {
	a.setX(p.getX());
	a.setY(p.getY());
}
void Line::setEnd(Point p) {
	b.setX(p.getX());
	b.setY(p.getY());

};
	
Polygon::Polygon(int _n) {
	n = (_n < 3) ? 3 : _n;
	p = new Line[n];
}

Polygon:: ~Polygon() {
	delete[] p;
	p = nullptr;
};
void Polygon:: Readall() {
		double x, y;
		std::cout << " Point #1 : ";
		std::cin >> x;
		std::cin >> y;
		p[0].setStart(x, y);
		for (int i = 1; i < n; i++) {
			std::cout << " Point #"<<i+1<<" : ";
			std::cin >> x;
			std::cin >> y;
			p[i-1].setEnd(x, y);
			p[i].setStart(x, y);
		}
		p[n-1].setEnd(p[0].getStart());
};
void Polygon::Display() const {
	for (int i = 0; i < n; i++) {
		std::cout << " Line #" << i + 1 << " : ";
		p[i].Display();
		std::cout << std::endl;
		
}

};

Course::Course(int a=0, std::string b=" ") : code(a),title(b) {}
void Course::setCode(int c) { code = c; }
void Course::setTitle(std::string d) { title = d; }
int Course::getCode() const { return code; }
std::string Course::getTitle() const{ return title; }
void Course::AddTeacher(Teacher* tp) {
	if (tptr == nullptr && tp != nullptr && !(tp->getCourse())) {
		tptr = tp;
		tptr->AddCourse(this);
	}
	else if (tptr != nullptr) std::cout << "Only One Teacher Per Course" << std::endl;
	else if ((tp->getCourse()))std::cout << "Course already Have a Teacher"<<std::endl;
	else std::cout << "No Teacher Detected" << std::endl;

};
void Course::DropTeacher() {
	if (tptr) {
		tptr->DropCourse();
		tptr = nullptr;
	}
};
Teacher* Course::getTeacher() const { return tptr; }

void Course::PrintInfo()const {
	std::cout << "Course Title : " << title << std::endl;
	std::cout << "Course Code : " << code << std::endl;

};

Teacher::Teacher(int a = 0, std::string b = " ", std::string f = " ") : 
	ID(a), Name(b),LastCertificate(f),cptr(nullptr) {}
void Teacher::setID(int c) { ID = c; }
void Teacher::setName(std::string d) { Name = d; }
void Teacher::setLastCertificate(std::string d) { LastCertificate = d; }
int Teacher::getID() const { return ID; }
std::string Teacher::getName() const { return Name; }
std::string Teacher::getLastCertificate() const { return LastCertificate; }
void Teacher::AddCourse(Course* cp) {
	if (cptr == nullptr && cp != nullptr && !(cp->getTeacher())) {
		cptr = cp;
		cptr->AddTeacher(this);
	}
	else if (cptr != nullptr) std::cout << "Only One Course Per Teacher" << std::endl;
	else std::cout << "No Course Detected" << std::endl;

};
void Teacher::DropCourse() {
	if (cptr) {
		cptr->DropTeacher();
		cptr = nullptr;
	}
};
Course* Teacher::getCourse() const { return cptr; }
void Teacher::PrintInfo()const {
	std::cout << "Teacher's Name : " << Name << std::endl;
	std::cout << "Teacher's ID : " << ID << std::endl;
	std::cout << "Teacher's LastCertificate : " << LastCertificate << std::endl;
	if (cptr)std::cout << "Teaches Course : " << cptr->getTitle();
};

