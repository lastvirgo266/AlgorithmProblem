class Solution {
    
    static int[] visited;
    
    public int solution(int n) {
        int answer = 0;
        visited = new int[n];
        
        for(int i=0; i<n; i++){
            visited[i] = 0;
        }
        
        answer = DFS(0, n);
        
        return answer;
    }
    
    int DFS(int now, int max){
        
        if(now >= max){
            if(now==max)
                return 1;
            else
                return 0;
        }
        
        if(visited[now] != 0)
            return visited[now] % 1000000007;
        
        int result = 0;
             
        if(now+1 <= max)
            result += DFS(now+1, max) % 1000000007;
        if(now+2 <= max)
            result += DFS(now+2, max) % 1000000007;
        
        if(now > 0)
            visited[now] = result % 1000000007;
            
        
        return result % 1000000007 ;
        
    }
    
}