# https://leetcode.com/problems/design-circular-queue/

class MyCircularQueue:

    def __init__(self, k: int):
        self.List = []
        self.K = k

    def enQueue(self, value: int) -> bool:
        if len(self.List) >= self.K:
            return False
        self.List.append(value)
        return True

    def deQueue(self) -> bool:
        if self.isEmpty(): return False
        self.List.pop(0)
        return True

    def Front(self) -> int:
        if self.isEmpty(): return -1
        return self.List[0]

    def Rear(self) -> int:
        if self.isEmpty(): return -1
        return self.List[len(self.List) - 1]

    def isEmpty(self) -> bool:
        return len(self.List) == 0

    def isFull(self) -> bool:
        return len(self.List) == self.K

# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()