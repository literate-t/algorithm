/*
>> 문제(1463)
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

>> 입력
첫째 줄에 1보다 크거나 같고, 10^6보다 작거나 같은 정수 N이 주어진다.

>> 출력
첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.

>> 점화식
dp[N]는 N을 1로 만드는 최소 연산 횟수.
시작 연산을 어떤 것으로 했을 때 최솟값이 나오는가.
dp[N]: min(dp[N/3] + 1, dp[N/2] + 1, dp[N-1] + 1)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min(x, y)	((x <= y) ? (x) : (y))
void ProblemSolved()
{
	int N;
	scanf("%d", &N);
	int* dp = new int[1000000];
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= N; ++i)
	{
		if (i % 3 == 0)
			dp[i] = min(dp[i / 3] + 1, dp[i - 1] + 1);
		else if (i % 2 == 0)
			dp[i] = min(dp[i / 2] + 1, dp[i - 1] + 1);
		else
			dp[i] = dp[i - 1] + 1;
		// 이렇게 조금 더 줄일 수 있다
		//dp[i] = dp[i - 1] + 1;
		//if (i % 3 == 0)
		//	dp[i] = min(dp[i / 3] + 1, dp[i]);
		//else if (i % 2 == 0)
		//	dp[i] = min(dp[i / 2] + 1, dp[i]);
	}
	printf("%d", dp[N]);
	delete[] dp;
}
int main()
{
	ProblemSolved();
	return 0;
}