algebraic3d
solid box1 = plane (0,0,0;-1,0,0) -bc=18;
solid box2 = plane (0,0,0;0,-1,0) -bc=14; 
solid box3 = plane (0,0,0;0,0,-1) -bc=16; 
solid box4 = plane (10.000000,1,1;1,0,0) -bc=22; 
solid box5 = plane (1,10.000000,1;0,1,0) -bc=15; 
solid box6 = plane (1,1,9.600000;0,0,1) -bc=19;
solid box = box1 and box2 and box3 and box4 and box5 and box6;
solid plastina2 =
plane (0, 0, 0; -1, 0, 0) and plane (0, 0, 0; 0, -1, 0)
and plane (0, 0, 0; 0, 0, -1) and plane (10.000000, 1, 1; 1, 0, 0)
and plane (1, 10.000000, 1; 0, 1, 0) and plane (1, 1, 3.000000; 0, 0, 1);
solid plastina1 =
plane (0, 0, 6.600000; -1, 0, 0) and plane (0, 0, 6.600000; 0, -1, 0)
and plane (0, 0, 6.600000; 0, 0, -1) and plane (10.000000, 1, 1; 1, 0, 0)
and plane (1, 10.000000, 1; 0, 1, 0) and plane (1, 1, 9.600000; 0, 0, 1);
solid sp1 = sphere (0, 0, 4.800000; 2.000000) -bc=1;
solid sp2 = sphere (10.000000, 10.000000, 4.800000; 2.000000) -bc=1;
solid sp3 = sphere (10.000000, 0, 4.800000; 2.000000) -bc=1;
solid sp4 = sphere (0, 10.000000, 4.800000; 2.000000) -bc=1;
solid matrix = box
and not sp1 and not sp2 and not sp3 and not sp4
and not plastina1 and not plastina2;
solid plastiny = (plastina1 or plastina2) and not (sp1 or sp2 or sp3 or sp4);
solid sps = box and (sp1 or sp2 or sp3 or sp4);
tlo matrix -col=[1,0,0] -transparent;
tlo sps -col=[0,0,1];
tlo plastiny -col=[0,1,1];