#include <stdio.h>

struct process {
    char pid[10];
    int at, bt, rt;
    int ct, wt, tat;
};

int main() {
    int n;
    scanf("%d", &n);

    struct process p[20];

    for(int i = 0; i < n; i++) {
        scanf("%s %d %d", p[i].pid, &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
    }

    int completed = 0, time = 0, min_index;
    int min_rt;

    while(completed < n) {

        min_rt = 9999;
        min_index = -1;

        for(int i = 0; i < n; i++) {
            if(p[i].at <= time && p[i].rt > 0 && p[i].rt < min_rt) {
                min_rt = p[i].rt;
                min_index = i;
            }
        }

        if(min_index == -1) {
            time++;
            continue;
        }

        p[min_index].rt--;
        time++;

        if(p[min_index].rt == 0) {
            completed++;

            p[min_index].ct = time;
            p[min_index].tat = p[min_index].ct - p[min_index].at;
            p[min_index].wt = p[min_index].tat - p[min_index].bt;
        }
    }

    float avg_wt = 0, avg_tat = 0;

    printf("Waiting Time:\n");
    for(int i = 0; i < n; i++) {
        printf("%s %d\n", p[i].pid, p[i].wt);
        avg_wt += p[i].wt;
    }

    printf("Turnaround Time:\n");
    for(int i = 0; i < n; i++) {
        printf("%s %d\n", p[i].pid, p[i].tat);
        avg_tat += p[i].tat;
    }

    printf("Average Waiting Time: %.1f\n", avg_wt/n);
    printf("Average Turnaround Time: %.1f\n", avg_tat/n);

    return 0;
}
