# cpp-ppp-notes
# Programming: Principles and Practice using C++
---
## Part I: The Basics
### Chapter 5: Writing a Program
### Problem
All programs must solve problems, so you must first decide what kind of problem you need to solve. This program will be a simple calculator. The stages of development are:
1. Analysis: Write down what you currently understand about the problem and what should be done. These are the *set of requirements*.
2. Design: Create a high-level design of the system and how it will work and how different parts will communicate.
3. Implementation: Write, debug and test code.

A good strategy to take into account while developing the program is the next:
1. Be specific about what the program needs to do or understand well what needs to be done. Ask questions about the problem and how the program will be interacted with, not about how it will be implemented.
- Make sure you understand the problem to not create a solution for a different problem, and don't be too ambitious. It's best to have a simple, easy to maintain solution when it can be updated later.
- Make sure the program can go through the three development stages given the time, resources and skills. It's pointless to do a task that can't be done. Try to get more time, resources, skills, or modify the requirements so that it can be done.
2. Break the program into smaller, manageable parts.
- Use libraries or tools where possible. Reinventing the wheel is only useful when learning to program, and has no place in real-world development.
- Identify parts of solutions in the same program that could be reused in many places.
3. Build a prototype first and foremost. Don't start with a full-scale solution. It's best to start with a program that solves a key part of the solution that goes through the stages of development. This will not be built upon, but parts may be reused for the last part of the strategy.
4. Build a full-scale solution using initial version's parts and prototypes so that it can be gradually built upon.

### Back to the calculator
This calculator will be in the console, so we could say that the program, from the user's perspective, might look like:
```
{
Expression: 2+2
Result: 4
Expression: 2+2*3
Result: 8
Expression 2+3-25/5
Result: 0
}
```

Now, how could we achieve that? First thing that comes to mind is a logic akin to this:

```
{
    input
    compute
    output
}
```
This is called pseudocode, because we don't really know what things are yet, but it's sort of code.
As a first attempt, we could do something like [the first version of this](5_WriteAProgram/1_FirstAttempt.cpp). There are flaws in this, like using if statements instead of switches, only supports one operand, only supports the '+' and '-' operands...
The [second version of the same file](5_WriteAProgram/1_FirstAttempt.cpp) fixes those issues, but it does not respect the order of operations, because it does them as they're read.

We need to look ahead of the operation before computing the answer. To do this, we need to tokenize. 

A token is a series of characters that represent a unit. In this calculator we need:
- Floating-point literals (e.g. 3.14159..., 4.5, 3.3333..., 20)
- Operators (+, -, *, /, %)
- Parentheses

We tokenize by representing is as a (kind, value) pair, where "kind" is what kind of token it is (floating-point literal, what operator it is, or parentheses), and value is its numeric value (only applicable to numbers). For this, we need to define tokens in C++.

How can we define it? Well, we need a way to store operators and numeric values, so something like this:
|| Token |      
|-------|-------|
| Kind | plus |
| Value ||

|| Token |      
|-------|-------|
| Kind | number |
| Value | 3.14 |

Knowing this, the simplest way to define this type is like so:
```cpp
{

    class Token                     // a very simple user-defined type
    {              
    public:
         char kind;
         double value;
    };
    
}
```
This fulfills the criteria we need for the token:
- [x] Stores operators. `kind` is of type `char`, which can store the operators that we need, plus what kind of token it is.
- [x] Stores numeric values. `value` is of type `double`, which can store the numbers we need.

Now we can freely create tokens like so:
```cpp
{

    Token t;                       // t is a Token
    t.kind = '+';                  // t represents a +
    Token t2;                      // t2 is another Token
    t2.kind = '8';                 // we use the digit 8 as the “kind” for numbers
    t2.value = 3.14;

}
```

We can now set how we want the implementation to sort of look like:
| '(' | '8' | '+' | '8' | ')' | '*' | '8' |
|-----|-----|-----|-----|-----|-----|-----|
|     | 1.5 |     |  4  |     |     |  11 |

`Token` is a user-defined type. It can have member functions and data members.
```cpp
{
    
    class Token
    {
    public:
         char kind;                                             // what kind of token
         double value;                                          // for numbers: a value
         Token(char k) :kind{k}, value{0.0}{}                   // construct from one value
         Token(char k, double v) :kind{k}, value{v}{}           // construct from two values
    };

}
```

`Token(char k) :kind{k}, value{0.0}{}` and `Token(char k, double v) :kind{k}, value{v}{}` are functions to help us initialize variables with the type `Token`.