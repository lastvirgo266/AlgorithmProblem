import java.util.*;

class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        
        if(people.length == 1)
            return 1;
        
        Arrays.sort(people);
        
        for(int start = 0,last = people.length - 1; start <= last; start++, answer++){
            
            while(start < last){

                int left = limit;
                int startPerson = people[start];
                int lastPerson = people[last];


                left -= startPerson;
                left -= lastPerson;
                
                if(left >= 0){
                    last--;
                    break;
                }

                else{
                    answer++;
                    last--;
                }

            }
            
        }
        
        
        return answer;
    }
}