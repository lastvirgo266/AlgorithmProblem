class Solution {
    public String solution(int n, int t, int m, int p) {
        String answer = "";
        int nowTurn = 1;
        
        for(int i=0; i<m*t;i++){
            String result = digitChange(i, n);
            
            if(i== 0)
                result = "0";
            
            int len = result.length();
            
            for(int j=0; j<len; j++){
                
                if(nowTurn == p){
                    answer += result.charAt(j);
                }
                nowTurn++;
                
                if(nowTurn == m+1)
                    nowTurn = 1;
                
                if(answer.length() == t )
                    return answer;
            }
            
        }
        
        //answer = digitChange(22,13);
        
        return answer;
    }
    
    public String digitChange(int n, int digit){
        String answer = "";
        
        if(n == 0)
            return "";
        
        answer += numberChange(n%digit);
        
        answer = digitChange(n/digit, digit).concat(answer);
        
        return answer;
        
        
    }
    
    public String numberChange(int number){
        char basic = 'A';
        
        if(number >= 10){
            basic += (number-10);
            String temp = Character.toString(basic);
            return temp;
        }
        
        else{
            return Integer.toString(number);
        }
        
    }
    
}