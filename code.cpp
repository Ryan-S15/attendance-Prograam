#include <iostream>
#include <string>
#include <fstream>
#include <vector> 
using namespace std;

int main() {

    // List of all student names
    vector<string> names = {
        "Envy",
        "Ilyas",
        "Damon",
        "Hamir",
        "Anthony",
        "Bode",
        "George",
        "Jordan",
        "Christopher",
        "Caleb",
        "Seth",
        "Tiahna",
        "Bailin",
        "Elijah",
        "Connor"
    };

    // Stores attendance results
    vector<string> attendance;

    // Variables
    string date;
    string input;
    int attendances;
    bool validDate;

    // Ask user for the date
    do {
        validDate = true;
        cout << "Enter date as month-day-year\n";
        cin >> date;

        // Check if date contains slashes
        for (char c : date) {
            if (c == '/') {
                cout << "Invalid input, slashes are not allowed. Use hyphens instead.\n";
                validDate = false;
                break;
            }
        }
    } while (!validDate);

    // Create text file using the date
    ofstream MyFile(date + ".txt");

    // Go through every student in the list
    for (int x = 0; x < names.size(); x++) {

        bool validInput = false;

        while (!validInput) {

            // Ask if the student is present
            cout << "Is " << names[x] << " present? yes(1) no(2)\n";
            cin >> input;

            // Check if input is exactly "1" or "2"
            if (input == "1" || input == "2") {
                attendances = stoi(input);
                validInput = true;

                // If student is present
                if (attendances == 1) {

                    // Write to file
                    MyFile << names[x] << ", attendance: present\n";

                    // Save attendance in vector
                    attendance.push_back(", attendance: present\n");
                }

                // If student is absent
                else if (attendances == 2) {

                    // Write to file
                    MyFile << names[x] << ", attendance: absent\n";

                    // Save attendance in vector
                    attendance.push_back(", attendance: absent\n");
                }
            }

            // If user enters wrong input
            else {
                cout << "Invalid input, try again\n";
            }
        }
    }

    // Print blank line
    cout << endl;

    // Display all attendance results
    for (int x = 0; x < names.size(); x++) {

        // Print student name and attendance
        cout << names[x] << attendance[x];
    }

    // Close the file
    MyFile.close();

    return 0;
}
