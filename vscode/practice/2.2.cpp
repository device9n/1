#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* findKthFromEnd(ListNode* head, int k) {
    ListNode* fast = head;
    ListNode* slow = head;

    for (int i = 0; i < k ; i++){
        if(fast == nullptr) return nullptr;
        fast = fast->next;
    }
    while (fast != nullptr){
         fast = fast->next;
          slow = slow->next;
    }
    return slow;    
}   
void printList(ListNode* head){
    while(head != nullptr) {
        cout<< head->val << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    // 创建一个链表: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // 输出链表
    cout << "链表: ";
    printList(head);

    // 查找倒数第 2 个节点
    int k = 1;
    ListNode* result = findKthFromEnd(head, k);
    
    if (result) {
        cout << "倒数第 " << k << " 个节点的值是: " << result->val << endl;
    } else {
        cout << "链表长度小于 " << k << endl;
    }

    return 0;
}
