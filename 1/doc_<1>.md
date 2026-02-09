Data Structures
A global char array named stack of size 50 stores the input brackets. A global integer top initialized to -1 tracks the current stack index and determines if the stack is empty.

Function Descriptions
The push function increments top and adds a character to the array. The pop function returns the character at top and then decrements the index to remove it.

Main Method Organization
The main method reads a string and iterates through it with a for loop. Opening brackets are passed to push(), and closing brackets trigger pop(). A final check on the top variable determines if the expression is balanced.

Sample Output
Enter the input expression: (())
The expression is balanced!!