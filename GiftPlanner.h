#ifndef GIFTPLANNER_H
#define GIFTPLANNER_H

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// Stores one gift idea
struct Gift {
    string description;
    double price;
    bool purchased;
};

// Stores one person and their list of gifts
struct Recipient {
    string relationship;
    vector<Gift> gifts;
};

// Main class that manages the gift planner
class GiftPlanner {
private:
    unordered_map<string, Recipient> planner; // hash table: name -> recipient
    double budget;

public:
    GiftPlanner();

    void setBudget(double amount);
    void addRecipient(string name, string relationship);
    void addGift(string name, string description, double price);
    void viewPlanner();
    void markGiftPurchased(string name, int giftNumber);
    void viewBudgetSummary();
    void saveToFile();
    void loadFromFile();
};

#endif