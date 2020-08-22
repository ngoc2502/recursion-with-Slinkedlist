#include"recursion.h"

void initialize(Slist** w_list)
{
	*w_list = new Slist{ nullptr, nullptr };
}

Snode* newnode(int val)
{
	Snode* node = new Snode;
	node->key = val;
	node->pnext = nullptr;
	return node;
}

bool isEmpty(Slist* r_list)
{
	if (r_list->phead== nullptr)
		return true;
	return false;
}

Snode* pop(Slist* &u_list)// delete the first element
{
	if (isEmpty(u_list)) return nullptr;
	Snode* node = u_list->phead;
	Snode* temp = u_list->phead->pnext;
	delete u_list->phead;
	u_list->phead = temp;
	return node;
}

void push(Slist* u_list, int val)// add to the head of list
{
	Snode* node = newnode(val);
	if (isEmpty(u_list))
	{
		u_list->phead = u_list->ptail = node;
		return;
	}
	node->pnext = u_list->phead;
	u_list->phead = node;
	return;
}

void deinitialize(Slist* list)
{
	while (!isEmpty)
	{
		pop(list);
	}
}

void insert(Snode*node1, Snode*node2, int val)// insert val2 between node1 and node2
{
	Snode* node = newnode(val);
	node->pnext = node2;
	node1->pnext = node;
}

long long Cpow(int x, int n)
{
	if (n == 0) return 1;
	return Cpow(x,n - 1) * x;
}

long long cpow(int x,int n, long long g)
{
	if (n == 0) return g;
	return cpow(x,n - 1,x*g);
}



int sumEven(Slist *list,int sum, Snode*node)// initialize node=list->phead in main function
{
	if (isEmpty(list)) return 0;
	if (node->pnext == nullptr) return sum;
	else if (node->key % 2 == 0) sum += node->key;
	return sumEven(list, sum, node = node->pnext);
}

int maxElement(Slist *list, Snode* node, int max)
{
	if (isEmpty(list)) return 0;
	if (node == nullptr) return max;
	if (node->key >= max) max = node->key;
	return maxElement(list, node=node->pnext, max);
}

bool find_Xelement(Slist*list, Snode*node, int x, int &i)
{
	if (isEmpty(list)) return false;
	int kt = false;
	if (node == nullptr) return kt;
	if (node->key == x)
	{
		kt = true;
		return kt;
	}
	i++;
	return find_Xelement(list, node->pnext, x, i);
}

void reverseLinklisted(Slist*list, Slist*re_list, Snode* node)// initialize node=list->phead in main function
{
	if (isEmpty(list)) return;
	if (node==nullptr) return;
	push(re_list, node->key);
	return reverseLinklisted( list,re_list,node=node->pnext);
}


int tongchung(int n, int k)
{
	if (n == 1 && k == 1) return 1;
	return tongchung(n - 1, k - 1) + tongchung(n, k+1);
}

long Pascal(int n, int k)
{
	if (k == 0 || k == n) return 1;
	return Pascal(n - 1, k - 1) + Pascal(n - 1, k);
}
 int combination(int k, int n)
{
	if (n == k or k == 0)
		return 1;
	return  combination(k - 1, n - 1) + combination(n, k - 1);
	
}

void swap(int& a, int& b)
{
	int temp = a;
	a= b;
	b = temp;
}
void poptail(Slist* &list)
{
	Snode* n = list->phead;
	while (n->pnext->pnext != nullptr)
	{
		n = n->pnext;
	}
	delete n->pnext;
	list->ptail = n;
	n->pnext = nullptr;
}


void sortArrayGoup(Slist* list, Snode* node)//node=list->phead
{
	if (node == nullptr || list->phead->pnext == nullptr)return;

	if (node->key <= list->phead->key && node != list->phead)
	{
		Snode* Nadd = newnode(node->key);
		Nadd->pnext = list->phead;
		list->phead = Nadd;
		if (node == list->ptail)
		{
			denode(list, node);
			return;
		}
		denode(list,node);
		return sortArrayGoup(list, node=node->pnext);
	}
	if (node != list->phead->pnext && node != list->phead)
	{
		for (Snode* n = list->phead; n->pnext != node; n = n->pnext)
		{
			if (n->key <= node->key && n->pnext->key >= node->key)
			{
				Snode* Nadd = newnode(node->key);
				Nadd->pnext = n->pnext;
				n->pnext = Nadd;
				if (node == list->ptail)
				{
					denode(list, node);
					return;
				}
				denode(list,node);
				return sortArrayGoup(list, node=node->pnext);
			}
		}
	}
	return sortArrayGoup(list, node = node->pnext);
}

void denode(Slist* &list, Snode* node)
{
	Snode* n = list->phead;
	if (n == node)
	{
		pop(list);
		return;
	}
	if (node == list->ptail)
	{
		poptail(list);
		return;
	}
	for (Snode* no = list->phead; no != list->ptail; no = no->pnext)
	{
		if (node == no->pnext)
		{
			no->pnext = no->pnext->pnext;
			return;
		}
	}
}
