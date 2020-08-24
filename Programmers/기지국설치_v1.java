import java.util.*;

class Solution {
    public int solution(int n, int[] stations, int w) {
        int answer = 0;
        int[] visited = new int[n+1];
        Queue<Integer> q = new LinkedList<>();
        
                
        for(int i=0; i<=n; i++){
            visited[i] = 0;
        }
        
        
        for(int station : stations){
            q.offer(station);
            
            visited[station] = 1;
            
            for(int i=1; i<=w; i++){
                
                if(station +i <= n)
                    visited[station+i] = 1;
                if(station-i > 0)
                    visited[station-i] = 1;
                
            }
            
        }

        
        while(!q.isEmpty()){
            int now = q.poll();
            int leftCheck = now - w - 1;
            
            if(leftCheck > 0 && visited[leftCheck] == 0){
            
                int leftMax = leftCheck-w;
                int i = -1;
            
                if(leftMax <= 0){
                    leftMax = 1;
                }
                
                for(i= leftCheck; i>= leftMax && visited[i] == 0; i--){
                    visited[i] = 1;
                }
                
                leftMax = i+1;
                q.offer(leftMax);
                answer++;
            }
            
            
            int rightCheck = now + w + 1;
            
            if(rightCheck <= n  && visited[rightCheck] == 0){
            
                int rightMax = rightCheck + w;
                int i = -1;
            
                if(rightMax > n){
                    rightMax = n;
                }
                
                for(i= rightCheck; i<= rightMax && visited[i] == 0; i++){
                    visited[i] = 1;
                }
                
                rightMax = i-1;
                q.offer(rightMax);
                answer++;
            }
            
            
        }
        

        return answer;
    }
}