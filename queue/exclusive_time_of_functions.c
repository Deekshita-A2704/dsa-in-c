/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* exclusiveTime(int n, char** logs, int logsSize, int* returnSize) {
    int* ans = (int*)calloc(n,sizeof(int));
    int stack[1000], top = -1;
    int prevTime = 0;
    for (int i = 0; i<logsSize; i++) {
        int id,time;
        char type[10];

        sscanf(logs[i],"%d:%[^:]:%d",&id,type,&time);

        if(strcmp(type,"start") == 0) {
            if(top != -1)
                ans[stack[top]] += time - prevTime;

            stack[++top] = id;
            prevTime = time;
        }

        else {
            ans[stack[top--]] += time - prevTime + 1;
            prevTime = time + 1;

        }
    }

    *returnSize = n;
    return ans;
}
