#include"recursion.h"

# define SIZEMAX 1000; 
int main()
{
	Slist* list = nullptr;
	initialize(&list);
	int nume = 0;
	cout << "Enter the number of elements:\n";
	cin >> nume;
	for (int i = 0; i < nume; i++)
	{
		int x = 0;
		cout << "Value: ";
		cin >> x;
		push(list, x);
	}
	for (Snode* n = list->phead; n != nullptr; n=n->pnext)
	{
		cout << n->key << "\t";
	}
	cout << endl;
	int sum = 0;
	Snode* node = list->phead;
	int sum1=sumEven(list, sum, node );
	cout <<"The total of even elements\t"<< sum1 << "\n";

	int max = -123456789;
	Snode* node1 = list->phead;
	cout <<"Max element :"<< maxElement(list,node1, max)<<"\n";

	int i = 0;
	int f = 0;
	cout << "Enter X value wanting to find out :";
	cin >> f;
	Snode* node2=list->phead;
	if (find_Xelement(list, node2, f, i)) cout << "Position of X in Array: " << i<<"\n";
	else cout << "X not exist in array!\n";

	Slist* relist = nullptr;
	initialize(&relist);
	cout << "Array after being reversed:\n";
	reverseLinklisted(list,relist,node);
	for (Snode* n = relist->phead; n != nullptr; n=n->pnext)
	{
		cout << n->key << "\t";
	}
	
	cout << "\n";

	Snode* node3 = list->phead;
	Snode* pos = list->phead;
	
	cout << "Array after being sorting:\n";
	sortArrayGoup(list,node3);
	for (Snode* n = list->phead; n != nullptr; n = n->pnext)
	{
		cout << n->key << "\t";
	}
	deinitialize(list);
	deinitialize(relist);
	
	return 0;
}