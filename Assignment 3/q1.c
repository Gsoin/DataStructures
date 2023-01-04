// imports
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



/*
 *Gunteshwar Soin
 *1178257
 */



int numberTop = -1;
int operatorTop = -1;
int stackOpArray[50];
float stackNumArray[50];



char operPush(char node) // seperate stack for operands
{
	if (operatorTop == 50)
	{
		printf("Stack full\n");
		exit(0);
	}
	else
	{
		stackOpArray[++operatorTop] = node;
		return stackOpArray[operatorTop];
	}
}

float numPush(float node) // stack for numbers
{
	if (numberTop == 50)
	{
		printf("Stack full\n");
		exit(0);
	}
	else
	{
		stackNumArray[++numberTop] = node;
		return stackNumArray[numberTop];
	}
}



char operPop() // push for operand stack
{
	if (operatorTop == -1)
	{
		printf("Stack empty\n");
		exit(0);
	}
	else
	{
		return (stackOpArray[operatorTop--]);
	}
}
float numPop() // push for float stack
{
	if (numberTop == -1)
	{
		printf("Stack empty\n");
		exit(0);
	}
	else
	{
		return (stackNumArray[numberTop--]);
	}
}



/*start expression tree */
typedef struct node
{
	char *info;
	struct node *right;
	struct node *left;
} node;

node *makeElement(char *information)
{
	node *tmp;
	tmp = malloc(sizeof(struct node) + 1);

	tmp->info = malloc(sizeof(char) * (strlen(information) + 1));
	strcpy(tmp->info, information);
	tmp->right = NULL;
	tmp->left = NULL;

	return tmp;
}

node *addtoList(node *theList, node *toBeAdded, char *direction)
{
	node *ptrTemp = toBeAdded;
	if (theList == NULL)
	{
		theList = ptrTemp;
		return theList;
	}

	if (strcmp(direction, "right") == 0)
	{
		ptrTemp->right = theList;
		theList = toBeAdded;
		return theList;
	}
	else
	{
		ptrTemp->right = theList;
		theList = toBeAdded;
		return theList;
	}
}

int main(int argc, char const *argv[])
{
	// char expr[50]//tested using expression
	int userChoice = 1;
	char expr[50];
	


	char character;
	float poppedNumber;
	char poppedOperator;
	

	char realExp[50];
	char tempStr[5];
	char tempStr2[2];

	int exprLen = strlen(expr);
	int j = 0, count = 1;
	float f, first = 0.00, second = 0.00;
	char c, d;
	char varName[2];
	char xVar[3];

	if ((argc < 2) || (argc > 3)) // if command input is incorrect
	{
		printf("Incorrect number of arguments\n");
		return -1;
	}

	strcpy(expr, argv[1]);

	while (userChoice != 0)
	{
		printf("\n");
		printf("1. Preorder\n");
		printf("2. Postorder\n");
		printf("3. Exit\n");
		scanf("%d", &userChoice);

		switch (userChoice)
		{

		case 1: // print the order of the expression but replace any operand with the earliest open bracket in the expression
			printf("Preorder\n");
			poppedOperator = ')';
			exprLen = strlen(expr);
			strcpy(realExp, expr);


			for (int i = 0; i < exprLen; ++i){
				c = expr[i];


				if ((c == '+') || (c == '/') || (c == '-') || (c == '*')){
					expr[i] = ' ';		 // replace open bracket with a space


					for (int j = i; j >= 0; j--) // count down from that point
					{
						d = expr[j]; // when coming to first open bracket


						if (d == '(' && count == 1){
							expr[j] = c; // replace with the operand
							count++;
						}
					}
				}
				count = 1;
			}

			for (int i = 0; i < exprLen; ++i){
				c = expr[i];
				if (c == ')')
				{
					// don't print the bracket
				}
				else
				{
					printf("%c", c); // print the character
				}
			}

			strcpy(expr, realExp);
			break;



		case 2: // good
			printf("Postorder\n");
			exprLen = strlen(expr);

			strcpy(realExp, expr);
			poppedOperator = ')';
			for (int i = 0; i < exprLen; ++i){
				character = expr[i];

				if (isdigit(character)){// if it's a number, push into stack
					memcpy(tempStr, &expr[i], 4);
					tempStr[4] = '\0';
					f = atof(tempStr);
					i += 3;
					numPush(f);
				}
				else if (character == 'x') // if it's an unknown variable, push 0.00 into the stack
				{
					memcpy(tempStr2, &expr[i], 3);
					tempStr2[2] = '\0';
					f = 0.00;
					numPush(f);
					i += 1;
				}
				else if ((character == '+') || (character == '-') || (character == '/') || (character == '*') || (character == '(')){
					operPush(character); // push any operator into the stack
				}
				else // character is )
				{
					realExp[j] = character;
					j++;

					while (numberTop != -1){
						poppedNumber = numPop();
						printf("%.2f ", poppedNumber); // keep on popping numbers
					}
					while (operatorTop != -1){ // keep popping characters until before )
						poppedOperator = operPop();
						if (poppedOperator != '('){
							printf("%c ", poppedOperator);
						}
					}
				}
			}
			strcpy(expr, realExp);
			break;



		case 3: // good
			printf("Exit\n");
			return 0;
			break;



		default:
			printf("Incorrect operation\n");
			break;
		}
	}

	return 0;
}