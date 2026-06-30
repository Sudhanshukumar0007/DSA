#include <iostream>
using namespace std;

class PriorityQueue {
    int arr[100];   // fixed size array (max 100 elements)
    int size;       // current size

public:
    PriorityQueue() {
        size = 0;
    }

    // Helper: swap function
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Insert element (O(log n))
    void push(int x) {
        arr[size] = x;   // insert at end
        int i = size;
        size++;

        // Fix heap property (bubble up)
        while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Remove and return highest priority element (O(log n))
    int pop() {
        if (size <= 0) {
            cout << "Queue is empty!\n";
            return -1;
        }
        if (size == 1) {
            size--;
            return arr[0];
        }

        // Take root element
        int root = arr[0];
        arr[0] = arr[size - 1]; // move last to root
        size--;

        heapify(0); // fix heap property

        return root;
    }

    // Heapify (O(log n))
    void heapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && arr[left] > arr[largest])
            largest = left;

        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    // Peek highest priority
    int top() {
        if (size <= 0) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[0];
    }

    // Check empty
    bool empty() {
        return size == 0;
    }

    // Print queue
    void display() {
        cout << "Priority Queue: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

// ---------------- MAIN ----------------
int main() {
    PriorityQueue pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    pq.display(); // should show heap order

    cout << "Top: " << pq.top() << endl;

    cout << "Removed: " << pq.pop() << endl;
    pq.display();

    cout << "Removed: " << pq.pop() << endl;
    pq.display();

    pq.push(15);
    pq.push(20);
    pq.display();
    return 0;
}
