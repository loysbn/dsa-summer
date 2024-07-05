#ifndef BST 
#define BST

typedef struct{
	int day, month, year;
}Date;

typedef struct {
	char prodName[20]; // use strcmp()
	float prodPrice;
	int prodQty;
	Date expDate;
}Product;

typedef struct node{
	Product item;
	struct node *left, *right;
}NodeType, *NodePtr;

void initTree(NodePtr* Tree);
void insert(NodePtr* Tree, Product b);
void Delete(NodePtr* Tree, Product b);
void preOrder(NodePtr Tree);
void inOrder(NodePtr Tree);
void postOrder(NodePtr Tree);

#endif
