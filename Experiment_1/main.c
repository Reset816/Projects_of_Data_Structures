#include <stdio.h>

void arry(int m, int n) {
    int a[1000];
    int i;
    for (i = 0; i < m; i++)
        a[i] = 1;
    int out[1000];
    int total = 0;
    i = 0;
    int tmp = 0;
    while (total < m) {
        if (i == m) {
            i = 0;
        }
        if (a[i] == 1) {
            tmp++;
            if (tmp == n) {
                a[i] = 0;
                out[total] = i + 1;
                total++;
                tmp = 0;
            }
        }
        i++;
    }
    for (i = 0; i < m; i++)
        printf("%d", out[i]);
}


int main() {
    int m, n;//m：总人数 n：出列序号

    scanf("%d %d", &m, &n);

    arry(m, n);

    return 0;
}