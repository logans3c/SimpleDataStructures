#include <iostream>
#include <climits>

class MaxHeap {
private:
    void customSwap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void maxHeapify(int arr[], int i, int heapSize) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int largest = i;

        // Compare with left child
        if (leftChild < heapSize && arr[leftChild] > arr[largest]) {
            largest = leftChild;
        }

        // Compare with right child
        if (rightChild < heapSize && arr[rightChild] > arr[largest]) {
            largest = rightChild;
        }

        // If the largest value is not the current node, swap and recursively apply maxHeapify
        if (largest != i) {
            customSwap(arr[i], arr[largest]);
            maxHeapify(arr, largest, heapSize);
        }
    }

public:
    void buildMaxHeap(int arr[], int size) {
        // Start from the last non-leaf node and apply maxHeapify on each
        for (int i = size / 2 - 1; i >= 0; --i) {
            maxHeapify(arr, i, size);
        }
    }

    void heapSort(int arr[], int size) {
        buildMaxHeap(arr, size);

        // Extract elements one by one
        for (int i = size - 1; i > 0; --i) {
            // Swap the root (maximum element) with the last element
            customSwap(arr[0], arr[i]);

            // Reduce the size of the heap and restore the max heap property
            maxHeapify(arr, 0, i);
        }
    }

    void insert(int arr[], int &size, int value) {
        if (size == 0) {
            arr[0] = value;
            size = 1;
            return;
        }

        // Insert at the end of the array
        int currentIndex = size;
        arr[currentIndex] = value;
        size++;

        // Fix the max heap property by moving the newly inserted element up the heap
        while (currentIndex > 0) {
            int parentIndex = (currentIndex - 1) / 2;
            if (arr[currentIndex] > arr[parentIndex]) {
                customSwap(arr[currentIndex], arr[parentIndex]);
                currentIndex = parentIndex;
            } else {
                break;
            }
        }
    }

    int deleteMax(int arr[], int &size) {
        if (size == 0) {
            std::cout << "Heap underflow, cannot delete from an empty heap." << std::endl;
            return -1; // Assuming -1 represents an invalid value; you can modify as needed.
        }

        // Store the maximum element to be returned later
        int maxValue = arr[0];

        // Replace the root with the last element and reduce the size
        arr[0] = arr[size - 1];
        size--;

        // Restore the max heap property
        maxHeapify(arr, 0, size);

        return maxValue;
    }

    void maxHeapInsert(int arr[], int &size, int value) {
        // Increase the size of the heap and place the new element at the end
        size++;
        arr[size - 1] = INT_MIN; // A very small value

        // Increase the key to the desired value
        heapIncreaseKey(arr, size - 1, value);
    }

    int heapExtractMax(int arr[], int &size) {
        return deleteMax(arr, size);
    }

    void heapIncreaseKey(int arr[], int i, int newValue) {
        if (newValue < arr[i]) {
            std::cout << "New value is smaller than the current value. Cannot increase key." << std::endl;
            return;
        }

        // Update the value at index i
        arr[i] = newValue;

        // Fix the max heap property by moving the updated element up the heap
        while (i > 0) {
            int parentIndex = (i - 1) / 2;
            if (arr[i] > arr[parentIndex]) {
                customSwap(arr[i], arr[parentIndex]);
                i = parentIndex;
            } else {
                break;
            }
        }
    }

    int heapMaximum(int arr[], int size) {
        if (size > 0) {
            return arr[0];
        } else {
            std::cout << "Heap is empty. No maximum value." << std::endl;
            return -1; // Assuming -1 represents an invalid value; you can modify as needed.
        }
    }

    void printArray(int arr[], int size) {
        std::cout << "Array: ";
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MaxHeap maxHeap;

    int arr[] = {25, 15, 10, 5, 20};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original Array: ";
    maxHeap.printArray(arr, size);

    // Perform heapsort
    maxHeap.heapSort(arr, size);

    std::cout << "Array after heapsort: ";
    maxHeap.printArray(arr, size);

    return 0;
}
