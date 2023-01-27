#include<stdio.h>
#include<stdlib.h>

typedef struct Time{
    int hour;
    int minute;
    int second;
} time;

time* read(time*p)
{  
    printf("\nEnter 'hours':\t");
    scanf("%d",&(p->hour));
    
    printf("\nEnter 'minutes':\t");
    scanf("%d",&(p->minute));
    
    printf("\nEnter 'seconds':\t");
    scanf("%d",&(p->second));
    
    if((p->hour)>23 || (p->hour)<0 || (p->minute)>59 || (p->minute)<0 || (p->second)>59 || (p->second)<0)
    {
        printf("\nInvalid time\ntime set to 0:0:0\n");
        p->hour = p->minute = p->second = 0;
        return p;
    }
    
    else{return p;}
}

void display(time*p)
{
    printf("\nThe time is %d:%d:%d\n",(p->hour),(p->minute),(p->second));
}

time* update(time*p)
{
    p->second += 1;
    
    if(p->second > 59)
    {
        p->second = 00;
        
        p->minute += 1;
        
    }
    
    if(p->minute > 59)
        {
           p->minute = 00;
           p->hour += 1;
        }  
        
    if(p->hour > 23)
           {
              p->hour = 00;
           }
    
    return p;
}

void timeAdd(time one, time two)
{     
    printf("\nEnter the times you want to add...\n");
    printf("\nTime 1\n");
    printf("Hour:\t"); scanf("%d",&one.hour);
    printf("\nMinute:\t"); scanf("%d",&one.minute);
    printf("\nSecond:\t"); scanf("%d",&one.second);
    
    printf("\nTime 1\n");
    printf("Hour:\t"); scanf("%d",&two.hour);
    printf("\nMinute:\t"); scanf("%d",&two.minute);
    printf("\nSecond:\t"); scanf("%d",&two.second);
    
    time add;int day = 0;
    add.second = one.second + two.second;
    add.minute = one.minute + two.minute;
    add.hour =   one.hour + two.hour;
    
    if(add.second > 59)
    {
        add.minute += (add.second/60);
        add.second =  (add.second%60);
    }
    
    if(add.minute > 59)
    {
        add.hour += (add.minute/60);
        add.minute =  (add.minute%60);
    }
    
    if(add.hour > 23)
    {
        day += (add.hour/24);
        add.hour =  (add.hour%24);
    }
    
    printf("\nResultant time after adding the above inputted two times is...\n");
    printf("\n%d Days:%d hours: %d minutes:%d seconds\n",day,add.hour,add.minute,add.second);
    
    
}


void main()
{  
    time*q; time T1; time T2;
    q = (time*)calloc(1,sizeof(time));
    
    int choice;
    
    
    while(1)
    {   
        printf("\n\n1.Read time\n2.Display time\n3.Update time(by 1 sec)\n4.Add two times\n5.Exit\nEnter your choice:\t"); scanf("%d",&choice);
        switch(choice)
        {
            case 1: q = read(q); break;
            
            case 2: display(q); break;
            
            case 3: q = update(q);
                    printf("\nAfter the updation...\n");
                    display(q);
                    break;
                
            case 4: timeAdd(T1, T2); break;
            
            case 5: exit(0);
            
            default: printf("\nInvalid choice...\n");
        }
    }

}

