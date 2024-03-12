#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct headnode{
    struct node *start,*end;
    int count;
    float avg;
};
void initheadnode(struct headnode* H){
    H->start=NULL;
    H->end=NULL;
    H->count=0;
    H->avg=0;
};
void insert_at_beginning(struct headnode *h,int x){
    struct node* p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->next=h->start;
    if(h->start==NULL){
        h->start=p;
        h->end=p;
        h->count=1;
        h->avg=p->data;
    }
    else{
        h->start=p;
        h->count=h->count+1;
        h->avg=((h->count-1)*(h->avg)+(p->data))/(h->count);
    }
}
void insert_at_end(struct headnode *h,int x){
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->next=NULL;
    if(h->end==NULL){
        h->start=p;
        h->end=p;
        h->count=1;
        h->avg=p->data;
    }
    else{
        (h->end)->next=p;
        h->end=p;
        h->count=h->count+1;
        h->avg=((h->count-1)*(h->avg)+(p->data))/(h->count);
    }
}
void insertxaftery(struct headnode* h,int x,int y){
    struct node* q=h->start;
    struct node* p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    while(q!=NULL){
        if(q->data==y){
            break;
        }
        q=q->next;
    }
    p->next=q->next;
    q->next=p;
    if(p->next==NULL){
        h->end=p;
    }
    h->count=h->count+1;
    h->avg=((h->count-1)*(h->avg)+(p->data))/(h->count);
}
void display(struct headnode h){
    struct node* q=h.start;
    while(q!=NULL){
        printf("%d ",q->data);
        q=q->next;
    }
    printf("\n");
}
struct node* search(struct headnode h,int x){
    struct node* q=h.start;
    while(q!=NULL){
        if(q->data==x){
            return q;
        }
        q=q->next;
    }
    return NULL;
}
void deletex(struct headnode *h, int x){
    struct node* s=h->start;
    if(s==NULL){
        return;
    }
    else if(s->data==x){
        h->start=s->next;
        h->count=h->count-1;
        h->avg=((h->count+1)*(h->avg)-(s->data))/(h->count);
        struct node* q=s;
        s=(s)->next;
        free(q);
        return;
    }
    struct node* q=s;
    while((q->next)!=NULL&&(q->next)->data!=x){
        q=q->next;}
    if(q->next!=NULL){
        h->count=h->count-1;
        h->avg=((h->count+1)*(h->avg)-x)/(h->count);
        struct node* p=q->next;
        q->next=(q->next)->next;
        free(p);  
        if(q->next==NULL){
            h->end=q;
        } 
    }
}
void reversell(struct headnode *h){
    struct node*s=h->start;
    if(s==NULL||(s)->next==NULL){
        return;
    }
    struct node *q,*prev,*fwd;
    h->end=s;
    q=s;
    prev=NULL;
    while(q->next!=NULL){
        fwd=q->next;
        q->next=prev;
        prev=q;
        q=fwd;
    }
    q->next=prev;
    s=q;
    h->start=s;
}
int main(){
    struct headnode H;
    initheadnode(&H);
    while(1){
    printf("Menu (Headnode): \n");
    printf("1) Insert at beginning \n2) Insert at end \n3) Insert a value after a particular value \n4) Display linked list \n5) Search \n6) Delete a value \n7) Reverse the linked list \n8) Exit \n");
    printf("Enter the Choice \n\n");
    int x;
    scanf("%d",&x);
    if(x==1){
        int v;
        printf("Enter the value to be inserted at the beginning : ");
        scanf("%d",&v);
        insert_at_beginning(&H,v);
    }
    else if(x==2){
        int v;
        printf("Enter the value to be inserted at the end : ");
        scanf("%d",&v);
        insert_at_end(&H,v);
    }
    else if(x==3){
        int a,b;
        printf("Enter the value to be inserted and the value after which it has to be inserted : ");
        scanf("%d %d",&a,&b);
        insertxaftery(&H,a,b);
    }
    else if(x==4){
        display(H);
    }
    else if(x==5){
        int v;
        printf("Enter the value to be searched : ");
        scanf("%d",&v);
        struct node* found=search(H,v);
        printf("The element is present at the address : %d\n",found);
    }
    else if(x==6){
        int v;
        printf("Enter the value to be deleted : ");
        scanf("%d",&v);
        deletex(&H,v);
    }
    else if(x==7){
        reversell(&H);
    }
    else{
        break;
    }
    }
}