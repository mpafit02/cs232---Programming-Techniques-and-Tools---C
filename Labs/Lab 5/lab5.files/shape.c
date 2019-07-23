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
  strcpy(s3.name ,"circle");
  s3.shapeType = circle;
  s3.stats.radius = 2.5;
  /*  printf("%f\n",s3.stats.radius);*/
  printShape(s1);
  printShape(s2);
  printShape(s3);
  
  return 0;

}


