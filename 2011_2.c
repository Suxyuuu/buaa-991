/* 将一个整型数组循环向右移动k个位置

* 基本思路: 用k个位置存储后k个元素, 前面n-k个元素后移, 最后前面k个位置补全
* 较佳思路: 根据k值将数值划分为两部分, 两部分分别逆置后再整体逆置(只需要一个元素大小的辅助空间)

* 本代码实现第二种思路
*/

#include <stdio.h>
#define MAXSIZE 7   // 初始化为 10 20 30 40 50 60 70

void reverse(int * a, int length);

int main(void){

    int a[MAXSIZE];
    for (int i = 0; i < MAXSIZE; i++)
    {
        a[i]=(i+1)*10;
    }
    int key;
    scanf("%d", &key);
    reverse(a, MAXSIZE-key);
    reverse(a+MAXSIZE-key, key);
    reverse(a, MAXSIZE);

    for (int i = 0; i < MAXSIZE; i++)
    {
        printf("%d ", a[i]);
    }
    

    getchar();
    getchar();
    return 0;
}

void reverse(int * a, int length){
    int temp;
    for (int i = 0; i < length/2; i++)
    {
        temp=*(a+i);
        *(a+i)=*(a+length-i-1);
        *(a+length-i-1)=temp;
    }
    
}