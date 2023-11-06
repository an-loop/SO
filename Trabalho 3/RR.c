#include <stdio.h>
#include <time.h>

#define QUANTUM 2

void gera_processos(int proc[], int burst_time[],int arrival_time[], int n) {
   // Inicializa o gerador de números aleatórios com o tempo atual
   srand(time(NULL));
   int times[] = {5, 8, 12};
   for (int i = 0; i < n; i++) {
      proc[i] = i + 1;
      burst_time[i] = times[rand() % 3];  // Burst time 5,8 ou 12
      arrival_time[i] = i*3; // Gera arrival time com multiplos de 3
   }
}
// Function to find the waiting time for all processes
int waitingtime(int proc[], int n,
int burst_time[], int wait_time[], int arrival_time[]) {
   // Faça uma cópia do tempo de rajada para modificar
   int remaining_time[n];
   for (int i = 0; i < n; i++)
      remaining_time[i] = burst_time[i];
   int current_time = 0, done;  
   do{
      done = 1; // Suponha que todos os processos sejam concluídos
      // Atravesse todos os processos
      for (int i = 0; i < n; i++) {
         // Se o processo ainda não estiver concluído
         if (remaining_time[i] > 0) {
            done = 0; // Marcar como não concluído
            // Se o tempo restante for menor ou igual ao quantum
		if(arrival_time[i] <= current_time){// testa se o processo já está pronto para a execução
	            if (remaining_time[i] <= QUANTUM) {
	               current_time += remaining_time[i]; // Adicionar o tempo restante ao horário atual
	               wait_time[i] = current_time - burst_time[i]-arrival_time[i] ; // Calcular tempo de espera
	               remaining_time[i] = 0; // Marcar processo como concluído
	            } else {
	               current_time += QUANTUM; // Adicionar quantum ao tempo atual
	               remaining_time[i] -= QUANTUM; // Subtraia o quantum do tempo restante
	            }
		}
         }
      }
      }while(done == 0);
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
   int i;
   //Function to find waiting time of all processes
   waitingtime(proc, n, burst_time, wait_time, arrival_time);
   //Function to find turn around time for all processes
   turnaroundtime(proc, n, burst_time, wait_time, tat);
   //Display processes along with all details
   printf("Processes  Burst Arrival  Waiting Turn around \n");
   // Calculate total waiting time and total turn
   // around time
   for ( i=0; i<n; i++) {
      total_wt = total_wt + wait_time[i];
      total_tat = total_tat + tat[i];
      printf(" %d\t  %d\t\t %d\t %d \t%d\n", i+1, burst_time[i], arrival_time[i], wait_time[i], tat[i]);
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
   gera_processos(proc, burst_time,arrival_time, n);
   avgtime(proc, n, burst_time, arrival_time);
   return 0;
}
