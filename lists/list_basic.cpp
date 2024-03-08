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
    ListNode* fast = sentinal;
    ListNode* slow = sentinal;
    // 先让fast走n步
    while (n && fast->next != nullptr) {
        fast = fast->next;
        n --;
    }
    // 以下写法可以避免访问空指针
    // 调整fast的时序列，让fast在提前slow一步，以便slow进行删除
    // 注意：倒数第m个的数字的下标是size-m
    fast = fast->next;
    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return sentinal->next;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* InterSect;
    //注意，两个链表一旦发生相交，那么交点之后的所有节点都是相同的
    //所以只需要找到有没有交点即可，思路如下
    //1、分别求出链表长度，2、将两个链表末端对齐
    //3、从短链开头处，逐个节点对比
    int sizeA = 0, sizeB = 0;
    ListNode* A_tmp = headA;
    ListNode* B_tmp = headB;
    while (A_tmp->next != nullptr) {
        A_tmp = A_tmp->next;
        sizeA ++;
    }
    while (B_tmp->next != nullptr) {
        B_tmp = B_tmp->next;
        sizeB ++;
    }
    if(A_tmp != B_tmp) return nullptr;
    int steps = abs(sizeA-sizeB);
    if(sizeA > sizeB){
        while (steps--) {
            headA = headA->next;            
        }
    } else {
        while (steps--) {
            headB = headB->next;            
        }
    }
    while (headA != NULL) {
        // 判断条件要放在前面，否则会产生遗漏情况
        if(headA == headB ) return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;        
}
ListNode *detectCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        //还是要注意空指针异常
        fast = fast->next->next;
        //如果相遇，说明确实存在环
        if(fast == slow){
            ListNode* start1 = head;
            ListNode* start2 = fast;
            while (start1 != start2) {
                start1 = start1->next;
                start2 = start2->next;
            }
            return start2; 
        }    
    }
    return NULL;    
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