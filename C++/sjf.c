#include <stdio.h>
#include <stdbool.h>

struct Process {
  int id;
  int arrival_time;
  int burst_time;
  int completion_time;
  int turn_around_time;
  int waiting_time;
  bool is_completed;
};

int main(void){
  int n;
  float total_tat = 0,total_wt = 0;

  printf("Enter the number of processes:");
  scanf("%d",&n);

  struct Process p[n];

  for(int i = 0;i<n;i++){
    p[i].id = i+1;
    printf("Enter the arrival time and burst_time:");
    scanf("%d %d",&p[i].arrival_time,&p[i].burst_time);
    p[i].is_completed = false;
  }

  int current_time=0,completed = 0;
  while ( completed < n) {
    int idx = -1;
    int min_burst = 10000;

    for(int i=0;i<n;i++){
      if (p[i].arrival_time <= current_time && !p[i].is_completed){
        if (p[i].burst_time < min_burst){
          min_burst = p[i].burst_time;
          idx = i;
        }
        else if (p[i].burst_time == min_burst){
          if (idx != -1 && p[i].arrival_time < p[idx].arrival_time){
            idx = i;
          }
        }
      }
    }
    if (idx==-1){
      current_time++;
    }
    else{
      p[idx].completion_time = current_time + p[idx].burst_time;
      p[idx].turn_around_time = p[idx].completion_time - p[idx].arrival_time;
      p[idx].waiting_time = p[idx].turn_around_time - p[idx].burst_time;

      total_tat += p[idx].turn_around_time;
      total_wt += p[idx].waiting_time;

      current_time = p[idx].completion_time;
      p[idx].is_completed = true;
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
