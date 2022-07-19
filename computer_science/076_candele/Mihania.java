
public class Mihania {

	// 0 1 2 : 3
	// 0 2 1 : 2
	// 1 0 2 : 2
	// 1 2 0 : 2
	// 2 0 1 : 1
	// 2 1 0 : 1
	//
	// 0 1
	// 1 0
	//
	// 
	// 0 2 1
	// 1 2 0
	// 1 0 2
	// 
	//
	// 0 3 2 1 
	// 1 3 2 0
	// 1 0 3 2
	//
	// 0 2 3 1
	// 1 2 3 0
	// 1 0 2 3
	//
	//


    public static void main(String[] args) {
    	int n = 3;
	int k = 2;
	Integer[][][] dp = new Integer[n + 1][k + 1][n + 1];
	
	int res = 0;
	for (int j = 0; j < n; j++) {
		res += count(n, k, j, dp);
	}

	System.out.printf("n=%d k=%d res=%d\n", n, k, res);
    }

    // dp[n][k][j], j - is the index of the biggest candle
    private static int count(int n, int k, int j, Integer[][][] dp) {
	if (dp[n][k][j] == null) {
		int res;
    		if (n < k) {
			res = 0;
		} else if (n == 1) {
			res = 1;
		} else {
			// dp[n][k] = dp[n - 1][k] by inserting n at position j.	
			// 	      +
			//            dp[n - 1][k - 1] by inserting n at any position after j.

			res = j <= k ? 1 : 0;
			for (int j1 = j + 1; j1 < n; j1++) {
				res += count(n - 1, k - 1, j1, dp);
			}
		}

		dp[n][k][j] = res;
	}

	System.out.printf("res[%d][%d][%d]=%d\n", n, k, j, dp[n][k][j]);
	return dp[n][k][j];
    }
}

