#include "Assistance.h"					// 辅助软件包
#include "AdjListDirNetwork.h"		// 邻接表有向网
int target;
int n=6;


int main()
{
    int infity = DEFAULT_INFINITY;
    char vexs[] = {'A', 'B', 'C', 'D','E','F'};
    int m[6][6] = {
        {infity,7,infity,infity,14,9},
        {infity,infity,15,infity,infity,10},
        {infity,infity,infity,6,infity,infity},
        {infity,infity,infity,infity,infity,infity},
        {infity,infity,infity,9,infity,infity},
        {infity,infity,11,infity,2,infity}
        };
    char e, e1, e2;
    int v, v1, v2, w;

    AdjListDirNetwork<char, int> net(vexs, n);

    for (int v = 0; v < n; v++)
        for (int u = 0; u < n; u++)
            if (m[v][u] != infity) net.InsertArc(v, u, m[v][u]);

    if (net.IsEmpty())
        cout << "该有向网为空。" << endl;
    else
        net.Display();

    DFSTraverse<char>(net);
//    for (int i = 0; i < net.GetVexNum(); i++)
//		if (net.GetTag(i) == UNVISITED)
    int start=0;
    int targ=3;

    cout<<dijkstra(net,start,targ)<<endl;

    return 0;
}

