// "static void main" must be defined in a public class.
public class Main {
    public static void main(String[] args) {
        int s = 50;
        int[] a = {8, 5, 2, 36, 70, 17};
        Arrays.sort(a);
        int[] m = new int[a.length]; // m[i] - max occupied area on interval [i, N - 1], starting from a[i]
        int[] idx = new int[a.length]; // idx[i] - the index of next captured state.
        int maxIdx = -1;
        
        for (int i = a.length - 1; i >= 0; i--) {
            if (a[i] <= s) {
                m[i] = a[i];                
                idx[i] = i;
                for (int j = i + 1; j < a.length; j++) {
                    if (a[i] <= s - m[j]        // enough sodiers?
                        && a[i] < a[j]          // next territory is bigger?
                        && m[i] < m[j] + a[i]   // do we get bigger territory then before?
                       ) {
                        m[i] = m[j] + a[i];
                        idx[i] = j;
                    }
                }
            }
            
            if (maxIdx == -1 || m[i] > m[maxIdx]) {
                maxIdx = i;
            }
        }
        
        if (maxIdx == -1) {
            System.out.println(s);
        } else {
            System.out.println(s - m[maxIdx]);    
            while (maxIdx != idx[maxIdx]) {                
                System.out.println(a[maxIdx]);                
                maxIdx = idx[maxIdx];
            } 
            
            System.out.println(a[maxIdx]);
        }        
    }
}
