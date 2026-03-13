#include <stdio.h>
#include <string.h>

struct process{
    char pid[10];
    int at, bt, pr;
    int rt;
    int ct, wt, tat;
};
int main(){
    int n;
    scanf("%d",&n);
    struct process p[100];
    int i;
    float avg_wt=0,avg_tat=0;
    for(i=0;i<n;i++){
        scanf("%s %d %d %d",p[i].pid,&p[i].at,&p[i].bt,&p[i].pr);
        p[i].rt=p[i].bt;
    }
    int completed=0,time=0,current=-1;
    while(completed<n){
        int idx=-1;
        for(i=0;i<n;i++){
            if(p[i].at<=time && p[i].rt>0){
                if(idx==-1){
                    idx=i;
                }
                else if(p[i].pr>p[idx].pr){
                    idx=i;
                }
                else if(p[i].pr==p[idx].pr){
                    if(p[i].at<p[idx].at)
                        idx=i;
                    else if(p[i].at==p[idx].at && i<idx)
                      idx=i;
                }
            }
        }
        if(idx==-1){
            time++;
            current=-1;
            continue;
        }
        p[idx].rt--;
        time++;
        current=idx;
        if(p[idx].rt==0){
            p[idx].ct=time;
            completed++;
            current=-1;
        }
    }
    for(i=0;i<n;i++){
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        avg_wt+=p[i].wt;
        avg_tat+=p[i].tat;
    }
    printf("Waiting Time:\n");
    for(i=0;i<n;i++)
        printf("%s %d\n",p[i].pid,p[i].wt);
    printf("Turnaround Time:\n");
    for(i=0;i<n;i++)
        printf("%s %d\n",p[i].pid,p[i].tat);
    printf("Average Waiting Time: %.2f\n",avg_wt/n);
    printf("Average Turnaround Time: %.2f\n",avg_tat/n);
    return 0;
}