// FCFS Algo manually written
#include <stdio.h>

struct Process {
  int id;
  int arrival_time;
  int burst_time;
  int completion_time;
  int turn_around_time;
  int waiting_time;
};

void sort_by_arrival(struct Process p[], int n) {
  struct Process temp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (p[j].arrival_time > p[j + 1].arrival_time) {
        temp = p[j];
        p[j] = p[j + 1];
        p[j+1] = temp;
      }
    }
  }
}

int main(void) {
  int n;
  float total_tat = 0, total_wt = 0;
  printf("Enter number of process:");
  scanf("%d", &n);
  struct Process p[n];
  for (int i = 0; i < n; i++) {
    p[i].id = i + 1;
    printf("Enter arrival time and burst time:");
    scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
  }

  sort_by_arrival(p, n);

  int current_time = 0;
  for (int i = 0; i < n; i++) {
    if (current_time < p[i].arrival_time)
      current_time = p[i].arrival_time;
    p[i].completion_time = current_time + p[i].burst_time;
    p[i].turn_around_time = p[i].completion_time - p[i].arrival_time;
    p[i].waiting_time = p[i].turn_around_time - p[i].burst_time;

    current_time = p[i].completion_time;

    total_tat += p[i].turn_around_time;
    total_wt += p[i].waiting_time;
  }

  printf("\nId Arrival Burst Completion Turn-Around Waiting\n");

  for (int i = 0; i < n; i++) {
    printf("\n%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].arrival_time,
           p[i].burst_time, p[i].completion_time, p[i].turn_around_time,
           p[i].waiting_time);
  }

  printf("\nAverage Turn Around Time:%.2f\n", total_tat / n);

  printf("\nAverage Waiting Time:%.2f\n", total_wt / n);

  return 0;
}
