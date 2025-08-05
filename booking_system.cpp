#include <iostream>
#include <vector>
using namespace std;

class ganapati_idol {
    int idol_id;
    string name;
    string size;
    float price;
    bool is_available;

public:
    ganapati_idol(int id, string n, string s, float p) {
        idol_id = id;
        name = n;
        size = s;
        price = p;
        is_available = true;
    }

    int getId() {
        return idol_id;
    }

    bool getAvailability() {
        return is_available;
    }

    void displayDetails() {
        cout << "ID: " << idol_id << " | " << name << " | " << size
             << " | ₹" << price << " | " << (is_available ? "Available" : "Booked") << endl;
    }

    void bookIdol() {
        if (is_available) {
            is_available = false;
            cout << "Booking successful for " << name << endl;
        } else {
            cout << "Idol is already booked!" << endl;
        }
    }
};

class customer {
    int cust_id;
    string name;
    string phone_no;
};

class bookingsystem {
    vector<ganapati_idol> idols;

public:
    void addIdol(ganapati_idol idol) {
        idols.push_back(idol);
    }

    void displayAvailableIdols() {
        cout << "\nAvailable Ganapati Idols:\n";
        for (auto &idol : idols) {
            if (idol.getAvailability()) {
                idol.displayDetails();
            }
        }
    }

    void bookIdolById(int idol_id) {
        for (auto &idol : idols) {
            if (idol.getId() == idol_id) {
                idol.bookIdol();
                return;
            }
        }
        cout << "Idol with ID " << idol_id << " not found!" << endl;
    }
};

int main() {
    bookingsystem system;

    // Adding sample idols
    system.addIdol(ganapati_idol(1, "Eco-Friendly Ganapati", "2 feet", 1500));
    system.addIdol(ganapati_idol(2, "Clay Ganapati", "3 feet", 2500));
    system.addIdol(ganapati_idol(3, "Painted Ganapati", "4 feet", 3500));
    system.addIdol(ganapati_idol(4, "Bal Ganapati", "1.5 feet", 1000));

    char continueBooking;
    int choice;

    do {
        system.displayAvailableIdols();

        cout << "\nEnter Idol ID to book: ";
        cin >> choice;

        system.bookIdolById(choice);

        cout << "\nDo you want to book another idol? (y/n): ";
        cin >> continueBooking;

    } while (continueBooking == 'y' || continueBooking == 'Y');

    cout << "\nFinal Status of Idols:\n";
    system.displayAvailableIdols();

    return 0;
}
