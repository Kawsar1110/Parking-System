#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>



struct node
{
    int val;
    struct node* next;
};

typedef struct node node;
node *head = NULL;
int T=0;


void insert (int);
void del(int);
void display(node*);
void count(node*);
void Password();

COORD coord = {0, 0};
char password[100]={"a"};


int main()
{
    int  a, n;
    Password();
    getch();
    count(head);
    do
    {
    printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t\t Selected \t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t For parking the car press 1 \t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t For leaving the car press 2 \t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t       For Exit enter 0 \t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\n\t\t\tPlease Press: ");
    scanf("%d", &a);
    switch (a)
    {
    case 1:
    {
    if(T<10){
        printf("\n\t\t\tInter the car number you want to parking: ");
        scanf("%d", &n);
        insert (n);
        system("cls");
        }
    else
        printf("\n\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\t Please deallocate lot first \t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n\n");

    count(head);
    display(head);
    break;
    }

    case 2:
    {
        printf("\n\t\t\tInter the car number you want to leaving:");
        scanf("%d", &n);
        system("cls");
        del(n);
        count(head);
        display(head);
    break;
    }
    default:
        printf("\n\n\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB        Thanks For Using          \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n\n\n");
        break;
    }
    } while (a!=0);


}

void gotoxy (int x, int y)
{
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Password(void)
{

system("cls");
char d[25]="\tPassword Protected";
char ch,pass[10];
int i=0,j;
gotoxy(10,4);
printf("\t\t");
for(j=0;j<20;j++)
{
Sleep(50);
printf("\xDB");
}
for(j=0;j<20;j++)
{
Sleep(50);
printf("%c",d[j]);
}
for(j=0;j<20;j++)
{
Sleep(50);
printf("\xDB");
}
gotoxy(10,10);
gotoxy(15,7);
printf("\t\tEnter Password:");

while(ch!=13)
{
ch=getch();

if(ch!=13 && ch!=8){
putch('*');
pass[i] = ch;
i++;
}
}
pass[i] = '\0';
if(strcmp(pass,password)==0)
{

gotoxy(15,9);
printf("\n\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\t        Password match          \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
gotoxy(17,10);
printf("\n\n\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\t  Press any key to continue  \t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
getch();
count(head);
}
else
{
gotoxy(15,16);
printf("\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\tWarning!! Incorrect Password  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
getch();
Password();
}
}



void insert(int num)
{
    node *p;
    p=(node*)malloc(sizeof(node));
    p->val=num;
    p->next=head;
    head=p;
}


void del(int num)
{
    struct node *temp, //
    temp=head;
    while(temp!=NULL)
    {
    if(temp->val==num)
    {
        if(temp==head)
        {
        head=head->next;
        free(temp);
        printf("\n\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\t\t  Deallocated \t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
        return;
        }
        else
        {
        prev->next=temp->next;
        free(temp);
        printf("\n\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\t\t  Deallocated \t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
        return ;
        }
    }
    else
    {
        prev=temp;
        temp= temp->next;
    }
    }
    printf("\n\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\t  This car is not Available \t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    return;
}


void display(node *p)
{
    printf("\n\t\t\t\t      Available car no: ");
    while(p!=NULL){
        printf("%d ",p->val);
        p=p->next;
    }
}


void count(node *p)
{
    int total=0;
    while( p!=NULL )
    {
        p=p->next;
        total++;
    }
    T=total;
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t    Total parking lot : %d   \t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n",10-total);
    return;
}
