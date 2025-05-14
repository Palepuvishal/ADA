#include <stdio.h>
#include <time.h>

// Function to heapify the tree
void heapify(int arr[], int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // left child
    int right = 2 * i + 2;  // right child

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        // Swap the largest element with the root
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to perform Heap Sort
void heap_sort(int arr[], int n) {
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // One by one extract elements from the heap
    for (int i = n - 1; i >= 1; i--) {
        // Move current root to the end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print the array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Create a large array with 100,000 elements (or any large number)
    int n = 100000;
    int arr[n];

    // Fill the array with random values
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;  // Random values between 0 and 99999
    }

    // Start time measurement
    clock_t start_time = clock();

    // Perform heap sort
    heap_sort(arr, n);

    // End time measurement
    clock_t end_time = clock();

    // Calculate and print time taken
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken to sort the array with %d elements: %f seconds\n", n, time_taken);

    return 0;
}
