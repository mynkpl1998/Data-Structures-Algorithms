#include <iostream>
#include<unordered_map>
#include <list>
using namespace std;

class graph 
{
    
    public:
        unordered_map<int, list<int>> adj;
    
        void addEdge(int u, int v, bool direction)
        {
            // if direction = 0, undirected
            // if direction = 1, directed
            
            adj[u].push_back(v);

            if(direction == 0)
                adj[v].push_back(u);
        }

        void printAdjList()
        {
            unordered_map<int, list<int>>::iterator ptr = adj.begin();
            for(unordered_map<int, list<int>>::iterator ptr=adj.begin(); ptr != adj.end(); ptr++)
            {
                cout<<ptr->first<<"->";
                for(list<int>::iterator lptr = ptr->second.begin(); lptr != ptr->second.end(); lptr++)
                    cout<<*lptr<<", ";
                cout<<endl;
            }
            
        }

};

int main()
{
    int nodes;
    int edges;
    cout<<"Enter number of nodes in graph: "<<endl;
    cin>>nodes;

    cout<<"Enter number of edges in graph: "<<endl;
    cin>>edges;

    graph g;

    for(int i=0; i<edges; i++)
    {
        int u, v;
        cin>>u>>v;
        g.addEdge(u, v, 1); // undirected
    }

    g.printAdjList();

    return 0;
}