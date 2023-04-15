// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
struct SYM {
  char ch;
  int prior;
};
template<typename T, int size>
class TPQueue {
 private:
    int head;
    int tail;
    int fullness;
    T arr[size];
    void QueueSort() {
        if (this->fullness < 2) {
            return;
        }
        for (int i = head + fullness; i > head; i--) {
            if (arr[(i - 1) % size].pr <= arr[(i) % size].pr) {
                T temp = arr[(i - 1) % size];
                arr[(i - 1) % size] = arr[(i) % size];
                arr[(i) % size] = temp;
            }
        }
    }
 public:
    TPQueue() :head(0), tail(0), fullness(0) {}
    void push(const T& value) {
        if (fullness == size) {
            throw std::string("Already full Queue");
            return;
        }
        arr[(tail++) % size] = value;
        QueueSort(value);
        fullness++;
        return;
    }
    const T& pop() {
        fullness--;
        SYM val = arr[head % size];
        return arr[(head++) % size];
    }
};



#endif  // INCLUDE_TPQUEUE_H_
