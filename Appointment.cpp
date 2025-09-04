#include "Appointment.h"
#include<iostream>
using namespace std;
Appointment::Appointment(){

}
void Appointment::setAge(int a)
{
	patientAge = a;
}
int Appointment::getAge()
{
	return patientAge;
}
void Appointment::setID(int id) {
	PatientID = id;
}
void Appointment::setName(string Name) {
	Patientname = Name;
	
}
void Appointment::setCondition(string Condition) {
	
	Patientcondition = Condition;
}
int Appointment::getID() {
	return PatientID;
}
string Appointment::getName() {
	return Patientname;
}
string Appointment::getCondition() {
	return Patientcondition;
}

void Appointment::Booking() {
	string n1, c1;
	int i1;
	
	cout << "Enter the Patient name: ";
	cin >> n1;
	setName(n1);
	cout << "Enter the Patient ID: ";
	cin >> i1;
	setID(i1);
	
	cout << "Enter the Patient condition: ";
	cin >> c1;
	setCondition(c1);
}
void Appointment::view() {

	if (getName().empty() && getID() == 0 && getAge() == 0 && getCondition().empty()) {
		cout << "*******************************************\n";
		cout << "Appointments\n";
		cout << "*******************************************\n";
		cout << "No appointments have been booked." << endl;
	}
	else {
		
		cout << "*******************************************\n";
		cout << "Appointments\n";
		cout << "*******************************************\n";
		cout << "Patient Name: " << getName() << "\t"
			<< "Patient ID: " << getID() << "\t"
			<< "Patient Age: " << getAge() << "\t"
			<< "The department for the appointment: " << getCondition() << endl;
	}
}
