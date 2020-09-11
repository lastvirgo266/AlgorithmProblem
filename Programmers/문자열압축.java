import java.util.*;

class Solution {
    public int solution(String s) {
        
        if(s.length() == 1)
            return 1;
        
        int answer = 0;
        answer = solve(s);
        return answer;
    }
    
    public int solve(String s){
        int max = s.length()/2;
        int answer = 99999;
        
        for(int i=1; i<=max; i++){
            int val = getSplitMin(s, i);
            if(val < answer && val != 0){
                answer = val;
            }
        }
        
        return answer;
    }
    
    
    public int getSplitMin(String s, int n){
        
        String prev = "";
        String newS = "";
        int count =1;
        
        prev = s.substring(0,n);
        
        for(int i=n; i<s.length(); i+=n){
            
            
            
            if(i+n >= s.length()){
                String now = s.substring(i, s.length());
                if(now.equals(prev)){
                    count++;
                    newS += count + prev;
                    count = 0;
                    break;
                }
                
                if(count > 1){
                    newS += count + prev;
                }
                else{
                    newS += prev;
                }
                
                newS += s.substring(i,s.length());
                count = 0;
                break;
            }

            String now = s.substring(i,i+n);
            
            if(prev.equals(now)){
                count++;
            }
            
            else{
                if(count > 1){
                    newS += count + prev;
                }
                else{
                    newS += prev;
                }
                
                count = 1;
            }
            
            prev = now;
        }
        
        if(count > 1){
            newS +=  count+ prev;
        }
        else if (count == 1){
            newS += prev;
        }
        
        
        return newS.length();
    }
}