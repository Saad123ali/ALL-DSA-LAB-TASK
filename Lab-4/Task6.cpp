#include <iostream>
#include <ctime>      // For time()

using namespace std;

// Function to generate a random integer array of a given size
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100000;  // Generate random numbers within a range
    }
}

// Linear search function
int linearSearch(const int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return index of the target
        }
    }
    return -1;  // Return -1 if target is not found
}

// Binary search function (array must be sorted)
int binarySearch(const int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            return mid;  // Return index of the target
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  // Return -1 if target is not found
}

// Function to measure time in milliseconds
long long getTimeInMilliseconds() {
    return static_cast<long long>(clock()) * 1000 / CLOCKS_PER_SEC;
}

int main() {
    // Array sizes to test
    const int sizes[] = {100, 1000, 10000, 100000};
    const int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    cout << "Size\tLinear Search Time (ms)\tBinary Search Time (ms)" << endl;

    for (int i = 0; i < numSizes; i++) {
        int size = sizes[i];
        int* arr = new int[size];

        // Generate random array of integers
        generateRandomArray(arr, size);

        // Choose a random target to search
        int target = arr[rand() % size];

        // Measure time for linear search
        long long startLinear = getTimeInMilliseconds();
        int linearIndex = linearSearch(arr, size, target);
        long long endLinear = getTimeInMilliseconds();
        double timeLinear = (endLinear - startLinear) / 1000.0;

        // Sort the array for binary search
        for (int j = 0; j < size - 1; j++) {
            for (int k = j + 1; k < size; k++) {
                if (arr[j] > arr[k]) {
                    int temp = arr[j];
                    arr[j] = arr[k];
                    arr[k] = temp;
                }
            }
        }

        // Measure time for binary search
        long long startBinary = getTimeInMilliseconds();
        int binaryIndex = binarySearch(arr, size, target);
        long long endBinary = getTimeInMilliseconds();
        double timeBinary = (endBinary - startBinary) / 1000.0;

        // Print results
        cout << size << "\t" << timeLinear << "\t\t\t" << timeBinary << endl;

        // Print search results
        if (linearIndex != -1) {
            cout << "Linear Search: Target " << target << " found at index " << linearIndex << "." << endl;
        } else {
            cout << "Linear Search: Target " << target << " not found." << endl;
        }

        if (binaryIndex != -1) {
            cout << "Binary Search: Target " << target << " found at index " << binaryIndex << "." << endl;
        } else {
            cout << "Binary Search: Target " << target << " not found." << endl;
        }

        delete[] arr;
    }

    return 0;
}
