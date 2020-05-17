import java.util.*;


class Solution {
    public int solution(int[] food_times, long k) {
        int answer = -1;
        
        long div = k / (long)food_times.length;
        long reminder = k % (long)food_times.length;
        
        long prev = 0;
        
        for(int i=0; i<food_times.length; i++){
            long val = div+prev;
            
            if(reminder > 0){
                val++;
                reminder--;
            }
            
            if((long)food_times[i] < val){
                food_times[i] = 0;
                prev = val - (long)food_times[i];
            }
            
            else{
                prev = 0;
            }
        }
        
        
        for(int i=0; i<food_times.length; i++){
            long val = prev;
            
            if((long)food_times[i] < val){
                food_times[i] = 0;
                prev = val - (long)food_times[i];
            }
            
            else{
                prev = 0;
                break;
            }
        }
        
        
        for(int i=0; i<food_times.length; i++){
            if(food_times[i] != 0){
                answer = i+1;
                break;
            }
        }
        
        return answer;
    }
}