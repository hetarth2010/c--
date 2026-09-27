#include <iostream>
#include <vector>

// Function to print the array elements
void printArray(const std::vector<int>& arr) {
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

// 1. SELECTION SORT IMPLEMENTATION
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        // Swap elements
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

// MERGE SORT HELPERS AND IMPLEMENTATION
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];

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

// 2. MERGE SORT IMPLEMENTATION
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// 3. LINEAR SEARCH IMPLEMENTATION
int linearSearch(const std::vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i; // Returns index where target is found
        }
    }
    return -1; // Not found
}

// 4. BINARY SEARCH IMPLEMENTATION (Requires array to be sorted)
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1; // Not found
}

int main() {
    int size;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Invalid array size!\n";
        return 1;
    }

    std::vector<int> originalArr(size);
    std::cout << "Enter " << size << " integer elements:\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> originalArr[i];
    }

    // Work with copies to preserve the original state for alternate testing
    std::vector<int> workingArr = originalArr;
    bool isSorted = false;
    int choice;

    do {
        std::cout << "\n===============================\n";
        std::cout << "   ALGORITHM MENU INTERFACE\n";
        std::cout << "===============================\n";
        std::cout << "Current Array: ";
        printArray(workingArr);
        std::cout << "-------------------------------\n";
        std::cout << "1. Sort via Selection Sort\n";
        std::cout << "2. Sort via Merge Sort\n";
        std::cout << "3. Search via Linear Search\n";
        std::cout << "4. Search via Binary Search (Auto-sorts if needed)\n";
        std::cout << "5. Reset Array to Original Input\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice (1-6): ";
        std::cin >> choice;

        int target, result;
        switch (choice) {
            case 1:
                selectionSort(workingArr);
                std::cout << "Array sorted successfully using Selection Sort!\n";
                isSorted = true;
                break;

            case 2:
                mergeSort(workingArr, 0, workingArr.size() - 1);
                std::cout << "Array sorted successfully using Merge Sort!\n";
                isSorted = true;
                break;

            case 3:
                std::cout << "Enter search target: ";
                std::cin >> target;
                result = linearSearch(workingArr, target);
                if (result != -1) {
                    std::cout << "Target element " << target << " found at index " << result << ".\n";
                } else {
                    std::cout << "Target element " << target << " not found in the array.\n";
                }
                break;

            case 4:
                std::cout << "Enter search target: ";
                std::cin >> target;
                if (!isSorted) {
                    std::cout << "[Notice] Binary search requires data to be sorted. Applying Merge Sort first...\n";
                    mergeSort(workingArr, 0, workingArr.size() - 1);
                    isSorted = true;
                    std::cout << "Sorted Array: ";
                    printArray(workingArr);
                }
                result = binarySearch(workingArr, target);
                if (result != -1) {
                    std::cout << "Target element " << target << " found at index " << result << ".\n";
                } else {
                    std::cout << "Target element " << target << " not found in the array.\n";
                }
                break;

            case 5:
                workingArr = originalArr;
                isSorted = false;
                std::cout << "Array reset to its initial unsorted state.\n";
                break;

            case 6:
                std::cout << "Exiting program. Good luck with your Project 14 submission!\n";
                break;

            default:
                std::cout << "Invalid entry. Choose a menu option from 1 to 6.\n";
        }
    } while (choice != 6);

    return 0;
}
