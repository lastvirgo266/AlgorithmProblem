class Solution {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];
        
        
        for(int i=0; i<arr1.length; i++){
            String result = binaryChange(arr1[i], n);
            String subAns = "";
            
            for(int j=0; j<result.length(); j++){
                if(result.charAt(j) == '1')
                    subAns += "#";
                else
                    subAns += " ";
            }
            
            answer[i] = subAns;
        }
        
        for(int i=0; i<arr2.length; i++){
            String result = binaryChange(arr2[i], n);
            StringBuilder builder = new StringBuilder(answer[i]);
            
            for(int j=0; j<result.length(); j++){
                if(result.charAt(j) == '1')
                    builder.setCharAt(j, '#');
            }
            
            answer[i] = builder.toString();
        }
        
        //System.out.println(binaryChange(0,5));
        
        
        return answer;
    }
    
    
    public String binaryChange(int number, int n){
        String result = "";
        
        while(number != 0){
            result += Integer.toString(number%2);
            number /= 2;
        }
        
        if(result.length() < n){
            int remind = n-result.length();
            
            for(int i=0; i<remind; i++)
                result +="0";
        }
        
        
        
        return ( new StringBuffer(result) ).reverse().toString();
        
    }
    
}