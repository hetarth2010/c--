#include <iostream>
#include <string>

// 1. INHERITANCE: Abstract base class defining the contract for a Stack
template <typename T>
class BaseStack {
public:
    virtual void push(T value) = 0;
    virtual void pop() = 0;
    virtual T top() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    virtual ~BaseStack() {} // Virtual destructor
};

// 2. CLASS, OBJECT & ENCAPSULATION: Derived Stack class using an array
// POLYMORPHISM: Handled via Class Templates (compile-time polymorphism)
template <typename T>
class Stack : public BaseStack<T> {
private:
    T* arr;          // Dynamic array to hold elements
    int capacity;    // Maximum capacity of the stack
    int topIndex;    // Index of the top element

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new T[capacity];
        topIndex = -1; // Stack is initially empty
    }

    // Destructor to free memory
    ~Stack() {
        delete[] arr;
    }

    // 4. Check if the stack is full
    bool isFull() override {
        return topIndex == capacity - 1;
    }

    // 3. Check if the stack is empty
    bool isEmpty() override {
        return topIndex == -1;
    }

    // 1. Push an element onto the stack
    void push(T value) override {
        if (isFull()) {
            std::cout << "Stack Overflow! Cannot push " << value << ".\n";
            return;
        }
        arr[++topIndex] = value;
        std::cout << "Successfully pushed " << value << " onto the stack.\n";
    }

    // 2. Pop an element from the stack
    void pop() override {
        if (isEmpty()) {
            std::cout << "Stack Underflow! The stack is empty.\n";
            return;
        }
        std::cout << "Successfully popped " << arr[topIndex] << " from the stack.\n";
        topIndex--;
    }

    // Display the top element without removing it
    T top() override {
        if (isEmpty()) {
            std::cout << "Stack is empty. No top element available.\n";
            // Return a default-constructed value safely if empty
            return T(); 
        }
        return arr[topIndex];
    }
};

// Main interactive application menu
int main() {
    int maxCapacity;
    std::cout << "Enter the maximum size of the stack: ";
    std::cin >> maxCapacity;

    // Creating an Integer Stack Object
    Stack<int> intStack(maxCapacity);
    int choice;
    int val;

    do {
        std::cout << "\n--- Stack Operations Menu ---\n";
        std::cout << "1. Push an element\n";
        std::cout << "2. Pop an element\n";
        std::cout << "3. Display top element\n";
        std::cout << "4. Check if empty\n";
        std::cout << "5. Check if full\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice (1-6): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                if (intStack.isFull()) {
                    std::cout << "Stack is full. Cannot accept new elements.\n";
                } else {
                    std::cout << "Enter an integer value to push: ";
                    std::cin >> val;
                    intStack.push(val);
                }
                break;

            case 2:
                intStack.pop();
                break;

            case 3:
                if (!intStack.isEmpty()) {
                    std::cout << "The top element is: " << intStack.top() << "\n";
                } else {
                    intStack.top(); // Calls function to trigger empty message
                }
                break;

            case 4:
                if (intStack.isEmpty()) {
                    std::cout << "The stack is EMPTY.\n";
                } else {
                    std::cout << "The stack is NOT EMPTY.\n";
                }
                break;

            case 5:
                if (intStack.isFull()) {
                    std::cout << "The stack is FULL.\n";
                } else {
                    std::cout << "The stack is NOT FULL.\n";
                }
                break;

            case 6:
                std::cout << "Exiting program. Good luck with your assignment!\n";
                break;

            default:
                std::cout << "Invalid choice! Please choose a number between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}
