#include <stdio.h>
#include <math.h>

unsigned long long X, Y = 0;
int sum = 0;


int main()
{
    scanf("%llu %llu", &X, &Y);

    int range = Y - X + 1;

    // 初始化布林陣列
    int is_prime[range];

    for (int i = 0; i < range; i++) 
    {
        is_prime[i] = 1; // 假設全部都是質數
    }

    

    // 篩選非質數
    for(int i = 0; i < range; i++)
    {
        
    }
    

    // 累加範圍內的質數
    int sum = 0;

    for(int i = 0; i < range; i++) 
    {
        if(is_prime[i])//如果標記為質數(true則執行sum這行)
        {
            sum += (X + i); // 加上對應的實際數字(X不變，i變大)
        }
    }


    printf("%d", sum);

    return 0;
}

//平方根法依舊碰到timelimit

    /*for(int i = X; i <= Y; i++)
    {
        int count = 0;//計算可被整除的數有幾個

        //只需檢查根號i以下的數
        int check = (unsigned long long)sqrt(i);//無條件捨去小數部分

        for(int j = 2; j <= check; j++)
        {
            if(i % j == 0)
            {
                count += 1;
            }
        }

        if(count == 0 && i != 1)
        {
            sum += i;
        }
    }*/