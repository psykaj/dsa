// Doubly Linklist 
#include <iostream>
using namespace std;
// class for DLL 
class Node {
    public:
    int data;
    Node* prev;
    Node* next;
    
    Node() {
        cout<<"Default ctor"<<endl;
        this->prev = NULL;
        this->next = NULL;
    }
    
    // pamaterized ctor 
    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    
    ~Node() {
        cout<<"dtor called for : "<<this->data<<endl;
    }
};

void printLinklist(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}

int findLength(Node* &head) {
    int count = 0;
    Node* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertNodeAtHead(Node* &head,Node* &tail,int data) {
    if(head == NULL) {
        // create node 
        Node* newNode = new Node(data);
        // newNode = head 
        head = newNode;
        tail = newNode;
        return;
    } else {
        // create Node 
        Node* newNode = new Node(data);
        // head->prev = newNode;
        head->prev = newNode;
        // newNode->next = head;
        newNode->next = head;
        // head = newNode;
        head = newNode;
    }
}

void insertNodeAtTail(Node* &head,Node* &tail,int data) {
    if(head == NULL) {
        // linklist is empty 
        // create Node 
        Node* newNode = new Node(data);
        newNode = head;
        newNode = tail;
    } else {
        // linklist is not empty
        // create Node 
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertNodeAtPos(Node* &head,Node* &tail,int data,int pos) {
    int len = findLength(head);
    if(pos == 1) {
        insertNodeAtHead(head,tail,data);
    } else if(pos == len+1) {
        insertNodeAtTail(head,tail,data);
    } else {
        // insert at middle 
        // create node 
        Node* newNode = new Node(data);
        // set prev & curr pointer using while loop 
        Node* prevNode = NULL;
        Node* currNode = head;
        while(pos != 1) {
            pos--;
            prevNode = currNode;
            currNode = currNode->next;
        }
        // prev->next = newNode;
        prevNode->next = newNode;
        newNode->prev = prevNode;
        // newNode->next = curr;
        newNode->next = currNode;
        currNode->prev = newNode;
    }
}

void deleteNodeAtHead(Node* &head,Node* &tail,int data) {
    
    if(head == tail) {
        // Single element case 
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
    }
    
    if(head == NULL) {
        // linklist is empty
        cout<<"Cannot delete, please give valid number!!";
        return;
    } else {
        // linklist is not empty
        // create temp node 
        Node* temp = head;
        // head = head->next;
        head = head->next;
        // temp->prev = NULL;
        temp->prev = NULL;
        // temp->next = NULL;
        temp->next = NULL;
        // delete temp node 
        delete temp;
    }
}

void deleteNodeAtTail(Node* &head,Node* &tail,int data) {
    
    if(head == tail) {
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
    }
    
    if(head == NULL) {
        // linklist is empty
        cout<<"Cannot delete, please give valid number!!";
        return;
    } else {
        // linklist is not empty
        // create temp Node 
        Node* temp = tail;
        // tail = tail->prev 
        tail = tail->prev;
        // tail->next = NULL;
        tail->next = NULL;
        // temp->prev = NULL;
        temp->prev = NULL;
        // delete temp node 
        delete temp;
    }
}

void deleteNodeAtPos(Node* &head,Node* &tail,int data,int pos) {
    int len = findLength(head);
    
    if(head == tail) {
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
    }
    
    if(pos == 1) {
        // deleteNodeAtHead(head,tail,data);
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
        
    } else if(pos == len) {
        // deleteNodeAtTail(head,tail,data);
        Node* prevNode = tail->prev;
        prevNode->next = NULL;
        tail->prev = NULL;
        delete tail;
        tail = prevNode;
        
    } else {
        // delete node at middle 
        // create temp Node 
        Node* temp = head;
        // set prev curr pointer
        Node* prevNode = NULL;
        Node* currNode = head;
        while(pos != 1) {
            pos--;
            prevNode = currNode;
            currNode = currNode->next;
        }
        Node* nextNode = currNode->next;
        
        // prevNode->next = currNode;
        prevNode->next = nextNode;
        // currNode->prev = prevNode->next;
        currNode->prev = NULL;
        currNode->next = NULL;
        nextNode->prev = prevNode;
        // delete currNode;
        delete currNode;
    }
}

int main()
{
    // Node* head = new Node(10);
    // printLinklist(head);
    // int getLength = findLength(head);
    // cout<<"The length of the linklist is : "<<getLength<<endl;
    
    // insert at head 
    Node* head = NULL;
    Node* tail = NULL;
    insertNodeAtHead(head,tail,40);
    insertNodeAtHead(head,tail,30);
    insertNodeAtHead(head,tail,20);
    insertNodeAtHead(head,tail,10);
    printLinklist(head);
    insertNodeAtTail(head,tail,2000);
    printLinklist(head);
    insertNodeAtPos(head,tail,67778,3);
    printLinklist(head);
    
    // deleteNodeAtHead working 
    // deleteNodeAtHead(head,tail,10);
    // printLinklist(head);
    
    // deleteNodeAtTail working
    // deleteNodeAtTail(head,tail,2000);
    // printLinklist(head);
    
    // deleteNodeAtPos working
    // deleteNodeAtPos(head,tail,67778,3);
    // printLinklist(head);
    
    // insert at pos 
    // Node* head = NULL;
    // Node* tail = NULL;
    // insertNodeAtPos(head,tail,1,1);
    // printLinklist(head);
    // insertNodeAtPos(head,tail,10,2);
    // printLinklist(head);
    // insertNodeAtPos(head,tail,2,2);
    // printLinklist(head);

    return 0;
}