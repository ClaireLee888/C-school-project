#include <stdio.h>

//T for total step; S for magic leap; W for rest day after leap; R for normal leap
unsigned long long T, S, W, R = 0;

void magicLeap(unsigned long long T, unsigned long long S, unsigned long long W, unsigned long long R)
{
    unsigned long long count = 0;
    unsigned long long cycle = (T / (S + R*W)); 
    count += cycle * (W + 1);

    unsigned long long remainingSteps = T % (S + R*W);

    if(remainingSteps != 0)
    {
        if(remainingSteps <= S)//餘數小於Magicleap
        {
            count += 1;
        }
        else
        {
            remainingSteps -= S;
            count += 1;

            count += (remainingSteps + R - 1) / R;

        }
    }

    printf("%d", count);
}


int main()
{
    scanf("%llu %llu %llu %llu", &T, &S, &W, &R);

    magicLeap(T, S, W, R);//magic leap calculation first

    return 0;
}