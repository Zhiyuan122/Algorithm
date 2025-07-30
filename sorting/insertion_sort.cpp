/*

插入排序一句话：0~i范围上已经有序，新来的数从右到左滑到不再小的位置插入，然后继续
本质上是一个arr逐渐放缩变大，每个新进来的元素都和前面的比较，谁小谁往左

*/

#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr){
    if (arr.size() < 2) return;
   
//    用J+1代表新来的数字，然后j--往左
//用两个指针实现比较，同时第三个最外层的指针i负责控制论数（每轮新进来的）
//    for (int i = 0 ; i < arr.size(); ++i){
//        for (int j = i-1 ; j >=0 && arr[j] > arr[j+1]; j--){
//             swap(arr[j], arr[j+1]);
        }
//    }

    for (int end = 1; end < arr.size(); ++end){
        for (int i = end; i >=0; i-- ){
            if (i > 0 && arr [i] < arr [i-1]){
                swap(arr[i], arr[i-1]);
            }
        }
    }



void printArray(const vector<int>& arr){
    for (int x : arr){
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    vector <int> arr = {1,2,5,6,9,8,7,4,5};
    cout << "before insertion sort:";
    printArray(arr);


    cout << "after insertion sort:";
    insertionSort(arr);
    printArray(arr);

    return 0;

}