'''
可以说，我已经写出来了拓扑排序，但问题是，我无法判断一棵树是否又环
所以结局是，我的提交只能通过20多个测试用例
我已经在这个题上画了太多时间
本质上来讲，是我的能力还不足
我甚至不知道拓扑排序，bfs是可以用循环来写的
以及python其实自带的有图和树的结构
我想等我有能力之后在来解决这个问题吧
最后有我抄的代码
'''






class Solution2(object):
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        tree = {}
        starts = []
        for i in prerequisites:
            starts.append(i[1])
            if not i[1] in tree.keys():
                tree[i[1]] = []   #获得整个树的节点
        for j in prerequisites:
            tree[j[1]].append(j[0])   #获得完整的树
        treekey = tree.keys()
        for t in prerequisites:
            if t[0] in starts:
                starts.remove(t[0])   #获得所有可能的开始节点
        result = starts[:1]
        def dfs(current):  #深度优先算法遍历整个序列
            if current in treekey:
                for eachkey in tree[current]:
                    if not eachkey in result:
                        result.append(eachkey)
                for eachkey in tree[current]:
                    dfs(eachkey)
            else:
                return
        if starts == [] and len(prerequisites) != 0:  #对应[[1,0],[0,1]]这种
            return []
        elif starts == [] and len(prerequisites) == 0:
            return [i for i in range(numCourses)]
        dfs(starts[0])
        if len(result) < numCourses:
            print(len(result),numCourses)
            print(9)
            for j in range(numCourses):
                if not j in result:
                    result.append(j)
        return result


class Solution(object):

    def findOrder(self, numCourses, prerequisites):
        key = 0
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        def byson(key):
            try:
                return len(tree[key])
            except:
                return 0

        tree = {}
        starts = []
        ends = []
        for i in prerequisites:
            starts.append(i[1])
            ends.append(i[0])
            if not i[1] in tree.keys():
                tree[i[1]] = []   #获得整个树的节点
        end = False
        if starts != []:
            end = True
        for j in prerequisites:
            tree[j[1]].append(j[0])   #获得完整的树
        for t in prerequisites:
            while t[0] in starts:
                starts.remove(t[0])
            while t[1] in ends:
                ends.remove(t[1])
        for x in starts:
            if starts.count(x)>1:
                for k in range(starts.count(x)-1):
                    starts.remove(x)
                #获得所有可能的开始节点
        for y in starts:
            if starts.count(y)>1:
                for k in range(starts.count(y)-1):
                    starts.remove(y)


        if starts != []:
            tree[-1] = starts

        elif end:
            return []
        treekey = tree.keys()
        result = []
        path = []
        def dfs(current):  #深度优先算法遍历整个序列

            if not current in path:
                path.append(current)
                #print(path)
            else:
                # print(current)
                return True
            if current in treekey:
                cache = []
                for eachkey in tree[current]:
                    if not eachkey in result:
                        cache.append(eachkey)
                cache.sort(key=byson,reverse=True)

                result.extend(cache)
                for eachkey in tree[current]:
                    t = dfs(eachkey)
                    if t:
                        # print("wrong")
                        return
            else:
                return

        dfs(-1)


        if len(result) < numCourses:
            for j in range(numCourses):
                if not j in result:
                    result.append(j)
        return result

t = Solution()
s = Solution()


print(t.findOrder(3,[[0,1],[0,2],[1,2]]))
print(t.findOrder(3,[[1,2],[2,0],[0,2]]))
print(s.findOrder(3,[[1,0]]))
print(t.findOrder(1,[]))
print(t.findOrder(2,[[0,1],[1,0]]))
print(t.findOrder(2,[[0,1]]))
print(s.findOrder(8,[[3,1],[4,3],[5,3],[2,1],[8,6],[6,2],[7,2]]))

'''
[2,1,0]
[]
[0, 1, 2]
[0]
[]
[1, 0]
[1, 3, 2, 4, 5, 6, 7, 8]
'''

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = defaultdict(list)
        inDegree = [0] * numCourses
        for prerequisite in prerequisites:
            graph[prerequisite[1]].append(prerequisite[0])
            inDegree[prerequisite[0]] += 1

        queue = []
        for i in range(numCourses):
            if inDegree[i] == 0:
                queue.append(i)
        res = []
        while queue:
            cur = queue.pop(0)
            res.append(cur)
            for v in graph[cur]:
                inDegree[v] -= 1
                if inDegree[v] == 0:
                    queue.append(v)
        return res if len(res) == numCourses else []
