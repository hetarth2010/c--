#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Create Class Template: Memory Calculate
template <typename T>
class MemoryCalculate {
private:
    // Attributes
    T id;
    std::string name;

public:
    // A constructor to initialize the id and name
    MemoryCalculate(T id, std::string name) : id(id), name(name) {}

    // Methods
    T getId() const { return id; }
    std::string getName() const { return name; }

    // A method to display the student's details
    void displayDetails() const {
        std::cout << "ID: " << id << " | Name: " << name << std::endl;
    }
};

int main() {
    // Vector to store MemoryCalculate objects (using int for ID type)
    std::vector<MemoryCalculate<int>> studentVector;
    int choice;

    do {
        std::cout << "\n--- Student Management System ---" << std::endl;
        std::cout << "1. Add students to a list" << std::endl;
        std::cout << "2. Display the list of students" << std::endl;
        std::cout << "3. Remove a student from the list by ID" << std::endl;
        std::cout << "4. Search for a student by ID" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            // Task: Add a Student using push_back()
            int id;
            std::string name;
            std::cout << "Enter Student ID: ";
            std::cin >> id;
            std::cin.ignore(); // Clear newline character from buffer
            std::cout << "Enter Student Name: ";
            std::getline(std::cin, name);

            studentVector.push_back(MemoryCalculate<int>(id, name));
            std::cout << "Student added successfully." << std::endl;

        } else if (choice == 2) {
            // Task: Display All Students iterating through the vector
            if (studentVector.empty()) {
                std::cout << "No student records found." << std::endl;
            } else {
                std::cout << "\n--- Student List ---" << std::endl;
                for (const auto& student : studentVector) {
                    student.displayDetails();
                }
            }

        } else if (choice == 3) {
            // Task: Remove a Student by ID
            if (studentVector.empty()) {
                std::cout << "No student records to remove." << std::endl;
            } else {
                int searchId;
                std::cout << "Enter Student ID to remove: ";
                std::cin >> searchId;

                auto it = std::find_if(studentVector.begin(), studentVector.end(), 
                    [searchId](const MemoryCalculate<int>& student) {
                        return student.getId() == searchId;
                    });

                if (it != studentVector.end()) {
                    studentVector.erase(it);
                    std::cout << "Student with ID " << searchId << " removed successfully." << std::endl;
                } else {
                    std::cout << "Student with ID " << searchId << " not found." << std::endl;
                }
            }

        } else if (choice == 4) {
            // New Task: Search for a Student by ID
            if (studentVector.empty()) {
                std::cout << "No student records available to search." << std::endl;
            } else {
                int searchId;
                std::cout << "Enter Student ID to search: ";
                std::cin >> searchId;

                auto it = std::find_if(studentVector.begin(), studentVector.end(), 
                    [searchId](const MemoryCalculate<int>& student) {
                        return student.getId() == searchId;
                    });

                if (it != studentVector.end()) {
                    std::cout << "\nStudent Found:" << std::endl;
                    it->displayDetails();
                } else {
                    std::cout << "Student with ID " << searchId << " not found." << std::endl;
                }
            }
        }
    } while (choice != 5);

    std::cout << "Exiting program." << std::endl;
    return 0;
}
