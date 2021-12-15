#include<stdio.h>
int main(void)
{
    int length_of_conversation;
    scanf("%d", &length_of_conversation);
    char english_translation[27];
	scanf("%s", english_translation);
	while(length_of_conversation--)
    {
        int i, length;
		char sentence[100];
		scanf("%s", sentence);
        for(i=0; sentence[i] != '\0'; i++)
		{
			if(sentence[i] == '_')
				sentence[i] = ' ';
			if(sentence[i] >= 'a' && sentence[i] <= 'z')
			{
				length = sentence[i] - 97;
				sentence[i] = english_translation[length];
			}
			if(sentence[i] >= 'A' && sentence[i] <= 'Z')
			{
				length = sentence[i] - 65;
				sentence[i] = english_translation[length] - 32;
			}
		}
		printf("%s\n", sentence);
    }
    return(0);
}
