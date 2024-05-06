class Solution:
    def invalidTransactions(self, transactions: list[str]) -> list[str]:
        n = len(transactions)
        transactions = list(map(lambda i:i.split(','),transactions))
        transactions.sort(key=lambda x:int(x[1]))
        invalid = []
        for i in range(n):
            k = 1
            if int(transactions[i][2]) > 1000:
                invalid.append(transactions[i])
            else:
                r = 1
                while i-r>=0 and abs(int(transactions[i][1])-int(transactions[i-r][1])) <= 60:
                    if transactions[i][0] == transactions[i-r][0] and transactions[i][3] != transactions[i-r][3]:
                        # print(i,i-r)
                        # print(transactions[i][0],transactions[i-r][0])
                        invalid.append(transactions[i])
                        k = 0
                        break
                        # print(1,invalid)
                    r += 1
                r = 1
                while k and i+r<n and abs(int(transactions[i][1])-int(transactions[i+r][1])) <= 60:
                    if transactions[i][0] == transactions[i + r][0] and transactions[i][3] != transactions[i + r][3]:
                        invalid.append(transactions[i])
                        break
                        # print(2,invalid)
                    r += 1
        return list(map(lambda x:','.join(x),invalid ))

t = Solution()
print(t.invalidTransactions(["alice,20,800,mtv","alice,50,100,beijing"]))
print(t.invalidTransactions(["alice,20,800,mtv","alice,50,1200,mtv"]))
print(t.invalidTransactions(["alice,20,800,mtv","bob,50,1200,mtv"]))
print(t.invalidTransactions(["alice,20,800,mtv","alice,50,100,mtv","alice,51,100,frankfurt"]))
print(t.invalidTransactions(["alice,20,1220,mtv","alice,20,1220,mtv"]))
print(t.invalidTransactions(["alice,20,800,mtv","bob,50,1200,mtv","alice,20,800,mtv","alice,50,1200,mtv","alice,20,800,mtv","alice,50,100,beijing"]))
print(t.invalidTransactions(["xnova,261,1949,chicago","bob,206,1284,chicago","xnova,420,996,bangkok","chalicefy,704,1269,chicago","iris,124,329,bangkok","xnova,791,700,amsterdam","chalicefy,572,697,budapest","chalicefy,231,310,chicago","chalicefy,763,857,chicago","maybe,837,198,amsterdam","lee,99,940,bangkok","bob,132,1219,barcelona","lee,69,857,barcelona","lee,607,275,budapest","chalicefy,709,1171,amsterdam"]))
'''
[['iris', '124', '329', 'bangkok'], ['bob', '132', '1219', 'barcelona'], ['bob', '206', '1284', 'chicago'], ['chalicefy', '231', '310', 'chicago'], ['xnova', '261', '1949', 'chicago'], ['xnova', '420', '996', 'bangkok'], ['chalicefy', '572', '697', 'budapest'], ['lee', '607', '275', 'budapest'], ['lee', '69', '857', 'barcelona'], ['chalicefy', '704', '1269', 'chicago'], ['chalicefy', '709', '1171', 'amsterdam'], ['chalicefy', '763', '857', 'chicago'], ['xnova', '791', '700', 'amsterdam'], ['maybe', '837', '198', 'amsterdam'], ['lee', '99', '940', 'bangkok']]
['bob,132,1219,barcelona', 'bob,206,1284,chicago', 'chalicefy,704,1269,chicago', 'chalicefy,709,1171,amsterdam', 'chalicefy,763,857,chicago', 'xnova,261,1949,chicago']
['bob,132,1219,barcelona', 'bob,206,1284,chicago', 'chalicefy,704,1269,chicago', 'chalicefy,709,1171,amsterdam', 'chalicefy,763,857,chicago', 'lee,69,857,barcelona', 'lee,99,940,bangkok', 'xnova,261,1949,chicago']
'''