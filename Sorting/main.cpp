#include <iostream>


class list {
private:
	struct node {
		int val;
		node *next, *prev;
	};

	node *head = NULL, *bot;
	int values = 0;


	node* GetIndex(const int &index) const
	{
		node *n;

		if(index < values/2)
		{
        	n = head;
        	for(int current_index = 0; current_index != index; current_index++)
        	{
        		n = n->next;
        	}
		} else{
			n = bot;
			for(int current_index = values-1; current_index != index; current_index--)
			{
				n = n->prev;
			}
		}

		return n;
	}
	
public:
	void Add(const int &value)
	{
		if(head == NULL)
		{
			head = new node();
			head->val = value;
			bot = head;

		} else{
			bot->next = new node;
			bot->next->prev = bot;
			bot->next->val = value;
			bot = bot->next;
		}
		values++;
	}
	void Add(const int &index, const int &value)
	{
		if(index == values)
		{
			Add(value);
			return;
		}

		node *n = GetIndex(index);

		node *new_node = new node();
		new_node->val = value;
		new_node->next = n;
		
		if(n == head)
		{
			head = new_node;
		} else{
        	new_node->prev = n->prev;
			n->prev->next = new_node;
		}
		n->prev = new_node;

		values++;
	}
	void Modify(const int &index, const int &value)
	{
		node *n = GetIndex(index);
		n->val = value;
	}
	int Get(const int &index)
	{
		return GetIndex(index)->val;
	}
	void Print() const
	{
		node *n = head;
		while(n != NULL)
		{
			std::cout << n->val << std::endl;
			n = n->next;
		}
	}
	void PrintRev() const
	{
    	node *n = bot;
    	while(n != NULL)
    	{
    		std::cout << n->val << std::endl;
    		n = n->prev;
    	}
	}
	void Sort()
    {
		int avg = Get(0);	// Make use of!
		list *new_list = new list();
		new_list->Add(Get(0));


    	for(int index = 1; index < values; index++)
		{
			int index_val = Get(index);
			avg = (avg+index_val)/2;

    		for(int test = 0; test <= index; test++)
    		{	
    			if(test == new_list->values || index_val < new_list->Get(test))
				{
					new_list->Add(test, index_val);
					break;
				}
    		}
    	}
		
		head = new_list->head;
		bot = new_list->bot;
		delete(new_list);
    }
};

int main()
{
	list prices;
	prices.Add(100);
	prices.Add(23);
	prices.Add(5);
	prices.Add(99);
	prices.Add(71);
	prices.Add(4, 67);
	prices.Add(100);
	prices.Print();
	std::cout << "Sorted:" << std::endl;
	prices.Sort();
	prices.Print();
	return 0;
}

/*
TODO:
* Templates
* Stop memory leaking
* Different sortings
* Effectivise many Get()
*/
