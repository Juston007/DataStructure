#include "stdio.h"
#include "HashTable.h"

int main(){
    unsigned int address = hash("hello world!");
    printf("key %s address %x", "hello", address);
    return 0;
}