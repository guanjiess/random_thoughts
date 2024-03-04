#include <cstddef>
#include <cstdio>
#include <iostream>
using namespace std;

struct ListListNode{
    int data;
    ListListNode* next;
    ListListNode(int x):data(x),next(NULL){}
};

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val):val(val),next(nullptr){}
};

// Leetcode 204，两两交换相邻节点
ListNode* swapPairs(ListNode* head){
    ListNode* sentinal = new ListNode(0);
    sentinal->next = head;
    ListNode* current = sentinal;
    // 因为要做两两交换，所以需要一次性判断两个后继节点的有效性
    // 如果不满足条件，则无法两两交换
    while (current->next != nullptr && current->next->next != nullptr) {
        ListNode* temp1 = current->next;
        ListNode* temp2 = current->next->next;
        ListNode* temp3 = current->next->next->next;
        current->next = temp2;
        current->next->next = temp1;
        current->next->next->next = temp3;
        // 交换后，将current后移两位，注释版本是错误答案
        // current = temp2;
        current = current->next->next;
    }
    return sentinal->next;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* sentinal = new ListNode(0);
    sentinal->next = head;
    ListNode* fast = head;
    ListNode* slow = head;
    //找到倒数第n个
    int size = 0;
    while (fast) {
        size ++;
        fast = fast->next;
    }
    //删除第n个
    for (int i = 0; i < size - n - 1; i ++) {
        slow = slow->next;
    }
    ListNode* n_node = slow->next;
    ListNode* np1_node = slow->next->next;
    slow->next = np1_node;
    delete n_node;
    return sentinal->next;
}

class Solution{
    public:
        ListListNode* removeE(ListListNode* head, int E){
            // head
            while (head != NULL && head->data == E) {
                ListListNode* tmp = head;
                head = head->next;
                delete tmp;
            }

            // not head
            ListListNode* current = head;
            while (current != NULL && current->next != NULL) {
                if(current->next->data != E){
                    current = current->next;
                } else{
                    ListListNode* tmp = current->next;
                    current = current->next->next;
                    delete tmp;
                }
            }
            return head;
        }
};

class LinkedList{

public:

    LinkedList() {
        //史诗级大bug，加深了我对局部变量、类成员变量的理解
        //ListNode* sentinal = new ListNode(0);
        sentinal = new ListNode(0);
        _size = 0;
    }
    
    // get the index-th item of list, return -1 if invalid.
    int get(int index) {
        // authenticate index valid
        if(index < 0 || index > _size-1){
            return -1;
        }
        ListNode* current = sentinal->next; // corrosponding to index 0
        while (index) {
            current = current->next;
            index --;
        }
        return current->val;
    }

    ListNode* getHead()
    {
        return sentinal->next;
    }
    
    void addAtHead(int val) {
        ListNode* add = new ListNode(val);
        if(_size == 0){
            sentinal->next = add;
            _size ++;
            return;
        }
        add->next = sentinal->next;
        sentinal->next = add;
        _size ++;
    }
    
    void addAtTail(int val) {
        ListNode* add = new ListNode(val);
        //也是一个大bug，如果current为sentinal->next，则current可能是空指针
        //下面的while访问空指针时会带来bug
        ListNode* current = sentinal;
        // jump out of this while, meaning current->next is nullptr
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = add;
        _size ++;
    }
    
    void addAtIndex(int index, int val) {
        //需要判断index是否有效
        if(index > _size) return;
        if(index < 0) index = 0;
        
        ListNode* add = new ListNode(val);
        ListNode* current = sentinal;
        while (index) {
            current = current->next;
            index --;
        }
        add->next = current->next;
        current->next = add; 
        _size ++;
    }
    
    void deleteAtIndex(int index) {
        //注意这里的index判定，是 >= size，因为默认下标从0开始
        if(index >= _size) return;
        if(index < 0) return;
        ListNode* current = sentinal;
        while(index){
            current = current->next;
            index --;
        }
        ListNode* index_ListNode = current->next;
        current->next = current->next->next;
        delete index_ListNode;
        _size --;
    }

    // Leetcode 206，翻转单链表
    // 用temp暂存current->next后续节点
    // pre保存current节点的前序节点，逐个反转current节点的指向
    ListNode* reverseList(LinkedList* list)
    {
        ListNode* head = list->sentinal->next;
        ListNode* current = head;
        ListNode* pre_head = NULL;
        ListNode* temp;
        while (current) {
            temp = current->next;
            current->next = pre_head;
            pre_head = current;
            current = temp;
        }
        return pre_head;
    }

    ListNode* reverse_recursion(ListNode* head){
        return nullptr;
    }


    void print_list(){
        ListNode* current = sentinal->next;
        while (current != nullptr) {
            printf("%d",current->val);
            current = current->next;
            if(current){
                printf("->");
            } else {
                printf("\n");
            }
        }
    }

private:
    int _size;
    ListNode* sentinal;
};

//int main()
//{
//    ListListNode *head = new ListListNode(5);
//    head -> next = NULL;
//
//    printf("Head's value is:%d\n", head->data);
//
//    return 0;
//}