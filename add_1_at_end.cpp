Node* reverseList( Node *head)
{
    Node* head1;
    Node* prev=NULL;
    Node* curr=head;
    Node* nxt=NULL;
    while(curr!=NULL)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    head1=prev;
    return head1;
}

Node* addOne(Node *head) 
{
    if(head->next==NULL)
    {
        if(head->data==9)
        head->data=10;
        else
        head->data=head->data+1;
        return head;
    }
    Node* root=reverseList(head);
    Node* a=root;
    Node* b=a;
    if(a->data==9)
    a->data=10;
    bool f=false;
    while(a->next!=NULL)
    {
        if(a->data==10 && f==false)
        {
            a->data=0;
            if(a->next->data<9)
            {
                a->next->data=a->next->data+1;
                break;
            }
            else
            {
                a->next->data=a->next->data+1;
            }
        }
        else
        {
            a->data=a->data+1;
            break;
        }
        a=a->next;
    }
    Node* c=reverseList(b);
    return c;
}

// Time - O(n)
// Space - O(1)