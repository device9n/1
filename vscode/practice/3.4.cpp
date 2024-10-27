#include <iostream>
#include <stack>
#include <stdexcept>
using namespace std;

class MyQueue {
    private:
        stack<int> stack1;
        stack<int> stack2;

    public:
        MyQueue(){}

        void enqueue(int x){
            stack1.push(x);
        }

        int dequeue(){
            if (stack2.empty()) {
                while(!stack1.empty()){
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
            if(stack2.empty()){
                throw out_of_range("queue is empty");
            }
            int result = stack2.top();
            stack2.pop();
            return result;
        }
        int peek(){
            if(stack2.empty()){
                while(!stack1.empty()){
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
            if(stack2.empty()){
                throw out_of_range("queue is empty");
            }
            return stack2.top();
        }
    bool isEmpty(){
        return stack1.empty() && stack2.empty(); 
    }

};
int main() {
    MyQueue q;

    // 入队
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // 查看队首元素
    cout << "队首元素: " << q.peek() << endl;  // 输出 10

    // 出队
    cout << "出队元素: " << q.dequeue() << endl;  // 输出 10
    cout << "出队元素: " << q.dequeue() << endl;  // 输出 20

    // 入队
    q.enqueue(40);

    // 查看队首元素
    cout << "队首元素: " << q.peek() << endl;  // 输出 30

    // 出队
    cout << "出队元素: " << q.dequeue() << endl;  // 输出 30
    cout << "出队元素: " << q.dequeue() << endl;  // 输出 40

    // 检查队列是否为空
    cout << "队列是否为空: " << (q.isEmpty() ? "是" : "否") << endl;  // 输出 是

    return 0;
}