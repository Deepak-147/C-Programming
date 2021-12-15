#include<stdio.h>
int length_of_songs[100];
int duplicate(int [], int);//For unique values of length_of_songs
void sort_playlist(int[], int);//Sorting the length_of_songs in playlist
int main(void)
{
    int no_of_test_cases, no_of_songs, i, j, position, length_of_target_song, k;
    scanf("%d", &no_of_test_cases);
    if(no_of_test_cases > 1000)
        return(0);
    else
    {
        for(i=0; i<no_of_test_cases; i++)
        {
           scanf("%d", &no_of_songs);
           if((no_of_songs < 1) || (no_of_songs > 100))
                return(0);
           else
           {
               for(j=0; j<no_of_songs; j++)
               {
                    scanf("%d", &length_of_songs[j]);
                    if((length_of_songs[j] < 1) || (length_of_songs[j] > 1000000000))
                        return(0);
               }
               if(duplicate(length_of_songs, no_of_songs) == 1)
                    return(0);
               scanf("%d", &position);
               length_of_target_song = length_of_songs[position-1];
               sort_playlist(length_of_songs, no_of_songs);
               for(k=0; k<no_of_songs; k++)
               {
                    if(length_of_songs[k] == length_of_target_song)
                        printf("%d", k+1);

               }
               printf("\n");
           }
        }
    }
    printf("\n");
    return(0);
}

int duplicate(int length_of_songs[], int n)
{
    int i, j, flag = 0;
    for(i=0; i<n; i++)
     {
         for(j=i+1; j<n; j++)
         {
             if(length_of_songs[i] == length_of_songs[j])
             {
                flag = 1;
                return(flag);
             }

         }
     }
     return(flag);
}

void sort_playlist(int length_of_songs[], int n)
{
    int i, j, temp;
    for(i=1; i<n; i++)
    {
        for(j=0; j<(n-i); j++)
        {
            if(length_of_songs[j] > length_of_songs[j+1])
            {
                temp=length_of_songs[j];
                length_of_songs[j]=length_of_songs[j+1];
                length_of_songs[j+1]=temp;
            }
        }
    }
}
