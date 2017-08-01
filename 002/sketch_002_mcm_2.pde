// Treat this as the dimensions:
// 40x30, 30x10, 10x20
float[] dimensions = { 1, 2, 3, 4, 10, 99};
// Task: Create a 2D array showing the minimum results
// p.376 of Introduction to Algorithms

String result;

void setup() {
  pixelDensity(displayDensity());
  textAlign(CENTER, CENTER);
  textSize(25);
  background(41);
  result = String.valueOf(getMCM(dimensions, dimensions.length));
}

void draw() {
  background(41);
  text(result, width/2, height/2);
}




static int getMCM(float[] dims, int num) {
  int[][] m = new int[num][num];
  for (int i = 1; i < num; i++) {
    m[i][i] = 0;
  }
  for (int l = 2; l < num; l++) {
    for (int i = 1; i < num-l+1; i++) {
      int j = i+l-1;
      if (j == num) {
        continue;
      }
      m[i][j] = Integer.MAX_VALUE;
      for (int k = i; k <= j-1; k++) {
        float q = m[i][k] + m[k+1][j] + dims[i-1]*dims[k]*dims[j];
        if (q < m[i][j]) {
          m[i][j] = int(q);
        }
      }
    }
  }
  return m[1][num-1];
}