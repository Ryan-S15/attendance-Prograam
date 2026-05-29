#include <iostream>
#include <string>
#include <fstream>
#include <vector> 
using namespace std;

int main() {

    // List of all student names
    vector<string> names = {
        "Envy Brown",
        "Ilyas Devaux",
        "Damon Diulio",
        "Hamir Griffith",
        "Anthony Landritsi",
        "Bode Lentz",
        "George Louglos",
        "Jordan Mckenzie",
        "Christopher Richter",
        "Caleb Roswell",
        "Seth Scott",
        "Tiahna Spencer",
        "Bailin Stokes",
        "Elijah Verdaguer",
        "Connor Wentworth"
    };

    // Stores attendance results
    vector<string> attendance;

    // Variables
    string date;
    int fail;
    int attendances;

    // Ask user for the date
    cout << "Enter date as month-day-year\n";
    cin >> date;

    // Create text file using the date
    ofstream MyFile(date + ".txt");

    // Go through every student in the list
    for (int x = 0; x < names.size(); x++) {

        do {

            // Reset fail value
            fail = 0;

            // Ask if the student is present
            cout << "Is " << names[x] << " present? yes(1) no(2)\n";
            cin >> attendances;

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

            // If user enters wrong number
            else {

                // Error message
                cout << "Invalid input, try again\n";

                // Makes loop repeat
                fail++;
            }

        } while (fail == 1); // Repeat if input was invalid
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
