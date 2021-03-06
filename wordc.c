#include<stdio.h>
#include<string.h>
#include<time.h>
#include<sys/time.h>
#include<stdlib.h>

struct word_t
{
	char *word;
	int count;
	struct word_t *next;
};

typedef struct word_t Word;
void freeMem(Word *head);
void convertToNormal(char* string);
void MergeSort(struct word_t** headref);
struct word_t* SortedMerge(struct word_t* one, struct word_t* two);
void Split(struct word_t* origin, struct word_t** front, struct word_t** back);

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
	char wordOne[1000];
	Word *curr, *head;
	Word *curr2;

	head = curr = NULL;
	curr2 = head;
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
	
	MergeSort(&head);

	FILE *countFile;
	countFile = fopen(argv[2],"w");
	for(curr = head; curr; curr = curr->next)
		curr->count = curr->count++;
	for(curr = head; curr; curr = curr->next)
	{
		while((curr->next != NULL) && strcmp(curr->word,curr->next->word) == 0)
		{		
			if((curr->next != NULL) && strcmp(curr->word,curr->next->word) == 0)
			{
				curr->count = curr->count++;
				curr->next  = curr->next->next;
			}
		}
	} 
	for(curr = head; curr; curr = curr->next)
	{
		fprintf(countFile, "%s, %d\n", curr->word, curr->count); 
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

void MergeSort(struct word_t** headref)
{
	struct word_t* one;
	struct word_t* two;
	struct word_t* head= *headref;
	if (head == NULL || head->next == NULL)
	{
		return;
	}

	Split(head, &one, &two);
	MergeSort(&one);
	MergeSort(&two);
	*headref = SortedMerge(one, two);
}

struct word_t* SortedMerge(struct word_t* one, struct word_t* two)
{
	struct word_t* result = NULL;
	if (one == NULL)
	{
		return(two);
	}
	else if (two == NULL)
	{
		return(one);
	}
	
	if (strcmp(one->word, two->word) < 0 )
	{
		result = one;
		result->next = SortedMerge(one->next, two);
		return(result);
	}
	else
	{
		result = two;
		result->next = SortedMerge(one, two->next);
		return(result);
	}
	return(result);
}

void Split(struct word_t* origin, struct word_t** front, struct word_t** back)
{
	struct word_t* fast;
	struct word_t* slow;
	if (origin == NULL || origin->next == NULL)
	{
		*front = origin;
		*back = NULL;
	}
	else
	{
		slow = origin;
		fast = origin->next;
		
		while(fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		
		*front = origin;
		*back = slow->next;
		slow->next = NULL;
	}
}
