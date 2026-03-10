#include <stdio.h>
#include <limits.h>

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
    
    int completed = 0;
    int current_time = 0;
    int total_wt = 0, total_tat = 0;
    int min_rt_index;
    int shortest = -1;
    
    // Array to track if process is completed
    int is_completed[20] = {0};
    
    while(completed < n) {
        // Find process with minimum remaining time among arrived processes
        shortest = -1;
        int min_rt = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            if(p[i].at <= current_time && !is_completed[i]) {
                if(p[i].rt < min_rt) {
                    min_rt = p[i].rt;
                    shortest = i;
                }
                // If remaining time is same, choose the one that arrived earlier
                else if(p[i].rt == min_rt && p[i].at < p[shortest].at) {
                    shortest = i;
                }
            }
        }
        
        if(shortest == -1) {
            // If no process has arrived yet, increment time
            current_time++;
            continue;
        }
        
        // Execute the selected process for 1 time unit
        p[shortest].rt--;
        current_time++;
        
        // If process is completed
        if(p[shortest].rt == 0) {
            completed++;
            is_completed[shortest] = 1;
            
            // Calculate completion time
            p[shortest].ct = current_time;
            
            // Calculate turnaround time
            p[shortest].tat = p[shortest].ct - p[shortest].at;
            
            // Calculate waiting time
            p[shortest].wt = p[shortest].tat - p[shortest].bt;
            
            // Add to totals
            total_wt += p[shortest].wt;
            total_tat += p[shortest].tat;
        }
    }
    
    // Print Waiting Time
    printf("Waiting Time:\n");
    for(int i = 0; i < n; i++) {
        printf("%s %d\n", p[i].pid, p[i].wt);
    }
    
    // Print Turnaround Time
    printf("Turnaround Time:\n");
    for(int i = 0; i < n; i++) {
        printf("%s %d\n", p[i].pid, p[i].tat);
    }
    
    // Print Averages
    printf("Average Waiting Time: %.1f\n", (float)total_wt/n);
    printf("Average Turnaround Time: %.1f\n", (float)total_tat/n);
    
    return 0;
}
