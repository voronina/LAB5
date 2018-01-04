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

#include "objects.h"

#define EPS 100
#define AA 4

vector<PLANE> initialize_box();

bool check_new(FBR F, BOX B, double x, double y);