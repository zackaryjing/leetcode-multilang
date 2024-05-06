class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        senate = list(senate)
        while "D" in senate and "R" in senate:
            front = []
            behind = senate
            while behind:
                if behind[0] == "R":
                    behind.remove("R")
                    front.append("R")
                    if "D" in behind:
                        behind.remove("D")
                    elif "D" in front:
                        front.remove("D")
                else:
                    behind.remove("D")
                    front.append("D")
                    if "R" in behind:
                        behind.remove("R")
                    elif "R" in front:
                        front.remove("R")
            senate = front
        return "Radiant" if "R" in senate else "Dire"

t = Solution()
print(t.predictPartyVictory("RD"))
print(t.predictPartyVictory("DR"))
print(t.predictPartyVictory("RDD"))
print(t.predictPartyVictory("RRDDD"))
print(t.predictPartyVictory("RDDRD"))
