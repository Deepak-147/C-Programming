#include<stdio.h>
int i, j, no_of_test_cases, no_of_games, initial_state, no_of_coins, count_what, output, A[100], count = 0;
int coinflip(int, int, int);
void assign_initial_state(int);
int final_game(int, int);
void flip(int);
void reset(void);
int main(void)
{
    scanf("%d", &no_of_test_cases);
    if(no_of_test_cases > 10)
        return(0);
    else
    {
        for(i=0; i<no_of_test_cases; i++)
        {
                scanf("%d", &no_of_games);
                if((no_of_games < 1) || (no_of_games > 2000))
                    return(0);
                else
                {
                    for(j=0; j<no_of_games; j++)
                    {
                        scanf("%d", &initial_state);
                        if((initial_state < 1) || (initial_state > 2))
                            return(0);
                        else
                        {
                            scanf("%d", &no_of_coins);
                            if((no_of_coins < 1) || (no_of_coins > 1000000000))
                                return(0);
                            else
                            {
                                scanf("%d", &count_what);
                                if((count_what) < 1 || (count_what > 2))
                                    return(0);
                                else
                                {
                                    reset();
                                    output = coinflip(initial_state, no_of_coins, count_what);
                                    printf("%d", output);
                                    printf("\n");
                                }
                            }
                        }
                    }
                }

        }


    }
    return(0);
}

void reset(void)
{
    for(i=0; i<no_of_coins; i++)
        A[i] = 0;
    count = 0;
}
int coinflip(int initial_state, int no_of_coins, int count_what)
{
    assign_initial_state(initial_state);
    return(final_game(no_of_coins, count_what));
}

void assign_initial_state(int initial_state)
{
    if(initial_state == 1)
    {
        for(i=0; i<no_of_coins; i++)
            A[i] = 1;// 1 for Heads
    }
    else
    {
        for(i=0; i<no_of_coins; i++)
            A[i] = 2;// 2 for Tails
    }
}

int final_game(int no_of_coins, int count_what)
{
    for(i=0; i<no_of_coins; i++)
    {
        if(((no_of_coins-i) % 2) != 0)//Flip only if odd
            flip(i);
    }
    for(i=0; i<no_of_coins; i++)
    {
        if(A[i] == count_what)
            count++;
    }
    return count;
}

void flip(int i)
{
    if(initial_state == 1)
        A[i] = 2;
    else
        A[i] = 1;
}
