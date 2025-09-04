#include "Hospital.h"
#include <iostream>
#include <exception>
#include <string>
#include <sqlite3.h>

using namespace std;

Hospital::Hospital(const char* path) {
    // Constructor can be used to initialize the database or open an existing one.
}

void Hospital::setDrName(string Dn) {
    drName = Dn;
}

void Hospital::setDrSpec(string Ds) {
    specialization = Ds;
}

void Hospital::setDrId(int Di) {
    drID = Di;
}

string Hospital::getDrName() {
    return drName;
}

string Hospital::getDrSpec() {
    return specialization;
}

int Hospital::getDrId() {
    return drID;
}



int Hospital::  createDB(const char* s) {
    sqlite3* DB;
    int exit = 0;

    // Open the database
    exit = sqlite3_open(s, &DB);



    // Close the database
    sqlite3_close(DB);
    return 0;
}
int Hospital::createTables(const char* s) {
    sqlite3* DB;
    char* error_message;
    string sql = "CREATE TABLE IF NOT EXISTS DOCTOR("
        "NAME                          TEXT NOT NULL,"
        "ID                            INT NOT NULL,"
        "SPECIALIZATION                TEXT NOT NULL);"
        "CREATE TABLE IF NOT EXISTS PATIENT("
        "NAME                        TEXT NOT NULL,"
        "ID                           INT NOT NULL,"
        "AGE                          INT NOT NULL,"
        "CONDITION                     TEXT NOT NULL);";
    try {
        int exit = 0;
        exit = sqlite3_open(s, &DB);
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &error_message);
        if (exit != SQLITE_OK)
        {
            cerr << "Error in create tables function";
            sqlite3_free(error_message);
        }
        else
            cout << "tables created successfully" << endl;
        sqlite3_close(DB);
    }
    catch (const exception& e) {
        cerr << e.what();
    }
    return 0;

}
int Hospital:: insertDB(const char *s) {
    sqlite3* DB;
    char* error_message;
    string sql_insert = "INSERT INTO DOCTOR (NAME, ID, SPECIALIZATION) VALUES('Dr. John Doe', '190105', 'Cardiologist'); "
        "INSERT INTO DOCTOR (NAME, ID, SPECIALIZATION) VALUES('Dr. Jane Smith', '102', 'Neurologist'); "
        "INSERT INTO DOCTOR (NAME, ID, SPECIALIZATION) VALUES('Dr. James Brown', '103', 'Orthopedic'); "
        "INSERT INTO DOCTOR (NAME, ID, SPECIALIZATION) VALUES('Dr. Patricia Taylor', '104', 'Dermatologist'); "
        "INSERT INTO DOCTOR (NAME, ID, SPECIALIZATION) VALUES('Dr. Robert Johnson', '105', 'Pediatrician'); "
        "INSERT INTO DOCTOR (NAME, ID, SPECIALIZATION) VALUES('Dr. Jennifer Williams', '106', 'Oncologist'); "
        "INSERT INTO DOCTOR (NAME, ID, SPECIALIZATION) VALUES('Dr. Michael Davis', '107', 'General Surgeon'); "
        "INSERT INTO DOCTOR (NAME, ID, SPECIALIZATION) VALUES('Dr. Linda Martinez', '108', 'Rheumatologist'); "
        "INSERT INTO DOCTOR (NAME, ID, SPECIALIZATION) VALUES('Dr. David Lee', '109', 'Urologist'); "
        "INSERT INTO DOCTOR (NAME, ID, SPECIALIZATION) VALUES('Dr. Mary Walker', '110', 'Psychiatrist'); "
        "INSERT INTO DOCTOR (NAME, ID, SPECIALIZATION) VALUES('Dr. William Harris', '111', 'Pathologist'); "
        "INSERT INTO DOCTOR (NAME, ID, SPECIALIZATION) VALUES('Dr. Elizabeth Clark', '112', 'Otorhinolaryngologist'); "
        "INSERT INTO DOCTOR (NAME, ID, SPECIALIZATION) VALUES('Dr. George Lewis', '113', 'Endocrinologist'); "
        "INSERT INTO DOCTOR (NAME, ID, SPECIALIZATION) VALUES('Dr. Barbara Young', '114', 'Anesthesiologist'); "
        "INSERT INTO DOCTOR (NAME, ID, SPECIALIZATION) VALUES('Dr. Thomas King', '115', 'Ophthalmologist'); "
        "INSERT INTO DOCTOR (NAME, ID, SPECIALIZATION) VALUES('Dr. Susan Scott', '116', 'Nephrologist'); "
        "INSERT INTO DOCTOR (NAME, ID, SPECIALIZATION) VALUES('Dr. Charles Allen', '117', 'Gastroenterologist'); "

        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('John Adams', '2001', 32, 'Flu'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Linda White', '2002', 45, 'Diabetes'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Michael Hall', '2003', 27, 'Asthma'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Sarah Allen', '2004', 60, 'Hypertension'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('David Moore', '2005', 33, 'Back Pain'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Jessica Robinson', '2006', 41, 'Arthritis'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Joshua Walker', '2007', 50, 'Heart Disease'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Elizabeth Harris', '2008', 28, 'Fever'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Brian Clark', '2009', 36, 'Cold'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Angela Lewis', '2010', 55, 'Stroke'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Kevin Young', '2011', 62, 'Pneumonia'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Laura King', '2012', 37, 'Anxiety'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Daniel Scott', '2013', 48, 'Cancer'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Amy Davis', '2014', 29, 'Migraine'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Gary Taylor', '2015', 54, 'Gallstones'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Nancy Adams', '2016', 64, 'COPD'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Mark Lewis', '2017', 38, 'Bronchitis'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Olivia Walker', '2018', 47, 'High Cholesterol'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Nathan Moore', '2019', 52, 'Sepsis'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Sophia Hall', '2020', 30, 'Broken Leg'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Henry Robinson', '2021', 40, 'Sleep Apnea'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Megan Brown', '2022', 33, 'Appendicitis'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Ethan Walker', '2023', 56, 'Kidney Stones'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Charlotte Allen', '2024', 41, 'Gastritis'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Samantha Lee', '2025', 24, 'Ear Infection'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Isaac Scott', '2026', 59, 'Alzheimer’s'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Daniel White', '2027', 22, 'Intestinal Issues'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Fiona Johnson', '2028', 43, 'Tonsillitis'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Jack Davis', '2029', 50, 'Depression'); "
        "INSERT INTO PATIENT (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('Martha Brown', '2030', 60, 'Osteoporosis');";
    int exit = sqlite3_open(s, &DB);
    exit = sqlite3_exec(DB, sql_insert.c_str(), NULL, 0, &error_message);
    if (exit != SQLITE_OK)
    {
        cerr << "Error in insert data function" << endl;
        sqlite3_free(error_message);
    }
    else
        cout << "Records inserted successfully!" << endl;
    return 0;
   
}









    

Hospital::~Hospital() {
    // Destructor implementation if necessary
}
/*void Hospital::add() {
    int choice;
    cout << "Are you (1) Patient or (2) Doctor? ";
   /* cin >> choice;

    if (choice == 1) {

        int in, ag;
        string s, con;
        cout << "Enter Patient name: ";
        cin.ignore();
        getline(cin, s);
        setName(s);
        cout << "Enter Patient ID: ";*/
        /* cin >> in;
         setID(in);
         cout << "Enter Patient age: ";
         cin >> ag;
         setAge(ag);
         cout << "Enter Condition: ";
         cin.ignore();  // to clear the newline left in the buffer
         getline(cin, con);
         setCondition(con);*/

         // Construct the SQL query for inserting a patient
        /* string sql_patient_add = "INSERT INTO Patient(NAME, ID, AGE, CONDITION) VALUES('"
             + getName() + "', "
             + to_string(getID()) + ", "
             + to_string(getAge()) + ", '"
             + getCondition() + "');";

         insertDB(sql_patient_add);
     else if (choice == 2) {

         int ind;
         string nam, speci;
         cout << "Enter Doctor Name: ";
         cin.ignore();
         getline(cin, nam);
         setDrName(nam);
         cout << "Enter Doctor ID: ";
         cin >> ind;
         setDrId(ind);
         cout << "Enter Doctor Specialization: ";
         cin.ignore();
         getline(cin, speci);
         setDrSpec(speci);

         // Construct the SQL query for inserting a doctor
         string sql_dr_add = "INSERT INTO Doctor(NAME, ID, SPECIALIZATION) VALUES ('"
             + getDrName() + "', "
             + to_string(getDrId()) + ", '"
             + getDrSpec() + "');";

         insertDB(sql_dr_add);  // Pass the SQL query to insert the data into the database
     }
     else {
         cout << "Invalid choice." << endl;
     }
 }*/