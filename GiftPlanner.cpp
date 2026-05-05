#include "GiftPlanner.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Constructor starts the budget at 0
GiftPlanner::GiftPlanner() {
    budget = 0;
}

// Sets the user's holiday budget
void GiftPlanner::setBudget(double amount) {
    budget = amount;
    cout << "Budget set.\n";
}

// Adds a recipient to the planner
void GiftPlanner::addRecipient(string name, string relationship) {
    planner[name].relationship = relationship;
    cout << "Recipient added.\n";
}

// Adds a gift to a specific recipient
void GiftPlanner::addGift(string name, string description, double price) {
    if (planner.find(name) == planner.end()) {
        cout << "Recipient not found. Add them first.\n";
        return;
    }

    Gift newGift;
    newGift.description = description;
    newGift.price = price;
    newGift.purchased = false;

    planner[name].gifts.push_back(newGift);

    cout << "Gift added.\n";
}

// Displays all recipients and their gifts
void GiftPlanner::viewPlanner() {
    if (planner.empty()) {
        cout << "No recipients have been added yet.\n";
        return;
    }

    cout << "\n--- Holiday Gift Planner ---\n";

    for (auto &person : planner) {
        cout << "\n" << person.first << " (" << person.second.relationship << ")\n";

        if (person.second.gifts.empty()) {
            cout << "  No gifts added.\n";
        }

        for (int i = 0; i < person.second.gifts.size(); i++) {
            Gift gift = person.second.gifts[i];

            cout << "  " << i + 1 << ". " << gift.description
                 << " - $" << fixed << setprecision(2) << gift.price
                 << " - " << (gift.purchased ? "Purchased" : "Planned") << "\n";
        }
    }
}

// Marks a selected gift as purchased
void GiftPlanner::markGiftPurchased(string name, int giftNumber) {
    if (planner.find(name) == planner.end()) {
        cout << "Recipient not found.\n";
        return;
    }

    if (giftNumber < 1 || giftNumber > planner[name].gifts.size()) {
        cout << "Invalid gift number.\n";
        return;
    }

    planner[name].gifts[giftNumber - 1].purchased = true;

    cout << "Gift marked as purchased.\n";
}

// Calculates and displays budget information
void GiftPlanner::viewBudgetSummary() {
    double plannedTotal = 0;
    double purchasedTotal = 0;

    // Traverses the hash table and each gift vector
    for (auto &person : planner) {
        for (Gift gift : person.second.gifts) {
            plannedTotal += gift.price;

            if (gift.purchased) {
                purchasedTotal += gift.price;
            }
        }
    }

    cout << fixed << setprecision(2);
    cout << "\n--- Budget Summary ---\n";
    cout << "Budget: $" << budget << "\n";
    cout << "Total planned spending: $" << plannedTotal << "\n";
    cout << "Total purchased spending: $" << purchasedTotal << "\n";
    cout << "Remaining budget after planned gifts: $" << budget - plannedTotal << "\n";

    if (plannedTotal > budget) {
        cout << "Warning! You are over budget.\n";
    }
}

// Saves planner data to a text file
void GiftPlanner::saveToFile() {
    ofstream file("gift_planner.txt");

    if (!file) {
        cout << "Error saving file.\n";
        return;
    }

    file << budget << "\n";

    for (auto &person : planner) {
        file << person.first << "\n";
        file << person.second.relationship << "\n";
        file << person.second.gifts.size() << "\n";

        for (Gift gift : person.second.gifts) {
            file << gift.description << "\n";
            file << gift.price << "\n";
            file << gift.purchased << "\n";
        }
    }

    file << "END\n";
    file.close();

    cout << "Planner saved to gift_planner.txt.\n";
}

// Loads planner data from a text file
void GiftPlanner::loadFromFile() {
    ifstream file("gift_planner.txt");

    if (!file) {
        cout << "No saved file found.\n";
        return;
    }

    planner.clear();

    file >> budget;
    file.ignore();

    string name;

    while (getline(file, name) && name != "END") {
        Recipient recipient;
        int giftCount;

        getline(file, recipient.relationship);

        file >> giftCount;
        file.ignore();

        for (int i = 0; i < giftCount; i++) {
            Gift gift;

            getline(file, gift.description);
            file >> gift.price;
            file >> gift.purchased;
            file.ignore();

            recipient.gifts.push_back(gift);
        }

        planner[name] = recipient;
    }

    file.close();

    cout << "Planner loaded from gift_planner.txt.\n";
}