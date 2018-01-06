#include "header.h"

#define SMALL_NUM   0.00000001 // anything that avoids division overflow
#define dot(u,v)   ((u).x * (v).x + (u).y * (v).y + (u).z * (v).z)
#define norm(v)    sqrt(dot(v,v))  // norm = length of  VECT
#define d(u,v)     norm(u-v)        // distance = norm of difference
#define abs(x)     ((x) >= 0 ? (x) : -(x))   //  absolute value

VECT point_minus(POINT A, POINT B) { return VECT((A.x - B.x), (A.y - B.y), (A.z - B.z)); }
POINT point_sum(POINT A, VECT B) { return POINT((A.x + B.x), (A.y + B.y), (A.z + B.z)); }
VECT vector_minus(VECT A, VECT B) { return VECT((A.x - B.x), (A.y - B.y), (A.z - B.z)); }
VECT vector_sum(VECT A, VECT B) { return VECT((A.x + B.x), (A.y + B.y), (A.z + B.z)); }
VECT vector_mult(VECT A, double b) { return VECT((A.x * b), (A.y * b), (A.z * b)); }
double dist(POINT A, POINT B) { return norm(point_minus(A, B)); }

double dist3D_LINE_to_LINE(LINE S1, LINE S2)
{
	VECT   u = point_minus(S1.P1, S1.P0);
	VECT   v = point_minus(S2.P1, S2.P0);
	VECT   w = point_minus(S1.P0, S2.P0);
	double    a = dot(u, u);         // always >= 0
	double    b = dot(u, v);
	double    c = dot(v, v);         // always >= 0
	double    d = dot(u, w);
	double    e = dot(v, w);
	double    D = a*c - b*b;        // always >= 0
	double    sc, sN, sD = D;       // sc = sN / sD, default sD = D >= 0
	double    tc, tN, tD = D;       // tc = tN / tD, default tD = D >= 0

								   // compute the line parameters of the two closest POINTs
	if (D < SMALL_NUM) 
	{						// the lines are almost parallel
		sN = 0.0;			 // force using POINT M on LINE S1
		sD = 1.0;			 // to prevent possible division by 0.0 later
		tN = e;
		tD = c;
	}
	else {                 // get the closest POINTs on the infinite lines
		sN = (b*e - c*d);
		tN = (a*e - b*d);
		if (sN < 0.0) 
		{				 // sc < 0 => the s=0 edge is visible
			sN = 0.0;
			tN = e;
			tD = c;
		}
		else if (sN > sD) 
		{  // sc > 1  => the s=1 edge is visible
			sN = sD;
			tN = e + b;
			tD = c;
		}
	}

	if (tN < 0.0) 
	{					// tc < 0 => the t=0 edge is visible
		tN = 0.0;		// recompute sc for this edge
		if (-d < 0.0)
			sN = 0.0;
		else if (-d > a)
			sN = sD;
		else {
			sN = -d;
			sD = a;
		}
	}
	else if (tN > tD) 
	{					// tc > 1  => the t=1 edge is visible
		tN = tD;		// recompute sc for this edge
		if ((-d + b) < 0.0)
			sN = 0;
		else if ((-d + b) > a)
			sN = sD;
		else {
			sN = (-d + b);
			sD = a;
		}
	}
	// finally do the division to get sc and tc
	sc = (abs(sN) < SMALL_NUM ? 0.0 : sN / sD);
	tc = (abs(tN) < SMALL_NUM ? 0.0 : tN / tD);

	// get the difference of the two closest POINTs
	VECT usc = vector_mult(u, sc);
	VECT vtc = vector_mult(v, tc);
	VECT w_usc = vector_sum(w, usc);
	VECT dP = vector_minus(w_usc, vtc);  // =  S1(sc) - S2(tc)

	return norm(dP);   // return the closest distance
}


