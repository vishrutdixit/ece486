cd U:\ece486\
lab1


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