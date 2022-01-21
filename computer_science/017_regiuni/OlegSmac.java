import java.util.*;

public class olympus17 {
    private Hashtable<Integer, List<Integer>> paths;
    private int[] components;
    private int numComponents;

    private Stack<Integer> orderVertices;
    private boolean[] marked;

    public olympus17(int n) {
        this.paths = new Hashtable<>();
        this.components = new int[n + 1];
        for (int i = 1; i < n + 1; i++) {
            components[i] = -1;
        }

        orderVertices = new Stack<>();
        marked = new boolean[n + 1];
    }

    private void findOrderVertices(Hashtable<Integer, List<Integer>> p) {
        Hashtable<Integer, List<Integer>> revPaths = new Hashtable<>();
        for (int i : p.keySet()) {
            List<Integer> listI = p.get(i);
            for (int j : listI) {
                if (revPaths.containsKey(j)) {
                    revPaths.get(j).add(i);
                }
                else {
                    List<Integer> l = new ArrayList<>();
                    l.add(i);
                    revPaths.put(j, l);
                }
            }
        }
        for (int i = 1; i < marked.length; i++) {
            if (!marked[i]) {
                dfs(i, revPaths);
            }
        }
    }

    private void dfs(int v, Hashtable<Integer, List<Integer>> revPaths) {
        marked[v] = true;
        if (revPaths.get(v) != null) {
            for (int i : revPaths.get(v)) {
                if (!marked[i]) {
                    dfs(i, revPaths);
                }
            }
            orderVertices.add(v);
        }
        else {
            orderVertices.add(v);
        }
    }

    public int findStronglyConnectedComponents() {
        // записать в стек порядок рассмотрения вершин
        findOrderVertices(paths);

        numComponents = 0;
        while (!orderVertices.isEmpty()) {
            int i = orderVertices.pop();
            if (components[i] == -1) {
                dfs(i);
                numComponents++;
            }
        }
        for (int i = 1; i < components.length; i++) {
            System.out.print(components[i] + " ");
        }
        return numComponents;
    }

    private void dfs(int v) {
        components[v] = numComponents;
        if (paths.get(v) != null) {
            for (int w : paths.get(v)) {
                if (components[w] == -1) {
                    dfs(w);
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        olympus17 p = new olympus17(n);
        for (int i = 1; i < n + 1; i++) {
            List<Integer> list = new ArrayList<>();
            p.paths.put(i, list);
        }
        while (in.hasNext()) {
            int v = in.nextInt();
            if (v == 0) break;
            p.paths.get(v).add(in.nextInt());
        }
        System.out.println();
        System.out.println("num components = " + p.findStronglyConnectedComponents());
    }
}
