#include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
#include<string>
#include <unordered_map>
#include<math.h>
#include <bits/stdc++.h>
#define INF 99999


using namespace std;

int visited[10],v=8,m[10][10]= {{0,0,1,0,0,0,0,0},
    {0,0,1,1,0,0,0,0},
    {1,1,0,1,0,0,0,0},
    {0,1,1,0,1,1,0,0},
    {0,0,0,1,0,1,1,0},
    {0,0,0,1,1,0,1,0},
    {0,0,0,0,1,1,0,1},
    {0,0,0,0,0,0,1,0}
};
int path[10],j=0;
const int vert = 4;
unordered_map<string,string> impactmap;

// --------------1----------

void handle( priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq)
{
    while(!pq.empty())
    {
        auto req=pq.top();
        cout << "Processing evacuation request of zone " << req.first << " with severity " << req.second << endl;
        pq.pop();
    }
}

void pq_1()
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({1,10});
    pq.push({2,3});
    pq.push({3,50});
    pq.push({4,0});
    pq.push({5,20});

    cout << "Assume higher the Severity, lower the Priority\n";
    handle(pq);

}

// --------------2----------

void changes(unordered_map<string,string>&impactmap)
{
    int n;
    string s;
    cout << "Enter zone number, and new severity\n";
    cin >> n;
    cin.ignore();
    getline(cin,s);
    string zone = "zone "+to_string(n);
    auto it=impactmap.find(zone);
    if(it!=impactmap.end())
    {
        impactmap[zone]=s;
    }
    else
        cout << "Zone not found\n";
}

void deletezone(unordered_map<string,string>&impactmap)
{
    int n;
    cout << "Enter Zone number\n";
    cin >> n;
    string zone = "zone " + to_string(n);
    auto it = impactmap.find(zone);
    if (it != impactmap.end())
    {
        impactmap.erase(it);
        cout << "Zone deleted\n";
    }
    else
        cout << "Zone not found\n";
}

void searchzone(unordered_map<string,string>&impactmap)
{
    int n;
    cout << "Enter Zone number\n";
    cin >> n;
    string zone = "zone "+to_string(n);
    auto it = impactmap.find(zone);
    if (it != impactmap.end())
    {
        cout << "Zone found\n";
        cout << zone << " : " << impactmap[zone] << endl;
    }
    else
        cout << "Zone not found\n";
}

void hashingdisplay(unordered_map<string,string>&impactmap)
{
    if(impactmap.empty())
    {
        cout << "No zones available\n";
    }
    for(auto &pair:impactmap)
    {
        cout << pair.first << " : " << pair.second << endl;
    }
    cout << endl;
}

void addzone(unordered_map<string,string>&impactmap)
{
    cout << "Enter zone number and severity level\n";
    int n;
    string s;
    cin >> n;
    cin.ignore();
    getline(cin,s);
    string newzone = "zone " + to_string(n);
    impactmap[newzone] = s;
    cout << "New zone added :)\n\n";
}

void hashing_2(int *c)
{
    if(*c==0)
    {
        impactmap["zone 1"] = "High";
        impactmap["zone 2"] = "Medium";
        impactmap["zone 3"] = "Low";
        impactmap["zone 4"] = "Low";
    }

    cout << "Impacted areas and their severity level : \n\n";
    hashingdisplay(impactmap);
    int ch,zone;

    while(1)
    {
        cout << "\n\nWould you like to make any adjustments?\n0. None\n1. Delete zone\n2. Change Severity\n3. Display\n4. Add a zone\n5. Search for a zone\n\n";
        cin >> ch;
        switch(ch)
        {
        case 0:
            return;
            break;
        case 1:
            if(impactmap.empty())
            {
                cout << "No zones available\n";
            }
            else
                deletezone(impactmap);
            break;
        case 2:
            changes(impactmap);
            break;
        case 3:
            hashingdisplay(impactmap);
            break;
        case 4:
            addzone(impactmap);
            break;
        case 5:
            searchzone(impactmap);
            break;
        default :
            cout << "Invalid Choice\n";
            break;
        }
    }
}

// ------------3-----------

typedef pair<int, int> PII;

vector<int> dijkstra(int n, vector<vector<PII>>& graph, int start)
{
    vector<int> dist(n, INT_MAX);
    priority_queue<PII, vector<PII>, greater<PII>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u])
            continue;

        for (const auto& neighbor : graph[u])
        {
            int v = neighbor.second;
            int weight = neighbor.first;

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

void dij_3()
{
    int n = 6;
    vector<vector<PII>> graph(n);

    graph[0].push_back({2, 1});
    graph[0].push_back({4, 2});
    graph[1].push_back({1, 2});
    graph[1].push_back({7, 3});
    graph[2].push_back({3, 3});
    graph[2].push_back({1, 4});
    graph[3].push_back({2, 5});
    graph[4].push_back({5, 5});

    int start = 0;

    vector<int> distances = dijkstra(n, graph, start);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "To node " << i << ": "
             << (distances[i] == INT_MAX ? -1 : distances[i]) << '\n';
    }
}

// -----------4-------------

vector<int> bellf(int V,vector<vector<int>> &edges,int source,vector<int>&parent)
{
    vector<int>dist(V,1e8);
    int u,v,wt;
    dist[source]=0;

    for(int i=1; i<V; i++)
    {
        for(vector<int> e:edges)
        {
            u=e[0];
            v=e[1];
            wt=e[2];
            if(dist[u]!=1e8 && dist[v]>(dist[u]+wt))
            {
                dist[v]=dist[u]+wt;
                parent[v]=u;
            }
        }
    }
    if(dist[u]!=1e8 && dist[v]>(dist[u]+wt))
        return {};
    return dist;

}

void paths(int vertex,vector<int>&parent)
{
    stack<int>p;
    while(vertex!=-1)
    {
        p.push(vertex);
        vertex = parent[vertex];
    }

    while(!p.empty())
    {
        cout << p.top();
        p.pop();

        if(!p.empty())
        {
            cout << " -> ";
        }
    }
}

void bellmanford_4()
{
    vector<vector<int>> edges = {{0,1,5},{1,2,1},{1,3,2},{2,4,1},{4,3,-1}};
    int V = 5, source = 0, i = 0, s = 0;
    vector<int>parent(V,-1);
    vector<int>dist = bellf(V,edges,source,parent);

    if(dist.empty())
        cout << "Routes lead to a negative weighted cycle!\n";

    else
    {
        cout << "Shortest Path from source 0 : \n";
        for(int i=0; i<V; i++)
        {
            cout << "Location " << i << " : " << dist[i] << endl;
            s+=dist[i];
        }
        cout << "\n\nOptimized paths : \n" << endl;

        for(int i=0; i<V; i++)
        {
            cout << "Location " << i << " : ";
            paths(i,parent);
            cout << endl;
        }
        cout << "\nTotal distance travelled = " << s << endl;
    }
}

// -----------------5-------------------

void print(int dist[][vert])
{
    for(int i=0; i<vert; i++)
    {
        for(int j=0; j<vert; j++)
        {
            if(dist[i][j]==INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

void floyd(int dist[][vert])
{
    for(int k=0; k<vert; k++)
    {
        for(int i=0; i<vert; i++)
        {
            for(int j=0; j<vert; j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j] && dist[i][k]!=INF && dist[k][j]!=INF)
                    dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    print(dist);
}

void fw_5()
{
    int graph[vert][vert] = {{0,INF,3,INF},{2,0,INF,INF},{INF,7,0,1},{6,INF,INF,0}};
    cout << "All pair shortest path between shelters and disaster zone : \n";
    floyd(graph);
}
// -----------------6-------------------


void primsAlgorithm(int V, vector<pair<int, int>> adj[])
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int>parent(V,-1);
    vector<int>key(V,INT_MAX);
    vector<bool>inmst(V,false);

    int start = 0;
    key[start] = 0;
    pq.push({0,start}); // weight , node

    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();

        inmst[u] = true;

        for(auto it:adj[u])
        {
            int v=it.first;
            int wt=it.second;

            if(!inmst[v] && wt<key[v])
            {
                parent[v]=u;
                key[v]=wt;
                pq.push({key[v],v});
            }
        }
    }

    cout << "Network of Evacuation Zones and shelters : \n";
    int s=0;
    for(int i=1; i<V; i++)
    {
        cout << parent[i] << " - " << i << " : " << key[i] << endl;
        s+=key[i];
    }
    cout << "Total cost = " << s << endl;
}

void prim_6()
{
    int V = 5;
    vector<pair<int, int>> adj[V];

    // Graph edges (u, v, weight)
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});


    primsAlgorithm(V, adj);
}

// -----------------7--------------------

void heapify( vector<pair<int,int>>&h,int &n)
{
    int i,j,k;
    pair<int,int> v;
    bool heap;
    for(i=n/2; i>=1; i--)
    {
        k=i;
        v=h[k];
        heap=false;
        while(!heap && 2*k<=n)
        {
            j=2*k;
            if(j<n && h[j].second<h[j+1].second)
                j=j+1;
            if(v.second>=h[j].second)
                heap=true;
            else
            {
                h[k]=h[j];
                k=j;
            }
        }
        h[k]=v;
    }

}

void heapsort(vector<pair<int,int>>&h,int &n, vector<pair<int,int>>&d)
{
    while(h.size()!=0)
    {
        d.push_back(h[1]);
        swap(h[1],h[n]);
        h.pop_back();
        n--;
        heapify(h,n);
    }
}

void heapsort_7()
{
    vector<pair<int,int>>h(1);
    int n=5,l=5;

    h.push_back({1,10});
    h.push_back({2,20});
    h.push_back({3,15});
    h.push_back({4,30});
    h.push_back({5,40});


    heapify(h,n);

    cout << "\n\nConsidering the input as the 'safety bar' : higher the value, higher the risk\n";
    cout << "\nZones before prioritization\n";

    for(int i=1; i<=l; i++)
    {
        cout << "Location : " << h[i].first << " , Risk " << h[i].second << "\n";
    }
    cout << "\n\nZones after prioritization\n";

    vector<pair<int,int>>d(1);
    heapsort(h,n,d);

    for(int i=1; i<=l; i++)
    {
        cout << "Location : " << d[i].first << " , Risk " << d[i].second << "\n";
    }
}

// ---------------8-------------

void merge(vector<pair<int,int>> &b,vector<pair<int,int>> &c,vector<pair<int,int>> &a)
{
    int i=0,j=0,k=0,p=b.size(),q=c.size();
    while(i<p && j<q)
    {
        if(b[i].second>=c[j].second)
        {
            a[k] = b[i];
            i++;
        }
        else
        {
            a[k] = c[j];
            j++;
        }
        k++;
    }

    while(i<p)
    {
        a[k]=b[i];
        i++;
        k++;
    }
    while(j<q)
    {
        a[k]=c[j];
        j++;
        k++;
    }
}

void mergesort(vector<pair<int,int>> &a)
{
    if(a.size()>1)
    {
        int half = a.size()/2;
        vector<pair<int,int>> b(a.begin(),a.begin()+half);
        vector<pair<int,int>> c(a.begin()+half,a.end());
        mergesort(b);
        mergesort(c);
        merge(b,c,a);
    }
}

void mergesort_8()
{
    vector<pair<int,int>> tasks = {{1,34},{2,0},{3,45},{4,6},{5,5}};
    cout << "Task number and their priority level : \n\nTask\tPriority\n\n";
    for(auto &pair:tasks)
    {
        cout << pair.first << " \t " << pair.second << endl;
    }
    cout << "\nOn sorting the tasks based on priority level : \n\nTask\tPriority\n\n";
    mergesort(tasks);
    for(auto &pair:tasks)
    {
        cout << pair.first << " \t " << pair.second << endl;
    }
}

// ---------------9--------------

void bfs(int m[10][10],int v,int source)
{
    int queue[10],front=0,rear=0,visited[10];
    for(int i=0; i<v; i++)
        visited[i]=0;
    visited[source]=1;
    queue[rear]=source;

    while(front<=rear)
    {
        int u=queue[front];
        front++;
        cout << u << " ";
        for(int i=0; i<v; i++)
        {
            if(m[u][i]==1 && visited[i]==0)
            {
                visited[i]=1;
                rear++;
                queue[rear]=i;
            }
        }
    }
}
void bfs_9()
{
    cout << "Connectivity of the road, thus allowing water flow in the following path (considering root source of flood is 0):\n ";
    int source = 0;
    bfs(m,v,source);
}

// --------------10--------------

void dfs(int m[10][10],int v,int source)
{
    visited[source]=1;
    for(int i=0; i<v; i++)
    {
        if(m[source][i]==1 && visited[i]==0)
        {
            cout << i << " ";
            for(int j=0; j<v; j++)
            {
                if(m[j][i]==1)
                    path[i]+=1;
            }
            dfs(m,v,i);
        }
    }
}


void dfs_10()
{
    int i=0,source=0;
    for(int i=0; i<v; i++)
    {
        visited[i]=0;
        path[i]=0;
    }

    cout << "\nFinding routes : \n";
    cout << source << " ";
    dfs(m,v,source);

    for(int j=0; j<v; j++)
    {
        if(m[j][i]==1)
            path[i]+=1;
    }

    cout << "\n\nLocations     critical level : \n";
    for(int i=0; i<=7; i++)
    {
        cout << i << "\t\t" << path[i] << "\n";
    }
}
// ----------------11---------------

struct Edge
{
    int src, dest, weight;
};

int find(vector<int>& parent, int u)
{
    if (u != parent[u])
    {
        parent[u] = find(parent, parent[u]);
    }
    return parent[u];
}

void unionSets(vector<int>& parent, vector<int>& rank, int u, int v)
{
    int rootU = find(parent, u);
    int rootV = find(parent, v);

    if (rootU != rootV)
    {
        if (rank[rootU] < rank[rootV])
        {
            parent[rootU] = rootV;
        }
        else if (rank[rootU] > rank[rootV])
        {
            parent[rootV] = rootU;
        }
        else
        {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

int kruskal(int n, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b)
    {
        return a.weight < b.weight;
    });

    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; ++i)
    {
        parent[i] = i;
    }

    int mstCost = 0;
    vector<Edge> mstEdges;

    for (const auto& edge : edges)
    {
        if (find(parent, edge.src) != find(parent, edge.dest))
        {
            mstCost += edge.weight;
            mstEdges.push_back(edge);
            unionSets(parent, rank, edge.src, edge.dest);
        }
    }

    cout << "Edges in the MST for distributing resources across disaster-hit zones:\n";
    for (const auto& edge : mstEdges)
    {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << '\n';
    }

    return mstCost;
}

void krus_11()
{
    int n = 4;
    vector<Edge> edges =
    {
        {0, 1, 4},
        {1, 2, 1},
        {0, 2, 3},
        {2, 3, 2},
        {1, 3, 5}
    };

    int mstCost = kruskal(n, edges);

    cout << "Total cost of MST: " << mstCost << '\n';
}

//------------------12---------------

typedef struct node
{
    int n;
    char status;
    struct node *next;
} road;

road * addroads(road *r)
{
    road *newnode;
    newnode = (road *)malloc(sizeof(road));
    newnode->n=1;
    newnode->status='o';
    newnode->next=nullptr;
    r=newnode;
    road *t=r;

    newnode = (road *)malloc(sizeof(road));
    newnode->n=2;
    newnode->status='x';
    newnode->next=nullptr;
    t->next=newnode;
    t=t->next;

    newnode = (road *)malloc(sizeof(road));
    newnode->n=3;
    newnode->status='o';
    newnode->next=nullptr;
    t->next=newnode;
    t=t->next;

    newnode = (road *)malloc(sizeof(road));
    newnode->n=4;
    newnode->status='x';
    newnode->next=nullptr;
    t->next=newnode;
    t=t->next;

    newnode = (road *)malloc(sizeof(road));
    newnode->n=5;
    newnode->status='o';
    newnode->next=nullptr;
    t->next=newnode;
    t=t->next;

    newnode = (road *)malloc(sizeof(road));
    newnode->n=6;
    newnode->status='x';
    newnode->next=nullptr;
    t->next=newnode;
    t=t->next;

    newnode = (road *)malloc(sizeof(road));
    newnode->n=7;
    newnode->status='x';
    newnode->next=nullptr;
    t->next=newnode;
    t=t->next;

    newnode = (road *)malloc(sizeof(road));
    newnode->n=8;
    newnode->status='o';
    newnode->next=nullptr;
    t->next=newnode;
    t=t->next;

    newnode = (road *)malloc(sizeof(road));
    newnode->n=9;
    newnode->status='o';
    newnode->next=nullptr;
    t->next=newnode;
    t=t->next;

    newnode = (road *)malloc(sizeof(road));
    newnode->n=10;
    newnode->status='o';
    newnode->next=nullptr;
    t->next=newnode;
    t=t->next;

    return r;

}
void display(road *r)
{
    road *t=r;
    if(t==nullptr)
        cout << "No road list\n";
    else
    {
        while(t)
        {
            cout << t->n << " ";
            t=t->next;
        }
        cout << endl;
    }
}

road * ev(road *r)
{
    road *t=r,*p=nullptr,*z;
    if(t==nullptr)
        return r;

    while(t)
    {
        if(t->status=='x')
        {
            z=t;
            cout << "Road " << t->n << " blocked, evacuating it\n";
            if(t==r)
            {
                r=t->next;
                free(z);
                t=r;
            }

            else if(t->next==nullptr)
            {
                p->next=nullptr;
                t=nullptr;
            }
            else
            {
                p->next=t->next;
                t=p->next;
            }
            free(z);
        }
        else
        {
            cout << t->n << "\n";
            p=t;
            t=t->next;
        }
    }
    return r;
}

void ll_12()
{
    road *r=nullptr;
    r=addroads(r);
    r=ev(r);
    cout << "\nFinal roads\n";
    display(r);

}

//-----------------------------------------------------

int main()
{

    int ch,c=0;
    cout << "**Smart Disaster Response and Evacuation System**\n\nThis System is implemented to provide you,\n";
    cout << "with all the facilities needed to survive and evacuate safely in case of a disaster!\n";
    cout << "\nLet's level up our Vasanth Nagar by prioritizing the safety of our citizens!\n\n";
    cout << "Choose the option you need help with : \n\n";

    while(1)

    {
        cout << "\n\n0.  Exit\n1.  Evacuation Request Scheduling (Priority Queue)\n2.  Disaster Impact Mapping (Hashing)\n3.  Optimal Evacuation Routing (Dijkstra's)\n";
        cout << "4.  Dynamic Resource Allocation (Bellman Ford)\n5.  Shelter-to-Zone Connectivity Analysis (Floyd-Warshall)\n6.  Evacuation Zone Network Design (Prim's)\n";
        cout << "7.  High-Risk Zone Prioritization (Heap Sort)\n8.  Task Scheduling for Rescue Operations (Merge Sort)\n9.  Flood Path Prediction (BFS)\n";
        cout << "10. Critical Infrastructure Identification (DFS)\n11. Resource Distribution Cost Minimization (Kruskal's)\n";
        cout << "12. Dynamic Evacuation Path Updates (Linked Lists)\n\n";
        cin >> ch;

        if(ch==1)
        {
            pq_1();
        }
        else if (ch==2)
        {
            hashing_2(&c);
            c=1;
        }
        else if (ch==3)
        {
            dij_3();
        }
        else if (ch==4)
        {
            bellmanford_4();

        }
        else if (ch==5)
        {
            fw_5();
        }
        else if (ch==6)
        {
            prim_6();
        }
        else if (ch==7)
        {
            heapsort_7();

        }
        else if (ch==8)
        {
            mergesort_8();
        }
        else if (ch==9)
        {
            bfs_9();
        }
        else if (ch==10)
        {
            dfs_10();

        }
        else if (ch==11)
        {
            krus_11();
        }
        else if (ch==12)
        {
            ll_12();
        }
        else if (ch==0)
        {
            cout << "Thank you for your time! This System is always at your service!\nExiting...\n";
            exit(0);
        }
        else
        {
            cout << "Invalid Choice, please choose among the above options\n";
        }

    }

    return 0;

}



