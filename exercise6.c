#include <stdio.h>
#include <string.h>


int M = 0;
unsigned long long S = 0;

void encrypt(int S, char* str, int len)
{
    
    for(int j = 0; j < len; j++)
    {
        char c = str[j];//這樣就可以一次取一個字元了!!
        
        if(c >= 'A' && c <= 'Z')
        {
            c = (c - 'A' + S) % 26 + 'A';// %26 因為可能shift超過範圍(Z)，需要重新回到A開始算
        }
        else if(c >= 'a' && c <= 'z')
        {
            c = (c - 'a' + S) % 26 + 'a';
        }
        //數字和特殊字元直接印出，不須加解密

        
        //printf("%c", c);//不須強制轉型，char型別會依據前面的%d, %c決定輸出的是數字還是字元
        putchar(c);
    }
    
}

void decrypt(int S, char* str, int len)
{
    for(int j = 0; j < len; j++)
    {
        char c = str[j];//這樣就可以一次取一個字元了!!
        
        if(c >= 'A' && c <= 'Z')
        {
            c = (c - 'A' - S + 26) % 26 + 'A';// +26 因為可能被除數為負，則餘數也會為負，將影響後面的運算
        }
        else if(c >= 'a' && c <= 'z')
        {
            c = (c - 'a' - S + 26) % 26 + 'a';
        }
        //數字和特殊字元直接印出，不須加解密

        
        putchar(c);
    }
    
}

int main()
{
    char str[1000];
    scanf("%d", &M);
    scanf("%lld", &S);

    //int len = sizeof(str)/sizeof(str[0]); 因為輸入不一定跟str[1000]一樣大

    S = S % 26;//在加密或解密時，應該先將 S 對 26 取餘數來避免處理超大位移。

    getchar();// 清除輸入流中的換行符號

    while(fgets(str, sizeof(str), stdin) != NULL)//相當scanf()直接把字串吃進來
    {
        // 移除換行符號
        str[strcspn(str, "\n")] = 0;

        int len = strlen(str);// 每次迴圈重新計算字串長度

        if(M == 1)
        {
            encrypt(S, str, len);
        }
        else if(M == 2)
        {
            decrypt(S, str, len);
        }
    }
    

    return 0;
}