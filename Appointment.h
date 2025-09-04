#pragma once
#include<iostream>
using namespace std;
class Appointment
{
protected:
	int PatientID,patientAge;
	string Patientname, Patientcondition;
public:
	Appointment();
	void setAge(int a);
	void setID(int);
	void setName(string);
	void setCondition(string);
	int getID();
	string getName();
	string getCondition();
	int getAge();
	void Booking();
	void view();
};

