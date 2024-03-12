#include<stdio.h>
struct sparse{
    int rno;
    int cno;
    int value;
};
void ReadSparseMatrix(struct sparse s[]){
    int a,b;
    printf("Enter the dimension of the matrix: \n");
    scanf("%d %d",&a,&b);
    int arr[a][b];
    printf("Enter entries of matrix:  \n");
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    s[0].rno=a;
    s[0].cno=b;
    int nz=0,k=1;

    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(arr[i][j]!=0){
                s[k].rno=i;
                s[k].cno=j;
                s[k].value=arr[i][j];
                nz++;
                k++;
            }
        }
    }
    s[0].value=nz;
}
void PrintSparseMatrix(struct sparse s[]){
    int a=s[0].rno;
    int b=s[0].cno;
    int k=1;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(i==s[k].rno&&j==s[k].cno){
                printf("%d ",s[k].value);
                k++;
            }
            else{
                printf("%d ",0);
            }
        }
        printf("\n");
    }
}
void AddSparseMatrix(struct sparse s1[],struct sparse s2[],struct sparse s3[]){
    int k1=1,k2=1,k3=1;
    if(s1[0].rno==s2[0].rno&&s1[0].cno==s2[0].cno){
        int a=s1[0].rno;
        int b=s1[0].cno;
        s3[0].rno=a;
        s3[0].cno=b;
        int nz=0;
        int m=s1[0].value,n=s2[0].value;
        while(k1<=m&&k2<=n){
            if(s1[k1].rno<s2[k2].rno||(s1[k1].rno==s2[k2].rno&&s1[k1].cno<s2[k2].cno)){
                    s3[k3].rno = s1[k1].rno;
                    s3[k3].cno = s1[k1].cno;
                    s3[k3].value=s1[k1].value;
                    k1++;
                    k3++;
                    nz++;
            }
            else if(s1[k1].rno>s2[k2].rno||(s1[k1].rno==s2[k2].rno&&s1[k1].cno>s2[k2].cno)){
                    s3[k3].rno = s2[k2].rno;
                    s3[k3].cno = s2[k2].cno;
                    s3[k3].value=s2[k2].value;
                    k2++;
                    k3++;
                    nz++;
            }
            else if(s1[k1].value+s2[k2].value!=0){
                    s3[k3].rno = s1[k1].rno;
                    s3[k3].cno = s1[k1].cno;
                    s3[k3].value=s1[k1].value+s2[k2].value;
                    k1++;
                    k2++;
                    k3++;
                    nz++;
            }
            else{
                k1++;
                k2++;
            }
        }
        while(k1<=m){
                    s3[k3].rno = s1[k1].rno;
                    s3[k3].cno = s1[k1].cno;
                    s3[k3].value=s1[k1].value;
                    k1++;
                    k3++;
                    nz++;

        }
        while(k2<=n){
                    s3[k3].rno = s2[k2].rno;
                    s3[k3].cno = s2[k2].cno;
                    s3[k3].value=s2[k2].value;
                    k2++;
                    k3++;
                    nz++;
        }
        s3[0].value=nz;
        PrintSparseMatrix(s3);
    }
    else{
        printf("The dimensions of matrix are not same.\n");
    }

}
int main(){
    struct sparse sparsemat1[30],sparsemat2[30],sparsemat3[30];
    while(1){
    printf("Menu : \n");
    printf("1) Form a sparse Matrix from normal Matrix \n2) Print normal matrix from sparse matrix \n3) Add two sparse matrix \n4) Exit \n");
    printf("Enter the Choice \n\n");
    int x;
    scanf("%d",&x);
    if(x==1){
        ReadSparseMatrix(sparsemat1);
        ReadSparseMatrix(sparsemat2);
    }
    else if(x==2){
        PrintSparseMatrix(sparsemat1);
        printf("\n");
        PrintSparseMatrix(sparsemat2);
    }
    else if(x==3){
        AddSparseMatrix(sparsemat1,sparsemat2,sparsemat3);
    }
    else{
        break;
    }
    }
}