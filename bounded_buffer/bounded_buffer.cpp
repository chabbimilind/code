#include<stdint.h>
#include<assert.h>

class BoundedBuffer {
    int capacity;
    int64_t head, tail;
    int * buffer;
public:
    BoundedBuffer(uint32_t sz):capacity(sz), head(0), tail(-1) {
        buffer= new int[sz];
    }
    ~BoundedBuffer() {
        delete buffer;
    }
    
    bool Enq(const int data) {
        // invariant num_elements = tail - head + 1.
        if (tail - head + 1 == capacity) {
            return  false; // queue full
        }
        tail ++;
        buffer[tail % capacity] = data;
        return  true;
    }
    
    bool Deq(int &data) {
        // invariant num_elements  = tail - head + 1.
        // ==> head > tail means queue empty
        if (head > tail) {
            return  false; // empty
        }
        data = buffer[head % capacity];
        head ++;
        return  true;
    }
};

int main() {
    auto b = BoundedBuffer(1);
    int x;
    assert(false == b.Deq(x));
    assert(true == b.Enq(200));
    assert(false == b.Enq(300));
    assert(true == b.Deq(x)) ;
    assert(200 == x);
    assert(false == b.Deq(x));
    assert(true == b.Enq(300));
    assert(false == b.Enq(500));
    assert(true == b.Deq(x)) ;
    assert(300 == x);
    return 0;
}

