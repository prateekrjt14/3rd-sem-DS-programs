/*   C-program to implement Priority Queue [Enqueue] using static & dynamic memory allocation  */

#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int left, right, size, a[100];
}queue;

typedef struct Queue{
    int *p, left, right, size;
}Queue;

queue* enQ(queue*);
queue* deQ(queue*);
void   display_static(queue*);

Queue* ENq(Queue*);
Queue* DEq(Queue*);
void   display_dynamic(Queue*);

int main()
{
    int choice;
    
    queue*s = (queue*)malloc(1*sizeof(queue));
    printf("Enter the size of the SMA queue:\t");
    scanf("%d",&s->size);
    s->left = s->right = -1;
    
    Queue*d = (Queue*)malloc(1*sizeof(Queue));
    printf("\nEnter the size of the DMA queue:\t");
    scanf("%d",&d->size);
    d->left = d->right = -1;
    d->p = (int*)malloc((d->size)*sizeof(int));
    
    for(;;)
    {
        printf("\n1.SMA PQ\n2.DMA PQ\n3.Exit\nEnter your choice:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\n>>> SMA PQ >>>\n1.PEnqueue\n2.Dequeue\n3.Display Queue\nEnter your choice:\t");
                    scanf("%d",&choice);
                    switch(choice)
                    {
                        case 1: s = enQ(s); break;
                        case 2: s = deQ(s); break;
                        case 3: display_static(s); break;
                        default: printf("\nInvalid choice!!\n");
                    }break;
            
            case 2: printf("\n>>> DMA PQ >>>\n1.PEnqueue\n2.Dequeue\n3.Display Queue\nEnter your choice:\t");
                    scanf("%d",&choice);
                    switch(choice)
                    {
                        case 1: d = ENq(d); break;
                        case 2: d = DEq(d); break;
                        case 3: display_dynamic(d); break;
                        default: printf("\nInvalid choice!!\n");
                    }break;  
            
            case 3: exit(0);
            
            default: printf("\nnInvalid choice!!\n");
        }
    }
    return 0;
}

queue* enQ(queue*s)
{
    int data; int i,j;
    if((s->right + 1)%(s->size) == s->left)
    {
        printf("\nQueue Overflow !!\n");
        return s;
    }
    
    if(s->left == -1)
    {
        s->left = 0;
        s->right = 0;
        printf("\nEnter the data:\t");
        scanf("%d",&data);
        s->a[0] = data;
        return s;
    }
    
    printf("\nEnter the data:\t");
    scanf("%d",&data);
    
    if(s->left == s->right)
    {  
        s->right = (s->right + 1)%(s->size);
        if(s->a[s->left] > data )
        {
            s->a[s->right] = s->a[s->left];
            s->a[s->left] = data;
            return s;
        }
        else
          s->a[s->right] = data;
          return s;
    }
    
    else
    {   
        i = s->left;
        while(i != (s->right + 1)%(s->size) && data > s->a[i])
        {
            i++;
        }
        
        if(i == (s->right + 1)%(s->size))
        {
            s->right = (s->right + 1)%(s->size);
            s->a[s->right] = data;
            return s;
        }
        
        j = s->right;
        
        while(j != (i - 1)%(s->size))
        {
            s->a[j+1] = s->a[j];
            j = (j-1)%(s->size);
        }
        s->a[i] = data;
        s->right = (s->right + 1)%(s->size);
        return s;
    }
    
}

queue* deQ(queue*s)
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

Queue* ENq(Queue*s)
{
    int data; int i,j;
    if((s->right + 1)%(s->size) == s->left)
    {
        printf("\nQueue Overflow !!\n");
        return s;
    }
    
    if(s->left == -1)
    {
        s->left = 0;
        s->right = 0;
        printf("\nEnter the data:\t");
        scanf("%d",&data);
        *(s->p) = data;
        return s;
    }
    
    printf("\nEnter the data:\t");
    scanf("%d",&data);
    
    if(s->left == s->right)
    {  
        s->right = (s->right + 1)%(s->size);
        if(*(s->p + s->left) > data )
        {
            *(s->p + s->right) = *(s->p + s->left);
            *(s->p + s->left) = data;
            return s;
        }
        else
          *(s->p + s->left) = data;
          return s;
    }
    
    else
    {   
        i = s->left;
        while(i != (s->right + 1)%(s->size) && data > *(s->p + i))
        {
            i++;
        }
        
        if(i == (s->right + 1)%(s->size))
        {
            s->right = (s->right + 1)%(s->size);
            *(s->p + i) = data;
            return s;
        }
        
        j = s->right;
        
        while(j != (i - 1)%(s->size))
        {
            *(s->p + j + 1) = *(s->p + j);
            j = (j-1)%(s->size);
        }
        *(s->p + i) = data;
        s->right = (s->right + 1)%(s->size);
        return s;
    }
    
}

Queue* DEq(Queue*d)
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
