import java.util.*;

class Solution {
    class Node{
        Node parent = null;
        int count = 0;
        char cur;
        List<Node> children = new LinkedList<>();
        
        public Node(Node parent, char cur){
            this.parent = parent;
            this.cur =cur;
        }
        
        public void addChild(Node child){
            children.add(child);
        }
        
        public Node getChild(char search){
            for(Node child : children){
                if(child.cur == search)
                    return child;
            }
            
            return null;
        }
        
    }
    
    public int solution(String[] words) {
        int answer = 0;
        
        Node root = new Node(null, '-');
        
        for(int i=0; i<words.length; i++){
            Node start;
            
            if( (start = root.getChild(words[i].charAt(0)) ) == null){
                start = new Node(root, words[i].charAt(0));
                root.addChild(start);
           }
            
            start.count++;
           
            
            for(int j=1; j<words[i].length(); j++){
                Node child;
                if((child = start.getChild(words[i].charAt(j))) == null ){
                    child = new Node(start, words[i].charAt(j));
                    start.addChild(child);
                }
                
                child.count++;
                
                start = child;
                
            }
        }
        
        for(int i=0; i<words.length; i++){
            answer += findCost(root, words[i]);
        }
        
        
        return answer;
    }
    
    public int findCost(Node root, String target){
        Node cur = root.getChild(target.charAt(0));
        int cost = 1;
        
        if(cur.children.size() <=1 && cur.count <=1)
            return cost;
        
        
        for(int i=1; i<target.length(); i++){
            Node next;
            
            if((next = cur.getChild(target.charAt(i))) != null){
                cost++;
                if(next.children.size() <= 1 && next.count <=1){
                    break;
                }
            }
            
            else{
                break;
            }
            
            cur = next;
            
            
        }
        
        return cost;
        
        
    }
    
    
}