#include <iostream>
using namespace std;

// Tc = O(N) + O(N+M) + O(N) + O(M)
// where N is the length of left and M is the length of right;
// Sc = O(N); -> for recursion stack space
// Lc -> 148. Sort List
// Problem link -> https://leetcode.com/problems/sort-list/
// This is a merge sort approach for linked list  

struct Node {
  int data;
  Node* next;
  
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
  
  ~Node() {
    cout<<"Dtor called for : "<<this->data<<endl;
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

Node* findMidEle(Node* head) {
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

Node* mergeList(Node* &left,Node* &right) {
    // base case 
    if(left == NULL) {
        return right;
    }
    
    if(right == NULL) {
        return left;
    }
    
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    
    while(left != NULL && right != NULL) {
        if(left->data < right->data) {
            temp->next = left;
            temp = left;
            left = left->next;
        } else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    
    // Remaining element for left 
    // while(left != NULL) {
    //     temp->next = left;
    //     temp = left;
    //     left = left->next;
    // }
    
    // more optimise 
    if(left != NULL) {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    
    // Remaining element for right 
    // while(right != NULL) {
    //     temp->next = right;
    //     temp = right;
    //     right = right->next;
    // }
    
    // More optimise
    if(right != NULL) {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    
    return dummy->next;
}  

Node* sortList(Node* &head) {
    // base case 
    if(head == NULL || head->next == NULL) {
        return head;
    }
    
    Node* midEle = findMidEle(head);
    Node* left = head;
    Node* right = midEle->next;
    
    // sort 2 list
    left = sortList(left);
    right = sortList(right);
    
    // merge 2 sorted list 
    Node* mergeListAns = mergeList(left,right);
    
    return mergeListAns;
}

void printList(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
}

int main()
{
    Node* head = NULL;
    insertNode(head,0);
    insertNode(head,4);
    insertNode(head,3);
    insertNode(head,5);
    insertNode(head,-1);
    cout<<"Print Original List : "<<endl;
    printList(head);
    
    Node* ans = sortList(head);
    
    cout<<"Print after sort List : "<<endl;
    printList(head);

    return 0;
}