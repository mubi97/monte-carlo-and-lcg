#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <curses.h>
void solution(int steps){
    int n, count = 0;
    double x, y;
    FILE *gplot;

    for(int i = 1; i < steps; i++){
        count = 0;
        gplot = popen("gnuplot -persistent", "w");
		fprintf(gplot, "set term jpeg\n");
		fprintf(gplot, "set output \"task-2a-d-%d.jpg\"\n", i);
		fprintf(gplot, "plot '-' title \"sqrt(cos^2(x)+1)\" with points pt 7\n");

        n = pow(10, i);
        for(int j = 0; j < n; j++){
            x = 2 * (rand() /(double) RAND_MAX );
            y = 2 * (rand() /(double) RAND_MAX );

            if( y <= sqrt(pow(cos(x), 2) + 1) ){
                count++;
                fprintf(gplot, "%f %f\n", x, y);
            }
        }
        fprintf(gplot, "e");
		fclose(gplot);

		printf("N = %d\t", n);
		printf("%f\t", (double) count/n);
		printf("%f\n", (4.* (double)count/(double) n ));

    }
}
int main() {
    int steps = 6;
    solution(steps);
    return 0;
}