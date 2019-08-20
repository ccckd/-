#include<iostream>

using namespace std;

void heaptify(int heap[], const int i, const int size){
    int minI = i;
    if(heap[2 * i + 1] < heap[i] && 2 * i + 1 < size)
        minI = 2 * i + 1;
    if(heap[2 * i + 2] < heap[minI] && 2 * i + 2 < size)
        minI = 2 * i + 2;
    if(minI != i){
        int temp = heap[minI];
        heap[minI] = heap[i];
        heap[i] = temp;
        heaptify(heap, minI, size);
    }
}

void buildHeap(int heap[], const int size){  //第一个无子节点的位置:size / 2
    for (int i = 0; i < size / 2; i++){
        heaptify(heap, i, size);
    }
}

void heapSort(int heap[], int const size){
    int cap = size;
    while(cap > 1){
        int temp = heap[cap - 1];
        heap[cap - 1] = heap[0];
        heap[0] = temp;
        cap--;
        heaptify(heap, 0, cap);
    }

}


int main(){
    int heap[] = {3, 5, 1, 4, 2};
    buildHeap(heap, 5);
    heapSort(heap, 5);
    return 0;
}