import java.util.*;

class Solution {
    public String solution(String number, int k) {
        String answer = "";
        int len = number.length();
        int[] store = new int[len];
        int[][] arr = new int[len][len];
        
        for(int i=0; i<number.length(); i++){
            char temp = number.charAt(i);
            arr[i][0] = (temp - '0');
            arr[i][1] = i;
            store[i] = arr[i][0];
        }
        
        Arrays.sort(arr,(o1, o2)->
                    {if(o1[0] != o2[0]) 
                        return o1[0] - o2[0]; 
                    else 
                        return o1[1] - o2[1];});
        
        for(int i=0; i<k; i++){
            store[arr[i][1]] = -1;
        }
        
        for(int i=0; i<len; i++){
            if(store[i] != -1)
                answer += Integer.toString(store[i]);
        }
        
        
        return answer;
    }
}