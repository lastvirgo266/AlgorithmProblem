import java.util.*;

class Solution {
    
    class Graph{
        int nowVertex;
        List<Integer> nextVertex = new ArrayList<>();
        int count = 0;
        
        public void add(int n){
            this.nextVertex.add(n);
        }
        
        public List<Integer> getNextList(){
            return this.nextVertex;
        }
        
    }
    
    int[] visited;
    int[] max = new int[2];
    
    public int solution(int n, int[][] edge) {
        int answer = 0;
        
        
        max[0] = -1;
        max[1] = -1;
        visited = new int[n+1];
        
        Graph[] graph = new Graph[n+1];
        
        for(int i=1; i<=n; i++){
            graph[i] = new Graph();
            visited[i] = 0;
        }
        
        for(int i=0; i<edge.length; i++){
            int firstVertex = edge[i][0];
            int secondVertex = edge[i][1];
            
            graph[firstVertex].add(secondVertex);
            graph[firstVertex].nowVertex = i;
            graph[secondVertex].add(firstVertex);
            
        }
        
        BFS(graph, n);

        
        return answer=max[1];
    }
    
    public void BFS(Graph[] graph, int n){
        
        Queue<Graph> queue = new LinkedList<>();
        
        graph[1].count += 1;
        queue.offer(graph[1]);
        visited[1] = 1;
        
        while(!queue.isEmpty()){
            
            Graph now = queue.poll();
            int nowCount = now.count;
            List<Integer> next = now.nextVertex;
            
            if(max[0] < nowCount){
                max[0] = nowCount;
                max[1] = 1;
            }
            
            else if(max[0] == nowCount){
                max[1]++;
            }
            
            
            for(Integer vertex : next){
                
                
                if(visited[vertex] == 1)
                    continue;
                
                visited[vertex] = 1;
                graph[vertex].count = nowCount+1;
                queue.offer(graph[vertex]);
            }
            
            
        }
        
        
    }
}