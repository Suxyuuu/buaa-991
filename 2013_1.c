#include <stdio.h>
#define MAXNUM 100

// 找出并删除一维整型数组a[100]中最小值元素 要求数组各元素通过键盘输入获得初值且对数组元素的引用全部用指针完成

int main(void){

    int a[MAXNUM];
    int * p=a;
    int * pos=a;
    for (int i = 0; i < MAXNUM; i++)
    {
        scanf("%d", p+i);
    }
    for (int i = 0; i < MAXNUM; i++)
    {
        if (*pos > *(p+i))
        {
            pos=p+i;    
        }
    }
    while (pos!=p+MAXNUM)
    {
        *(pos)=*(pos+1);
        pos++;
    }
    for (int i = 0; i < MAXNUM-1; i++)
    {
        printf("%d\n", *(p++));
    }
    
    getchar();
    getchar();
    return 0;
}
