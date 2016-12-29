//===========================================================
// HW#: HW1P1 stack
// Your name: Chris Banci
// Compiler:  g++
// File type: stack client program
//===========================================================

#include <iostream>
#include <string>
#include <math.h>
#include "stack.h"

using namespace std;

//PURPOSE: This program evaluates postfix expression.
//ALGORITHM: To evaluate a post fix expression, we must implement a stack. A while loop is used to parse each character of the expression.
//			 Operands are pushed onto the stack until an operator is encounter. Once is an operator is encountered,
//           two elements are popped from the top of the stack and is evaluated with operator then pushed back onto
//           the stack. The evaluation is finish when there are no longer any elements on the stack.
int main()
{
	stack postfixstack; // my stack object instance.
	string expression; // string variable to hold expression.

	char item; // current operand or operator parsed from expression.
	int i = 0; // incrementer to parse next item in expression.
	int box1; // first element popped from stack 
	int box2; // second element popped from stack
	int result; // evaluated result using operator with box2 and box1.

	cout << "type a postfix expression: ";
	cin >> expression;

	// while loop used to parse expression.
	while (expression[i] != '\0') {
		try {
			item = expression[i]; // current item.

			// if item is operand, push to stack.
			if (item >= '0' && item <= '9') {
				postfixstack.push(item - 48);
				postfixstack.displayAll();
			}
			
			// if its an operand, two elements are popped from stack and are evaulated with the operand.
			else if ((item == '+') || (item == '-') || (item == '*') || (item == '/') || (item == '^')) {
				postfixstack.pop(box1);
				postfixstack.pop(box2);

				if (item == '-') {
					result = box2 - box1;
				}
				else if (item == '+') {
					result = box2 + box1;
				}
				else if (item == '*') {
					result = box2 * box1;
				}
				else if (item == '/') {
					result = box2 * box1;
				}
				else if (item == '^') {
					result = pow(box2, box1);
				}

				// result is then pushed to the stack and stack is displayed.
				postfixstack.push(result);
				postfixstack.displayAll();
			}

			// exception thrown when item is not an operand or operator
			else {
				throw "invalid item";
			}

			i++; //incrementer to parse next item in expression.
		}

		//exception cases.
		catch (stack::Overflow) { // for too many elements on stack.
			cerr << "[Error] Overflow: Not enough memory on stack!" << endl;
			return -1;
		}

		catch (stack::Underflow) { // for too few operands
			cerr << "[Error] Underflow: Not enough operands!" << endl;
			return -1;
		}

		catch (char const* errorcode) { // for invalid item
			cerr << "[Error] Expression contains invalid item! " << endl;
			return -1;
		}
	}

	// the result is popped off the stack and printed to console.
	// the stack should be empty now.
	postfixstack.pop(result);
	cout << "result: " << result << endl;

	// if the stack is not empty after expression is evaluated, the expression is incomplete.
	// the current stack is shown.
	if (!postfixstack.isEmpty()) {
		cerr << "[Error] Incomplete expression! " << endl
			<< endl;

		cerr << "Current stack" << endl;
		cerr << "--------------" << endl;
		postfixstack.displayAll();
	}
}