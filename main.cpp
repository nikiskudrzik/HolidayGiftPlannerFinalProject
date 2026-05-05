#include <iostream>
#include <string>
#include "GiftPlanner.h"
using namespace std;

int main() {
    GiftPlanner planner;
    int choice;

    cout << "Welcome to the Holiday Gift Planner!\n";

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Set budget\n";
        cout << "2. Add recipient\n";
        cout << "3. Add gift\n";
        cout << "4. View planner\n";
        cout << "5. Mark gift as purchased\n";
        cout << "6. View budget summary\n";
        cout << "7. Save planner\n";
        cout << "8. Load planner\n";
        cout << "9. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            double budget;

            cout << "Enter holiday budget: $";
            cin >> budget;
            cin.ignore();

            planner.setBudget(budget);
        }

        else if (choice == 2) {
            string name;
            string relationship;

            cout << "Recipient name: ";
            getline(cin, name);

            cout << "Relationship: ";
            getline(cin, relationship);

            planner.addRecipient(name, relationship);
        }

        else if (choice == 3) {
            string name;
            string description;
            double price;

            cout << "Recipient name: ";
            getline(cin, name);

            cout << "Gift description: ";
            getline(cin, description);

            cout << "Gift price: $";
            cin >> price;
            cin.ignore();

            planner.addGift(name, description, price);
        }

        else if (choice == 4) {
            planner.viewPlanner();
        }

        else if (choice == 5) {
            string name;
            int giftNumber;

            cout << "Recipient name: ";
            getline(cin, name);

            cout << "Gift number to mark purchased: ";
            cin >> giftNumber;
            cin.ignore();

            planner.markGiftPurchased(name, giftNumber);
        }

        else if (choice == 6) {
            planner.viewBudgetSummary();
        }

        else if (choice == 7) {
            planner.saveToFile();
        }

        else if (choice == 8) {
            planner.loadFromFile();
        }

        else if (choice == 9) {
            cout << "Bye Bye!\n";
        }

        else {
            cout << "Invalid option. Try again.\n";
        }

    } while (choice != 9);

    return 0;
}