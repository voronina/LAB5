algebraic3d
solid box1= plane(0,0,0;0,0,-1);
solid box2= plane(0,0,0;0,-1,0);
solid box3= plane(0,0,0;-1,0,0);
solid box4= plane(1 ,0,0;1,0,0);
solid box5= plane(0, 1 ,0;0,1,0);
solid box6= plane(0, 0,1 ;0,0,1);
solid YAP = box1 and box2 and box3 and box4 and box5 and box6;

solid cyl = cylinder(0.5, 0.5 , 0 ; 0.5 , 0.5 , 1 ; 0.3 );
solid hole = cylinder(0.5, 0.5 , 0 ; 0.5 , 0.5 , 1 ; 0.2 );


solid fbr = cyl and not hole;

solid matrix = YAP and not fbr and not hole;

solid fiber = YAP and fbr;

solid gas = YAP and hole;


tlo fiber -col=[1,1,0];
tlo gas -col=[0,0,0] -transparent;
tlo matrix -col=[1,1,1] -transparent;