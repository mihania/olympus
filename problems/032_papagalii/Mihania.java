import java.io.*;
import java.util.*;
import java.math.*;
import java.util.stream.*;

public class Mihania {
    public static void main(String[] args) throws Exception {
        List<Test> tests = readInput();
	BufferedWriter out = null;
        try {
		out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("tests.out"), "utf-8"));
		for (Test test : tests) {
            		BigInteger result = solve(test.S, test.N);
			out.append(result.toString());
			out.newLine();
        	}
	} finally {
		if (out != null) {
			out.close();
		}
	}
    }

    private static BigInteger solve(int S, int N) {
        BigInteger[][] dp = new BigInteger[N + 1][N * S + 1];
        return solve(0, 0, N, S, dp);
    }

    private static BigInteger solve(int id, int start, int N, int S, BigInteger[][] dp) {
        if (dp[id][start] == null) {
	    BigInteger res;
            if (id == N) {
                res = BigInteger.ONE;
            } else {
                res = BigInteger.ZERO;
                for (int i = start; i < (id + 1) * S; i++) {
                    res = res.add(solve(id + 1, i + 1, N, S, dp));
                }
            }

            dp[id][start] = res;
        }

        return dp[id][start];
    }

    private static List<Test> readInput() throws Exception {
        File file = new File("tests.in");
	Scanner scanner = null;
	List<Test> res = new ArrayList<>();
        try {	
            scanner = new Scanner(file);
	    int T = scanner.nextInt();
	    for (int i = 0; i < T; i++) {
	    	Test test = new Test();
            	test.S = scanner.nextInt();
            	scanner.skip(" ");
            	test.N = scanner.nextInt();
		if (scanner.hasNextLine()) {
			scanner.nextLine();
		}
		
		res.add(test);
	    }
        } finally {
            if (scanner != null) {
                scanner.close();
            }
        }

        return res;
    }

    private static class Test {
        String testId;
        int S;
        int N;
        BigInteger expectedResult;

        @Override
        public String toString() {
            return String.format("%s (S=%d N=%d)", testId, S, N);
        }
    }
}
