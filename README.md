# EECE2140-MiniProject3
Mini Project 3 Image Denoising

Author Hayden Trent

Description
This program reads a grayscale image stored as a matrix of integers from a text file and removes noise using a 3 by 3 median filter. The image is stored as a vector of vectors. Border pixels are handled using clamp which replicates edge values.

Build
Make sure you have a C++ compiler such as g++

Compile with
g++ main.cpp -o denoise

Run
denoise input.txt output.txt median 1

Arguments
input.txt file containing the image matrix
output.txt file where the filtered matrix will be written
median filter type
1 number of iterations

Example
denoise noisy.txt clean.txt median 2

Copilot usage / other sources
Copilot helped generate ideas for the clamp function and median filtering approach as did this website here https://people.math.sc.edu/burkardt/cpp_src/image_denoise/image_denoise.html. 
I wrote and verified the file input output logic using references and the value validation myself.
In many cases Co-Pilot provided advanced examples that far exceeded my knowledge and understanding, and I sought out google provided references to ensure the code actually represented my level of knowledge, since I could not parse Co-Pilot's examples to pick and pull what I liked. 

Terminal Output Example:
<img width="2030" height="581" alt="image" src="https://github.com/user-attachments/assets/ce4d022a-2db2-4151-871d-6e9797eeaa31" />
