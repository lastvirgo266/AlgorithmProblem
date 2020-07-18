import java.util.*;

class Solution {
    public int solution(int[] people, int limit) {
        int answer = 1;
        
        int left = limit;
        
        List<Integer> list = new ArrayList<>();
        
        
        for(int i=0; i< people.length; i++)
            list.add(people[i]);
        
        
        Collections.sort(list);
        
        for(int nowPerson : list){
            
            left -= nowPerson;
            
            if(left < 0){
                answer++;
                left = limit;
                left -= nowPerson;
            }
            
        }
        
        
        return answer;
    }
}