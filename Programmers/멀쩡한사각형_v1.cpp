#include<stdio.h>
#include<algorithm>

using namespace std;

int gcd(int a, int b){
	while(b!=0){
		int r = a%b;
		a= b;
		b= r;
	}
	return a;
}

long long solution(int w,int h)
{
	long long answer = 1;
    
    int g = gcd(w,h);
    
    int _max = max(w, h);
    int _min = min(w, h);
    
    int max_divide = _max / g;
    int min_divide = _min / g;
    
    long long not_use;
    
    if(max_divide == 1){
        not_use = 1;    
    }
    
    else if(min_divide == 1){
        not_use = min_divide * max_divide;
    }
    
    else{
        not_use = (max_divide - 2)*2 + 2;
    }
    
    not_use *= g;
    
    answer = w*h - not_use;
    
    
    
    
    
    
    
	return answer;
}