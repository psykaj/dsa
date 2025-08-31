#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    
    ~Node() {
        cout<<"dtor called for : "<<this->data<<endl;
    }
};

void insertNode(Node* &head,int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void printList(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}

// Brute force 
// Tc = O(N);
// Sc = O(N); -> vector 
// bool isPalindrome(Node* &head) {
//     Node* temp = head;
//     vector<int> v;
    
//     while(temp != NULL) {
//         v.push_back(temp->data);
//         temp = temp->next;
//     }
    
//     int start = 0;
//     int end = v.size()-1;
    
//     while(start <= end) {
//         if(v[start] != v[end]) {
//             return false;
//         }
//         start++;
//         end--;
//     }
//     return true;
// }

// Better approch 
// Tc = O(N);
// Sc = O(1);
Node* middle(Node* &head) {
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

Node* reverseUsingRecursion(Node* prev,Node* curr) {
    if(curr == NULL) {
        return prev;
    }
    
    Node* nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
    
    Node* ans = reverseUsingRecursion(prev,curr);
    
    return ans;
}

bool compare(Node* head1,Node* head2) {
    
    while(head2 != NULL) {
        if(head1->data != head2->data) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    
    return true;
}

bool isPalindrome(Node* &head) {
    Node* middleNode = middle(head);
    Node* head2 = middleNode->next;
    middleNode->next = NULL;
    
    // reverse head 2 
    Node* prev = NULL;
    Node* curr = head2;
    head2 = reverseUsingRecursion(prev,curr);
    
    bool ans = compare(head,head2);
    
    return ans;
}

int main()
{
    Node* head = NULL;
    
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,2);
    insertNode(head,1);
    
    printList(head);

    bool ans = isPalindrome(head);
    if(ans) {
        cout<<"the given list is Palindrome"<<endl;
    } else {
        cout<<"the given list is not a Palindrome"<<endl;
    }

    return 0;
}