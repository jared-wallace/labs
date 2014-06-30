#include <iostream>
#include <cstdlib>

int main()
{
   int choice = 0;

   std::cout << "Please select a soda:" << std::endl << std::endl;
   std::cout << "1. Coca-Cola" << std::endl;
   std::cout << "2. Diet Coca-Cola" << std::endl;
   std::cout << "3. Sprite" << std::endl;
   std::cout << "4. Dr. Pepper" << std::endl;
   std::cin >> choice;
   std::cout << std::endl << "You chose ";

   switch (choice)
   {
      case 1:
         std::cout << "Coca-Cola.";
         break;
      case 2:
         std::cout << "Diet Coca-Cola.";
         break;
      case 3:
         std::cout << "Sprite.";
         break;
      case 4:
         std::cout << "Dr. Pepper.";
         break;
      default:
         std::cerr << "an invalid number dumbass.";
         break;
   }

   std::cout << std::endl;

   return (EXIT_SUCCESS);
}
