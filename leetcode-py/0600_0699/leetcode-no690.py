# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: list[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates

class Solution:
    def getImportance(self, employees: list[Employee], id: int) -> int:
        total = 0
        for i in employees:
            if i.id == id:
                # print(i.id)
                descent = i.subordinates[:]
                total += i.importance
                break
        while descent:
            # print(descent)
            for i in employees:
                if i.id in descent:
                    total += i.importance
                    descent.extend(i.subordinates)
                    descent.remove(i.id)
        return total


t = Solution()
e1 = Employee(1,5,[2,3])
e2 = Employee(2,3,[])
e3 = Employee(3,3,[])


e4 = Employee(4,1,[])
e5 = Employee(2,3,[4])
e6 = Employee(3,4,[])
print(t.getImportance([e1,e2,e3],1))
print(e1.id,e1.subordinates)
print(t.getImportance([e1,e4,e5,e6],1))
