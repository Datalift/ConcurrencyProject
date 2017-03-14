/*
 * MemoryManager.h
 *
 *  Created on: 04/03/2012
 *      Author: Llopis
 *      Translated: Sergio Galvez Rojas
 */

#ifndef MEMORYMANAGER_H_
#define MEMORYMANAGER_H_

	const unsigned MAX = 99;

	typedef struct T_Node* T_handler;

	struct T_Node {
			unsigned start;
			unsigned end;
			T_handler next;
		};

// Creates the required structure to manage the available memory
	void Create(T_handler* phandler){
		T_handler ptr = (T_handler)malloc(sizeof(struct T_Node));
		ptr -> start = 0;
		ptr -> end = MAX;
		ptr -> next = NULL;
		(*phandler) = ptr;
	}

// Frees the required structure
	void Destroy(T_handler* handler){
	    while((*handler) -> next != NULL){
	      free(handler);
	      (*handler) = (*handler) -> next;
	    }
	  }
/* Returns in "ad" the memory address where the required block of memory with length "size" starts.
 * If this operation finishes successfully then "ok" holds a TRUE value; FALSE otherwise.
 */
	void Allocate(T_handler* phandler, unsigned size, unsigned* ad, unsigned* ok);

/* Frees a block of memory with length "size" which starts at "ad" address.
 * If needed, can be assumed to be a previous allocated block
 */
	void Deallocate(T_handler* phandler, unsigned size ,unsigned ad);

/* Shows the current status of the memory */
	void Show (T_handler phandler);


#endif /* MEMORYMANAGER_H_ */
