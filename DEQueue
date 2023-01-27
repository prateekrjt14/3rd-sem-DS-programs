/* C-program to implement double ended queue using SMA & DMA allocations  */
#include<stdio.h>
#include<stdlib.h>

/////////////////////////////////////////////////////////////////////////////
typedef struct stQ{
                                       int left, right, size, a[100];
}queue;

////////////////////////////////////////////////////////////////////////////
typedef struct dynQ{
                                         int left, right, size,*p;
}Queue;

queue* frontEnqueue(queue*,int);
queue* rearEnqueue(queue*,int);
queue* frontDequeue(queue*);
queue* rearDequeue(queue*);
queue* initialize(queue*);
void   display_sma(queue*);

Queue* FrontEnqueue(Queue*,int);
Queue* RearEnqueue(Queue*,int);
Queue* FrontDequeue(Queue*);
Queue* RearDequeue(Queue*);
Queue* Initialize(Queue*);
void   display_dma(Queue*);

int main()
{
    int choice;
    queue*s = (queue*)malloc(sizeof(queue));
    printf("\nEnter the size for SMA operations:\t");
    scanf("%d",&s->size);
    s = initialize(s);

    Queue*d = (Queue*)malloc(sizeof(Queue));
    printf("\nEnter the size for DMA operations:\t");
    scanf("%d",&d->size);
    d->p = (int*)malloc((d->size)*sizeof(int));
    d = Initialize(d);

    for(;;)
    {
          printf("\n1.DEQueue(SMA)\n2.DEQueue(DMA)\n3.Exit\n4.Enter your choice:\t");
          scanf("%d",&choice);
          switch(choice)
          {
                case 1: printf("\nSMA operations>>>\n1.Front ENQ\n2.Rear ENQ\n3.Front DQ\n4.Rear DQ\n5.Display Queue\nEnter your choice:\t"); scanf("%d",&choice);
                 switch(choice)
{
    case 1: printf("\nEnter the data:\t"); scanf("%d",&choice);
   s = frontEnqueue(s,choice); break;

    case 2: printf("\nEnter the data:\t"); scanf("%d",&choice);
   s = rearEnqueue(s,choice); break;

    case 3: s = frontDequeue(s); break;

    case 4: s = rearDequeue(s); break;
    
    case 5: display_sma(s); break;

    default: printf("\nInvalid Choice\n");
}break;

                 case 2: printf("\nDMA operations>>>\n1.Front ENQ\n2.Rear ENQ\n3.Front DQ\n4.Rear DQ\n5.Display Queue\nEnter your choice:\t"); scanf("%d",&choice);
                 switch(choice)
{
    case 1: printf("\nEnter the data:\t"); scanf("%d",&choice);
   d = FrontEnqueue(d,choice); break;

    case 2: printf("\nEnter the data:\t"); scanf("%d",&choice);
   d = RearEnqueue(d,choice); break;

    case 3: d = FrontDequeue(d); break;

    case 4: d = RearDequeue(d); break;
    
    case 5: display_dma(d); break;

    default: printf("\nInvalid Choice\n");
}break;

                   case 3: exit(0);

                   default : printf("\nInvalid Choice\n");
          }
    }

    return 0;
}

queue*initialize(queue*s)
{
    s->left = s->right = -1;
    return s;
}

queue*frontEnqueue(queue*s, int a)
{
    if(s->left == -1 && s->right == -1)
    {
         s->left = s->right = 0;
         s->a[s->left] = a;
         printf("\n%d enqueued...\n",s->a[s->left]);
    }
   
    else if(s->left == 0 && s->right == s->size -1)
    {
         printf("\nQueue Overflow !!\n");
    }
   
    else if(s->left == 0 && s->right != s->size-1)
    {
         int i;
         for(i = s->right; i >= s->left; i--)
         {
              s->a[i+1] = s->a[i];
         }
         s->right++;
         s->a[0] = a;
         printf("\n%d enqueued...\n",s->a[s->left]);
    }

     else
     {
          s->left--;
          s->a[s->left] = a;
          printf("\n%d enqueued...\n",s->a[s->left]);
     }

      return s;
}

queue*rearEnqueue(queue*s, int a)
{
    if(s->left == -1  && s->right == -1)
    {
         s->left = s->right = 0;
         s->a[s->left] = a;
         printf("\n%d enqueued...\n",s->a[s->left]);
    }
   
    else if(s->right == s->size - 1 )
    {
         printf("\nQueue Overflow !!\n");
    }
   
    else
   {
        s->right++;
        s->a[s->right] = a;
        printf("\n%d enqueued...\n",s->a[s->right]);
   }

      return s;
}

queue* frontDequeue(queue*s)
{
     if(s->left == -1 && s->right == -1)
     {
          printf("\nQueue Underflow !!\n");
     }
     
     else if(s->left == s->right)
     {
          printf("\n%d dequeued\n",s->a[s->left]);
          s->left = s->right = -1;
     }

     else
    {
          printf("\n%d dequeued\n",s->a[s->left]);
          s->left++;
    }

     printf("\n%d\n",s->a[s->left]);

     return s ;
}

queue* rearDequeue(queue*s)
{
     if(s->right == -1)
     {
          printf("\nQueue Underflow !!\n");
     }

     else if(s->left == s->right)
     {
          printf("\n%d dequeued\n",s->a[s->left]);
          s->left = s->right = -1;
     }

      else
    {
          printf("\n%d dequeued\n",s->a[s->right]);
          s->right--;
    }

     return s;  
}

Queue*Initialize(Queue*s)
{
    s->left = s->right = -1;
    return s;
}

Queue*FrontEnqueue(Queue*s, int a)
{
    if(s->left == -1 && s->right == -1)
    {
         s->left = s->right = 0;
         *(s->p+0) = a;
         printf("\n%d enqueued...\n",*(s->p+s->right));
    }
   
    else if(s->left == 0 && s->right == s->size -1)
    {
         printf("\nQueue Overflow !!\n");
    }
   
    else if(s->left == 0 && s->right != s->size-1)
    {
         int i;
         for(i = s->right; i >= s->left; i--)
         {
              *(s->p+i+1)= *(s->p+i);
         }
         s->right++;
         *(s->p) = a;
         printf("\n%d enqueued...\n",*(s->p+s->left));
    }

     else
     {
          s->left--;
          *(s->p+s->left) = a;
          printf("\n%d enqueued...\n",*(s->p+s->left));
     }

      return s;
}

Queue*RearEnqueue(Queue*s, int a)
{
    if(s->left == -1  && s->right == -1)
    {
         s->left = s->right = 0;
         *(s->p+0) = a;
         printf("\n%d enqueued...\n",*(s->p+0));
    }
   
    else if(s->right == s->size - 1 )
    {
         printf("\nQueue Overflow !!\n");
    }
   
    else
   {
        s->right++;
        *(s->p+s->right) = a;
        printf("\n%d enqueued...\n",*(s->p+s->right));
   }

      return s;
}

Queue* FrontDequeue(Queue*s)
{
     if(s->left == -1 && s->right == -1)
     {
          printf("\nQueue Underflow !!\n");
     }
     
     else if(s->left == s->right)
     {
          printf("\n%d dequeued\n",*(s->p+s->left));
          s->left = s->right = -1;
     }

     else
    {
          printf("\n%d dequeued\n",*(s->p+s->left));
          s->left++;
    }

     return s ;
}

Queue* RearDequeue(Queue*s)
{
     if(s->right == -1)
     {
          printf("\nQueue Underflow !!\n");
     }

     else if(s->left == s->right)
     {
          printf("\n%d dequeued\n",*(s->p+s->left));
          s->left = s->right = -1;
     }

      else
    {
          printf("\n%d dequeued\n",*(s->p+s->right));
          s->right--;
    }

     return s;  
}

void display_sma(queue*s)
{
    if(s->left == -1)
    {
     printf("\nQueue is empty !!\n");
     return;
    }
    
    else
    {   int i = s->left;
        printf("\nCurrent status of the SMA queue is...\n");
        do{
            printf("%d ",s->a[i]);
            i++;
        }while(i <= s->right);
    }
    
}

void display_dma(Queue*d)
{
    if(d->left == -1)
    {
     printf("\nQueue is empty !!\n");
     return;
    }
    
    else
    {   int i = d->left;
        printf("\nCurrent status of the DMA queue is...\n");
        do{
            printf("%d ",*(d->p+i));
            i++;
        }while(i <= d->right);
    }
    
}

