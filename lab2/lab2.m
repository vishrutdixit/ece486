A = [-6 -25; 1 0]
B = [25; 0]
C = [1 0; 0 1]
D = [0; 0]

subplot(2,1,1)
plot(tout,y)
grid on
title('$y$ vs. $t$','interpreter','latex')
ylabel('$y$','interpreter','latex')

subplot(2,1,2)
plot(tout,y_dot)
grid on
title('$\dot{y}$ vs. $t$','interpreter','latex')
xlabel('$t$, time','interpreter','latex')
ylabel('$\dot{y}$','interpreter','latex')

a = 0.5
zeta = 2

