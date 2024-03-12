#include<stdio.h>
#define size 30
struct stack{
    int a[size];
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

void push(struct stack* s,int x){
    s->top=s->top+1;
    s->a[s->top]=x;
}
int pop(struct stack* s){
    int x=s->a[s->top];
    s->top=s->top-1;
    return x;
}
void display(struct stack s){
    for(int i=0;i<=s.top;i++){
        printf("%d ",s.a[i]);
    }
    printf("\n");
}
void menu_insert(struct stack* S){
    printf("Enter the value to be inserted : ");
    int v;
    scanf("%d",&v);
    if(!isfull(S)){
        push(S,v);
    }
}
void menu_delete(struct stack* S){
    if (!isempty(S)){
        int v = pop(S);
        printf("%d has been deleted \n", v);
    }
    else{
        printf("Stack is empty. No value has been deleted.\n");
    }
}
int main(){
    struct stack S;
    initalise(&S);
    while(1){
    printf("Menu : \n");
    printf("1) Push into stack \n2) Pop from stack \n3) Display stack \n4) Exit \n");
    printf("Enter the Choice \n\n");
    int x;
    scanf("%d",&x);
    if(x==1){
        menu_insert(&S);
    }
    else if(x==2){
        menu_delete(&S);
    }
    else if(x==3){
        display(S);
    }
    else{
        break;
    }
    }
}