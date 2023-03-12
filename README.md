Fractals is a program that generates fractals using IFS, iterated function system. 
The transformation of a point on the plane is described by the system:

x' = ax + by + c

y' = dx + ey + f


The input file describes a set of n such transformations, each with an associated probability
pi according to the format:

p1 a1 b1 c1 d1 e1 f1
p2 a2 b2 c2 d2 e2 f2
...
pn an bn cn dn en fn


Fractal generation starts from the point (0,0). The operation of the algorithm is based on random selection
transformation from a defined set with the appropriate probability and transformation of the current one
point. Final result is displayed using SFML library.


Program should be run with following switches: 
  -i input file in .txt extension
  -o output file (avilable extensions: .bmp, .png, .tga, .jpg, .gif, .psd, .hdr oraz .pic)
  -n (optional) number of generated points