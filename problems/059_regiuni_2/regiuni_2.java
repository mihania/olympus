import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class regiuni_2 {
    public static void main(String[] args) {
        int n = StdIn.readInt();
        UnionFind reg = new UnionFind(n);
        for (int i = 0; i < n; i++) {
            int p = StdIn.readInt();
            int q = StdIn.readInt();
            if (p == 0 || q == 0) {
                break;
            }
            //StdOut.println("p = " + p + " q = " + q);
            reg.union(p - 1, q - 1);
        }
        StdOut.println("smaller number of regiuni = " + reg.count());
    }
}