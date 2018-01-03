algebraic3d
solid box1 = plane (0,0,0;-1,0,0) -bc=18;
solid box2 = plane (0,0,0;0,-1,0) -bc=14;
solid box3 = plane (0,0,0;0,0,-1) -bc=16;
solid box4 = plane (1,1,1;1,0,0) -bc=22;
solid box5 = plane (1,1,1;0,1,0) -bc=15;
solid box6 = plane (1,1,1;0,0,1) -bc=19;
solid box = box1 and box2 and box3 and box4 and box5 and box6;

solid cyl11 = cylinder (0,0,-0.1;0,0,1.1;0.3) -bc=1;
solid cyl12 = plane (0,0,-0.1;0,0,-1.2) -bc=1;
solid cyl13 = plane (0,0,1.1;0,0,1.2) -bc=1;
solid cyl1 = cyl11 and cyl12 and cyl13;

solid cyl21 = cylinder (1,1,-0.1;1,1,1.1;0.3) -bc=1;
solid cyl22 = plane (1,1,-0.1;0,0,-1.2) -bc=1;
solid cyl23 = plane (1,1,1.1;0,0,1.2) -bc=1;
solid cyl2 = cyl21 and cyl22 and cyl23;

solid virtual651 = cyl1 or cyl2;
solid matrix = box and not virtual651;
solid virtual651 = cyl1 or cyl2;
solid fiber = box and virtual651;

tlo fiber -col=[1,1,1] ;
tlo matrix -col=[1,0,1] -transparent;