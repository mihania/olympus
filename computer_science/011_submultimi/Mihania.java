public class Main {
    public static void main(String[] args) {
        int N = 64;
        int K = 7;

        // dp[i][j][0] - number of desirable subsets ending at index i of size j without element 1
        // dp[i][j][1] - number of desirable subsets ending at index i of size j with element 1
        long[][][] dp = new long[N + 1][K + 1][2];

        for (int i = 1; i <= N; i++) {

            // adding self element {i}
            dp[i][1][i == 1 ? 1 : 0] = 1;

            // traversing up to i - 2 to exclude adjancent element (i - 1), adjacent to i
            for (int k = 1; k < i - 1; k++) {
                for (int j = 2; j <= K; j++) {
                    dp[i][j][0] += dp[k][j - 1][0];
                    dp[i][j][1] += dp[k][j - 1][1];
                }
            }
        }

        int res = 0;
        for (int i = 1; i <= N; i++) {
            res += dp[i][K][0];

            // preventing N and 1 to be adjacent.
            if (i != N || N == 1) {
                res += dp[i][K][1];
            }
        }

        System.out.println(res);
    }        
}
