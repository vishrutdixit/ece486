K = 1;

Kd = 0:.1:10;


zeta = (15+60*K*Kd)/(2*sqrt(36+60*K));
w = sqrt(36+60*K);

p1 = (-2*zeta*w + sqrt((2*zeta*w).^2 - 4*(w^2)))/2;
p2 = (-2*zeta*w - sqrt((2*zeta*w).^2 - 4*(w^2)))/2;

plot(Kd, p2, 'g')
hold on
grid on
plot(Kd, p1, 'b')

xlabel('$K_{d}$', 'interpreter','latex');
ylabel('poles');
title('$K_{d}$ vs pole locations','interpreter','latex');