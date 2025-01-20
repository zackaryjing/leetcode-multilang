class Heap {
  List<int> _heap = [];
  bool Function(int, int) greater;

  Heap(this.greater) {}

  void insert(int val) {
    _heap.add(val);
    int index = _heap.length - 1;
    while (index != 0) {
      int parent = _heap[(index - 1) ~/ 2];
      if (greater(val, parent)) {
        _heap[index] = parent;
        _heap[(index - 1) ~/ 2] = val;
        index = (index - 1) ~/ 2;
      } else {
        break;
      }
    }
    // print(_heap);
  }

  bool empty() {
    return _heap.isEmpty;
  }

  int size() {
    return _heap.length;
  }

  int pop() {
    assert(_heap.length != 0, "No element left! ");
    int popped_element = _heap[0];
    int n = _heap.length - 2;
    int last_elem = _heap.last;
    _heap[0] = last_elem;
    int index = 0;
    while (index <= n) {
      // print(index);
      int first = (index + 1) * 2 - 1;
      // print("first $first");
      int second = (index + 1) * 2;
      // print("second $second");
      int bigger = first;
      if (second <= n) {
        if (greater(_heap[second], _heap[first])) {
          bigger = second;
        }
      } else if (first <= n) {} else {
        break;
      }
      // print("bigger $bigger");

      if (!greater(_heap[index], _heap[bigger])) {
        _heap[index] = _heap[bigger];
        _heap[bigger] = last_elem;
        index = bigger;
      } else {
        break;
      }
    }
    _heap.removeLast();
    // print(_heap);

    return popped_element;
  }

  int operator [](int index) {
    return _heap[index];
  }

}
class MedianFinder {
  Heap small_heap = Heap((a, b) => a > b);
  Heap big_heap = Heap((a, b) => a < b);
  int n = 0;

  MedianFinder() {

  }

  void addNum(int num) {
    if (small_heap.empty() || num <= small_heap[0]) {
      small_heap.insert(num);
      if (big_heap.size() + 1 < small_heap.size()) {
        big_heap.insert(small_heap[0]);
        small_heap.pop();
      }
    } else {
      big_heap.insert(num);
      if (big_heap.size() > small_heap.size()) {
        small_heap.insert(big_heap[0]);
        big_heap.pop();
      }
    }
  }

  double findMedian() {
    if (small_heap.size() > big_heap.size()) {
      return small_heap[0].toDouble();
    }
    return (small_heap[0] + big_heap[0]) / 2.0;
  }
}

void main() {
  Heap heap = Heap((a, b) => a < b);
  heap.insert(12);
  heap.insert(1);
  heap.insert(3);
  heap.insert(13);
  heap.insert(10);
  heap.insert(15);
  heap.insert(7);
  heap.insert(19);
  heap.pop();
  heap.pop();
  heap.pop();
  heap.pop();
  heap.pop();
  heap.pop();
  heap.pop();
  heap.pop();
}
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = MedianFinder();
 * obj.addNum(num);
 * double param2 = obj.findMedian();
 */

/*
大顶堆测试
  MaxHeap heap = MaxHeap();
  heap.insert(12);
  heap.insert(1);
  heap.insert(3);
  heap.insert(13);
  heap.insert(10);
  heap.insert(15);
  heap.insert(7);
  heap.insert(19);
  heap.pop();
  heap.pop();
  heap.pop();
  heap.pop();
  heap.pop();
  heap.pop();
  heap.pop();
  heap.pop();

*/
