function [] = PlotResponse(tout1, w1, tout2, w2)
close all
hold on
grid on
plot(tout1, w1);
plot(tout2, w2);
legend('td_w', 'wr_w');
xlabel('time (s)');
ylabel('response!');
title('Controller 2 Responses');