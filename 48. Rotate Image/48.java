public void rotate(int[][] matrix) {
  if(matrix.length <= 1) return;
  for(int i = 0; i < matrix.length / 2; i++) {
    int side = matrix.length - i * 2;
    for(int j = 0; j < side - 1; j++) {
      int top_left = matrix[i][i + j];
      int top_right = matrix[i + j][i + side - 1];
      int bottom_right = matrix[i + side - 1][i + side - 1 - j];
      int bottom_left = matrix[i + side - 1 - j][i];
      matrix[i][i + j] = bottom_left;
      matrix[i + j][i + side - 1] = top_left;
      matrix[i + side - 1][i + side - 1 - j] = top_right;
      matrix[i + side - 1 - j][i] = bottom_right;
    }
  }
}