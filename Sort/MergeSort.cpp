#include<iostream>
using namespace std;

void merge(int A[], const int left, const int mid, const int right){
    //遍历辅助数组B和C得时候要注意其索引是从0开始的
    int B[mid + 1 - left + 1];
    for (int i = left; i <= mid + 1; i++){
        if(i != mid + 1)
            B[i - left] = A[i];
        else
            B[i - left] = 999;  //无穷
    }
    int C[right + 1 - mid];
    for (int i = mid + 1; i <= right + 1; i++){
        if(i != right + 1)
            C[i - mid - 1] = A[i];
        else
            C[i - mid - 1] = 999;
    }
    int i = left, j = left, k = left;
    while(i <= right){
        if(B[j - left] < C[k - left]){
            A[i++] = B[j - left];
            j++;
        }else{
            A[i++] = C[k - left];
            k++;
        }
    }
}

void mergeSort(int A[], const int left, const int right){
    if(left >= right)
        return;
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid + 1, right);
    merge(A, left, mid, right);
}
int A[] = {3, 5, 2, 7, 5, 8, 4, 1, 9};
int main(){
    
    mergeSort(A, 0, 8);
    return 0;
}