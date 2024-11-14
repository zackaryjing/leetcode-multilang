class Solution:
    def validIPAddress(self, queryIP: str) -> str:
        validip6ch = ["a","b","c","d","e","f","A","B","C",
                      "D","E","F","1","2","3","4","5","6",
                      "7","8","9","0"]
        def checkIPv4(ip):
            each_part = ip.split(".")
##            print(each_part)
            if len(each_part) != 4:
                return False
            for i in each_part:
                if i == "":
                    return False
                if not i.isnumeric() or int(i) > 255 or int(i) < 0:
                    return False
                if i != "0" and i.startswith("0"):
                    return False
            return True

        def checkIPv6(ip):
            each_part = ip.split(":")
##            print(each_part)
            if len(each_part) != 8:
                return False
            for i in each_part:
                if i == "":
                    return False
##                if not (i == "0000" or i == "0") and i.startswith("0"):
##                    return False
                if not i == "0":
                    if len(i) > 4:
                        return False
                    for ch in i:
                        if ch not in validip6ch:
##                            print(i,ch)
                            return False
            return True
        
        if checkIPv4(queryIP):
            return "IPv4"
        elif checkIPv6(queryIP):
           return "IPv6"
        else:
            return "Neither"

t = Solution()
print(t.validIPAddress("0172.16.254.1"))
print(t.validIPAddress("1e1.16.252.1"))
print(t.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334"))
print(t.validIPAddress("2001:0db8:85a3:033:0:8A2E:0370:7334"))

        
