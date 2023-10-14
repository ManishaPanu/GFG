class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        // The task is to complete this method
        if(!head || !head->next) return head;
        Node *dummy = new Node(0);
        Node *curr = head;
        Node *prev = dummy;
        while(curr && curr->next) {
            prev->next = curr->next;
            curr->next = prev->next->next;
            prev->next->next = curr;
            prev = curr;
            curr = curr->next;
        }
        return dummy->next;
    }
};
