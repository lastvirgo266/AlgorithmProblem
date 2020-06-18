import java.util.*;

class Solution {
    Map<Integer, Integer> map = new HashMap<>();
    public int solution(int n) {
        int answer = solve(n);
        
        return answer;
    }
    
    public int solve(int n){
        if(n == 1){
            return 1;
        }
        
        else if( n<= 0)
            return 0;
        
        if(map.containsKey(n))
            return map.get(n);
        
        int result = (solve(n-2) + solve(n-1))%1234567 ;
        
        map.put(n, result);
        
        return result;
        
    }
}