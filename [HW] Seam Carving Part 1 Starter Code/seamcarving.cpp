#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using std::cout;
using std::cin;
using std::string;
using std::ostringstream;
using std::endl;
using std::istringstream;

int main() { 
  cout << "Input filename: ";
  string filename;
  cin >> filename;
  
  // TODO(student): add error checking for width, height, targetWidth, and targetHeight
  cout << "Input width and height: ";
  int width = 0;
  int height = 0;

  // check if width and height are integers

  if (!(cin >> width)) {
    cout << "Error: width is a non-integer value" << endl;
    return 0;
  }

  
  if (!(cin >> height)) {
    cout << "Error: height is a non-integer value" << endl;
    return 0;
  }

  // check if width and height are valid
  if (width <= 0) {
    cout << "Error: width must be greater than 0. You entered " << width << endl;
    return 0; 
  }
  if (height <= 0) {
    cout << "Error: height must be greater than 0. You entered " << height << endl;
    return 0;
  }

  cout << "Input target width and height: ";
  int targetWidth = 0;
  int targetHeight = 0;

  if (!(cin >> targetWidth)) {
    cout << "Error: target width is a non-integer value" << endl;
    return 0;
  }

  
  if (!(cin >> targetHeight)) {
    cout << "Error: target height is a non-integer value" << endl;
    return 0;
  }


  // check if target width and height are valid
  if (targetWidth <= 0) {
    cout << "Error: target width must be greater than 0. You entered " << targetWidth << endl;
    return 0; 
  }
  if (targetHeight <= 0) {
    cout << "Error: target height must be greater than 0. You entered " << targetHeight << endl;
    return 0;
  }

  if (targetWidth > width) {
    cout << "Error: target width must be less than width, " << targetWidth << " is greater than " << width << endl;
    return 0;
  }

  if (targetHeight > height) {
    cout << "Error: target height must be less than height, " << targetHeight << " is greater than " << height << endl;
    return 0;
  }


  
  // save originalWidth since width will change with carving
  int originalWidth = width; 
  
  Pixel** image1 = createImage(width, height);
  if (image1 != nullptr) { // new returns nullptr if it fails to allocate array

    if (loadImage(filename, image1, width, height)) {
      
      // uncomment for part 2
    
      while ((width - targetWidth > 0) || (height - targetHeight > 0)) {
        if (width - targetWidth > 0) {
          int* verticalSeam = findMinVerticalSeam(image1, width, height);
          removeVerticalSeam(image1, width, height, verticalSeam);
          deleteSeam(verticalSeam);
          width--;
        }
        
        // this is for the extra credit
        if (height - targetHeight > 0) {
          int* horizontalSeam = findMinHorizontalSeam(image1, width, height);
          removeHorizontalSeam(image1, width, height, horizontalSeam);
          deleteSeam(horizontalSeam);
          height--;
        }
      }
    
      
      ostringstream oss;
      oss << "carved" << width << "X" << height << "." << filename;
      outputImage(oss.str().c_str(), image1, width, height);
    }
  }
  
  // call last to remove the memory from the heap
  deleteImage(image1, originalWidth);
}