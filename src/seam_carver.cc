#include "seam_carver.hpp"

// implement the rest of SeamCarver's functions here

// SeamCarver::SeamCarver(const ImagePPM& image) {
//   image_ = image;
//   width_ = image.GetWidth();
//   height_ = image.GetHeight();
// }

// void SeamCarver::SetImage(const ImagePPM& image) {
//   image_ = image;
//   width_ = image.GetWidth();
//   height_ = image.GetHeight();
// }

const ImagePPM& SeamCarver::GetImage() const { return image_; }
int SeamCarver::GetHeight() const { return height_; }
int SeamCarver::GetWidth() const { return width_; }
int SeamCarver::GetEnergy(int row, int col) const {
  if ((row >= 1 && row < height_ - 1) && (col >= 1 && col < width_ - 1)) {
    return Innercase(row, col);
  }
  // left top
  if ((row == 0) && (col == 0)) {
    return Lefttop(row, col);
  }
  // left bottom
  if ((row == height_ - 1) && (col == 0)) {
    return Leftbot(row, col);
  }
  // right top
  if ((row == 0) && (col == width_ - 1)) {
    return Righttop(row, col);
  }
  if ((row == height_ - 1) && (col == width_ - 1)) {
    return Rightbot(row, col);
  }
  if ((row > 0 && row < height_ - 1) && (col == 0)) {
    return LeftChunk(row, col);
  }
  if ((row > 0 && row < height_ - 1) && (col == width_ - 1)) {
    return RightChunk(row, col);
  }
  if ((row == 0) && (col > 0 && col < width_ - 1)) {
    return TopChunk(row, col);
  }
  if ((row == height_ - 1) && (col > 0 && col < width_ - 1)) {
    return BotChunk(row, col);
  }
  return BotChunk(row, col);
}

// helper function
int SeamCarver::Innercase(int row, int col) const {
  int colenergy = 0;
  int rowenergy = 0;
  int energy = 0;

  colenergy = (image_.GetPixel(row, col - 1).GetRed() -
               image_.GetPixel(row, col + 1).GetRed()) *
                  (image_.GetPixel(row, col - 1).GetRed() -
                   image_.GetPixel(row, col + 1).GetRed()) +
              (image_.GetPixel(row, col - 1).GetGreen() -
               image_.GetPixel(row, col + 1).GetGreen()) *
                  (image_.GetPixel(row, col - 1).GetGreen() -
                   image_.GetPixel(row, col + 1).GetGreen()) +
              (image_.GetPixel(row, col - 1).GetBlue() -
               image_.GetPixel(row, col + 1).GetBlue()) *
                  (image_.GetPixel(row, col - 1).GetBlue() -
                   image_.GetPixel(row, col + 1).GetBlue());
  rowenergy = (image_.GetPixel(row - 1, col).GetRed() -
               image_.GetPixel(row + 1, col).GetRed()) *
                  (image_.GetPixel(row - 1, col).GetRed() -
                   image_.GetPixel(row + 1, col).GetRed()) +
              (image_.GetPixel(row - 1, col).GetGreen() -
               image_.GetPixel(row + 1, col).GetGreen()) *
                  (image_.GetPixel(row - 1, col).GetGreen() -
                   image_.GetPixel(row + 1, col).GetGreen()) +
              (image_.GetPixel(row - 1, col).GetBlue() -
               image_.GetPixel(row + 1, col).GetBlue()) *
                  (image_.GetPixel(row - 1, col).GetBlue() -
                   image_.GetPixel(row + 1, col).GetBlue());
  energy = colenergy + rowenergy;
  return energy;
}
int SeamCarver::Lefttop(int row, int col) const {
  int colenergy = 0;
  int rowenergy = 0;
  int energy = 0;

  colenergy = (image_.GetPixel(row, width_ - 1).GetRed() -
               image_.GetPixel(row, col + 1).GetRed()) *
                  (image_.GetPixel(row, width_ - 1).GetRed() -
                   image_.GetPixel(row, col + 1).GetRed()) +
              (image_.GetPixel(row, width_ - 1).GetGreen() -
               image_.GetPixel(row, col + 1).GetGreen()) *
                  (image_.GetPixel(row, width_ - 1).GetGreen() -
                   image_.GetPixel(row, col + 1).GetGreen()) +
              (image_.GetPixel(row, width_ - 1).GetBlue() -
               image_.GetPixel(row, col + 1).GetBlue()) *
                  (image_.GetPixel(row, width_ - 1).GetBlue() -
                   image_.GetPixel(row, col + 1).GetBlue());

  rowenergy = (image_.GetPixel(row + 1, col).GetRed() -
               image_.GetPixel(height_ - 1, col).GetRed()) *
                  (image_.GetPixel(row + 1, col).GetRed() -
                   image_.GetPixel(height_ - 1, col).GetRed()) +
              (image_.GetPixel(row + 1, col).GetGreen() -
               image_.GetPixel(height_ - 1, col).GetGreen()) *
                  (image_.GetPixel(row + 1, col).GetGreen() -
                   image_.GetPixel(height_ - 1, col).GetGreen()) +
              (image_.GetPixel(row + 1, col).GetBlue() -
               image_.GetPixel(height_ - 1, col).GetBlue()) *
                  (image_.GetPixel(row + 1, col).GetBlue() -
                   image_.GetPixel(height_ - 1, col).GetBlue());
  energy = colenergy + rowenergy;
  return energy;
}
int SeamCarver::Leftbot(int row, int col) const {
  int colenergy = 0;
  int rowenergy = 0;
  int energy = 0;

  colenergy = (image_.GetPixel(row, col + 1).GetRed() -
               image_.GetPixel(row, width_ - 1).GetRed()) *
                  (image_.GetPixel(row, col + 1).GetRed() -
                   image_.GetPixel(row, width_ - 1).GetRed()) +
              (image_.GetPixel(row, col + 1).GetGreen() -
               image_.GetPixel(row, width_ - 1).GetGreen()) *
                  (image_.GetPixel(row, col + 1).GetGreen() -
                   image_.GetPixel(row, width_ - 1).GetGreen()) +
              (image_.GetPixel(row, col + 1).GetBlue() -
               image_.GetPixel(row, width_ - 1).GetBlue()) *
                  (image_.GetPixel(row, col + 1).GetBlue() -
                   image_.GetPixel(row, width_ - 1).GetBlue());

  rowenergy = (image_.GetPixel(row - 1, col).GetRed() -
               image_.GetPixel(0, 0).GetRed()) *
                  (image_.GetPixel(row - 1, col).GetRed() -
                   image_.GetPixel(0, 0).GetRed()) +
              (image_.GetPixel(row - 1, col).GetGreen() -
               image_.GetPixel(0, 0).GetGreen()) *
                  (image_.GetPixel(row - 1, col).GetGreen() -
                   image_.GetPixel(0, 0).GetGreen()) +
              (image_.GetPixel(row - 1, col).GetBlue() -
               image_.GetPixel(0, 0).GetBlue()) *
                  (image_.GetPixel(row - 1, col).GetBlue() -
                   image_.GetPixel(0, 0).GetBlue());
  energy = colenergy + rowenergy;
  return energy;
}
int SeamCarver::Righttop(int row, int col) const {
  int colenergy = 0;
  int rowenergy = 0;
  int energy = 0;

  colenergy = (image_.GetPixel(row, col - 1).GetRed() -
               image_.GetPixel(row, 0).GetRed()) *
                  (image_.GetPixel(row, col - 1).GetRed() -
                   image_.GetPixel(row, 0).GetRed()) +
              (image_.GetPixel(row, col - 1).GetGreen() -
               image_.GetPixel(row, 0).GetGreen()) *
                  (image_.GetPixel(row, col - 1).GetGreen() -
                   image_.GetPixel(row, 0).GetGreen()) +
              (image_.GetPixel(row, col - 1).GetBlue() -
               image_.GetPixel(row, 0).GetBlue()) *
                  (image_.GetPixel(row, col - 1).GetBlue() -
                   image_.GetPixel(row, 0).GetBlue());
  rowenergy = (image_.GetPixel(row + 1, col).GetRed() -
               image_.GetPixel(height_ - 1, col).GetRed()) *
                  (image_.GetPixel(row + 1, col).GetRed() -
                   image_.GetPixel(height_ - 1, col).GetRed()) +
              (image_.GetPixel(row + 1, col).GetGreen() -
               image_.GetPixel(height_ - 1, col).GetGreen()) *
                  (image_.GetPixel(row + 1, col).GetGreen() -
                   image_.GetPixel(height_ - 1, col).GetGreen()) +
              (image_.GetPixel(row + 1, col).GetBlue() -
               image_.GetPixel(height_ - 1, col).GetBlue()) *
                  (image_.GetPixel(row + 1, col).GetBlue() -
                   image_.GetPixel(height_ - 1, col).GetBlue());
  energy = colenergy + rowenergy;
  return energy;
}
int SeamCarver::Rightbot(int row, int col) const {
  int colenergy = 0;
  int rowenergy = 0;
  int energy = 0;

  colenergy = (image_.GetPixel(row, col - 1).GetRed() -
               image_.GetPixel(row, 0).GetRed()) *
                  (image_.GetPixel(row, col - 1).GetRed() -
                   image_.GetPixel(row, 0).GetRed()) +
              (image_.GetPixel(row, col - 1).GetGreen() -
               image_.GetPixel(row, 0).GetGreen()) *
                  (image_.GetPixel(row, col - 1).GetGreen() -
                   image_.GetPixel(row, 0).GetGreen()) +
              (image_.GetPixel(row, col - 1).GetBlue() -
               image_.GetPixel(row, 0).GetBlue()) *
                  (image_.GetPixel(row, col - 1).GetBlue() -
                   image_.GetPixel(row, 0).GetBlue());
  rowenergy = (image_.GetPixel(row - 1, col).GetRed() -
               image_.GetPixel(0, col).GetRed()) *
                  (image_.GetPixel(row - 1, col).GetRed() -
                   image_.GetPixel(0, col).GetRed()) +
              (image_.GetPixel(row - 1, col).GetGreen() -
               image_.GetPixel(0, col).GetGreen()) *
                  (image_.GetPixel(row - 1, col).GetGreen() -
                   image_.GetPixel(0, col).GetGreen()) +
              (image_.GetPixel(row - 1, col).GetBlue() -
               image_.GetPixel(0, col).GetBlue()) *
                  (image_.GetPixel(row - 1, col).GetBlue() -
                   image_.GetPixel(0, col).GetBlue());
  energy = colenergy + rowenergy;
  return energy;
}
int SeamCarver::LeftChunk(int row, int col) const {
  int colenergy = 0;
  int rowenergy = 0;
  int energy = 0;

  colenergy = (image_.GetPixel(row, col + 1).GetRed() -
               image_.GetPixel(row, width_ - 1).GetRed()) *
                  (image_.GetPixel(row, col + 1).GetRed() -
                   image_.GetPixel(row, width_ - 1).GetRed()) +
              (image_.GetPixel(row, col + 1).GetGreen() -
               image_.GetPixel(row, width_ - 1).GetGreen()) *
                  (image_.GetPixel(row, col + 1).GetGreen() -
                   image_.GetPixel(row, width_ - 1).GetGreen()) +
              (image_.GetPixel(row, col + 1).GetBlue() -
               image_.GetPixel(row, width_ - 1).GetBlue()) *
                  (image_.GetPixel(row, col + 1).GetBlue() -
                   image_.GetPixel(row, width_ - 1).GetBlue());
  rowenergy = (image_.GetPixel(row - 1, col).GetRed() -
               image_.GetPixel(row + 1, col).GetRed()) *
                  (image_.GetPixel(row - 1, col).GetRed() -
                   image_.GetPixel(row + 1, col).GetRed()) +
              (image_.GetPixel(row - 1, col).GetGreen() -
               image_.GetPixel(row + 1, col).GetGreen()) *
                  (image_.GetPixel(row - 1, col).GetGreen() -
                   image_.GetPixel(row + 1, col).GetGreen()) +
              (image_.GetPixel(row - 1, col).GetBlue() -
               image_.GetPixel(row + 1, col).GetBlue()) *
                  (image_.GetPixel(row - 1, col).GetBlue() -
                   image_.GetPixel(row + 1, col).GetBlue());
  energy = colenergy + rowenergy;
  return energy;
}
int SeamCarver::RightChunk(int row, int col) const {
  int colenergy = 0;
  int rowenergy = 0;
  int energy = 0;

  colenergy = (image_.GetPixel(row, col - 1).GetRed() -
               image_.GetPixel(row, 0).GetRed()) *
                  (image_.GetPixel(row, col - 1).GetRed() -
                   image_.GetPixel(row, 0).GetRed()) +
              (image_.GetPixel(row, col - 1).GetGreen() -
               image_.GetPixel(row, 0).GetGreen()) *
                  (image_.GetPixel(row, col - 1).GetGreen() -
                   image_.GetPixel(row, 0).GetGreen()) +
              (image_.GetPixel(row, col - 1).GetBlue() -
               image_.GetPixel(row, 0).GetBlue()) *
                  (image_.GetPixel(row, col - 1).GetBlue() -
                   image_.GetPixel(row, 0).GetBlue());
  rowenergy = (image_.GetPixel(row - 1, col).GetRed() -
               image_.GetPixel(row + 1, col).GetRed()) *
                  (image_.GetPixel(row - 1, col).GetRed() -
                   image_.GetPixel(row + 1, col).GetRed()) +
              (image_.GetPixel(row - 1, col).GetGreen() -
               image_.GetPixel(row + 1, col).GetGreen()) *
                  (image_.GetPixel(row - 1, col).GetGreen() -
                   image_.GetPixel(row + 1, col).GetGreen()) +
              (image_.GetPixel(row - 1, col).GetBlue() -
               image_.GetPixel(row + 1, col).GetBlue()) *
                  (image_.GetPixel(row - 1, col).GetBlue() -
                   image_.GetPixel(row + 1, col).GetBlue());
  energy = colenergy + rowenergy;
  return energy;
}
int SeamCarver::TopChunk(int row, int col) const {
  int colenergy = 0;
  int rowenergy = 0;
  int energy = 0;

  colenergy = (image_.GetPixel(row, col - 1).GetRed() -
               image_.GetPixel(row, col + 1).GetRed()) *
                  (image_.GetPixel(row, col - 1).GetRed() -
                   image_.GetPixel(row, col + 1).GetRed()) +
              (image_.GetPixel(row, col - 1).GetGreen() -
               image_.GetPixel(row, col + 1).GetGreen()) *
                  (image_.GetPixel(row, col - 1).GetGreen() -
                   image_.GetPixel(row, col + 1).GetGreen()) +
              (image_.GetPixel(row, col - 1).GetBlue() -
               image_.GetPixel(row, col + 1).GetBlue()) *
                  (image_.GetPixel(row, col - 1).GetBlue() -
                   image_.GetPixel(row, col + 1).GetBlue());
  rowenergy = (image_.GetPixel(row + 1, col).GetRed() -
               image_.GetPixel(height_ - 1, col).GetRed()) *
                  (image_.GetPixel(row + 1, col).GetRed() -
                   image_.GetPixel(height_ - 1, col).GetRed()) +
              (image_.GetPixel(row + 1, col).GetGreen() -
               image_.GetPixel(height_ - 1, col).GetGreen()) *
                  (image_.GetPixel(row + 1, col).GetGreen() -
                   image_.GetPixel(height_ - 1, col).GetGreen()) +
              (image_.GetPixel(row + 1, col).GetBlue() -
               image_.GetPixel(height_ - 1, col).GetBlue()) *
                  (image_.GetPixel(row + 1, col).GetBlue() -
                   image_.GetPixel(height_ - 1, col).GetBlue());
  energy = colenergy + rowenergy;
  return energy;
}
int SeamCarver::BotChunk(int row, int col) const {
  int colenergy = 0;
  int rowenergy = 0;
  int energy = 0;

  colenergy = (image_.GetPixel(row, col - 1).GetRed() -
               image_.GetPixel(row, col + 1).GetRed()) *
                  (image_.GetPixel(row, col - 1).GetRed() -
                   image_.GetPixel(row, col + 1).GetRed()) +
              (image_.GetPixel(row, col - 1).GetGreen() -
               image_.GetPixel(row, col + 1).GetGreen()) *
                  (image_.GetPixel(row, col - 1).GetGreen() -
                   image_.GetPixel(row, col + 1).GetGreen()) +
              (image_.GetPixel(row, col - 1).GetBlue() -
               image_.GetPixel(row, col + 1).GetBlue()) *
                  (image_.GetPixel(row, col - 1).GetBlue() -
                   image_.GetPixel(row, col + 1).GetBlue());
  rowenergy = (image_.GetPixel(row - 1, col).GetRed() -
               image_.GetPixel(0, col).GetRed()) *
                  (image_.GetPixel(row - 1, col).GetRed() -
                   image_.GetPixel(0, col).GetRed()) +
              (image_.GetPixel(row - 1, col).GetGreen() -
               image_.GetPixel(0, col).GetGreen()) *
                  (image_.GetPixel(row - 1, col).GetGreen() -
                   image_.GetPixel(0, col).GetGreen()) +
              (image_.GetPixel(row - 1, col).GetBlue() -
               image_.GetPixel(0, col).GetBlue()) *
                  (image_.GetPixel(row - 1, col).GetBlue() -
                   image_.GetPixel(0, col).GetBlue());
  energy = colenergy + rowenergy;
  return energy;
}


int* SeamCarver::GetHorizontalSeam() const {
  int** earray = new int*[height_]; 
  for (int i = 0; i < height_; i++) { 
    earray[i] = new int[width_];
    for (int j = 0; j < width_; j++) { 
      earray[i][j] = GetEnergy(i , j);
    }
  } 
  int** value = new int*[height_];
  for (int i = 0; i < height_; i++) { 
    value[i] = new int[width_]; 
    for (int j = 0; j < width_; j++) {
      value[i][j] = 0; 
    }
  } 
  for (int i = 0; i < height_; i++) { 
    value[i][width_ - 1] = earray[i][width_ - 1];
  } 
  int best = 0; 
  for (int j = width_ -2; j >= 0; j--) { 
    for (int i = 0; i < height_; i++) {
      if (i == 0) { 
        if (value[i][j + 1] <= value[i + 1][j + 1]) { 
          best = value[i][j + 1]; 
        } else {
          best = value[i + 1][j + 1]; } 
          value[i][j] = best + earray[i][j]; } 
      else if (i == height_ - 1) {
        if (value[i - 1][j + 1] <= value[i][j + 1]) { 
          best = value[i - 1][j + 1]; 
        } else { 
          best = value[i][j + 1]; 
        }
        value[i][j] = best + earray[i][j]; 
      }
      else {  
        if (value[i -1][j + 1] <= value[i][j + 1]) { 
          if (value[i - 1][j +1] >= value[i + 1][j + 1]) {
            best = value[i +1][j + 1];} 
          else { 
            best = value[i - 1][j + 1];
            }
          }
        else if (value[i -1][j + 1] > value[i][j + 1]) { 
          if (value[i][j + 1] >= value[i + 1][j + 1]) {
            best = value[i +1][j + 1]; 
          } 
        else {best = value[i][j + 1]; 
          }
        } 
        value[i][j] = best + earray[i][j];
        }
      }
    }
  for (int i = 0; i < height_; i++) {
     delete[] earray[i];  
  }
  delete[] earray;
  int best_row = 0; 
  for (int i = 1; i < height_; i++) { 
    if (value[i][0] < value[best_row][0]) { 
      best_row = i;
    }
  } 
  int* result = new int[width_]; 
  result[0] = best_row; 
  for (int j = 1; j < width_; j++) {
    if (best_row == 0) { 
      if (value[best_row + 1][j] < value[best_row][j]) { 
        best_row = best_row + 1;} 
        result[j] = best_row;
    }
    else if (best_row == height_ - 1) {
      if (value[best_row - 1][j] < value[best_row][j]) {
        best_row = best_row - 1;
      }
      result[j] = best_row;
    } else {  
        if ((value[best_row -1][j] < value[best_row][j]) && (value[best_row - 1][j] <= value[best_row + 1][j])) {
          best_row = best_row - 1;
        }     
        else if ((value[best_row + 1][j] < value[best_row][j]) && (value[best_row + 1][j] < value[best_row -1][j])) {
          best_row = best_row + 1;
        }
        result[j] = best_row;
    }
  }
  for (int i = 0; i < height_; i++) { delete[] value[i];  } delete[] value; return result;
}

int* SeamCarver::GetVerticalSeam() const {
  int** earray = new int*[height_];  
  for (int i = 0; i < height_; i++) { 
    earray[i] = new int[width_];
    for (int j = 0; j < width_; j++) { 
      earray[i][j] = GetEnergy(i, j);
    }
  } 
  int** value = new int*[height_];
  for (int i = 0; i < height_; i++) { 
    value[i] = new int[width_]; 
    for (int j = 0; j < width_; j++) {
      value[i][j] = 0; 
    }
  } 
  for (int j = 0; j < width_; j++) { 
    value[height_ - 1][j] = earray[height_ - 1][j];
  } 
  int best = 0; 
  for (int i = height_ - 2; i >= 0; i--) { 
    for (int j = 0; j < width_; j++) { 
      if (j == 0) {
        if (value[i + 1][j] <= value[i + 1][j + 1]) { 
          best = value[i + 1][j]; 
        } 
        else { best = value[i + 1][j + 1];
        } 
        value[i][j] = best + earray[i][j]; 
      } 
      else if (j == width_ - 1) { 
        if (value[i + 1][j - 1] <= value[i + 1][j]) {
          best = value[i + 1][j - 1];
        } else { 
          best = value[i + 1][j]; 
        } 
        value[i][j] = best + earray[i][j]; 
      } 
      else { 
        if (value[i + 1][j - 1] <= value[i + 1][j]) {
          if (value[i + 1][j - 1] >= value[i + 1][j + 1]) { 
            best = value[i + 1][j + 1]; } else { best = value[i + 1][j - 1];
          }
        } else if (value[i + 1][j - 1] > value[i + 1][j]) { 
            if (value[i + 1][j] >= value[i + 1][j + 1]) { 
              best = value[i + 1][j + 1];
            } else { 
              best = value[i + 1][j]; 
              }
            } 
          value[i][j] = best + earray[i][j];
      }
    }
  }
  for (int i = 0; i < height_; i++) {
     delete[] earray[i];  
  }
  delete[] earray;
  int best_column = 0; 
  for (int i = 1; i < width_; ++i) { 
    if (value[0][i] < value[0][best_column]) { 
      best_column = i;
    } 
  } 
  int* result = new int[height_]; 
  result[0] = best_column; 
  for (int i = 1; i < height_; i++) {
    if (best_column == 0) { 
      if (value[i][best_column] > value[i][best_column + 1]) {
        best_column = best_column + 1; 
      }
    result[i] = best_column;
    }
    // cant check the right
  else if (best_column == width_ - 1) {
      if (value[i][best_column] > value[i][best_column - 1]) {
        best_column = best_column - 1;
      }
      result[i] = best_column;
    } else {
     // 3 4 5 
        if ((value[i][best_column + 1] < value[i][best_column]) && (value[i][best_column + 1] < value[i][best_column - 1])) {
          best_column = best_column + 1;
        } else if (value[i][best_column - 1] < value[i][best_column]) {
          best_column = best_column - 1;
        }
        result[i] = best_column;
    }
  }
  for (int i = 0; i < height_; i++) {
     delete[] value[i];  } delete[] value; return result;
}


// // helper function for deallocating 
//   for (int i = 0; i < height_; i++) {
//      delete[] earray[i];  
//    }
//   
//    delete[] earray;



void SeamCarver::RemoveHorizontalSeam() {

  int* seam = GetHorizontalSeam(); 

  image_.Helperfuntwo(seam); 
  height_--;

  delete[] seam;
}

void SeamCarver::RemoveVerticalSeam() {

  int* seam = GetVerticalSeam(); 
  
  image_.Helperfun(seam);
  width_--; 
  
  delete[] seam; 
}



// given functions below, DO NOT MODIFY

SeamCarver::SeamCarver(const ImagePPM& image): image_(image) {
  height_ = image.GetHeight();
  width_ = image.GetWidth();
}

void SeamCarver::SetImage(const ImagePPM& image) {
  image_ = image;
  width_ = image.GetWidth();
  height_ = image.GetHeight();
}
