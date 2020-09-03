import java.util.*;

class Solution {
    
    class Position{
        int y;
        int x;
        String val = "";
        
        Position(int y, int x, String val){
            this.y = y;
            this.x = x;
            this.val = new String(val);
        }
    }
    
    
    public String solution(int m, int n, String[] board) {
        String answer = "";
        
        HashMap<Position, Integer> map = new HashMap<>();
        Queue<Integer> q = new LinkedList<>();
        String[] pairList = new String[(m*n)/2];
        
        for(int i=0; i<m; i++){
            String word = board[i];
            for(int j=0; j<n; j++){
                String node = Character.toString(word.charAt(j));
                
                if(node == "." || node == "*"){
                    continue;
                }
                
                if(!map.containsKey(node)){
                    map.put(new Position(i,j,node), 0);
                }
            }
        }
        
        
        return answer;
    }
}