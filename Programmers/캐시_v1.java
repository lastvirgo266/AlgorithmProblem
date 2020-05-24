import java.util.*;

class Solution {
    public int solution(int cacheSize, String[] cities) {
        
        int answer = 0;
        
        Deque<String> deque = new ArrayDeque();
        
        if(cacheSize == 0)
            return cities.length*5;
        
        for(int i=0; i<cities.length; i++){
            String result = cities[i].toUpperCase();
            
            if(deque.contains(result)){
                answer += 1;
                deque.remove(result);
                deque.addLast(result);
            }
            
            else{
                if(deque.size() >= cacheSize){
                    deque.pollFirst();
                    deque.addLast(result);
                }
                
                else{
                    deque.addLast(result);
                }
                
                answer +=5;
                
            }
            
        }
        
        return answer;
    }
}