// COMSC-210 | Lab 23 | Dan Pokhrel
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], int age, string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    list<Goat> trip;

    bool quit = false;
    while (!quit){ // Loops until the user enters 4 to quit
        int choice = main_menu();

        switch (choice){
        case 1:
            add_goat(trip, &names[rand() % SZ_NAMES], rand() % (MAX_AGE+1), &colors[rand() % SZ_COLORS]);
            break;
        case 2:
            delete_goat(trip);
            break;
        case 3:
            break;
        case 4:
            break;
        }
    }


    return 0;
}

int main_menu(){
    cout << "\n*** GOAT MANAGER 3001 ***\n";
    cout << "[1] Add a goat\n";
    cout << "[2] Delete a goat\n";
    cout << "[3] List goats\n";
    cout << "[4] Quit\n";
    cout << "Choice --> ";
    int choice;
    cin >> choice;

    // Input Validation
    if (choice < 1 || choice > 4){ // Out of bounds
        cout << "Invalid Input. Please Try Again.\n";
        return main_menu();
    }

    return choice;
}