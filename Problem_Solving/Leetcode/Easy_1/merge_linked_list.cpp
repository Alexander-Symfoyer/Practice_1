#include <iostream>
#include <list>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main() {

    ListNode* list1 = nullptr;
    ListNode* list2 = nullptr;

    ListNode dummy;             //* Create actual node
    ListNode* cur = &dummy;     //* Make cur point to the actual dummy node
    
    while (list1 != nullptr && list2 != nullptr) {

        if (list1->val <= list2->val) {
            cur->next = list1;
            list1 = list1->next;
        }
        
        else {
            cur->next = list2;
            list2 = list2->next;
        }

        cur = cur->next;    //* Move cur to the node that we just attached

    }

    if (list1 != nullptr) {
        cur->next = list1;
    }
    else {
        cur->next = list2;
    }

    //return dummy.next()   //* dummy is not part of the result
                            //* the real head starts at dummy.next()
}