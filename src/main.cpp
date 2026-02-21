// Hayden Trent
//https://people.math.sc.edu/burkardt/cpp_src/image_denoise/image_denoise.cpp used as a reference for this project.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Image is defined as a 2D vector of integers (represents pixel values)
using Image = vector<vector<int>>;

// Clamp coordinate to image bounds (replicate border).
// This prevents accessing pixels outside the image by forcing the
// value to stay within the valid range [lo, hi].
int clamp(int v, int lo, int hi) {
    return max(lo, min(v, hi));
}

// Prints the image matrix to the console.
void print(const Image& img) {
    for (auto& row : img) {          // Loop through each row
        for (auto v : row)           // Loop through each value in the row
            cout << v << '\t';       // Print pixel with spacing
        cout << '\n';                // Move to next line after each row
    }
}

// Applies a median filter to the image.
// The filter looks at a 3x3 neighborhood around each pixel
// and replaces the center pixel with the median value.
void filter (Image& img, int rows, int cols) {
    Image temp = img;  // Copy of the original image so updates don't affect neighbors

    // Loop through every pixel in the image
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {

            vector<int> neighbors;  // Stores the 3x3 neighborhood values

            // Collect values from the 3x3 area around the pixel
            for (int k = i - 1; k <= i + 1; ++k) {
                for (int l = j - 1; l <= j + 1; ++l) {

                    // Clamp ensures we stay inside the image borders
                    int r = clamp(k, 0, rows - 1);
                    int c = clamp(l, 0, cols - 1);

                    neighbors.push_back(temp[r][c]);
                }
            }

            // Sort the 9 neighbor values to find the median
            sort(neighbors.begin(), neighbors.end());

            // The median of 9 values is the middle element (index 4)
            img[i][j] = neighbors[4];
        }
    }
}

int main(int argc, char* argv[]) {

    // Check if enough command-line arguments were provided
    if (argc < 5) {
        cerr << "Usage: " << argv[0]
             << " <input.txt> <output.txt> <filter> <iterations>" << endl;
        return 1;
    }

    // Read command-line arguments
    string inputPath = argv[1];   // Input image file
    string outputPath = argv[2];  // Output image file
    string filterType = argv[3];  // Filter type (not currently used)
    int iterations = stoi(argv[4]); // Number of times to apply the filter

    // Open input file
    ifstream inFile(inputPath);
    if (!inFile) return 1;

    // Read image dimensions
    int rows, cols;
    inFile >> rows >> cols;

    // Create the image matrix
    Image matrix(rows, vector<int>(cols));

    // Read pixel values from the file
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            inFile >> matrix[i][j];

            // Clamp pixel values to valid grayscale range (0–255)
            if (matrix[i][j] < 0) {
                matrix[i][j] = 0;
            } else if (matrix[i][j] > 255) {
                matrix[i][j] = 255;
            }
        }
    }

    inFile.close();  // Close input file

    // Apply the filter the specified number of times
    for (int i = 0; i < iterations; ++i) {
        filter(matrix, rows, cols);
    }

    // Open output file
    ofstream outFile(outputPath);

    // Write image dimensions
    outFile << rows << " " << cols << "\n";

    // Write filtered image values
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            outFile << matrix[i][j] << ' ';
        }
        outFile << '\n';
    }

    outFile.close();  // Close output file

    // Print the final filtered image to the console
    print(matrix);

    return 0;
}