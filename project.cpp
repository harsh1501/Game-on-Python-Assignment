#include<stdio.h> 
int main() 
{ 
  int count,j,n;
  int time,remaining;
  int flag=0,TimeQuantum=10; 
  int WaitingTime=0,TurnAroundTime=0,ArrivalTime[10],BurstTime[10],rt[10]; 
  printf("\n\nEnter the Total number of Process:  "); 
  scanf("%d",&n); 
  remaining=n; 
  for(count=0;count<n;count++) 
  { 
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1); 
    scanf("%d",&ArrivalTime[count]); 
    scanf("%d",&BurstTime[count]); 
    rt[count]=BurstTime[count]; 
  } 
  printf("Enter Time Quantum:%d\t",TimeQuantum); 

  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,count=0;remaining!=0;) 
  { 
    if(rt[count]<=TimeQuantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=TimeQuantum; 
      time+=TimeQuantum; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remaining--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-ArrivalTime[count],time-ArrivalTime[count]-BurstTime[count]); 
      WaitingTime+=time-ArrivalTime[count]-BurstTime[count]; 
      TurnAroundTime+=time-ArrivalTime[count]; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(ArrivalTime[count+1]<=time) 
      count++; 
    else 
    
      count=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",WaitingTime*1.0/n); 
  printf("Avg Turnaround Time = %f",TurnAroundTime*1.0/n); 

  return 0; 
}
