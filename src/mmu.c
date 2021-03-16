struct table_descriptor_stage1 L1table[512] __attribute__((aligned(4096)));

struct page_descriptor_stage1 L2table[512] __attribute__((aligned(4096)));

/*
 * 
 * 
 *  39				30 29		    	21 20				0
 *   |----------------|-------------------|-------------------|
 * 	 |	L1 table		L2 table entry  	Offset			  |
 * 	 |--------------------------------------------------------|
 * 	9 bits for each thing
 * 
 */

void mapPages(void *vaddr, void *paddr){
	unsigned int L2tableIndex = (vaddr >> 21) & 0x1ff;
	unsigned int L1tableIndex = (vaddr >> 30) & 0x1ff;
	
	L1table[L1tableIndex].type = 3;
	L1table[L1tableIndex].next_lvl_table = L2table>>12;
	
	L2table[L2tableIndex].attrindex = 0; //normal memory, not memory mapped IO
	L2table[L2tableIndex].type = 0; //Pointing to memory page
	L2table[L2tableIndex].sh = 3; //inner sharable
	L2table[L2tableIndex].ap = 0; //Access permission,
	L2table[L2tableIndex].af = 1; // ??
	L2table[L2tableIndex].output_addr = paddr >> xxxxx; //Ouput address//point to physical address of block//well have to shift it
}
