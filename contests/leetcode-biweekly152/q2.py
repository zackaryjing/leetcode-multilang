# problem: design-spreadsheet
from typing import *


class Spreadsheet:

    def __init__(self, rows: int):
        self.data = [[0] * rows for _ in range(26)]

    def setCell(self, cell: str, value: int) -> None:
        self.data[ord(cell[0]) - ord('A')][int(cell[1:]) - 1] = value

    def resetCell(self, cell: str) -> None:
        self.data[ord(cell[0]) - ord('A')][int(cell[1:]) - 1] = 0

    def get(self, cell: str) -> int:
        return self.data[ord(cell[0]) - ord('A')][int(cell[1:]) - 1]

    def getValue(self, formula: str) -> int:
        formula = formula.strip("=")
        formula = formula.split("+")
        if formula[0][0].isalpha():
            first = self.get(formula[0])
        else:
            first = int(formula[0])
        if formula[1][0].isalpha():
            second = self.get(formula[1])
        else:
            second = int(formula[1])
        return first + second


def main():
    test = Spreadsheet(20)
    test.setCell("A15", 20)
    print(1)
    test.setCell("A12", 21)
    print(2)
    print(test.getValue("=A1+A12"))
    print(3)
    print(test.getValue("=A15+A12"))
    print(test.getValue("=A15+3"))


if __name__ == "__main__":
    main()
