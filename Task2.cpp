#include<iostream>
using namespace std;
class Stack
{
private:
	class ListNode
	{
	public:
		char data;
		ListNode *next;
		ListNode(char d)
		{
			data = d;
			next = NULL;
		}
	};

	ListNode *top;

public:
	Stack()
	{
		top = NULL;
	}

	~Stack()
	{
		ListNode *temp = top;
		while (!IsEmpty())
		{
			Pop();
		}
		temp = NULL ;
	}

	void Push(char g)
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

	ListNode* RetTop()
	{
		return top;
	}
 char Pop()
	{
		if (top == NULL)
		{
			return '0';
		}
		ListNode* temp = top;
		char val = temp->data;
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
bool InFormat(string a)
{
	Stack A;
	int val;
	bool kal = true;
	char temp;
	for (int i = 0; a[i] == 'a'; i++)
	{
		A.Push(a[i]);
		val = i;
	}
	for (int j = val; j < a.length(); j++)
	{
		if (a[j] == 'a')
		{
			return false;
		}
		if (a[j] == 'b')
		{
			if (a[j++] == 'a')
			{
				kal = false;
				return kal;

			}
			else
			{
				char val = A.Pop();
				if (val == '0')
				{
					return false;
				}
			}
		}
		if (!A.IsEmpty())
		{
			return false;
		}
	}
	return kal;

}
////////////
bool ExpressionsCheck(string b)
{
	Stack A;
	for (int i = 0; i < b.length(); i++)
	{
		if (b[i] == '(')
		{
			A.Push(b[i]);
		}
		if (b[i] == '[')
		{
			A.Push(b[i]);
		}
		if (b[i] == '{')
		{
			A.Push(b[i]);
		}
		if (b[i] == ')')
		{
			A.Pop();
		}
		if (b[i] == ']')
		{
			A.Pop();
		}
		if (b[i] == '}')
		{
			A.Pop();
		}
	}
	if (A.IsEmpty())
	{
		return true;
	}
	else
	{
		return false;
	}
}
//////
bool IsOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '[' || c == '{' || c == '(' || c == ')' || c == '}' || c == ']')
	{
		return true;
	}
	else
	{
		false;
	}
}
int Precedence(char a)
{
	if (a == '+' || a == '-')
	{
		return 1;
	}
	else if (a == '*' || a == '/')
	{
		return 2;
	}
	else
	{
		return 3;
	}
}
void ConvertToPost(string a)
{
	Stack Num;
	Stack op;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] >= 0 || a[i] <= 9)
		{
			cout << a[i];
		}
		if(IsOperator(a[i]))
		{	
			if (i == 0)
			{
				op.Push(a[i]);
			}

			if (Precedence(op.Peek()) < Precedence(a[i]))
			{
				op.Push(a[i]);
			}

			else if (Precedence(op.Peek()) >= Precedence(a[i]))
			{
				cout << op.Pop();
				op.Push(a[i]);
			}
		}
		
	}
}
int main()
{
	if (!InFormat("aabbb"))
	{
		cout << "Invalid";
	 }
	else
	{
		cout << "Valid";
	}
	cout << "\n";
	//////task 3
	if (!ExpressionsCheck("(2+3*4"))
	{
		cout << "Invalid";
	}
	else
	{
		cout << "Valid";
	}
	/////////
	cout << endl;
	ConvertToPost("(2+3)*4");
	return 0;
}