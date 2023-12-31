/*
   C-program to implement ordinary Queue with static and 
   dynamic memory allocation mechanisms using array storage representation
*/

#include<stdio.h>                      //Queue implementation (SMA & DMA) using array
#include<stdlib.h>                 

typedef struct static_queue{         // Structure being defined for SMA implementation of queue using array
    int a[100], left, right, size;
}queue;


typedef struct dynamic_queue{        // Structure being defined for DMA implementation of queue using array
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
    
    else if(s->right == s->size -1)
    {
        printf("\nQueue Overflow!!  :(\n");
    }
    
    else
    {
        s->right++;
        s->a[s->right] = b;
        printf("\n%d enqueued\n",s->a[s->right]);
    }
    
    return s;
}

queue* dequeue(queue*s)
{
    s->left++;
    if(s->left == 0)
       {
           s->left = -1;
           printf("\nQueue Underflow :(\n");
       }
   
    else if(s->left > s->right && s->right != -1)
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
        while(i <= s->right)
        {
            printf("%d\t",s->a[i++]);
        }
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
    
    else if(d->right == d->size -1)
    {
        printf("\nQueue Overflow!!  :(\n");
    }
    
    else
    {
        d->right++;
        *(d->p+d->right) = b;
        printf("\n%d enqueued\n",b);
    }
    
    return d;
}

Queue* Dequeue(Queue*d)
{
    d->left++;
    if(d->left == 0)
       {
           d->left = -1;
           printf("\nQueue Underflow :(\n");
       }
   
    else if(d->left > d->right && d->right != -1)
       {
           printf("\n%d dequeued\n",*(d->p+d->right));
           d->left = d->right = -1;
       }
       
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
        while(i <= d->right)
        {
            printf("%d\t",*(d->p+i++));
        }
    }
} 
