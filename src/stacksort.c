#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10
#define NEW_SET 1
#define EXIT 2

typedef struct
{
  int elems[MAX_SIZE];
  int top;

} Stack;

void getNumbers(Stack *);
void getChoice(int *, char *);
void printMenu();
void printStack(Stack);
int pop(Stack *);
int peek(Stack *);
bool isFull(Stack *);
bool isEmpty(Stack *);
int push(int, Stack *);
void initStack(Stack *);
void sortStack(Stack *);
bool isSorted(Stack);
void handleNewNumbers();
void handleExit();

int main(void)
{
  int choice;
  while (true)
  {
    printMenu();
    getChoice(&choice, "Choice: ");
    switch (choice)
    {
    case NEW_SET:
      handleNewNumbers();
      break;
    case EXIT:
      handleExit();
      break;
    default:
      printf("Unknown option");
    }
  }
  return 0;
}

void handleExit()
{
  exit(0);
}

void handleNewNumbers()
{
  Stack inputStack;
  Stack *inputStackPtr = &inputStack;
  initStack(inputStackPtr);
  getNumbers(inputStackPtr);
  if (isSorted(*inputStackPtr))
  {
    printf("Wow, that was amazing clap your hands!");
  }
  else
  {
    printf("Good try! Mistakes help us learn new things.\n");
    printf("Here is the correct answer: ");
    sortStack(inputStackPtr);
    printStack(*inputStackPtr);
  }
}

void getNumbers(Stack *stack)
{
  int num, count = 0;
  while (count < MAX_SIZE)
  {
    if (count == 0)
    {
      printf("Let's start at the beginning—what's the first number? ");
    }
    else
    {
      printf("Can you tell me which number comes next, please? ");
    }
    scanf("%d", &num);
    push(num, stack);
    count++;
  }
}

void sortStack(Stack *stack)
{
  Stack sortedStack;
  initStack(&sortedStack);
  // Sort with the largest element on top of the stack
  while (!isEmpty(stack))
  {
    int tmp = pop(stack);
    while (!isEmpty(&sortedStack) && tmp < peek(&sortedStack))
    {
      push(pop(&sortedStack), stack);
    }
    push(tmp, &sortedStack);
  }
  // Copy into the original stack
  while (!isEmpty(&sortedStack))
  {
    push(pop(&sortedStack), stack);
  }
}

bool isSorted(Stack stack)
{
  while (!isEmpty(&stack))
  {
    int tmp = pop(&stack);
    if (peek(&stack) > tmp)
      return false;
  }
  return true;
}

void initStack(Stack *stack)
{
  stack->top = -1;
}

int pop(Stack *stack)
{
  if (isEmpty(stack))
    return -1;
  int elem = stack->elems[stack->top];
  stack->top--;
  return elem;
}

int peek(Stack *stack)
{
  if (isEmpty(stack))
    return -1;
  return stack->elems[stack->top];
}

bool isEmpty(Stack *stack)
{
  return stack->top == -1;
}

bool isFull(Stack *stack)
{
  return stack->top == MAX_SIZE - 1;
}

int push(int num, Stack *stack)
{
  if (isFull(stack))
    return -1;
  stack->elems[++stack->top] = num;
  return num;
}

void printMenu()
{
  printf("\nWelcome to the game of numbers!!!");
  printf("\n%d. Begin\n", NEW_SET);
  printf("%d. Exit\n", EXIT);
}

void getChoice(int *dest, char *prompt)
{
  printf("%s ", prompt);
  scanf("%d", dest);
}

void printStack(Stack stack)
{
  while (!isEmpty(&stack))
  {
    printf("%d ", pop(&stack));
  }
}
