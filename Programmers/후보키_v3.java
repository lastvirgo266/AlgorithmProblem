import java.util.*;

class Solution {
    int colMax = 0;
    int rowMax = 0;
    
    String[][] columns;
        
    static ArrayList<HashSet<Integer>> candidates;
    
    public int solution(String[][] relation) {
        candidates = new ArrayList<HashSet<Integer>>();
        int answer = 0;
        rowMax = relation.length;
        colMax = relation[0].length;
        
        columns = new String[colMax][rowMax];
        
        for(int i=0; i<relation[0].length; i++){
            for(int j=0; j<relation.length; j++){
                columns[i][j] = relation[j][i];
            }
        }
        
        DFS(new HashSet<Integer>(), 0);
        
        answer = candidates.size();
        
        return answer;
    }
    
    
    private void DFS(HashSet<Integer> lists, int pos){
        
        if(pos == colMax){
            boolean result = Join(lists);
            return;
        }
        
        
        HashSet<Integer> lists_1 = new HashSet<>();
        HashSet<Integer> lists_2 = new HashSet<>();
        
        
        lists_1.addAll(lists);
        lists_2.addAll(lists);
        lists_2.add(pos);
        
        DFS(lists_1,pos+1);
        DFS(lists_2,pos+1);
        
        
        return;
        
    }
    
    private boolean Join(HashSet<Integer> _copy){
        HashSet<Integer> lists = new HashSet<>();
        lists.addAll(_copy);

        
        for(int i=0; i<candidates.size(); i++){
            if(lists.containsAll(candidates.get(i)))
                return false;
        }
        
        HashSet<String> query_res = new HashSet<>();
        for(int i=0; i<columns[0].length; i++){
            String content = "";
            for(int j : lists)
                content += (columns[j][i] +",");
            
            if(query_res.contains(content))
                return false;
            else{
                query_res.add(content);
            }
        }
        
        candidates.add(lists);
        
        return true;
        
    }

    
}//END CLASS