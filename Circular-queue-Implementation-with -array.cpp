#include<iostream>
struct queue {
    int front;
    int rear;
    int*array;
    int occupied;
    int capacity;
};

queue* createqueue(int cap)
{
    queue* q= new queue;
    q->front = 0;
    q->rear = 0;
    q->capacity=cap;
    q->array= new int[cap];
    q->occupied =0;
    return q;
}

bool isfull(queue*q)
{
    if(q-> occupied==q->capacity) return true;
    else return false;
}
bool isempty(queue *q)
{
    if(q->occupied==0) return true;
    else return false;
}
void enque (queue *q, int val)
{
    if(isfull(q)) std::cout<<"Queue is full!\n";
    else
    {
        q->array[q->rear]= val;
        q->rear = (q->rear + 1)%(q->capacity); //this makes our Queue Circular;
        q->occupied++;
    }
}
void deque (queue *q)
{
    if(isempty(q)) std::cout<<"Queue is Empty!\n";
    else {
        q->front= (q->front +1)%(q->capacity);
        q->occupied--;
    }
}

int peek(queue *q)
{   if(isempty(q)) {
        std::cout<<"Empty queue , nothing to display\n";
        return -101;
    }
    return q->array[q->front];
}



void display (queue *q)
{   if(isempty(q)) {
        std::cout<<"Empty queue , nothing to display\n";
    }
    else {
        int i = q->front;
        int count = 0;
        while(count < q->occupied) {
            std::cout<<q->array[i]<<"->";
            i = (i + 1) % q->capacity;
            count++;
        }
        std::cout<<"\n";
    }
}



int main()
{
    queue* q1 = NULL;
    while(1)
    {   std::cout<<"\n\n\nSelect an option\n1. Create a queue \n2.enqueue\n3.dequeue\n4.display queue\n5.peek\n6.terminate the programme";
        int op;
        std::cout<<"\nEnter an option here:  ";
        std::cin>>op;
        switch(op) {
        case 1:
    {   if(q1!=NULL) {
                std::cout<<"There exists a queue , creating another deletes previous one";
            }
            {   int cap;
                std::cout<<"Enter the capacity:";
                std::cin>>cap;
                q1 = createqueue(cap);
            }
        }
        break;
        case 2:
        {
            if(q1==NULL) {
                std::cout<<"There is no que , create a queue first";
            }
            else {
                std::cout<<"Enter the value , you want to Enque: ";
                int a ;
                std::cin>>a;
                enque(q1,a);
            }
        }
        break;
        case 3:
        {
            if(q1==NULL) {
                std::cout<<"There is no que , create a queue first";
            }
            else {
                deque(q1);
            }
        }
        break;
        case 4:
        {
            if(q1==NULL) {
                std::cout<<"There is no que , create a queue first";
            }
            else {
                display(q1);
            }
        }
        break;
        case 5:
        {
            if(q1==NULL) {
                std::cout<<"There is no que , create a queue first";
            }
            else {
                peek(q1);
            }
        }
        break;
        case 6:
        {
            return 0;
        }
        default:
        {
            std::cout<<"Invalid option selected\n";
        }
        }
    }
    
}
