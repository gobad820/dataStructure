#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i, n;                      // i = 소수 확인 반복 // n = 숫자
    int prime[500];                // 저장할 배열
    int ptr = 0;                   // 소수의 갯수
    unsigned long counter = 0;     // 나눗셈의 횟수
    prime[ptr++] = 2;              // 2는 소수이기 때문에 prime[0]에 2대입 후 ptr값 증가
    for (n = 3; n <= 1000; n += 2) // 3 ~ 1000까지의 수 중 소수 탐색
    {
        for (i = 1; i < ptr; i++) // 소수로 판명된 수들로만 나누어 보면 되기 때문 // 소수의 수만큼만 반복 // i가 1부터 시작하는 이유는 홀수만 하기 때문에 2로 나누어 볼 필요는 전혀 없다.
        {
            counter++;             // 나눗셈
            if (n % prime[i] == 0) // 나누어 떨어지면
                break;             // 뒤에 소수가 더 있을 경우 뒤의 계산을 할 필요가 없어진다.
        }
        if (ptr == i)         // n보다 작은 모든 소수로 나누어도 안 나누어 진 경우는 소수로 판정
            prime[ptr++] = n; // prime배열에 소수 저장
    }
    for (i = 0; i < ptr; i++)
        printf("%d ", prime[i]);
    printf("\n");
    printf("나누셈을 실행한 횟수 : %lu", counter);
    return 0;
}
