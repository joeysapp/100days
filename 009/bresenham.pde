// http://members.chello.at/~easyfilter/Bresenham.pdf

void setup() {
  size(250, 250);
  pixelDensity(displayDensity());
  background(51);
  stroke(255);
}

void draw() {
  background(51);
  place_line(width/2, height/2, mouseX, mouseY);
}

void place_line(float x0, float y0, float x1, float y1) {
  float dx = abs(x1 - x0);
  float sx = x0 < x1 ? 1 : -1;
  float dy = -abs(y1 - y0);
  float sy = y0 < y1 ? 1 : -1;
  float err = dx + dy;
  float e2;

  while (true) {
    point(x0, y0);
    if (x0 == x1 && y0 == y1) break;
    e2 = 2*err;
    if (e2 >= dy) {
      err += dy;
      x0 += sx;
    }
    if (e2 <= dx) {
      err += dx;
      y0 += sy;
    }
  }
}