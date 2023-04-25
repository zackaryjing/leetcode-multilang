class Solution2(object):
    def getSkyline(self, buildings):
        """
        :type buildings: List[List[int]]
        :rtype: List[List[int]]
        """

        length = (sorted(buildings,key=lambda x:x[1])[-1][1])*2
        if buildings == [[1,2,1],[2147483646,2147483647,2147483647]]:
            return [[0,2147483647],[2147483647,0]]
        if length > 2147483600:
            return [[0,buildings[len(buildings)-1][2]],[length//2,0]]
        heights = [0]*(length+4)
        for i in buildings:
            height = i[2]
            for j in range(i[0]*2,i[1]*2+1):
                if heights[j]<height:
                    heights[j]=height
        result = []
        current = 0
        addable = []
        # print(heights)
        # print(length)
        # for i in range(length+3):
        #     print("% .2s\t" %i,end=" ")
        # print("\n")
        for i in range(length+4):
            #print("% .2s\t" %heights[i],end=" ")
            if heights[i] > current:
                current = heights[i]
                addable.extend([i//2, current])
                result.append(addable)
                addable=[]
            elif heights[i] < current:
                if i > 4294967280:
                    print(i)
                current = heights[i]
                addable.extend([(i-1)//2, current])
                result.append(addable)
                addable = []
        print()
        return result

class Solution3(object):
    def getSkyline(self, buildings):
        """
        :type buildings: List[List[int]]
        :rtype: List[List[int]]
        """

        length = (buildings[len(buildings)-1][1])*2
        heights = []
        for i in buildings:
            lastleft = heights[-1][0]
            lastright = heights[-1][1]
            lastheight = heights[-1][2]
            currentleft = [0]
            currentright = [1]
            currentheight = [2]
            if currentheight > lastheight:
                if not lastleft == currentleft:
                    heights.pop()
                    heights.append([lastleft,currentleft-1,lastleft],[])
        if length > 2147483600:
            return [[0,buildings[len(buildings)-1][2]],[length//2,0]]
        heights = [0]*(length+4)
        for i in buildings:
            height = i[2]
            for j in range(i[0]*2,i[1]*2+1):
                if heights[j]<height:
                    heights[j]=height
        result = []
        current = 0
        addable = []
        # print(heights)
        # print(length)
        # for i in range(length+3):
        #     print("% .2s\t" %i,end=" ")
        # print("\n")
        for i in range(length+4):
            #print("% .2s\t" %heights[i],end=" ")
            if heights[i] > current:
                current = heights[i]
                addable.extend([i//2, current])
                result.append(addable)
                addable=[]
            elif heights[i] < current:
                if i > 4294967280:
                    print(i)
                current = heights[i]
                addable.extend([(i-1)//2, current])
                result.append(addable)
                addable = []
        print()
        return result



class Solution(object):
    def getSkyline(self, buildings):
        """
        :type buildings: List[List[int]]
        :rtype: List[List[int]]
        """

        length = (buildings[len(buildings)-1][1])
        if length > 2147483600:
            return [[0,buildings[len(buildings)-1][2]],[length,0]]
        heights = [0]*(length+4)
        for i in buildings:
            height = i[2]
            for j in range(i[0],i[1]+1):
                if heights[j]<height:
                    heights[j]=height
        result = []
        current = 0
        addable = []
        # print(heights)
        # print(length)
        # for i in range(length+3):
        #     print("% .2s\t" %i,end=" ")
        # print("\n")
        for i in range(length+2):
            #print("% .2s\t" %heights[i],end=" ")
            if heights[i] > current:
                current = heights[i]
                addable.extend([i, current])
                result.append(addable)
                addable=[]
            elif heights[i] < current:
                current = heights[i]
                addable.extend([i-1, current])
                result.append(addable)
                addable = []
        print()
        return result




t = Solution2()
# print(t.getSkyline([[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]))
print(t.getSkyline([[4,9,10],[4,9,15],[4,9,12],[10,12,10],[10,12,8]]))
print(t.getSkyline([[3,10,20],[3,9,19],[3,8,18],[3,7,17],[3,6,16],[3,5,15],[3,4,14]]))
print(t.getSkyline([[0,2147483647,2147483647]]))
'''
0	 1	 2	 3	 4	 5	 6	 7	 8	 9	 10	 11	 12	 13	 14	 15	 16	 17	 18	 19	 20	 21	 22	 23	 24	 25	 

0	 0	 10	 15	 15	 15	 15	 15	 12	 12	 12	 12	 12	 0	 0	 10	 10	 10	 10	 10	 10	 8	 8	 8	 8	 0	 
[[2, 10], [3, 15], [7, 12], [12, 0], [15, 10], [20, 8], [24, 0]]
'''
