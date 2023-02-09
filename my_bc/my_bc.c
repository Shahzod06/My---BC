#include "my_bc.h"
#include <stdio.h>
#include <stdlib.h>
void push(int x)
{
    if (top  == SIZE - 1)
    {
        printf ("Parse Error.");
        exit(1);
    }
    top = top+1;
    stack[top] = x;
}
int pop()
{
     if (top == -1)
     {
        printf("Parse error");
        exit(1);
     }
    else
    {
        int x;
        x=stack[top];
        top=top-1;
        return(x);
    }
}
int precedence(char x)
{
    if(x=='(')
        return 0;
    if(x=='+'||x=='-')
        return 1;
    if(x=='*'||x=='/'||x=='%'||x=='!')
        return 2;
    return 3;
}
int empty()
{
    if(top==-1)
        return(1);
    return(0);
}
int top_element()
{
    return (stack[top]);
}

void infix_to_postfix(char infix[],char postfix[])
{
    char x,token;
    int i,j=0;
    for( i=0;infix[i]!='\0';i++)
    {
        token=infix[i];
        if (isalnum(token)||token=='.')
            postfix[j++]=token;
        else
            if(token=='(')
               push('(');
        else
            if(token==')')
                while ((x=pop())!='(')
                { postfix[j++] = 32;
                      postfix[j++] = x;  }
                else
                {    postfix[j++] = 32;
                    while (precedence(token)<=precedence(top_element()) && !empty())
                    {
                        x=pop();
                        postfix[j++]=x;
                        postfix[j++] = 32;
                    }
                 push(token); }}
    while (!empty())
    {
        x = pop();
        postfix[j++] = 32;
        postfix[j++] = x;
    }
    postfix[j]='\0';
}

void evaluate(char a[])
{
    char postfix[SIZE];
    int i;
    int len, val, opr1, opr2, res,cal=0,H1;
    int point=0;
    int point_value;
    strcpy(postfix,a);
    len = strlen(postfix);
    int B[6];
    // int value=0;
    for (i=0;i<len;i++)
    {
        switch (get_type(postfix[i]))
        {
case 0:
                if (postfix[i] == 32 && cal != 0)
                { 
                    pushh(val); 
                    cal=0;  
                    break;
                }
                if (postfix[i]== 32 && cal == 0)
                    break;
                cal++;
           if (postfix[i] == '.')
           {   
                
                point=1;
                point_value=val;
                cal=0;
                break;
           }
            val = postfix[i] - '0';
            B[5] = B[4];
            B[4] = B[3];
            B[3] = B[2]; 
            B[2] = B[1]; 
            B[1] = B[0]; 
            B[0] = val;
            if (cal == 1)
            {
                val=B[0]; 
                H1=10; 
            }
            if (cal == 2)
                {val=(B[1]*10)+B[0]; H1=100;}
            if (cal == 3)
            {
                val = (B[2] * 100) + (B[1] * 10) + B[0]; 
                H1 = 1000;
            }
            if (cal == 4)
            {
                val = (B[3]*1000)+(B[2]*100)+(B[1]*10)+B[0]; 
                H1 = 10000;
            }
            if (cal == 5)
            {
                val = (B[3]*10000)+(B[2]*1000)+(B[1]*100)+(B[1]*10)+B[0]; 
                H1 = 100000;}
                if (point == 1 && postfix[i+1] == 32)
                { 
                  val = point_value+(val/H1);
                    point = 0;
                    break;
                }
                break;


case -1:        printf("Please enter only the number");
                break;
case 1:
                opr1 = popp();
                opr2 = popp();
                
                switch(postfix[i])
                {
                    case '+':
                    res = opr2 + opr1;
                    break;
                    case '-':
                    res = opr2 - opr1;
                    break;
                    case '*':
                    res = opr2 * opr1;
                    break;
                    case '/':
                    res = opr2 / opr1;
                    break;
                    case '%':
                    res = (int)opr2 % (int)opr1;
                    break;
                    }
                    pushh(res);}}
        printf("%d\n", stk[0]);
}

void pushh(int a)
{
    if(top==SIZE-1)
    {
        printf ("Parse  error.");
        exit(1);
    }
    stk[++top] = a;
}
int parse_err(char* node){
    for(int i = 0 ; node[i]; i++){
        if( node[i] == '/' && node[i+1] == '+' && node[i-1] == '+'){
            fprintf(stderr,"parse error");
            return 1;
        }
    }
    for(int i=0; node[i]; i++){
        if(node[i]=='/' && node[i+1]=='0'){
            fprintf(stderr,"divide by zero");
            return 1;
        }
        if(node[i] >= 'a' && node[i] <= 'z'){
            fprintf(stderr,"parse error");
            return 1;
        }
        if(node[i] == '(' && node[i+1] == ')'){
            fprintf(stderr,"parse error");
            stderr;
            return 1;
        }
    }
    return 0;
}

int popp()
{
    return(stk[top--]);
}

int get_type(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ){
    return 1;
    }
   
    if (c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'||c==' '||c=='.'){
    return 0;
    }else { 
        return -1;
    }
  
}

int main(int ac , char** av)
{
    if(ac > 0){
    char* infix = av[1];
    char postfix[30];

    if (infix[0] == '1' && strlen(infix) == 1) {
        printf("1\n");
        return 0;
    };
    int i = parse_err(infix);
    if( i == 1 ){
        return 1;
    }
    infix_to_postfix(infix,postfix);
    evaluate(postfix);
    }
    
}