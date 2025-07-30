/*
0~i范围上，相邻位置较大的数滚下去，最大值最终来到i位置，然后0~i-1范围上继续
0-4的位置上，谁大谁往后，end最后来到4
    0 1， 1 2， 2 3， 3 4；
0-3的位置上，谁大谁往后。end最后来到3
    0 1， 1 2， 2 3；
冒泡排序：每轮把最大值"冒"到最后

其实笔记的逻辑本质上是逐步缩小array，然后每个新的end 的array中，相邻两个元素比较，大的往后移动

*/

#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector <int>& arr){
    if (arr.size() < 2) return;

    for ( int end = arr.size()-1; end > 0; --end){
        for (int i = 0; i < end; ++i){
            if(arr[i] > arr [i+1]){
                swap(arr[i], arr[i+1]);
            }
        }
    }

}

void printArray(const vector <int>& arr){
    for (int x : arr){
        cout << x << " ";
    }
    cout << endl;
}


int main(){
    vector<int> arr = {1,2,5,6,9,8,4,5,6,5,5,5};
    cout << "before bubbleSort :";
    printArray(arr);

    cout <<"after bubbleSort :";
    bubbleSort(arr);

    printArray(arr);//这里是不是相当于创建了一个arr的副本？， 还是原有arr的数值已经被更改了？

    return 0;

}