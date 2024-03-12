#include<stdio.h>
#define size 30
struct stack{
    float a[size];
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

void push(struct stack* s,float x){
    s->top=s->top+1;
    s->a[s->top]=x;
}
float pop(struct stack* s){
    float x=s->a[s->top];
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
void getvalues(float alphabets[],char postfix[]){
    int i=0;
    while(postfix[i]!='\0'){
        if(isoperand(postfix[i])){
            printf("Enter the value of %c variable : ",postfix[i]);
            scanf("%f",&alphabets[postfix[i]-'a']);
        }
        i++;
    }
}
float compute(float op1,float op2,char operator){
    switch(operator){
        case '+':return op1+op2;
        case '-':return op1-op2;
        case '*':return op1*op2;
        case '/':return op1/op2;
    }
}
float valueof(char c,float alphabets[]){
    return (alphabets[c-'a']);
}
float evaluate(char postfix[],float values[]){
    struct stack s;
    initalise(&s);
    int i=0;
    while(postfix[i]!='\0'){
        if(isoperand(postfix[i])){
            push(&s,valueof(postfix[i],values));
        }
        else if(isoperator(postfix[i])){
            float op2=pop(&s);
            float op1=pop(&s);
            float result=compute(op1,op2,postfix[i]);
            push(&s,result);
        }
        i++;
    }
    return pop(&s);
}
void inputpostfix(char postfix[],float values[]){
    printf("Enter the postfix expression : ");
    scanf("%s",postfix);
    getvalues(values,postfix);
}
int main(){
    struct stack S;
    initalise(&S);
    char postfix[30];
    float values[26];
    inputpostfix(postfix,values);
    printf("%f",evaluate(postfix,values));

}