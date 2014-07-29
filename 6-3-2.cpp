//#include<iostream>
//#include<stdlib.h>
//using namespace std;
//#define MAXN 1000
//char s[MAXN+10];
//int faild;
//int n=0,ans[MAXN];
//
//struct Node{
//    int have_value;
//    int val;
//    Node *left,*right;
//};
//
//Node* newnode()
//{
//    Node *u = new Node;
//    if(u!=NULL){
//        u->have_value=0;
//        u->left = u->right = NULL;
//    }
//    return u;
//}
//Node* root = newnode();
//
//
//void addnode(int v,char *s)
//{
//    int n=strlen(s);
//    Node* u = root;
////    Node *u = root;
//    for(int i=0;i<n;i++){
////        cout<<s[i];
//        if(s[i]=='L'){
//            if(u->left==NULL) u->left = newnode();
//            u = u->left;
//        }
//        else if(s[i]=='R'){
//            if(u->right == NULL) u->right = newnode();
//            u = u->right;
//        }
//        if(u->have_value) faild = 1;
//        if(s[i]==')')
//            u->val = v;
////        cout<<"44 "<<u->val<<endl;
//        u->have_value = 1;
//    }
//}
//
//int bfs()
//{
//    int front=0,rear=1;
//    Node* q[MAXN];
//    q[0] = root;
////    cout<<"51  "<<q[0]->val<<endl;
//    while(front<rear){
//        Node *u=q[front++];
//        if(!u->have_value) { cout<<"u had not a value\n"; return 0; }
//        ans[n++] = u->val;
//        if(u->left!=NULL) q[rear++] = u->left;
//        if(u->right!=NULL) q[rear++] = u->right;
//    }
//    return 1;
//}
//
//
//void remove_tree(Node *u){
//    if(u==NULL) return;
//    remove_tree(u->left);
//    remove_tree(u->right);
//    free(u);
//}
//
//int read_input()
//{
//    faild=0;
//    for(;;){
//        if(scanf("%s",s)!=1) return 0;
//        if(!strcmp(s,"()")) break;
//        int v;
//        sscanf(&s[1],"%d",&v);
//        addnode(v,strchr(s,',')+1);
//    }
//    return 1;
//}
//
//
//int main()
//{
//    freopen("6-3-2.in","r",stdin);
//    read_input();
//    bfs();
//    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
//    remove_tree(root);
//    return 0;
//}



#include<iostream>
using namespace std;
struct Node
{
    int val;
    Node *left,*right;
};

Node* newnode()
{
    Node* u = new Node();
    if(u!=NULL){
        u->val=0;
        u->left=u->right=NULL;
    }
    return u;
}

Node* root = newnode();

void addnode(int v,string s)
{
    Node* r = root;
//    cout<<"r->val="<<r->val<<endl;
    int i=0;
    for(i=0;i<s.length();i++){
        if(s[i]=='L'){
//            cout<<"->left";
            if(r->left==NULL){
                r->left=newnode();
            }
            r=r->left;
        }
        else if(s[i]=='R'){
//            cout<<"->right";
            if(r->right==NULL){
                r->right=newnode();
            }
            r=r->right;
        }
        else{
            r->val=v;
//            cout<<'\n'<<r->val<<endl;
        }
    }
}


void bfs()
{
    int q[10];
    Node* nodeq[10];
    nodeq[0] = root;
//    cout<<root->val<<" 152"<<endl;
    int front=0,rear=1;
    while(front<rear){
        cout<<nodeq[front]->val<<endl;
        if(nodeq[front]->left!=NULL){
            nodeq[rear++]=nodeq[front]->left;
        }
        if(nodeq[front]->right!=NULL){
            nodeq[rear++]=nodeq[front]->right;
        }
        front++;
    }
}


void get_input()
{
    string s;
    int n;
    while(1){
        cin>>s;
        if(s=="()") break;
        sscanf(&s[1],"%d",&n);
//         cout<<n<<" at 174"<<endl;
        s.erase(0,s.find_first_of(',')+1);
        addnode(n,s);
    }
}


int main()
{
    freopen("6-3-2.in","r",stdin);
    get_input();
    bfs();
//    cout<<"end"<<endl;
    return 0;
}

