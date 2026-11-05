
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
		int n;
		std::cout << "Enter Number of Teachers : ";
		std::cin >> n;
		Teacher* Teachers = new Teacher[n];
		for (int i = 0; i < n; i++) {
			int id;
			std::string name;
			std::string lastc;
			std::cout << "\nEnter Teacher #" << i + 1 << " ID : ";
			std::cin >> id;
			std::cout << "\nEnter Teacher #" << i + 1 << " Name : ";
			std::cin >> name;
			std::cout << "\nEnter Teacher #" << i + 1 << " Last Certificate : ";
			std::cin >> lastc;
			Teachers[i].setID(id);
			Teachers[i].setLastCertificate(lastc);
			Teachers[i].setName(name);

		}
		int m;
		std::cout << "\nEnter Number of Courses : ";
		std::cin >> m;
		Course* Courses = new Course[m];
		for (int i = 0; i < m; i++) {
			int code;
			std::string title;
			std::string lastc;
			std::cout << "\nEnter Course #" << i + 1 << " Code : ";
			std::cin >> code;
			std::cout << "\nEnter Course #" << i + 1 << " Title : ";
			std::cin >> title;
			Courses[i].setCode(code);
			Courses[i].setTitle(title);

		}
		bool loop = true;
		while (loop) {
			int choice;
			std::cout << "\nWhat Do You Want To Do? [Add Course to Teacher(1) - Drop Course from Teacher(2) - Add Teacher to Course(3) - Drop Teacher from Course (4) - Print Info (5)- Exit(6) ] : ";
			std::cin >> choice;
			switch (choice) {
			case 1: {
				int c;
				int nc;
				std::cout << "\nWhich Course (Code)? ";
				std::cin >> c;
				for (int i = 0; i < m; i++)
				{
					if (Courses[i].getCode() == c) { nc = i; break; }
				}
				std::string name;
				std::cout << "\nWhich Teacher (Name)? ";
				std::cin >> name;
				int nt;
				for (int i = 0; i < n; i++)
				{
					if (Teachers[i].getName() == name) { nt = i; break; }
				}

				Teachers[nt].AddCourse(&Courses[nc]);
				break;
			}
			case 2: {
				std::string name;
				std::cout << "\nWhich Teacher (Name)? ";
				std::cin >> name;
				int nt;
				for (int i = 0; i < n; i++)
				{
					if (Teachers[i].getName() == name) { nt = i; break; }
				}

				Teachers[nt].DropCourse();
				break;
			}
			case 3:
			{
				std::string name;
				std::cout << "\nWhich Teacher (Name)? ";
				std::cin >> name;
				int nt;
				for (int i = 0; i < n; i++)
				{
					if (Teachers[i].getName() == name) { nt = i; break; }
				}

				int c;
				int nc;
				std::cout << "\nWhich Course (Code)? ";
				std::cin >> c;
				for (int i = 0; i < m; i++)
				{
					if (Courses[i].getCode() == c) { nc = i; break; }
				}
				Courses[nc].AddTeacher(&Teachers[nt]);
				break;
			}
			case 4: {

				int c;
				int nc;
				std::cout << "\nWhich Course (Code)? ";
				std::cin >> c;
				for (int i = 0; i < m; i++)
				{
					if (Courses[i].getCode() == c) { nc = i; break; }
				}
				Courses[nc].DropTeacher();
				break;
			}
			case 5: {
				bool ch = true;
				while (ch) {
					char ans;
					std::cout << "\nCourse or Teacher? (C / T)";
					std::cin >> ans;
					if (ans == 'c' || ans == 'C') {
						int c;
						int nc;
						std::cout << "\nWhich Course (Code)? ";
						std::cin >> c;
						for (int i = 0; i < n; i++)
						{
							if (Courses[i].getCode() == c) { nc = i; break; }
						}
						Courses[nc].PrintInfo();
						ch = false;
					}
					else if (ans == 't' || ans == 'T') {

						std::string name;
						std::cout << "\nWhich Teacher (Name)? ";
						std::cin >> name;
						int nt;
						for (int i = 0; i < n; i++)
						{
							if (Teachers[i].getName() == name) { nt = i; break; }
						}
						Teachers[nt].PrintInfo();
						ch = false;


					}
					else std::cout << "\nEnter Either C or T";

				}
				break;
			}
			case 6: {
				loop = false; break;
			}
			default: std::cout << "Enter a Valid Number!";
			}
		}
		return 0;
	}
