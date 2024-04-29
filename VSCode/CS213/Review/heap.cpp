#include <iostream>
#include <vector>

class Heap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] < heap[parentIndex]) {
                std::swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        while (2 * index + 1 < heap.size()) {
            int childIndex = 2 * index + 1;
            if (childIndex + 1 < heap.size() && heap[childIndex + 1] < heap[childIndex]) {
                childIndex++;
            }

            if (heap[childIndex] < heap[index]) {
                std::swap(heap[childIndex], heap[index]);
                index = childIndex;
            } else {
                break;
            }
        }
    }

public:
    void heapEnqueue(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int heapDequeue() {
        if (heap.empty()) {
            std::cerr << "Heap is empty." << std::endl;
            return -1; // or any appropriate value to indicate an error
        }

        int maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return maxValue;
    }

    void printHeap() {
        for (int value : heap) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Heap heap;

    heap.heapEnqueue(4);
    heap.heapEnqueue(10);
    heap.heapEnqueue(8);
    heap.heapEnqueue(5);
    heap.heapEnqueue(1);

    heap.printHeap(); // Output: 10 5 8 4 1

    int max_value = heap.heapDequeue();
    std::cout << "Max Value: " << max_value << std::endl; // Output: 10
    max_value = heap.heapDequeue();
    std::cout << "Max Value: " << max_value << std::endl;
    max_value = heap.heapDequeue();
    std::cout << "Max Value: " << max_value << std::endl;
    max_value = heap.heapDequeue();
    std::cout << "Max Value: " << max_value << std::endl;
    max_value = heap.heapDequeue();
    std::cout << "Max Value: " << max_value << std::endl;

    heap.printHeap(); // Output: 8 5 1 4

    return 0;
}