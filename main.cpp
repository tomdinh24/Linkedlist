//3/11/2022
//Prompt users to display a list of composers as well as their
//date of death and the users have the option to check
//whether there's a specifc composer on the list,
//they can remove composers from the list,
// and they display the list

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Node.h"
#include "LinkedList.h"
#include "composer.h"

using namespace std;

int main() {
    int size = 0;
    LinkedList<Composer> list;
    Composer comp;
    string name;
    string year;
    int date;
    string option;
    bool exit = true;
    bool answer;

    ifstream inFile;
    inFile.open("Composers.txt");
    if (!inFile) {
        cout << "Cannot open the file";
        return 0;
    }
    else {
        size = comp.numberOfLines(inFile);

    }


    for (int i = 0; i < size; i++) {
        getline(inFile, name, ',');
        getline(inFile, year);
        Composer person(name, year);

        list.insert(person);
    }
    inFile.close();


    while (exit) {
        cout << "Enter 's' to search, 'r' to remove,";
        cout << "'d' to display, or 'e' to exit : ";
        cin >> option;
        cin.ignore();
        if (option == "s" || option == "S") {
            cout << "Enter composer's name: ";
            getline(cin, name);
            cin.ignore();
            Composer n(name, "");

            answer = list.find(n);

            if (answer == true) {
                cout << name << " is in the list!!" << endl;
            }
            else {
                cout << "Error: composer is not in the list!!" << endl;
            }

        }
        else if (option == "r" || option == "R") {
            cout << "Enter composer's name: ";
            getline(cin, name);
            cin.ignore();

            Composer n(name, "");

            if (!list.remove(n)) {
                cout << "Error: composer is not in the list!!" << endl;
            }
            else {
                cout << name << " was successfully removed from the list!!" << endl;
            }

        }
        else if (option == "d" || option == "D") {
            list.printList();
        }
        else if (option == "e" || option == "E") {
            return 0;
        }

    }

}