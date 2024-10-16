//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
        vector<Node*> vc;
        if(!head->next)
        {
            vc.push_back(head);
            return vc;
        }
        // define pointer for every alternate list
        // store the heads in the vector
        Node* h1 = head;
        vc.push_back(h1);
        Node* h2 = head->next;
        vc.push_back(h2);
        // another pointer running through original list
        Node* h = h2->next;
        bool odd = false;
        while(h)
        {
            // even times - add next element to list of h1
            if(!odd)
            {
                h1->next = h;
                h1 = h;
                // increase next element
                h = h1->next;
                odd = true;
            }
            // odd times - add next element to list of h2
            else
            {
                h2->next = h;
                h2 = h;
                // increase next element
                h = h2->next;
                odd = false;
            }
        }
        // reset next pointers of the last elements
        h1->next = NULL;
        h2->next = NULL;
        return vc;
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

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

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends