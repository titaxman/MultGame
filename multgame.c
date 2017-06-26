#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void intro(){
  printf("\n\n\n\n\n\n\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
  printf("\n\t\t=\tMultiplication Table Game\t=\n");
  printf("\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  printf("Developed by Gustavo H M Silva\nReach me at gustavohmsilva[at]member.fsf.org\nThis game is under BY-CC Creative Commons Attribution 4.0 International License.\nVersion 0.1\n\n");
}

int main(){
  srand(time(0));
  int
    alg1,
    alg2,
    res,
    points = 0,
    contJog = 1;
  char
    EscOp;

  intro();
  while(contJog){
      alg1 = (rand() % 10) + 1; alg2 = (rand() % 10) + 1;
      printf("Your points: %d\t|\t%d X %d = ", points, alg1, alg2); scanf("%d", &res);
      if (res == (alg1*alg2)) {
        printf("\nYour points: %d\t|\tCongrats! %d X %d is indeed equal to %d\n\n", points, alg1, alg2, res);
        points+=res;
      }else{
        printf("\nYour points: %d\t|\tSorry %d X %d is equal to %d, but your answer was %d...\n\n", points, alg1, alg2, alg1*alg2, res);
      }
      printf("Your points: %d\t|\tDo you wish to play again (Y or N)? ", points); scanf(" %c", &EscOp);
      (EscOp == 'n' || EscOp =='N') ? (contJog = 0) : (contJog = 1);
    }

}
