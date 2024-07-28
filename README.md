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
As a first attempt, we could do something like [this](5_WriteAProgram/1_FirstAttempt.cpp).