import java.util.*;

class Solution {
    
    ArrayList<ArrayList> store;
    
    public int solution(String[] user_id, String[] banned_id) {
        int answer = 0;
        
        store = new ArrayList<>();
        
        int[] visited = new int[user_id.length];
        
        for(int i=0; i<visited.length; i++)
            visited[i] = 0;
        
        backTracking(user_id, banned_id, visited, 0);
        
        answer = store.size();
        
        return answer;
    }
    
    public void backTracking(String[] user_id, String[] banned_id, int[] visited, int idx){
        
        if(idx == banned_id.length){
            checkList(user_id, visited,idx);
            return;
        }
        
        for(int i=idx; i<banned_id.length; i++){
            
            for(int j=0; j<user_id.length; j++){
                
                if(banned_id[i].length() == user_id[j].length()){
                    
                    boolean val  = true;
                    
                    for(int k=0; k<banned_id[i].length(); k++){
                        
                        if(banned_id[i].charAt(k) == '*')
                            continue;
                        else if( banned_id[i].charAt(k) != user_id[j].charAt(k)){
                            val = false;
                            break;
                        }
                        
                    }
                    
                    if(val){
                        visited[j] = 1;
                        backTracking(user_id, banned_id, visited, idx+1);
                        visited[j] = 0;
                    }
                }
                
            }
            
        }

    }
    
    public void checkList(String[] user_id, int[] visited, int idx){
        
        boolean val = false;
        
        ArrayList<String> temp = new ArrayList<>();
        
        for(int j=0; j<visited.length; j++){
            if(visited[j] == 1){
                temp.add(user_id[j]);
            }
        }
        
        if(temp.size() != idx)
            return;
        
        
        for(int i=0; i<store.size(); i++){
            int matching = 0;
            ArrayList<String> list = store.get(i);
            
            for(String word : temp){
                
                if(list.contains(word)){
                    matching++;
                }
                
            }
            
            if(matching == list.size()){
                val = true;
                break;
            }
            
        }
        
        if(val == false){
            System.out.println(temp);
            store.add(temp);
        }
        
    }
    
}