#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	int **a = (int **) malloc(n * sizeof(int *));
	for(int i = 0; i < n; i++) {
		a[i] = (int *) malloc(n * sizeof(int));
		for(int j = 0; j < n; j++) {
			a[i][j] = (i + 1) * (j + 1);
		}
	}
	int l1, r1, l2, r2;
	scanf("%d", &l1);
	while(l1 != 0) {
		scanf("%d%d%d", &r1, &l2, &r2);
		int sz = 1;
		int now = a[l2 - 1][r2 - 1];
		while(now > 0) {
			sz++;
			now /= 10;
		}	
		for(int i = l1; i <= r1; i++) {
			for(int j = l2; j <= r2; j++) {
				printf("%*d", sz, a[i - 1][j - 1]);
			}
			printf("\n");
		}
		scanf("%d", &l1);
	}              
	for(int i = 0; i < n; i++) {
		free(a[i]);
	}
	free(a);	
	return 0;
}	