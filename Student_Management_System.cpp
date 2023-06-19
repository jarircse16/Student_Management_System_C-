#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <limits>

using namespace std;

class Student {
private:
    string name;
    string roll;
    string department;
    string cgpa;
    string semester;

public:
    Student(const string& name, const string& roll, const string& department, const string& cgpa, const string& semester)
        : name(name), roll(roll), department(department), cgpa(cgpa), semester(semester) {}

    string getName() const {
        return name;
    }

    string getRoll() const {
        return roll;
    }

    string getDepartment() const {
        return department;
    }

    string getCGPA() const {
        return cgpa;
    }

    string getSemester() const {
        return semester;
    }

    void updateFile() const {
        string filePath = name + "_" + roll + ".txt";
        ofstream outputFile(filePath);
        if (outputFile.is_open()) {
            outputFile << "Name: " << name << endl;
            outputFile << "Roll: " << roll << endl;
            outputFile << "Department: " << department << endl;
            outputFile << "CGPA: " << cgpa << endl;
            outputFile << "Semester: " << semester << endl;
            outputFile.close();
        } else {
            cout << "Error opening file: " << filePath << endl;
        }
    }

    void deleteFile() const {
        string filePath = name + "_" + roll + ".txt";
        if (remove(filePath.c_str()) == 0) {
            cout << "Student file deleted: " << filePath << endl;
        } else {
            cout << "Error deleting file: " << filePath << endl;
        }
    }
};

void addStudent() {
    string name, roll, department, cgpa, semester;

    cout << "Enter student name: ";
    getline(cin, name);

    cout << "Enter roll number: ";
    getline(cin, roll);

    cout << "Enter department: ";
    getline(cin, department);

    cout << "Enter CGPA: ";
    getline(cin, cgpa);

    cout << "Enter semester: ";
    getline(cin, semester);

    Student student(name, roll, department, cgpa, semester);
    student.updateFile();

    cout << "Student information added successfully!" << endl;
}

void readStudent() {
    string fileName;
    cout << "Enter the name and roll in the format 'name_roll.txt': ";
    getline(cin, fileName);

    ifstream file(fileName);
    if (file.is_open()) {
        // File exists, read its contents
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "No such student." << endl;
    }
}

void deleteStudent() {
    string fileName;
    cout << "Enter the name and roll in the format 'name_roll.txt': ";
    getline(cin, fileName);

    if (remove(fileName.c_str()) == 0) {
        cout << "Student file deleted successfully." << endl;
    } else {
        cout << "No such student." << endl;
    }
}

void updateStudent() {
    string fileName;
    cout << "Enter the name and roll in the format 'name_roll.txt': ";
    getline(cin, fileName);

    ifstream file(fileName);
    if (file.is_open()) {
        string name, roll, department, cgpa, semester;

        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter roll: ";
        getline(cin, roll);
        cout << "Enter department: ";
        getline(cin, department);
        cout << "Enter CGPA: ";
        getline(cin, cgpa);
        cout << "Enter semester: ";
        getline(cin, semester);

        // Write the updated contents to the file
        ofstream outFile(fileName);
        if (outFile.is_open()) {
            outFile << "Name: " << name << endl;
            outFile << "Roll: " << roll << endl;
            outFile << "Department: " << department << endl;
            outFile << "CGPA: " << cgpa << endl;
            outFile << "Semester: " << semester << endl;
            outFile.close();
            cout << "Student information updated successfully." << endl;
        } else {
            cout << "Error updating student information." << endl;
        }
    } else {
        cout << "No such student." << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "Student Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Read Student" << endl;
        cout << "3. Delete Student" << endl;
        cout << "4. Update Student" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                readStudent();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}
