#include <iostream> // for cout and cin functions
#include <string>   // for string functions
#include <vector>   // for vector functions
#include <fstream>  // for file functions
#include <sstream>  // for string stream functions
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct patient
{
    int id;
    string name;
    string address;
    string phone;
    int age;
};
struct physician
{
    int id;
    string name;
    string specialization;
    string department;
    string phone;
};
// Define a struct to store schedule details
struct Schedule
{
    int id;
    int physicianID;
    string date;
    string time;
    int patientID;
};
// Declare an object of the struct patient
patient newPatient;
// Declare an object of the struct physician
physician newPhysician;
// Declare an object of the struct schedule
Schedule newSchedule;

// Define a method to add a new physician to the file
// نستخدم الدالة لاضافة طبيب جديد الى الملف

void addPhysicianToFile(physician &newPhysician)
{
    ofstream outFile;
    // Open the file in append mode
    outFile.open("physicians.txt", ios::app); // open the file in append mode

    // Check if the file is open
    if (outFile.is_open())
    {
        // write the physician details to the file
        // out file used to write to the file
        outFile << newPhysician.id << endl;
        outFile << newPhysician.name << endl;
        outFile << newPhysician.specialization << endl;
        outFile << newPhysician.department << endl;
        outFile << newPhysician.phone << endl;
        outFile.close();
        cout << "Physician added to the file." << endl;
    }
    else
    {
        cout << "Error: Unable to open file for writing." << endl;
    }
}

// Define a method to add a new patient to the file
void addPatientToFile(patient &newPatient)
{
    ofstream outFile;
    outFile.open("patients.txt", ios::app); // open the file in append mode
    if (outFile.is_open())
    {
        // write the patient details to the file
        outFile << newPatient.id << endl;
        outFile << newPatient.name << endl;
        outFile << newPatient.address << endl;
        outFile << newPatient.phone << endl;
        outFile << newPatient.age << endl;
        outFile.close();
        cout << "Patient added to the file." << endl;
    }
    else
    {
        cout << "Error: Unable to open file for writing." << endl;
    }
}

// Define a method to check if the patient exists in the file

bool isPatientExist(int patientID)
{
    // Declare an object of the class ifstreة
    ifstream inputFile("patients.txt");
    // Check if the file is ope
    if (!inputFile.is_open())
    {
        cout << "Error opening file." << endl;
        return false;
    }

    // Read the file line by line
    
    int id;
    string name;
    string address;
    string phone;
    int age;

    while (inputFile >> id >> name >> address >> phone >> age)
    {
        //  cout << "Found patient with ID: " << id << endl;
        if (id == patientID)
        {
            inputFile.close();
            return true;
        }
    }

    inputFile.close();

    return false;
}

bool isPhysicianExist(int physicianID)
{
    ifstream inputFile("physicians.txt");
    if (!inputFile.is_open())
    {
        cout << "Error opening file." << endl;
        return false;
    }

    int id;
    string name;
    string specialization;
    string department;
    string phone;
  
    while (inputFile >> id >> name >> specialization >> department >> phone)
    {
        if (id == physicianID)
        {
            inputFile.close();
            return true;
        }
    }

    inputFile.close();
    return false;
}

// Define a method to display the list of patients
// نستخدم الدالة لعرض قائمة المرضى
// نستخدم الدالة ifstream لقراءة البيانات من الملف
void displayPatients()
{
    ifstream inputFile("patients.txt");
    int id;
    string name;
    string address;
    string phone;
    int age;

    while (inputFile >> id >> name >> address >> phone >> age)
    {
        // طباعة بيانات المريض
        cout << "Patient ID: " << id << endl;
        cout << "Patient name: " << name << endl;
        cout << "Patient address: " << address << endl;
        cout << "Patient phone: " << phone << endl;
        cout << "Patient age: " << age << endl;
        cout << "-----------------" << endl;
    }

    inputFile.close();
}

// Define a method to display the list of physicians
void displayPhysicians()
{
    ifstream inputFile("physicians.txt");
    int id;
    string name;
    string specialization;
    string department;
    string phone;

    while (inputFile >> id >> name >> specialization >> department >> phone)
    {
        cout << "Physician ID: " << id << endl;
        cout << "Physician name: " << name << endl;
        cout << "Physician specialization: " << specialization << endl;
        cout << "Physician department: " << department << endl;
        cout << "Physician phone: " << phone << endl;
        cout << "-----------------" << endl;
    }

    inputFile.close();
}

// Define a method to edit a patient record

void editPatientRecord(int patientID)
{
    // Check if the patient exists in the file
    if (!isPatientExist(patientID))
    {
        cout << "Patient not found." << endl;
        return;
    }
    // ifstream is used to read data from the file
    ifstream inputFile("patients.txt");
    if (!inputFile.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }

    int id;
    string name;
    string address;
    string phone;
    int age;

    // Create a vector to store the patients
    vector<patient> patients;

    while (inputFile >> id >> name >> address >> phone >> age)
    {
        if (id == patientID)
        {
            cout << "Enter the new name: ";
            cin >> name;
            cout << "Enter the new address: ";
            cin >> address;
            cout << "Enter the new phone: ";
            cin >> phone;
            cout << "Enter the new age: ";
            cin >> age;
        }

        patient p;
        p.id = id;
        p.name = name;
        p.address = address;
        p.phone = phone;
        p.age = age;

        patients.push_back(p);
    }

    inputFile.close();
// نستخدم الدالة ofstream لكتابة البيانات في الملف  
    ofstream outFile("patients.txt");
    if (!outFile.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }

    for (int i = 0; i < patients.size(); i++)
    {
        outFile << patients[i].id << endl;
        outFile << patients[i].name << endl;
        outFile << patients[i].address << endl;
        outFile << patients[i].phone << endl;
        outFile << patients[i].age << endl;
    }

    outFile.close();
}

// Define a method to edit a physician record
void editPhysicianRecord(int physicianID)
{
    // Check if the physician exists in the file
    if (!isPhysicianExist(physicianID))
    {
        cout << "Physician not found." << endl;
        return;
    }

    // ifstream is used to read data from the file


    ifstream inputFile("physicians.txt");
    if (!inputFile.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }

    int id;
    string name;
    string specialization;
    string department;
    string phone;

    vector<physician> physicians;

    while (inputFile >> id >> name >> specialization >> department >> phone)
    {
        if (id == physicianID)
        {
            cout << "Enter the new name: ";
            cin >> name;
            cout << "Enter the new specialization: ";
            cin >> specialization;
            cout << "Enter the new department: ";
            cin >> department;
            cout << "Enter the new phone: ";
            cin >> phone;
        }

        physician p;
        p.id = id;
        p.name = name;
        p.specialization = specialization;
        p.department = department;
        p.phone = phone;

        physicians.push_back(p);
    }

    inputFile.close();

    ofstream outFile("physicians.txt");
    if (!outFile.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }

    for (int i = 0; i < physicians.size(); i++)
    {
        outFile << physicians[i].id << endl;
        outFile << physicians[i].name << endl;
        outFile << physicians[i].specialization << endl;
        outFile << physicians[i].department << endl;
        outFile << physicians[i].phone << endl;
    }

    outFile.close();
}

// Define a method to delete a patient record
void deletePatientRecord(int patientID)
{
    ifstream inputFile("patients.txt");
    if (!inputFile.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }
// to delete a patient record we need to read all the records from the file



    int id;
    string name;
    string address;
    string phone;
    int age;

    vector<patient> patients;

    while (inputFile >> id >> name >> address >> phone >> age)
    {
        if (id != patientID)
        {
            patient p;
            p.id = id;
            p.name = name;
            p.address = address;
            p.phone = phone;
            p.age = age;

            patients.push_back(p);
        }
    }

    inputFile.close();

    ofstream outFile("patients.txt");
    if (!outFile.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }

    for (int i = 0; i < patients.size(); i++)
    {
        outFile << patients[i].id << endl;
        outFile << patients[i].name << endl;
        outFile << patients[i].address << endl;
        outFile << patients[i].phone << endl;
        outFile << patients[i].age << endl;
    }

    outFile.close();
}

// Define a method to display schedule
void displaySchedule()
{
    ifstream inputFile("schedule.txt");
    if (!inputFile.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }

    int id;
    string name;
    string date;
    string time;
    string phone;

    while (inputFile >> id >> name >> date >> time >> phone)
    {
        cout << "Patient ID: " << id << endl;
        cout << "Patient name: " << name << endl;
        cout << "Appointment date: " << date << endl;
        cout << "Appointment time: " << time << endl;
        cout << "Patient phone: " << phone << endl;
        cout << "-----------------" << endl;
    }

    inputFile.close();
}

// Define a method to delete a physician record
void deletePhysicianRecord(int physicianID)
{
    ifstream inputFile("physicians.txt");
    if (!inputFile.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }

    int id;
    string name;
    string specialization;
    string department;
    string phone;

    vector<physician> physicians;

    while (inputFile >> id >> name >> specialization >> department >> phone)
    {
        if (id != physicianID)
        {
            physician p;
            p.id = id;
            p.name = name;
            p.specialization = specialization;
            p.department = department;
            p.phone = phone;

            physicians.push_back(p);
        }
    }

    inputFile.close();

    ofstream outFile("physicians.txt");
    if (!outFile.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }

    for (int i = 0; i < physicians.size(); i++)
    {
        outFile << physicians[i].id << endl;
        outFile << physicians[i].name << endl;
        outFile << physicians[i].specialization << endl;
        outFile << physicians[i].department << endl;
        outFile << physicians[i].phone << endl;
    }

    outFile.close();
}

// Define a method to Add new schedule
void addScheduleToFile(Schedule &newSchedule)
{
    ofstream outFile;
    outFile.open("schedules.txt", ios::app); // open the file in append mode
    if (outFile.is_open())
    {
        // write the schedule details to the file
        outFile << newSchedule.id << endl;
        outFile << newSchedule.physicianID << endl;
        outFile << newSchedule.date << endl;
        outFile << newSchedule.time << endl;
        outFile << newSchedule.patientID << endl;
        outFile.close();
        cout << "Schedule added to the file." << endl;
    }
    else
    {
        cout << "Error: Unable to open file for writing." << endl;
    }
}
string getPhysicianNameById(int id)
{
    ifstream inputFile;
    inputFile.open("physicians.txt", ios::in);

    if (!inputFile.is_open())
    {
        cerr << "Unable to open physicians file.\n";
        return "";
    }

    physician physician;
    while (inputFile >> physician.id >> physician.name >> physician.specialization >> physician.department >> physician.phone)
    {
        if (physician.id == id)
        {
            inputFile.close();
            return physician.name;
        }
    }

    inputFile.close();
    return "";
}

// Define a method to display the list of schedules
void displaySchedulesForPhyscians()
{
    ifstream inputFile("schedules.txt");
    int id;
    int physicianID;
    string date;
    string time;
    int patientID;

    cout << "Enter physician ID: " << endl;
    int phID;
    cin >> phID;

    while (inputFile >> id >> physicianID >> date >> time >> patientID)
    {
        //  search for the physician id and display the physician name ,schedule date ,schedule time ,patient id

        if (phID == physicianID)
        {
            cout << "Physician name: " << getPhysicianNameById(phID) << endl;
            cout << "Physician ID: " << physicianID << endl;
            cout << "Schedule date: " << date << endl;
            cout << "Schedule time: " << time << endl;
            cout << "Patient ID: " << patientID << endl;
            cout << "-----------------" << endl;
        }
        else
        {
            cout << "Physician ID not found" << endl;
        }

        cout << "Schedule ID: " << id << endl;
    }

    inputFile.close();
}

// Define a method to delete a schedule

void deleteSchedule()
{
    int scheduleId;
    cout << "Enter the ID of the schedule to delete: ";
    cin >> scheduleId;

    ifstream inputFile("schedules.txt");
    if (!inputFile)
    {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    // Open a temporary file in write mode
    ofstream tempFile("temp.txt");
    if (!tempFile)
    {
        cout << "Error: Unable to create temporary file." << endl;
        return;
    }

    // Read each record from the original file and write it to the temporary file
    // if it does not match the ID of the record to be deleted
    Schedule record;
    bool found = false;
    while (inputFile >> record.id >> record.physicianID >> record.date >> record.time >> record.patientID)
    {
        if (record.id != scheduleId)
        {
            tempFile << record.id << endl
                     << record.physicianID << endl
                     << record.date << endl
                     << record.time << endl
                     << record.patientID << endl;
        }
        else
        {
            found = true;
        }
    }

    inputFile.close();
    tempFile.close();

    if (found)
    {
        // Delete the original file
        remove("schedules.txt");

        // Rename the temporary file
        rename("temp.txt", "schedules.txt");
        cout << "Schedule deleted successfully." << endl;
    }
    else
    {
        cout << "Error: Schedule not found." << endl;
    }
}

void rescheduleAppointment()
{
    int appointmentId;
    cout << "Enter the ID of the appointment to reschedule: ";
    cin >> appointmentId;

    ifstream inputFile("schedules.txt");
    if (!inputFile)
    {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    // Open a temporary file in write mode
    ofstream tempFile("temp.txt");
    if (!tempFile)
    {
        cout << "Error: Unable to create temporary file." << endl;
        return;
    }

    // Read each record from the original file and update it if necessary
    Schedule record;
    bool found = false;
    while (inputFile >> record.id >> record.physicianID >> record.date >> record.time >> record.patientID)
    {
        if (record.id == appointmentId)
        {
            // Prompt the user for the new appointment details
            cout << "Enter the new appointment date: ";
            cin >> record.date;
            cout << "Enter the new appointment time: ";
            cin >> record.time;
            found = true;
        }
        tempFile << record.id << endl
                 << record.physicianID << endl
                 << record.date << endl
                 << record.time << endl
                 << record.patientID << endl;
    }

    // Close both files
    inputFile.close();
    tempFile.close();

    if (!found)
    {
        cout << "Error: Record not found." << endl;
        return;
    }

    // Delete the original file and rename the temporary file
    remove("schedules.txt");
    rename("temp.txt", "schedules.txt");
    cout << "Record updated successfully." << endl;
}

void enterToContinue()
{
    cout << "\nPress enter to continue...";
    cin.ignore();
    cin.get();
}

int main()
{
    // Display menu
    // Ask user for option and store in variable option
    // Use switch statement to execute code based on option
    // Use do-while loop to repeat menu until user chooses to exit
    int option;
    int appointmentId;
    int patientId;
    int physicianId;

    // cout<< isPatientExist(2);
    displayPatients();

    do
    {
        cout << "=======================" << endl;
        cout << "HOSPITAL MANAGEMENT SYSTEM" << endl;
        cout << "=======================" << endl;
        cout << "1. Add new patient details" << endl;
        cout << "2. Add new physician details" << endl;
        cout << "3. Assign schedule for a patient" << endl;
        cout << "4. Reschedule patient" << endl;
        cout << "5. Cancel schedule" << endl;
        cout << "6. Search for physicians schedule" << endl;
        cout << "7. Show list of patients and their records" << endl;
        cout << "8. Show list of physicians" << endl;
        cout << "9. Update patient " << endl;
        cout << "10. Update physician details" << endl;
        cout << "11. Delete patient record" << endl;
        cout << "12. Delete physician record" << endl;
        cout << "13. Exit" << endl;
        cout << "=======================" << endl;
        cout << "Enter your option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            // prompt the user for the patient's details
            cout << "Enter patient ID: ";
            cin >> newPatient.id;
            cout << "Enter patient name: ";
            cin.ignore();
            getline(cin, newPatient.name);
            cout << "Enter patient address: ";
            getline(cin, newPatient.address);
            cout << "Enter patient phone number: ";
            getline(cin, newPatient.phone);
            cout << "Enter patient age: ";
            cin >> newPatient.age;
            addPatientToFile(newPatient); // add the patient to the file
            enterToContinue();
            break;
        case 2:
            cout << "Enter the physician ID: ";
            cin >> newPhysician.id;
            cout << "Enter the physician name: ";
            cin.ignore();
            getline(cin, newPhysician.name);
            cout << "Enter the physician specialization: ";
            getline(cin, newPhysician.specialization);
            cout << "Enter the physician department: ";
            getline(cin, newPhysician.department);
            cout << "Enter the physician phone number: ";
            getline(cin, newPhysician.phone);
            addPhysicianToFile(newPhysician);
            enterToContinue();
            break;
        case 3:
            // code to assign schedule for a patient
            // نستخدم الدالة addScheduleToFile لاضافة جدول جديد
            cout << "Enter the schedule ID: " << endl;
            cin >> newSchedule.id;

            // print the list of physicians
            cout << "List of physicians: " << endl;
            cout << "==================" << endl;
            displayPhysicians();
            cout << "==================" << endl;
            cout << "Enter the physician ID: " << endl;
            cin >> newSchedule.physicianID;
            if (!isPhysicianExist(newSchedule.physicianID))
            {
                cout << "Physician not found." << endl;
                break;
            }
            cout << "Enter the appointment date (dd/mm/yyyy): " << endl;
            cin.ignore();
            getline(cin, newSchedule.date);
            cout << "Enter the appointment time (hh:mm): " << endl;
            getline(cin, newSchedule.time);
            cout << "Enter the patient ID: " << endl;
            cin >> newSchedule.patientID;
            if (!isPatientExist(newSchedule.patientID))
            {
                cout << "Patient not found." << endl;
                break;
            }
            addScheduleToFile(newSchedule);
            enterToContinue();

            break;
        case 4:
            // code to reschedule patient appointment
            // نستخدم الدالة rescheduleAppointment لتغيير جدول موعد موجود
            rescheduleAppointment();
            enterToContinue();
            break;
        case 5:
            // code to cancel schedule
            deleteSchedule();
            enterToContinue();
            break;
        case 6:
            // code to search for physicians schedule
            displaySchedulesForPhyscians();
            enterToContinue();
            break;
        case 7:
            // code to show list of patients and their records
            displayPatients();
            enterToContinue();
            break;
        case 8:
            // code to show list of physicians
            displayPhysicians();
            enterToContinue();
            break;
        case 9:
            // code to update patient and physician details
            cout << "Enter the patient ID: " << endl;
            cin >> patientId;

            editPatientRecord(patientId);
            enterToContinue();
            break;
        case 10:
            // code to update  physician details
            cout << "Enter the physician ID: " << endl;
            cin >> physicianId;
            editPhysicianRecord(physicianId);
            enterToContinue();
            break;
        case 11:
            // code to delete patient record
            cout << "Enter the patient ID: " << endl;
            cin >> patientId;
            deletePatientRecord(patientId);
            enterToContinue();
            break;
        case 12:
            // code to delete physician record
            cout << "Enter the physician ID: " << endl;
            cin >> physicianId;
            deletePhysicianRecord(physicianId);
            enterToContinue();
            break;
        case 13:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    } while (option != 13);

    return 0;
}
