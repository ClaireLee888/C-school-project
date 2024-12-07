#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

// 埃拉托色尼篩法計算小質數
void simpleSieve(unsigned long long limit, bool *is_prime_small) {
    for (unsigned long long i = 0; i <= limit; i++) 
        is_prime_small[i] = true;

    is_prime_small[0] = is_prime_small[1] = false; // 0 和 1 不是質數

    for (unsigned long long i = 2; i * i <= limit; i++) {
        if (is_prime_small[i]) {
            for (unsigned long long j = i * i; j <= limit; j += i) {
                is_prime_small[j] = false;
            }
        }
    }
}

// 分段篩法找出 [X, Y] 範圍內的質數和
unsigned long long segmentedSieve(unsigned long long X, unsigned long long Y) {
    unsigned long long limit = (unsigned long long)sqrt(Y); // 找到 sqrt(Y)
    bool *is_prime_small = malloc((limit + 1) * sizeof(bool));
    simpleSieve(limit, is_prime_small); // 找到小質數

    unsigned long long range = Y - X + 1;
    bool *is_prime = malloc(range * sizeof(bool));
    for (unsigned long long i = 0; i < range; i++) 
        is_prime[i] = true;

    // 對每個小質數篩除 [X, Y] 的非質數
    for (unsigned long long i = 2; i <= limit; i++) {
        if (is_prime_small[i]) {
            unsigned long long start = (X / i) * i; // 計算起始倍數
            if (start < X) start += i;             // 確保在區間內
            if (start == i) start += i;            // 避免小質數本身被標記

            for (unsigned long long j = start; j <= Y; j += i) {
                is_prime[j - X] = false; // 標記非質數
            }
        }
    }

    // 計算質數的和
    unsigned long long sum = 0;
    for (unsigned long long i = 0; i < range; i++) {
        if (is_prime[i] && (X + i) != 1) { // 排除數字 1
            sum += (X + i);
        }
    }

    free(is_prime_small);
    free(is_prime);
    return sum;
}

int main() {
    unsigned long long X, Y;
    scanf("%llu %llu", &X, &Y);

    unsigned long long sum = segmentedSieve(X, Y);
    printf("%llu\n", sum);

    return 0;
}
