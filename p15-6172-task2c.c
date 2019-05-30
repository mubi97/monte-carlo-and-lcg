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
		fprintf(gplot, "set output \"task-2c-d-%d.jpg\"\n", i);
		fprintf(gplot, "plot '-' title \"exp(x)\" with points pt 7\n");

        n = pow(10, i);
        for(int j = 0; j < n; j++){
            x = 1 * (rand() /(double) RAND_MAX );
            y = 4 * (rand() /(double) RAND_MAX );
            double xOriginal = x;
            x *= x;
            if( y <= exp(x) ){
                count++;
                fprintf(gplot, "%f %f\n", xOriginal, y);
            }
        }
        fprintf(gplot, "e");
		fclose(gplot);

		printf("Area Estimation : %f\n", (4.* (double)count/(double) n ));

    }
}
int main() {
    int steps = 6;
    solution(steps);
    return 0;
}