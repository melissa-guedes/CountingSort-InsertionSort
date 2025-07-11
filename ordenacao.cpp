#include <iostream>
#include <vector>
#include <algorithm>

void printArray(const std::vector<int>& arr) {
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;
}

void countingSort(std::vector<int>& arr) {
    if (arr.empty()) return;

    int maxVal = *std::max_element(arr.begin(), arr.end());

    std::vector<int> count(maxVal + 1, 0);

    for (int num : arr) {
        count[num]++;
    }

    int index = 0;
    for (int i = 0; i <= maxVal; ++i) {
        while (count[i]-- > 0) {
            arr[index++] = i;
        }
    }
}

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    std::vector<int> original = {5, 1, 4, 2, 8};

    std::vector<int> arr1 = original;
    std::cout << "Original: ";
    printArray(arr1);

    countingSort(arr1);
    std::cout << "Counting Sort: ";
    printArray(arr1);

    std::vector<int> arr2 = original;
    insertionSort(arr2);
    std::cout << "Insertion Sort: ";
    printArray(arr2);

    return 0;
}
