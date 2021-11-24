#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 1024

typedef struct {
	char class[MAX];
	char plate[MAX];
	char color[MAX];
} vehicle;

void parking__lot__data(vehicle);
FILE * which_file(char [], FILE *);

int main(void) {
	
	vehicle veh;
	parking__lot__data(veh);

	return EXIT_SUCCESS;
}

void parking__lot__data(vehicle machine) {
	
	FILE *fp = NULL;
	
	/* Class */
	printf("Enter vehicle class:\n-->\t");
	fgets(machine.class, MAX, stdin);
	if((fp = which_file(machine.class, fp)) == NULL)
		exit(1);
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
	
	switch(tolower(spec[0])) {
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
		return NULL;
	}

	return file_pointer;
}
