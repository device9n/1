#include <iostream>
#include <stdexcept>
using namespace std;

class KStacks {
    private:
        int *arr;
        int *top;
        int *next;
        int n, k;
        int free;
    public:
        KStacks(int k, int n) {
            this->k = k;
            this->n = n;
            arr = new int[n];
            top = new int[k];
            next = new int[n];
            free = 0;

            for(int i = 0; i < k; i++) {
                top[i] = -1;
            }
            for(int i = 0; i < n - 1; i++){
                next[i] = i + 1;
            }
            next[n-1] = -1;
        }
        bool isFull(){
            return free == -1;
        }
        bool isEmpty(int sn) {
            return top[sn] == -1;
        }
        void push(int value, int sn) {
            if(isFull()){
                throw overflow_error("stack is full");
            }

            int i = free;

            free = next[i];

            arr[i] = value;

            next[i] = top[sn];

            top[sn] = i;
        }
        int pop(int sn){
            if(isEmpty(sn)){
                throw underflow_error("stack is empty");
            }

            int i = top[sn];

            top[sn] = next[i];

            next[i] = free;

            free = i;

            return arr[i];
        }
        ~KStacks(){
            delete[] arr;
            delete[] top;
            delete[] next;
        }
};
int main(){
    int k = 3, n = 10;
    KStacks ks(k, n);

    ks.push(15, 0);
    ks.push(45, 0);

    ks.push(17, 1);
    ks.push(41, 1);
    ks.push(33, 1);

    ks.push(13, 2);
    ks.push(14, 2);

    // 从每个栈弹出元素
    cout << "从栈0弹出元素: " << ks.pop(0) << endl;
    cout << "从栈1弹出元素: " << ks.pop(1) << endl;
    cout << "从栈2弹出元素: " << ks.pop(2) << endl;

    return 0;
}