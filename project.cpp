// Ask if the student wants to participate in sports
    cout << "Do you want to participate in sports? (yes/no): ";
    string participateInSports;
    cin >> participateInSports;

    // If student wants to participate in sports
    if (participateInSports == "yes") {
        // Allow selection of one sport
        while (selectedSports.size() < 1) {
            cout << "Select a sport (Rugby, Athletics, Swimming, Soccer): ";
            string sport;
            cin >> sport;
            bool found = false;
            // Check if the selected sport exists and has remaining capacity
            for (auto& s : sports) {
                if (s.name == sport && s.getRemainingCapacity() > 0) {
                    Student newStudent(firstname, surname, gender, age, group);
                    if (s.addStudent(newStudent)) {
                        selectedSports.push_back(sport);
                        found = true;
                    } else {
                        cout << "Sport is full. Please try again.\n";
                    }
                    break;
                }
            }
            if (!found) {
                cout << "Sport not found or full. Please try again.\n";
            }
        }

        // Allow selection of up to two clubs
        while (selectedClubs.size() < 2) {
            cout << "Select a club (Journalism, Red Cross Society, AISEC, Business, Computer Science): ";
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