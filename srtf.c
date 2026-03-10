#include <stdio.h>
#include <ctype.h>

struct process {
    char pid[10];
    int at, bt, rt;
    int ct, wt, tat;
};

int main() {

    struct process p[20];
    int n = 0;

    char first[10];

    scanf("%s", first);

    if(isdigit(first[0])) {
        n = first[0] - '0';

        for(int i = 0; i < n; i++) {
            scanf("%s %d %d", p[i].pid, &p[i].at, &p[i].bt);
            p[i].rt = p[i].bt;
        }
    } 
    else {
        sscanf(first, "%s", p[0].pid);
        scanf("%d %d", &p[0].at, &p[0].bt);
        p[0].rt = p[0].bt;
        n = 1;

        while(scanf("%s %d %d", p[n].pid, &p[n].at, &p[n].bt) == 3) {
            p[n].rt = p[n].bt;
            n++;
        }
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

            if(p[min_index].wt < 0)
                p[min_index].wt = 0;
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
