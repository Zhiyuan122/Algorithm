#include <iostream>
#include <vector>
using namespace std;

/*
std::swap() 是 模板函数，可自动优化为 移动（move）操作，避免不必要的复制
手写的swap通常是：
    int temp = a;
    a = b;
    b = temp;
虽然在 int 类型上无所谓，但在对象类型（如 vector、string）上就容易 额外复制，慢很多。

std::swap() 适用于：
1. 内置类型（int、char、double）
2. STL 容器（vector, map, string, pair 等）
3. 用户自定义类型（只要实现了移动构造和赋值）

    1. 手动实现swap（适用于基础类型如 int）
    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }
    int& a：使用引用传递，确保可以交换原变量的值，而不是副本

    2. 泛型版本（模板，适用于任意类型）
    template<typename T>
    void swap(T& a, T& b){
        T temp = a;
        a = b
        b = temp;
    }
    T 可以是 int, double, string, vector<int> 等任意类型

    3. 高级版本（使用 move，性能更好，类似 std::swap 实现）
    #include <utility>

    template<typename T>  // 为了 std::move
    void swap(T& a. T& b){
        T temp = std :: move(a); // 避免拷贝
        a = std :: move(b);
        b = std :: move(temp);
    }
    避免了对象的深拷贝（特别是 vector, string 这类大对象）
    性能几乎和 std::swap 一样

    void badSwap(int a, int b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    // 在C++ 里面 不起作用，交换的是副本！

*/

/*
移动语义（move semantics）
string a = "hello";
string b = std::move(a);

这不会拷贝字符串内容，而是：
    把 a 的内部资源（内存指针）直接“搬”给了 b
    a 会变成“空壳”，但不崩溃

为什么用 std::move()？
比拷贝更快（特别是大对象如 vector, string, 自定义类）
用在 swap、emplace_back 等底层优化里很常见


常见错误：
    for (int i = 0; i < arr.size(); i++){
        int minIndex = i;
        for (int j = i+1; j < arr.size(); j++){
            if (arr[i] < arr[j]){
                minIndex = j;

arr[i] 与 arr[j] 比较，但 arr[i] 是固定的，不该参与比较


*/

void selectionSort(vector<int>& arr){
    if(arr.size() < 2) return;

    for (int i = 0; i < arr.size(); i++){
        int minIndex = i;
        for (int j = i+1; j < arr.size(); j++){
            if (arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }

}

void printArray(const vector <int>& arr){
    for (int x : arr){
        cout << x << " ";
    }
    cout << endl;
}


int main(){
    vector <int> arr = {5,6,5,8,7,5,4};
    cout << "Before Selection Sort:" ;
    printArray(arr);

    selectionSort(arr);
    cout << "After Selection Sort:";
    printArray(arr);
    return 0;
}