/*
   C-program to implement Circular Queue with static and
dynamic memory allocation mechanisms using array storage
representation.
*/

#include<stdio.h>                      //Circular queue implementation (SMA & DMA) using array
#include<stdlib.h>                 

typedef struct static_queue{         // Structure being defined for SMA implementation of circular queue using array
    int a[100], left, right, size;
}queue;


typedef struct dynamic_queue{        // Structure being defined for DMA implementation of circular queue using array
    int size,left,right,*p;
}Queue;

//////////////////////////////
// SMA Operations //
queue* enqueue(queue*,int);
queue* dequeue(queue*);
void   display_static(queue*);
queue* initialize(queue*);


/////////////////////////////
// DMA Operations //
Queue* Enqueue(Queue*,int);
Queue* Dequeue(Queue*);
void   display_dynamic(Queue*);
Queue* Initialize(Queue*);

int main()
{
    int choice;
    
    queue*s = malloc(sizeof(queue));
    printf("Enter the size of queue for SMA operations:\t");
    scanf("%d",&s->size);
    s = initialize(s); 
    
    Queue*d = malloc(sizeof(Queue));
    printf("\nEnter the size of queue for DMA operations:\t");
    scanf("%d",&d->size);
    d->p = (int*)malloc(sizeof(int));
    d = Initialize(d);
    
    for(;;)
    {
        printf("\n\n1.Queue(SMA)\n2.Queue(DMA)\n3.Exit\nEnter your choice:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nSMA operations>>>\n1.Enqueue\n2.Dequeue\n3.Display\nEnter your choice:\t\n");
                    scanf("%d",&choice);
                    switch(choice)
                    {
                        case 1: printf("\nEnter the data for enqueue operation:\t"); scanf("%d",&choice);
                                s = enqueue(s,choice); break;
                        case 2: s = dequeue(s); break;
                        case 3: display_static(s); break;
                        default: printf("\nInvalid Choice!!\n");
                    } break;
                    
            case 2: printf("\nDMA operations>>>\n1.Enqueue\n2.Dequeue\n3.Display\nEnter your choice:\t\n");
                    scanf("%d",&choice);
                    switch(choice)
                    {
                        case 1: printf("\nEnter the data for enqueue operation:\t"); scanf("%d",&choice);
                                d = Enqueue(d,choice); break;
                        case 2: d = Dequeue(d); break;
                        case 3: display_dynamic(d); break;
                        default: printf("\nInvalid Choice!!\n");
                    }break;
                    
            case 3: exit(0);        
                    
            default: printf("\nInvalid Choice!!\n");        
        }
        
    }
    return 0;
}

/***  Static Operations ***/

queue* initialize(queue*s)
{
    s->left = -1;
    s->right = -1;
    
    return s;
}

queue* enqueue(queue*s, int b)
{
    if(s->left == -1 && s->right == -1)
    {
        s->left = s->right = 0;
        s->a[s->left] = b;
        printf("\n%d enqueued\n",s->a[s->left]);
    }
    
    else if((s->right+1) % s->size == s->left)
    {
        printf("\nQueue Overflow!!  :(\n");
    }
    
    else
    {
        s->right = (s->right+1) % s->size; 
        s->a[s->right] = b;
        printf("\n%d enqueued\n",s->a[s->right]);
    }
    
    return s;
}

queue* dequeue(queue*s)
{
    s->left = (s->left + 1) % s->size;
    if(s->right == -1)
       {
           s->left = -1;
           printf("\nQueue Underflow :(\n");
       }
   
    else if(s->left -1 == s->right && s->right != -1)
       {
           printf("\n%d dequeued\n",s->a[s->right]);
           s->left = s->right = -1;
       }
       
    else if(s->left == 0 && s->right == s->size-1)
        {
           printf("\n%d dequeued\n",s->a[s->right]);
           s->left = s->right = -1;   
        }
        
    else
       {
           printf("\n%d dequeued\n",s->a[s->left-1]);
       }   
   
   return s;
}

void display_static(queue*s)
{
    if(s->left == -1)
    {
        printf("\nQueue is empty!!\n");
    }
    
    else
    {   int i = s->left;
        printf("\nCurrent status of the queue is...\n");
        do
        {
            printf("%d\t",s->a[i]);
            i = (i+1)%(s->size);
        }while(i != (s->right+1)%(s->size));
    }
}

/*** Dynamic Operations ***/

Queue* Initialize(Queue*d)
{
    d->left = -1;
    d->right = -1;
    
    return d;
}

Queue* Enqueue(Queue*d, int b)
{
    if(d->left == -1 && d->right == -1)
    {
        d->left = d->right = 0;
        *(d->p+d->left) = b;
        printf("\n%d enqueued\n",b);
    }
    
    else if((d->right+1) % d->size == d->left)
    {
        printf("\nQueue Overflow!!  :(\n");
    }
    
    else
    {
        d->right = (d->right+1) % d->size;
        *(d->p+d->right) = b;
        printf("\n%d enqueued\n",b);
    }
    
    return d;
}

Queue* Dequeue(Queue*d)
{
    d->left = (d->left + 1) % d->size;
    if(d->right == -1)
       {
           d->left = -1;
           printf("\nQueue Underflow :(\n");
       }
   
    else if(d->left-1 == d->right && d->right != -1)   //      |   |   |   |   |   |   |   |
       {                                               //                              ^
           printf("\n%d dequeued\n",*(d->p+d->right)); //                              |  (when initially right and left both are pointing to any element of the queue, except the last element)
           d->left = d->right = -1;                    // a case of single element present in the queue
       }
       
    else if(d->left == 0 && d->right == d->size-1)    // when, intitially left and right were pointing to the last element  
        {
           printf("\n%d dequeued\n",*(d->p+d->right));
           d->left = d->right = -1;   
        }                                             // a case of single element present in the queue
       
    else
       {
           printf("\n%d dequeued\n",*(d->p+d->left-1));
       }   
   
   return d;
}

void display_dynamic(Queue*d)
{
    if(d->left == -1)
    {
        printf("\nQueue is empty!!\n");
    }
    
    else
    {   int i = d->left;
        printf("\nCurrent status of the queue is...\n");
        do
        {
            printf("%d\t",*(d->p+i));
            i = (i+1)%(d->size);
        }while(i != (d->right+1)%(d->size));
    }
}
