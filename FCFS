#include<stdio.h>

int main(){

int n;

printf("Enter the no of processes:");
scanf("%d",&n);

int BT[n],WT[n],TAT[n];

int Tot_Wt=0,Tot_Tat=0;

for(int i=0;i<n;i++)
{
 printf("Enter the burst time for process %d:",i+1);
 scanf("%d",&BT[i]);
}
WT[0];
 for(int i=0;i<n;i++)
{
 WT[i]=BT[i-1]+WT[i-1];
}
 for(int i=0;i<n;i++)
{
 TAT[i]=BT[i]+WT[i];
}
 for(int i=0;i<n;i++)
{
 Tot_Wt+=WT[i];
 Tot_Tat+=TAT[i];
}
printf("\nGant chart:\n");
printf(" ");
for(int i=0;i<n;i++)
{
printf("| p%d\t",i+1);
}
printf("|\n");
printf("0\t");
int time=0;
for(int i=0;i<n;i++)
{
 time+=BT[i];
 printf("%d\t",time);
}    
 printf("\n\n");

printf("Process\tBurst Time\tWaiting Time\tTurn Around Time\n");  
for(int i=0;i<n;i++)
{
 printf("%d\t%d\t\t%d\t\t%d\n",i+1,BT[i],WT[i],TAT[i]);                                              
}
printf("\nAverage Waiting time:%0.2f",(float)Tot_Wt/n);
printf("\nAverage Turn around time:%0.2f\n",(float)Tot_Tat/n);
return 0;
}
