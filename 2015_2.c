// 输出字母串中某个字符第一次出现的位置, 并将其删除, 输出删除前和删除后的字符串(若不存在该字符,则输出提示信息)

#include <stdio.h>
#include <string.h>

void solve(const char * bef, char key, char * aft);
int main(void){

    char strbef[20];
    char straft[20];
    char key;
    scanf("%s %c", strbef, &key);
    //printf("strbef: %s\n", strbef);
    //printf("key:%c\n", key);

    solve(strbef, key, straft);

    getchar();
    getchar();
    return 0;
}

void solve(const char * bef, char key, char * aft){
    int flag=0;
    int pos=0;
    for (int i = 0; i < strlen(bef); i++)
    {
        if (bef[i]==key)
        {
            flag=1;
            pos=i;
            break;
        }
        
    }
    if (!flag)
    {
        printf("There is no '%c' in this string!\n", key);
    }
    else
    {
        char * temp=aft;
        printf("The letter '%c' first appears in string is %d\n", key, pos);
        printf("string before delete: %s\n", bef);
        for (int i = 0; i < strlen(bef); i++)
        {
            if (i==pos)
            {
                continue;
            }
            *(aft++)=bef[i];
            
            
        }
        *aft='\0';
        
        printf("string after delete: %s\n", temp);
        
    }
    
    
    
}