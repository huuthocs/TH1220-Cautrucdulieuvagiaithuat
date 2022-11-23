#include<iostream>
using namespace std;

// Khai bao cau truc Tree
typedef int Info;
struct BinT_Node {
	Info Key;
	BinT_Node* Left; 
	BinT_Node* Right;
};
typedef BinT_Node* BinT_Type;

// Khoi tao cay
void Initialize(BinT_Type &BTree) {
	BTree = NULL;
}

// Khoi tao cay nhi phan
BinT_Type Create_Node(Info NewData) {
 	BinT_Type BTnode = new BinT_Node;
 	if(BTnode != NULL)
 	{
 		BTnode->Left = NULL;
 		BTnode->Right = NULL;
 		BTnode->Key = NewData;
	}
	return BTnode;
}

// Nhap cay nhi phan
void Read_Tree(BinT_Type &BTree){ 
	Info X;
 	cin>>X;
 	if(X!=0){
 		BinT_Type BT;
 		BT = Create_Node(X);
 		BTree = BT;
 		cout<<"Nhap con trai cua "<<X<<" : ";
 		Read_Tree(BTree->Left);
 		cout<<"Nhap con phai cua "<<X<<" : ";
 		Read_Tree(BTree->Right);
 	}
 else BTree=NULL;
}	

// De qui, de duyet cay nhi phan theo thu tu Left - Root - Right
void LRootR_Traverse(BinT_Type BTree) { 
	if(BTree == NULL)
		return;
	LRootR_Traverse(BTree->Left);
	cout << BTree->Key << '\t';
	LRootR_Traverse(BTree->Right);
} 

// Them mot nut vao ben trai nhat cua cay
void Add_Left(BinT_Type &BTree, Info NewData) {
	BinT_Type NewNode = Create_Node(NewData);
	if(BTree == NULL)
		BTree = NewNode;
	else{
		BinT_Type Lnode = BTree;
		while(Lnode->Left != NULL)
			Lnode = Lnode->Left;
			Lnode->Left = NewNode;
	}
} 

// Tinh chieu cao cua cay
int Tree_Height(BinT_Type BTree) {
	if(BTree == NULL)
	return 0;
	int HTL = Tree_Height(BTree->Left);
	int HTR = Tree_Height(BTree->Right);
	if(HTL > HTR)
		return HTL + 1;
	else
		return HTR + 1;
}

// Dem nut so cay
int Count_Node(BinT_Type BTree) {
	if(BTree == NULL) return 0;
	int NNL = Count_Node(BTree->Left);
	int NNR = Count_Node(BTree->Right);
	return(NNL + NNR + 1);
}

