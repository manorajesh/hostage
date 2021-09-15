#include <stdio.h>
#include <conio.h>                                                                  //for _getch
#include <stdlib.h>                                                                 //for rand()

#define GAME_BOUNDS 100                                                             //denotes the length of printed characters or game boundries

void print_k(int rand_seed);
void clr_scr();
void init(int rand_seed);

extern int counter_space = 0;                                                       //multiple functions interact with these varibles
extern int counter_fc = 0;                                                          //
extern int score = 0;                                                               //

int main()
{
	int rand_number = rand();                                                       //rand_number is kept here since print_k is refreshing its random numbers
    char c;

  init(rand_number);

	while((c = _getch()) != 'q') {                                                  //get a character without hitting enter and assign value to c; if that character is q, quit
        if (c == 'd') {
          ++counter_space;
          counter_space = counter_space > GAME_BOUNDS ? 0 : counter_space;          //wrap around when H reaches right end of bounds

          system("cls");

          print_k(rand_number);
          for(counter_fc = 0; counter_fc < counter_space; ++counter_fc)             //print spaces until it function_call is one less than required spaces (counted by counter_space)
              printf(" ");
          printf("H");
        }
        else if (c == 'a') {
            --counter_space;
            counter_space = counter_space < 0 ? GAME_BOUNDS : counter_space;        //wrap around when H reaches left end of bounds

            system("cls");

          print_k(rand_number);
          for(counter_fc = 0; counter_fc < counter_space; ++counter_fc) {           //print spaces until it function_call is one less than required spaces
            printf(" ");
          }		
          printf("H");
        }
        else if (c == 'w') {
            if (counter_space == rand_number % GAME_BOUNDS) {                       //when a correct answer is picked, score will increment by 1 and will re-initalize the scene
                ++score;
                rand_number = rand();
                init(rand_number);
            }
            else {                                                                  //when a correct answer is not picked, score will decrease by 1 and will re-initalize the scene
                --score;
                init(rand_number);
            }
        }
	}	
}

void print_k(int rand_seed)
{ 
	//rand_seed will be used to determine where random character will be
    /*
    * The line of letters will refresh into randomly chosen letters from the charset array; occasionally the 
    * unique letter will become the same by that event is few and far between
    */

    printf("Score = %d\n", score);

    rand_seed %= GAME_BOUNDS;

    int c;
    int i = 10 - rand_seed;
    int rand_num_1 = rand()%26;                                                     //keeping random numbers between 26 so there is no read-access violation
    int rand_num_2 = rand()%26;                                                     //

    char *charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(c = 0; c < rand_seed; ++c)                                                  //print character until random character will be printed
        printf("%c", charset[rand_num_1]);
    printf("%c", charset[rand_num_2]);

    for (; c < GAME_BOUNDS; ++c)                                                    //continue printing characters until game bounds
        printf("%c", charset[rand_num_1]);
  printf("\n");
}

void print_k_stnd(int rand_seed)
{
    //rand_seed will be used to determine where random character will be

    printf("Score = %d\n", score);

    rand_seed %= GAME_BOUNDS;

    int c;
    int i = 10 - rand_seed;

    for (c = 0; c < rand_seed; ++c)
        printf("K");
    printf("F");

    for (; c < GAME_BOUNDS; ++c)
        printf("K");
    printf("\n");
}

void clr_scr()  //clear screen (deprecated) 
{
  int i;

  for(i = 0; i <= 25; ++i)
    printf("\n");
}

void init(int rand_seed)                                                            //initalize scene
{
  system("cls");
  counter_fc = 0;                                                                   //'H' will start on the left
  counter_space = 0;
  print_k(rand_seed);
  printf("H");                                                                      //print_k does not handle 'H' printing
}