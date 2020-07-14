import java.util.*;

class Solution {
    public int solution(int[][] routes) {
        int answer = 0;
        
        TreeMap<Integer, Integer> map = new TreeMap<>();
        
        for(int i=0; i<routes.length; i++){
            map.put(routes[i][0], 1);
            map.put(routes[i][1], 2);
        }
        
        
       Iterator<Integer> set = map.keySet().iterator();
        
        int prev = 0;
        int key = 0;
        int val = 0;
        
        while(set.hasNext()){

            
            key = set.next();
            val = map.get(key);
            //System.out.println(key + " " + map.get(key));
            
            if(prev == 0){
                prev = 1;
                answer++;
                continue;
            }
            
            else if(val == 1 && prev== 2){
                prev = 1;
                answer++;
            }
            
            else{
                prev = val;
            }
            
        }
        
        return answer;
    }
}