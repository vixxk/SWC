#include <iostream>
#include <vector>

using namespace std;

// Doubly Linked List Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
};

// Split the doubly linked list into two halves
Node* split(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* temp = slow->next;
    slow->next = nullptr;
    if (temp != nullptr) {
        temp->prev = nullptr;
    }
    return temp;
}

// Merge two sorted doubly linked lists in-place
Node* merge(Node* first, Node* second) {
    if (first == nullptr) return second;
    if (second == nullptr) return first;

    Node* dummy = new Node(0);
    Node* tail = dummy;

    while (first != nullptr && second != nullptr) {
        if (first->data <= second->data) {
            tail->next = first;
            first->prev = tail;
            first = first->next;
        } else {
            tail->next = second;
            second->prev = tail;
            second = second->next;
        }
        tail = tail->next;
    }

    if (first != nullptr) {
        tail->next = first;
        first->prev = tail;
    } else if (second != nullptr) {
        tail->next = second;
        second->prev = tail;
    }

    Node* result = dummy->next;
    if (result != nullptr) {
        result->prev = nullptr;
    }
    delete dummy;
    return result;
}

// Perform merge sort on doubly linked list
Node* mergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* mid = split(head);
    head = mergeSort(head);
    mid = mergeSort(mid);
    return merge(head, mid);
}

int main() {
    // Optimizing input/output operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        Node* head = nullptr;
        Node* curr = nullptr;
        for (int i = 0; i < n; ++i) {
            int val;
            cin >> val;
            Node* node = new Node(val);
            if (head == nullptr) {
                head = node;
            } else {
                curr->next = node;
                node->prev = curr;
            }
            curr = node;
        }

        // Sort the DLL using Merge Sort
        head = mergeSort(head);

        // Print forward traversal
        Node* temp = head;
        Node* tail = nullptr;
        while (temp != nullptr) {
            cout << temp->data << (temp->next != nullptr ? " " : "");
            tail = temp;
            temp = temp->next;
        }
        cout << "\n";

        // Print backward traversal
        temp = tail;
        while (temp != nullptr) {
            cout << temp->data << (temp->prev != nullptr ? " " : "");
            temp = temp->prev;
        }
        cout << "\n";

        // Free memory to prevent memory leaks
        temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
    return 0;
}
