import java.util.*;

class Solution {
    public int solution(int[] weight) {
        int answer = 1;
        Arrays.sort(weight);
        
        for(int i=0; i<weight.length; i++){
            if(answer >= weight[i]){
                answer += weight[i];
            }
            
            else
                break;
            
        }
        
        
        
        return answer;
    }
}