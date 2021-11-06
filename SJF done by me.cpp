#include<iostream>
#include <algorithm>
using namespace std;
struct process
{
  int pid;
  int at;
  int bt;
  int ct,wt,tat,rt,start_time;
}ps[10];

bool comparingBT(struct process a,struct process b)
{
   int x =a.bt;
   int y =b.bt;
   return x < y;

}

bool comparingPID(struct process a,struct process b)
{
   int x =a.pid;
   int y =b.pid;
   return x < y;
}
int main()
{
    int n;
    cout<<"Enter total number of processes: ";
    cin>>n;
    float sumoftat=0,sumofwt=0,sumofrt=0;
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter Process " <<i<< " Arrival Time: ";
        cin >> ps[i].at;
        ps[i].pid=i;
    }
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter Process " <<i<< " Burst Time: ";
        cin >> ps[i].bt;
    }
    sort(ps,ps+n, comparingBT);
    for(int i=0;i<n;i++)
    {
      ps[i].start_time = (i==0) ? ps[i].at : max(ps[i].at, ps[i-1].ct);
      ps[i].ct =  ps[i].start_time + ps[i].bt;
      ps[i].tat = ps[i].ct-ps[i].at;
      ps[i].wt = ps[i].tat-ps[i].bt;
      ps[i].rt=ps[i].wt;

      sumoftat += ps[i].tat;
      sumofwt += ps[i].wt;
      sumofrt += ps[i].rt;
    }
    sort(ps,ps+n, comparingPID);
    cout<<"\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n";
    for(int i=0;i<n;i++)
     cout<<i<<"\t"<<ps[i].at<<"\t"<<ps[i].bt<<"\t"<<ps[i].ct<<"\t"<<ps[i].tat<<"\t"<<ps[i].wt<<"\t"<<ps[i].rt<<endl;
    cout<<endl;
    cout<<"\nAverage Turn Around time= "<< sumoftat/n;
    cout<<"\nAverage Waiting Time= "<<sumofwt/n;
    cout<<"\nAverage Response Time= "<<sumofrt/n;

    return 0;
}
