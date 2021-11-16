#include <stdio.h>
#include <stdlib.h>
#define MAX 1024

struct v_data {
	char class[MAX];
	char plate[MAX];
	char color[MAX];
} vehicle;

void parking__lot__data(struct v_data);
FILE * which_file(char spec[], FILE * fp);

int main(void) {
	
	extern struct v_data vehicle;
	parking__lot__data(vehicle);

	return EXIT_SUCCESS;
}

void parking__lot__data(struct v_data machine) {
	
	FILE *fp;
	
	/* Class */
	printf("Enter vehicle class:\n-->\t");
	fgets(machine.class, MAX, stdin);
	fp = which_file(machine.class, fp);
	fprintf(fp, "Class: %s", machine.class);
	/* Plate */
	printf("Enter vehicle plate:\n-->\t");
	fgets(machine.plate, MAX, stdin);
	fprintf(fp, "Plate: %s", machine.plate);
	/* Color */
	printf("Enter vehicle color:\n-->\t");
	fgets(machine.color, MAX, stdin);
	fprintf(fp, "Color: %s|----------------|\n", machine.color);

	fclose(fp);
}

 FILE * which_file(char spec[], FILE *file_pointer) {
	
	switch(spec[0]) {
	case 'c':
		file_pointer = fopen("car_data", "a");
		break;
	case 't':
		file_pointer = fopen("truck_data", "a");
		break;
	case 'b':
		file_pointer = fopen("bus_data", "a");
		break;
	case 'm':
		file_pointer = fopen("motorcycle_data", "a");
		break;
	default:
		printf("Error: invalid vehicle class!\n");
		break;
	}

	return file_pointer;
}
