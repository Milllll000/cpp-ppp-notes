#include <iostream>

int main()
{
         std::cout << "Please enter expression (we can handle + and −): ";
         int lval = 0;
         int rval = 0;
         char op = 0;
         int res = 0;
         std::cin >> lval >> op >> rval;          // read something like 1 + 3

         if (op=='+')
                  res = lval + rval;                 // addition
         else if (op=='−')
                  res = lval - rval;                // subtraction
         std::cout << "Result: " << res << '\n';
}