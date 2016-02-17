//Merge Sort

void MergeSort(struct word_t** headref)
{
	struct word_t* one, two, head;
	head = *headRef;
	
	if (head == NULL || head->next == NULL)
	{
		return 0;
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
		return(one);
	}
	else if (two == NULL)
	{
		return(two);
	}
	
	if (one->word <= two->word)
	{
		result = one;
		result->next = SortedMerge(one->next, two);
	}
	else
	{
		result = two;
		result->next = SortedMerge(a, b->next);
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