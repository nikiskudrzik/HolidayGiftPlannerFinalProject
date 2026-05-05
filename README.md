# Holiday Gift Planner

## Project Overview

The Holiday Gift Planner is a C++ console program that helps users organize holiday gift shopping. The program allows the user to keep track of people they need to buy gifts for, gift ideas for each person, whether each gift has been purchased, and how much money they are planning to spend.

I chose this project because holiday shopping can get stressful and disorganized, especially when buying gifts for multiple people. It is easy to forget gift ideas, lose track of what has already been purchased, or spend more than planned. This program gives the user a simple way to keep everything in one place.

## Problem the Program Solves

The main problem this program solves is gift planning organization. Instead of using paper notes, a phone notes app, or trying to remember everything, the user can enter recipients and gift ideas into the program.

The program helps answer questions like:

- Who do I still need to buy gifts for?
- What gift ideas do I have for each person?
- Which gifts have already been purchased?
- How much money am I planning to spend?
- Am I staying within my holiday budget?

This makes the planning process easier and more organized.

## Main Features

The program includes the following features:

- Set a holiday budget
- Add a recipient
- Add gifts for a recipient
- View all recipients and their gifts
- Mark a gift as purchased
- View a budget summary
- Save planner data to a text file
- Load saved planner data from a text file
- Exit the program when finished

The program runs through a simple text menu, so the user can choose what action they want to perform.

## Files in the Project

This project is split into three files:

- main.cpp
- GiftPlanner.h
- GiftPlanner.cpp

### main.cpp

This file contains the main menu and handles user interaction. It asks the user for input and calls the correct functions based on the menu option they choose.

### GiftPlanner.h

This file contains the struct and class declarations. It defines the Gift struct, the Recipient struct, and the GiftPlanner class.

### GiftPlanner.cpp

This file contains the actual function definitions for the GiftPlanner class. This includes adding recipients, adding gifts, viewing the planner, marking gifts as purchased, calculating budget totals, and saving/loading from a file.

Splitting the program into these files keeps the project more organized than putting everything into one long file.

## Data Structures Used

This project uses two main data structures: an unordered_map and a vector.

### unordered_map

The main data structure is:

unordered_map<string, Recipient> planner;

This works like a hash table. The recipient’s name is used as the key, and the recipient’s information is stored as the value.

I chose this structure because the program often needs to find a recipient by name. Using an unordered_map makes that easier and faster than searching through a regular list one item at a time.

### vector

Each recipient has a vector of gifts:

vector<Gift> gifts;

I chose a vector because each person can have multiple gifts, and the number of gifts can change as the user adds more. A vector is a good choice because it stores a flexible list of items.

## Structs and Class Design

The program uses two structs.

The Gift struct stores the gift description, price, and whether the gift has been purchased.

The Recipient struct stores the recipient’s relationship to the user and a vector of gifts.

The program also uses a class called GiftPlanner. This class manages the main program data and actions. It stores the planner map and budget, and it includes functions for adding, viewing, saving, loading, and calculating totals.

Using a class helps keep related data and functions together.

### Hash Table Lookup

When adding a gift or marking a gift as purchased, the program checks whether the recipient exists in the unordered_map.

For example, the program uses:

planner.find(name)

This allows the program to search for a recipient by name.

### Traversal

The program loops through the unordered_map to display all recipients. It also loops through each recipient’s vector of gifts to display gift information and calculate totals.

### Budget Calculation

The program calculates total planned spending by adding the price of every gift. It also calculates purchased spending by only adding gifts marked as purchased.

This allows the user to compare their spending with their budget.

### File Input and Output

The program can save data to a file called:

gift_planner.txt

It can also load the data back into the program later. This makes the program more useful because the user does not lose their planner information after closing the program.

## How to Compile and Run the Program

To compile the program on Mac in VS Code:

g++ -std=c++17 main.cpp GiftPlanner.cpp -o HolidayGiftPlanner

To run the program:

./HolidayGiftPlanner

## Example Use

A user could use the program like this:

1. Set a budget of $300
2. Add a recipient named Mom
3. Add the relationship Family
4. Add a gift idea such as Candle
5. Enter the gift price as $25
6. View the planner
7. Mark the gift as purchased
8. View the budget summary
9. Save the planner before exiting

## Program Demonstration Screenshots

 These screenshots show three of the main features of the program: setting a budget, adding a recipient, and adding a gift.

### Screenshot 1: Setting the Holiday Budget

File: set_budget_demo.png

This screenshot shows the user selecting option 1 from the menu to set the holiday budget. The user enters a budget of $1000, and the program confirms that the budget has been set. This feature allows the user to create a spending limit before adding gifts.

### Screenshot 2: Adding a Recipient

File: add_recipient_demo.png

This screenshot shows the user selecting option 2 to add a recipient. The sample recipient entered is Luka, and the relationship is Brother. The program stores this recipient in an `unordered_map`, which allows the recipient to be found quickly later when adding gifts or viewing the planner.

### Screenshot 3: Adding a Gift

File: add_gift_demo.png

This screenshot shows the user selecting option 3 to add a gift for an existing recipient. The user enters Luka as the recipient, Shoes as the gift description, and $50 as the gift price. The gift is then added to Luka's gift list, which is stored using a `vector` inside the recipient record.
