bool search(char** board, int rowSize, int colSize, char* word,
            int row, int col, int pointer, int len, bool** mark) {
  if(pointer == len - 1 && board[row][col] == word[pointer]
    && !mark[row][col]) {
    return true;
  }
  if(mark[row][col] || board[row][col] != word[pointer]) {
    return false;
  }
  
  mark[row][col] = true;
  if(row > 0 && search(board, rowSize, colSize, word, row - 1,
                       col, pointer + 1, len, mark)) {
     return true;
  }
  if(row < rowSize - 1 && search(board, rowSize, colSize, word, row + 1,
                       col, pointer + 1, len, mark)) {
     return true;
  }
  if(col > 0 && search(board, rowSize, colSize, word, row,
                       col - 1, pointer + 1, len, mark)) {
     return true;
  }
  if(col < colSize - 1 && search(board, rowSize, colSize, word, row,
                                 col + 1, pointer + 1, len, mark)) {
    return true;
  }
  mark[row][col] = false;
  return false;
}

bool exist(char** board, int rowSize, int colSize, char* word) {
  int len = strlen(word);
  if(len == 0) {
    return true;
  }
  bool** mark = calloc(rowSize, sizeof(bool*));
  for(int i = 0; i < rowSize; i++) {
    mark[i] = calloc(colSize, sizeof(bool));
  }
  for(int i = 0; i < rowSize; i++) {
    for(int j = 0; j < colSize; j++) {
      if(search(board, rowSize, colSize, word, i, j, 0, len, mark)) {
        return true;
      }
    }
  }
  return false;
}