package ex;

import java.util.*;

public class Problem16235 {
	
	static int[][] direction = { {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1},
			{1,0}, {1,1} };
	
	
	static class Soil{
		int fer = 0;
		PriorityQueue<Integer> tree = new PriorityQueue<Integer>();
		PriorityQueue<Integer> destroy = new PriorityQueue<Integer>();
		
		public Soil(int fer) {
			this.fer = fer;
		}
		
		public void addTree(int tree) {
			this.tree.offer(tree);
		}
		
		public void eatFer() {
			PriorityQueue<Integer> newTree = new PriorityQueue<Integer>();
			
			while(!tree.isEmpty()) {
				int top = tree.poll();
				
				if(fer- top >= 0) {
					fer -= top;
					newTree.offer(top+1);
				}
				
				else {
					destroy.offer(top);
				}
			}
			
			tree = newTree;
		}
		
		public void changeFer() {
			
			while(!destroy.isEmpty()) {
				int top = destroy.poll();
				fer += (top/2);
			}
			
		}
		
		public int canExtend() {
			int extendTree = 0;
			PriorityQueue<Integer> newTree = new PriorityQueue<Integer>();
			
			while(!tree.isEmpty()) {
				int top = tree.poll();
				
				//System.out.println(top);
				
				if(top % 5 == 0) {
					extendTree++;
				}
				
				newTree.offer(top);
				
			}
			
			//System.out.println("END");
			
			tree = newTree;
			
			return extendTree;
			
			
		}
		
		
		
	}
	
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N,M,K;
		
		
		N = sc.nextInt();
		M = sc.nextInt();
		K = sc.nextInt();
		
		Soil[][] map = new Soil[N+1][N+1];
		int [][] ferMap = new int[N+1][N+1];
		
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				map[i][j] = new Soil(5);
			}
		}
		
		for(int i=1; i<=N; i++) {
			for(int j=1; j<N+1; j++) {
				int val = sc.nextInt();
				map[i][j].fer += val;
				ferMap[i][j] = val;
			}
		}
		
		
		for(int i=0; i<M; i++) {
			int r,c,z;
			r = sc.nextInt();
			c = sc.nextInt();
			z = sc.nextInt();
			map[r][c].addTree(z);
		}
		
		int answer = 0;
		
		for(int i=0; i<K; i++) {
			spring(map, N);
			summer(map, N);
			fall(map, N);
			winter(map, ferMap, N);
		}
		
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				answer += map[i][j].tree.size();
			}
		}
		
		System.out.println(answer);
		
		
		
	}
	
	
	
	
	static void spring(Soil[][] map, int N) {
		
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				map[i][j].eatFer();
			}
		}
		
	}
	
	
	
	static void summer(Soil[][] map, int N) {
		
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				map[i][j].changeFer();
			}
		}
		
	}
	
	
	
	static void fall(Soil[][] map, int N) {
		
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				int extendTree = map[i][j].canExtend();
				
				for(int k=0; k<8; k++) {
					int newX = i+direction[k][0];
					int newY = j+direction[k][1];
					
					if(newX > 0 && newX <= N && 
					newY >0 && newY <= N) {
						for(int z=0; z<extendTree; z++)
							map[newX][newY].addTree(1);
					}
				}
				
				
			}
		}
		
	}
	
	
	
	static void winter(Soil[][] map, int[][] ferMap, int N) {
		
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				map[i][j].fer += ferMap[i][j];
			}
		}
	}
	

}
