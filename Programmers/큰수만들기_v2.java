import java.util.*;

class Solution {
    public String solution(String number, int k) {
        String answer = "";
        int len = number.length();
        int[] arr = new int[len];
        List<Integer> list = new ArrayList<>();
        
        for(int i=0; i<number.length(); i++){
            char temp = number.charAt(i);
            arr[i] = (temp - '0');
        }
        
        int prev = arr[0];
        int prevIndex = 0;
        
        for(int i=1; i<len; i++){
            int nowVal = arr[i];
            
            if(prev <nowVal){
                for(int j=i-1; j>=0; j--){
                    if(!list.contains(j) && arr[j] < nowVal){
                        list.add(j);
                        k--;
                        if(k == 0)
                            break;
                    }
                }
            }
            
            if(k == 0)
                break;
            
            prev = nowVal;
            prevIndex = i;
        }
        
        //Parsing
        for(int i : list){
            arr[i] = -1;
        }
        
        for(int i=0; i<len; i++){
            if(arr[i] != -1)
                answer += Integer.toString(arr[i]);
        }
        
        System.out.println(answer);
        
        return answer;
    }
}