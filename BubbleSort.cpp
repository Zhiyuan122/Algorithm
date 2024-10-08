/*
Bubble Sort
 */

#include<iostream>
using namespace std;

void swap(int arr[], int a, int b){
  int temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
}

void BubbleSort(int arr[], int n){
  if (arr == nullptr || n < 2){
    return;
  }

  for (int end = n-1; end > 0 ; end--){
    for (int i = 0 ; i< end ; i++)
      if (arr[i] > arr[i+1]){
        swap(arr,i,i+1);
      }
  }

}