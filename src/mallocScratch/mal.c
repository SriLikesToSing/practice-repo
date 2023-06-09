
//implimenting malloc from scratch? (idk the difficulty scale lol)


/*research
  - https://web.stanford.edu/class/cs101/bits-bytes.html

  - the reason it's called an 8-bit computer is because of the fact that there are 8 bits and each 
  bit can either be a 0 or a 1. Therefore each there are 2^8 total arrangments or 256 possible bytes.

  an 8 bit computer does not necessarily have only 8 bits of storage. Each "register" has 9 bits of storage

  a pointer fundamentally holds the address of a variable. it is denoted by putting an * in front of a variable.
 
  how the fuck does malloc work? 

	- void *malloc(size_t size);
		- this function takes an input nuumber of bytes and returns a pointer 
			to a block of memory of that size.

  how does malloc assign memory?
  	- virtual memory vs physical memory.
		- every single process has its own private virtual memory that gives 
			the process the perceptions of contiguous memory.
				-> this virtual memory is then translated to location memory in physical memory
					through each process's page table.


	- all variables allocated by malloc is stored in heap memory
		- what is heap memory?
			- https://stackoverflow.com/questions/2308751/what-is-a-memory-heap

			heap memory:
				- heap memory is a portion of the memomry where dynamically allocated memory resides 
					- memory allocated by malloc

				- Memory will remain in the heap until the memory is free'd or if the program 
					itself terminates

					- if the pointers to memory in program are lost (which means that you cannot access the location on the heap)
						- this is called a memory leak.
						- the variables are still defined and there until the program instance gets terminated by the operating system.

			stack memory:
				- stack memory is where local variables (local function for ex.) get precisely allocated and dispursed

	- srbk() return s		
 
*
*/

#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

void _freeSimple(void *ptr){
	if(!ptr){
		return;
	}

	struct block_meta* block_ptr = get_block_ptr(ptr);
	assert(block_ptr->free == 0);
	assert(block_ptr->magic == 0x77777777 || block_ptr-> magic = 0x12345678);
	block_ptr->free =1;
	block_ptr->magic = 0x5555555;


}

//*malloc, free, and *realloc

//super simple malloc implimentation

//https://moss.cs.iit.edu/cs351/slides/slides-malloc.pdf
/*
void *_mallocOne(int size){

	if(size <= 0){
		return NULL;
	}

	if(!global_base){
		block = request_space(NULL< size);
	}
	void *p = sbrk(0);
	void *request = sbrk(size);
	if(request == (void*) -1){
		//failed allocation
		return NULL;
	}else{
		assert(p == request);
		return p;
	}


}
*/

#define ALIGNMENT 8
#define ALIGN(size) (((size) + (ALIGNMENT-1)) & -(ALIGNMENT-1))
#define SIZE_T_SIZE (ALIGN(sizeof(size_t))) //header size

void *find_fit(size_t size){
	size_t *header = heap_start();
	while(header < heap_end()){
		if(!(*header & 1) && *header >= size)
			return header;
		header = (char *)header + (*header & -1L);
	}
	return NULL;
}

void *malloc(size_t size){
	size_t blk_size = ALIGN(size + SIZE_T_SIZE):
	size_t *header = find_fit(blk_size);
	if(header){
		*header = *header | 1;
	}else{
		header = sbrk(blk_size);
		*header = blk_size | 1;
	}
	return (char *)header + SIZE_T_SIZE:
}

int main(void){

	for(int i=1; i<=32; i+=2){
		printf("ALIGN(%d) = %d\n", i, ALIGN(i));
	}


	return 0;
}





















