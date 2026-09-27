#include <iostream>

using namespace std; 

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main() {

    ListNode* head = nullptr;
    ListNode* current = head;

    while (current->next != nullptr) {

        if (current->val == current->next->val) {
            current->next = current->next->next;
        }

        else {
            current = current->next;
        }

    }

}