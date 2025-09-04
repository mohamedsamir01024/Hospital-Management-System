#pragma once
#include <string>
#include <sqlite3.h>
#include"Appointment.h"

using namespace std;

class Hospital:public Appointment{
private:
    string drName;
    string specialization;
    int drID;
    

public:
        
    Hospital(){
    }
    Hospital(const char* path);  // Constructor
    void setDrName(string Dn);
    void setDrSpec(string Ds);
    void setDrId(int Di);

    string getDrName();
    string getDrSpec();
    int getDrId();
    int createDB(const char* s);
    int createTables(const char* s);  // Function to create database tables
    void add(); 
   

int insertDB(const char *s);  // Declare insertDB function here
    ~Hospital();  // Destructor
};

// Function declarations outside the class


