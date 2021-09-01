/*
 * Project : hw2
 * Name    : Run Dong Lin
 * Date    : 2/5/2017
 * File    : bmi.c
 * Notes   : output the BMI with the given weight and height. (5'9" = 60 inches + 9 inches)
 */

#include <stdio.h>

/*
 * List any constants here, for example the start, end, and step values of your
 * weight and height ranges.
 */
  #define DEFAULT_WEIGHT 150 // Default weight.
  #define DEFAULT_HEIGHT 69  // Default height.
  #define STEP_WEIGHT 10     // Default step of weight increment.
  #define STEP_HEIGHT 1	     // Default step of height increment.
  #define MAX_WEIGHT 180     // Max weight range (including).
  #define MAX_HEIGHT 72      // Max height range (including).
  #define CONST_SCALAR 703   // BMI scalar.
/* A program to output the BMI values for the following weight/height
 * combinations:
 *   weight: every 10 pounds from 150 - 180
 *   height: every height from 5'9" to 6' from (69 <= 72)
 * Use the following formula:
 *   BMI = (Weight in Pounds / (Height in inches x Height in inches)) x 703
 */
int main(void)
{
 int weight, height;

  for (weight = DEFAULT_WEIGHT; weight <= MAX_WEIGHT; weight+=STEP_WEIGHT)
  {
    for (height = DEFAULT_HEIGHT; height <= MAX_HEIGHT; height+=STEP_HEIGHT)
    {
      float BMI = (weight /(float)(height*height)) * CONST_SCALAR;
      printf("weight = %dlb, height = %d\", BMI = %.2f\"\n", weight, height, BMI);
    }
  }
}
