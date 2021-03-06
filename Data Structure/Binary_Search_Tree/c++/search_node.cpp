// C++ Implementation
// Binary Search Tree Search Operation

//  Visual Representation of the binary search tree
//                 10
//            /         \ 
//          5              17
//       /    \           /   \ 
//      2      7        14     22
//     / \    / \      / \     / \       
//    1   4  6   9   11   16 22   27     


#include <iostream>
using namespace std;


// Node Class
class NODE
{
   int data;
   NODE *left; 
   NODE *right;

public:

   NODE()
      : data(0)
      , left(NULL)
      , right(NULL)
   {
   }

   NODE(int value)
   {
      data = value;
      left = NULL;
      right = NULL;
   }

   NODE* Insert(NODE*, int);

   NODE* Search(NODE*, int);

   void Inorder(NODE*);

};



// Insert Operation
NODE* NODE ::Insert(NODE* root, int value)
{
   if (!root)
   {
      return new NODE(value);
   }
   if (value > root->data)
   {

      root->right = Insert(root->right, value);
   }
   else
   {
      root->left = Insert(root->left, value);
   }

   return root;
}


// Searching Element
NODE* NODE ::Search(NODE* root, int key)
{
   if (root == NULL || root->data == key) 
      if(root == NULL)
         {
            printf("\n Not Found");
            return 0;
         }
      else if(root->data != key)
         {
            printf("\n Not Found");
            return 0;
         }
      else
         {
            printf("\nFound");
            return 0;
         }
      // return root;
   
   if (root->data < key)
      return Search(root->right, key);

   return Search(root->left, key);
}


// To print in inorder method
void NODE ::Inorder(NODE* root)
{
   if (!root) {
      return;
   }
   Inorder(root->left);
   cout << root->data << endl;
   Inorder(root->right);
}





int main()
{
   NODE bst, *item = NULL;
   item = bst.Insert(item, 10);
   bst.Insert(item, 2);
   bst.Insert(item, 1);
   bst.Insert(item, 4);
   bst.Insert(item, 9);
   bst.Insert(item, 7);
   bst.Insert(item, 6);
   bst.Insert(item, 5);
   bst.Insert(item, 11);
   bst.Insert(item, 14);
   bst.Insert(item, 19);
   bst.Insert(item, 17);
   bst.Insert(item, 16);
   bst.Insert(item, 27);
   bst.Insert(item, 22);

   // bst.Inorder(item);

   bst.Search(item,5);

   return 0;

}












