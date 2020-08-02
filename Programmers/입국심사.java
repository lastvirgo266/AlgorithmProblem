import java.util.*;

class Solution {
    public long solution(int n, int[] times) {
        long answer = Long.MAX_VALUE;
        
        Arrays.sort(times);
        
        long left = 1;
        long max = times[times.length-1];
        
        long right  = max*n;
        
        while(left<=right){
            
            long mid = (left+right)/2;
            long val =0;
            
            for(int i=0; i<times.length; i++)
                val += mid/times[i];
            
            if(n <= val){
                answer = answer > mid ? mid : answer;
                right = mid -1;
            }
            
            else if(n > val)
                left = mid+1;
            
            
        }
        
        
        
        return answer;
    }
}