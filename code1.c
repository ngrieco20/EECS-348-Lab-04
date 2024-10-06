#include <stdio.h>

void potential_combinations(int score) {
    int td, fg, safety, td_2pt, td_1pt; //makes a interer variable for each scoring method 

    printf("Possible combinations of scoring plays if a team’s score is %d\n", score); // prints the possible combos of scores 

    for (td = 0; td <= score / 6; td++) { //sets TD scores to 6  points 
        for (td_1pt = 0; td_1pt <= score / 7; td_1pt++) { // sets td +1 pt to 7 points 
            for (td_2pt = 0; td_2pt <= score / 8; td_2pt++) { // sets td + 2 pt to 8 points 
                for (fg = 0; fg  <= score / 3; fg++) { // sets fg to 3 points 
                    for (safety = 0; safety <= score / 2; safety++) { // sets safety to 2 points
                        int total = td * 6 + td_2pt * 8 + td_1pt * 7 + fg * 3 + safety * 2; // adds everything to total
                        if (total == score) {
                            printf("%d TD, %d TD + FG, %d TD + 2 pts, %d 3 Pt FG, %d Safety\n", td, td_1pt, td_2pt, fg, safety); // prints score total
                        }
                    }
                }
            }
        }
    }
}
int main() {
    
    int score;

   while (1) {
        printf("Enter 0 or 1 to STOP\n"); // instructions to stop 
        printf("Enter the NFL score: "); // asks for score 
        scanf("%d", &score);

        if (score <= 1) {
            break;
        }

        potential_combinations(score); //calls function and prints score 
    }

    printf("Program terminated.\n"); // prints when you enter 0 or 1 to stop 
    return 0;
}
