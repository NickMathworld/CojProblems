#include <bits/stdc++.h>
using namespace std;
bool almostIncreasingSequence(vector<int> sequence) {
   bool res = false;
   sequence.push_back(100005);
   sequence.push_back(100006);
   sequence.push_back(100007);
   for(int i=0;i<sequence.size()-1;i++){
   		if(sequence[i] >= sequence[i+1]){
   			if( !res ){
   				if( sequence[i] < sequence[i+2])
	   				res=true,i++;
	   			else if(!i and sequence[i+1] < sequence[i+2])
	   				res=true;
	   			else if(i and sequence[i-1] < sequence[i+1])
	   				res=true;
	   			else return false;
   			}
	   		else return false;
   		}
   }
   	return true;
};

int main(){
 	vector<int>input = *(new vector<int>());
 	int aux = 0;
 	while(cin >> aux)
 		input.push_back(aux);
 	cout << almostIncreasingSequence(input);
}