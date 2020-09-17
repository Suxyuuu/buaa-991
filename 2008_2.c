// (使用命令行传入参数) 实现命令: replace oldfile newfile oldword newword
// 将某个文件中的所有的某个单词全部替换成新单词并保存至新文件中
// 要求: 必须有必要的正确性检查

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20

void changeword(char * oldfile, char * newfile, char * oldword, char * newword);

// 命令行键入: 2008_2 replace 2008_1.txt 2008_2.txt love hate
int main(int argc, char * argv[]){
    char * oldfile, * newfile , * oldword, * newword;
    if (argc!=6 || argv[1][0]!='r' || argv[1][1]!='e' || argv[1][2]!='p' || argv[1][3]!='l' || argv[1][4]!='a' || argv[1][5]!='c' || argv[1][6]!='e')
    {
        fprintf(stderr, "command error. Usage: 2008_2 replace 2008_1.txt 2008_2.txt love hate\n");
    }
    else
    {
        oldfile=argv[2];
        newfile=argv[3];
        oldword=argv[4];
        newword=argv[5];
        
        changeword(oldfile, newfile, oldword, newword);
        
    }
    
    return 0;
}

void changeword(char * oldfile, char * newfile, char * oldword, char * newword){
    FILE * fpold, * fpnew;
    char ch;
    char buff[MAX];
    if ((fpold=fopen(oldfile, "r"))==NULL)
    {
        fprintf(stderr, "can't find file: %s\n", oldfile);
        exit(0);
    }
    
    if ((fpnew=fopen(newfile, "w"))==NULL)
    {
        fprintf(stderr, "can't create or open file: %s\n", newfile);
        exit(0);
    }
    
    
    while ((ch=getc(fpold))!=EOF)
    {
        if (ch!=*oldword)
        {
            putc(ch, fpnew);
        }
        else
        {
            buff[0]=ch;
            int flag=1;
            int count=1;
            for (int i = 1; i < strlen(oldword); i++)
            {
                if ((ch=getc(fpold))!=oldword[i])
                {
                    buff[i]=ch;
                    flag=0;
                    count++;
                    break;
                }
            }
            if (flag)
            {
                for (int i = 0; i < strlen(newword); i++)
                {
                    putc(newword[i], fpnew);
                }
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    putc(buff[i], fpnew);
                }
                
            }
            
            
        }
        
        
    }

    if (fclose(fpold)!=0 || fclose(fpnew)!=0)
    {
        fprintf(stderr, "error in closing files\n");
        exit(0);
    }
    
}