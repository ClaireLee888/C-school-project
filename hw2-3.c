#include <stdio.h>

unsigned long long zaraHealth, zaraAttack, firelordHealth, firelordAttack = 0;


int main()
{
    scanf("%llu %llu %llu %llu", &zaraHealth, &zaraAttack, &firelordHealth, &firelordAttack);

    if (zaraAttack == 0)
    {
        printf("Firelord wins");
    }
    else if (firelordAttack == 0)
    {
        printf("Zara wins");
    }

    unsigned long long zaraRounds = (firelordHealth + zaraAttack - 1) / zaraAttack;
    unsigned long long firelordRounds = (zaraHealth + firelordAttack - 1) / firelordAttack;

    if (zaraRounds <= firelordRounds)
    {
        printf("Zara wins");
    }
    else
    {
        printf("Firelord wins");
    }


//攻擊力為零，那麼對應的生命值永遠不會減少。
//輸入值過大：數值過大，導致需要執行許多迭代才能結束迴圈，超出時間限制。

    /*while(zaraHealth > 0 && firelordHealth > 0)
    {
        firelordHealth -= zaraAttack;

        if(firelordHealth <= 0)
        {
            break;
        }

        zaraHealth -= firelordAttack;
    }

    if(zaraHealth <= 0)
    {
        printf("Firelord wins");
    }
    else
    {
        printf("Zara wins");
    }*/

    return 0;
}