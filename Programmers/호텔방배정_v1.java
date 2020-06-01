import java.util.*;

class Solution {
    class Node{
        long index = -1;
        Node next = null;
        
        public Node(long index){
            this.index = index;
        }
        
        public Node getLast(){
            Node prev =null;
            Node next = this.next;
            while(next != null){
                prev = next;
                next= next.next;
            }
            
            if(prev == null)
                prev = this;
            
            return prev;
        }
        
    }
    
    public long[] solution(long k, long[] room_number) {
        long[] answer = new long[room_number.length];
        
        TreeMap<Long, Node> map = new TreeMap<>();
        
        for(int i=0; i<room_number.length; i++){
            long rIndex = room_number[i];
            long nextIndex = rIndex+1 > k ? 1: rIndex+1;
            long prevIndex = rIndex-1 <= 0 ? k : rIndex-1;
            
            if(!map.containsKey(rIndex)){
                Node newNode = new Node(rIndex);
                map.put(rIndex, newNode);
                answer[i] = rIndex;
                
                if(map.containsKey(nextIndex)){
                    Node nextNode = map.get(nextIndex);
                    newNode.next = nextNode;
                }
                
                if(map.containsKey(prevIndex)){
                    Node prevNode = map.get(prevIndex);
                    prevNode.next = newNode;
                }
            }
            
            else{
                Node lastNode = map.get(rIndex).getLast();
                long enterIndex = lastNode.index+1;
                enterIndex = enterIndex > k ? 1 : enterIndex;
                
                Node newNode = new Node(enterIndex);
                lastNode.next = newNode;                
                
                map.put(enterIndex, newNode);
                
                long newNextIndex = enterIndex+1 > k ? 1 : enterIndex+1;
                
                if(map.containsKey(newNextIndex)){
                    Node nextNode = map.get(newNextIndex);
                    newNode.next = nextNode;
                    Node temp = map.get(rIndex);
                }
                
                
                answer[i] = enterIndex;
                
            }
            
        }
        
        return answer;
    }
}