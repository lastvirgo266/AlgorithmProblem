import java.util.*;

class Solution {
    public int solution(int n, int[][] costs) {
        int[] visited = new int[n];
        int[] union = new int[n];
        int answer = 0;
        
        Arrays.sort(costs, (o1, o2) -> o1[2] - o2[2]);
        
        for(int i=0; i<n; i++){
            visited[i] = 0;
            union[i] = -1;
        }
        
        for(int i=0; i<costs.length; i++){
            int startNode = costs[i][0];
            int endNode = costs[i][1];
            int cost = costs[i][2];
            
            if(endNode < startNode){
                int temp = endNode;
                endNode = startNode;
                startNode = temp;
            }
            
            
            if(visited[startNode] == 0 || visited[endNode] == 0){
                visited[startNode] = 1;
                visited[endNode] = 1;
                
                if(union[startNode] == -1 && union[endNode] == -1){
                    union[startNode] = startNode;
                    union[endNode] = startNode;
                }
                
                else{
                    if(union[startNode] == -1)
                        union[startNode] = union[endNode];
                    else
                        union[endNode] = union[startNode];
                }
                
                answer += cost;
            }
            
            else if(union[startNode] != union[endNode]){
                int fromUnion;
                int targetUnion;
                
                if(union[startNode] < union[endNode]){
                    targetUnion = union[endNode];
                    fromUnion = union[startNode];
                }
                
                else{
                    targetUnion = union[startNode];
                    fromUnion =  union[endNode];
                }
                
                setUnion(union, targetUnion, fromUnion);
                answer += cost;
                
            }
        }
        
        
        
        return answer;
    }
    
    void setUnion(int[] union, int target, int from){
        for(int  i=0; i<union.length; i++){
            if(union[i] == target )
                union[i] = from;
        }
    }
    
    
}