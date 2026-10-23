from typing import Any
import random

class Quicksort:
    def __init__(self, L : List[Any])->None:
        self.ArrayList = L
    def startquick(self):
        self.quicksort(0, len(self.ArrayList)-1)
    def quicksort(self,low:int, high : int):
        if(low < high):
            self.pi = self.partition(low, high)
            self.quicksort(low, self.pi - 1)
            self.quicksort( self.pi + 1, high)
            
    def partition(self, low: int, high: int) -> int:
        pivot = self.ArrayList[low]
        k = high

        for i in range(high, low, -1):
            if self.ArrayList[i] > pivot:
                self.ArrayList[i], self.ArrayList[k] = (
                    self.ArrayList[k],
                    self.ArrayList[i]
                )
                k -= 1

        self.ArrayList[low], self.ArrayList[k] = (
            self.ArrayList[k],
            self.ArrayList[low]
        )

        return k
    def display(self):
        print(self.ArrayList)


l = [random.randint(1, 10)for i in range(10)]

#for testing the code 
# q = Quicksort(l)
# q.display()
# q.startquick()
# q.display()
         