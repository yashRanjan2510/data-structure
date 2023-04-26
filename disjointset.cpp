#include<bits/stdc++.h>
using namespace std;
class disjointset {
	vector<int> rank,parent,size;
	public:
		disjointset(int n){
			rank.resize(n+1,0);
			parent.resize(n+1);
			size.resize(n+1,1);
			
			for(int i=0;i<=n;i++){
				parent[i]=i;
				
			}  
		}
		int findup(int node){
			if(node==parent[node])
			return node;

            return parent[node]= findup(parent[node]);
		}
		void  unionbyrank(int u,int v){
			int upu=findup(u);
			int upv=findup(v);
			if(upu==upv)// belonging to same component
			return;
			
			if(rank[upu]<rank[upv]){
				parent[upu]=upv;
			}
			else if(rank[upu]>rank[upv]){
				parent[upv]=upu;
			}
			else{
     			parent[upv]=upu;
     			rank[upu]++;
	
			}
		}
		
		void  unionbysize(int u,int v){
			int upu=findup(u);
			int upv=findup(v);
			if(upu==upv)// belonging to same component
			return;
			if(size[ulu]<size[ulv])
			 {
			 	parent[ulu]=ulv;
			 	size[ulv]+=size[ulu];
			 }
			 else{
			 	parent[ulv]=ulu;
			 	size[ulu]+=size[ulv];
			 }
			}
		        
};

int main(){
	disjointset  ds(7);
	ds.unionbyrank(1,2);
	ds.unionbyrank(2,3);
	ds.unionbyrank(4,5);
	ds.unionbyrank(6,7);
	ds.unionbyrank(5,6);
	if(ds.findup(3)==ds.findup(7)){
		cout<<"same";
	}
	else
	cout<<"not same";
    ds.unionbyrank(3,7);
    if(ds.findup(3)==ds.findup(7)){
		cout<<"same";
	}
	else
	cout<<"not same";
   
	return 0;
}
