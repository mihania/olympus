#include <stdio.h>

FILE *in;
FILE *out;
int n, r, q;

int main(int argc, char *argv[]) {
	int i, s, h, a, b;
	int ans;

	in = fopen(argv[1], "r");
	fscanf(in, "%d %d %d", &n, &r, &q);
	printf("%d %d %d\n", n, r, q);
	fscanf(in, "%d", &h);
	printf("%d\n", h);
	for (i = 2; i <= n; i++) {
		fscanf(in, "%d %d", &s, &h);
		printf("%d %d\n", s, h);
	}

	out = fopen(argv[2], "w");

	for (i = 0; i < q; i++) {
		fscanf(in, "%d %d", &a, &b);
		printf("%d %d\n", a, b);
		fflush(stdout);
		if (scanf(" %d", &ans) != 1) return 0;
		fprintf(out, "%d\n", ans);
	}

	return 0;
}
