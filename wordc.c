#include<stdio.h>
#include<string.h>
#include<time.h>
#include<sys/time.h>
#include<stdlib.h>
#include<regex.h>

struct word_t
{
	char *word;
	int count;
	struct word_t *next;
};

typedef struct word_t Word;
void freeMem(Word *head);
void convertToNormal(char* string);

int main(int argc, char *argv[])
{
	struct timeval startTime, endTime;	
	gettimeofday(&startTime, NULL);
	if(argc != 4)
	{
		printf("Please enter valid files: inputFile outputCountFile outputRuntimeFile\n");
		return 0;
	}
	FILE *inputFile;
	char wordOne[10];
	Word *curr, *head;

	head = curr = NULL;
	inputFile = fopen(argv[1], "r");
	//while(fgets(wordOne,sizeof(wordOne),inputFile))
	while(fscanf(inputFile,"%s",wordOne)==1)
	{
		Word *node = malloc(sizeof(Word));
		char *temp = strdup(wordOne);
		convertToNormal(temp);
		node->word = (strdup(temp));
		node -> next=NULL;

		if(head ==NULL)
		{
			curr = head = node;
		}
		else
		{
			curr = curr->next=node;
		}
	}
	fclose(inputFile);

	FILE *countFile;
	countFile = fopen(argv[2],"w");
	for(curr = head; curr; curr = curr->next)
	{
		fprintf(countFile, "%s\n", curr->word); 
	} 
	fclose(countFile);
	
	freeMem(head);
	
	gettimeofday(&endTime, NULL);
	unsigned int runtime = endTime.tv_usec - startTime.tv_usec;
	
	FILE *fRuntime;
	fRuntime=fopen(argv[3], "w");
	fprintf(fRuntime,"The runtime is %d\n" , runtime);
	fclose(fRuntime);
	
	return 0;
}

void freeMem(Word *head)
{
	Word *curr, *next;
	curr = head;

	while(curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
}

void convertToNormal(char* string)
{
	int length = strlen(string);
	int isAlpha;
	int i; 
	for(i = 0; i < length; i++)
	{
		isAlpha = isalnum(string[i]);
		if(isAlpha==0)
		{
			int j;
			for(j=i;j<=(length);j++)
			{
				string[j]=string[j+1];
				length--;
			}	
		}
		string[i] = tolower(string[i]);
	}
}