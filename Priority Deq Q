/*   C-program to implement Priority Queue [Dequeue] using static & dynamic memory allocation  */

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
    int data;
    if(s->left == -1 && s->right == -1)
    {
        printf("\nEnter the data:\t");
        scanf("%d",&data);
        s->left = s->right = 0;
        s->a[s->left] = data;
        printf("\n%d enqueued\n",s->a[s->left]);
        return s;
    }
    
    else if((s->right+1) % s->size == s->left)
    {
        printf("\nQueue Overflow!!  :(\n");
        return s;
    }
    
    else
    {
        printf("\nEnter the data:\t");
        scanf("%d",&data);
        s->right = (s->right+1) % s->size; 
        s->a[s->right] = data;
        printf("\n%d enqueued\n",s->a[s->right]);
        return s;
    }
    
    return s;
}

queue* deQ(queue*s)
{
    if(s->right == -1)
    {
        printf("\nQueue Underflow !!\n");
        return s;
    }
    else if(s->left == s->right)
    {
        printf("\n%d dequeued...\n",s->a[s->left]);
        s->left = s->right = -1;
        return s;
    }
    else
    {
       int min = s->a[s->left], i = s->left, index = s->left;
       do
       {
           if(s->a[i] < min)
           {
               min = s->a[i];
               index = i;
           }
            i = (i + 1)%(s->size);
       }while(i != (s->right + 1)%(s->size));
       if(index == s->left)
       {
           printf("\n%d dequeued...\n",s->a[s->left]);
           s->left = (s->left + 1)%(s->size);
           return s;
       }
       
       if(index == s->right && s->right == 0)
       {
           printf("\n%d dequeued...\n",s->a[s->right]);
           s->right = s->size - 1;
           return s;
       }
       
       if(index == s->right && s->right != 0)
       {
           printf("\n%d dequeued...\n",s->a[s->right]);
           s->right = (s->right - 1)%(s->size);
           return s;
       }
       else
       {
           i = index;
           printf("\n%d dequeued...\n",s->a[index]);
           while(i != s->right)
           {
               s->a[i] = s->a[(i + 1)%(s->size)];
               i = (i + 1)%(s->size);
           }
           s->right = (s->right - 1)%(s->size);
           return s;
       }
       
    }
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
        printf("\n");
    }
}

Queue* ENq(Queue*d)
{
    int data;
    if(d->left == -1 && d->right == -1)
    {
        printf("\nEnter the data:\t");
        scanf("%d",&data);
        d->left = d->right = 0;
        *(d->p+d->left) = data;
        printf("\n%d enqueued\n",data);
    }
    
    else if((d->right+1) % d->size == d->left)
    {
        printf("\nQueue Overflow!!  :(\n");
    }
    
    else
    {
        printf("\nEnter the data:\t");
        scanf("%d",&data);
        d->right = (d->right+1) % d->size;
        *(d->p+d->right) = data;
        printf("\n%d enqueued\n",data);
    }
    
    return d;
}

Queue* DEq(Queue*s)
{
    if(s->right == -1)
    {
        printf("\nQueue Underflow !!\n");
        return s;
    }
    else if(s->left == s->right)
    {
        printf("\n%d dequeued...\n",*(s->p + s->left));
        s->left = s->right = -1;
        return s;
    }
    else
    {
       int min = *(s->p + s->left), i = s->left, index = s->left;
       do
       {
           if(*(s->p + i) < min)
           {
               min = *(s->p + i);
               index = i;
           }
            i = (i + 1)%(s->size);
       }while(i != (s->right + 1)%(s->size));
       if(index == s->left)
       {
           printf("\n%d dequeued...\n",*(s->p + s->left));
           s->left = (s->left + 1)%(s->size);
           return s;
       }
       
       if(index == s->right && s->right == 0)
       {
           printf("\n%d dequeued...\n",*(s->p + s->right));
           s->right = s->size - 1;
           return s;
       }
       
       if(index == s->right && s->right != 0)
       {
           printf("\n%d dequeued...\n",*(s->p+s->right));
           s->right = (s->right - 1)%(s->size);
           return s;
       }
       else
       {
           i = index;
           printf("\n%d dequeued...\n",*(s->p + index));
           while(i != s->right)
           {
               *(s->p + i) = *(s->p + ((i + 1)%(s->size))); 
               i = (i + 1)%(s->size);
           }
           s->right = (s->right - 1)%(s->size);
           return s;
       }
       
    }
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
        printf("\n");
    }
}
