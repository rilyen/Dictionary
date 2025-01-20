/*
 * Dictionary.cpp
 * 
 * Description: Dictonary data collection ADT class.
 *              BST-based implementation.
 *              Duplicated elements not allowed.
 *              
 * Author: 
 * Date of last modification: Nov. 1 2023
 */

#include "Dictionary.h"
#include <iostream>
using std::cout;
using std::endl;

    /* Constructor and Destructor */
    // Default Constructor
    Dictionary::Dictionary(){
        keyValuePairs = new BST();
    }
    // Destructor
    Dictionary::~Dictionary(){
        // if (keyValuePairs != nullptr) {
        //     delete keyValuePairs;
        //     keyValuePairs = nullptr;
        // }
        delete keyValuePairs;
        keyValuePairs = nullptr;
    }

    /* Dictionary operations */
    // Description: Returns the number of elements currently stored in the Dictionary.
    unsigned int Dictionary::getElementCount() const{
        return keyValuePairs->getElementCount();
    }

    // Description: Puts "newElement" (association of key-value) into the Dictionary.
    // Precondition: "newElement" does not already exist in the Dictionary.
    //               This is to say: no duplication allowed.
    // Exception: Throws the exception "UnableToInsertException" 
    //            when newElement cannot be inserted in the Dictionary.  
    // Exception: Throws the exception "ElementAlreadyExistsException" 
    //            if "newElement" already exists in the Dictionary.  
    void Dictionary::put(WordPair & newElement){
        keyValuePairs->insert(newElement);
    }

    // Description: Gets "newElement" (i.e., the associated value of a given key) 
    //              from the Dictionary.
    // Precondition: Dictionary is not empty.
    // Exception: Throws the exception ElementDoesNotExistException
    //            if the key is not found in the Dictionary.
    // Exception: Throws the exception EmptyDataCollectionException if the Dictionary is empty.
    WordPair & Dictionary::get(WordPair & targetElement) const{
        return keyValuePairs->retrieve(targetElement);
    }

    // Description: Prints the content of the Dictionary.
    // Precondition: Dictionary is not empty.
    // Exception: Throws the exception EmptyDataCollectionException if the Dictionary is empty.
    void Dictionary::displayContent(void visit(WordPair &)) const{
        keyValuePairs->traverseInOrder(visit);
    }
