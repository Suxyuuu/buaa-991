#include <stdio.h>
#define MAXSIZE 100

// 求出字符串s和t的公共最长单词(每个字符串均有英文字母和空格字符组成), 否则返回null 注意: 不得设置保存单词的存储空间

char * maxword(char * s, char * t);
int main(void){

    char s[MAXSIZE]="This is C programming text";
    char t[MAXSIZE]="This is a text for programming";

    printf("%s\n", maxword(s, t));

    getchar();
    return 0;
}

// 以s串中每个单词为准, 多次遍历t串
char * maxword(char * s, char * t){
    struct word
    {
        char * pos;
        int length;
    };
    struct word w[MAXSIZE];
    int count=0;
    char * pos=s, *t0=t;
    while (*s)
    {
        if (*s == *t0 && *s !=' ')  // 某个单词匹配过程中出现相同字符, 继续匹配下一个字符
        {
            s++;
            t0++;
        }
        else if ((*s==*t0 && *s==' ') || (*(s-1)==*(t0-1) && *t0=='\0'))    // s串中某个单词完全匹配成功, 保存单词信息, 然后开始匹配s串中下一个单词
        {
            w[count].pos=pos;
            w[count].length=s-pos;
            count++;
            pos=s+1;
            s=pos;
            t0=t;
        }
        else if(*t0=='\0' && (*(s-1)!=*(t0-1)))     // s中某个单词匹配过程中t字符串已经遍历完仍未匹配到, 指针指向s的下一个单词
        {
            t0=t;
            while (*pos!=' ' && *pos!='\0')
            {
                pos++;
            }
            pos++;
            s=pos;
        }
        
        else        // 匹配中出现不同字符, 指针指向t的下一个单词(可能在t的后面存在相同单词)
        {
            s=pos;
            while (*t0!=' ' && *t0!='\0')
            {
                t0++;
            }
            t0++;
        }   
    }
    if (*(s-1)==*(t0-1) && *s=='\0')    // s串遍历结束, 如果恰好最后一个单词可以匹配到需进行处理
    {
        w[count].pos=pos;
        w[count].length=s-pos;
        count++;
    }

    // 寻找最长单词
    pos=w[0].pos;
    int maxlen=0;
    for (int i = 0; i < count-1; i++)
    {
        if (w[i].length>w[i+1].length)
        {
            pos=w[i].pos;
            maxlen=w[i].length;
        }
        
    }
    *(pos+maxlen)='\0';     // 通过这种方式截断字符串来返回最长单词
    return pos;
      
}