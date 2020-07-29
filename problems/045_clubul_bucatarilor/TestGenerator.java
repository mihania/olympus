import java.io.*;   // Import the FileWriter class
import java.util.*;

public class TestGenerator {
    private static Random random = new Random();
    public static void main(String[] args) throws Exception {
        List<Test> tests = generateTests();
        BufferedWriter testIn = null;
        BufferedWriter testOut = null;
        try {
            testIn = new BufferedWriter(
                    new OutputStreamWriter(
                            new FileOutputStream("TESTS.IN"), "utf-8"));

            testOut = new BufferedWriter(
                    new OutputStreamWriter(
                            new FileOutputStream("TESTS.OUT"), "utf-8"));
            testIn.append(String.valueOf(tests.size()));
            testIn.newLine();
            for (int i = 0; i < tests.size(); i++) {
                Test test = tests.get(i);
                testIn.append(String.format("%d %d %d", test.N, test.K, test.A.length));
                testIn.newLine();
                for (int j = 0; j < test.A.length; j++) {
                    testIn.append(String.format("%d", test.A[j]));
                    if (j != test.A.length - 1) {
                        testIn.append(" ");
                    }
                }
                testIn.newLine();
                testIn.append(String.valueOf(test.P));
                testOut.append(String.valueOf(test.D));
                if (i != tests.size() - 1) {
                    testIn.newLine();
                    testOut.newLine();
                }
            }
        } finally {
            try {
                if (testIn != null) {
                    testIn.close();
                }
            } catch (Exception ex) {
            }

            try {
                if (testOut != null) {
                    testOut.close();
                }
            } catch (Exception ex) {
            }
        }
    }

    private static List<Test> generateTests() {
        List<Test> result = new ArrayList<>();
        int N = 20;
        for (int i = 0; i < N; i++) {
            if (i < N - 2) {
                result.add(generateTest(random.nextInt(i + 1) + 1, random.nextInt(i + 1) + 1));
            } else {
                result.add(generateTest(random.nextInt(1_000_000) + 1, random.nextInt(100_000) + 1));
            }
        }

        return result;
    }

    private static Test generateTest(int MAX_N, int MAX_R) {
        int MAX_K = MAX_N;

        Test result = new Test();
        result.N = random.nextInt(MAX_N) + 1;
        result.K = random.nextInt(result.N) + 1;
        result.D = random.nextInt(result.N) + 1;
        result.A = new int[random.nextInt(MAX_R) + 1];
        LinkedHashSet<Integer> set = new LinkedHashSet<>();
        for (int i = 1; i <= result.N; i++) {
            set.add(i);
        }

        for (int i = 0; i < result.A.length; i++) {
            result.A[i] = random.nextInt(result.K) + 1;
            int id = getIdByPos(result.A[i], set);
            set.remove(id);
            set.add(id);
        }

        int i = 1;
        Iterator<Integer> itr = set.iterator();
        while(itr.hasNext() && itr.next() != result.D) {
            i++;
        }

        result.P = i;
        return result;
    }

    private static class Test {
        int N;
        int K;
        int P; // last rating
        int D; // first rating
        int[] A; // protocol

        @Override
        public String toString() {
            return String.format("(N=%d K=%d P=%d A=%s)", N, K, P, Arrays.toString(A));
        }
    }

    private static int getIdByPos(int pos, LinkedHashSet<Integer> set) {
        Iterator<Integer> itr = set.iterator();
        int res = 0;
        for (int i = 0; i < pos; i++) {
            res = itr.next();
        }

        return res;
    }
}