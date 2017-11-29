

%% Calculating Torque Constants

% [bpMax, brMax] = DetermineTorqConstants(theta_p.time, theta_p.signals.values,theta_r.signals.values);
% 
% disp(bpMax);
% disp(brMax);

%% 4.b
% 
% A = [ 0 1 ; 77.64 0 ];
% B = [ 0 ; -0.9278];
% 
% p = [-5-8.66*i -5+8.66*i];
% 
% K = place(A,B,p)

%% 4.c

A = [ 0 1 0 0 ; 77.64 0 0 0 ; 0 0 0 1 ; 0 0 0 0 ];
B = [ 0 ; -0.9278 ; 0 ; 143.7745];

p = [-5-8.66*i -5+8.66*i -5 0];

K = place(A,B,p)


