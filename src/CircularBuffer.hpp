#ifndef CIRCULAR_BUFFER_HPP
#define CIRCULAR_BUFFER_HPP

// Numeric functions: min(), max() and avg() work only with numeric types (int, float, long, etc).

template<typename T, size_t N>
class CircularBuffer {
private:
    T _data[N] = {};
    size_t _writeIndex;
    bool _isFull;

    void updateWriteIndex() {
        if(_writeIndex == N - 1) {
            _writeIndex = 0;
            _isFull = true;
            return;
        }
        ++_writeIndex;
    }
public:
    CircularBuffer() : _writeIndex(0), _isFull(false) {}

    size_t capacity() const { return N; }
    size_t size() const { return _isFull ? N : _writeIndex; }

    bool isEmpty() const { return size() == 0; }
    bool isFull() const { return _isFull; }

    void push(const T value) {
        _data[_writeIndex] = value;
        updateWriteIndex();
    }

    void reset() {
        _writeIndex = 0;
        _isFull = false;
    }

    void clear() {
        if(isEmpty())
            return;
        reset();
        for(size_t pos = 0; pos < N; ++pos)
            _data[pos] = T{};
    }

    T oldest() const {
        if (isEmpty())
            return T{};
        return _data[_isFull ? _writeIndex : 0];
    }

    T latest() const { 
        if (isEmpty())
            return T{};
        return _data[_writeIndex == 0 ? N - 1 : _writeIndex - 1];
    }

    bool contains(T value) const {
        size_t n = size();
        for (size_t pos = 0; pos < n; ++pos)
            if (_data[pos] == value)
                return true;
        return false;
    }

    T minValue() const {
        size_t n = size();
        if (n == 0)
            return T{};
        T min = _data[0];
        for (size_t pos = 1; pos < n; ++pos)
            if (_data[pos] < min)
                min = _data[pos];
        return min;
    }

    T maxValue() const {
        size_t n = size();
        if (n == 0)
            return T{};
        T max = _data[0];
        for (size_t pos = 1; pos < n; ++pos)
            if (_data[pos] > max)
                max = _data[pos];
        return max;
    }

    float avg() const {
        size_t n = size();
        if(n == 0) 
            return 0.0f;
        double sum = 0;
        for(size_t pos = 0; pos < n; ++pos)
            sum += _data[pos];
        return (float)sum / n;
    }
};
#endif
