#include<iostream>
using namespace std;
int findnum=4;
int bucketsize1=6,bucketsize2=3,bucketsize3=1;
int stateq[10000000];
int stateqp=0;
int stateqf=0;

void states(int state1,int state2,int state3)
{
//    if(state1)
//    for(int i=0;i<stateqp;i+=3){
//        if(state1==stateq[i]&&state2==stateq[i+1]&&state3==stateq[i+2])
//            return ;
//    }
//    cout<<state1<<state2<<state3<<endl;
    stateq[stateqp]=state1;
    stateqp++;
    stateq[stateqp]=state2;
    stateqp++;
    stateq[stateqp]=state3;
    stateqp++;
}


void pour(int mainb,int mainbsize,int leftb,int leftbsize,int rightb,int rightbsize)
{
    while(mainb>0 && (leftb<leftbsize)){
        while(leftb<leftbsize && mainb>0){
            mainb--; leftb++;
        }
//        while(rightb<rightbsize && mainb>0){
//            mainb--; rightb++;
//        }
    }
    int save_state_1,save_state_2,save_state_3;

    if(mainbsize==bucketsize1) save_state_1=mainb;
    if(mainbsize==bucketsize2) save_state_2=mainb;
    if(mainbsize==bucketsize3) save_state_3=mainb;

    if(leftbsize==bucketsize1) save_state_1=leftb;
    if(leftbsize==bucketsize2) save_state_2=leftb;
    if(leftbsize==bucketsize3) save_state_3=leftb;

    if(rightbsize==bucketsize1) save_state_1=rightb;
    if(rightbsize==bucketsize2) save_state_2=rightb;
    if(rightbsize==bucketsize3) save_state_3=rightb;

    states(save_state_1,save_state_2,save_state_3);
//    cout<<save_state_1<<save_state_2<<save_state_3<<endl;
}

void save_all_pour(int state1,int state2,int state3)
{
//    cout<<"now: "<<state1<<state2<<state3<<endl;
//    cout<<"1: ";
    pour(state1,bucketsize1,state2,bucketsize2,state3,bucketsize3);
//    cout<<"2: ";
    pour(state1,bucketsize1,state3,bucketsize3,state2,bucketsize2);
//    cout<<"3: ";
    pour(state2,bucketsize2,state1,bucketsize1,state3,bucketsize3);
//    cout<<"4: ";
    pour(state2,bucketsize2,state3,bucketsize3,state1,bucketsize1);
//    cout<<"5: ";
    pour(state3,bucketsize3,state1,bucketsize1,state2,bucketsize2);
//    cout<<"6: ";
    pour(state3,bucketsize3,state2,bucketsize2,state1,bucketsize1);
//    cout<<endl;
}

int findpath(int state1,int state2,int state3)
{
    states(state1,state2,state3);
//    save_all_pour(state1,state2,state3);
    while(stateqf<stateqp){
        if(stateq[stateqf]==findnum||stateq[stateqf+1]==findnum||stateq[stateqf+2]==findnum){
//            cout<<"find!!!!!"<<endl;
            return 1;
        }
        save_all_pour(stateq[stateqf],stateq[stateqf+1],stateq[stateqf+2]);
//        cout<<"**point: "<<stateqp<<" front: "<<stateqf<<endl;
        stateqf+=3;
    }
    return 0;
}

void printpath()
{
//    cout<<stateq[stateqf]<<" "<<stateq[stateqf+1]<<" "<<stateq[stateqf+2]<<endl;
//    cout<<"stateqf "<<stateqf<<endl;
    while(stateqf>0){
        cout<<stateq[stateqf]<<" "<<stateq[stateqf+1]<<" "<<stateq[stateqf+2]<<endl;
        stateqf/=18;stateqf*=3;
    }
    cout<<stateq[stateqf]<<" "<<stateq[stateqf+1]<<" "<<stateq[stateqf+2]<<endl;
}



int main()
{
    int state1=6,state2=0,state3=0;
    if(findpath(state1,state2,state3)){
        printpath();
    }
    else{
        cout<<"find not"<<endl;
    }
//    cout<<"all*********************************************"<<endl;
//    for(int i=3,k=0;i<=stateqf;i+=3){
////        cout<<stateqf<<endl;
//        k++;
//        cout<<i<<" : "<<stateq[i]<<" "<<stateq[i+1]<<" "<<stateq[i+2]<<endl;
//        if(k>5){k=0;cout<<endl;cout<<stateq[(i+3)/6]<<stateq[1+(i+3)/6]<<stateq[2+(i+3)/6]<<endl;}
//    }
//    cout<<195/18*3<<endl;
    return 0;
}
