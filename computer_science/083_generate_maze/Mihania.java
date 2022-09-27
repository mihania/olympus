import java.util.*;

public class Mihania {
        private static class Maze {
                private int N;
                private int M;
                private List<Edge> edges;

                public Maze(int N, int M) {
                        this.N = N;
                        this.M = M;
                        this.edges = generateMaze();
                }
             
                // The implementation of Prim's algorithm.
                private List<Edge> generateMaze() {
                        List<Edge> all = new ArrayList<>();
                        for (int i = 0; i < N; i++) {
                                for (int j = 0; j < M; j++) {
                                        if (i != 0) {
                                                all.add(new Edge(id(i, j), id(i - 1, j)));
                                        }

                                        if (j != 0) {
                                                all.add(new Edge(id(i, j), id(i, j - 1)));
                                        }
                                }
                        }

                        Collections.shuffle(all);
                        List<Edge> res = new ArrayList<>();

                        UnionFind uf = new UnionFind(N * M);
                        for (Edge e : all) {
                                if (uf.find(e.s) != uf.find(e.t)) {
                                        uf.union(e.s, e.t);
                                } else {
                                        res.add(e);
                                }
                        }

                        return res;
                }

                public void draw() {
                        String fullH = "++";
                        String emptyH = " +";
                        // +++
                        // | |
                        // + +
                        Set<Edge> s = new HashSet<>(edges);
                        for (int i = 0; i <= N; i++) {
                                for (int j = 0; j < M; j++) {
                                        if (j == 0) {
                                                System.out.print("+");
                                        }

                                        if (i == 0 || i == N) {
                                                System.out.print(fullH);
                                        } else {
                                                System.out.print(s.contains(new Edge(id(i, j), id(i - 1, j))) ? fullH : emptyH);
                                        }

                                }
                                
                                System.out.println();

                                if (i != N) {
                                        for (int j = 0; j <= M; j++) {
                                                if (j == 0 || j == M) {
                                                        System.out.print("| ");
                                                } else {
                                                        System.out.print(s.contains(new Edge(id(i, j), id(i, j - 1))) ? "| " : "  ");
                                                }
                                        }
                                        
                                        System.out.println();
                                }

                                
                        }

                        System.out.println();	
                }

                public int id(int i, int j) {
                        return i * M + j;
                }
        }

	public static class Edge {
		public int s;
		public int t;

		public Edge(int s, int t) {

                        // applying min, max functions to make undirected edge.
			this.s = Math.min(s, t);
			this.t = Math.max(s, t);
		}

		public boolean equals(Object o) {
			Edge e = (Edge)o;
			if (e == null) {
				return false;
			}

			return this.s == e.s && this.t == e.t;
		}

		public int hashCode() {
			return s ^ t;
		}

                public String toString() {
                        return String.format("(%d, %d)", s, t);
                }
	}

	public static class UnionFind {
		private int[] id;
		private int[] sz;

		public UnionFind(int N) {
			this.id = new int[N];
			this.sz = new int[N];
			for (int i = 0; i < id.length; i++) {
				this.id[i] = i;
				this.sz[i] = 1;
			}
		}

		public void union(int i, int j) {
			int parI = find(i);
			int parJ = find(j);
                        if (parI != parJ) {
				if (sz[parI] < sz[parJ]) {
					id[parI] = id[parJ];
					sz[parJ] += sz[parI];
				} else {
					id[parJ] = id[parI];
					sz[parI] += sz[parJ];
				}
			}
		}

		public int find(int i) {
			while (i != id[i]) {
				i = id[i];
			}

			return i;
		}

                public String toString() {
                        return String.format("id=[%s]\nsz=[%s]", Arrays.toString(id), Arrays.toString(sz));
                }
	}

	public static void main(String[] args) {
		int N = Integer.parseInt(args[0]);
		int M = Integer.parseInt(args[1]);
                Maze maze = new Maze(N, M);
                maze.draw();
	}
}

