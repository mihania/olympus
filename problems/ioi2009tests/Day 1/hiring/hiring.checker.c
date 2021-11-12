// The arguments should be (in this order):
//
// 1) Input file
// 2) Output file (of contestant)
// 3) Solution file (one optimal output file)
// 4) Maximum number of points for this test case
//
// For example:
//
// ./hiring.checker hiring.006.in contestant.out hiring.006.sol 4
//
// The score will be printed on the first line of the checker's output.


#include <stdio.h>

#define MAXN 500001

int n;
long long w;
int s[MAXN];
int q[MAXN];
int seen[MAXN];

FILE *in;
FILE *out;
FILE *sol;

int sol_cnt = -2;
int out_cnt = -1;
long long sol_num, out_num;
int sol_denom, out_denom;

int max_score;
int score = 0;

void quit(void) {
	if (sol_cnt == out_cnt) score = max_score / 2;
	printf("%d\nInvalid or incomplete OUT file!\n", score);
	exit(0);
}

void load(FILE *fh, int *cnt, long long *num, int *denom) {
	int i;
	int tops = 0;
	int topq = 1;

	for (i=1; i<=n; i++) seen[i] = 0;
	*num = 0;
	*denom = 0;


	if (fscanf(fh, "%d", cnt) != 1) quit();
	if (*cnt < 0 || *cnt > n) quit();
	for (i=0; i<*cnt; i++) {
		int j;
		if (fscanf(fh, "%d", &j) != 1) quit();
		if (j < 1 || j > n || seen[j]++) quit();
		if (s[j] * topq > tops * q[j]) {
			tops = s[j];
			topq = q[j];
		}
		*num += q[j];
	}
	*num *= tops;
	*denom = topq;
}

int main(int argc, char *argv[]) {
	int i;

	max_score = atoi(argv[4]);
	in = fopen(argv[1], "r");
	out = fopen(argv[2], "r");
	if (!out) quit();
	sol = fopen(argv[3], "r");
	fscanf(in, "%d %lld", &n, &w);
	for (i=1; i<=n; i++) {
		fscanf(in, "%d %d", &s[i], &q[i]);
	}
	load(sol, &sol_cnt, &sol_num, &sol_denom);
	load(out, &out_cnt, &out_num, &out_denom);

	if (sol_cnt == out_cnt) {
		if (sol_num * out_denom == out_num * sol_denom) {
			printf("%d\n", max_score);
		} else {
			printf("%d\nOnly partially correct answer.\n", max_score / 2);
		}
	} else if ((out_cnt > sol_cnt && out_num <= w * out_denom) ||
	           (out_cnt == sol_cnt && out_num * sol_denom < sol_num * out_denom))
	{
		printf("100\n"); // Should never happen!
	} else {
		printf("0\nWrong answer.\n");
	}

	return 0;
}
