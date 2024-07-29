#include "../PPP.h"

#include <iostream>

/*
// Second version
int main()
{
        int lval = 0;
        int rval = 0;

        std::cout << "Please enter expression (we can handle +, −, * and /).\n";
        std::cout << "Add an \"x\" to end an expression (e.g 1+2+3x): \n";
         
        std::cin >> lval;                       // Read left value

        if (!std::cin)
            error("No first operand.");

        for (char op; std::cin>>op;)            // This reads the operand and the right value
        {
            if (op!='x')
                std::cin >> rval;

            if (!std::cin)
                error("No second operand.");

            switch (op)
            {
            case '+':
                lval += rval;
                break;
            case '-':
                lval -= rval;
                break;
            case '*':
                lval *=rval;
                break;
            case '/':
                lval /= rval;
                break;
            default:
                std::cout << "Result: " << lval << "\n";
                return 0;
            }
        }
    error("Bad operation.");
    return 0;
}
*/

/*
// First version
#include "PPP.h"

int main()
{
         cout << "Please enter expression (we can handle + and −): ";
         int lval = 0;
         int rval = 0;
         char op = 0;
         int res = 0;
         cin >> lval >> op >> rval;          // read something like 1 + 3

         if (op=='+')
                  res = lval + rval;                 // addition
         else if (op=='−')
                  res = lval − rval;                // subtraction
         cout << "Result: " << res << '\n';
}
*/