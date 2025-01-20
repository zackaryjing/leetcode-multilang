class Solution {
  List<String> removeComments(List<String> source) {
    bool founding_block_end = false;
    List<String> ans = [];
    String tempLine = "";
    for (var line in source) {
      int i = 0;
      for (; i < line.length; i++) {
        if (!founding_block_end) {
          if (line[i] == "/") {
            if ((i + 1) < line.length) {
              if (line[i + 1] == '*') {
                founding_block_end = true;
                i++;
                continue;
              } else if (line[i + 1] == '/') {
                break;
              } else {}
            }
          }
          tempLine += line[i];
        } else {
          if (line[i] == '*') {
            if ((i + 1) < line.length && line[i + 1] == '/') {
              founding_block_end = false;
              i++;
            }
          }
        }
      }
      if (founding_block_end == false) {
        if (!tempLine.isEmpty) {
          ans.add(tempLine);
        }
        tempLine = "";
      }
    }
    return ans;
  }
}

void main() {
  Solution test = Solution();
  List<String> example1 = [
    "for (; i < line  .length; i++) { /* ",
    "if (!founding_block_end) {",
    "if (line[i] == ' / ') {",
    "*/ asdf",
    "if (i < line.length /* && lin // e[i + */ 1] == '*') {",
    "founding_block_end = true;",
    "} else {"
  ];
  var temp = test.removeComments(example1);
  for (var line in temp) {
    print(line);
  }
}


// """
// for (; i < line
// if (!founding_block_end) {
// if (line[i] == ' / ') {
// */
// if (i < line.length  1] == '*') {
// founding_block_end = true;
// } else {
// """