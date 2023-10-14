class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        // Code here
        Node* front = head;
        Node* prev = NULL;
        while(head->next != NULL && data > head->data) {
            prev = head;
            head = head->next;
        }
        
        Node *newNode = new Node(data);
        
        //handling insertion at last
        if(head->next == NULL && data > head->data) {
            head->next = newNode;
            newNode->next = NULL;
            return front;
        }
        
        //handdling insertion in front
        if(head == front) {
            newNode->next = head;
            return newNode;
        }
        
        //insertion in between
        prev->next = newNode;
        newNode->next = head;
        return front;
    }
};
