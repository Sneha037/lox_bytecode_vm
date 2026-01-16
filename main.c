#include <stdlib.h>
#include "common.h"

#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char* argv[])
{
    initVM();
    Chunk chunk;
    initChunk(&chunk);

   /*chunk.capacity = 8;
    chunk.count = 3;
    chunk.code = malloc(sizeof(uint8_t) * 5);
    */
    
    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);
    writeChunk(&chunk, OP_RETURN, 123);
   // writeChunk(&chunk, OP_CONSTANT);
   // writeChunk(&chunk, constant);
   // writeChunk(&chunk, OP_RETURN);

   chunk.code[0] = OP_CONSTANT;
   chunk.code[1] = 1.2;
   chunk.code[2] = OP_RETURN;

    disassembleChunk(&chunk, "test chunk");
    interpret(&chunk);
    freeVM();
    freeChunk(&chunk);
    return 0;
}