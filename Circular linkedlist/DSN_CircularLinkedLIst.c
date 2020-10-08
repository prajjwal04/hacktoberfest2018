#include<stdio.h>
#include<stdlib.h>
struct student
{
    int rollno;
    int age;
    struct student* next;
};
struct student* start=NULL;
struct student* nn(int rno,int ag)
{
    struct student* p = (struct student*)malloc(sizeof(struct student*));
	p->rollno = rno;
	p->age = ag;
	p->next = NULL;
	return p;
}
void add()
{
    int rollno;
    int age;
    char ch;
    struct student* ptr;
    struct student* p1;
    do
    {
    printf("\nEnter rollno :");
    scanf("%d",&rollno);
    printf("\nEnter age");
    scanf("%d",&age);
    p1=nn(rollno,age);
    if(start==NULL)
    {
        start=p1;
        start->next=start;
    }
    else{
        ptr=start;
        while(ptr->next!=start)
        {
            ptr=ptr->next;
        }
        ptr->next=p1;
        p1->next=start;
}
        printf("\nDo you want to add node?(y/n)");
		fflush(stdin);
		scanf("%c",&ch);
		}
		while(ch=='y');
    }
int count(struct student* ptr)
{
    int count=0;
    if(ptr==NULL)
        return 0;
    else{
        do{
            count++;
            ptr=ptr->next;
        }
        while(ptr!=start);
        return count;
    }
}
void display(struct student* ptr)
{
    if(start==NULL)
        printf("list is empty");
    else
    {
        do
        {
            printf("\n%d--->%d",ptr->rollno,ptr->age);
            ptr=ptr->next;
        }
        while(ptr!=start);
    }
}
void insert()
{
    int pos,rollno,age,n,c;
    struct student *ptr,*p1;
    printf("Enter position");
    scanf("%d",&pos);
    n=count(start);
    if(pos<=0||pos>n+1)
        printf("Invalid Position");
    else
    {
        printf("\nEnter Rollno: ");
        scanf("%d",&rollno);
        printf("\nEnter Age: ");
        scanf("%d",&age);
        p1=nn(rollno,age);
        if (pos==1)
        {
            ptr=start;
            while(ptr->next!=start)
            {
                ptr=ptr->next;
            }
            p1->next=start;
            ptr->next=p1;
            start=p1;
        }
        else
        {
            ptr=start;
            c=0;
            while(pos-2>c)
            {
                ptr=ptr->next;
                c++;
            }
            ptr->next=p1;
            p1->next=ptr->next;
        }
    }
}
void delete()
{
    int pos,rollno,age,c,n;
    struct student* ptr,*ptr1;
    printf("\nEnter Position: ");
    scanf("%d",&pos);
    n=count(start);;
    if(pos<=0||pos>n)
        printf("Invalid Position");
    else
    {
        if(pos==1)
        {
            if(start==NULL)
            {
                free(start);
                start=NULL;
            }

        else
        {
            ptr=start;
            while(ptr->next!=start)
            {
                ptr=ptr->next;
            }
            start=start->next;
            free(ptr->next);
            ptr->next=start;
        }
    }
    else
        {
        c=0;
        ptr=start;
        while(pos-2>c)
        {
            ptr=ptr->next;
            c++;
        }
        ptr1=ptr->next;
        ptr->next=ptr->next->next;
        free(ptr1);
        ptr1=NULL;
    }
}
}
void update()
{
    int pos,n,c;
    struct student* ptr;
    printf("Enter Position:");
    scanf("%d",&pos);
    n=count(start);
    if(pos<=0||pos>n)
        printf("Invalid Position");
    else{
        ptr=start;
        c=0;
        while(pos-1>c)
        {
            ptr= ptr->next;
            c++;
        }
        printf("Enter new rollno.:");
        scanf("%d",&ptr->rollno);
        printf("Enter new age:");
        scanf("%d",&ptr->age);
        }
}
int main()
{
	int ch;
	while(1)
    {
        printf("\n 1. Add node");
        printf("\n 2. display ");
        printf("\n 3. Insert node");
        printf("\n 4. Delete node");
        printf("\n 5. Update node");
        printf("\n 6. Exit");
        printf("\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch){
        case 1: add();
        break;
        case 2: display(start);
        break;
        case 3:insert();
        break;
        case 4:delete();
        break;
        case 5:update();
        break;
        case 6:printf("%d",count(start));
        break;
        case 7: return 0;
        default:printf("Invalid option");
        }
    }
}
