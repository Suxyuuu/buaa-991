// 输出1-1000内的所有同构数
// 同构数: 对于一个N位的自然数，其平方数的末尾N位数等于该数本身
// 如: 5 -> 25;  25 -> 625

#include <stdio.h>

int main(void){
    int length, exp;
    for (int i = 1; i < 1000; i++)
    {
        int num=i;
        int tail=0;
        length=0;
        exp=i*i;
        while (num/10>=1)
        {
            length++;
            num=num/10;
        }
        length++;
        
        int j=1;
        for (int i = 0; i < length; i++)
        {
            j*=10;
        }
        if (exp%j==i)
        {
            printf("%d ", i);
        }
        
    }

    getchar();
    return 0;
    
}