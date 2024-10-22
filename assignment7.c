//Katherine Quartana
//Date: 3/6/23
//Assignment 7
//about 200 lines NO MORE THAN 400!!

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ADD 1
#define MULT 2

//user defined functions
void menu(); //welcome menu
double arithGame(int max, int quantity, int op); //Gives the user quantity arithmetic questions
double guessGame(int max); //Allows the user to play the guessing game
int numDigits(int number); //Returns the number of digits in number
int numPoints(double timesec); //Returns the number of points the user has earned based on time
void quitGame(); //quit game

//additional functions
void addition();
void multi();
int randomNum(int max);
void printScore();

//GAME BEGINS
int userOpt;

//global score variable
int globalScore = 0;

int main() {
  srand(time(0)); //random number generator

  menu(); //call menu

  return 0;
}
// welcome function
void menu() {
  printf("Hello! Here are some games to help with arithmetic!\n\n");
  printf("1) Play Arithmetic Game\n");
  printf("2) Play Guessing Game\n");
  printf("3) Print Score\n");
  printf("4) Quit\n\n");

  printf("Select your option: ");
  scanf("%d", &userOpt);

  //arithmetic game
  if (userOpt == 1) {
    printf("1) Addition\n");
    printf("2) Multiplication\n");
    printf("Pick another option: ");
    scanf("%d", &userOpt);

    //Addition call for input 1
    if (userOpt == 1) {
      addition();
    }
    // Multiplication call for input 2
    else if (userOpt == 2) {
      multi();
    }
  }
  //Guessing game call for input 2
  else if (userOpt == 2) {
    int max;
    printf("Enter the max number: ");
    scanf("%d", &max);
    guessGame(max); //scanf & ask max number (no function neccessary)
  }
  //Print score call for input 3
  else if (userOpt == 3) {
    printScore();
  }
  //Quit call for input 4
  else if (userOpt == 4) {
    quitGame();
  }
}
//addition funct
void addition() {
  //declare variables
  int max;
  int quantity;
  int op = ADD;
  
  printf("What is the max value of the number you want?\n");
  scanf("%d", &max);
  printf("What do you want the total number of problems to be?\n");
  scanf("%d", &quantity);

  arithGame(max, quantity, op); // call arith funct
}
//multiplication funct
void multi() {
  //declare variables
  int max;
  int quantity;
  int op = MULT;
  
  printf("What is the max value of the number you want?\n");
  scanf("%d", &max);
  printf("What do you want the total number of problems to be?\n");
  scanf("%d", &quantity);

  arithGame(max, quantity, op); //call arith funct
}
//random funct
int randomNum(int max) {
  return rand() % (max + 1); //grabs max val and adds 1 to it
}
//print score funt
void printScore() {
  printf("Here's your score %d.\n", globalScore);
  menu();
}
//arithmetic game funct
double arithGame(int max, int quantity, int op) {
  //declare variables
  int choice;
  int penalty = 0;

  //time function
  int start = time(0);

  //used for the addition funct in arithgame
  if (op == 1) {

    for (int i = 0; i < quantity; i++) {

      int x = randomNum(max);
      int y = randomNum(max);

      printf("What is %d + %d?\n", x, y);
      scanf("%d", &choice);

      if (choice == (x + y)) {
        printf("Correct, YIPPEEE!\n");
        continue;
      } else
        printf("Incorrect, L+ratio. The correct answer was %d!\n", (x + y));
      penalty += 5;
    }
    int end = time(0);
    int timespent = end - start + penalty;
    double avg = timespent / quantity;
    printf("You took an average of %f seconds per question.\n", avg);

    int score = numPoints(avg);
    globalScore += score;
    printf("Your score for the round is %d.\n\n\n", score);
    menu();
  }
  //user for the multiplication funct in arithgame
  if (op == 2) {

    for (int i = 0; i < quantity; i++) {

      int x = randomNum(max);
      int y = randomNum(max);

      printf("What is %d * %d?\n", x, y);
      scanf("%d", &choice);

      if (choice == (x * y)) {
        printf("Correct, YIPPEEE!\n");
      } else
        printf("Incorrect, L+ratio. The correct answer was %d!\n", (x * y));
      penalty += 5;
    }
    //calculates score and time taken
    int end = time(0);
    int timespent = end - start + penalty;
    double avg = timespent / quantity;
    printf("You took an average of %f seconds per question.\n", avg);

    int score = numPoints(avg);
    globalScore += score;
    printf("Your score for the round is %d.\n\n\n", score);
    menu();
  }
  return 0;
}
//guess game funct
double guessGame(int max) {

  int num = ((rand() % max) + 1);
  //time function
  int start = time(0);

  //should give u random # between 1 and max
  int userGuess = 0;
  int numGuesses = 0;
  
  printf("Enter guess, bestie: ");
  scanf("%d", &userGuess);
  while (userGuess != num) {
    numGuesses++;
    if (userGuess > num) {
      printf("Number is lower.\n");
    } else if (userGuess < num) {
      printf("Number is higher.\n");
    }
    printf("Try again!! ");
    scanf("%d", &userGuess);
  }
  if (userGuess == num) {
    numGuesses++;
    printf("Congrats, You did it!!\n\n");
  }
  //calculate score
  int end = time(0);
  int timespent = end - start;
  double totalTime = ((double)(timespent)) / ((double)(4 * numDigits(num)));
  int score = numPoints(totalTime);
  globalScore += score;
  printf("Great, you guessed the correct number %d in %d guesses in %d seconds.\n\n\n", num, numGuesses, timespent);
  menu(); //call menu so game continues
  
  return 0;
}
//num digits funct
int numDigits(int number) {
  int tempDigits; //use temp digit variable
  //decides number of digits in number
  for (int i = 1; i < 10; i++) {
    if (number < pow(10, i)) {
      tempDigits = i;
    }
  }
  return tempDigits;
}
//score function
int numPoints(double timesec) {
  double score = 10 - timesec;
  score = ceil(score); //check math lib
  if (score < 0) {
    score = 0;
  }
  return score;
}
//quit game function
void quitGame() {
  printf("Ending game now..."); 
  }