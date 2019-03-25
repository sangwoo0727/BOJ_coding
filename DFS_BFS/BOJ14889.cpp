#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
int board[25][25];
int check[25];
int Min=110000000;

void team_pow(int idx, int size) {
	if(idx>0) check[idx] = 1;
	int ansS = 0;
	int ansL = 0;
	if (size == N / 2) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (check[i] == 1 && check[j] == 1) ansS += board[i][j];
				if (check[i] == 0 && check[j] == 0) ansL += board[i][j];
			}
		}
		Min = min(Min, abs(ansS - ansL));
	}
	else {
		for (int i = idx; i <= N; i++) {
			team_pow(i+1, size + 1);
			check[i + 1] = 0;
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	team_pow(0, 0);
	printf("%d", Min);
	return 0;
}