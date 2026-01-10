#include<bits/stdc++.h>
using namespace std;

//structure
struct node
{   int data;
    node* next;
};

node* nodeCreator(int val)
{
    node* n1 = new node();
    n1-> data = val;
    n1->next=NULL;
    return n1;
}



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


//Linked List Reverse:

void listrev (node *&head)
{

    node * curr = head ;
    node * prev = nullptr;
    node * nextNode ;

    while(curr!=NULL)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    head = prev;
}

// Linked List middle element:
void midNodefinder(node*& head)
{
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "middle Element:" << slow->data << endl;
}

int main()
{   //List Creation:
    node * head = nodeCreator(5);
    head -> next = nodeCreator(7);
    head -> next -> next = nodeCreator(9);


    cout<<"Initial Linked list:\n";
    display(head);
    cout<<"After reverse: "<<endl;
    listrev(head);
    display(head);
    midNodefinder(head);

}
