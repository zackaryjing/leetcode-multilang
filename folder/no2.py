from collections import defaultdict
class Solution:
    def adventureCamp(self, expeditions: list[str]) -> int:
        vis = defaultdict(int)
        ans = 0
        posreturn = 0
        for j in expeditions[0].split("->"):
            # print(j)
            vis[j] = 1

        for i in range(1,len(expeditions)):
            path = expeditions[i]
            newvis = 0
            for j in path.split("->"):
                # print(j,vis[j])
                if j != "":
                    if vis[j] == 0:
                        newvis += 1
                        vis[j] = 1
            if newvis > ans:
                ans = newvis
                posreturn = i
            # print(newvis)
            # print("-"*40)
        return posreturn if posreturn != 0 else -1


t = Solution()
print(t.adventureCamp(["leet->code","leet->code->Campsite->Leet","leet->code->leet->courier"]))
print(t.adventureCamp(["Alice->Dex","","Dex"]))
print(t.adventureCamp(["","Gryffindor->Slytherin->Gryffindor","Hogwarts->Hufflepuff->Ravenclaw"]))
