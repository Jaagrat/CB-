#include <iostream>
#include<queue>
#include<map>
#include<list>
using namespace std;

class Pair{
    public:
        string nbr;
        int weight;
        Pair(string nb,int wt){
            nbr = nb;
            weight = wt;
        }
};

//in most situations, we do not require ordering so instead of using a map ,we can use an unordered map as it consumes less time
class Graph{
    map<string,list<Pair>> l;
    public: 
        void addEdge(string x,string nbr,bool bidir,int wt){
            l[x].push_back(Pair(nbr,wt));
            if(bidir){
                l[nbr].push_back(Pair(x,wt));
            }
        }

        void print(){
            //iterate over all the elements in the map
            for(auto ele: l){
                string name = ele.first;
                cout<<name<<"->";
                //iterating over all the neighbours of a vertex
                for(auto i: ele.second){
                    cout<<"("<<i.nbr<<","<<i.weight<<")"<<",";
                }
                cout<<endl;
            }
        }

        void bfs(string src){
            map<string,bool> visited;
            //mark all vertices as not visited in the begining 
            for(auto ele: l){
                string name = ele.first;
                visited[name]=false;
            }

            queue<string> q;
            q.push(src);
            visited[src] = true;
            while(!q.empty()){
                string name = q.front();
                q.pop();
                cout<<name<<" ";
                for(auto i : l[name]){
                    string nbr = i.nbr;
                    if(!visited[nbr]){
                        q.push(nbr);
                        visited[nbr]=true;
                    }
                }
            }
        }

        //recursive function
        void dfs_helper(string src,map<string,bool> &visited){
            cout<<src<<" ";
            visited[src]=true;
            for(auto i: l[src]){
                string nbr = i.nbr;
                if(!visited[nbr]){
                    dfs_helper(nbr,visited);
                }
            }
        }

        //main dfs function
        void dfs(string src){
            map<string,bool> visited;
            //mark all vertices as not visited in the begining 
            for(auto ele: l){
                string name = ele.first;
                visited[name]=false;
            }
            //call the helper function
            dfs_helper(src,visited);
        }
};

int main() {
    Graph g;
    g.addEdge("A","B",false,20);
    g.addEdge("A","C",true,230);
    g.addEdge("B","C",false,15);
    g.addEdge("B","D",true,0);
    g.addEdge("C","D",true,110);
    g.addEdge("D","E",true,5);
    g.print();
    // g.bfs("B");
    g.dfs("B");
    return 0;

}
