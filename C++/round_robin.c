#include <stdio.h>
#include <stdbool.h>

struct Process {
  int id;
  int arrival_time;
  int burst_time;
  int remaining_time;
  int completion_time;
  int turn_around_time;
  int waiting_time;
  bool in_queue;
};

int main(void){
  int n,time_quantum,current_time=0,completed =0;
  float total_tat = 0,total_wt = 0;

  printf("Enter the number of processes:");
  scanf("%d",&n);
  printf("Enter Time Quantum:");
  scanf("%d",&time_quantum);

  struct Process p[n];

  for(int i = 0;i<n;i++){
    p[i].id = i+1;
    printf("Enter the arrival time and burst_time:");
    scanf("%d %d",&p[i].arrival_time,&p[i].burst_time);
    p[i].remaining_time = p[i].burst_time;
    p[i].in_queue = false;
  }

  //FIFO
  int queue[100];
  int front=0,rear =0;

  int min_arrival=10000;
  for(int i=0;i<n;i++){
    if(p[i].arrival_time < min_arrival){
      min_arrival = p[i].arrival_time;
    }
  }

  current_time = min_arrival;

  for (int i=0;i<n;i++){
    if(p[i].arrival_time==current_time){
      queue[rear++]=i;
      p[i].in_queue=true;
    }
  }

  while (completed<n) {
    if(front==rear){
      current_time++;
      for(int i=0;i<n;i++){
        if (p[i].arrival_time == current_time && !p[i].in_queue){
          queue[rear++] = i;
          p[i].in_queue=true;
        }
      }
      continue;
    }

    int idx = queue[front++];

    int execute_time;
    if (p[idx].remaining_time > time_quantum ){
      execute_time = time_quantum;
    }
    else {
      execute_time = p[idx].remaining_time;
    }

    p[idx].remaining_time -= execute_time;
    current_time+= execute_time;

    for(int i=0;i<n;i++){
      if (p[i].arrival_time<=current_time && !p[i].in_queue && p[i].remaining_time > 0){
        queue[rear++] = i;
        p[i].in_queue = true;
      }
    }

    if (p[idx].remaining_time > 0){
      queue[rear++]=idx;
    }
    else {
      p[idx].completion_time = current_time;
      p[idx].turn_around_time = p[idx].completion_time - p[idx].arrival_time;
      p[idx].waiting_time = p[idx].turn_around_time - p[idx].burst_time;

      total_tat += p[idx].turn_around_time;
      total_wt += p[idx].waiting_time;

      completed++;
    }
  }

  printf("\nId Arrival Burst Completion Turn-Around Waiting\n");

  for(int i=0;i<n;i++){
    printf("\n%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].arrival_time,p[i].burst_time,p[i].completion_time,p[i].turn_around_time,p[i].waiting_time);
  }

  printf("\nAverage Turn Around Time:%.2f\n",total_tat/n);
  printf("\nAverage Waiting Time:%.2f\n",total_wt/n);

  return 0;
}
