#include<iostream>
#include<string>
using namespace std;
class Stack
{
private:
	class ListNode
	{
	public:
		int data;
		ListNode *next;
		ListNode(int d)
		{
			data = d;
			next = NULL;
		}
	};

	ListNode *top;

public:
	Stack()
	{
		cout << "Constructing Stack\n";
		top = NULL;
	}

	~Stack()
	{
		cout << "destructing  stack\n";
		ListNode *temp = top;
		while (!IsEmpty())
		{
			Pop();
		}
		delete temp;
	}

	void Push(int g)
	{
		if (top == NULL)
		{
			top = new ListNode(g);
			return;
		}
		else
		{
			ListNode *temp = new ListNode(g);
			temp->next = top;
			top = temp;
		}

	}


	int Pop()
	{
		if (top == NULL)
		{
			return 0;
		}
		ListNode* temp = top;
		int val = temp->data;
		top = temp->next;
		delete temp;
		return val;
	}
	int Peek()
	{
		if (top == NULL)
		{
			return 0;
		}
		ListNode* temp = top;
		return top->data;
	}


	bool IsEmpty()
	{
		if (top == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void display()
	{
		ListNode *tmp = top;
		while (tmp != NULL)
		{
			cout << tmp->data << endl;
			tmp = tmp->next;
		}

	}
};
int countA(string a)
{
	int count = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == 'a')
		{
			count++;
		}
	}
	return count;
}
int countB(string a)
{
	int count = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == 'b')
		{
			count++;
		}
	}
	return count;

}


int main()
{
	Stack k;
	k.Push(32);
	k.Push(3);

	k.Push(2);

	k.Push(1);
	cout << k.Peek();
	int c = k.Pop();
	cout << k.Peek();
	cout << endl;
	cout << c;
	k.Pop();
	k.Pop();

	k.Pop();
	k.Pop();

	cout << "\n" << k.IsEmpty();
	cout << endl;
	return 0;
}