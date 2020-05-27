import java.util.*;

class Solution {
    
    public int solution(String[] words) {
        int answer = 0;
        
        for(int i=0; i<words.length; i++){
            String word = words[i];
            int result = searchWordCost(word, words);
            answer += result;
        }
        
        
        return answer;
    }
    
    
    public int searchWordCost(String word, String[] words){
        
        List<String> lists =new LinkedList<>();
        
        for(int i=0; i<words.length; i++)
            lists.add(words[i]);
        
        for(int i=0; i<word.length(); i++){
            List<String> new_lists = new LinkedList<>();
            
            for(String list : lists){
                if(list.length() >= i+1 && 
                   list.charAt(i) == word.charAt(i))
                    new_lists.add(list);
            }
            
            if(new_lists.size()==1){
                return i+1;
            }
            
            lists.clear();
            lists.addAll(new_lists);
            
        }
        
        return word.length();
    }
    
    
}