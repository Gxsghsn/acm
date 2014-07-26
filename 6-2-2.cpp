#include<iostream>
using namespace std;


struct node
{
    int data;
    node *left;
    node *right;
    node(int num=0) {this->data=num;this->left=this;this->right=this;}

    node(int num=0,node b,node c) {this->data=num;this->left=&b;this->right=&c;}

    void get_node(int data=0,node *Left=NULL,node *Right=NULL)
    {
        this->data=data;
        this->left=Left;
        this->right=Right;
    }

    void link(node *Left,node *Right)
    {
        this->left=Left;
        this->right=Right;
    }
};

ostream& operator <<(ostream &out,const node a)
{
    out<<a.data;
    return out;
}

ostream& operator <<(ostream &out,const node* a)
{
    out<<(*a).data;
    return out;
}

void link(node &a,node &b)
{
    a.right=&b;
    b.left=&a;
}
void link(node* &a,node &b)
{
    (*a).right=&b;
    b.left=a;
}
void link(node &a,node* &b)
{
    a.right=b;
    (*b).left=&a;
}
void link(node* &a,node* &b)
{
    (*a).right=b;
    (*b).left=a;
}

node get_node(int data,node a,node b)
{
    node c(data,a,b);
//    c.get_node(data,&a,&b);
    return c;
}
node get_node(int data)
{
    node c(data,c,c);
    return c;
}
int main()
{
//    freopen("6-2-2.in","r",stdin);
//    node a(1);
//    node b(2);
//    link(a,b);
//    cout<<a.right<<endl;
//    cout<<b.left<<endl;


//

    int n;
    cin>>n;
    node a[10];
    //inistallize
    for(int i=0;i<=n;i++)
        a[i] = get_node(i);
//    cout<<
    //link
    for(int i=0;i<n;i++)
        link(a[i],a[i+1]);

//    for(int i=0;i<n;i++)
//    {
//        cout<<a[0].right<<" ";
//        a[0]=*(a[0].right);
//    }



//    //display
//    for(int i=0;i<n;i++)
//        cout<<a[i]<<" ";
//    cout<<endl;
////    cout<<*(a[0].right)<<endl;
//    for(int i=0;i<n-1;i++)
//        cout<<*a[i].right<<" ";




    int num;
    cin>>num;
//    cout<<a[1].right<<endl;
    while(num>0)
    {
        int o,p;
        char c;
        cin>>c;
//        cout<<c<<endl;
        if(c=='A')
        {
            cin>>o>>p;
            link(a[o].left,a[o].right);
            link(a[p].left,a[o]);
            link(a[o],a[p]);
        }
        if(c=='B')
        {
            cin>>o>>p;
            link(a[o].left,a[o].right);
            link(a[o],a[p].right);
            link(a[p],a[o]);

        }
        num--;
//        cout<<a[1].right<<endl;
    }

    for(int i=0;i<n;i++)
    {
        cout<<a[0].right<<" ";
        a[0]=*(a[0].right);
    }

    return 0;
}
