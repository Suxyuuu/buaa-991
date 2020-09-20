// 输入n 输出n以为所有素数
// 与2007_2 类似

#include <stdio.h>

void makeprimes(int * primes, int n);
int main(void){
    int n;
    scanf("%d", &n);
    int primes[n];
    makeprimes(primes, n);
    for (int i = 0; i < n-1; i++)
    {
        printf("%d,",primes[i]);
    }
    printf("%d\n", primes[n-1]);
    
    getchar();
    getchar();
    return 0;

}
void makeprimes(int primes[], int num) 
{     
    int i, j, cnt;          
    primes[0] = 2;     
    primes[1] = 3;          
    for(i = 5, cnt = 2; cnt < num; i += 2)     
    {         
        int flag = 1;          
        for(j = 1; primes[j]*primes[j] <= i; ++j)         
        {             
            if(i%primes[j] == 0)             
            {                 
                flag = 0; 
                break;             
            }         
        }         
        if(flag) 
            primes[cnt++] = i;     
    }
}