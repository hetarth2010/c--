#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. LINKED LIST IMPLEMENTATION
// ==========================================
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Add node to the end of the list
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            cout << "Value " << val << " added as head.\n";
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Value " << val << " inserted at the end.\n";
    }

    // Delete the first occurrence of a value
    void remove(int val) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Value " << val << " removed from list.\n";
            return;
        }
        Node* curr = head;
        Node* prev = nullptr;
        while (curr && curr->data != val) {
            prev = curr;
            curr = curr->next;
        }
        if (!curr) {
            cout << "Value " << val << " not found in the list.\n";
            return;
        }
        prev->next = curr->next;
        delete curr;
        cout << "Value " << val << " removed from list.\n";
    }

    // Display list elements
    void display() {
        if (!head) {
            cout << "Linked List is empty.\n";
            return;
        }
        cout << "Linked List: ";
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// ==========================================
// 2. SORTING ALGORITHMS
// ==========================================

// --- Merge Sort ---
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// --- Quick Sort ---
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Helper function to print an array
void printArray(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << "\n";
}

// ==========================================
// 3. SEARCHING ALGORITHM
// ==========================================

// --- Binary Search ---
int binarySearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1; // Not found
}

// ==========================================
// 4. MAIN MENU-DRIVEN PROGRAM
// ==========================================
int main() {
    LinkedList list;
    vector<int> arrayData;
    bool isSorted = false;
    int choice;

    do {
        cout << "\n=========================================\n";
        cout << "         PR. 20 FINAL PROJECT MENU       \n";
        cout << "=========================================\n";
        cout << "1. Linked List Operations (Create/Modify)\n";
        cout << "2. Sort an Array (Merge Sort / Quick Sort)\n";
        cout << "3. Search Array Value (Binary Search)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int subChoice;
                cout << "\n--- Linked List Operations ---\n";
                cout << "1. Insert Value\n";
                cout << "2. Delete Value\n";
                cout << "3. Display List\n";
                cout << "Enter sub-choice: ";
                cin >> subChoice;

                if (subChoice == 1) {
                    int val;
                    cout << "Enter integer value to insert: ";
                    cin >> val;
                    list.insert(val);
                } else if (subChoice == 2) {
                    int val;
                    cout << "Enter integer value to delete: ";
                    cin >> val;
                    list.remove(val);
                } else if (subChoice == 3) {
                    list.display();
                } else {
                    cout << "Invalid choice.\n";
                }
                break;
            }

            case 2: {
                int n, sortChoice;
                cout << "\nEnter number of elements for the array: ";
                cin >> n;
                arrayData.resize(n);
                cout << "Enter " << n << " integers:\n";
                for (int i = 0; i < n; i++) {
                    cin >> arrayData[i];
                }

                cout << "\n--- Choose Sorting Algorithm ---\n";
                cout << "1. Merge Sort\n";
                cout << "2. Quick Sort\n";
                cout << "Enter sub-choice: ";
                cin >> sortChoice;

                if (sortChoice == 1) {
                    mergeSort(arrayData, 0, arrayData.size() - 1);
                    cout << "Array sorted using Merge Sort.\n";
                    isSorted = true;
                } else if (sortChoice == 2) {
                    quickSort(arrayData, 0, arrayData.size() - 1);
                    cout << "Array sorted using Quick Sort.\n";
                    isSorted = true;
                } else {
                    cout << "Invalid selection. Array remains unsorted.\n";
                    isSorted = false;
                }
                
                cout << "Sorted Array: ";
                printArray(arrayData);
                break;
            }

            case 3: {
                if (arrayData.empty()) {
                    cout << "\nError: The array is currently empty. Please populate and sort it using Option 2 first.\n";
                    break;
                }
                if (!isSorted) {
                    cout << "\nWarning: Array layout may have changed. Sorting it automatically via Merge Sort to ensure accurate Binary Search...\n";
                    mergeSort(arrayData, 0, arrayData.size() - 1);
                    isSorted = true;
                }

                int target;
                cout << "\nCurrent Array Data: ";
                printArray(arrayData);
                cout << "Enter value to search for using Binary Search: ";
                cin >> target;

                int result = binarySearch(arrayData, target);
                if (result != -1) {
                    cout << "Success: Value found at zero-based array index: " << result << "\n";
                } else {
                    cout << "Value not found in the array.\n";
                }
                break;
            }

            case 4:
                cout << "\nExiting assignment application. Good luck with your project submission!\n";
                break;

            default:
                cout << "\nInvalid main option. Please select a valid number (1-4).\n";
        }
    } while (choice != 4);

    return 0;
}
