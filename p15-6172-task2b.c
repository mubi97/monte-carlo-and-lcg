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
		fprintf(gplot, "set output \"task-2b-d-%d.jpg\"\n", i);
		fprintf(gplot, "plot '-' title \"x^2\" with points pt 7\n");

        n = pow(10, i);
        for(int j = 0; j < n; j++){
            x = 2 + (rand() /(double) RAND_MAX ) * (3.0 - 2.0);
            y = 9 * (rand() /(double) RAND_MAX );
            double xOriginal = x;
            double yOriginal = y;
            x *= x;
            if( y <= x ){
                count++;
                fprintf(gplot, "%f %f\n", xOriginal, yOriginal);
            }
        }
        fprintf(gplot, "e");
		fclose(gplot);

		printf("Answer : %f\n", (9.* (double)count/(double) n ));

    }
}
int main() {
    int steps = 6;
    solution(steps);
    return 0;
}