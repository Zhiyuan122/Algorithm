//Selection Sort
/*
原生数组（C 风格数组）没有像 std::vector 那样的 size() 方法。
原生数组的大小在编译时是固定的，没有内置的函数来获取数组的大小。
你必须手动计算数组的大小
在主函数中
int n = sizeof(arr) / sizeof(arr[0]);整个数组的字节大小除以单个元素的大小

tips:
1. i 表示轮数，j表示当前论数正在对比的数字，min表示当前轮数的最小下标
2. 最后交换的不是下标i，j,而是【i】和[min]，表示每轮最初的元素和当前轮最小的元素交换位置
3. minIndex先放到i，然后再放到j,j再变
*/

/*
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n){
  //如果数组为元素空/小于2
  if (arr == nullptr || n < 2){
    return;
  }

  for (int i = 0 ; i < n-1; i++){
    int minIndex = i;
    for ( int j = i+1 ; j < n ; j++ ){
      if ( arr[j] < arr[minIndex]){
        minIndex = j; //设置一个下标min表示这一轮最小的数
      }
    }
    swap(arr, i , minIndex);



}

void swap(int arr[], int i, int j){
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

 */

#include <iostream>
using namespace std;

void swap( int arr[], int a, int b){
  int temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
}

void selectionSort(int arr[],  int n){ // 错误1： 这里的参数加上了int i, int j,
  if (arr == nullptr || n<2){
    return;
  }

  for (int i = 0; i < n-1 ; i++){  //错误2：i<n?
    int minIndex = i;
    for (int j = i+1 ; j<n; j++ ){
      if(arr[j] < arr[minIndex]){ //错误4：arr[i]
        minIndex = j; //错误3：这里该写swap(arr, i, minIndex)？
      }
    swap(arr, i, minIndex);
    }


  }



}



















