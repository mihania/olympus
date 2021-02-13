// "static void main" must be defined in a public class.
public class Main {
    public static void main(String[] args) {
        int N = 64;
        int K = 7;
        
        // inspiration from https://www.geeksforgeeks.org/count-of-subsets-of-integers-from-1-to-n-having-no-adjacent-elements/
        
        // dp[i][j][0] - number of desirable subsets ending at index i of size j without element 1
        // dp[i][j][1] - number of desirable subsets ending at index i of size j with element 1
        long[][][] dp = new long[N + 1][K + 1][2];  
                
        for (int i = 1; i < dp.length; i++) {
            // adding self element {i}
            dp[i][1][i == 1 ? 1 : 0] = 1;     
            
            // traversing up to i - 2 to exclude adjancent element (i - 1), adjacent to i
            for (int k = 1; k < i - 1; k++) {                
                for (int j = 2; j < dp[0].length; j++) {
                    dp[i][j][0] += dp[k][j - 1][0];
                    dp[i][j][1] += dp[k][j - 1][1];
                }
            }            
        }
        
        int res = 0;
        for (int i = 1; i < dp.length; i++) {
            res += dp[i][K][0];
            
            // prenting N and 1 to be adjacent.
            if (i != dp.length - 1) {
                res += dp[i][K][1];
            }
        }
        
        System.out.println(res);
    }        
}
