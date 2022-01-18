// "static void main" must be defined in a public class.
public class Main {
    public static void main(String[] args) {
        int s = 50;
        int[] a = {8, 5, 2, 36, 70, 17};
        Arrays.sort(a);
        int[] dp = new int[a.length]; // dp[i] - max occupied area on interval [i, N - 1], starting from a[i]
        int[] idx = new int[a.length]; // idx[i] - the index of next captured state.
        int[] pred = new int[a.length]; // pred[i] - max allowed soldiers to be captured before i-th state.
        int maxIdx = -1;
        
        for (int i = a.length - 1; i >= 0; i--) {
            if (a[i] <= s) {
                dp[i] = a[i];                
                idx[i] = i;
                pred[i] = a[i];
                for (int j = i + 1; j < a.length; j++) {
                    if (a[i] <= s - dp[j]        // enough sodiers?
                        && a[i] < pred[j]        // sum of current territories smaller than the next captured terrritory?
                        && dp[i] < dp[j] + a[i]  // do we get bigger territory then before?
                       ) {
                        dp[i] = dp[j] + a[i];
                        idx[i] = j;
                        pred[i] = pred[j] - a[i];
                    }
                }
            }
            
            if (maxIdx == -1 || dp[i] > dp[maxIdx]) {
                maxIdx = i;
            }
        }
        
        if (maxIdx == -1) {
            System.out.println(s);
        } else {
            System.out.println(s - dp[maxIdx]);    
            while (maxIdx != idx[maxIdx]) {                
                System.out.println(a[maxIdx]);                
                maxIdx = idx[maxIdx];
            } 
            
            System.out.println(a[maxIdx]);
        }        
    }
}
