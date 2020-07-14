import java.util.*;

class Solution {
    public int solution(int[][] routes) {
        int answer = 1;
        
        TreeMap<Integer, Integer> map = new TreeMap<>();
        
        for(int i=0; i<routes.length; i++){
            map.put(routes[i][0], routes[i][1]);
        }
        
        
       Iterator<Integer> set = map.keySet().iterator();
        
        int j = 0;
        
        while(set.hasNext()){
            
            
            int key = set.next();
            int val = map.get(key);
            
            routes[j][0] = key;
            routes[j][1] = val;
            
            j++;
            
        }
        
        
        int tmp = routes[0][1]; 
        
        for (int i = 0; i < routes.length-1; i++) { 
            if (tmp > routes[i][1]) tmp = routes[i][1]; 
            if (tmp < routes[i + 1][0]) { 
                answer += 1; tmp = routes[i + 1][1]; 
            } 
        }
        
        
        return answer;
    }
}