import threading


class Foo:
    def __init__(self):
        pass
        self.a = 0

    def first(self, printFirst: 'Callable[[], None]') -> None:

        # printFirst() outputs "first". Do not change or remove this line.
        printFirst()
        self.a |= 1
        # print(self.a, "1")

    def second(self, printSecond: 'Callable[[], None]') -> None:
        # printSecond() outputs "second". Do not change or remove this line.
        # print(self.a, "2")
        while not self.a:
            pass
        if self.a:
            printSecond()
            self.a |= 2

    def third(self, printThird: 'Callable[[], None]') -> None:
        # printThird() outputs "third". Do not change or remove this line.
        while not self.a & 2:
            pass;
        if self.a & 2:
            printThird()


def printFirst():
    print("first", end="")


def printSecond():
    print("second", end="")


def printThird():
    print("third", end="")


def test():
    foo = Foo()
    t1 = threading.Thread(target=foo.first, args=(printFirst,))
    t2 = threading.Thread(target=foo.second, args=(printSecond,))
    t3 = threading.Thread(target=foo.third, args=(printThird,))

    t2.start()
    t1.start()
    t3.start()

    t1.join()
    t2.join()
    t3.join()


test()
