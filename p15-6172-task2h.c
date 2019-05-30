#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <curses.h>
void solution(int steps, int random){
    int count;
    double x, y, z;
    FILE *gplot;

	for (int i = 1; i <= steps; i++) {
        count = 0;
		gplot = popen("gnuplot -persistent", "w");
		fprintf(gplot, "splot '-' u 1:2:3 title 'm' with lines\n");
        fprintf(gplot, "set output \"task-2h-d-%d.jpg\"\n", i);
		fprintf(gplot, "plot '-' title \"sqrt(cos(x*y) + 1)\" with points pt 7\n");

		random = pow(10, i);

		for (int j = 0; j < random; j++) {
			x = (double)rand() / RAND_MAX*(2.0);
	     	y = (double)rand() / RAND_MAX*(2.0);
            z = (double)rand() / RAND_MAX*(1.2);
			double xOriginal = x;
			double yOriginal = y;
			x *= x;
			y *= y;
			if ((sqrt( cos( x * y ) + 1)) >= z) {
				fprintf(gplot, "%lf %lf %lf\n", xOriginal, yOriginal, z);
				count++;
			}
		}
		fprintf(gplot, "e");
		fclose(gplot);
        printf("Answer is : %f\n", i, (((double)count / (double)random) * 2 * 2 * 1.2));
		
	}
}
int main() {
    int steps = 6, random = 10;
    solution(steps, random);
    return 0;
}