//C- program for demonstration of the array opeartions using SMA & DMA
#include<stdio.h>  
#include<stdlib.h>

int i,j;

//Read
void read(int*,int*);

//Display
void display(int*,int*);


//Static  fn-1
void insByPos (void);

//Static  fn-2
void delByPos (void);

//Static  fn-3
void searchInsert (void);

//Static  fn-4
void searchDeletion(void);

//Static  fn-5
void searchByKey(void);

//Static  fn-6
void searchByPos(void);

//Static  fn-7
void reverseArray(void);

//Static fn-8
void sortInsert(void);


//Dynamic  fn-1
void insByPosPtr (int*, int*);

//Dynamic fn-2
void delByPosPtr (int*, int*);

//Dynamic fn-3
void searchInsertPtr(int*,int*);

//Dynamic  fn-4
void searchDeletionPtr(int*,int*);

//Dynamic  fn-5
void searchByKeyPtr(int*,int*);

//Dynamic fn-6
void searchByPosPtr(int*, int*);

//Dynamic fn-7
void reverseArrayPtr(int*,int*);

//Dynamic fn-8
void sortInsertPtr(int*,int*);

int main()
{   int choice, s=0; int*p,*size;
    printf("Enter the size of the array,to which memory is allocated dynamically:\t"); scanf("%d",&s);
    p = (int*)malloc(s*sizeof(int));
    size = &s;
    read(p,size);
    display(p,size);

while(1){
    printf("\n1.Array operations using static memory allocation.\n2.Array operations using dynamic memory allocation\n3.Exit\n");
    printf("Your choice:\t"); scanf("%d",&choice);
    switch(choice)
    {
        case 1:     printf("\n\n\nSMA OPERATIONS >>>\n\n1.Insert By Position.\n2.Delete By Position.\n3.Search Insertion.\n4.Search Deletion.\n5.Search By Key.\n6.Search By Position.\n7.Reverse Array.\n8.Sort Insert.\n9.Exit\n");
                    printf("\nYour choice:\t"); scanf("%d",&choice);
                    
                    switch(choice)
                    {
                        case 1: insByPos();break;
                        case 2: delByPos();break;
                        case 3: searchInsert();break;
                        case 4: searchDeletion();break;
                        case 5: searchByKey();break;
                        case 6: searchByPos();break;
                        case 7: reverseArray();break;
                        case 8: sortInsert();break;
                        case 9: exit(0);
                    }
                break;
        
        case 2: 
                    printf("\n\n\nDMA OPERATIONS >>>\n\n1.Insert By Position.\n2.Delete By Position.\n3.Search Insertion.\n4.Search Deletion.\n5.Search By Key.\n6.Search By Position.\n7.Reverse Array.\n8.Sort Insert.\n9.Display Current Array.\n10.Exit\n");
                    printf("\nYour choice:\t"); scanf("%d",&choice);
                    
                    switch(choice)
                    {  
                        case 1: insByPosPtr(p,size); display(p,size); break;
                                
                        case 2: delByPosPtr(p,size); break;
                        case 3: searchInsertPtr(p,size);break;
                        case 4: searchDeletionPtr(p,size);break;
                        case 5: searchByKeyPtr(p,size);break;
                        case 6: searchByPosPtr(p,size);break;
                        case 7: reverseArrayPtr(p,size);break;
                        case 8: sortInsertPtr(p,size);break;
                        case 9: printf("\nCurrent Array is...\n");
                                display(p,size); break;
                        case 10: exit(0);
                        default: printf("\nInvalid choice...\n");
                    }break;
         
        case 3: exit(0); 
                
        default: printf("\nInvalid Choice...\n");  break;        
    

}
}
    return 0;
}


void read(int*p,int*size)
{
    if(*size <= 0)
    {
        printf("\nOperations can't be performed on %d elements :(\n",*size);
        exit(0);
    }
    
    printf("\nEnter the elements one by one...\n");
    for(i = 0; i<*size; i++)
    {
        scanf("%d",(p+i));   // (p+i) NOT '&(p+i)' because (p+i) in itself is an address
    }

}

void display(int*p,int*size)
{   int i;
    printf("\n");
    for(i=0; i<*size; i++)
    printf("%d\t",*(p+i));
    printf("\n");
}

//Static  fn-1
void insByPos (void)
{
  int i,size,pos,val,a[50];
 printf("Enter the size of the array:\t"); scanf("%d",&size);
 
 printf("\nEnter the elements one by 1...\n");
 for(i=0; i<size; i++)
 scanf("%d",&a[i]);

 printf("\nEnter the value and the position:\t"); scanf("%d%d",&val,&pos);
 for(i=size-1; i>=pos-1; i--)
 { a[i+1]=a[i];}
 a[pos-1] = val;

 printf("\nUpdated array is...\n");
 size++;
 for(i=0; i<size; i++)
 printf("%d\t",a[i]);

 printf("\n");
}

//Static  fn-2
void delByPos (void)
{
 int i,size,pos,a[50];
 printf("Enter the size of the array:\t"); scanf("%d",&size);
 
 printf("\nEnter the elements one by 1...\n");
 for(i=0; i<size; i++)
 scanf("%d",&a[i]);

 printf("\nEnter the position of the element to be deleted:\t"); scanf("%d",&pos);
 
 for(i=pos-1; i<size; i++)
 { a[i]=a[i+1];}
 
 printf("\nUpdated array is...\n");
 size--;
 for(i=0; i<size; i++)
 printf("%d\t",a[i]);
}

//Static  fn-3
void searchInsert (void)
{
    int size, key, a[50],i;

  printf("Enter the size of the array:\t"); scanf("%d",&size);
  printf("\nEnter the elements one by 1...\n");
 
 for(i=0; i<size; i++)
 scanf("%d",&a[i]);

 printf("\nEnter the key:\t"); scanf("%d",&key);
  printf("\n");
int flag = 0;
 for(i=0; i<size; i++)
 { if(a[i]==key)
         {flag+=1; break;}
}
if (flag !=0)
printf("\n%d is already present the array\n",key);
 
else
{  size++;
     a[size-1] = key;
 
printf("\nUpdated array is...\n");
 
 for(i=0; i<size; i++)
 printf("%d\t",a[i]);  
}
}

//Static  fn-4
void searchDeletion(void)
{int i,flag = 0, size,key,pos=1,a[50];
 printf("Enter the size of the array:\t"); scanf("%d",&size);
 
 printf("\nEnter the elements one by 1...\n");
 for(i=0; i<size; i++)
 scanf("%d",&a[i]);

 printf("\nEnter the key:\t"); scanf("%d",&key);

for(i=0; i<size;i++)
{if(a[i]==key)
   {flag+=1; break;}
 pos+=1;
}

if (flag ==0)
{printf("\n%d is not present the array\n",key);}
 
else
{
     for(i=pos-1; i<size; i++)
    { a[i]=a[i+1];}

 
printf("\nUpdated array is...\n");
 size--;
 for(i=0; i<size; i++)
 printf("%d\t",a[i]);
}
}

//Static  fn-5
void searchByKey(void)
{
int a[50], key,i,size,count=0;
printf("\nEnter the size of the array:\t"); scanf("%d",&size);
   printf("Enter the element one by 1...\n");
   for(i=0; i<size; i++)
         {scanf("%d",&a[i]);}
   printf("\nEnter the element to be searched...\n"); scanf("%d",&key);

   for(i=0; i<size; i++)
{
     if(a[i]==key)
     {printf("\nElement present at position %d.\n",i+1);
     count+=1;
      printf("\n%d",count);}
}
if(count==0)
{printf("\nElement is not present in the array.\n");}

}

//Static  fn-6
void searchByPos(void)
{int a[50], pos,i,size;
printf("\nEnter the size of the array:\t"); scanf("%d",&size);
   printf("Enter the element one by 1...\n");
   for(i=0; i<size; i++)
         {scanf("%d",&a[i]);}
   printf("\nEnter the position of the element to be accessed...\n"); scanf("%d",&pos);;

   printf("\nElement at position %d is %d.\n",pos,a[pos-1]);
   printf("\n\n");
}

//Static  fn-7
void reverseArray(void)
{
   int i=1, size, a[50], temp;
   printf("\nEnter the size of the array:\t"); scanf("%d",&size);
   printf("\nEnter the elements one by 1...\n");
   for(i=0; i<size; i++)
    scanf("%d",&a[i]);

  
   for(i=0; i<size/2;i++)
   {
     temp = a[i];
     a[i] = a[size-i-1];
     a[size-i-1] = temp;
   }
printf("\nReversed array is...\n");
for(i=0; i<size; i++)
printf("%d\t",a[i]);

}

//Static fn-8
void sortInsert(void)
{ int i,j, size, elem,temp, a[50];
   printf("\nEnter the array size\n"); scanf("%d", &size);
   printf("\nEnter the elements one by 1...\n");
   for(i=0; i<size; i++)
   {scanf("%d",&a[i]);}
   
   printf("\nElements entered are...\n");
   for(i=0; i<size; i++)
   {printf("%d\t",a[i]);}

  printf("\nEnter the element for insert sort\n"); scanf("%d",&elem);

   size++;
   a[size-1] = elem;
   for(i=size-1; i>=0; i--)
 {
    for(j = size-i-1; j>=0; j--)
     {if( a[j]>a[j+1])
         { temp = a[j+1];
           a[j+1] = a[j];
           a[j] = temp;
         }
     }
 }
printf("\nUpdated array is\n");
   for(i=0; i<size; i++)
   printf("%d\t",a[i]);
}



//Dynamic  fn-1
void insByPosPtr (int*p,int *size)
{  int val, pos;
   printf("\nEnter value:\t"); scanf("%d",&val);
   printf("\nEnter position:\t"); scanf("%d",&pos);
   
 *size = *size + 1;// updating the size, we passed the size by 'call by reference' because unlike linked list we cannot write a function to count the number of elements in the array 
 printf("%d",*size);
 p = (int*)realloc(p,(*size+1)*sizeof(int)); // We need to realloc the size bcz some element is being inserted in this operation
 
 for(i=*size; i>=pos-1; i--)
 { *(p+i+1) = *(p+i);}
 *(p+pos-1) = val;
 printf("%d",*size);
 printf("\nUpdated array is...\n");
 display(p,size);
 printf("\n");
 
}

//Dynamic  fn-2
void delByPosPtr (int*p, int*size)
{ int pos;
 printf("\nEnter the position of the element to be deleted:\t"); scanf("%d",&pos);
 
 for(i=pos-1; i<*size; i++)
 { *(p+i)=*(p+i+1);}
 *size = *size - 1;
 display(p,size);
 printf("\n");
 
}

//Dynamic  fn-3
void searchInsertPtr (int*p,int*size)
{
    int key;

 printf("\nEnter the key:\t"); scanf("%d",&key);
  printf("\n");
int flag = 0;
 for(i=0; i<*size; i++)
 { if(*(p+i)==key)
         {flag+=1; break;}
}
if (flag !=0)
printf("\n%d is already present the array\n",key);
 
else
{  *size = *size + 1;
     *(p+ *size-1) = key;
 
printf("\nUpdated array is...\n");
 
 display(p,size);  
}
}

//Dynamic  fn-4
void searchDeletionPtr(int*p, int*size)
{int flag = 0, key,pos=1;

 printf("\nEnter the key:\t"); scanf("%d",&key);

for(i=0; i<*size;i++)
{if(*(p+i)==key)
   {flag+=1; break;}
 pos+=1;
}

if (flag == 0)
{printf("\n%d is not present the array\n",key);}
 
else
{   *size = *size - 1;
     for(i=pos-1; i<*size; i++)
    { *(p+i)=*(p+i+1);}

 
printf("\nUpdated array is...\n");

 display(p,size);
}
}

//Dynamic  fn-5
void searchByKeyPtr(int*p, int*size)
{
   int key,count=0;
   printf("\nEnter the element to be searched...\n"); scanf("%d",&key);

   for(i=0; i<*size; i++)
{
     if(*(p+i)==key)
     {printf("\nElement present at position %d.\n",i+1);
     count+=1;
     }
}
if(count==0)
{printf("\nElement is not present in the array.\n");}

}

//Dynamic  fn-6
void searchByPosPtr(int*p, int*size)
{int pos;
   printf("\nEnter the position of the element to be accessed...\n"); scanf("%d",&pos);;

   printf("\nElement at position %d is %d.\n",pos,*(p+pos-1));
   printf("\n\n");
}

//Dynamic  fn-7
void reverseArrayPtr(int*p,int*size)
{
   int temp; i=1;
  
   for(i=0; i<((*size)/2);i++)
   {
     temp = *(p+i);
     *(p+i) = *(p+*size-i-1);
     *(p+*size-i-1) = temp;
   }
printf("\nReversed array is...\n");
display(p,size);
}

//Dynamic fn-8
void sortInsertPtr(int*p, int*size)
{ int elem,temp;
   
  printf("\nCurrent status of the array is...\n");
  display(p,size);

  printf("\nEnter the element for insert sort\n"); scanf("%d",&elem);

   p = (int*)realloc(p,(*size + 1)*sizeof(int));
   *(p+ *size) = elem;
   for(i=*size; i>0; i--)
 {
    for(j = *size-i; j>0; j--)
     {if( *(p+j)>*(p+j+1))
         { temp = *(p+j+1);
           *(p+j+1) = *(p+j);
           *(p+j)= temp;
         }
     }
 }
 *size = *size + 1;
printf("\nUpdated array is\n");
   display(p,size);
}
