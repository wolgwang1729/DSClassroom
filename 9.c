#include<stdio.h>
struct poly{
    float coeff;
    int expo;
};
void swap(struct poly* a, struct poly* b) {
    struct poly t = *a;
    *a = *b;
    *b = t;
}

int partition (struct poly arr[], int low, int high) {
    int pivot = arr[high].expo;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].expo > pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(struct poly arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void sortpoly(struct poly p[], int n) {
    quickSort(p, 0, n-1);
}
void printpoly(struct poly p[],int n){
    printf("The polynomial is: \n");
    for(int i=0;i<n;i++){
        printf("(%0.2f)x^%d",p[i].coeff,p[i].expo);
        if(i!=n-1){
            printf("+");
        }
    }
    printf("\n");
}
void readPoly(struct poly p[],int *s){
    printf("\n");
    printf("Enter the polynomial: \n");
    printf("Enter the numbers of terms in the polynomial : ");
    int n;
    scanf("%d",&n);
    *s=n;
    printf("\n");
    for(int i=0;i<n;i++){
        int c,e;
        printf("Enter the coefficient : ");
        scanf("%f",&p[i].coeff);
        printf("Enter the exponent : ");
        scanf("%d",&p[i].expo);
        printf("\n");
    }
    sortpoly(p,*s);
    printpoly(p,*s);
}
void addpoly(struct poly p1[],struct poly p2[],struct poly p3[],int s1,int s2,int*s3){
    int i=0,j=0,k=0;
    while(i<s1&&j<s2){
        if(p1[i].expo==p2[j].expo){
            p3[k].expo=p1[i].expo;
            p3[k].coeff=p1[i].coeff+p2[j].coeff;
            k++;
            i++;
            j++;
        }
        else if(p1[i].expo>p2[j].expo){
            p3[k].expo=p1[i].expo;
            p3[k].coeff=p1[i].coeff;
            k++;
            i++;
        }
        else{
            p3[k].expo=p2[j].expo;
            p3[k].coeff=p2[j].coeff;
            k++;
            j++;
        }
    }
    while(i<s1){
            p3[k].expo=p1[i].expo;
            p3[k].coeff=p1[i].coeff;
            k++;
            i++;
    }
    while(j<s2){
            p3[k].expo=p2[j].expo;
            p3[k].coeff=p2[j].coeff;
            k++;
            j++;
    }
    *s3=k;
}
void multiterm(struct poly p1[],struct poly term,struct poly p5[],int s2){
    for(int i=0;i<s2;i++){
        p5[i].coeff=p1[i].coeff*term.coeff;
        p5[i].expo=p1[i].expo+term.expo;
    }
}
void multipoly(struct poly p1[],struct poly p2[],struct poly p4[],int s1,int s2,int*s4){
    struct poly p5[30];
    int s5=s2,s6;
    *s4=0;
    for(int i=0;i<s1;i++){
        multiterm(p2,p1[i],p5,s2);
        addpoly(p4,p5,p4,*s4,s5,s4);
    }
}
int main(){
    while(1){
    printf("Menu : \n");
    printf("1) Enter polynomial \n2) Add polynomials \n3) Multiply polynomials \n4) Exit \n");
    printf("Enter the Choice \n\n");
    int x;
    scanf("%d",&x);
    struct poly p1[20],p2[20],p3[30],p4[30];
    int s1,s2,s3,s4;
    if(x==1){
        readPoly(p1,&s1);
        readPoly(p2,&s2);
    }
    else if(x==2){
        addpoly(p1,p2,p3,s1,s2,&s3);
        printpoly(p3,s3);
    }
    else if(x==3){
        multipoly(p1,p2,p4,s1,s2,&s4);
        printpoly(p4,s4);
    }
    else{
        break;
    }
    }
}