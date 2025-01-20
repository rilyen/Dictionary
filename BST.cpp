/*
 * BST.cpp
 * 
 * Description: Binary Search Tree data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are not allowed.
 *
 * Class invariant: It is always a BST.
 * 
 * Author: 
 * Date of last modification: Nov. 1 2023
 */
 
#include "BST.h"
#include "WordPair.h"
#include <iostream>

using std::cout;
using std::endl;

// You cannot change the prototype of the public methods of this class.
// Remember, if you add public methods to this class, our test driver 
// - the one we will use to mark this assignment - will not know about them
// since we will use these public method prototypes to create our test driver.

/* Constructors and destructor */

   // Default constructor
   BST::BST() { }            

   // Description: Recursively creates a deep copy of a binary search tree
   BSTNode* BST::copyTree(BSTNode * current) {
      if (current == nullptr) {
         return nullptr;
      }
      else {
         BSTNode* newNode = new BSTNode(current->element);
         newNode->left = copyTree(current->left);
         newNode->right = copyTree(current->right);
         return newNode;
      }
   }

   // Copy constructor
   BST::BST(const BST & aBST) {
     root = copyTree(aBST.root);
     elementCount = aBST.elementCount;
	  // to do
   }

   // Description: Recursively deletes a binary search tree
   void BST::clearTree(BSTNode* current) {
      // if (current == nullptr) {
      //    return;
      // }
      if (current != nullptr) {
         clearTree(current->left);
         clearTree(current->right);
         delete current;
      }
   }

   // Destructor 
   BST::~BST() {

      // to do
      //cout << "Calling destructor" << endl;
      clearTree(root);
   }                
   
   
/* Getters and setters */

   // Description: Returns the number of elements currently stored in the binary search tree.   
   // Time efficiency: O(1)   
   unsigned int BST::getElementCount() const {     

     return this->elementCount;
   }
   

/* BST Operations */

   // Description: Inserts an element into the binary search tree.
   //              This is a wrapper method which calls the recursive insertR( ).
   // Precondition: "newElement" does not already exist in the binary search tree.
   // Exception: Throws the exception "UnableToInsertException" when newElement 
   //            cannot be inserted because the "new" operator failed. 
   // Exception: Throws the exception "ElementAlreadyExistsException" 
   //            if "newElement" already exists in the binary search tree.
   // Time efficiency: O(log2 n)   
   void BST::insert(WordPair & newElement) {
  
      // to do
      BSTNode* newNode = new BSTNode(newElement);
	  if (newNode == nullptr) {
       throw UnableToInsertException("the 'new' operator failed");
     }
     if (elementCount == 0) {
       root = newNode;
     }
     else {
       if (!insertR(newNode,this->root)) {
          throw ElementAlreadyExistsException("element already exists");
       }
     }
     elementCount++;
   } 

   // Description: Recursive insertion into a binary search tree.
   //              Returns true when "anElement" has been successfully inserted into the 
   //              binary search tree. Otherwise, returns false.
   bool BST::insertR(BSTNode * newNode, BSTNode * current) {  
    
	  // to do
     // BASE CASE
		if (current == nullptr) {
         current = newNode;
         return true;
      } 
      // RECURSIVE CASE
      else if (newNode->element < current->element) {
         // BASE CASE
         if (current->left == nullptr) {
            current->left = newNode;
            return true;
         }
         else {
            return insertR(newNode, current->left);
         }
      }
      else if (newNode->element > current->element) {
         // BASE CASE
         if (current->right == nullptr) {
            current->right = newNode;
            return true;
         }
         else {
            return insertR(newNode, current->right);
         }
      }
      // Case where element already exists
      else {
         return false;
      }
   }

   
   // Description: Retrieves "targetElement" from the binary search tree.
   //           This is a wrapper method which calls the recursive retrieveR( ).
   // Precondition: Binary search tree is not empty.
   // Exception: Throws the exception "EmptyDataCollectionException" 
   //            if the binary search tree is empty.
   // Exception: Throws (propagates) the exception "ElementDoesNotExistException" 
   //            thrown from the retrieveR(...)
   //            if "targetElement" is not in the binary search tree.
   // Time efficiency: O(log2 n)
   WordPair& BST::retrieve(WordPair & targetElement) const {
      
     if (elementCount == 0)  
        throw EmptyDataCollectionException("Binary search tree is empty.");
	
     WordPair& translated = retrieveR(targetElement, root);
	 
     return translated;
   }

   // Description: Recursive retrieval from a binary search tree.
   // Exception: Throws the exception "ElementDoesNotExistException" 
   //            if "targetElement" is not found in the binary search tree.
   WordPair& BST::retrieveR(WordPair & targetElement, BSTNode * current) const {

	  // to do
		if (current == nullptr) {
         throw ElementDoesNotExistException("element is not in the binary search tree");
      }
      else if (targetElement == current->element) {
         return current->element;
      }
      else if (targetElement < current->element) {
         return retrieveR(targetElement, current->left);
      }
      else {
         return retrieveR(targetElement, current->right);
      }
   } 
         
   
   // Description: Traverses the binary search tree in order.
   //           This is a wrapper method which calls the recursive traverseInOrderR( ).
   //           The action to be done on each element during the traverse is the function "visit".
   // Precondition: Binary search tree is not empty.
   // Exception: Throws the exception "EmptyDataCollectionException" 
   //         if the binary search tree is empty.
   // Time efficiency: O(n)     
   void BST::traverseInOrder(void visit(WordPair &)) const {
     
     if (elementCount == 0)  
       throw EmptyDataCollectionException("Binary search tree is empty.");

     traverseInOrderR(visit, root);
     
     return;
   }

   // Description: Recursive in order traversal of a binary search tree.   
   //              in order traversal is left, root, right
   void BST::traverseInOrderR(void visit(WordPair &), BSTNode* current) const { 
   
	  // to do
      if (current != nullptr) {
         traverseInOrderR(visit,current->left);
         visit(current->element);
         traverseInOrderR(visit,current->right);
      }
   }
