import java.util.*;

class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        
        if(people.length == 1)
            return 1;
        
        List<Integer> list = new ArrayList<>();
        
        
        for(int i=0; i< people.length; i++)
            list.add(people[i]);
        Collections.sort(list);
        
        
        int p=0;
        for(int nowPerson : list)
            people[p++] = nowPerson;
        
        for(int start = 0,last = people.length - 1; start < last;){
            
            
            
            while(start < last){

                int left = limit;
                int startPerson = people[start];
                int lastPerson = people[last];


                left -= startPerson;
                left -= lastPerson;
                
                if(left >= 0){
                    start++;
                    last--;
                    break;
                }

                else{
                    answer++;
                    last--;
                }

            }
            answer++;
            
        }
        
        
        return answer;
    }
}