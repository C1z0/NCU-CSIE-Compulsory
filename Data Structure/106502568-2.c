#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define STACKSIZE 100


typedef struct
{
    int top;
    char items[STACKSIZE];
    double smeti[STACKSIZE];
} stack;

void toPostfix(char*,char*,int*,stack* );
int calPostfix(char*,char*,stack* );
int priority(char);
bool IsFull(stack*);
bool IsEmpty(stack*);
void Push(stack*,char);
void Husp(stack*,char);
char Pop(stack*);
double Pop2(stack*);
void createS();

int main()
{
    char input[100];
    while(scanf("%s", input)!=EOF)
    {
        char out[100]= {'\0'};
        int neg[100]= {'\0'};
        stack s;
        createS(&s);
        toPostfix(input,out,neg,&s);
        calPostfix(out,neg,&s);
    }

    return 0;
}

void toPostfix(char* num,char* out,int* neg,stack* s)
{
    int j=0,a=0;
    for (int i=0; num[i]!='\0'; i++)
    {
        switch (num[i])
        {

        case'/':
        case'+':
        case'*':
            while (priority(s->items[s->top])>=priority(num[i]))
            {
                out[j++]=Pop(s);
            }
            Push(s,num[i]);
            break;
        case'-':
            if(num[i-1]=='(')
            {
                neg[a++]=1;
            }
            while (priority(s->items[s->top])>=priority(num[i]))
            {
                out[j++]=Pop(s);
            }
            Push(s,num[i]);
            break;
        case'(':
            Push(s,'(');
            break;

        case')':
            while (s->items[s->top]!='(')
            {
                out[j++]=Pop(s);
            }
            s->top--;
            break;

        default:
            out[j++]=num[i];
        }
    }

    while(s->top!=-1)
    {
        out[j++]=Pop(s);
    }
    for (int i=0; out[i]!='\0'; i++)
    {
        printf("%c", out[i]);
    }
    printf("\n");
}
int calPostfix(char* out,char* neg,stack* s)
{
    int i=0,top=-1;
    double temp=0;
    while(out[i]!='\0')
    {
        double num1=0,num2=0;
        switch(out[i])
        {
        case '+':
            num1=Pop2(s);
            num2=Pop2(s);
            Hsup(s,num1+num2);
            break;
        case '-':
            top++;
            if(neg[top]==1)
            {
                Hsup(s,Pop2(s)*(-1));
            }
            else
            {
                Hsup(s,Pop2(s)*(-1)+Pop2(s));
            }
        case '*':
            Hsup(s,Pop2(s)*Pop2(s));
            break;
        case '/':
            Hsup(s,1/Pop2(s)*Pop2(s));
            break;
        default:
            temp=(double)(out[i]-'0');
            printf("%f\n",temp);
            Hsup(s,temp);
            break;
        }
        i++;
    }
    if(s->smeti[s->top]>0)
    {
        printf("%d\n",(int)(Pop2(s)+0.5));
    }
    else
    {
        printf("%d\n",(int)(Pop2(s)-0.5));
    }
}

int priority(char c)
{
    switch(c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

bool IsFull(stack* s)
{
    if(s->top == STACKSIZE-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool IsEmpty(stack* s)
{
    if(s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Push(stack *s, char x)
{
    if(!IsFull(s))
    {
        s->items[++(s->top)] = x;
    }
}
char Pop(stack *s)
{
    if(!IsEmpty(s))
    {
        return s->items[s->top--];
    }
}

void Hsup(stack *s, double x)
{
    if(!IsFull(s))
    {
        s->smeti[++(s->top)] = x;
    }
}
double Pop2(stack *s)
{
    if(!IsEmpty(s))
    {
        return s->smeti[s->top--];
    }
}

void createS(stack *s)
{
    s->top = -1;
}
