if (!found) {
                cout << "Club not found or full. Please try again.\n";
            }
        }
    } else {
        // Allow selection of up to three clubs if no sport is selected
        while (selectedClubs.size() < 1 || selectedClubs.size() > 3) {
            cout << "Select up to 3 clubs (Journalism, Red Cross Society, AISEC, Business, Computer Science): ";
            string club;
            cin >> club;
            bool found = false;
            // Check if the selected club exists and has remaining capacity
            for (auto& c : clubs) {
                if (c.name == club && c.getRemainingCapacity() > 0) {
                    Student newStudent(firstname, surname, gender, age, group);
                    if (c.addStudent(newStudent)) {
                        selectedClubs.push_back(club);
                        found = true;
                    } else {
                        cout << "Club is full. Please try again.\n";
                    }
                    break;
                }
            }
            if (!found) {
                cout << "Club not found or full. Please try again.\n";
            }
            if (selectedClubs.size() >= 1 && selectedClubs.size() <= 3) {
                break;
            }
        }
    }

    // Create a new student object and add it to the global students vector
    Student newStudent(firstname, surname, gender, age, group);
    newStudent.sports = selectedSports;
    newStudent.clubs = selectedClubs;
    students.push_back(newStudent);

    cout << "Student added successfully!\n";
}

// Function to view all students and their activities
void viewStudents() {
    for (const auto& student : students) {
        cout << student.firstname << " " << student.surname << " (" << student.gender << ", " << student.age << ", Group " << student.group << ")";
        if (!student.sports.empty()) {
            cout << " - Sports: ";
            for (const auto& sport : student.sports) {
                cout << sport << " ";
            }
        }
        if (!student.clubs.empty()) {
            cout << " - Clubs: ";
            for (const auto& club : student.clubs) {
                cout << club << " ";
            }
        }
        cout <<endl;
}
}
