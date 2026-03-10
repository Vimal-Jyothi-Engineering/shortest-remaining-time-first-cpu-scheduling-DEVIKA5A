#include <stdio.h>
#include <string.h>

struct process {
    char pid[10];
    int at, bt, rt;
    int ct, wt, tat;
    int done;
};

int main() {
    int n;
    scanf("%d", &n);

    struct process p[20];

    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", p[i].pid, &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
        p[i].done = 0;
    }

    int completed = 0;
    int time = 0;

    // Start time from the earliest arrival
    int min_at = p[0].at;
    for (int i = 1; i < n; i++)
        if (p[i].at < min_at) min_at = p[i].at;
    time = min_at;

    while (completed < n) {
        // Find process with smallest remaining time that has arrived
        int idx = -1;
        int min_rt = 99999;

        for (int i = 0; i < n; i++) {
            if (!p[i].done && p[i].at <= time && p[i].rt < min_rt) {
                min_rt = p[i].rt;
                idx = i;
            }
        }

        if (idx == -1) {
            // CPU idle — no process has arrived yet
            time++;
            continue;
        }

        // Execute for 1 time unit
        p[idx].rt--;
        time++;

        if (p[idx].rt == 0) {
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].done = 1;
            completed++;
        }
    }

    float avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++) {
        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
    }

    printf("Waiting Time:\n");
    for (int i = 0; i < n; i++)
        printf("%s %d\n", p[i].pid, p[i].wt);

    printf("Turnaround Time:\n");
    for (int i = 0; i < n; i++)
        printf("%s %d\n", p[i].pid, p[i].tat);

    printf("Average Waiting Time: %.1f\n", avg_wt / n);
    printf("Average Turnaround Time: %.1f\n", avg_tat / n);

    return 0;
}
