/** @file operators1.c
* @brief Operator precedence and data types. Use of formatting.
*
* This program performs various arithmetic operations. Its purpose is
* to demonstrate the importance and priority of operators, data types,
* and the use of formatting.
*
* @author Pavlos Antoniou
* @bug No known bugs.
*/
#include <stdio.h>
int main(){
 /* Variable declaration */
 int int1, int2, int3, int4;
 float float1, float2, float3, float4;

 /* Arithmetic operations */
 int1 = 2;
 int2 = 3;
 int3 = 2/3;
 int4 = 3.0/2;
 float1 = 2/3;
 float2 = 2.0/3;
 float3 = int1 * int2 + (float1 + 1) / float2;
 float4 = 2.0 * 3 + 4 - 2 * 4 * 2.0 * 1.5;

 /* Print results */
 printf("\n Ta apotelesmata einai:\n");
 printf("\t int3 = %d\n", int3);
 printf("\t int4 = %d\n", int4);
 printf("\t int4 (f) = %f\n", int4);
 printf("\t float1 = %f\n", float1);
 printf("\t float2 = %f\n", float2);
 printf("\t float2 (e) = %e\n", float2);
 printf("\t float2 (d) = %d\n", float2);
 printf("\t float2/float1 = %f\n", float2/float1);
 printf("\t float3 = %f\n", float3);
 printf("\t float2 + float3 = %f\n", float2 + float3);
 printf("\t float2 + float3 = %5.2f\n", float2 + float3);
 printf("\t float4 = %f\n\n", float4);
 return 0;
}
