#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i, n;
    int prime[500];
    int ptr = 0;
    unsigned long counter = 0;
    prime[ptr++] = 2;
    prime[ptr++] = 3;
    for (n = 5; n <= 1000; n += 2) // 5 ~ 1000 // 짝수는 계산이 필요 없음
    {
        int flag = 0;                                             // 소수 판별 플래그
        for (int i = 1; counter++, prime[i] * prime[i] <= n; i++) // 곱셈의 수 증가 // 대칭성 이용 제수와 몫은 서로 상관관계 이용?
        {                                                         // 조건문 부분인 counter++ 먼저 평가 후 prime[i]*prime[i] <= n 부분을 평가
            counter++;                                            // 나눗셈의 수 증가
            if (n % prime[i] == 0)                                // 나누어진다면
            {
                flag = 1; /// 소수 아님
                break;    // 뒤에 반복은 불필요 하기 때문에 탈출
            }
        }
        if (!flag)            // 나누어 지는 수가 없으면
            prime[ptr++] = n; // 소수로 입력
    }
    for (i = 0; i < ptr; i++)
        printf("%d\n", prime[i]);
    printf("곱셈과 나눗셈을 실행한 횟수 :%lu\n", counter);
    return 0;
}
