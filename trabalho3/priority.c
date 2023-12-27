#include <stdio.h>
#include <time.h>
// Function to find the waiting time for all processes
void gera_processos(int proc[], int burst_time[], int arrival_time[], int priority[], int n) {
    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(NULL));
   int times[] = {5, 8, 12};
    for (int i = 0; i < n; i++) {
        proc[i] = i + 1;
        burst_time[i] = times[rand() % 3];  // Burst time 5,8 ou 12
        arrival_time[i] = i*3;   //Gera o arrival time de cada processo como multiplo de 3
        priority[i] = rand() % 5 + 1;   // Prioridade entre 1 e 5
    }
}
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
int avgtime( int proc[], int n, int burst_time[],int priority[], int arrival_time[]) {
   int wait_time[n], tat[n], total_wt = 0, total_tat = 0;
   int i, j, idMax, current_time = 0;
   int maior_p = 0;
   //ordenação dos processos
   for (i = 0; i < n; i++) {
    idMax = -1;
    maior_p = 0;
    for (j = i; j < n; j++) {
        if (arrival_time[j] <= current_time && priority[j] > maior_p  ){
            idMax = j;
            maior_p = priority[j];
        }
    }

    // Depois de identificar o processo com a maior prioridade e que já chegou, realizamos a troca
      if (idMax == -1)
         {current_time++;
         i--;}
      else{if (idMax != i) {
            int temp;

            // Trocar os IDs dos processos
            temp = proc[i];
            proc[i] = proc[idMax];
            proc[idMax] = temp;

            // Trocar as prioridades
            temp = priority[i];
            priority[i] = priority[idMax];
            priority[idMax] = temp;

            // Trocar os burst times
            temp = burst_time[i];
            burst_time[i] = burst_time[idMax];
            burst_time[idMax] = temp;

            // Trocar os tempos de chegada
            temp = arrival_time[i];
            arrival_time[i] = arrival_time[idMax];
            arrival_time[idMax] = temp;
         }
   current_time += burst_time[i];
   }
    // Atualizar o current_time após escalonar um processob 
}

   waitingtime(proc, n, burst_time, wait_time, arrival_time);
   //Function to find turn around time for all processes
   turnaroundtime(proc, n, burst_time, wait_time, tat);
   //Display processes along with all details
   printf("Processes  Priority Burst   Waiting Arrival Turn around \n");
   // Calculate total waiting time and total turn
   // around time
   for ( i=0; i<n; i++) {
      total_wt = total_wt + wait_time[i];
      total_tat = total_tat + tat[i];
      printf(" %d\t   %d\t    %d\t    %d    \t%d    \t%d\n", proc[i], priority[i], burst_time[i], wait_time[i], arrival_time[i], tat[i]);
   }
   printf("Average waiting time = %f\n", (float)total_wt / (float)n);
   printf("Average turn around time = %f\n", (float)total_tat / (float)n);
   return 0;
}
// main function
int main() {
   //process id's
   int proc[30];
   int n = sizeof(proc) / sizeof(proc[0]);
   int burst_time[30];
   int arrival_time[30];
   int priority[30];
   gera_processos(proc, burst_time, arrival_time, priority, n);
   //Burst time of all processes
   avgtime(proc, n, burst_time, priority, arrival_time);
   return 0;
}
