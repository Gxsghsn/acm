#include <iostream>
#include <cstdio>
using namespace std;

int state[100][100];
int pstate=0;

int main()
{
    freopen("10881.txt","r",stdin);
	int w;
	scanf("%d",&w);
	while(w--){
        pstate=0;
		int casenum=1;
		int L,T,n;
		cin>>L>>T>>n;
		int m=n;
		while(m--){
			char c;
            cin>>state[pstate][0];
//			scanf("%d%c",&state[pstate][0],&c);
            cin>>c;
			if(c=='R') state[pstate][1]=1;
			else state[pstate][1]=-1;
			pstate++;
		}

		while(T--){
//			int flag=-1;
			for(int i=0;i<n;i++){
                int flag=0;
				state[i][0]+=state[i][1];
				flag=state[i][0];
			}
			for(int i=0;i<n;i++)
				for(int j=i;j<n;j++)
					if(state[i][0]==state[j][0]){
						state[i][1]*=-1;
						state[j][1]*=-1;
					}
		}
//
//        for(int i=0;i<n;i++){
//            printf("%d %d\n",state[i][0],state[i][1]);
//		}
//		printf("%n");


		printf("Case #%d\n", casenum);
//		cout<<"n: "<<n<<endl;
		for (int i = 0; i < n; i++)
		{
			/* code */

//			int a=-1;
			if(state[i][0]>L||state[i][0]<0)
                cout<<"Fell off"<<endl;
            else{
                int a=0;
                printf("%d ",state[i][0]);
                for(int j=0;j<n;j++){
                	if(j==i) continue;
                    if(state[j][0]==state[i][0]){
                        a=1;
                    }
                }
                if(a==1) printf("Turing\n");
                else if(state[i][1]==1)
                    printf("R\n");
                else printf("L\n");
            }
		}
		casenum++;
		cout<<endl;
	}
	return 0;
}
