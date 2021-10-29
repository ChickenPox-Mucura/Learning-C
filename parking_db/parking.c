#include <stdio.h>
#include <stdlib.h>

struct v_data {
	char class[10];
	char plate[10];
	char color[10];
} vehicle;

void parking__lot__data(struct v_data);

int main(void) {
	
	extern struct v_data vehicle;
	parking__lot__data(vehicle);

	return EXIT_SUCCESS;
}

void parking__lot__data(struct v_data machine) {
	
	FILE *fp;
	fp = fopen("lot_data", "a");
	
	/* Class */
	printf("Enter vehicle class:\n-->\t");
	scanf("%s", machine.class);
	fprintf(fp, "Class: %s\n", machine.class);
	/* Plate */
	printf("Enter vehicle plate:\n-->\t");
	scanf("%s", machine.plate);
	fprintf(fp, "Plate: %s\n", machine.plate);
	/* Color */
	printf("Enter vehicle color:\n-->\t");
	scanf("%s", machine.color);
	fprintf(fp, "Color: %s\n|----------------|\n", machine.color);

	fclose(fp);
}
