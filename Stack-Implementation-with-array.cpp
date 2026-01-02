#include<bits/stdc++.h>
using namespace std;

struct Stack {
    int top;
    int size;
    int *array;
};

Stack* createstack(int cap)
{
    Stack* newstack = new Stack;
    newstack -> size = cap;
    newstack -> top = -1;
    newstack -> array = new int[cap];
    cout<<" Successfully Created a stack!"<<endl;
    return newstack;
}


bool isempty (Stack* st)
{
    if(st-> top==-1) return true;
    else return false;
}

bool isfull (Stack*st)
{
    if(st->top == (st->size -1) ) {
        return true ;
    }
    else return false;
}

int Peek(Stack*st)
{
    if(isempty(st))
    {
        cout<<"The Stack is Empty "<<endl;
        return -1000;
    }
    else {
        return  st->array[st->top];
    }
}

void push(Stack *st,int val)
{
    if(isfull(st))
    {
        cout<<"Stack Is Full!"<<endl;
    }

    else {

        st->top +=1;
        st->array[st->top]= val;
        cout<<"Push successful!";
    }
}


void pop(Stack *st)
{
    if(isempty(st))
    {
        cout<<"Stack is Empty , Insert something , then try to pop!"<<endl;
    }
    else {
        st->top --; 
        cout<<"Pop successful!";
    }
}

void printstack (Stack * st)

{
    if(isempty(st))
    {
        cout<<"Empty Stack,there is  nothing to print. push something first "<<endl;
    }
    else {
        for(int i=st->top; i>=0; i--)
        {
            cout<<st->array[i]<<endl;
            cout<<"↓"<<endl;
        }
    }
    cout<<endl;
}


int main()
{

    Stack* stack1=NULL;

    while(1)
    {



        cout<<"\n\nSelect An option:\n1.Create an Stack \n 2.Push \n 3.Pop \n 4.peek() \n 5. Print the stack \n 6.terminate Programme"<<endl;
        cout<<" Enter an option here: ";
        int op;
        cin>>op;
        switch (op)
        {
        case 1:

        { 
             if (stack1 != NULL) {
        delete[] stack1->array;
        delete stack1;          
    }
          cout<<" Enter stack size:";
            int size;
            cin>>size;
            stack1 = createstack (size);
        }
        break;
        case 2:
        {
            if(stack1==NULL) cout<<"No stack created Yet, create a stack"<<endl;
            else {
                cout<<"Enter a value to push: ";
                int z;
                cin>>z;
                push(stack1,z);

            }
        }
        break;

        case 3:

        {

            if(stack1==NULL) cout<<"No stack created Yet, create a stack"<<endl;
            else {
                pop(stack1);
            }

        }

        break;

        case 4:
        {   if(stack1==NULL) cout<<"No stack created Yet, create a stack"<<endl;
            cout<<Peek(stack1)<<endl;

        }
        break;
        case 5:
        {   if(stack1==NULL) cout<<"No stack created Yet, create a stack"<<endl;
            else {
                printstack(stack1);
            }

        }
        break;
        case 6:
        {
            return 0;
        }

        break;
        default:
            cout<<"Invalid option selected "<<endl;

        }

    }
}
