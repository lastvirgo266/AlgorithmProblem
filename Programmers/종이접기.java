import java.util.*;

class Solution {
    public int[] solution(int n) {
        int[] answer = {};
        List<Integer> list = new ArrayList<>();
        
        if(n == 1){
            answer = new int[1];
            answer[0] = 0;
            return answer;
        }
        
        
        list.add(0);
        
        int count = 1;
        
        
        while(count < n){
            
            List<Integer> newList = new ArrayList<>();
            int extension = 0;
            
            for(int i=0; i<list.size(); i++){
                newList.add(extension);
                newList.add(list.get(i));
                
                if(extension == 0) extension = 1;
                else extension = 0;
            }
            newList.add(extension);
            
            list = newList;
            count++;
            
        }
        
        answer = new int[list.size()];
        for(int i=0; i<list.size(); i++)
            answer[i] = list.get(i);
        
        
        return answer;
    }
}