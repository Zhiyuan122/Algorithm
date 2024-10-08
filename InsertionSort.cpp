//insertion Sort
//
#include <iostream>
using namespace std;

void sawp(int arr[], int a, int b){
  int temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
}

void insertionSort(int arr[], int n){
  if(arr == nullptr || n<2){
    return;
  }

   for (int i = 1; i < n; i++){
     for(int j = i -1; j>=0 && arr[j] > arr[j+1] ; j--){
       swap(arr, j, j+1);
   }


]