#include "Assistance.h"					// 辅助软件包
#include "AdjListDirNetwork.h"		// 邻接表有向网
int target;
int n=6;


int main()
{
    int infity = DEFAULT_INFINITY;
    char vexs[] = {'A', 'B', 'C', 'D','E','F'};
    int m[6][6] = {
        {infity, 1, infity, 1,1,infity},
        {infity,infity,infity,infity,infity,infity},
        {infity,infity,infity,infity,infity,1},
        {infity,infity,1,infity,infity,infity},
        {infity,infity,infity,infity,infity,infity},
        {infity,1,infity,infity,infity,infity}
        };
    char c = 'a', e, e1, e2;
    int v, v1, v2, w;

    AdjListDirNetwork<char, int> net(vexs, n);

    for (int v = 0; v < n; v++)
        for (int u = 0; u < n; u++)
            if (m[v][u] != infity) net.InsertArc(v, u, m[v][u]);

//    if (net.IsEmpty())
//        cout << "该有向网为空。" << endl;
//    else
//        net.Display();

    DFSTraverse<char>(net);
//    for (int i = 0; i < net.GetVexNum(); i++)
//		if (net.GetTag(i) == UNVISITED)
    int start=0;
    int dist=4;
    int targ=1;
    if(!FindPathInDist(net,start,0,dist,targ)) cout<<"no path"<<endl;




//    DFS(net, net.FirstAdjVex(0) , Visit);
//    DFSTraverse<char>(net, Write<char>);

    return 0;
}
