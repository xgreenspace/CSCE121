#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

#define INFO(X) cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << endl;

using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::ofstream;

Pixel** createImage(int width, int height) {
  cout << "Start createImage... " << endl;
  
  // Create a one dimensional array on the heap of pointers to Pixels 
  //    that has width elements (i.e. the number of columns)
  Pixel** image = new Pixel*[width];
  
  bool fail = false;
  
  for (int i=0; i < width; ++i) { // loop through each column
    // assign that column to a one dimensional array on the heap of Pixels
    //  that has height elements (i.e. the number of rows)
    image[i] = new Pixel[height];
    
    if (image[i] == nullptr) { // failed to allocate
      fail = true;
    }
  }
  
  if (fail) { // if any allocation fails, clean up and avoid memory leak
    // deallocate any arrays created in for loop
    for (int i=0; i < width; ++i) {
      delete [] image[i]; // deleting nullptr is not a problem
    }
    delete [] image; // dlete array of pointers
    return nullptr;
  }
  
  // initialize cells
  //cout << "Initializing cells..." << endl;
  for (int row=0; row<height; ++row) {
    for (int col=0; col<width; ++col) {
      //cout << "(" << col << ", " << row << ")" << endl;
      image[col][row] = { 0, 0, 0 };
    }
  }
  cout << "End createImage... " << endl;
  return image;
}

void deleteImage(Pixel** image, int width) {
  cout << "Start deleteImage..." << endl;
  // avoid memory leak by deleting the array
  for (int i=0; i<width; ++i) {
    delete [] image[i]; // delete each individual array placed on the heap
  }
  delete [] image;
  image = nullptr;
}

int* createSeam(int length) {
    // TODO(student): create a seam
    // initalize pointer
    int* seam = new int[length];

    // Set all parts of array to zero
    for (int i = 0; i < length; i++) {
      seam[i] = 0;
    }

    INFO(length);
  return seam;
}

void deleteSeam(int* seam) {
    // TODO(student): delete a seam
    delete[] seam;
    INFO(seam);
}

bool loadImage(string filename, Pixel** image, int width, int height) {
    // TODO(student): load an image
    cout << "Loading image..." << endl;
    // declare/define and open input file stream
    std::ifstream ifs (filename);
  
    // check if input stream opened successfully
    if (!ifs.is_open()) {
      cout << "Error: failed to open input file - " << filename << endl;
      return false;
    }
  
    // get type from preamble
    char type[3];
    ifs >> type; // should be P3
    if ((toupper(type[0]) != 'P') || (type[1] != '3')) { // check that type is correct
      cout << "Error: type is " << type << " instead of P3" << endl;
      return false;
    }
  
    // get width (w) and height (h) from preamble
    int w = 0, h = 0;
  
    if (!(ifs >> w)) {
      cout << "Error: read non-integer value" << endl;
      return 0;
    }
    if (!(ifs >> h)) {
      cout << "Error: read non-integer value" << endl;
      return 0;
    }

    if (w != width) { // check that width matches what was passed into the function
      cout << "Error: input width (" << width << ") does not match value in file (" << w << ")" << endl;
      return false;
    }
    if (h != height) { // check that height matches what was passed into the function
      cout << "Error: input height (" << height << ") does not match value in file (" << h << ")" << endl;
      return false;
    }
  
    // get maximum value from preamble
    int colorMax = 0;
    ifs >> colorMax;
    if (colorMax != 255) {
      cout << "Error: file is not using RGB color values." << endl;
      return false;
    }

    // get RGB pixel values
    int numPixel = 0;
    // int actualPixel = height * width * 3;
    while (!ifs.eof()) {
      for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
          if (ifs.eof()) {
            break;
          }
          if (!(ifs >> image[col][row].r)) {
            // if (ifs.eof()) {
            //   cout << "Error: not enough color values" << endl;
            //   return false;
            // } else {
            //   cout << "Error: read non-integer value" << endl;
            //   return false;
            // }
          } 
          numPixel++;
          // if (numPixel > actualPixel) {
          //   cout << "Error: too many color values" << endl;
          //   return false;
          // }
          if (!(ifs >> image[col][row].g)) {
            // if (ifs.eof()) {
            //   cout << "Error: not enough color values" << endl;
            //   return false;
            // } else {
            //   cout << "Error: read non-integer value" << endl;
            //   return false;
            // }
          } 
          numPixel++;
          // if (numPixel > actualPixel) {
          //   cout << "Error: too many color values" << endl;
          //   return false;
          // }
          if (!(ifs >> image[col][row].b)) {
            //   if (ifs.eof()) {
            //   cout << "Error: not enough color values" << endl;
            // return false;
            // } else {
            //   cout << "Error: read non-integer value" << endl;
            //   return false;
            // }
          } 
          numPixel++;
          // if (numPixel > actualPixel) {
          //   cout << "Error: too many color values" << endl;
          //   return false;
          // }

          if (!(ifs.good())) {
            break;
          }

          if (image[col][row].r < 0 || image[col][row].r > 255) {
            cout << "Error: invalid color value " << image[col][row].r << endl;
            return false;
          }
          if (image[col][row].g < 0 || image[col][row].g > 255) {
            cout << "Error: invalid color value " << image[col][row].g << endl;
            return false;
          }
          if (image[col][row].b < 0 || image[col][row].b > 255) {
            cout << "Error: invalid color value " << image[col][row].b << endl;
            return false;
          }
        }
      }
    }
  
  
    INFO(filename);
    INFO(image);
    INFO(width);
    INFO(height);
  return true;
}

bool outputImage(string filename, Pixel** image, int width, int height) {
    // TODO(student): output an image
    cout << "Outputting image..." << endl;
    // declare/define and open output file stream
    ofstream ofs (filename);
  
    // check if output stream opened successfully
    if (!ofs.is_open()) {
      cout << "Error: failed to open output file" << filename << endl;
      return false;
    }
  
    // output preamble
    ofs << "P3" << endl;
    ofs << width << " " << height << endl;
    ofs << 255 << endl;
  
    // output pixels
    for (int row = 0; row < height; ++row) {
      for (int col = 0; col < width; ++col) {
        ofs << image[col][row].r << " ";
        ofs << image[col][row].g << " ";
        ofs << image[col][row].b << " ";
      }
      ofs << endl;
    }
      INFO(filename);
      INFO(image);
      INFO(width);
      INFO(height);
  return true;
}

int energy(Pixel** image, int column, int row, int width, int height) { 
    // TODO(student): compute the energy of a pixel
    // Define coloumns and rows
    int right_column;
    int left_column;
    int up_row;
    int down_row;

    int r_x;
    int g_x;
    int b_x;
    int r_y;
    int g_y;
    int b_y;

    int x_gradient;
    int y_gradient;

    // Use a control flow to determine the left and the right pixel for x-gradient
     if (width > 1) {
      if (column == 0) {
        left_column = width - 1;
        right_column = column + 1;
      } else if (column == width - 1) {
        right_column = 0;
        left_column = column - 1; 
      } else {
        right_column = column + 1;
        left_column = column - 1;
      }
    
      // Find the difference between the right and left pixels
      r_x = image[right_column][row].r - image[left_column][row].r;
      g_x = image[right_column][row].g - image[left_column][row].g;
      b_x = image[right_column][row].b - image[left_column][row].b;

      // Calculate the x-gradient
      x_gradient = pow(r_x, 2) + pow(g_x, 2) + pow(b_x, 2);
    } else {
      x_gradient = 0;
    }

    // Use a control flow to determine the up and the down pixel for the y-gradient

    if (height > 1) {
      if (row == 0) {
        down_row = row + 1;
        up_row = height - 1;
      } else if (row == height - 1) {
        down_row = 0;
        up_row = row - 1; 
      } else {
        down_row = row + 1;
        up_row = row - 1;
      }

      // Find the difference between the lower and upper pixels
      r_y = image[column][down_row].r - image[column][up_row].r;
      g_y = image[column][down_row].g - image[column][up_row].g;
      b_y = image[column][down_row].b - image[column][up_row].b;

      // Calculate the y-gradient
      y_gradient = pow(r_y, 2) + pow(g_y, 2) + pow(b_y, 2);
    } else {
      y_gradient = 0;
    }
    // Calculate the energy
    return y_gradient + x_gradient;

    INFO(image);
    INFO(column);
    INFO(row);
    INFO(width);
    INFO(height);
  return 0;
}

int loadVerticalSeam(Pixel** image, int start_col, int width, int height, int* seam) {
    // TODO(student): load a vertical seam
    int left_col;
    int mid_col;
    int right_col;

    int left_energy;
    int mid_energy;
    int right_energy;

    // Set seam for the first row to the starting column
    seam[0] = start_col; 
    // Initalize total energy to the energy for pixel (start_col, 0)
    int totalEnergy = energy(image, start_col, 0, width, height);
    // Using a for loop that interates through each row, calculate the energy of each possible next column, set the seam for the current row to the column with the minimal energy, add the minimal energy to the total energy.
    for (int row = 1; row < height; row++) {
      //Calculate the energy for each possible next column
      if (start_col - 1 >= 0) {
        right_col = start_col - 1;
      } else {
        right_col = 0;
      }

      if (start_col + 1 <= width - 1) {
        left_col = start_col + 1;
      } else {
        left_col = width - 1;
      }

      mid_col = start_col;

      left_energy = energy(image, left_col, row, width, height);
      mid_energy = energy(image, mid_col, row, width, height);
      right_energy = energy(image, right_col, row, width, height);

      if (mid_energy <= right_energy && mid_energy <= left_energy) {
        seam[row] = start_col;
        totalEnergy += mid_energy;
      } else if (left_energy <= right_energy && left_energy <= mid_energy) {
        start_col = left_col;
        seam[row] = start_col;
        totalEnergy += left_energy;
      } else {
        start_col = right_col;
        seam[row] = start_col;
        totalEnergy += right_energy;
      }
    }
    // Return total energy 
    return totalEnergy;
    INFO(image);
    INFO(start_col);
    INFO(width);
    INFO(height);
    INFO(seam);
}

int loadHorizontalSeam(Pixel** image, int start_row, int width, int height, int* seam) {
    // TODO(student): load a horizontal seam
    int left_row;
    int mid_row;
    int right_row;

    int left_energy;
    int mid_energy;
    int right_energy;

    // Set seam for the first row to the starting column
    seam[0] = start_row; 
    // Initalize total energy to the energy for pixel (start_col, 0)
    int totalEnergy = energy(image, 0, start_row, width, height);
    // Using a for loop that interates through each row, calculate the energy of each possible next column, set the seam for the current row to the column with the minimal energy, add the minimal energy to the total energy.
    for (int col = 1; col < width; col++) {
      //Calculate the energy for each possible next column
      if (start_row - 1 >= 0) {
        right_row = start_row - 1;
      } else {
        right_row = 0;
      }

      if (start_row + 1 <= height - 1) {
        left_row = start_row + 1;
      } else {
        left_row = height - 1;
      }

      mid_row = start_row;

      left_energy = energy(image, col, left_row, width, height);
      mid_energy = energy(image, col, mid_row, width, height);
      right_energy = energy(image, col, right_row, width, height);

      if (mid_energy <= right_energy && mid_energy <= left_energy) {
        seam[col] = start_row;
        totalEnergy += mid_energy;
      } else if (left_energy <= right_energy && left_energy <= mid_energy) {
        start_row = left_row;
        seam[col] = start_row;
        totalEnergy += left_energy;
      } else {
        start_row = right_row;
        seam[col] = start_row;
        totalEnergy += right_energy;
      }
    }
    // Return total energy
    return totalEnergy;
    INFO(image);
    INFO(start_row);
    INFO(width);
    INFO(height);
    INFO(seam);
}

int* findMinVerticalSeam(Pixel** image, int width, int height) {
    // TODO(student): find min vertical seam'
    int testEnergy;
    // Create seam
    int* minimum_seam = createSeam(height);
    // Set minimal energy to the result of loading the seam for the first column
    // Note minimal seam was loaded by function that returned minimal energy
    int minEnergy = INT32_MAX;
    // For each column
    for (int col = 0; col < width; col++) {
      // Get energy for the column and load candidate seam
      int* test_seam = createSeam(height);
      testEnergy = loadVerticalSeam(image, col, width, height, test_seam);
      // If the energy is less than the minimal energy
      if (testEnergy < minEnergy) {
        delete[] minimum_seam;
        // Set minimal energy to energy
        minEnergy = testEnergy;
        // Update minimal energy to energy
        minimum_seam = test_seam;
        // Delete unsued memory
      } else {
        delete[] test_seam;
      }
    }

    INFO(image);
    INFO(width);
    INFO(height);
    INFO(minEnergy);
    INFO(testEnergy);
  return minimum_seam;
}

int* findMinHorizontalSeam(Pixel** image, int width, int height) {
    // TODO(student): find min horizontal seam
    int testEnergy;
    // Create seam
    int* minimum_seam = createSeam(width);
    // Set minimal energy to the result of loading the seam for the first column
    // Note minimal seam was loaded by function that returned minimal energy
    int minEnergy = INT32_MAX;
    // For each column
    for (int row = 0; row < height; row++) {
      // Get energy for the column and load candidate seam
      int* test_seam = createSeam(width);
      testEnergy = loadHorizontalSeam(image, row, width, height, test_seam);
      // If the energy is less than the minimal energy
      if (testEnergy < minEnergy) {
        delete[] minimum_seam;
        // Set minimal energy to energy
        minEnergy = testEnergy;
        // Update minimal energy to energy
        minimum_seam = test_seam;
        // Delete unsued memory
      } else {
        delete[] test_seam;
      }
    }

    INFO(image);
    INFO(width);
    INFO(height);
    INFO(minEnergy);
    INFO(testEnergy);
  return minimum_seam;
}

void removeVerticalSeam(Pixel** image, int width, int height, int* verticalSeam) {
    // TODO(student): remove a vertical seam
    // For each row
    for (int row = 0; row < height; row++) {
      // Remove pixel (seam[row], row) - note that seam[row] will be the column
      for (int col = verticalSeam[row]; col < width - 1; col++) {
        image[col][row] = image[col + 1][row];
      }
    }
    INFO(image);
    INFO(width);
    INFO(height);
    INFO(verticalSeam);
}

void removeHorizontalSeam(Pixel** image, int width, int height, int* horizontalSeam) {
    // TODO(student): remove a horizontal seam
    for (int col = 0; col < width; col++) {
      // Remove pixel (seam[row], row) - note that seam[row] will be the column
      for (int row = horizontalSeam[col]; row < height - 1; row++) {
        image[col][row] = image[col][row + 1];
      }
    }
    INFO(image);
    INFO(width);
    INFO(height);
    INFO(horizontalSeam);
}
