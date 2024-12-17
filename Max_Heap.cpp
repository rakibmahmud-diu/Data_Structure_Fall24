#include <stdio.h>

#define MAX_SIZE 100

int heap[MAX_SIZE];
int size = 0;


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void upHeapify(int index) {
    while (index > 1) {
        int parent = index / 2;
        if (heap[index] > heap[parent]) {
            swap(&heap[index], &heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}


void downHeapify(int index) {
    int largest = index;
    int leftChild = 2 * index;
    int rightChild = 2 * index + 1;

    if (leftChild <= size && heap[leftChild] > heap[largest]) {
        largest = leftChild;
    }

    if (rightChild <= size && heap[rightChild] > heap[largest]) {
        largest = rightChild;
    }

    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        downHeapify(largest);
    }
}


void insert(int value) {
    if (size >= MAX_SIZE - 1) {
        printf("Heap overflow! Cannot insert %d\n", value);
        return;
    }

    size++;
    heap[size] = value;
    upHeapify(size);
    printf("Inserted %d into the heap.\n", value);
}


int deleteMax() {
    if (size == 0) {
        printf("Heap underflow! No elements to delete.\n");
        return -1;
    }

    int max = heap[1];
    heap[1] = heap[size];
    size--;
    downHeapify(1);
    //printf("Deleted %d from the heap.\n", max);
    return max;
}


void heapSort() {
    if (size == 0) {
        printf("Heap is empty. Cannot sort.\n");
        return;
    }
    printf("Heap elements in sorted order: ");
    int originalSize = size;
    while (size > 0) {
        printf("%d ", deleteMax());
    }
    printf("\n");
    size = originalSize;
}


// Main function to test the Max Heap
int main() {
    insert(25);
    insert(40);
    insert(35);
    insert(15);
    insert(50);
    insert(10);
    heapSort();

    deleteMax();
    heapSort();

    insert(45);
    heapSort();

    deleteMax();
    deleteMax();
    heapSort();

    return 0;
}
