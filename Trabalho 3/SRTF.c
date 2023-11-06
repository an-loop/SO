#include <stdio.h>
#include <time.h>

void gera_processos(int proc[], int burst_time[], int arrival_time[], int n) {
    //inicia o gerador de numeros psedoaleatorios
    srand(time(NULL));
    int times[] = {5, 8, 12};
    for (int i = 0; i < n; i++) {
        proc[i] = i + 1;
        burst_time[i] = times[rand() % 3];  // Burst time 5,8 ou 12
        arrival_time[i] = i*3;   //gera o arrival time de cada processo com multiplos de 3
    }
}
// Function to find the process with the shortest remaining time
int findMenorProc(int arrival_time[], int n, int remaining_time[], int current_time) {
    int min_time = __INT_MAX__;
    int menorProc = -1;

    for (int i = 0; i < n; i++) {
        if (remaining_time[i] > 0 && remaining_time[i] < min_time && arrival_time[i] <= current_time) {
            min_time = remaining_time[i];
            menorProc = i;
        }
    }

    return menorProc;
}

// Função do escalonador
int SRTF(int proc[], int n, int burst_time[], int arrival_time[]) {
    int wait_time[n], turnaround_time[n], remaining_time[n];
    int total_wait_time = 0, total_turnaround_time = 0;
    int current_time = 0;
    int completed = 0;

    // Inicia remainning_time array
    for (int i = 0; i < n; i++) {
        remaining_time[i] = burst_time[i];
    }
   int menorProc;
    while (completed < n) {
        menorProc = findMenorProc(arrival_time, n, remaining_time, current_time);
        if (menorProc == -1) {
            current_time++;
        } else {
            remaining_time[menorProc]--;

            if (remaining_time[menorProc] == 0) {
                completed++;
                int finish_time = current_time + 1;
                turnaround_time[menorProc] = finish_time - arrival_time[menorProc];
                wait_time[menorProc] = turnaround_time[menorProc] - burst_time[menorProc];
                total_wait_time += wait_time[menorProc];
                total_turnaround_time += turnaround_time[menorProc];
            }

            current_time++;
        }
    }

    printf("Processes  Burst   Arrival   Waiting   Turnaround\n");
    for (int i = 0; i < n; i++) {
        printf("   %d\t    %d\t\t%d\t  %d\t\t%d\n", proc[i], burst_time[i], arrival_time[i], wait_time[i], turnaround_time[i]);
    }

    printf("Average waiting time = %.2f\n", (float)total_wait_time / n);
    printf("Average turnaround time = %.2f\n", (float)total_turnaround_time / n);

    return 0;
}

int main() {
    int proc[30]; //array para os ids dos processos
    int n = sizeof(proc) / sizeof(proc[0]);
    int burst_time[30]; // array para o brust dos 30 processos
    int arrival_time[30]; // array para o arrival de cada processo
    gera_processos(proc, burst_time, arrival_time, n);
    SRTF(proc, n, burst_time, arrival_time);
    return 0;
}
