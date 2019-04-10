#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void findwt(int P[],int n,int Bt[],int wt[])
{
	wt[0]=0;
	int i;
	for(i = 1;i<n;i++)
	{
		wt[i]=Bt[i-1]+wt[i-1];
	}
}
void findtat(int P[],int n, int Bt[],int wt[],int tat[])
{
	int i;
	for(i=0;i<n;i++)
	{
		tat[i]=Bt[i]+wt[i];
	}
}
void fcfs(int P[],int n,int Bt[])
{
	int wt[n], total_wt=0; int tat[n], total_tat=0;
	findwt(P,n,Bt,wt);
	findtat(P,n,Bt,wt,tat);
	int i;
	printf("\n");
	printf("\t\t---FCFS---\t\t");
	printf("\n\nProcess Burst Time  Waiting time  \tTurnArroundTime\n");
	for(i=0;i<n;i++)
	{
		total_wt=total_wt+wt[i];
		total_tat=total_tat+tat[i];
		printf("P%d",i+1);
		printf("        %d",Bt[i]);
		printf("            %d",wt[i]);
		printf("                  %d",tat[i]);
		printf("\n");
	}
	int a=(float)total_wt/(float)n;
	int b=(float)total_tat/(float)n;
	printf("Average Waiting time is : %d ",a);
    printf("\nAverage Turn Around Time is : %d ",b);
}
void sjf(int P[],int Bt[], int n)
{
	int wt[n],tat[n],i,j,temp,total=0,k;
	float awt,atat;
    for(i=0;i<n;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(Bt[j]<Bt[k])
                k=j;
        }
        temp=Bt[i];
        Bt[i]=Bt[k];
        Bt[k]=temp;
        temp=P[i];
        P[i]=P[k];
        P[k]=temp;
    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=Bt[j];
        total+=wt[i];
    }
    awt=(float)total/n;
    total=0;
    printf("\n");
    printf("\t\t---SJF---\t\t");
    printf("\n\nProcess\t  Burst Time  \tWaiting Time  \tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=Bt[i]+wt[i];
        total+=tat[i];
        printf("\nP%d\t\t  %d\t\t   %d\t\t\t%d",P[i],Bt[i],wt[i],tat[i]);
    }
    atat=(float)total/n;
    printf("\n\nAverage Waiting Time=%f",awt);
    printf("\nAverage Turnaround Time=%f\n",atat);	
}
void sjf1(int P[],int bt[],int n)
{
	int wt[n],tat[n],i,j,temp,total=0,k;
	float awt,atat;
    for(i=0;i<n;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[k])
                k=j;
        }
        temp=bt[i];
        bt[i]=bt[k];
        bt[k]=temp;
 
        temp=P[i];
        P[i]=P[k];
        P[k]=temp;
    }
    wt[0]=1;
    for(i=1;i<n;i++)
    {
        wt[i]=1;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
        total+=wt[i];
    }
    awt=(float)total/n;
    total=0;
    printf("\n");
    printf("\t---Cpu is in Idle Condition  for 1 unit---\t\t");
    printf("\n\nProcess\t   Burst Time  \tWaiting Time  \tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        total+=tat[i];
        printf("\nP%d\t\t  %d\t\t    %d\t\t\t%d",P[i],bt[i],wt[i],tat[i]);
    }
    atat=(float)total/n;
    printf("\n\nAverage Waiting Time=%f",awt);
    printf("\nAverage Turnaround Time=%f\n",atat);
}
int main()
{
   int P[10],Bt[10],n,i;
   printf("Enter the total number of Process : \n");
   scanf("%d",&n);
   printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("Process of burst time %d:",i+1);
        scanf("%d",&Bt[i]);
        P[i]=i+1;
    }
   fcfs(P,n,Bt);
   sjf(P,Bt,n);
   sjf1(P,Bt,n);
}
