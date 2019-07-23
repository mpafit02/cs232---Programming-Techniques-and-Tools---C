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

typedef struct {
  double length;
  double width;
}rectStuff;


typedef struct {
  double base;
  double height;
}triStuff;


/*
 * The shape data structure
*/
typedef struct {
  char name[10];
  enum tagField {rectangle, triangle, circle}__attribute__((packed)) shapeType;
  union {
    rectStuff rect;
    triStuff tri;
    double radius;
  } stats;
}__attribute__((packed))shape;


void printShape(shape);


/** @brief Print out the information on a shape
 *
 * This function prints the shape's characteristics according to where it
 * is a rectangle or a triangle.
 *
 * @param shape The shape object
 * @return void
 */
void printShape(shape s) {
  printf("Name: %s\n", s.name);
  switch(s.shapeType){
  case rectangle:   
    printf("\tLength:%f\n", s.stats.rect.length);
    printf("\tWidth:%f\n\n", s.stats.rect.width);
    break;
  case triangle:   
    printf("\tBase:%f\n", s.stats.tri.base);
    printf("\tHeight:%f\n\n", s.stats.tri.height);
    break;
  case circle:   
    printf("Radius:%f\n",s.stats.radius);
    break;
  }
}


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

  strcpy(s3.name ,"circle");
  s3.shapeType = circle;
  s3.stats.radius = 2.5;

  printShape(s1);
  printShape(s2);
  printShape(s3);

  printf("\nThe size of a shape is: %d Bytes\n", sizeof(s1));
  
  return 0;
}

