clear
load('./prelab4');
close all

time = Iner(:,1);
w = Iner(:,2);

b = 3.8e-5;
c = 0.0105;

%J = 1.096e-4;

Wss = -c/b;

out = log(w - Wss);

%plot(time, w);

idx = find(time > .45, 1, 'first');
idx = idx-1;

coeffs = polyfit(time(1:idx), out(1:idx), 1);

y_fitted = coeffs(1)*time + coeffs(2);

hold on
plot(time(1:idx), out(1:idx))
plot(time(1:idx), y_fitted(1:idx))
xlabel('time (s)');
ylabel('$ln(W(t) - W_{ss})$', 'interpreter', 'latex');
title('Time vs. Angular Velocity Linear Fit');
legend('actual', 'linear fit');

J = -b/coeffs(1)



