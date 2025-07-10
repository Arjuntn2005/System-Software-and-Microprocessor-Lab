#include <stdio.h>
 struct Process 
 {
   int pid, bt, priority, wt, tat;
 };

void sortByPriority(struct Process p[], int n)
 {
  
for (int i = 0; i < n - 1; i++) {
for (int j = i + 1; j < n; j++) {
if (p[i].priority > p[j].priority) {
struct Process temp = p[i];
p[i] = p[j];
p[j] = temp;
     }
    }   
   }
  }

void calculateTimes(struct Process p[], int n) 
{
 p[0].wt = 0;
 for (int i = 1; i < n; i++)
 p[i].wt = p[i - 1].wt + p[i - 1].bt;

 for (int i = 0; i < n; i++)
 p[i].tat = p[i].wt + p[i].bt;
}

 void display(struct Process p[], int n)
  {
 float total_wt = 0, total_tat = 0;

 printf("\nProcess\tBT\tPriority\tWT\tTAT\n");
 for (int i = 0; i < n; i++) 
{
 printf("P%d\t%d\t%d\t\t%d\t%d\n", p[i].pid, p[i].bt, p[i].priority, p[i].wt, p[i].tat);
 total_wt += p[i].wt;
 total_tat += p[i].tat;
}

printf("\nAverage WT: %.2f", total_wt / n);
printf("\nAverage TAT: %.2f\n", total_tat / n);


printf("\nGantt Chart:\n|");
for (int i = 0; i < n; i++)
printf(" P%d |\t", p[i].pid);
printf("\n0\t");
int time = 0;
for (int i = 0; i < n; i++) {
time += p[i].bt;
printf(" %d\t", time);
}
printf("\n");
}

int main() {
int n;
printf("Enter number of processes: ");
scanf("%d", &n);

struct Process p[n];

for (int i = 0; i < n; i++) 
{
 p[i].pid = i + 1;
 printf("Enter BT & Priority for P%d: ", p[i].pid);
 scanf("%d %d", &p[i].bt, &p[i].priority);
}

sortByPriority(p, n);
calculateTimes(p, n);
display(p, n);


return 0;
}
