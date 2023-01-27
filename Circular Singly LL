#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    
    int data;
    struct node*next;
    }node;

int i,j;

node*  createCSLL(node*,int);//Working Correctly :)
node*  createNode(void);//Working Correctly :)
node*  insertBeg(node*);//Working Correctly :)
void   display(node*);//Working Correctly :)
node*  insertEnd(node*);//Working Correctly :)
node*  deleteBeg(node*);//Working Correctly :)
node*  deleteEnd(node*);//Working Correctly :)
int    nodeCount(node*);//Working Correctly :)
node*  insertAtPosition(node*);//Working Correctly :)
node*  deleteAtPosition(node*,int);//Working Correctly :)
void   searchByKey(node*);//Working Correctly :)
node*  deleteByKey(node*,int);//Working Correctly :)
node*  reverseCSLL(node*tail);//Working Correctly :)
void   orderList(void);
node*  copyLL(node*);//Working Correctly :)

int main()
{
    int size,no;  node*tail2 = NULL; node*tail = NULL;
    printf("Enter the number of nodes for circular singly linked list:\t"); scanf("%d",&size);
    
    tail = createCSLL(tail,size);
    display(tail);
    no = nodeCount(tail);
    printf("\n%d\n",no); int choice;
    for(;;)
    {
        printf("\n\n1.Insert At The Beginning\n2.Insert At The End\n3.Delete At The Beginning\n4.Delete At the End\n5.Insert At Position\n6.Delete At Position\n7.Delete By Key\n8.Search By Key\n9.Reverse List\n10.Create A Copy\n11.Create an ordered list\n12.Exit\n\n");
        printf("Enter your choice:\t"); scanf("%d",&choice);
        switch(choice)
        {
            case 1: tail = insertBeg(tail); display(tail); break;
            case 2: tail = insertEnd(tail); display(tail); break;
            case 3: tail = deleteBeg(tail); display(tail); break;
            case 4: tail = deleteEnd(tail); display(tail); break;
            case 5: tail = insertAtPosition(tail); display(tail); break;
            case 6: printf("\nEnter the position:\t"); scanf("%d",&choice);
                    tail = deleteAtPosition(tail,choice); display(tail); break;
            case 7: printf("\nEnter the key:\t"); scanf("%d",&choice);
                    tail = deleteByKey(tail,choice); display(tail); break;
            case 8: searchByKey(tail); break;
            case 9: tail = reverseCSLL(tail); display(tail); break;
            case 10: tail2 = copyLL(tail); display(tail2); break;
            case 11: orderList(); break;
            case 12: exit(0);
            default: printf("\nInvalid Position...\n"); break;
            
        }
    }
    
    
    return 0;
}

node* createNode(void)
{
    node* nextnode;
    nextnode = (node*)malloc(sizeof(node));
    printf("\nEnter the data:\t");
    scanf("%d",&nextnode->data);
    nextnode->next = NULL;
    
    return nextnode;
}

node* createCSLL(node*tail,int size)
{
    if(size <= 0)
    {   printf("\nEnter a valid size...\n");
        return NULL;
    }
    
    else
    {  node*newnode;
        for(i=0; i<size; i++)
        {
            printf("\nNode %d",i+1);
            newnode = createNode();
            
            if(tail == NULL)
            {
                tail = newnode;
                newnode->next = tail;
            }
            else
            {   
                if(tail->next == NULL)      //if there is only one node, and no circular links exists
                {
                    newnode->next = tail;
                    tail->next = newnode;
                    tail = newnode;
                }
                else
                {
                    newnode->next = tail->next;
                    tail->next = newnode;
                    tail = newnode;
                }
            }
        }
        
        return tail;
    }
}

void display(node*tail)
{
    printf("\nThe current status of the circular singly linked list is....\n");
    if(tail == NULL)
    {
        printf("\nIt is empty...\n");
    }
    
    else
    {   
        node*head; node*temp;
        head = tail->next;
        
        do
        {
            printf("%d\t",head->data);
            head = head->next;
        }
        while(head!= tail->next);
    }
}

node* insertBeg(node*tail)
{   
    if(tail == NULL)
    {
        printf("\nLinked list is empty...\n");
        return tail;
    }
    else
    {
        node*newnode;
        printf("\nFor the data to be inserted at the beginning...\n");
        newnode = createNode();
        
        newnode->next = tail->next;
        tail->next = newnode;
        
        return tail;
    }
}

node* insertEnd(node*tail)
{
    if(tail == NULL)
    {
        printf("\nLinked list is empty...\n");
        return tail;
    }
    else
    {
        node*newnode;
        printf("\nFor the data to be inserted at the end...\n");
        newnode = createNode();
        
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
        
        return tail;
    }
}

node*  deleteBeg(node*tail)
{
    if(tail == NULL)
    {
        printf("\nLinked list is empty...\n");
        return tail;
    }
    else
    {
    node*temp;
    temp = tail->next;
    tail->next = temp->next;
    free(temp);
    
    return tail;
    }
}

node* deleteEnd(node*tail)
{
    if(tail == NULL)
    {
        printf("\nLinked list is empty...\n");
        return tail;
    }
    else
    {
        node*temp;
        temp = tail;
        while(tail->next != temp)
        {
            tail = tail->next;
        }
        tail->next = temp->next;
        free(temp);
        
        return tail;
    }
}

int nodeCount(node*tail)
{
    node*temp; int count = 0;
    temp = tail;
    while(temp->next != tail)
    {
        temp = temp->next;
        count++;
    }
    count++;
    
    return count;
}


node* insertAtPosition(node*tail)
{
    int p; int no = nodeCount(tail); node*newnode;
    printf("\nEnter the position:\t"); scanf("%d",&p);
    newnode = createNode();
    
    if(p<=0 || p>no+1)
    {
        printf("\nInvalid Position...\n");
        return tail;
    }
    
    else
    {
        node*temp; node*prev;
        temp = tail->next;
        prev = tail;
        
        for(i=1; i<p; i++)
        {
           prev = temp;
           temp = temp->next;
        }
        
        newnode->next = temp;
        prev->next = newnode;
        
        if(p == no+1)
        {
            tail = newnode;
        }
        
        return tail;
    }
}

node* deleteAtPosition(node*tail, int p)
{
    int no = nodeCount(tail);
    
    if(p<=0 || p>no)
    {
        printf("\nInvalid Position...\n");
        return tail;
    }
    
    else
    {
        node*temp; node*prev;
        temp = tail->next;
        prev = tail;
        
        for(i=1; i<p; i++)         //To make sure that the 'temp' is pointing at the 'pth' node...
        {
           prev = temp;
           temp = temp->next;
        }
        
        if(p == no)                //Updating the tail if we want to delete the last node...
        {
            tail = prev;
        }
        
        if(p == 1 && no==1)        //If the list has only one node...
        {
            free(tail);
            return NULL;
        }
        
        prev->next = temp->next;   //Deleting that node to which 'temp' is pointing...
        free(temp);
        
        return tail;
    }
}

void searchByKey(node*tail)
{
    if(tail == NULL)
    {
       printf("\nLinked list is empty...\n");
    }
    
    int key;
    printf("\nEnter the key:\t");  scanf("%d",&key);
    node*temp; node*prev;
    temp = tail->next; 
    prev = tail; i=1; int flag = 0;
    while(flag == 0)
    {
        if(temp->data == key)
        {
            printf("\n%d found at position %d\n",key,i);
            flag = 1;
            break;
        }
        prev = temp;
        temp = temp->next;
        i++;
        
        if(prev->next == tail->next)
        {
            flag = 2;
        }
        
    }
    
    if(flag - 3 == 0)
    {
        printf("\nElement absent\n");
    }
}

node* deleteByKey(node*tail, int key)
{
    if(tail == NULL)                       //If the linked list is empty
    {
        printf("\nLL is empty...\n");
        return tail;
    }
    
    else                                
    {
        node*temp; node*prev; int flag = 0;
        temp = tail->next;                  // 'temp' pointing to the first node initially
        prev = tail;                        //'prev' pointing to the last node initially
        
        while(temp->next != tail)
        {
            if(temp->data == key)           // This loop is used to get 'temp' pointing at the node holding 'key' data
            {
                flag = 1;
                break;                      // But this loop won't compare the key with last node's data
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        
        if(temp->next->data == key)        //In case 'key' data is present in the last node, so to update the tail
        {
            prev = tail;
            tail = temp;
            tail->next = prev->next;
            free(prev);
            
            return tail;
        }
        else if(flag == 1)                // To delete the node (other than the last node) containing 'key' data       
        {
            prev->next = temp->next;
            free(temp);
            
            return tail;
        }
        
        else                             
        {
            printf("\nElement Absent\n");
            return tail;
        }
    }
}

node* reverseCSLL(node*tail)
{
    if(tail == NULL)
    {
        printf("\nlinked list is empty...\n");
        return NULL;
    }
    
    else
    {
        node*current = NULL; node*previous = NULL; node*h;
        
        previous = tail;        //Creating the Circular SLL into a SLL, with 'tail' functioning as 'head'
        tail = tail->next;
        h = tail;
        previous->next = NULL;
        
        previous = tail;         //Isolating the very first node of the SLL
        current = tail->next;
        tail = tail->next;
         previous->next = NULL;  
        
        while(tail != NULL)
            {
                tail = tail->next;
                current->next = previous;
    
                previous = current;
                current = tail;
            }
    
            tail = previous;    //  Reversing of SLL is done, but it is still a SLL
        
        
        h->next = tail;         // Creating Circular SLL again
         
        tail = h;               // As the first node, to which 'h' was assigned, after reversing is going to be the last node
        
        return tail;
    }
}

void orderList(void)
{
    int size; node*tail = NULL; node*newnode; node*temp; node*prev;
    printf("\nEnter the size for Circular SLL:\t"); scanf("%d",&size);
    for(i=0;i<size;i++)
    {   
        printf("\nNode %d",i+1);
        newnode = createNode();
        if(tail == NULL)        //For First run (iteration) only
        {
            tail = newnode;
            newnode->next = tail;      //Circular linked list with single node is created
        }
        
        else
        {
            temp = tail->next;                  // 'temp' pointing to the first node initially
            prev = tail;                        //'prev' pointing to the last node initially
        
            while(temp->next != tail && newnode->data > temp->data)
            {
                if(temp->data > newnode->data)      
                {
                    break;                      // But this loop won't compare the 'newnode->data' with tail node's data
                }
                else
                {
                    prev = temp;
                    temp = temp->next;
                }
            }
            
            if(temp->next == tail && temp->next->data < newnode->data)        //In case the loop has ended and newnode->data is the largest, so to update the tail
            {
                prev = tail;
                temp = tail->next;
                
                newnode->next = temp;
                tail->next = newnode;
                tail = newnode;
                newnode = NULL;
    
            }
            else if(temp->next == tail && temp->next->data > newnode->data)  //To compare the 'newnode->data' with 'tail->data' if it is 2nd largest          
            {                                                                // Only if the loop has ended
                prev = tail;
                
                newnode->next = prev;
                temp->next = newnode;
                newnode = NULL;
                
            }
            
            else                                      //For remaining cases
            {
                newnode->next = temp;
                prev->next = newnode;
                newnode = NULL;
                
                
            }
        }
    }
    printf("\nThe created ordered list is...\n");
    
    display(tail);
}

node* copyLL(node*tail)
{
    node* tail2 = NULL; node*temp; node*current;
    temp = tail;
    do{
        if (tail2 == NULL)
        {
            tail2 = (node*)malloc(sizeof(node));
            tail2->data = temp->data;
            tail2->next = tail2;
            current = tail2;
        }
        
        else {
            current->next = (node*)calloc(1,sizeof(node));//to create a newnode with data initialized as zero
            current = current->next;
            current->data = temp->data;
            current->next = tail2;
        }
        temp  = temp->next;
    }while(temp != tail); printf("\n\n%d\n\n",tail2->next->data);
    
    return tail2;
}
