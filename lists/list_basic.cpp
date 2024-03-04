#include <cstddef>
#include <cstdio>
#include <iostream>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;
    ListNode(int x):data(x),next(NULL){}
};

struct node{
    int val;
    node* next;
    node(int val):val(val),next(nullptr){}
};

// Leetcode 204，两两交换相邻节点
node* swapPairs(node* head){
    node* sentinal = new node(0);
    sentinal->next = head;
    node* current = sentinal;
    // 因为要做两两交换，所以需要一次性判断两个后继节点的有效性
    // 如果不满足条件，则无法两两交换
    while (current->next != nullptr && current->next->next != nullptr) {
        node* temp1 = current->next;
        node* temp2 = current->next->next;
        node* temp3 = current->next->next->next;
        current->next = temp2;
        current->next->next = temp1;
        current->next->next->next = temp3;
        // 交换后，将current后移两位，注释版本是错误答案
        // current = temp2;
        current = current->next->next;
    }
    return sentinal->next;
}

node* removeNthFromEnd(ListNode* head, int n) {

}

class Solution{
    public:
        ListNode* removeE(ListNode* head, int E){
            // head
            while (head != NULL && head->data == E) {
                ListNode* tmp = head;
                head = head->next;
                delete tmp;
            }

            // not head
            ListNode* current = head;
            while (current != NULL && current->next != NULL) {
                if(current->next->data != E){
                    current = current->next;
                } else{
                    ListNode* tmp = current->next;
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
        //node* sentinal = new node(0);
        sentinal = new node(0);
        _size = 0;
    }
    
    // get the index-th item of list, return -1 if invalid.
    int get(int index) {
        // authenticate index valid
        if(index < 0 || index > _size-1){
            return -1;
        }
        node* current = sentinal->next; // corrosponding to index 0
        while (index) {
            current = current->next;
            index --;
        }
        return current->val;
    }

    node* getHead()
    {
        return sentinal->next;
    }
    
    void addAtHead(int val) {
        node* add = new node(val);
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
        node* add = new node(val);
        //也是一个大bug，如果current为sentinal->next，则current可能是空指针
        //下面的while访问空指针时会带来bug
        node* current = sentinal;
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
        
        node* add = new node(val);
        node* current = sentinal;
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
        node* current = sentinal;
        while(index){
            current = current->next;
            index --;
        }
        node* index_node = current->next;
        current->next = current->next->next;
        delete index_node;
        _size --;
    }

    // Leetcode 206，翻转单链表
    // 用temp暂存current->next后续节点
    // pre保存current节点的前序节点，逐个反转current节点的指向
    node* reverseList(LinkedList* list)
    {
        node* head = list->sentinal->next;
        node* current = head;
        node* pre_head = NULL;
        node* temp;
        while (current) {
            temp = current->next;
            current->next = pre_head;
            pre_head = current;
            current = temp;
        }
        return pre_head;
    }

    node* reverse_recursion(node* head){
        return nullptr;
    }


    void print_list(){
        node* current = sentinal->next;
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
    node* sentinal;
};

//int main()
//{
//    ListNode *head = new ListNode(5);
//    head -> next = NULL;
//
//    printf("Head's value is:%d\n", head->data);
//
//    return 0;
//}