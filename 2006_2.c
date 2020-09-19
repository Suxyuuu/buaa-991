// 通过命令行获取参数 实现命令: fcat file1 file2 file3
// 命令功能: 将file1, file2, file3连接成一个文件, 文件名由第一个参数file1决定

#include <stdio.h>

// 命令行键入: 2006_2 fcat 20061.txt 20062.txt 20063.txt
int main(int argc, char * argv[]){
    if (argc!=5 || argv[1][0]!='f' || argv[1][1]!='c' || argv[1][2]!='a' || argv[1][3]!='t')
    {
        fprintf(stderr, "command error! Usage: 2006_2 fcat 20061.txt 20062.txt 20063.txt\n");
        return 0;
    }
    char * filename1, * filename2, *filename3;
    filename1=argv[2];
    filename2=argv[3];
    filename3=argv[4];
    FILE * fp1, * fp2, *fp3;
    if ((fp1=fopen(filename1, "a"))==NULL || (fp2=fopen(filename2, "r"))==NULL || (fp3=fopen(filename3, "r"))==NULL)
    {
        fprintf(stderr, "files open error!\n");
        return 0;
    }
    char ch;
    while ((ch=getc(fp2))!=EOF)
    {
        putc(ch, fp1);
    }
    while ((ch=getc(fp3))!=EOF)
    {
        putc(ch, fp1);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    printf("Successful!\n");
    //getchar();
    return 0;
    
}