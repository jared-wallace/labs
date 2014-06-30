// Insert proper header here

/*
 * This program asks for the lengths of the sides of a right
 * triangle and the lengths of the sides of a rectangle. The
 * length of the hypotenuse and the area of the rectangle are
 * then calculated and displayed.
 *
 */

#include <iostream>
#include <cmath> // For the sqrt and pow functions
using namespace std;

//****************************************************
// This function displays the header for the length
// of the hypotenuse of a triangle.
//****************************************************
void Display_triangle_header()
{
   cout << "The hypotenuse of the right angled triangle is: ";
}

//****************************************************
// This function displays the header for the area of
// the rectangle.
//****************************************************
void Display_rectangle_header()
{
   cout << "The area of the rectangle is: ";
}

//****************************************************
// This function prompts the user to enter the length
// of the height of a right angled triangle.
//****************************************************
double Get_height_of_triangle()
{
   double height;
   cout << "Enter the Height of a Triangle: ";
   cin >> height;
   return height;
}

//****************************************************
// This function prompts the user to enter the base
// of a right angled triangle.
//****************************************************
double Get_base_of_triangle()
{
   double base;
   cout << "Enter the Base of a Triangle: ";
   cin >> base;
   return base;
}

//****************************************************
// This function prompts the user to enter the width
// of a rectangle.
//****************************************************
double Get_width_of_rectangle()
{
   double width;
   cout << "Enter the Width of a Rectangle: ";
   cin >> width;
   return width;
}

//****************************************************
// This function prompts the user to enter the length
// of a rectangle.
//****************************************************
double Get_length_of_rectangle()
{
   double length;
   cout << "Enter the length of a Rectangle: ";
   cin >> length;
   return length;
}

int main()
{
   double height,        // The height of a right angled triangle
          base,          // The base of a right angled triangle
          hypotenuse,    // The hypotenuse of a right angled triangle
          length,        // The rectangle's length
          width,         // The rectangle's width
          area;          // The rectangle's area

   // Call the function to get the height of a triangle

   // Call the function to get the base of a triangle

   // Calculate the hypotenuse of a right triangle
   // Formula: square root (base ^ 2 + height ^ 2)

   // Call the function to get the rectangle's length

   // Call the function to get the rectangle's width

   // Calculate the rectangle's area

   // Call the function to display the triangle header

   // Display the hypotenuse of the triangle

   // Call the function to display the header for the calculated rectangle area

   // Display the area of the rectangle.


   return 0;
}

