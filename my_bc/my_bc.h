#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define SIZE 50

void push(int);
int pop();
int precedence(char);
int empty();
int top_element();
void infix_to_postfix(char [],char []);
void pushh(int);
int popp();
int get_type(char);
void evaluate(char []);
int stack[SIZE];
int top = -1;
int stk[SIZE];