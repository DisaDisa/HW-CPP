#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	int a[n][n];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			a[i][j] = (i + 1) * (j + 1);
		}
	}
	int l1, r1, l2, r2;
	scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
	if(l1 == 0) return 0;
	for(int i = l1; i <= r1; i++) {
		for(int j = l2; j <= r2; j++) {
			printf("%d ", a[i - 1][j - 1]);
		}
		printf("\n");
	}
	return 0;
}	