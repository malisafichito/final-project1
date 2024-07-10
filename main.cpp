#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// Class definitions

class Student {
public:
    string firstname;
    string surname;
    string gender;
    int age;
    int group;
    vector<string> sports;
    vector<string> clubs;

    // Constructor
    Student(string fn, string sn, string g, int a, int grp)
        : firstname(fn), surname(sn), gender(g), age(a), group(grp) {}
};

class Activity {
public:
    string name;
    int max_capacity;
    vector<Student> students;

    // Constructor
    Activity(string n, int cap) : name(n), max_capacity(cap) {}

    // Method to add a student to the activity if capacity allows
    bool addStudent(const Student& student) {
        if (students.size() < max_capacity) {
            students.push_back(student);
            return true;
        }
        return false;
    }

    // Method to get the remaining capacity of the activity
    int getRemainingCapacity() const {
        return max_capacity - students.size();
    }
};

// Global lists of students, sports, and clubs
vector<Student> students;
vector<Activity> sports;
vector<Activity> clubs;

// Function to initialize predefined activities
void initializeActivities() {
    // Initialize sports
    sports.emplace_back("Rugby", 20);
    sports.emplace_back("Athletics", 20);
    sports.emplace_back("Swimming", 20);
    sports.emplace_back("Soccer", 20);

    // Initialize clubs
    clubs.emplace_back("Journalism", 60);
    clubs.emplace_back("Red Cross Society", 60);
    clubs.emplace_back("AISEC", 60);
    clubs.emplace_back("Business", 60);
    clubs.emplace_back("Computer Science", 60);
}