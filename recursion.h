# include<iostream>
using namespace std;
struct Snode
{
	int key;
	Snode* pnext;
};
struct  Slist
{
	Snode* phead;
	Snode* ptail;
};
void initialize(Slist** w_list);

Snode* newnode(int val);

bool isEmpty(Slist* r_list);

// delete the first element
Snode* pop(Slist* &u_list);

// add to the head of list
void push(Slist* u_list, int val); 

void deinitialize(Slist* list);

// insert val2 between node1 and node2
void insert(Snode* node1, Snode* node2, int val);


// initialize node=list->phead in main function
int sumEven(Slist* list, int sum, Snode* node);

// initialize node=list->phead in main function
int maxElement(Slist* list, Snode* node, int max);

// return true if x exist on a array and  i is position need finding
bool find_Xelement(Slist* list, Snode* node, int x, int& i); 

// initialize node=list->phead in main function
void reverseLinklisted(Slist* list, Slist* re_list, Snode* node);

//node=list->phead in main function 
void sortArrayGoup(Slist* list, Snode* node);

long Pascal(int n, int k);

//long long int combination(int n, int k);

void denode(Slist* &list, Snode* node);