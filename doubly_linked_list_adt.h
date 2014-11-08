/*
 *  Project: Doubly Linked List C-API, example data type 
 *  File:   DoublyLinkedList_ADT.h
 *  Author: Chris Aslanoglou
 *  Github: https://github.com/chris-asl/doubly-linked-list-API
 */

#ifndef DOUBLYLINKEDLIST_ADT_H
#define	DOUBLYLINKEDLIST_ADT_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct DoublyLinkedList_ADT *List;
    typedef int IteratorID;
    
    /*
     * Function responsible for initializing the Doubly Linked List ADT
     * Return values:
     *      [*] On success,  0 is returned
     *      [*] On failure,  -1 is returned
     */
    int dll_init(List*);
    /*
     * Function returning the size of the list
     */
    int dll_size(List);
    /*
     * Function responsible for checking if the list is empty
     * Return values:
     *      [*] on empty list, 1 is returned
     *      [*] on non empty list, 0 is returned
     */
    int dll_isempty(List);
    /*
     * Function responsible for printing the list in this fashion:
     *          "element -> element -> element" (delimiter "->")
     * Return values:
     *      [*] On success,  0 is returned
     *      [*] On failure,  -1 is returned
     */
    void dll_print(const List, void (*print_data)(void*), int);
    /*
     * Function responsible for inserting an element at the end of the list
     * Return values:
     *      [*] On success,  0 is returned
     *      [*] On failure,  -1 is returned
     */
    int dll_insert_at_back(List, void*, void* (*)(void*));
    /*
     * Function responsible for inserting an element at the start of the list
     * The 2nd and 3rd arguments are to be used in conjuction, as the data parameter
     * acts as a dummy object which is going to be duplicated as a new object of the
     * data member of the list node struct.
     * The duplicate function is responsible for allocating a new object and 
     * assigning the values of source to destination.
     * Return values:
     *      [*] On success,  0 is returned
     *      [*] On failure,  -1 is returned
     */
    int dll_insert_at_front(List, void*, void* (*)(void*));
    /*
     * Function responsible for inserting an element into the list keeping the list
     * sorted by a comparison defined by the user with a function called issmaller
     * Elements are going to be presented in ascending order starting from the head
     * Return values:
     *      [*] On success,  0 is returned
     *      [*] On failure,  -1 is returned
     */
    int dll_insert_sorted(List, void*, int (*)(void*, void*),
            void* (*)(void*));
    /*
     * Inserts the element `data` before the `key` element provided. If the key is 
     * not found -1 is returned.
     * Return values:
     *      [*]: On success, 0 is returned
     *      [*]: On error or `on key not found`, -1 is returned
     */
    int dll_insert_before(List, void*, void* (*)(void*), void*,
            int (*)(void*, void*));
    /*
     * Inserts the element `data` after the `key` element provided. If the key is 
     * not found -1 is returned.
     * Return values:
     *      [*]: On success, 0 is returned
     *      [*]: On error or `on key not found`, -1 is returned
     */
    int dll_insert_after(List, void*, void* (*)(void*),
            void*, int (*)(void*, void*));
    /*
    * Function that enables accessing data at the list, identified by the 2nd
    * argument, with an is_equal type function as 3rd argument
    * Return values:
    *      [*] On success, the object is returned
    *      [*] On element not found or on error, NULL is returned
    */
    void* dll_edit_data(List, void*, int (*)(void*, void*));
    /*
     * Function that returns a copy of the data located at the front (Head) of 
     * the list, if getCopy option is true, or the actual data if the option is
     * set to 0 (false)
     */
    const void* dll_get_front(List, void* (*)(void*), int);
    /*
     * Function that returns a copy of the data located at the back (Tail) of 
     * the list, if getCopy option is true, or the actual data if the option is
     * set to 0 (false)
     */
    const void* dll_get_back(List, void* (*)(void*), int);
    /*
     * Function that is responsible for copying src list to dest list
     * Dest list must be initialized and empty
     * Return values:
     *      [*] On success, 0 is returned
     *      [*] On failure, -1 is returned
     *      [*] On destination list not empty, 2 is returned
     *      [*] On empty source list, 1 is returned
     */
    int dll_copy(List, List, void* (*)(void*), void (*)(void*));
    /*
     * Function responsible for appending `list b` to `list a`
     * Upon return, the second list pointer (a.k.a. List) is going to be freed
     * and nullified, so that it cannot longer be used
     */
    void dll_append(List, List*);
    /*
     * Function responsible for deleting the element that contains the `key` 
     * given as a 2nd parameter
     * Also, two pointers to functions needed, the 1st for identifying the 
     * correct element and the second one for freeing it
     * Return values:
     *      [*] On success,             0 is returned
     *      [*] On element not found,   1 is returned
     *      [*] On error,               -1 is returned
     */
    int dll_delete(List, void*, int (*)(void*, void*), void (*)(void*));
    /*
     * Deletes the tail element of the list
     */
    void dll_delete_back(List, void (*)(void*));
    /*
     * Deletes the head element of the list
     */
    void dll_delete_front(List, void (*)(void*));
    /*
     * Function responsible for freeing all the allocated memory
     */
    void dll_destroy(List*, void (*)(void*));
    /*
     *  Function responsible for allocating a new Iterator object
     *  assigning it to the head of the list and then returning its id 
     *  Return values:  
     *      [*] On success, the ID of the Iterator is returned 
     *      [*] On failure, -1 is returned
     */
    IteratorID dll_iteratorRequest(List);
    /*
     *  Function responsible for setting the iterator with ID iterID 
     *  to point to the head of the list
     *  Return values:
     *      [*] On success, 0 is returned
     *      [*] On failure, -1 is returned
     */
    int dll_iteratorBegin(List, IteratorID);
    /*
     *  Function responsible for setting the iterator with ID iterID 
     *  to point to the tail of the list
     *  Return values:
     *      [*] On success, 0 is returned
     *      [*] On failure, -1 is returned
     */
    int dll_iteratorEnd(List, IteratorID);
    /*
     *  Function responsible for returning the Object into the node
     *  pointed by the iterator
     *  Return values:
     *      [*] On success, the object is returned
     *      [*] On failure, NULL is returned
     */
    void* dll_iteratorGetObj(List, IteratorID);
    /*
     *  Function responsible for setting the iterator to the next node
     *  If by advancing, the iterator is requested to point after the tail
     *  of the list, 1 is returned
     *  Return values:
     *      [*] On success, 0 is returned
     *      [*] On failure, -1 is returned
     *      [*] On the case described above, 1 is returned
     */
    int dll_iteratorNext(List, IteratorID);
    /*
     *  Function responsible for setting the iterator to the previous node
     *  If by requesting the previous node, the iterator points before the head
     *  of the list, 1 is returned
     *  Return values:
     *      [*] On success, 0 is returned
     *      [*] On failure, -1 is returned
     *      [*] On empty list, 1 is returned to indicate invalidation of 
     *          iterators
     *      [*] On the case described above, 2 is returned
     */
    int dll_iteratorPrev(List, IteratorID);
    /*
     * Function that acts both as a copy constructor and copy function
     * When you need copy constructor functionality, dest IteratorID must be 
     * NULL, and this function will allocate a new iterator setting it 
     * to point to the node that src Iterator points
     * When you need simple copy functionality, the function will copy the
     * address of the node that src Iterator points to the node of dest Iterator 
     * Return values:
     *      [*] On success, 0 is returned
     *      [*] On failure, -1 is returned
     *      [*] On empty list, 1 is returned to indicate the invalidation of the
     *          iterators
     *      [*] On iteratorIdxOutOfBounds error, 2 is returned
     * 
     */
    int dll_iteratorCopy(List, const IteratorID, IteratorID*);
    /*
     * Function responsible for deleting the current node pointed by the iterator
     * After the deletion the iterator points to the next element of the list
     * (towards the end). If the element to be destroyed is the last element of the
     * list, which means that the list will be empty, all the iterators are 
     * invalidated
     * Return values:
     *         [*] On success, 0 is returned
     *         [*] On failure, -1 is returned
     *         [*] On empty list, 1 is returned to indicate invalidation of 
     *             iterators
     */
    int dll_iteratorDeleteCurrentNode(List, IteratorID, void (*)(void*));
    /*
     *  Function responsible for deleting the iterator pointed by iterID
     *  Return values:
     *      [*] On success, 0 is returned
     *      [*] On failure, -1 is returned
     */
    int dll_iteratorDelete(List, IteratorID);
    /*
     *  Function responsible for deleting all iterators 
     *  Return values:
     *      [*] On success, 0 is returned
     *      [*] On failure, -1 is returned
     */
    int dll_iteratorDeleteAll(List);
    


#ifdef	__cplusplus
}
#endif

#endif	/* DOUBLYLINKEDLIST_ADT_H */
