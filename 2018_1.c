/* 
* 求某个长字符串中指定字符串出现的频率
* 如 abcdefgdefkd 中 def 为2次  aaaa 中 aa 为3次
*/

#include <stdio.h>
#include <string.h>
#define MAXSIZE 100

int freqs(char *source, char *destination);
int freqs2(char *source, char *destination);
int main(void)
{
    char source[MAXSIZE] = "aaccdefgdefkdxefaaaa";
    char destination[MAXSIZE] = "aa";
    printf("%d\n", freqs(source, destination));
    printf("%d\n", freqs2(source, destination));
    getchar();
    return 0;
}

int freqs(char *source, char *destination)
{
    int desnum = strlen(destination);
    int count = 0;
    int flag;
    int m;
    for (int i = 0; i < strlen(source) - desnum + 1; i++)
    {
        m = i;
        flag = 1;
        for (int j = 0; j < desnum; j++, m++)
        {
            if (source[m] != destination[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            count++;
        }
    }
    return count;
}

int freqs2(char *source, char *destination)
{
    char *p = source;          // 主串比较游走指针
    char *q = destination;     // 子串比较游走指针
    char *havejudged = source; // 指向主串已经比较过的位置
    int count = 0;
    int flag = 0;
    while (*havejudged != '\0')
    {
        p = havejudged;
        q = destination;
        while (*q != '\0')
        {
            if (*p == *q)
            {
                p++;
                q++;
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            count++;
        }
        havejudged++;
    }
    return count;
}