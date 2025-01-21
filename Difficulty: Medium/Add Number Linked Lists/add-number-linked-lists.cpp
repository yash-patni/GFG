//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    void insertattail(Node* &head, Node* &tail, int digit) {
        Node* temp = new Node(digit);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* forward = NULL;
        while (curr != NULL) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    Node* add(Node* a, Node* b) {
        int carry = 0;
        Node* anshead = NULL;
        Node* anstail = NULL;
        while (a != NULL || b != NULL || carry != 0) {
            int value1 = (a != NULL) ? a->data : 0;
            int value2 = (b != NULL) ? b->data : 0;
            int sum = value1 + value2 + carry;
            int digit = sum % 10;
            insertattail(anshead, anstail, digit);
            carry = sum / 10;
            if (a != NULL) a = a->next;
            if (b != NULL) b = b->next;
        }
        return anshead;
    }

    Node* addTwoLists(Node* num1, Node* num2) {
        Node* Num1 = reverse(num1);
        Node* Num2 = reverse(num2);
        Node* ans = add(Num1, Num2);
       Node * final=reverse(ans);
       if(final->data==0){
           Node *w=final->next;
           Node* deletenode=final;
           deletenode->next=NULL;
           delete deletenode;
           final=w;
           
       }
       return final;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends