int main(void) {
    int num;
    printf("\n Enter any number: ");
    scanf("%d", &num);

    char inputNo[20];
    char convertedNo[20];

    itoa(num, inputNo, 10);


    int i = 1;
    int j = 0;

    while(inputNo[j] != '\0')
    {
        if(j%2 == 0)
        {
            convertedNo[j] = inputNo[j/2];
        }
        else
        {
            convertedNo[j] = inputNo[strlen(inputNo) - i];
            i++;
        }
        j++;
    }
    convertedNo[j] = '\0';
    printf("%s\n", convertedNo);

    return 0;
}
