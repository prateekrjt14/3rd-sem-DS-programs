#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node*lptr;
    struct node*rptr;                                                           
} node;

int i,j;  node*head = NULL; node*tail = NULL; node*head2 = NULL;    //////////////////////////////////////////////                                          
node*tail2 = NULL;                                                  //                                          //
node*   createNode(void);//Working Correctly :)                     //                                          //
node*   createDLL(node*,int);//Working Correctly :)                 //                                          //
void    display(node*);//Working Correctly :)                       //                                          //
node*   insertBeg(node*);//Working Correctly :)                     //           OPERATIONS ON DLL              //
node*   insertEnd(node*);//Working Correctly :)                     //                                          //
int     nodeCount(node*);//Working Correctly :)                     //                                          //
node*   insertAtPosition(node*);//Working Correctly :)              //                                          //
node*   deleteAtPosition(node*);//Working Correctly :)              //                                          //    
node*   deleteBeg(node*);//Working Correctly :)                     //////////////////////////////////////////////
node*   deleteEnd(node*);//Working Correctly :)
node*   deleteByKey(node*);//Working Correctly :)
void    searchByKey(node*);//Working Correctly :)
node*   reverseDLL(node*);//Working Correctly :)
node*   copyDLL(node*);//Working Correctly :)
void    orderDLL(void);

int main()
{  
    int n;
    printf("Number of nodes for DLL:\t");   scanf("%d",&n);
    head = createDLL(head,n);
    display(head);
    
    while(1)
    {
        int choice;
        printf("\nDLL OPERATIONS>>>\n\n1.Insert node at the beginning\n2.Insert node at the end\n3.Insert node at a position\n4.Delete node at a position\n5.Delete by key\n6.Search by key\n7.Create an ordered list\n8.Reverse a list\n9.Create a clone of present list\n10.Delete node at the beginning\n11.Delete node at the end\n12.Exit\n\n");
        printf("\nEnter your choice:\t"); scanf("%d",&choice);
       
        switch(choice)
        {
            case 1: head = insertBeg(head);
                    display(head);
                    break;
                    
            case 2: head = insertEnd(head);
                    display(head);
                    
            case 3: head = insertAtPosition(head);
                    display(head);
                    break;
                    
            case 4: head = deleteAtPosition(head);
                    display(head);
                    break;
                    
            case 5: head = deleteByKey(head);
                    display(head);
                    break;
                    
            case 6: searchByKey(head);
                    display(head);
                    break;
                    
            case 7: orderDLL();
                    break;
                    
            case 8: head = reverseDLL(head);
                    display(head);
                    break;
                    
            case 9: head2 = copyDLL(head);
                    if(head2 == NULL)
                    {
                        printf("\nCopy Operation Failed!!\n");
                    }
                    else
                    {
                        display(head2);    
                    }
                    break;
                    
            case 10: head = deleteBeg(head);
                     display(head);
                     break;
                
            case 11: head = deleteEnd(head);
                     display(head);
                     break;
                     
            case 12: exit(0);
            
            default: printf("\nInvalid Choice!!\n");
                     break;
        }
       
       
    }
    
    return 0;
}




node*createNode(void)
{
    node*nextnode;
    nextnode = (node*)malloc(sizeof(node));
    printf("\nEnter the data:\t"); scanf("%d",&nextnode->data);
    nextnode->lptr = NULL;
    nextnode->rptr = NULL;
    
    return nextnode;
}

node*createDLL(node*head,int n)
{  head = NULL;
   node*newnode;

   for(i=1; i<=n; i++)
   {   printf("\nNode %d",i);
       newnode = createNode();
       
       if(head == NULL)
       {
           head = newnode;
           tail = newnode;
       }
       
       else
       {
           tail->rptr = newnode;
           newnode->lptr = tail;
           tail = newnode;
       }
   }
    return head;
}

void display(node*head)
{   node*temp;
    
    printf("\nCurrent status of the linked list is...\n");
    if(head == NULL)
    {
        printf("\nDLL is empty....\n");
        printf("\n********************************************************************************************************************************\n");
    }
    else
    { temp = head;
        while(temp)
        {
            printf("%d\t",temp->data);
            temp = temp->rptr;
        }
        printf("\n********************************************************************************************************************************\n");
    }
}

node* insertBeg(node*head)
{
   if(head == NULL)
   {
       printf("\nDouble linked list is empty\n");
       printf("\n********************************************************************************************************************************\n");
       return 0;
   }
   
   else
   {  
       node*temp; node*newnode;
       printf("\n\n************     INSERT AT THE BEGINNING    ************************************************************************************\n");
       printf("\n\nFor the node to be inserted at the beginning...");
       newnode = createNode();
       
       temp = head;
       newnode->rptr = temp;
       temp->lptr = newnode;
       head = newnode;
       
       return head;
   } 
}

node* insertEnd(node*head)
{
    if(head == NULL)
    {
        printf("\nDouble linked list is empty...\n");
        printf("\n********************************************************************************************************************************\n");
        return 0;
    }
    
    else
    {   
        node*newnode;
        
        printf("\n\n************     INSERT AT THE END    ******************************************************************************************\n");
        printf("\n\nFor the node to be inserted at the end...");
        newnode = createNode();
        
        tail->rptr = newnode;
        newnode->lptr = tail;
        tail = newnode;
        newnode = newnode->rptr;
        
        return head;
    }
}

int nodeCount(node*head)
{
    if(head == NULL)
    return 0;
    
    else
    {
        node*temp = head; int count = 1;
        while(temp->rptr)
        {
            temp = temp->rptr;
            count++;
        }
        return count;
    }
}

node* insertAtPosition(node*head)
{
    if(head == NULL)
    {
        printf("\nDouble linked is empty...\n");
        printf("\n********************************************************************************************************************************\n");
        return 0;
    }
    
    else
    {
        node* temp; int p,no = nodeCount(head);
        printf("\n\n************     INSERT AT THE POSITION    *************************************************************************************\n");
        printf("\n\nSize of DLL: %d\n",no);
        printf("\nEnter position:\t"); scanf("%d",&p);
        if(p > no+1  ||  p < 1)
        {
            printf("\nInvalid position...\n");
            printf("\n********************************************************************************************************************************\n");
            return head;
        }
        else if(p == no+1)
        {   printf("\nFor the node to be inserted at the end...\n");
            node*newnode = createNode();
            tail->rptr = newnode;
            newnode->lptr = tail;
            tail = newnode;
            newnode = newnode->rptr;
        
        
            return head;
        }
        else if(p == 1)
        {   printf("\nFor the node to be inserted at the beginning...\n");
            node*newnode = createNode();
       
            temp = head;
            newnode->rptr = temp;
            temp->lptr = newnode;
            head = newnode;
        
            return head;
            
        }
        else
        {   temp = head;
            printf("\n\nFor the node to be inserted at position %d...\n",p);
            node*newnode = createNode(); node*previous;
            for(i=1 ; i<p; i++)
            {   previous = temp;
                temp = temp->rptr;
            }
            
            
                newnode->rptr = temp;
                temp->lptr = newnode;
                previous->rptr = newnode;
                newnode->lptr = previous;
                newnode = NULL;
                return head;
            
    
        }
    }    
}

node* deleteAtPosition(node*head)
{
    if(head == NULL)
    {
        printf("\nDLL is empty..\n");
        printf("\n********************************************************************************************************************************\n");
        return 0;
    }
    
    else
    {node* temp; int p,no = nodeCount(head);node*previous;
        printf("\n\n************     DELETE AT THE POSITION    *************************************************************************************\n");
        printf("\nSize of DLL: %d\n",no);
        printf("\nEnter position:\t"); scanf("%d",&p);
        if(p>no || p<1)
        {
            printf("\nInvalid Position...\n");
            printf("\n********************************************************************************************************************************\n");
            return head;
        }
        
        if(p==1)
        {
            temp = head;
            temp->rptr->lptr = NULL;
            head = temp->rptr;
            free(temp);
            
            return head;
        }
        
        else if(p == no)
        {
            temp = tail;
            tail = tail->lptr;
            tail->rptr = NULL;
            free(temp);
            
            return head;
        }
        else
        {
            temp = head;
            for(i=1; i<p; i++)
            {
                previous = temp;
                temp = temp->rptr;
            }
            
            previous->rptr = temp->rptr;
            temp->rptr->lptr = previous;
            free(temp);
            
            return head;
        }
        
    }
}

node* deleteBeg(node*head)
{
    if(head == NULL)
    {
        printf("\nDLL is Empty...\n");
        printf("\n********************************************************************************************************************************\n");
    }
    
    else
    {
        node*temp = head;
        printf("\n\n************     DELETE AT THE BEGINNING    ************************************************************************************\n");
        head = temp->rptr;
        temp->rptr->lptr = NULL;
        free(temp);
        
        return head;
    }
}

node* deleteEnd(node*head)
{
    if(head == NULL)
    {
        printf("\nDLL is Empty...\n");
        printf("\n********************************************************************************************************************************\n");
        return head;
    }
    
    else
    {
        node*temp = tail;
        printf("\n\n************     DELETE AT THE END    ******************************************************************************************\n");
        tail = temp->lptr;
        tail->rptr = NULL;
        free(temp);
        
        return head;
    }
}

node* deleteByKey(node* head)
{
    if(head == NULL)
    {
        printf("\nDLL is empty..\n");
        printf("\n********************************************************************************************************************************\n");
        return 0;
    }
    
    else
    {
        node*temp; node*previous; 
        temp = head; int key,no = nodeCount(head);
        printf("\n\n************     DELETE BY THE KEY    ******************************************************************************************\n");
        printf("\nEnter the key:\t"); scanf("%d",&key);
        int count = 0;
        if(no ==1 && temp->data == key)
        {
            head = NULL;
            free(temp);
            return head;
        }
        if(temp->data == key)
        {  
            head = temp->rptr;
            temp->rptr->lptr = NULL;
            free(temp);
            return head;
        }

        while(temp != NULL && count ==0)
        {  
            if(temp->data != key)
            {
                previous = temp;
                temp = temp->rptr;
            }
           
           else
            {  
                count = 1;
                if(temp->rptr == NULL)
                {
                    tail = previous;
                    previous->rptr = NULL;
                    temp->lptr = NULL;
                    free(temp);
                    return head;
                }
                
                else
                {
                    temp->rptr->lptr = previous;
                    previous->rptr = temp->rptr;
                    free(temp);
                
                    return head;
                }
            }
        }

       if(count == 0)
        {
            printf("\nElement %d is not present in the linked list\n",key);
            return head;
        }
}
}

void searchByKey(node*head)
{
    
    if(head == NULL)
    {   
        printf("\nDLL is empty...\n");
        
    }
   
    else
    {
        int key; node*temp; int count = 0,no = nodeCount(head);
        printf("\n\n************     SEARCH BY THE KEY    ******************************************************************************************\n");
        printf("\nEnter the key:\t"); scanf("%d",&key);
        temp = head;
        
        while(temp != NULL)
        {   
            count++;
            if(temp->data == key)
            { 
                printf("\nKey found at position %d in the doubly linked list.\n",count);
                count = 0;
                break;
            }
        temp =  temp->rptr;
        }
   
        if(count != 0)
        {
            printf("\nElement absent.\n");
            
        }
    }
}

node* copyDLL(node*head)
{
    printf("\n\n************     COPY DOUBLE LL    *******************************************************************************************\n");
    node* temp = head;    
    node* head2 = NULL;    
    node* tail2 = NULL;
    node*previous;      //to link tail->lptr in each iteration (except first)
 
    while (temp)
    {
        
        if (head2 == NULL)
        {
            head2 = (node*)malloc(sizeof(node));
            head2->data = temp->data;
            head2->lptr = NULL;
            head2->rptr = NULL;
            tail2 = head2;
        }
        else {
            tail2->rptr = (node*)malloc(sizeof(node));
            previous = tail2;
            tail2 = tail2->rptr;
            tail2->lptr = previous;
            tail2->data = temp->data;
            tail2->rptr = NULL;
        }
        temp = temp->rptr;
    }
 
    return head2;
}


node* reverseDLL(node*head)
{
    if(head == NULL)
    {
        printf("\nDLL is empty..\n");
        printf("\n********************************************************************************************************************************\n");
        return head;
    }
    
    else
    {   printf("\n\n************     REVERSE DOUBLE LL    ******************************************************************************************\n");
        int no = nodeCount(head);
        node*left; node*right; int temp;
        left = head;    right = tail;
        for(i=0; i< no/2; i++)
        {
            temp = left->data;
            left->data = right->data;
            right->data = temp;
            left = left->rptr;
            right = right->lptr;
            
        }
        return head;
    }
}

void orderDLL(void)
{
    node*head = NULL; node*temp; node*previous; node*newnode;node*tail = NULL;
    int size;
    printf("\n\n************     ORDERED DOUBLE LL    ******************************************************************************************\n");
    printf("\nEnter the DLL size:\t");  scanf("%d",&size);
    
    if(size != 0)
    {
        printf("\nNode 1");
        newnode = createNode();
        head = newnode;
        tail = newnode;
        if(size>1)
        {
            printf("\nNode 2");
            newnode = createNode();
            temp = head;
            
            if(temp->data > newnode->data)
            {
                head = newnode;
                newnode->rptr = tail;
                tail->lptr = newnode;
            }
                
            else
            {
                newnode->lptr = tail;
                tail->rptr = newnode;
                tail = newnode;
            }
            
            for(i=3; i<=size; i++)
            {
                printf("\nNode %d",i);
                newnode = createNode();
                temp = head;
                
                while(temp != NULL && temp->data < newnode->data)
                {
                    previous = temp;
                    temp = temp->rptr;
                }
                
                if(previous == tail)
                {
                    newnode->lptr = previous;
                    previous->rptr = newnode;
                    tail = newnode;
                }
                
                if(temp == head)
                {
                    head = newnode;
                    newnode->rptr = temp;
                    temp->lptr = newnode;
                }
                
                else
                {
                    newnode->rptr = temp;
                    temp->lptr = newnode;
                    newnode->lptr = previous;
                    previous->rptr = newnode;
                }
            }
        }
        
    }
    
    display(head);
}
