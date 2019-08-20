#include<iostream>
using namespace std;

int partition(int[], int, int);

void quickSort(int A[], const int left, const int right){
    if(left >= right)
        return;
    int res = partition(A, left, right);
    quickSort(A, left, res - 1);
    quickSort(A, res + 1, right);
    return;
}

int partition(int A[], const int left, const int right){
    int numFlag = A[right];
    int i = -1;
    for (int j = 0; j < right; j++){
        if(A[j] < numFlag){
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    i++;
    A[right] = A[i];
    A[i] = numFlag;
    return i;
}


int main(){
    int A[] = {5, 3, 2, 6, 7, 4, 1};
    quickSort(A, 0, 6);
    return 0;
}