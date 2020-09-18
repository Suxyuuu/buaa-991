// 命令行输入参数n 实现命令 outprime n
// 实现效果: 输出从2开始的n个素数

#include <stdio.h>
#include <stdlib.h>

void makeprimes(int * primes, int n);
// 命令行键入: 2007_2 outprime n
int main(int argc, char * argv[]){
    if (argc!=3 || argv[1][0]!='o' || argv[1][1]!='u' || argv[1][2]!='t' || argv[1][3]!='p' || argv[1][4]!='r' || argv[1][5]!='i' || argv[1][6]!='m' || argv[1][7]!='e')
    {
        printf("%d\n",argc);
        printf("%s\n",argv[1]);
        fprintf(stderr, "command error. Usage: 2007_2 outprime n\n");
    }
    else
    {
        int n=atoi(argv[2]);
        int primes[n];
        makeprimes(primes, n);
        for (int i = 0; i < n-1; i++)
        {
            printf("%d,",primes[i]);
        }
        printf("%d\n", primes[n-1]);
    }
    
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