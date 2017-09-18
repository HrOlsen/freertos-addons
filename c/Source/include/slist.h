
#ifndef SLIST_H_
#define SLIST_H_


/**
 *  The singly linked list structure.
 *  This is designed to be embedded within your data 
 *  structure(s).
 */
typedef struct SlNode_t_ {

    struct SlNode_t_ *Next;

} SlNode_t;


/**
 *  Macro to initialize a list head.
 *  @param _head The list head.
 */
#define SlInitHead(_head) \
    (_head)->Next = NULL;


/**
 *  Add a node to the list head.
 *  Runs in O(1) time.
 *
 *  @param Head Existing list head.
 *  @param Node The node you are adding to the head.
 */
#define SlAddNodeToHead(_head, _node) \
    SlInsertNodeAfter(_head, _node)


/**
 *  Add a node to the list tail.
 *  Runs in O(n) time.
 *  
 *  @param Head Existing list head.
 *  @param Node The node you are adding to the tail.
 */
void SlAddNodeToTail(   SlNode_t *Head,
                        SlNode_t *Node);


/**
 *  Removes the node from the list head.
 *  Runs in O(1) time.
 *
 *  @param Head Existing list head.
 *  @return The node removed, or NULL for an empty list.
 */
SlNode_t *SlRemoveNodeFromHead(SlNode_t *Head);


/**
 *  Removes the node from the list tail.
 *  Runs in O(n) time.
 *  
 *  @param Head Existing list head.
 *  @return The node removed, or NULL for an empty list.
 */
SlNode_t *SlRemoveNodeFromTail(SlNode_t *Head);


/**
 *  Check if the list is empty.
 *
 *  @return true if the list is empty, false otherwise.
 */
#define SlIsListEmpty(_head) \
    ((_head)->Next == NULL)


/**
 *  Inserts a new node into the list right after the marker element.
 *  Runs in O(1) time.
 *
 *  @param marker Node you are inserting after. Cannot be NULL.
 *  @param n The node you are inserting. Cannot be NULL.
 */
void SlInsertNodeAfter( SlNode_t *Marker,
                        SlNode_t *Node);


/**
 *  Inserts a new node into the list right before the marker element.
 *  Runs in O(n) time.
 *
 *  @param head Existing list head.
 *  @param marker Node you are inserting after. Cannot be NULL.
 *  @param n The node you are inserting. Cannot be NULL.
 */
void SlInsertNodeBefore(SlNode_t *Head, 
                        SlNode_t *Marker, 
                        SlNode_t *Node);


/**
 *  Removes a node from the list.
 *  Runs in O(n) time.
 *
 *  @param head Existing list head.
 *  @param n The node you are removing.
 */
void SlRemoveNode(  SlNode_t *Head, 
                    SlNode_t *Node);


/**
 *  Given here in case you do not have an equivalent macro.
 *  @param _type The structure type.
 *  @param _field The name of the field you want the offset to.
 *  @returns The offset into _type where _field starts, in bytes.
 */
#ifndef OFFSET_OF
#define OFFSET_OF(_type, _field)    \
    ((size_t)&((_type *)0)->_field)
#endif


/**
 *  Given here in case you do not have an equivalent macro.
 *  @param _address The real address of the _field you have.
 *  @param _type The structure type.
 *  @param _field The name of the field you want the offset to.
 *  @returns A typed pointer to the structure containing the _field 
 *  at _address.
 */
#ifndef CONTAINING_RECORD
#define CONTAINING_RECORD(_address, _type, _field)  \
    ((_type *)((unsigned char *)(_address) - OFFSET_OF(_type, _field)))
#endif


/**
 *  Macro to ease walking through all of the nodes in a list.
 *  @param _head The List head, cannot be NULL.
 *  @param _node An undefined symbol that will be defined by the macro.
 */ 
#define SlForEachNode(_head, _node) \
    for (SlNode_t *_node = _head->Next; _node != NULL; _node = _node->Next)


#endif

