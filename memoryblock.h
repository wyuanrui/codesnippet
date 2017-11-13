#include <sys/types.h>
#include <iostream>

class MemoryBlock {
public:
    explicit MemoryBlock(size_t length) : _length(length), _data(new int[length]) {
        std::cout << "In MemoryBlock(size_t). length = " << length << "." << std::endl;
    }
    ~MemoryBlock() {
        std::cout << "In ~MemoryBlock()." << std::endl;
        if (nullptr != _data) {
            delete[] _data;
        }
    }
    MemoryBlock(const MemoryBlock& other) {
        std::cout << "In MemoryBlock(const MemoryBlock&). length = " << other._length << "." << std::endl;

        _length = other._length;
        _data = new int[_length];

        std::copy(other._data, other._data + other._length, _data);
    }

    MemoryBlock(MemoryBlock&& other) {
        std::cout << "In MemoryBlock(MemoryBlock&&). length = " << other._length << "." << std::endl;

        _length = other._length;
        _data = other._data;

        other._length = 0;
        other._data = nullptr;
    }

    MemoryBlock& operator=(const MemoryBlock& other) {
        std::cout << "In MemoryBlock operator=(const MemoryBlock&). length = " << other._length << "." << std::endl;

        if (this != &other) {
            delete[] _data;

            _length = other._length;
            _data = other._data;

            std::copy(other._data, other._data + other._length, _data);
        }

        return *this;
    }

    MemoryBlock& operator=(MemoryBlock&& other) {
        std::cout << "In MemoryBlock operator=(MemoryBlock&&). length = " << other._length << "." << std::endl;

        if (this != &other) {
            delete[] _data;

            _length = other._length;
            _data = other._data;

            other._length = 0;
            other._data = nullptr;
        }

        return *this;
    }
private:
    size_t _length;
    int* _data;
};
