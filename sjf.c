#include <stdio.h>
int main() 
{
int n;

printf("Enter number of processes: ");
scanf("%d", &n);

int bt[n], wt[n], tat[n], p[n];
int total_wt = 0, total_tat = 0;

for (int i = 0; i < n; i++) 
{
p[i] = i + 1;
printf("Enter burst time for Process %d: ", p[i]);
scanf("%d", &bt[i]);
}
printf("Process\tBurst Time\n");
for (int i = 0; i < n; i++) 
{
printf("%d\t%d\n", p[i], bt[i]);
}
for (int i = 0; i < n - 1; i++) 
{
for (int j = i + 1; j < n; j++) 
{
if (bt[i] > bt[j]) 
{
int temp = bt[i];
bt[i] = bt[j];
bt[j] = temp;
temp = p[i];

p[i] = p[j];
p[j] = temp;
  }
 }
}
wt[0] = 0;
for (int i = 1; i < n; i++) 
{
wt[i] = wt[i - 1] + bt[i - 1];
}
for (int i = 0; i < n; i++) 
{
tat[i] = wt[i] + bt[i];
total_wt += wt[i];
total_tat += tat[i];
}
printf("\nGantt Chart:\n");
printf(" ");
for (int i = 0; i < n; i++) 
{
printf("| P%d\t ", p[i]);
}
printf("| \n");
printf("0\t");
int time = 0;
for (int i = 0; i < n; i++) 
{
time += bt[i];
printf("%d\t ", time);
}
printf("\n\n");
printf("Process\tBurst Time\tWaiting Time\tTurnAround Time\n");
for (int i = 0; i < n; i++) 
{
printf("%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
}
printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
printf("\nAverage Turnaround Time: %.2f", (float)total_tat / n);
return 0;
}
