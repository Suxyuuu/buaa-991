// 计算sum=a+aa+aaa+...+aaaa(共n项)

#include <stdio.h>

int sum(int a, int n);
int main(void){

    int a,n;
    printf("input a n:\n");
    scanf("%d %d", &a, &n);
    printf("%d\n", sum(a, n));
    
    getchar();
    getchar();
    return 0;
}

int sum(int a, int n){
    if (n==1)
    {
        return a;
    }
    else
    {
        int s=0;
        for (int i = 0; i < n; i++)
        {
            s=s*10+a;
        }
        
        return s+sum(a, n-1);
    }
    
    
}