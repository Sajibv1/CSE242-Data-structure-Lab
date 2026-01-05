#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* next;
};
node* ncreator(int val)
{
   node* n1= new node();
    n1->next = NULL;
    n1->data = val;
    return n1;
}
void listprinter(node* head)
{
    node* cur = head;
    while(cur!=NULL)
    {

        cout<<cur->data<<" ";
        cur = cur->next;
    }

}
node *inserathead(int data, node*head)
{
    node* n1 = new node;
   n1 -> data = data;
    n1->next =head;
    head = n1;
return head;
}
void insertatlast (node*head,int data)
{
     node * cur = head;
    while(cur->next!=NULL)
    {

        cur = cur-> next;
    }
   node * n1 = ncreator(data) ;
    n1-> next = NULL;
    if(head==NULL) {head = n1;}
   cur-> next =n1;

}
int main()
{
node * n1 = ncreator(5);
node*head = n1;
cout<<"Initially our List"<<endl;
listprinter(n1);
cout<<endl;
 head = inserathead(7,head);

cout<<"after insert at head"<<endl;
listprinter(head);
insertatlast(n1,7);
cout<<"after insert at last"<<endl;
listprinter(head);

}
