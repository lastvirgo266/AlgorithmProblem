import java.util.*;

class Solution {
    public int solution(String str1, String str2) {
        int answer = 0;
        ArrayList<String> refineStr1 = new ArrayList<>();
        ArrayList<String> refineStr2 = new ArrayList<>();
        
        refineStr1 = refine(str1);
        refineStr2 = refine(str2);
        
        if(refineStr1.size() == 0 && refineStr2.size() == 0)
            return 65536;
        else if(refineStr1.size() == 0 || refineStr2.size() == 0)
            return 0;
        
        answer = Jakad(refineStr1, refineStr2);
        
        return answer;
    }
    
    
    
    private ArrayList<String> refine(String temp){
        ArrayList<String> result = new ArrayList<>();
        temp = temp.toUpperCase();
        
        for(int i=0; i<temp.length()-1; i++){
            if('A' <= temp.charAt(i) && temp.charAt(i) <='Z' && 
               'A' <= temp.charAt(i+1) && temp.charAt(i+1) <='Z'){
                String temp_  = "";
                temp_ += temp.charAt(i);
                temp_ += temp.charAt(i+1);
                result.add(temp_);
            }
        }
        
        return result;
    }
    
    
    
    
    private int Jakad(ArrayList<String> str1, ArrayList<String> str2){
        ArrayList<String> intersection = new ArrayList<>();
        ArrayList<String> union = new ArrayList<>();
        
        Collections.sort(str1);
        Collections.sort(str2);
        
        for(String seq : str1){
            if(str2.remove(seq)){
                intersection.add(seq);
            }
            
            union.add(seq);
        }
        
        for(String seq : str2){
            union.add(seq);
        }
        
        
        double jakard = (double)intersection.size()/(double)union.size();
        
        return (int)(jakard*65536);
        
        
    }
    
    
    
}//End Class