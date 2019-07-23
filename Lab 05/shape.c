/** @file shape.c
 * @brief This program models a shape
 *
 * This program models a ractangle and a triagle using
 * the same data structure.
 *
 * @author Pavlos Antoniou
 * @bug No known bug
 */

#include <stdio.h>
#include <string.h>

// Write here your data structure

typedef enum {
	rectangle, triangle, circle
} ShapeType;

typedef struct {
	int length;
	int width;
} Rect;

typedef struct {
	int base;
	int height;
} Tri;

typedef union {
	Rect rect;
	Tri tri;
	double radius;
} Stats;

typedef struct {
	char name[20];
	ShapeType shapeType;
	Stats stats;
} shape;

/** @brief Print out the information on a shape
 *
 * This function prints the shape's characteristics according to where it
 * is a rectangle or a triangle.
 *
 * @param shape the shape object
 * @return void
 */
void printShape(shape);

int main() {
	shape s1, s2, s3;
	strcpy(s1.name, "rectangle");
	s1.shapeType = rectangle;
	s1.stats.rect.length = 10;
	s1.stats.rect.width = 20;
	strcpy(s2.name, "triangle");
	s2.shapeType = triangle;
	s2.stats.tri.base = 102;
	s2.stats.tri.height = 450;
	strcpy(s3.name, "circle");
	s3.shapeType = circle;
	s3.stats.radius = 2.5;
	/*  printf("%f\n",s3.stats.radius);*/
	printf("\nSize of a shape: %d", sizeof(s1));
	printf("\nSize of an enum: %d\nSize of rectangle in enum: %d\n",
			sizeof(s1.shapeType), sizeof(rectangle));
	printShape(s1);
	printShape(s2);
	printShape(s3);

	return 0;

}

void printShape(shape sh) {
	if (sh.shapeType == rectangle) {
		printf("\nThis is a rectangle with length = %d and width = %d.",
				sh.stats.rect.length, sh.stats.rect.width);
	} else if (sh.shapeType == triangle) {
		printf("\nThis is a triangle with base = %d and height = %d.",
				sh.stats.tri.base, sh.stats.tri.height);
	} else {
		printf("\nThis is a circle with radius = %.2lf", sh.stats.radius);
	}
}
