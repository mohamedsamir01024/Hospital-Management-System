#include<iostream>
#include"Hospital.h"
#include"Appointment.h"
using namespace std;
int main()
{
	//"C:/Users/maria/OneDrive/Desktop/OOP/HospitalSystem/Database.db"
	const char* dataBasePath = "C:\\Users\\maria\\OneDrive\\Desktop\\OOP\\HospitalSystem\\Database.db";
	Hospital h(dataBasePath);
	Appointment ap;
	h.createTables(dataBasePath);
	
	int choose;
	do
	{
		cout << "\n********************************************";
		cout << "\n Hospital Management System";
		cout << "\n1) Add a Patient or Doctor";
		cout << "\n2)Book An Appointment";
		cout << "\n3)View Appointment Details";
		cout << "\n4)Exit";
		cout << "\n**********************************************";
		cout << "\nEnter your choice:";
		cin >> choose;
	switch (choose)
	{case 1:
		h.add();
		break;
	case 2:
		ap.Booking();
		break;
	case 3:
		ap.view();
		break;
	case 4:
		break;
	default:
		cout << "Invalid choice ";
		break;
	}
	} while (choose!=5);
}