import java.util.*;

class Solution {
    int[] visited = new int[8];
    int colMax = 0;
    int rowMax = 0;
    int answer = 0;
    String[][] columns = new String[8][20];
    
    public int solution(String[][] relation) {
        rowMax = relation.length;
        colMax = relation[0].length;
        
        for(int i=0; i<relation[i].length; i++){
            for(int j=0; j<relation.length; j++){
                columns[i][j] = relation[j][i];
            }
        }
        
        DFS(new ArrayList<String>(), 0);
        
        
        return answer;
    }
    
    
    
    
    
    
    private boolean DFS(ArrayList<String> lists, int index){
        boolean ret = false;
        
        if(Check(lists)){
            answer++;
            ret = true;
        }
        
        
        
        for(int i= index; i<colMax; i++){
            ArrayList<String> temp = Join(i, lists);
                if(visited[i] == 0){
                    if(Check(temp)){
                        visited[i] = 1;
                        answer++;
                        visited[i] = 1;
                        ret = true;
                        //System.out.println(temp);
                    }

                    else{
                        Queue q = new LinkedList();
                        q.offer(temp);
                        int start = i+1;
                        boolean check = false;
                        while(!q.isEmpty()){
                            
                            for(int i=)
                            
                            ArrayList<String> top = q.pop();
                            
                            if(Check(top)){
                                check= true;
                                break;
                            }
                            
                            for(int i = start; i<colMax; i++){
                                q.offer(Join(i,top));
                            }
                            
                        }
                        
                        if(check)
                            answer++;
                    }
                }
        }
        
        return ret;
        
    }
    
    private ArrayList<String> Join(int index, ArrayList<String> _copy){
        ArrayList<String> lists = new ArrayList<>();
        lists.addAll(_copy);
        
        if(lists.size() == 0){
            for(int i=0; i<rowMax; i++){
                lists.add(columns[index][i]);
            }
            return lists;
        }
        
        
        for(int i=0; i<rowMax; i++){
            String content = lists.get(i);
            lists.set(i, content+" "+columns[index][i]);
        }
        
        return lists;
        
    }
    
    private boolean Check(ArrayList<String> lists){
        
        if(lists.size() == 0)
            return false;
        
        ArrayList<String> temp = new ArrayList<>();
        temp.addAll(lists);
        
        for(String content : lists){
            temp.remove(content);

            if(temp.contains(content))
                return false;
        }
        
        return true;

    }
    
    
}//END CLASS