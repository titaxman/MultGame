#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int
  alg1,
  alg2,
  res,
  modeChoice,
  points = 0,
  contJog = 1;
char
  EscOp;

void intro(){
  printf("\n\n\n\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
  printf("\n\t\t=\tMultiplication Table Game\t=\n");
  printf("\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n\n");
  printf("Developed by Gustavo H M Silva\nReach me at gustavohmsilva[at]member.fsf.org\nThis game is under BY-CC Creative Commons Attribution 4.0 International License.\nVersion 0.2\n\n");
  printf("MultGame is a small game programmed in C to help \npractice memorization of the Multiplication game. \nThis small program will add to your points every \nright answer and lower in 10 points every wrong one.\n\n\n");
}

void presentation(){
  printf("This game has two modes. The first one is the result mode,\n");
  printf("where you are presented with a multiplication and has to insert\n");
  printf("the result of this same operation.\n\n");
  printf("The second one is the operators mode, in which you are presented\n");
  printf("with a number and has to input a the first and second operators\n");
  printf("that will result in the number presented.\n\n");
  printf("What mode would you like to run?\n");
  printf("1 | Result mode\n");
  printf("2 | Operators mode\n");
  printf("3 | Close the game\n\n");
  printf("Please input your answer (1/2/3):"); scanf(" %d", &modeChoice);

}

void guessTheResult(){
  while(contJog){
    alg1 = (rand() % 10) + 1; alg2 = (rand() % 10) + 1;
    printf("Your points: %d\t|\t%d X %d = ", points, alg1, alg2); scanf("%d", &res);
    if (res == (alg1*alg2)) {
      printf("\nYour points: %d\t|\tCongrats! %d X %d is indeed equal to %d\n\n", points, alg1, alg2, res);
      points+=res;
    }else{
      printf("\nYour points: %d\t|\tSorry %d X %d is equal to %d, but your answer was %d...\n\n", points, alg1, alg2, alg1*alg2, res);
      (points > 10) ? (points = points - 10) : (points = 0);
    }
    printf("Your points: %d\t|\tDo you wish to play again (Y or N)? ", points); scanf(" %c", &EscOp);
    (EscOp == 'n' || EscOp =='N') ? (contJog = 0) : (contJog = 1);
  }
}

void guessTheOperators(){
  while(contJog){
    alg1 = (rand() % 10) + 1; alg2 = (rand() % 10) + 1;
    res = alg1 * alg2;
    printf("Your points: %d\t|\tWhat multiplication operators will generate %d?\n", points, res);
    printf("First operator: "); scanf("%d", &alg1);
    printf("Second operator: "); scanf("%d", &alg2);
    if ((alg1 * alg2) == res){
      printf("\nYour points: %d\t|\tCongrats! %d X %d is indeed equal to %d\n\n", points, alg1, alg2, res);
      points+=res;
    }else{
      printf("\nYour points: %d\t|\tSorry %d X %d is equal to %d, not %d...\n\n", points, alg1, alg2, alg1*alg2, res);
      (points > 10) ? (points = points - 10) : (points = 0);
    }
    printf("Your points: %d\t|\tDo you wish to play again (Y or N)? ", points); scanf(" %c", &EscOp);
    (EscOp == 'n' || EscOp =='N') ? (contJog = 0) : (contJog = 1);
  }
}

int main(){
  srand(time(0));

  intro();
  presentation();
  if (modeChoice == 1) {
    guessTheResult();
  }else{
    if (modeChoice == 2) {
      guessTheOperators();
    }
  }
}
