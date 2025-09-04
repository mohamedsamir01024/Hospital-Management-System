#include<iostream>
#include<stdio.h>
#include<sqlite3.h>
using namespace std;

static int createTables(const char* s);
static int createDB(const char* s);
static int insertDB(const char* s);

int main()
{
    // Full path to the database file
    const char* dir = "C:\\Users\\maria\\OneDrive\\Desktop\\OOP\\HospitalSystem\\Database.db";

    createDB(dir);       // Create the database file
    createTables(dir);   // Create the tables inside the database
    insertDB(dir);       // Insert data into the tables
    return 0;
}

// Function to create the database
static int createDB(const char* s)
{
    sqlite3* DB;
    int exit = 0;

    // Open the database
    exit = sqlite3_open(s, &DB);

    if (exit != SQLITE_OK) {
        cerr << "Error in creating the database: " << sqlite3_errmsg(DB) << endl;
    }
    else {
        cout << "Database created successfully!" << endl;
    }

    // Close the database
    sqlite3_close(DB);
    return 0;
}

// Function to create Patient and Doctor tables
static int createTables(const char* s)
{
    sqlite3* DB;
    char* error_message;

    // SQL statements for dropping and creating tables
    string sql =
        "DROP TABLE IF EXISTS Patient;"
        "DROP TABLE IF EXISTS Doctor;"
        "CREATE TABLE Patient ("
        "NAME TEXT NOT NULL, "
        "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
        "AGE INTEGER NOT NULL, "
        "CONDITION TEXT NOT NULL);"

        "CREATE TABLE Doctor ("
        "NAME TEXT NOT NULL, "
        "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
        "SPECIALIZATION TEXT NOT NULL);";

    try {
        int exit = sqlite3_open(s, &DB);  // Open the database
        if (exit != SQLITE_OK) {
            cerr << "Error opening database: " << sqlite3_errmsg(DB) << endl;
            return exit;
        }

        // Execute SQL statements to create the tables
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &error_message);

        if (exit != SQLITE_OK) {
            cerr << "Error in creating tables: " << error_message << endl;
            sqlite3_free(error_message);
        }
        else {
            cout << "Tables created successfully!" << endl;
        }

        sqlite3_close(DB);  // Close the database
    }
    catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}

// Function to insert data into the tables
static int insertDB(const char* s)
{
    sqlite3* DB;
    char* error_message;

    // SQL statements for inserting data into Patient and Doctor tables
    string sql_patient =
        "INSERT INTO Patient(NAME,AGE,CONDITION)VALUES('Alice Johnson',45,'Cardiology');"
        "INSERT INTO Patient(NAME,AGE,CONDITION)VALUES('Michael Brown',38,'Neurology');"
        "INSERT INTO Patient(NAME,AGE,CONDITION)VALUES('Sarah Williams',52,'Orthopedics');"
        "INSERT INTO Patient(NAME,AGE,CONDITION)VALUES('David Miller',41,'General Surgery');"
        "INSERT INTO Patient(NAME,AGE,CONDITION)VALUES('Emma Davis',27,'Pediatrics');"
        "INSERT INTO Patient(NAME,AGE,CONDITION)VALUES('James Wilson',34,'Dermatology');"
        "INSERT INTO Patient(NAME,AGE,CONDITION)VALUES('Olivia Martinez',29,'Gynecology');"
        "INSERT INTO Patient(NAME,AGE,CONDITION)VALUES('Liam Anderson',49,'ENT');"
        "INSERT INTO Patient(NAME,AGE,CONDITION)VALUES('Sophia Taylor',31,'Ophthalmology');"
        "INSERT INTO Patient(NAME,AGE,CONDITION)VALUES('Benjamin Clark',56,'Urology');"
        "INSERT INTO Patient(NAME,AGE,CONDITION)VALUES('Mia Thompson',33,'Cardiology');"
        "INSERT INTO Patient(NAME,AGE,CONDITION)VALUES('Ethan Harris',22,'Neurology');"
        "INSERT INTO Patient(NAME,AGE,CONDITION)VALUES('Ava Scott',37,'Orthopedics');"
        "INSERT INTO Patient(NAME,AGE,CONDITION)VALUES('Alexander Lopez',50,'General Surgery');"
        "INSERT INTO Patient(NAME,AGE,CONDITION)VALUES('Isabella Moore',26,'Pediatrics');"
        "INSERT INTO Patient(NAME,AGE,CONDITION)VALUES('Mason Martin',47,'Dermatology');"
        "INSERT INTO Patient(NAME,AGE,CONDITION)VALUES('Charlotte White',39,'Gynecology');"
        "INSERT INTO Patient(NAME,AGE,CONDITION)VALUES('Henry Garcia',44,'ENT');"
        "INSERT INTO Patient(NAME,AGE,CONDITION)VALUES('Amelia Martinez',30,'Ophthalmology');"
        "INSERT INTO Patient(NAME,AGE,CONDITION)VALUES('Lucas Walker',53,'Urology');";

    string sql_doctor =
        "INSERT INTO Doctor(NAME,SPECIALIZATION)VALUES('Dr. John Smith','Cardiology');"
        "INSERT INTO Doctor(NAME,SPECIALIZATION)VALUES('Dr. Emily White','Neurology');"
        "INSERT INTO Doctor(NAME,SPECIALIZATION)VALUES('Dr. Robert Jones','Orthopedics');"
        "INSERT INTO Doctor(NAME,SPECIALIZATION)VALUES('Dr. Linda Scott','General Surgery');"
        "INSERT INTO Doctor(NAME,SPECIALIZATION)VALUES('Dr. William Lee','Pediatrics');"
        "INSERT INTO Doctor(NAME,SPECIALIZATION)VALUES('Dr. Susan Adams','Dermatology');"
        "INSERT INTO Doctor(NAME,SPECIALIZATION)VALUES('Dr. Kevin Hall','Gynecology');"
        "INSERT INTO Doctor(NAME,SPECIALIZATION)VALUES('Dr. Nancy Young','ENT');"
        "INSERT INTO Doctor(NAME,SPECIALIZATION)VALUES('Dr. Thomas King','Ophthalmology');"
        "INSERT INTO Doctor(NAME,SPECIALIZATION)VALUES('Dr. Laura Green','Urology');"
        "INSERT INTO Doctor(NAME,SPECIALIZATION)VALUES('Dr. Jacob Carter','Cardiology');"
        "INSERT INTO Doctor(NAME,SPECIALIZATION)VALUES('Dr. Hannah Wright','Neurology');"
        "INSERT INTO Doctor(NAME,SPECIALIZATION)VALUES('Dr. Daniel Lewis','Orthopedics');"
        "INSERT INTO Doctor(NAME,SPECIALIZATION)VALUES('Dr. Grace Bennett','General Surgery');"
        "INSERT INTO Doctor(NAME,SPECIALIZATION)VALUES('Dr. Matthew Ward','Pediatrics');"
        "INSERT INTO Doctor(NAME,SPECIALIZATION)VALUES('Dr. Chloe Rivera','Dermatology');"
        "INSERT INTO Doctor(NAME,SPECIALIZATION)VALUES('Dr. Samuel Cooper','Gynecology');"
        "INSERT INTO Doctor(NAME,SPECIALIZATION)VALUES('Dr. Victoria Perez','ENT');"
        "INSERT INTO Doctor(NAME,SPECIALIZATION)VALUES('Dr. Andrew Ramirez','Ophthalmology');"
        "INSERT INTO Doctor(NAME,SPECIALIZATION)VALUES('Dr. Elizabeth Torres','Urology');";

    try {
        int exit = sqlite3_open(s, &DB);  // Open the database
        if (exit != SQLITE_OK) {
            cerr << "Error opening database: " << sqlite3_errmsg(DB) << endl;
            return exit;
        }

        // Execute SQL statements to insert data
        exit = sqlite3_exec(DB, sql_patient.c_str(), NULL, 0, &error_message);
        if (exit != SQLITE_OK) {
            cerr << "Error inserting into Patient table: " << error_message << endl;
            sqlite3_free(error_message);
        }
        else {
            cout << "Patient data inserted successfully!" << endl;
        }

        exit = sqlite3_exec(DB, sql_doctor.c_str(), NULL, 0, &error_message);
        if (exit != SQLITE_OK) {
            cerr << "Error inserting into Doctor table: " << error_message << endl;
            sqlite3_free(error_message);
        }
        else {
            cout << "Doctor data inserted successfully!" << endl;
        }

        sqlite3_close(DB);  // Close the database
    }
    catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
