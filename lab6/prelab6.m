close all

K_c = 1; %8.85
K_pot = 10/(2*pi);
K_amp = 2.4;
K = 18;
t_m = 2/10;
s = tf('s');

%% b

% gcg = K_c*1/s*K_pot*K_amp*K/(t_m*s+1);
% gcg_closed = gcg/(1+gcg);
% 
% margin(gcg)
% 
% figure(3),grid on,bode(gcg)
% figure(4),grid on,bode(gcg_closed)

%% c

% K_c = 1
% 
% gc = K_c*(0.1*s+1)/(0.01*s+1)
% 
% bode(gc)

%% d

% K_c = 3
% 
% t_z = 1/10
% t_p = 1/185
% 
% gc = K_c*(t_z*s+1)/(t_p*s+1)
% g = K_pot*K_amp*K/(s*(t_m*s+1))
% gcg = gc*g
% gcg_cl = gcg/(1+gcg)
% 
% figure(1),margin(gcg)
% figure(2),step(gcg_cl)
% figure(3),rlocus(gcg_cl)

%% e

K_c = .4

t_z = 1/2.3
t_p = 1/92

gc = K_c*(t_z*s+1)/(t_p*s+1)
g = K_pot*K_amp*K/(s*(t_m*s+1))
gcg = gc*g
gcg_cl = gcg/(1+gcg)

figure(1),margin(gcg)
figure(2),step(gcg_cl)
figure(3),rlocus(gcg_cl)
