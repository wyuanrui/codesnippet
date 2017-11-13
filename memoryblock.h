#include <sys/types.h>
#include <iostream>

class MemoryBlock {
public:
    explicit MemoryBlock(size_t length) : _length(length), _data(new int[length]) {
        std::cout << "In MemoryBlock(size_t). length = " << length << "." << std::endl;
    }
private:
    size_t _length;
    int* _data;
};
