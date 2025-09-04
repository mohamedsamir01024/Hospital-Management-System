🏥 Hospital Management System
📌 Project Overview

This project is a Hospital Management System built with C++ and integrated with a SQLite database.
The system is designed to handle core hospital operations, ensuring efficient management of:

👨‍⚕️ Patients

🩺 Doctors

📅 Appointments

💊 Treatments & Medications

Our goal was to design and implement a complete system that connects a C++ application with a relational database backend to provide reliable data storage, retrieval, and management.

⚙️ Features

✅ Patient Management – Add, update, search, and delete patient records.

✅ Doctor Management – Store and manage doctor information.

✅ Appointment Scheduling – Assign doctors to patients and schedule visits.

✅ Treatment Records – Track diagnosis, prescriptions, and medications.

✅ Database Integration – Persistent storage with SQLite.

✅ Search & Reports – Query data efficiently for decision-making.

🛠️ Tech Stack

C++ (core programming language)

SQLite (database for persistent storage)

SQL (queries for CRUD operations)

📂 Project Structure
📦 Hospital-System
 ┣ 📜 main.cpp             # Entry point of the system
 ┣ 📜 patient.cpp/h        # Patient-related functions and classes
 ┣ 📜 doctor.cpp/h         # Doctor-related functions and classes
 ┣ 📜 appointment.cpp/h    # Appointment management
 ┣ 📜 database.cpp/h       # SQLite database connection and queries
 ┣ 📜 hospital.db          # SQLite database file
 ┣ 📜 README.md            # Project documentation
 ┗ 📂 assets               # (Optional) ER diagrams, docs, etc.

🚀 How to Run

Clone the repository:

git clone https://github.com/your-username/Hospital-System.git
cd Hospital-System


Make sure you have SQLite3 installed.
On Linux:

sudo apt-get install sqlite3 libsqlite3-dev


On Windows: Install SQLite from the official site.

Compile the project:

g++ main.cpp patient.cpp doctor.cpp appointment.cpp database.cpp -o hospital -lsqlite3


Run the program:

./hospital

🗄️ Database Design

The system is backed by an SQLite relational database with the following tables:

Patients – Stores patient details (ID, name, age, contact, medical history).

Doctors – Stores doctor details (ID, name, specialty, availability).

Appointments – Links patients and doctors with date/time info.

Treatments – Stores diagnosis, medications, and treatment history.

🎓 Academic Context

This project was developed as part of the Database & Systems Programming coursework, with objectives:

To integrate C++ applications with a database backend.

To design and implement a relational schema.

To provide a simulation of real-world hospital management software.
