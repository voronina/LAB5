#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <vector>
#include <time.h>
#include <math.h>
#include <cmath>
#include <string> 
#include <ctime>

using namespace std;

#include "geometry.h"
#include "objects.h"

#define EPS 100
#define E 0.00001
#define AA 4
#define M_PI 3.14159265358979323846
#define TRY_AMO 100

double dist3D_LINE_to_LINE(LINE S1, LINE S2);