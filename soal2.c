// Muhammad Atpur Rafif
// 13522086

#include <stdio.h>

int traverse(int r, int c, char* N, char *T, int R, int C){
	if(r < 0 || r >= R || c < 0 || c >= C) return 0;
	if(T[r * C + c]) return 0;
	if(!N[r * C + c]) return 0;

	T[r * C + c] = 1;
	return 1 +
		traverse(r - 1, c, N, T, R, C) +
		traverse(r, c - 1, N, T, R, C) +
		traverse(r + 1, c, N, T, R, C) +
		traverse(r, c + 1, N, T, R, C);
}

int main(){
	int R, C;
	scanf("%d %d", &R, &C);

	char N[R][C];
	char T[R][C];
	for(int i = 0; i < R; ++i){
		char tmp[C];
		scanf("%s", tmp);

		for(int j = 0; j < C; ++j){
			N[i][j] = tmp[j] == '0' ? 0 : 1;
			T[i][j] = 0;
		}
	}

	int count = 0;
	int max = 0;
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			int t = traverse(i, j, (char*) N, (char*) T, R, C);
			if(t > max) max = t;
			if(t > 0) count += 1;
		}
	}

	printf("ISLANDS %d\n", count);
	printf("LARGEST %d", max);
}
