#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* curr = &dummy;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
    }
    
    ListNode* head = dummy.next;
    if (head == nullptr) {
        return new ListNode(0);
    }
    
    ListNode* last_non_zero = nullptr;
    ListNode* temp = head;
    while (temp != nullptr) {
        if (temp->val != 0) {
            last_non_zero = temp;
        }
        temp = temp->next;
    }
    
    if (last_non_zero == nullptr) {
        ListNode* new_head = new ListNode(0);
        temp = head;
        while (temp != nullptr) {
            ListNode* next = temp->next;
            delete temp;
            temp = next;
        }
        return new_head;
    } else {
        temp = last_non_zero->next;
        last_non_zero->next = nullptr;
        while (temp != nullptr) {
            ListNode* next = temp->next;
            delete temp;
            temp = next;
        }
    }
    
    return head;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if (cin >> n) {
        ListNode* l1 = nullptr;
        ListNode* curr = nullptr;
        for (int i = 0; i < n; ++i) {
            int val;
            cin >> val;
            ListNode* node = new ListNode(val);
            if (l1 == nullptr) {
                l1 = node;
            } else {
                curr->next = node;
            }
            curr = node;
        }
        if (cin >> m) {
            ListNode* l2 = nullptr;
            curr = nullptr;
            for (int i = 0; i < m; ++i) {
                int val;
                cin >> val;
                ListNode* node = new ListNode(val);
                if (l2 == nullptr) {
                    l2 = node;
                } else {
                    curr->next = node;
                }
                curr = node;
            }
            ListNode* result = addTwoNumbers(l1, l2);
            ListNode* temp = result;
            while (temp != nullptr) {
                cout << temp->val << (temp->next != nullptr ? " -> " : "");
                temp = temp->next;
            }
            cout << "\n";
            
            while (result != nullptr) {
                ListNode* next = result->next;
                delete result;
                result = next;
            }
        }
    }
    return 0;
}
