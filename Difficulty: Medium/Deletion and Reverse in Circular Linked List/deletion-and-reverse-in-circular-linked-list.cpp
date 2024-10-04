//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}


// } Driver Code Ends
class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
       Node *curr = head, *prev = NULL, *nex;
       while (curr != NULL) {
            nex = curr->next;
      
            curr->next = prev;
      
            prev = curr;
            curr = nex;
        }
        return prev->next;
    } 

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        if(head->data == key){
           Node* hh = head;
           while(hh->next != head) hh = hh->next;
           
           hh->next = head->next;
           return head->next;
        }
        // The case in which the value of the head doesn't matches the key value.
        Node* pp = head;
        Node* loop = head->next;
        while(loop != head){
            if(loop->data == key){
                pp->next = loop->next;
                return head;
            }
            loop = loop->next;
            pp = pp->next;
        }
        
        return head;
    }


};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Reading input into a vector
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
    }
    return 0;
}

// } Driver Code Ends