class Solution {
    public int solution(String name) {
        int answer = 0;
        
        for(int i=0; i<name.length(); i++){
            
            if(name.charAt(i) != 'A'){
                int up = name.charAt(i) - 'A';
                int down = 'Z' - name.charAt(i) +1;
                answer += up < down ? up: down;
            }
        }
         
        int minMove = name.length() - 1;
        for(int i = 0 ; i < name.length() ; i++) {
            if(name.charAt(i) != 'A') {
                int next = i+1;
                while(next < name.length() && name.charAt(next) == 'A') {
                    next++;
                }
                int move = 2 * i + name.length() - next;
                minMove = Math.min(move, minMove);
            }
        }
        
        
        
        return answer +  minMove;
    }
}