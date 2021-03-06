algebraic3d
solid box1 = plane(0, 0, 0; 0, 0, -4) -bc = 10;
solid box2 = plane(0, 0, 0; 0, -4, 0) -bc = 10;
solid box3 = plane(0, 0, 0; -4, 0, 0) -bc = 10;
solid box4 = plane(4, 4, 4; 4, 0, 0) -bc = 10;
solid box5 = plane(4, 4, 4; 0, 4, 0) -bc = 10;
solid box6 = plane(4, 4, 4; 0, 0, 4) -bc = 10;
solid box = box1 and box2 and box3 and box4 and box5 and box6;

solid cyl_1 = cylinder(0.6601, 0.2101, 0; 0.6601, 0.2101, 4; 0.1) -bc = 1;
solid hole_1 = cylinder(0.6601, 0.2101, 0; 0.6601, 0.2101, 4; 0.09) -bc = 1;
solid fiber_1 = cyl_1 and not hole_1;
solid cyl_2 = cylinder(0.7301, 2.5701, 0; 0.7301, 2.5701, 4; 0.1) -bc = 1;
solid hole_2 = cylinder(0.7301, 2.5701, 0; 0.7301, 2.5701, 4; 0.09) -bc = 1;
solid fiber_2 = cyl_2 and not hole_2;
solid cyl_3 = cylinder(0.7301, 2.6901, 0; 0.7301, 2.6901, 4; 0.1) -bc = 1;
solid hole_3 = cylinder(0.7301, 2.6901, 0; 0.7301, 2.6901, 4; 0.09) -bc = 1;
solid fiber_3 = cyl_3 and not hole_3;
solid cyl_4 = cylinder(0.3401, 6.4901, 0; 0.3401, 6.4901, 4; 0.1) -bc = 1;
solid hole_4 = cylinder(0.3401, 6.4901, 0; 0.3401, 6.4901, 4; 0.09) -bc = 1;
solid fiber_4 = cyl_4 and not hole_4;
solid cyl_5 = cylinder(0.9301, 1.0001, 0; 0.9301, 1.0001, 4; 0.1) -bc = 1;
solid hole_5 = cylinder(0.9301, 1.0001, 0; 0.9301, 1.0001, 4; 0.09) -bc = 1;
solid fiber_5 = cyl_5 and not hole_5;
solid cyl_6 = cylinder(1.7201, 2.0501, 0; 1.7201, 2.0501, 4; 0.1) -bc = 1;
solid hole_6 = cylinder(1.7201, 2.0501, 0; 1.7201, 2.0501, 4; 0.09) -bc = 1;
solid fiber_6 = cyl_6 and not hole_6;
solid cyl_7 = cylinder(1.6701, 3.1901, 0; 1.6701, 3.1901, 4; 0.1) -bc = 1;
solid hole_7 = cylinder(1.6701, 3.1901, 0; 1.6701, 3.1901, 4; 0.09) -bc = 1;
solid fiber_7 = cyl_7 and not hole_7;
solid cyl_8 = cylinder(1.4301, 4.6601, 0; 1.4301, 4.6601, 4; 0.1) -bc = 1;
solid hole_8 = cylinder(1.4301, 4.6601, 0; 1.4301, 4.6601, 4; 0.09) -bc = 1;
solid fiber_8 = cyl_8 and not hole_8;
solid cyl_9 = cylinder(2.1501, 0.4101, 0; 2.1501, 0.4101, 4; 0.1) -bc = 1;
solid hole_9 = cylinder(2.1501, 0.4101, 0; 2.1501, 0.4101, 4; 0.09) -bc = 1;
solid fiber_9 = cyl_9 and not hole_9;
solid cyl_10 = cylinder(3.7501, 2.87343, 0; 3.7501, 2.87343, 4; 0.1) -bc = 1;
solid hole_10 = cylinder(3.7501, 2.87343, 0; 3.7501, 2.87343, 4; 0.09) -bc = 1;
solid fiber_10 = cyl_10 and not hole_10;
solid cyl_11 = cylinder(3.5901, 4.56677, 0; 3.5901, 4.56677, 4; 0.1) -bc = 1;
solid hole_11 = cylinder(3.5901, 4.56677, 0; 3.5901, 4.56677, 4; 0.09) -bc = 1;
solid fiber_11 = cyl_11 and not hole_11;
solid cyl_12 = cylinder(3.8101, 0.2101, 0; 3.8101, 0.2101, 4; 0.1) -bc = 1;
solid hole_12 = cylinder(3.8101, 0.2101, 0; 3.8101, 0.2101, 4; 0.09) -bc = 1;
solid fiber_12 = cyl_12 and not hole_12;
solid cyl_13 = cylinder(3.2901, 2.70343, 0; 3.2901, 2.70343, 4; 0.1) -bc = 1;
solid hole_13 = cylinder(3.2901, 2.70343, 0; 3.2901, 2.70343, 4; 0.09) -bc = 1;
solid fiber_13 = cyl_13 and not hole_13;
solid cyl_14 = cylinder(5.0201, 6.40677, 0; 5.0201, 6.40677, 4; 0.1) -bc = 1;
solid hole_14 = cylinder(5.0201, 6.40677, 0; 5.0201, 6.40677, 4; 0.09) -bc = 1;
solid fiber_14 = cyl_14 and not hole_14;
solid cyl_15 = cylinder(5.4601, 1.1001, 0; 5.4601, 1.1001, 4; 0.1) -bc = 1;
solid hole_15 = cylinder(5.4601, 1.1001, 0; 5.4601, 1.1001, 4; 0.09) -bc = 1;
solid fiber_15 = cyl_15 and not hole_15;
solid cyl_16 = cylinder(3.3101, 2.33343, 0; 3.3101, 2.33343, 4; 0.1) -bc = 1;
solid hole_16 = cylinder(3.3101, 2.33343, 0; 3.3101, 2.33343, 4; 0.09) -bc = 1;
solid fiber_16 = cyl_16 and not hole_16;
solid cyl_17 = cylinder(5.0701, 3.15677, 0; 5.0701, 3.15677, 4; 0.1) -bc = 1;
solid hole_17 = cylinder(5.0701, 3.15677, 0; 5.0701, 3.15677, 4; 0.09) -bc = 1;
solid fiber_17 = cyl_17 and not hole_17;
solid cyls = cyl_1 or cyl_2 or cyl_3 or cyl_4 or cyl_5 or cyl_6 or cyl_7 or cyl_8 or cyl_9 or cyl_10 or cyl_11 or cyl_12 or cyl_13 or cyl_14 or cyl_15 or cyl_16 or cyl_17;
solid holes = hole_1 or hole_2 or hole_3 or hole_4 or hole_5 or hole_6 or hole_7 or hole_8 or hole_9 or hole_10 or hole_11 or hole_12 or hole_13 or hole_14 or hole_15 or hole_16 or hole_17;
solid fibers = fiber_1 or fiber_2 or fiber_3 or fiber_4 or fiber_5 or fiber_6 or fiber_7 or fiber_8 or fiber_9 or fiber_10 or fiber_11 or fiber_12 or fiber_13 or fiber_14 or fiber_15 or fiber_16 or fiber_17;

solid matrix = box and not cyls;
solid obj = box and fibers;
solid gas = box and holes;
tlo obj -col=[1,1,0];
tlo gas -col=[0,1,1] -transparent;
tlo matrix -col=[0,0,1] -transparent;
