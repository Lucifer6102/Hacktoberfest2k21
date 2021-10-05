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
int length(Node* head)
{
 int c=0;
 while(head!=NULL)
 {
     head=head->next;
     c++;
 }
 return c;
}
struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    Node* small;
    Node* large;
    int len1=length(first);
    int len2=length(second);
    if(len1>len2)
    {
        small=second;
        large=first;
    }
    else{
        small=first;
        large=second;
    }
    Node* f1=reverseList(small);
    Node* f2=reverseList(large);
    int carry=0;
    int sum;
    Node* start=NULL;
    Node* end=NULL;
    while(f1!=NULL || f2!=NULL)
    {
        int a=f1!=NULL?f1->data:0;
        int b=f2!=NULL?f2->data:0;
        sum=carry+(a+b);
        carry=sum>=10?1:0;
        sum=sum%10;
        if(start==NULL)
        {
            start=new Node(sum);
            end=start;
        }
        else
        {
            end->next=new Node(sum);
            end=end->next;
        }
        
        if(f1!=NULL)
        f1=f1->next;
        if(start!=NULL)
        f2=f2->next;
    }
    if(carry>0)
    end->next=new Node(carry);
    start=reverseList(start);
    return start;  
}

// Time - O(n)+O(m)
// Space - O(n)+O(m)