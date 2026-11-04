#pragma once
#include <iostream>
class Point {
private:
	double x;
	double y;
public:
	Point(double _x, double _y);
	void Display()const;
	double getX()const;
	double getY()const;
	void setX(double );
	void setY(double );
};

class Line {
private:
	Point a;
	Point b;
public:
	Line(double x1, double y1, double x2, double y2);
	Line();
	void Display()const;
	bool Isvertical()const;
	bool Ishorizontal()const;
	bool getslope(double& )const;
	Point  getStart()const;
	Point  getEnd()const;
	void  setStart(double,double);
	void  setEnd(double, double);
	void  setStart(Point);
	void  setEnd(Point);
};
class Polygon {
private:
	int n;
	Line* p;
public:
	Polygon(int _n);
	~Polygon();
	void Readall();
	void Display() const ;

};
class Course {
private:
	int code;
	std::string title;
	Teacher* tptr;
public:
	
	Course(int, std::string);
	void setCode(int );
	void setTitle(std::string);
	void AddTeacher(Teacher*) {};
	void DropTeacher() {};
	int getCode()const;
	std::string getTitle() const;
	Teacher* getTeacher() const;
	void PrintInfo()const;

};
class Teacher {
private:
	int ID;
	std::string Name;
	std::string LastCertificate;
	Course* cptr;
public:
	Teacher(int, std::string, std::string);
	void setID(int);
	void setName(std::string);
	void setLastCertificate(std::string);
	void AddCourse(Course*) {};
	void DropCourse() {};
	Course* getCourse() const;
	int getID()const;
	std::string getName() const;
	std::string getLastCertificate() const;
	void PrintInfo()const;

};
