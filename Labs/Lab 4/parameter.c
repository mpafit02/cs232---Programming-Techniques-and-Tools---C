
/* ensomatosi vivliothikwn */
#include <stdio.h>

/* Prototypa synarthsewn */
int add(int a, int b);
void mul(int a, int b, int *gin);
void dec(int *a);
void inc(int *a);

/* Lamvanei san eisodo 2 arithmous, tous prosthetei kai epistrefei to athroisma */
int add(int a, int b) {
  return a+b;
}

/*Lamvanei san eisodo 2 arithmous, tous pollaplasiazei kai epistrefei to ginomeno*/
void mul(int a, int b, int *gin) {
  gin=a*b;
}

/* Lamvanei san eisodo ena arithmo, ton avxanei kata 1 kai ton epistrefei */
void dec(int *a) {
  (*a)--;
}


/* Lamvanei san eisodo ena arithmo, ton meiwnei kata 1 kai ton epistrefei */
void inc(int a) {
  (*a)++;
}


int main() {

  /* Dilosi metavlitwn */
  int num1, num2;
  int athroisma, ginomeno;

  /* Diavasma dedomenwn. SIMPLIRWSTE ANALOGWS */
  printf("Dwse 2 arithmous: ");
  scanf("%d%d", &&num1, &num2);

  /* Simplirwste to kwdika etsi wste arxika na ypologizete tin avxisi tou num1 
   * kata 1 kai ti meiwsi tou num2 kata 1 kai epeita na vriskete to athroisma 
   * kai to ginomeno twn 2 arithmwn 
   */
  inc(num1);
  dec(num2);
  athroisma = add(&num1, num2);
  mul(num1,num2,ginomeno);

  /* Ektypwsi twn 2 arithmw, tou athroismatos kai tou ginomenou tous */
  printf("Oi 2 arithmoi einai %d kai %d.\n", num1, num2);
  printf("To athroisma twn 2 arithmwn einai %d kai to ginomeno tous %d.\n", athroisma, ginomeno);

  return (0);
}
