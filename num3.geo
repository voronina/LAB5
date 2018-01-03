algebraic3d
solid box1= plane(0,0,0;0,0,-1)-bc=16;
solid box2= plane(0,0,0;0,-1,0)-bc=14;
solid box3= plane(0,0,0;-1,0,0) -bc=18;
solid box4= plane(1.70554 ,0,0;1,0,0)-bc=22;
solid box5= plane(0, 1.70554 ,0;0,1,0)-bc=15;
solid box6= plane(0, 0,1.70554 ;0,0,1)-bc=19;
solid YAP = box1 and box2 and box3 and box4 and box5 and box6;

solid cyl_1 = cylinder(0, 0 , 0 ; 0 , 0 , 1.70554 ; 1 )-bc=1;
solid hole_1 = cylinder(0, 0 , 0 ; 0 , 0 , 1.70554 ; 0.8 )-bc=1;
solid fbr_1 = cyl_1 and not hole_1;

solid cyl_2 = cylinder(1.70554, 1.70554 , 0 ; 1.70554 , 1.70554 , 1.70554 ; 1 )-bc=1;
solid hole_2 = cylinder(1.70554, 1.70554 , 0 ; 1.70554 , 1.70554 , 1.70554 ; 0.8 )-bc=1;
solid fbr_2 = cyl_2 and not hole_2;

solid cyls = cyl_1 or cyl_2;
solid holes = hole_1 or hole_2;

solid matrix = YAP and not (cyl_1 or cyl_2);
solid fibers = YAP and (fbr_2 or fbr_1);
solid gas = YAP and (hole_1 or hole_2);

tlo fibers -col=[1,1,0];
tlo gas -col=[0,1,1] -transparent;
tlo matrix -col=[0,0,1] -transparent;