/****************************************************************************************************************************************************************
 NAME - IRAM ABID
 FACULTY ROLL NO- 20COB051
 ENROLLMENT NO- GJ8239
 
                /----------------PROGRAM TO CONVERT INFIX TO POSTFIX USING LINKED LIST------------------/
                
***************************************************************************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{

char data;
struct node *link;


}*top=NULL,*pstart=NULL;


void push (char opr)
{

    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=opr;
    if(top==NULL)
    {
        top=p;
        p->link=NULL;
    }
    else
    {
        p->link=top;
        top=p;
    }
}
char pop()
{
    struct node *x,*y;
    char k;
    if(top==NULL)
    {
    printf("stack underflow\n");
    return 0;

    }
    else
    {
        x=top;
        top=top->link;
        k=x->data;
        free(x);
        x=NULL;
        return k;
    }
}
void insert(char ch)
{
    struct node *temp1,*temp2;
    temp2=(struct node *)malloc(sizeof(struct node));
    temp2->link=NULL;
    temp2->data=ch;
    temp1=pstart;

    if(pstart==NULL)
        {
            pstart=temp2;
        }
    else
        {
        while(temp1->link!=NULL)
            temp1=temp1->link;
            temp1->link=temp2;
        }
}


void print_postfix()
{
    struct node *to;
    if(pstart==NULL)
    printf(" ");
    else
    {
        to=pstart;
        while(to!=NULL)
        {
        printf("%c",to->data);
        to=to->link;

        }
    }
}


/*Function to convert infix to postfix */

int precedence(char ch)
{

    if(ch=='^')
    return (5);
    else if(ch=='*' || ch== '/')
    return (4);
    else if (ch== '+' || ch== '-')
    return (3);
    else
    return (2);
}


/*function to convert infix to postfix */

void infixtopost(char infix[])
{

    int len;
    int index=0;
    char opr,temp;
    len= strlen(infix);
    
    while(len>index)
    {
        opr=infix[index];

        switch(opr)
        {

        case '(':
        push(opr);
        break;

        case ')':
        temp=pop();
        while(temp!='(')
        {
        insert(temp);
        temp=pop();
        }
        break;

        case '^':
        case '+':
        case '-':
        case '*':
        case '/':
        if(top==NULL)
        {
            push(opr);
  
        }
        else
        {
        while(top!=NULL && (precedence(top->data)>=precedence(opr)))
        {
            temp=pop();
            insert(temp);

        }
        push(opr);

        }   
        break;
        default:
        insert(opr);

         }
         index=index+1;


    }
    while(top!=NULL)
    {
    temp=pop();
    insert(temp);

    }
    print_postfix();
    return;
}


int main()
{
    system("clear");
    char arr_infix[100];

    printf("ENTER THE INFIX EXPRESSION YOU WANT TO CONVERT IN POSTFIX :\t");
    gets(arr_infix);

    printf("\n\n THE EQUIVALENT POSTFIX EXPRESSION :\t ");
    infixtopost(arr_infix);
    getchar();
    return 0;
}