#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node*next;
}node;

int i,j;

int    nodeCount(node*);//Working Correctly :)
node*  createLL(node*,int);//Working Correctly :)
node*  createNode(void);//working correctly :)
void   display(node*);//Working Correctly :)
node*  insertBeg(node*);//Working Correctly :)
node*  insertEnd(node*);//Working Correctly :)
node*  deleteBeg(node*);//Working Correctly :)
node*  deleteEnd(node*);//Working Correctly :)
node*  insertAtPosition(node*);//Working Correctly :)
node*  deleteAtPosition(node*);//Working Correctly :)
node*  deleteByKey(node*);//Working Correctly :)
void   searchByKey(node*);//Working Correctly :)
node*  reverseLL(node*);//Working Correctly :) 
node*   orderList(void);//Working Correctly :)
node*  copyLL(node*);//Working Correctly :)
node* deleteList(node*);//Working Correctly :)



int main()
{
    int n; node*head2 = NULL; node*copy = NULL; node*head = NULL;
    printf("Number of nodes for singly linked list:\t"); scanf("%d",&n);
    head = createLL(head,n);
    printf("\n");
    display(head);
    int choice;
    while(1)
    {
        printf("\n\n>>>OPERATIONS ON SLL>>>\n1.Insert at beginning\n2.Insert at end\n3.Insertion at specified position\n4.Deletion at specified position\n5.Delete by key\n6.Search by key\n7.Create an ordered list\n8.Reverse the present list\n9.Create a copy of the present list\n10.Delete first node\n11.Delete last node\n12.Exit\n\n");
        printf("Enter your choice:\t"); scanf("%d",&choice);
        switch(choice)
        {
           case 1: head = insertBeg(head); printf("\n"); display(head);
                          break;
           
           case 2: head = insertEnd(head); printf("\n"); display(head);
                          break;
           
           case 3: head = insertAtPosition(head);  printf("\n"); display(head);
                          break;
           
           case 4: head = deleteAtPosition(head);  printf("\n"); display(head);
                          break;
           
           case 5: head = deleteByKey(head);  printf("\n"); display(head);
                          break;
           
           case 6:        searchByKey(head);  printf("\n"); display(head);
                          break;
           
           case 7:      head = deleteList(head); head = orderList();  printf("\n");// display(head2);
                           break;
           
           case 8: head = reverseLL(head);  printf("\n"); display(head);
                          break;
           
           case 9: copy = copyLL(head);  if(copy == NULL){printf("\nCopy operation failed\n");}  else{display(copy);}
                          break;
           
           case 10: head = deleteBeg(head);  printf("\n"); display(head);
                           break;
           
           case 11: head = deleteEnd(head);  printf("\n"); display(head);
                           break;
                           
           case 12: exit(0); 
           
           case 13: head = deleteList(head); display(head); break;
                           
           default: printf("\nInvalid choice...\n"); break;               
        }
    }
    return 0;
}


node* copyLL(node* head)
{
    node* temp = head; //To traverse the original list   
    node* head2 = NULL;//To point to the first node of the copied list    
    node* current = NULL;//To clone the present temp pointing node in the copy list    
 
    while (temp)
    {
        
        if (head2 == NULL)
        {
            head2 = (node*)malloc(sizeof(node));
            head2->data = temp->data;
            head2->next = NULL;
            current = head2;
        }
        else {
            current->next = (node*)calloc(1,sizeof(node));//to create a newnode with data initialized as zero
            current = current->next;
            current->data = temp->data;
            current->next = NULL;
        }
        temp = temp->next;
    }
 
    return head2;
}

node* orderList(void)
{   node*head = NULL; node*temp = NULL; node*newnode = NULL; node*prevnode = NULL; int i,n;
    temp = (node*)malloc(sizeof(node));
    newnode = (node*)malloc(sizeof(node));
    prevnode = (node*)malloc(sizeof(node));
    
    printf("Enter the size of SLL:\t"); scanf("%d",&n);
    newnode->next = NULL;
    printf("\nEnter the data for node number 1:\t"); scanf("%d",&newnode->data);
    head = newnode;
    for(i=2; i<=n; i++)
    {   
        newnode = createNode();
        temp = head;
       while(temp!=NULL && newnode->data > temp->data) //This loop is just to traverse for the location for insertion by comparing
       {                                               // newnode->data and temp->data   before or until temp becomes NULL
           prevnode = temp;
           temp = temp->next;
       }
       
       if(temp == head)                //Loop didn't get executed, which means the current data of 'newnode' is the SMALLEST among the existing node/s.
       {
           newnode->next = head;
           head = newnode;
       }
       
       else if(temp == NULL)           //We are trying to add the 'newnode' at the end
       {
           prevnode->next = newnode;
       }
        
       else                           //To insert the 'newnode' in between
       {
           newnode->next = temp;
           prevnode->next = newnode;
       }
        
    }
    return head;
}

int nodeCount(node*head)
{
    int count = 0; node*temp;
    
    if(head == NULL)
    return 0;
   
    else{ temp=head;
    while(temp != NULL)
    {   temp = temp->next;
        count = count + 1;
    }
   
    return count;
   
    }
   
}

node* createNode(void)
{
    node*nextnode;//nextnode is not pointing to any node here
    nextnode = (node*)malloc(sizeof(node));
    printf("Enter the data:\t");
    scanf("%d",&nextnode->data);
    nextnode->next=NULL;
    
    return nextnode;
}

node* createLL(node*head,int n)
{   node* temp; node* newnode;
    for(i=0; i<n; i++){
    printf("\nNode %d\n",i+1);
    newnode = createNode();
   
    if(head == NULL){head = newnode; temp = head;}
    else{
        
        temp->next = newnode;
        temp = temp->next;
    }
}
    return head;
}

void display (node*head)
{   printf("\nCurrent status of Linked List is...\n");
    
    if(head == NULL)
    {
        printf("\nIt is empty :(");
    }
    node* temp;
    temp = head;
    while(temp != NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }
}

node* insertBeg(node*head)
{   node*newnode;
    newnode = (node*)malloc(sizeof(node));
    {
        printf("\nEnter the data:\t"); scanf("%d",&newnode->data);
        newnode->next = head; 
        head = newnode;
      
        return head;
    }
}

node* insertEnd(node*head)
{
    node*newnode = NULL; node*temp = NULL;
    newnode = (node*)malloc(sizeof(node));
    printf("\nEnter the data:\t"); scanf("%d",&newnode->data); newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
    }
   
    else{ temp = head;
        
        while(temp->next != NULL)
        {temp = temp->next;}
       
        temp->next = newnode;
       
    }
    return head;
}

node* deleteBeg(node*head)
{   int size; node*temp = NULL;
    if(head == NULL)
    {
        printf("\nCreate a linked list first...\n"); printf("Enter the number of nodes for linked list:\t"); scanf("%d",&size);
        head = createLL(head,size);
        head = deleteBeg(head);
    }
   
    else{ temp = head;
        head = head->next;
        free(temp);
        return head;
    }
}

node* deleteEnd(node*head)
{
    int size; node*temp = NULL; node*prevnode = NULL;
   
    if(head == NULL)
    {
        printf("\nCreate a linked list first...\n"); printf("Enter the number of nodes for linked list:\t"); scanf("%d",&size);
        head = createLL(head,size);
        head = deleteEnd(head);
    }
   
    else{ 
       
       if(head->next == NULL)     //if there exisis only one node
       {
           free(head); head = NULL;
           return head;
       }
       else
       { temp = head; prevnode = head;   // if more than one nodes are there
       
        while(temp->next != NULL)
        {   prevnode = temp;
            temp = temp->next;}
       
        prevnode->next = NULL;
        free(temp);
       
       
        return head;
    }
    }
}

node* insertAtPosition(node*head)
{   int no = nodeCount(head);
    int pos; node*newnode = NULL; node*temp = NULL;
    newnode = (node*)malloc(sizeof(node));
 
    if(head == NULL)
    {   int size;
        printf("\nCreate a linked list first...\n"); printf("Enter the number of nodes for linked list:\t"); scanf("%d",&size);
        head = createLL(head,size);
        head = insertAtPosition(head);
    }
   
    else{ temp = head;
        printf("\nEnter the data:\t"); scanf("%d",&newnode->data); newnode->next = NULL;
        printf("\nCurrent size of the linked list is : %d\n",no);
        printf("\nEnter the position for the insertion:\t"); scanf("%d",&pos);
       
        if(pos> no+1 || pos<=0)
        {
            printf("\nInvalid position...\n");
            return head;
        }
       
        else if(pos == 1)            //To insert at the beginning and to update the head
        {
            newnode->next = head;
            head = newnode;
            return head;
        }

        else{                       //intermediate position
        int count = 1; temp = head;
        while(count<pos - 1)
        {
            temp = temp->next;
            count++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
       
        return head;
    }
    }
}


node* deleteAtPosition(node*head)
{   int no = nodeCount(head);
    int pos,count=0; node*temp = NULL; node*prevnode = NULL;
    
    if(head == NULL)
    {   int size;
        printf("\nCreate a linked list first...\n"); printf("Enter the number of nodes for linked list:\t"); scanf("%d",&size);
        head = createLL(head,size);
        head = deleteAtPosition(head);
    }
   
    else{
        printf("\nCurrent size of the linked list is : %d\n",no);
        printf("\nEnter the position for the deletion:\t"); scanf("%d",&pos);
       
        if(pos> no || pos<=0)
        {
            printf("\nInvalid position...\n");
            return head;
        }
       
        else if(pos == 1)             //this case is required to update the 'head'
        {
            head = deleteBeg(head);
            return head;
        }
        else{ temp = head;
       
        while(count<pos-1)
        {   prevnode = temp;
            temp = temp->next;
            count++;
        }
       
        prevnode->next = temp->next;
        free(temp);
       
       
        return head;
        }
    }
}

node* deleteByKey(node*head)
{   int no = nodeCount(head);
    int key; node*temp=NULL; node*prevnode= NULL;
    //temp = (node*)malloc(sizeof(node));
    //prevnode=(node*)malloc(sizeof(node));
   
    if(head == NULL)
    {   int size;
        printf("\nCreate a linked list first...\n"); printf("Enter the number of nodes for linked list:\t"); scanf("%d",&size);
        head = createLL(head,size);
        head = deleteByKey(head);
    }
   else{
                 temp = head;
    printf("\nEnter the key:\t"); scanf("%d",&key);
    int count = 0;

if(temp->data == key)
  {  count = 1;
      head = temp->next;
                               
      free(temp);
      return head;
  }

        while(temp != NULL && count ==0)
        {  
            if(temp->data != key)
            {
                prevnode = temp;
                temp = temp->next;
            }
           
           else
           {  
               if(temp->data == key)
               {  count = 1;
                   prevnode->next = temp->next;
                   free(temp);
                   return head;
               }
           }
        }

       
        if(count == 0)
        {
            printf("Element not present in the linked list");
            return head;
        }
}
}

void searchByKey(node*head)
{
    int key; node*temp = NULL; int count = 0; int no = nodeCount(head); int flag =0;
    //temp = (node*)malloc(sizeof(node));
    if(head == NULL)
    {   int size;
        printf("\nCreate a linked list first...\n"); printf("Enter the number of nodes for linked list:\t"); scanf("%d",&size);
        head = createLL(head,size);
        searchByKey(head);
    }
   
    else{
    printf("\nEnter the key:\t"); scanf("%d",&key);
    temp = head;
    while(temp != NULL)
    {   count++;
        if(temp->data == key)
        {   flag =1;
            printf("\nKey found at position %d in the linked list.\n",count);break;
        }
        temp =  temp->next;
    }
   
    if(flag != 1){printf("\nElement absent.\n");}
   
}
}

node* reverseLL(node*head)
{   
    if(head == NULL)
    {   int size;
        printf("\nCreate a linked list first...\n"); printf("Enter the number of nodes for linked list:\t"); scanf("%d",&size);
        head = createLL(head,size);
        reverseLL(head);
    }
    
    
    else
    {
        node*current = NULL; node*previous = NULL;
        
        previous = head;
        current = head->next;
        head = head->next;
        
        previous->next = NULL;
        
        while(head != NULL)
            {
                head = head->next;
                current->next = previous;
    
                previous = current;
                current = head;
            }
    
            head = previous;
        
        return head;
    }
}

node* deleteList(node*head)
{
    node*temp;
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}
