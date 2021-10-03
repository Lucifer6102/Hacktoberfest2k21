//Kth largest element in array implelmented using Priority queue (min heap)

#include<iostream>
#include<queue>
using namespace std;
int main(){
int a[]={12, 3, 5, 7, 19 };
int n=5;
int k=3;
priority_queue<int>maxi;   //implementing max_heap using priority_queue
                            //priority_queue<int,vector<int>,greater <int> >mini; -to implement min heap and find kth smallest
   for(int i=0;i<n;++i){
   	 maxi.push(a[i]);
   }
   
  while(--k) {            //deleting upto k+1th term
  	maxi.pop();

}
cout<<maxi.top()<<endl;

return 0;
}
