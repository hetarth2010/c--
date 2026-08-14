#include <iostream>

// Structure defining a Node in the linked list
struct Node {
    int data;
    Node* next;
};

// Base Class: Dynamic Memory Allocation
class DynamicMemoryAllocation {
protected:
    Node* head; // Head node attribute

public:
    // Constructor initializing the head pointer to NULL
    DynamicMemoryAllocation() {
        head = nullptr;
    }

    // Task 1: Append function to add data at the end
    void append(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Task 1: Display function to output list contents
    void display() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }

    // Task 2: Insert element at the beginning
    void insert_at_beginning(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    // Task 2: Search operation (Returns true if found)
    bool Search(int key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Task 3: Deletion of a Node by value
    void Delete_node(int key) {
        if (head == nullptr) {
            std::cout << "List is empty. Cannot delete." << std::endl;
            return;
        }

        // If head node itself holds the key to be deleted
        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr && current->data != key) {
            previous = current;
            current = current->next;
        }

        // If the key was not present in the linked list
        if (current == nullptr) {
            std::cout << "Value " << key << " not found in the list." << std::endl;
            return;
        }

        // Unlink the node from linked list and free memory
        previous->next = current->next;
        delete current;
    }

    // Task 4: Reversing the Linked List
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;

        while (current != nullptr) {
            nextNode = current->next; // Store next node
            current->next = prev;     // Reverse current node's pointer
            prev = current;           // Move pointers one step forward
            current = nextNode;
        }
        head = prev;
    }

    // Destructor to free up dynamic allocation memory safely
    ~DynamicMemoryAllocation() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }
};

// Driver Program to test the implementation details
int main() {
    DynamicMemoryAllocation list;

    std::cout << "--- Task 1: Append and Display ---" << std::endl;
    list.append(10);
    list.append(20);
    list.append(30);
    std::cout << "Initial List: ";
    list.display();

    std::cout << "\n--- Task 2: Insert at Beginning and Search ---" << std::endl;
    list.insert_at_beginning(5);
    std::cout << "After inserting 5 at beginning: ";
    list.display();
    
    std::cout << "Searching for 20: " << (list.Search(20) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for 100: " << (list.Search(100) ? "Found" : "Not Found") << std::endl;

    std::cout << "\n--- Task 3: Deletion of a Node by Value ---" << std::endl;
    list.Delete_node(20);
    std::cout << "After deleting 20: ";
    list.display();

    std::cout << "\n--- Task 4: Reversing the Linked List ---" << std::endl;
    list.reverse();
    std::cout << "Reversed List: ";
    list.display();

    return 0;
}
