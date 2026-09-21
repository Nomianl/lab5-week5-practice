/*
 * Course: COEN 2220 - Programming 2
 * Name: [Your Name]
 * Lab: Lab 5 - Week 5 Practice: OOP and Function Templates
 * Description: Inheritance, polymorphism, and function template practice
 * Due date: [Date]
 */

#include <iostream>
#include <string>
using namespace std;

class CampusEvent
{
    private:
        string name; // Each CampusEvent object keeps its own name.

    public:
        CampusEvent(string eventName) {
            name = eventName; // The base class initializes shared state.
        }

        string getName() const {
            return name; // Derived classes use this public interface to read the name.
        }

        virtual void printDetails() const {
            cout << name << ": open attendance" << endl;
        }
};

class LimitedEvent : public CampusEvent
{
    private:
        // ===== Resolve these TODOs now (Part C) =====

        // TODO (Part C): Add a private int member that stores available seats.
        int availableSeats;

    public:
        // TODO (Part C): Write a constructor that receives an event name and an int.
        // Initialize the inherited CampusEvent part with the name, then store available seats.
        LimitedEvent(string eventName, int seats) : CampusEvent(eventName) {
            availableSeats = seats;
        }

        // TODO (Part C): Override printDetails() const.
        // Use getName() and print the number of available seats.
        void printDetails() const override {
            cout << getName() << ": " << availableSeats << " seats available" << endl;
        }
};

// ===== Resolve these TODOs later (Part D) =====

// TODO (Part D): Write a function template named largerValue.
// It receives two const references of the same generic type and returns the larger value.
// Do not write separate int and double versions.

template <typename T>
T largerValue(const T& a, const T& b) {
    return (a > b) ? a : b;
}

int main() {
    CampusEvent openEvent("Coding Club Meeting");

    cout << "--- Base event ---" << endl;
    openEvent.printDetails(); // This call uses CampusEvent::printDetails directly.

    // ===== Resolve these TODOs later (Part E) =====

    // TODO (Part E): Create a LimitedEvent with dummy data.
    LimitedEvent limitedEvent("Math Workshop", 30);

    // TODO (Part E): Store the addresses of openEvent and your LimitedEvent
    // in two CampusEvent pointers. Call printDetails() through both pointers.
    CampusEvent* event1 = &openEvent;
    CampusEvent* event2 = &limitedEvent;

    cout << "\n--- Polymorphism ---" << endl;
    event1->printDetails(); // Calls CampusEvent::printDetails()
    event2->printDetails(); // Calls LimitedEvent::printDetails() dynamically

    // 3. Testing function template with int and double
    cout << "\n--- Function template ---" << endl;

    int attendance1 = 45;
    int attendance2 = 91;
    int maxAttendance = largerValue(attendance1, attendance2);
    cout << "Higher attendance estimate: " << maxAttendance << endl;

    double rating1 = 4.2;
    double rating2 = 4.75;
    double maxRating = largerValue(rating1, rating2);
    cout << "Higher event rating: " << maxRating << endl;

    return 0;
}