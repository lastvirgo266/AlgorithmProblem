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
        ArrayList<String> common = new ArrayList<>();
        ArrayList<String> sum = new ArrayList<>();
        
        Map<String, Integer> cacheStr1 = new HashMap<>();
        Map<String, Integer> cacheStr2 = new HashMap<>();
        
        for(int i=0; i<str1.size(); i++){
            String temp = str1.get(i);
            if(!cacheStr1.containsKey(temp)){
                cacheStr1.put(temp,1);
            }
            
            else{
                cacheStr1.put(temp, cacheStr1.get(temp)+1);
            }
        }
        
        for(int i=0; i<str2.size(); i++){
            String temp = str2.get(i);
            if(!cacheStr2.containsKey(temp)){
                cacheStr2.put(temp,1);
            }
            
            else{
                cacheStr2.put(temp, cacheStr2.get(temp)+1);
            }
        }
        
        //dup
        Set<String> keys1 = cacheStr1.keySet();
        for(String key1 : keys1){
            if(cacheStr2.containsKey(key1)){
                int max= 0, min=0;
                if(cacheStr1.get(key1) < cacheStr2.get(key1)){
                    max = cacheStr2.get(key1);
                    min = cacheStr1.get(key1);
                }
                
                else{
                    max = cacheStr1.get(key1);
                    min = cacheStr2.get(key1);  
                }
                
                for(int i=0; i< min; i++){
                    common.add(key1);
                }
                
                for(int i=0; i< max; i++){
                    sum.add(key1);
                }
            }
        }
        
        for(int i=0; i<str1.size(); i++){
            String temp = str1.get(i);
            if(!sum.contains(temp)){
                sum.add(temp);
            }
        }
        
        for(int i=0; i<str2.size(); i++){
            String temp = str2.get(i);
            if(!sum.contains(temp)){
                sum.add(temp);
            }
        }
        
        double jakard = (double)common.size()/(double)sum.size();
        
        return (int)(jakard*65536);
        
        
    }
    
    
    
}//End Class