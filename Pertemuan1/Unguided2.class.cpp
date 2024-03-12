#include <iostream>
#include <string>

using namespace std;

class Student_135 {
private:
    string name_135;
    int age_135;
    string major_135;

public:
    // Constructor
    Student_135(string n_135, int a_135, string m_135) {
        name_135 = n_135;
        age_135 = a_135;
        major_135 = m_135;
    }

    // Member function to display student information
    void displayInfo() {
        cout << "Name: " << name_135 << endl;
        cout << "Age: " << age_135 << endl;
        cout << "Major: " << major_135 << endl;
    }
};

int main() {
    // Create an object of class Student
    Student_135 student1_135("Amelia Azmi", 19, "Teknik Informatika");

    // Display student information
    student1_135.displayInfo();

    return 0;
}

