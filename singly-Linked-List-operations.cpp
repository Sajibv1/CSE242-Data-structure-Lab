#include<bits/stdc++.h>
using namespace std;

//structure
struct node
{   int data;
    node* next;
};


//Node Create Function:

node* nodeCreator(int val)
{
    node* n1 = new node();
    n1-> data = val;
    n1->next=NULL;
    return n1;
}


//Display linked list:


void display(node* head)
{
    node* cur = head;
    while(cur!=NULL)
    {

        cout<<cur->data<<" -> ";
        cur = cur->next;
    }
    cout<<"NULL"<<endl;
}


//Insert a node at the beginning:

void insathead(node *&head,int val)
{
    node * n1 = nodeCreator(val);
    n1 -> next =head;
    head = n1;
}

//Insert a node at the end of the list:


void inslast(node *&head,int val)
{
    if(head==NULL)
    {
        insathead(head,val);
        return;
    }
    node*cur = head;
    while(cur->next!=NULL)
    {
        cur= cur->next;
    }
    cur-> next = nodeCreator(val);

}
//Insert a node at a specific position:
void insatpos(node*&head,int val,int pos)
{
    node * cur = head;
    int i=1;
    if (pos ==1) {
        insathead(head,val);
        return;
    }
    while(i<pos-1)
    {   if(cur==NULL) {
            cout<<" Invalid position to Insert \n";
            return;
        }
        cur = cur-> next;
        i++;
    }

    if(cur->next== NULL) {
        inslast(head,val);
        return;
    }

    node *n1 = nodeCreator(val);
    n1-> next = cur->next;
    cur->next =n1;

}

void delFirstnode(node *&head)
{   if(head == NULL) {
        cout<<"Nothing to Delete"<<endl;
        return;
    }
   
    head = head ->next;
 
}
//Delete a node from the end:


void dellastNode(node *&head)
{   if(head == NULL) {
        cout<<"Nothing to Delete"<<endl;
        return;
    }
    if(head->next==NULL) {
        head=NULL;
        return;
    }
    node*cur =head;
    while(cur->next->next!=NULL)
    {
        cur = cur->next;
    }
    cur->next =NULL;
}

//Delete a node containing a given value:


void delbyvalue (node* &head,int val)
{   if (head == NULL) return;
    if (head->data==val)
    {
        head = head ->next;
        return;
    }
    node * cur = head;

    while(cur->next!=NULL)
    {
        if(cur->next->data== val)
        {
            cur ->next = cur->next->next;
            return;
        }
        cur = cur->next;

    }
    cout<<"Value Not found in the List"<<endl;

}
int main()
{

    node* head = nodeCreator(5);
    display(head);
    cout<<"\n insert at head:\n";
    insathead(head,1);
    display(head);
    cout<<"\nafter insert at last:\n";
    inslast(head,90);

    display(head);
    cout<<"\nafter insert at position 2:\n";
    insatpos(head,44,2);
    display(head);
    cout<<"\nafter insert at position 3:\n";
    insatpos(head,17,3);
    display(head);
    cout<<"\ndelete the first node:\n";
    delFirstnode(head);
    display(head);
    cout<<"\nafter delete the last:\n";
    dellastNode(head);

    display(head);
    cout<<"\nafter delete value 17 \n";
    delbyvalue(head,17);
    display(head);
}
