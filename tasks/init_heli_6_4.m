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

%%%%%%%%%%%  Part 2  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

A = [0 1 0;0 0 0;0 0 0];
B = [0 0;0 k_1;k_2 0];

C = ctrb(A, B);

Q = [30 0 0; 0 5 0; 0 0 100];
R = [0.7 0 ; 0 0.7];
K = lqr(A, B, Q, R);
K1 = [0 0 -1; 1 2 0];
C1 = [1 0 0;0 0 1];

F = inv(C1*inv((B*K)-A)*B);

% A_i = [0 1 0 0 0; 0 0 0 0 0; 0 0 0 0 0; 1 0 0 0 0; 0 0 1 0 0];
% B_i = [B; 0 0; 0 0];
% R_i = [1 0; 0 1];
% %R_mat = [0 0; 0 0; 0 0; 1 0; 0 1];
% C2 = [1 0 0 0 0; 0 0 1 0 0];
% q_i_pivots = [30 5 100 100 50];
% Q_i = diag(q_i_pivots);
% Ki = lqr(A_i, B_i, Q_i, R_i);
% %Fi = inv(C2*inv((B_i*Ki)-A_i)*B_i);
% Fi = [0 10;10 0];


%%%%%%%%%% Day 4

PORT = 6;
A = [0 1 0 0 0 0;
    0 0 0 0 0 0;
    0 0 0 1 0 0;
    0 0 0 0 0 0;
    0 0 0 0 0 1;
    k_3 0 0 0 0 0];
B = [0 0; 0 k_1; 0 0; k_2 0; 0 0; 0 0];
C_gyro = [0 1 0 0 0 0;
    0 0 0 1 0 0;
    0 0 0 0 0 1];

C_IMU = [0 1 0 0 0 0;
    0 0 0 1 0 0;
    0 0 0 0 0 1;
    1 0 0 0 0 0;
    0 0 1 0 0 0];

%%%%%%%%%% Day 5

TS = 0.002;
SYS = ss(A,B,C_IMU,0);
SYSD = c2d(SYS,TS,'zoh');
A_d = SYSD.A;
B_d = SYSD.B;
C_d = SYSD.C;
Q_d = diag([0.0025,0.01,0.0001,0.001,1,0.1]);
P_0 = diag([0.001,0.014,0.001,0.001,0.001,0.0025]);
x_0 = [0;0;0;0;0;0];
M = eye(6);
v = [1,1,1,1,1,1]';

R_d = [0.0252594392205063 -0.0144533382020730 0.000513199731860151 0.0243943494726769 0.000483190598256583;
       -0.0144533382020730 0.00959024486602203 -0.000193294418480449 -0.0184351417185219 -0.00694107544021252;
       0.000513199731860151 -0.000193294418480449 0.000162066977774537 0.000585026602111998 -0.000387700588297450;
       0.0243943494726769 -0.0184351417185219 0.000585026602111998 0.0546356731828053 0.0365637964328360;
       0.000483190598256583 -0.00694107544021252 -0.000387700588297450 0.0365637964328360 0.0499623126628880];