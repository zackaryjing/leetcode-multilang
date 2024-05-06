class Trie:
    def __init__(self,value:str):
        self.val = value
        self.son = []
    def insert(self, word: str) -> None:
        def dfs(root):
            for i in root.son:
                if word.startswith(i.val):
                    key = dfs(i)
                    if not key:
                        root.son.remove(i)
                        root.son.append(root)
    def search(self, word: str) -> bool:
        pass
    def startsWith(self, prefix: str) -> bool:
        pass


class Trie:

    def __init__(self):
        self.isend = False
        self.children = [None] * 26

    def searchPrefix(self, prefix:str):
        node = self
        for ch in prefix:
            ch = ord(ch) - ord("a")
            if not node.children[ch]:
                return None
            node = node.children[ch]
        return node

    def insert(self, word: str) -> None:
        node = self
        for ch in word:
            ch = ord(ch)-ord("a")
            if not node.children[ch]:
                node.children[ch] = Trie()
            node = node.children[ch]
        node.isend = True

    def search(self, word: str) -> bool:
        node = self.searchPrefix(word)
        return node != None and node.isend


    def startsWith(self, prefix: str) -> bool:
        return self.searchPrefix(prefix) != None



# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
# a = "str"