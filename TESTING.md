
**How to run tests**


**Compile the program**

g++ main.cpp -o filter

**Run a test** (Note median is the only filter type provided at this time.)

./filter <input.txt> <output.txt> <median> <iterations>
./filter img1.txt img1out1.txt median 1


**Provided Test Files:**


img1.txt

**Test 1 small matrix**

Purpose verify the filter works on a small image

Expected result center noisy values are reduced and surrounding values become similar


img2.txt

**Test 2 salt and pepper noise**

Purpose test random high and low noise pixels

Expected result extreme values like 0 or 255 are smoothed by the median filter


img3.txt

**Test 3 border handling**

Purpose check edges of the image

Expected result border pixels are processed correctly because clamp replicates edge values
