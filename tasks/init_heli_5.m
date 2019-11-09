% FOR HELICOPTER NR 3-10
% This file contains the initialization for the helicopter assignment in
% the course TTK4115. Run this file before you execute QuaRC_ -> Build 
% to build the file heli_q8.mdl.

% Oppdatert høsten 2006 av Jostein Bakkeheim
% Oppdatert høsten 2008 av Arnfinn Aas Eielsen
% Oppdatert høsten 2009 av Jonathan Ronen
% Updated fall 2010, Dominik Breu
% Updated fall 2013, Mark Haring
% Updated spring 2015, Mark Haring


%%%%%%%%%%% Calibration of the encoder and the hardware for the specific
%%%%%%%%%%% helicopter
Joystick_gain_x = 1;
Joystick_gain_y = 1;


%%%%%%%%%%% Physical constants
g = 9.81; % gravitational constant [m/s^2]
l_c = 0.46; % distance elevation axis to counterweight [m]
l_h = 0.66; % distance elevation axis to helicopter head [m]
l_p = 0.175; % distance pitch axis to motor [m]
m_c = 1.92; % Counterweight mass [kg]
m_p = 0.72; % Motor mass [kg]

%%%%%%%%%%%  Part 1  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

j_p = 2*m_p*l_p.^2;
j_e = m_c*l_c.^2 + 2*m_p*l_h.^2;
j_x = m_c*l_c.^2 + 2*m_p*(l_h.^2 + l_p.^2);

v_s0 = 7.5;
k_f = (2*m_p*l_h-m_c*l_c)*g/(v_s0*l_h);

l_1 = l_p*k_f;
l_2 = l_h*k_f;
l_3 = l_h*k_f;

k_1 = l_1/j_p;
k_2 = l_2/j_e;
k_3 = l_3*v_s0/j_x;

e_0 = -0.54;
p_0 = 0.16;

%%%%%%%%%%%  Part 3  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

A = [0 1 0;0 0 0;0 0 0];
B = [0 0;0 k_1;k_2 0];

C = ctrb(A, B);

Q = [30 0 0; 0 5 0; 0 0 100];
R = [0.7 0 ; 0 0.7];
K = lqr(A, B, Q, R);
K1 = [0 0 -1; 1 2 0];
C1 = [1 0 0;0 0 1];

F = inv(C1*inv((B*K)-A)*B);

A_i = [0 1 0 0 0; 0 0 0 0 0; 0 0 0 0 0; 1 0 0 0 0; 0 0 1 0 0];
B_i = [B; 0 0; 0 0];
R_i = [1 0; 0 1];
%R_mat = [0 0; 0 0; 0 0; 1 0; 0 1];
C2 = [1 0 0 0 0; 0 0 1 0 0];
q_i_pivots = [30 5 100 100 50];
Q_i = diag(q_i_pivots);
Ki = lqr(A_i, B_i, Q_i, R_i);
%Fi = inv(C2*inv((B_i*Ki)-A_i)*B_i);
Fi = [0 10;10 0];


%%%%%%%%%% Day 4

PORT = 6;
A = [0 1 0 0 0 0; 0 0 0 0 0 0; 0 0 0 1 0 0; 0 0 0 0 0 0; 0 0 0 0 0 1; k_3 0 0 0 0 0];
B = [0 0; 0 k_1; 0 0; k_2 0; 0 0; 0 0];
C_gyro = [0 1 0 0 0 0; 0 0 0 1 0 0; 0 0 0 0 0 1];

C_IMU = [0 1 0 0 0 0; 0 0 0 1 0 0; 0 0 0 0 0 1; 1 0 0 0 0 0; 0 0 1 0 0 0];

%%%%%%%%%% Day 5

TS = 0.002;
SYS = ss(A,B,C_IMU,0);
SYSD = c2d(SYS,TS,'zoh');
A_d = SYSD.A;
B_d = SYSD.B;
C_d = SYSD.C;
Q_d = diag([1,1,1,1,1,1]);
P_0 = diag([0.001,0.014,0.001,0.001,0.001,0.0025]);
x_0 = [0;0;0;0;0;0];
M = eye(6);
v = [1,1,1,1,1,1]';
R_d = [0.13830511806937898	-0.07347759529399987	0.004505284621149424	-0.059514043346738536	-0.15039205004044764;
-0.07347759529399987	0.05941958792726958	-0.002372265025981698	-0.019339634506924754	0.07680841315542031;
0.004505284621149424	-0.002372265025981698	4.426615007531596E-4	-0.0026310295639721615	-0.005098867245050531;
-0.059514043346738536	-0.019339634506924754	-0.0026310295639721615	0.22610952453683036	0.1026156683047645;
-0.15039205004044764	0.07680841315542031	-0.005098867245050531	0.1026156683047645	0.21792366443416747];