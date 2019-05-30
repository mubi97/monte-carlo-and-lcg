#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <curses.h>
void solution(int steps, int random){
    int countp = 0, countn = 0;
    double x, y;
    FILE *gplot;

	for (int i = 1; i <= steps; i++) {
		gplot = popen("gnuplot -persistent", "w");
		fprintf(gplot, "set term jpeg\n");
		fprintf(gplot, "set output \"task-2f-d-%d.jpg\"\n", i);
		fprintf(gplot, "plot '-' title \"sin(x^2)\" with points pt 7\n");

		random = pow(10, i);

		for (int j = 0; j < random; j++) {
			x = (double)rand() / RAND_MAX*8.0;
	     	y = (double)rand() / RAND_MAX*(2.0 - 1.0);
			double xOriginal = x;
			
			x *= x;
            if(y > 0){
                if(sin(x) > 0 && sin(x) >= y){
                    fprintf(gplot, "%f %f\n", xOriginal, y);
				    countp++;
                }
            }
			if(y < 0){
                if(sin(x) < 0 && sin(x) <= y){
                    fprintf(gplot, "%f %f\n", xOriginal, y);
				    countn++;
                }
            }
		}
		fprintf(gplot, "e");
		fclose(gplot);
        double answer = ((double)(countp) / (double)(random)) + ((double)(countn) / (double)(random));
        printf("Answer is : %f\n", answer * 16);
		
	}
}
int main() {
    int steps = 5, random = 10;
    solution(steps, random);
    return 0;
}