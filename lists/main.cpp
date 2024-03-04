#include <iostream>
#include <vector>
#include "list_basic.cpp"

void p_list(ListNode* head)
{
    ListNode* current = head;
    while (current) {
        printf("%d", current->val);
        current = current->next;
        if(current){
            printf("->");
        } else{
            printf("\n");
        }
    }
}

void test_list_design(){
   //Your MyLinkedList object will be instantiated and called as such:
    LinkedList list;
    list.addAtHead(1);
    list.addAtHead(2);
    list.addAtHead(3);
    list.addAtTail(4);
    list.addAtIndex(1,5);
    list.print_list();// Output:32541
    list.deleteAtIndex(1);
    list.print_list();// Output:341 
}

void test_reverse(){
   //Your MyLinkedList object will be instantiated and called as such:

    LinkedList* list = new LinkedList();
    list->addAtTail(1);
    list->addAtTail(2);
    list->addAtTail(3);
    list->addAtTail(4);
    list->addAtTail(5);
    list->print_list();// 
    ListNode* head = list->reverseList(list);
    p_list(head);
}

void test_swap()
{
    LinkedList list;
    list.addAtTail(1);
    list.addAtTail(2);
    list.addAtTail(3);
    list.addAtTail(4);
    list.print_list();// Output:32541
    ListNode* head = list.getHead();
    head = swapPairs(head);
    p_list(head);
    list.addAtTail(5);
    list.addAtTail(6);
    list.print_list();// Output:32541

    list.addAtHead(4);
    list.print_list();// Output:32541
}


int main()
{
    //test_list_design();
    //test_reverse();
    test_swap();
    return 0;
}