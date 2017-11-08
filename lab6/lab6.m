%% Part 1

close all

VS = .5;

Kc = 3; %.4; %8.85;
Kp = 10/(2*pi);
Ka = 2.4;
K = 18;
Tm = 2/10;
Tz= 1/10; %1/2.3;
Tp = 1/200; %1/92;

s = tf('s');

cutoff = 1000;

figure(1),hold on
subplot(3,1,1),hold on, plot(tout(1:1000),lead_05(1:1000)),plot(tout(1:1000),lead_05sat(1:1000)), title('.5V step'), legend('Unsaturated','Saturated');
subplot(3,1,2),hold on, plot(tout(1:1000),lead_5(1:1000)),plot(tout(1:1000),lead_5sat(1:1000)), title('5V step');
subplot(3,1,3),hold on, plot(tout(1:1000),lead_50(1:1000)),plot(tout(1:1000),lead_50sat(1:1000)), title('50V step');


%% Part 2

