public class Main {
    public static void main(String[] args) {        
        int S = 50;
        int[] v = {8, 5, 2, 36, 70, 17};
        
        // sorting array to ensure countries 
        Arrays.sort(v);
        int[][] T = new int[v.length][S + 1];
        for (int i = 0; i < v.length; i++) {
            for (int j = 0; j <= S; j++) {
                if (j < v[i]) {
                    
                    // we cannot conquer country i
                    if (i != 0) {
                        T[i][j] = T[i - 1][j];    
                    }
                    
                } else {
                    
                    if (i != 0) {
                        T[i][j] = T[i - 1][j];    
                    }                    
                    
                    int prevSpace = (i == 0 ? 0 : T[i - 1][j < v[i] ? 0 : j - v[i]]);
                    
                    // checking that prev territory is greater than current country.
                    if (v[i] > prevSpace && T[i][j] < v[i] + prevSpace) {
                        T[i][j] = v[i] + prevSpace;
                    }
                }
            }
        }        
        
        System.out.println(T[T.length - 1][T[0].length - 1]);
        
        // traversing back to find the path
        int curS = T[T.length - 1][T[0].length - 1];
        int i = T.length - 1;
        int j = T[0].length - 1;
        List<Integer> countries = new ArrayList<>();
        while (curS > 0) {
            if (i > 0 && T[i][j] == T[i - 1][j]) {
            } else {
                countries.add(0, v[i]);
                j -= v[i];
                curS -= v[i];
            }
            
            i--;
        }
        
        System.out.println(countries);
    }        
}
