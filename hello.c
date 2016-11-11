/********************************************************************************
 * 45 --> E ~~~~~~ 4c --> L ~~~~~~ 46 --> F
 
              hypothetical layout
              +-----------------+
         +----| ELF File Header |----+
         |    +-----------------+    |
         v                           v
 +-----------------+      +-----------------+
 | Program Headers |      | Section Headers |
 +-----------------+      +-----------------+
      ||                               ||
      ||                               ||
      ||                               ||
      ||   +------------------------+  ||
      +--> | Contents (Byte Stream) |<--+
           +------------------------+
 

              hypothetical layout
              +-----------------+
              | ELF File Header |
              +-----------------+ 
              +-----------------+
              | program header  | 
              |     table       |
              +-----------------+ 
              +-----------------+
              |     .text       |
              +-----------------+ 
              +-----------------+
              |     .rodata     |
              +-----------------+ 
              +-----------------+
              | section header  | 
              |     table       |
              +-----------------+ 
 
 * ///////////////////////////////////////////////////////////////////////////////
 * 
 * Class:                   64 bit architecture
 * Data:                    Least Significant Bit (LSB or little endian)
 * ABI:                     application binary interface 
 * Type:                    this is REL, others are DYN (shared object file) or EXEC
 * Entry point address:     location of first part to be executed at runtime


 * Section Headers: post gcc linkage [gcc -o hello hello.c] 
 *      .interp                         holding pathname of interpreter 
 *      .gnu.hash                       dynamic hash table
 *      .dynsym                         imported/exported symbol table
 *      .dynstr                         dynamic names table
 *      .init, .plt, .fini              code sections
 *      .text                           code
 *      .rela.text, .rela               relocation tables
 *      .data, .bss, .rodata            data sections (ro = read only)
 *      .got, .dynamic, .plt            dynamic binaries 
 *      .comment                        extra, misc.
 *      .symtab                         symbol tables
 *      .shstrtab                       section string tables (name of each section)
 *      .strtab                         string tables

 * Definitions:
 * - linking: functions from libraries 
 *      - dynamic: linked at run-time
 *      - static: linked at compile-time 
 * 

 * Replacement of Main: 
        smashed: 	Entry Address (e_entry): 0x004004e0
        hello: 		Entry Address (e_entry): 0x004004f0
        
        Dump of assembler code for function _start:
        ==>0x00000000004004f0 <+0>:     xor    %ebp,%ebp
        
        ∴asm 
        00000000004005e0 <+0>:     xor    %ebp,%ebp
        	//should become// 
        00000000004005f0 <+0>:     xor    %ebp,%ebp



 * References: 
 * - https://linux-audit.com/elf-binaries-on-linux-understanding-and-analysis/
 * - http://fluxius.handgrep.se/2011/10/20/the-art-of-elf-analysises-and-exploitations/
 * - http://www.cs.stevens.edu/~jschauma/810/elf.html
 * - http://stackoverflow.com/questions/18633880/how-to-hack-an-elf-file-to-call-other-function-rather-main
 * - https://jvns.ca/blog/2014/09/06/how-to-read-an-executable/
 * - http://imgur.com/a/JEObT
 * - http://stackoverflow.com/questions/8455135/gdb-changing-the-assembly-code-of-a-running-program
 * 
********************************************************************************/
 
#include<stdio.h>

int testGlobal = 1; 

int main(void)
{
    printf("Hello World \n");
    printf("%d", testGlobal);

}