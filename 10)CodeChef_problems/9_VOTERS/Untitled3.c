#include <stdio.h>
#include <stdlib.h>

main()
{
	int N1, N2, N3, i, j, k, repeat, prev, *final, *arr;

	scanf("%d %d %d", &N1, &N2, &N3);

	final = (int *)malloc(sizeof(int*)*(N1+N2+N3));

	for(i = 0; i < N1; i++)
		scanf("%d", &final[i]);

	arr = (int *)malloc(sizeof(int *)*N2);

	for(i = 0; i < N2; i++)
		scanf("%d", &arr[i]);

	i = N1-1;
	j = N2-1;
	k = N1+N2-1;

	while(j >= 0 && i >= 0)
	{
		if(final[i] >= arr[j])
			final[k--] = final[i--];
		else
			final[k--] = arr[j--];

	}

	while(i >= 0)
		final[k--] = final[i--];

	while(j >= 0)
		final[k--] = arr[j--];

	free(arr);
	arr = NULL;

	arr = (int *)malloc(sizeof(int*)*N3);

	for(i = 0; i < N3; i++)
		scanf("%d", &arr[i]);

	i = N1+N2-1;
	j = N3-1;
	k = N1+N2+N3-1;

	while(j >= 0 && i >= 0)
	{
		if(final[i] >= arr[j])
			final[k--] = final[i--];
		else
			final[k--] = arr[j--];

	}

	while(i >= 0)
		final[k--] = final[i--];

	while(j >= 0)
		final[k--] = arr[j--];


	free(arr);
	arr = NULL;

	prev = final[0];

	j = 0;
	repeat = 0;

	for(i = 1; i < N1+N2+N3; i++)
	{
		if(prev == final[i])
		{
			if(repeat)
				continue;
			else
			{
				repeat = 1;
				final[j++] = final[i];
			}
		}
		else
			repeat = 0;

		prev = final[i];
	}

	printf("%d\n", j);

	for(i = 0; i < j; i++)
		printf("%d\n", final[i]);

	free(final);
	final = NULL;

	return 0;
}
