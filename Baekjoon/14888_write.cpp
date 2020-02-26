#include<stdio.h>
#include<stack>
using namespace std;


typedef struct _obj{
    int index;
    long long result;
    int oper[4];

}Obj;

int main(){

    int N;
    int number[100];
    int oper[4];
    long long max = -1000000000;
    long long min = 1000000000;

    stack<Obj> s;

    scanf("%d",&N);

    for(int i=0; i<N; i++){
        int temp;
        scanf("%d",&temp);
        number[i] = temp;
    }


    for(int i=0; i<4; i++){

        int temp;
        scanf("%d",&temp);
        oper[i] = temp;
    }

    
    Obj obj;
    obj.index = 0;
    obj.result = (long long)number[0]; 

    for(int i=0; i<4; i++){
        obj.oper[i] = oper[i];
    }

    

    s.push(obj);

    

    while(!s.empty()){

        Obj temp =  s.top();
        s.pop();
        
        if(temp.index == N-1){

           max = max > temp.result ? max : temp.result;
           min = min < temp.result ? min : temp.result;
           continue;
        }


            for(int i=0; i<4; i++){
                Obj new_obj;
                new_obj = temp;
                new_obj.index = temp.index;
                new_obj.index +=1;

                for(int i=0; i<4; i++){
                    new_obj.oper[i] = temp.oper[i];
                }

                new_obj.oper[i] -=1;
                
                if(temp.oper[i]-1 >= 0){
                    if(i==0){
                        new_obj.result = temp.result + number[temp.index+1];
                    }

                    else if(i==1){
                        new_obj.result = temp.result - number[temp.index+1];
                    }

                    else if(i==2){
                        new_obj.result = temp.result * number[temp.index+1];
                    }

                    else if(i==3){
                        new_obj.result = temp.result / number[temp.index+1];
                    }

                    s.push(new_obj);
                }

            }


    }

    

    printf("%lld\n",max);
    printf("%lld\n",min);

    return 0;
    

}