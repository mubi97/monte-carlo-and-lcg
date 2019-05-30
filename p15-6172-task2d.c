#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <curses.h>
void solution(int steps, int random){
    int count;
    double x, y;
    FILE *gplot;

	for (int i = 1; i <= steps; i++) {
        count = 0;
		gplot = popen("gnuplot -persistent", "w");
		fprintf(gplot, "set term jpeg\n");
		fprintf(gplot, "set output \"task-2d-d-%d.jpg\"\n", i);
		fprintf(gplot, "plot '-' title \"pi\" with points pt 7\n");

		random = pow(10, i);

		for (int j = 0; j < random; j++) {
			x = (double)rand() / RAND_MAX*(2.0 - 1.0);
	     	y = (double)rand() / RAND_MAX*(2.0 - 1.0);
			double xOriginal = x;
			double yOriginal = y;
			
			x *= x;
			y *= y;

			if (x + y <= 1) {
				fprintf(gplot, "%f %f\n", xOriginal, yOriginal);
				count++;
			}
		}
		fprintf(gplot, "e");
		fclose(gplot);
        printf("After %d steps, pi estimation is : %f\n", i, (4.* ((double)count / (double)random)));
		
	}
}
int main() {
    int steps = 6, random = 10;
    solution(steps, random);
    return 0;
}