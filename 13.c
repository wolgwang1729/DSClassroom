#include<stdio.h>
#define size 30
struct stack{
    char a[size];
    int top;
};
void initalise(struct stack* s){
    s->top=-1;
}
int isfull(struct stack* s){
    if(s->top+1==size){
        return 1;
    }
    return 0;
}
int isempty(struct stack* s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}
char stacktop(struct stack s){
    return s.a[s.top];
}
void push(struct stack* s,char x){
    s->top=s->top+1;
    s->a[s->top]=x;
}
char pop(struct stack* s){
    char x=s->a[s->top];
    s->top=s->top-1;
    return x;
}
int isoperand(char c){
    if(c>='a'&&c<='z'){
        return 1;
    }
    return 0;
}
int isoperator(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'){
        return 1;
    }
    return 0;
}
int ISP(char c){
    switch(c){
        case '*': return 2;
        case '/': return 2;
        case '+': return 1;
        case '-': return 1;
        case '(': return 0;
        case'#' :return -1;
    }
}
int ICP(char c){
    switch(c){
        case '*': return 2;
        case '/': return 2;
        case '+': return 1;
        case '-': return 1;
        case '(': return 4;
    }
}
void convert_to_postfix(char infix[],char postfix[]){
    struct stack s;
    initalise(&s);
    int i=0,j=0;
    push(&s,'#');
    while(infix[i]!='\0'){
        if(isoperand(infix[i])){
            postfix[j++]=infix[i++];
        }
        else if(isoperator(infix[i])){
            if(ISP(stacktop(s))<ICP(infix[i])){
                push(&s,infix[i]);
                i++;
            }
            else{
                while(ISP(stacktop(s))>=ICP(infix[i])){
                    postfix[j++]=pop(&s);
                }
                push(&s,infix[i]);
                i++;
            }
        }
        else if(infix[i]=='('){
            push(&s,'(');
            i++;
        }
        else if(infix[i]==')'){
            char x;
            do{
                x=pop(&s);
                if(x!='('){
                    postfix[j++]=x;
                }
            }
            while(x!='(');
            i++;
        }
    }
    while(s.top>=0){
        postfix[j++]=pop(&s);
    }
}
void inputinfix(char infix[]){
    printf("Enter the infix expression : ");
    scanf("%s",infix);
}
void printpostfix(char postfix[]){
    int i=0;
    while(postfix[i]!='#'){
        printf("%c",postfix[i]);
        i++;
    }
}
int main(){
    char infix[30];
    char postfix[30];
    inputinfix(infix);
    convert_to_postfix(infix,postfix);
    printpostfix(postfix);
}