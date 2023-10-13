class Solution
{
    public:
    void rearrange(struct Node *odd)
    {
        //add code here
        Node* head = odd;
        Node* nextt = NULL;
        Node* prev = NULL;
        while(head->next && head->next->next) {
            prev = head->next;
            head->next = head->next->next;
            prev->next = nextt;
            head = head->next;
            nextt = prev;
        }
        if(head->next == NULL)
            head->next = nextt;
        else if(head->next->next == NULL)
            head->next->next = nextt;
        
    }
};
