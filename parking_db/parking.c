#include <stdio.h>
#include <stdlib.h>

struct v_data {
	char class[10];
	char plate[10];
	char color[10];
} vehicle;

int main(int argc, char *argv[]) {
	FILE *fp;
	fp = fopen("parking_data", "a");
	
	/* Class */
	printf("Enter vehicle class:\n-->\t");
	scanf("%s", vehicle.class);
	fprintf(fp, "Class: %s\n", vehicle.class);
	/* Plate */
	printf("Enter vehicle plate:\n-->\t");
	scanf("%s", vehicle.plate);
	fprintf(fp, "Plate: %s\n", vehicle.plate);
	/* Color */
	printf("Enter vehicle color:\n-->\t");
	scanf("%s", vehicle.color);
	fprintf(fp, "Color: %s\n|----------------|\n", vehicle.color);

	fclose(fp);

	return EXIT_SUCCESS;
}
