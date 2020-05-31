package ex;

import java.util.*;

public class Problem15685 {
	static int[][] direction = {{1,0}, {0,-1}, {-1,0}, {0,1} };
	
	
	public static void main (String[] args) {
		
		int answer = 0;
		
		int N;
		
		int x,y,d,g;
		
		int[][] map = new int[101][101];
		
		
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		
		for(int i=0; i<N; i++) {
			x = sc.nextInt();
			y = sc.nextInt();
			d = sc.nextInt();
			g = sc.nextInt();
			
			dragonCurve(x, y, d, g, map);
			
			
		
		}
		
		for(int i=0; i<100; i++) {
			for(int j=0; j<100; j++) {
				if(map[i][j]== 1 && map[i+1][j] == 1 && 
						map[i][j+1] == 1&& map[i+1][j+1] == 1) {
					answer++;
				}
			}
		}
		
		
		System.out.println(answer);
		
		
		
	}
	
	
	public static void dragonCurve(int x, int y, int d, int g, int[][] map) {
		
		
		map[x][y] = 1;		
		map[x+direction[d][0]][y+direction[d][1]] = 1;
		
		int nowX = x+direction[d][0];
		int nowY = y + direction[d][1];
		
		List<Integer> list = new ArrayList<>();
		
		list.add(d);
		
		
		
		for(int i=0; i<g; i++) {
			
			int len = list.size()-1;
			
			for(int j=len; j>=0; j--) {
				int nowDirection = (list.get(j)+1)%4;
				
				nowX += direction[nowDirection][0];
				nowY += direction[nowDirection][1];
				
				map[nowX][nowY] = 1;
				
				list.add(nowDirection);
				
			}
			
			
		}
		
		
	}

}
