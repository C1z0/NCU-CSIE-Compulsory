#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define STACKSIZE 100


typedef struct{
        int top;
        char items[STACKSIZE];
}stack;
bool IsFull(stack*);
bool IsEmpty(stack*);
void Push(stack *,char);
char Pop(stack *);
void createS();
int main()
{
    char input[66];
    while(scanf("%s", input)!=EOF){
        stack s;
        stack* ps = &s;
        createS(ps);
        int i=0;
        while(input[i]!= '\0'){
            if(input[i]=='('){
                Push(ps,'(');
            }
            else if(input[i]==')'){
                if(ps->top >= 0){
                    Pop(ps);
                }
                else{
                    Push(ps,')');
                }
            }
            i++;
        }

        if(IsEmpty(ps)){
            printf("1");
        }
        else{
            printf("0");
        }
    }

    return 0;
}

bool IsFull(stack* ps){
    if(ps->top == STACKSIZE-1){
        return 1;
    }
    else{
        return 0;
    }
}

bool IsEmpty(stack* ps){
    if(ps->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
void Push(stack *ps, char x){
    if(!IsFull(ps)){
        ps->items[++(ps->top)] = x;
    }
    else{
        printf("Full");
    }
}
char Pop(stack *ps){
    if(IsEmpty(ps)){
         printf("Empty");
    }
    else{
        return ps->items[ps->top--];
    }
}

void createS(stack *ps){
    ps->top = -1;
}
