#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int V;     // No. of vertices
    list <int>*adj; // An array of adjacency lists adj[]
public:
    Graph(int v_num) {V = v_num; adj = new list<int>[V];}
    void addEdge(int v, int w) {adj[v].push_back(w);}
    void print()
    {
        for (int i = 0; i <V; i ++)
        {
            cout <<"Node- "<< i ;

            if(!adj[i].empty())
            {

               for (list <int>::iterator it = adj[i].begin(); it!= adj[i].end(); ++it)
               {

               cout << " with " << i << " -> " << *it;

               }
            }
            cout << endl;
        }
    }
};

// Driver program to test methods of graph class
int main()
{
    // Create a directed graph given in the diagram below
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.print();
    return 0;
}
