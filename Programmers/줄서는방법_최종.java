import java.util.*;


class Solution {
    
    List<Integer> visited;
    
    public int[] solution(int n, long k) {
        int[] answer = {};
        visited = new ArrayList<>();
        
        for(int i=1; i<=n; i++){
            visited.add(i);
        }
        
        answer = getSolve(n,k);
        
        
        return answer;
    }
    
    public int[] getSolve(int n, long k){
        
       int[] list = new int[n];
        int index = 0;
        
        while(n >= 1){
            
            long start = factorial(n-1);
            int count = 0;
            
            while(k > start && n >= count){
                k -= start;
                count++;
            }
            n--;
            
            
            if(count == 0){
                list[index++] = getMinNumber();
                continue;
            }
            
            
            list[index++] = getNextNumber(count+1);
            
        }
        
        return list;
    }
    
    
    public int getNextNumber(int n){
        int temp = visited.get(n-1);
        visited.remove(n-1);
        return temp;
    }
    
    public int getMinNumber(){
        int temp = visited.get(0);
        visited.remove(0);
        return temp;
    }
    
    public long factorial(int n){
        long start = 1;
        for(int i=n; i>=1; i--){
            start *= i;
        }
        return start;
    }
    
}