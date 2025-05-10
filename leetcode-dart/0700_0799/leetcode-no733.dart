class Solution {
  int _target = 0;
  List<List<int>> _image = [];
  int _color = 0;
  late int _width, _height = 0;
  final List<List<int>> _directions = [
    [1, 0],
    [-1, 0],
    [0, 1],
    [0, -1]
  ];

  List<List<int>> floodFill(List<List<int>> image, int sr, int sc, int color) {
    _target = image[sr][sc];
    _color = color;
    if (_target == _color) {
      return image;
    }
    _image = image;
    _height = image.length;
    _width = image[0].length;
    fill_worker(sr, sc);
    // print(_image);
    return image;
  }

  void fill_worker(int sr, int sc) {
    // print("$sr, $sc");
    _image[sr][sc] = _color;
    for (var direction in _directions) {
      var dr = direction[0];
      var dc = direction[1];
      var nr = sr + dr;
      var nc = sc + dc;
      if (0 <= nr && nr < _height && 0 <= nc && nc < _width) {
        // print("$nr,$nc");
        if (_image[nr][nc] == _target) {
          fill_worker(nr, nc);
        }
      }
    }
  }
}


void main() {
  var image = [[1,1,1],[1,1,0],[1,0,1]];
  var sr = 1;
  var sc = 1;
  Solution solution = Solution();
  var ans = solution.floodFill(image, sr, sc, 2);
  print(ans);
}