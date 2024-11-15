#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {
		vis[node]=1; pathVis[node]=1;

		for(auto it: adj[node]){
			if(!vis[it]) {
				if(dfsCheck(it,adj,vis,pathVis)) return true;
			}
			else if(pathVis[it]){
				return true;
			}
		}
		pathVis[node]=0;
		return false;
	}
public:
	// Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) {
		int vis[V]={0}; int pathvis[V]={0};

        for (int i = 1; i <= V; i++)
        {
            if(!vis[i])
            {
                if(dfsCheck(i,adj,vis,pathvis)) return true;
            }
        }
        return false;
        
	}
};


int main() {

	// V = 11, E = 11;
	vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	int V = 11;
	Solution obj;
	bool ans = obj.isCyclic(V, adj);

	if (ans)
		cout << "True\n";
	else
		cout << "False\n";

	return 0;
}