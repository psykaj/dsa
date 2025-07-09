// single Linklist 
#include <iostream>
using namespace std;

class Node {
    public:    
    int data;
    Node* next;
    
    // default
    Node() {
        // cout<<"Default ctor"<<endl;
        this->next = NULL;
    }
    
    Node(int data) {
        // cout<<"Paramaterized ctor"<<endl;
        this->data = data;
        this->next = NULL;
    }
    
    // Dtor for printing the deleted element 
    // ~Node() {
    //     cout<<"Destructor called : "<<this->data<<endl;
    // }

    // dtor for print & free memory space for deleted element 
    ~Node() {
        int value = this->data;
        // memory free 
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for data : "<<value<<endl;
    }
};

void printLinklist(Node* head) {
    Node* temp = head;
    
    while(temp != NULL) {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}

int getLength(Node* head) {
    int count = 0;
    Node* temp = head;
    
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Pass by reference karna hota hai 
void insertAtHead(Node* &head,Node* &tail,int data) {
    if(head == NULL) {
        // Linklist is empty 
        
        // create new node 
        Node* newNode = new Node(data);
        // change head pointer 
        head = newNode;
        tail = newNode;
    } else {
        // create new Node 
        Node* newNode = new Node(data);
        
        // shift head pointer
        newNode->next = head;
        
        // change head pointer 
        head = newNode;
    }
}

void insertAtTail(Node* &head,Node* &tail,int data) {
    if(head == NULL) {
        // empty case 
        // 1. create new node 
        Node* newNode = new Node(data);
        // 2. change head,tail pointer (update)
        head = newNode;
        
        tail = newNode;
    } else {
        // non-empty case
        // 1. create new Node
        Node* newNode = new Node(data);
        // 2. shift tail pointer 
        tail->next = newNode;
        // 3. change tail pointer 
        tail = newNode;
    }
}

void createTail(Node* &head,Node* &tail) {
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    tail = temp;
}

void insertAtPos(Node* &head,Node* &tail,int data,int position) {
    int length = getLength(head);
    // if(position < 1) {
    //     cout<<"cannot insert value, Please enter a valid number"<<endl;
    //     return;
    // }
    // else if(position > length) {
    //     cout<<"cannot insert value, Please enter a valid number"<<endl;
    //     return;
    // }
    
    if(position <= 1) {
        insertAtHead(head,tail,data);
        // length + 1 karna hai important point remember
    } else if(position > length) {
        insertAtTail(head,tail,data);
    } else {
        // create a new Node 
        Node* newNode = new Node(data);
        // traverse prev/curr pointer 
        // optimisation -> solve using single / prev pointer 
        Node* prev = NULL;
        Node* curr = head;
        while(position != 1) {
            prev = curr;
            curr = curr->next;
            position--;
        }
        // attach prev->next to newNode
        prev->next = newNode;
        // attach newNode->next to curr
        newNode->next = curr;
    }
}

void deleteNode(Node* &head,Node* &tail,int pos) {
    // base case 
    if(head == NULL) {
        cout<<"Cannot delete, cause LL is empty"<<endl;
        return;
    }
    
    // single element case 
    if(head == tail) {
        // create temp node 
        Node* temp = head;
        // delete temp 
        delete temp;
        
        // make head,tail null 
        head = NULL;
        tail = NULL;
        return;
    }
    
    int length = getLength(head);
    
    if(pos == 1) {
        // delete from head 
        // create a temp Node for head 
        Node* temp = head;
        // update head 
        // aslo we can write head->next 
        head = temp->next;
        // make temp->next = null 
        temp->next = NULL;
        // delete temp Node 
        delete temp;
    } else if(pos == length) {
        // delete from tail 
        // traverse 2 last Node prev 
        Node* prev = head;
        while(prev->next != tail) {
            prev = prev->next;
        }
        // prev->next to null 
        prev->next = NULL;
        // delete tail Node (which is isolated)
        delete tail;
        // make tail to prev 
        tail = prev;
    } else {
        // middle case 
        Node* prev = NULL;
        Node* curr = head;
        while(pos != 1) {
            pos--;
            prev = curr;
            curr = curr->next;
        }
        
        // prev->next ko curr->next ko add karo 
        prev->next = curr->next;
        
        // curr->next ko null karo 
        curr->next = NULL;
        
        // delete curr Node 
        delete curr;
    }
}

int main()
{
    // static objcet creation
    // Node obj;
    
    // creation of new Linklist
    Node* head = NULL;
    Node* tail = NULL;
    
    insertAtHead(head,tail,50);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,10); 
    printLinklist(head);
    
    // int position = 4;
    // insertAtPos(head,tail,45,position);
    // printLinklist(head);
    
    // delete head 
    // deleteNode(head,tail,1);
    
    // delete tail 
    // deleteNode(head,tail,5);
    
    // delete mid 
    deleteNode(head,tail,2);
    printLinklist(head);
    
    
    // Paramaterized objcet creation
    // Node* first = new Node(10);
    // Node* second = new Node(20);
    // Node* third = new Node(30);
    // Node* fourth = new Node(40);
    // Node* fifth = new Node(50);
    // Node* sixth = new Node(60);
    // Node* tail = sixth;
    
    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;
    // fifth->next = sixth;
    
    // // Linklist created 
    
    // // print Linklist
    // Node* head = first;
    // cout<<"Printing the linklist : "<<endl;
    // printLinklist(head);
    
    // int ans = getLength(head);
    // cout<<"Length of linklist : "<<ans<<endl;
    
    // // Insert at head 
    // insertAtHead(head,tail,500);
    // printLinklist(head);
    
    // // Insert at tail 
    // insertAtTail(head,tail,600);
    // cout<<"Printing insert at tail"<<endl;
    // printLinklist(head);
    
    // create tail 
    // tail maintain karte chal rahe hai
    // createTail(head,tail);
    // cout<<"Tail Created!!"<<endl;
    
    return 0;
}