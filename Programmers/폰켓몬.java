import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        
        Map<Integer, Integer> map = new HashMap<>();
        
        for(int i=0; i<nums.length; i++){
            map.put(nums[i],1);
        }
        
        int len = map.size();
        int max = nums.length/2;
        
        if(len > max)
            return max;
        else
            return len;
        

    }
}