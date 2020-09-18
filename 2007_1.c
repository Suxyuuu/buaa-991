// 输入的任意正整数n, 产生并显示相应的n阶螺旋式数字方阵
// 3阶螺旋式数字方阵如下:
//  1  2  3
//  8  9  4
//  7  6  5

#include <stdio.h>
int main(void){
    int n;
    scanf("%d", &n);
    int a[n][n];
    int bound0=n-1,bound1=n-1,bound2=0,bound3=1;    //下标到什么值就要开始拐弯
	int start = 1;
	int x=0,y=0;                                    //分别是两个维度的下标
	int direction = 0;	                            //定义一个方向，0代表右，1代表下，2代表左，3代表上
	while(start<=n*n){
		if(direction == 0){
			a[x][y++] = start++;    //向右前进是行不变，列递增
			if(y == bound0){        //转弯的临界条件
				direction = 1;      //改变方向
				bound0--;           //改变下一次循环的临界条件
			}
		}
		else if(direction == 1){   
			a[x++][y] = start++;    //向下前进列不变，行递增
			if(x == bound1){   
				direction = 2;
				bound1--;
			}
		}
		else if(direction == 2){
			a[x][y--] = start++;    //向左前进行不变，列递减
			if(y == bound2){
				direction = 3;
				bound2++;
			}
		}
		else if(direction == 3){
			a[x--][y] = start++;    //向上前进列不变，行递减
			if(x == bound3){
				direction = 0;
				bound3++;
			}
		}
	
	}
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
    
    getchar();
    getchar();
    return 0;
}