#include <stdio.h>

// sum=1^a+2^a+...+n^a

int psum(int a, int n);
int pow(int x, int exp);

int main(void){
    int a,n;
    scanf("%d %d", &a, &n);
    printf("sum=%d\n",psum(a,n));
    //printf("%d\n",pow(2,3));
    getchar();
    getchar();
    return 0;
}

int psum(int a, int n){
    if (a<=0 || n<=0)
    {
        return 0;
    }
    else
    {
        return pow(n,a)+psum(a,n-1);
    }
}

int pow(int x, int exp){
    int sum=1;
    for (int i = 0; i < exp; i++)
    {
        sum*=x;
    }
    return sum;
}