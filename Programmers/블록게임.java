import java.util.*;

class Solution {
    
    int[][] map;
    int N;
    
    int[][] direction_H = {
        {0,1}, {1,0},{1,1},{2,0},{2,1}
    };
    
    int[][] direction_V = {
        {0,1},{0,2},{1,0},{1,1},{1,2}
    };
    
    
    public int solution(int[][] board) {
        int answer = 0;
        map = board;
        N= board.length;
        
        int j=0;
        
        
        while(true){
            
            for(int i=0; i<N; i++){
                downBlock(i);
            }
            
            printMap();
            
                
            int val = checkSquare_H();
            val += checkSquare_V();
                
            if(val > 0){
                reset();
                answer += val;
                printMap();
            }
            
            else{
                break;
            }
                
        }
        
        
        return answer;
        
        
        
    }
    
    public int downBlock(int n){
        int val = -1;
        
        for(int i=0; i<N; i++){
            if(map[i][n] == 0){
                continue;
            }
            
            else if(i-1 >= 0){
                map[i-1][n] = -1;
                val = i-1;
                break;
            }
        }
        
        return val;
    }
    
    public int checkSquare_H(){
        
        int answer = 0;
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                int nowY = i;
                int nowX = j;
                
                if(map[nowY][nowX] == 0){
                    continue;
                }
                
                int checkNumber = 0;
                int isDelete = 1;
                
                for(int k=0; k<5; k++){
                    int newY = nowY + direction_H[k][0];
                    int newX = nowX + direction_H[k][1];
                    
                    if(isRange(newY, newX)){
                        int val = map[newY][newX];
                        
                        if(val == 0){
                            isDelete = 0;
                            break;
                        }
                        
                        if(checkNumber == 0){
                            if(val == -1){
                                checkNumber = 0;
                            }
                            else{
                                checkNumber = val;
                            }
                            continue;
                           
                        }
                        
                        if(checkNumber != val){
                            isDelete = 0;
                            break;
                        }
                    }
                    
                    else{
                        isDelete = 0;
                        break;
                    }
                    
                }
                
                if(isDelete == 1){
                    map[nowY][nowX] = 0;
                    for(int k=0; k<5; k++){
                        int newY = nowY + direction_H[k][0];
                        int newX = nowX + direction_H[k][1];
                        map[newY][newX] = 0;
                    }
                    answer++;
                }
            }
        }
        
        return answer;
        
    }
    
    
        public int checkSquare_V(){
        
        int answer = 0;
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                int nowY = i;
                int nowX = j;
                
                if(map[nowY][nowX] == 0){
                    continue;
                }
                
                int checkNumber = 0;
                int isDelete = 1;
                
                for(int k=0; k<5; k++){
                    int newY = nowY + direction_V[k][0];
                    int newX = nowX + direction_V[k][1];
                    
                    if(isRange(newY, newX)){
                        int val = map[newY][newX];
                        
                        if(val == 0){
                            isDelete = 0;
                            break;
                        }
                        
                        if(checkNumber == 0){
                            if(val == -1){
                                checkNumber = 0;
                            }
                            else{
                                checkNumber = val;
                            }
                            continue;
                           
                        }
                        
                        if(checkNumber != val || val == 0){
                            isDelete = 0;
                            break;
                        }
                    }
                    
                    else{
                        isDelete = 0;
                        break;
                    }
                    
                }
                
                if(isDelete == 1){
                    map[nowY][nowX] = 0;
                    for(int k=0; k<5; k++){
                        int newY = nowY + direction_V[k][0];
                        int newX = nowX + direction_V[k][1];
                        map[newY][newX] = 0;
                    }
                    answer++;
                }
                
            }
        }
        
        return answer;
        
    }
    
    public void reset(){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(map[i][j] == -1){
                    map[i][j] = 0;
                }
            }
        }
    }
    
    
    public boolean isRange(int y, int x){
        if(0<= y && y < N){
            if(0<= x && x< N){
                return true;
            }
            return false;
        }
        
        return false;
    }
    
    
    public void printMap(){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                System.out.print(map[i][j]+"      ");
            }
            
            System.out.println("");
        }
        
        System.out.println("");
        System.out.println("");
    }
    
    
    
}