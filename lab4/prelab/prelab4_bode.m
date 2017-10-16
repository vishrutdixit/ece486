cd U:\ece486\

s = tf('s');
sorder = .0545/(1.066*10^-7*s^2+6.292*10^-4*s+2.83*10^-3)
forder = .0545/(6.29*10^-4*s+2.83*10^-3)

so = step(sorder);
fo = step(forder);

hold on
bode(sorder);
bode(forder);
grid on
title('bode plot for the first and second order approximations')
legend('second order approx','first order approx');

%plot(so, ':')
%plot(fo, '-')

%title('w vs. t for the first and second order approximations')
%xlabel('t, time (s)')
%ylabel('w')
