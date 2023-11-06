#include <stdio.h>
#include <time.h>

void gera_processos(int proc[], int burst_time[], int arrival_time[], int n) {
    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(NULL));
   int times[] = {5, 8, 12};
    for (int i = 0; i < n; i++) {
        proc[i] = i + 1;
        burst_time[i] = times[rand() % 3];  // Burst time 5,8 ou 12
        arrival_time[i] = i*3;   //gera o arrrival time de cada processo como multiplo de 3
    }
}
// Function to find the waiting time for all processes
int waitingtime(int proc[], int n,
int burst_time[], int wait_time[], int arrival_time[]) {
   // waiting time for first process is 0
   wait_time[0] = 0;
   // calculating waiting time
   for (int i = 1; i < n ; i++ )
      wait_time[i] = burst_time[i-1] + wait_time[i-1];
   for (int i = 1; i < n ; i++ )
      wait_time[i] = wait_time[i] - arrival_time[i];
   return 0;
}
// Function to calculate turn around time
int turnaroundtime( int proc[], int n,
int burst_time[], int wait_time[], int tat[]) {
   // calculating turnaround time by adding
   // burst_time[i] + wait_time[i]
   int i;
   for ( i = 0; i < n ; i++)
   tat[i] = burst_time[i] + wait_time[i];
   return 0;
}
//Function to calculate average time
int avgtime( int proc[], int n, int burst_time[], int arrival_time[]) {
   int wait_time[n], tat[n], total_wt = 0, total_tat = 0;
   int i,j,minId, min_burst;
   int current_time = 0;
   //ordenando os processos de acordo com o burstTime
   for(i = 0; i < n; i++) {
      minId = -1;
      min_burst = __INT_MAX__;
      for(j = i; j < n; j++) {
         if(burst_time[j] < min_burst  && arrival_time[j] <= current_time){
            minId = j;
	    min_burst = burst_time[j];
 	 }
      }
   //troca os burstTime
   if(minId == -1){
	current_time++;
	i--;
   }else{if(i != minId){
     	 int temp = burst_time[i];
     	 burst_time[i] = burst_time[minId];
     	 burst_time[minId] = temp;
     	 // troca os proc
     	 temp = proc[i];
     	 proc[i] = proc[minId];
     	 proc[minId] = temp;
     	 // arrivaltime
     	 temp = arrival_time[i];
     	 arrival_time[i] = arrival_time[minId];
     	 arrival_time[minId] = temp;
        }
      current_time += burst_time[i];
   }
}
   //Function to find waiting time of all processes
   waitingtime(proc, n, burst_time, wait_time, arrival_time);
   //Function to find turn around time for all processes
   turnaroundtime(proc, n, burst_time, wait_time, tat);
   //Display processes along with all details
   printf("Processes  Burst  Arrival   Waiting Turn around \n");
   // Calculate total waiting time and total turn
   // around time
   for ( i=0; i<n; i++) {
      total_wt = total_wt + wait_time[i];
      total_tat = total_tat + tat[i];
      printf(" %d\t  %d\t\t %d\t%d \t%d\n", proc[i], burst_time[i],arrival_time[i] ,wait_time[i], tat[i]);
   }
   printf("Average waiting time = %f\n", (float)total_wt / (float)n);
   printf("Average turn around time = %f\n", (float)total_tat / (float)n);
   return 0;
}
// main function
int main() {
   int proc[30];
   int n = sizeof(proc) / sizeof(proc[0]);
   int burst_time[30];
   int arrival_time[30];
   gera_processos(proc, burst_time, arrival_time, n);
   avgtime(proc, n, burst_time, arrival_time);
   return 0;
}
